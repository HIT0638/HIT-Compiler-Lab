
#include "semantic.h"

// 全局域符号表
FieldList head = NULL;

/**
 * 初始化符号表
*/
void initSymbolTable(){
    head = createField();
}


int checkSame(FieldList field){
    FieldList f = head->tail;
    while(f){
        if(!strcmp(f->name, field->name))
            return 0;
        f = f->tail;
    }
    return 1;
}

void addSymbol(FieldList field){
    field->tail = head->tail;
    head->tail = field;
}


FieldList searchSymbol(char* name){
    FieldList f = head->tail;
    while(f){
        if(!strcmp(f->name, name))
            return f;
        f = f->tail;
    }

    return NULL;
}


void deleteField(FieldList field){
    free(field->name);
    while (field->tail)
        deleteField(field->tail);
    free(field); 
}

void printSymbols(){
    FieldList p = head->tail;
    while(p){
        printf("Symbol: %s \n", p->name);
        p = p->tail;
    }

    return ;
}

Type createType(Kind kind, int num, ...){
    Type t = (Type)malloc(sizeof(struct Type_));
    t->kind = kind;
    va_list tlist;
    va_start(tlist, num);
    switch(kind)
    {
        case BASIC:
            t->u.basic = va_arg(tlist, Basic_Type);
            // printf("创建基本类型: %d\n", t->u.basic);
            break;
        case ARRAY:
            t->u.array.size = va_arg(tlist, int);
            t->u.array.elem = va_arg(tlist, Type);
            // printf("创建数组类型\n");
            break;
    }
    va_end(tlist);
    return t;
}

/**
 * 创建符号
*/
FieldList createField(){
    FieldList f = (FieldList) malloc(sizeof(FieldList_));
    f->name = (char*) malloc(sizeof(32 * sizeof(char)));
    f->type = NULL;
    f->tail = NULL;

    return f;
}

/**
 * 遇到ExtDef，开始外部定义分析
 * ExtDef -> Specifier ExtDecList SEMI
             | Specifier SEMI
             | Specifier FunDec CompSt
*/
void ExtDef(pNode root){
    /**
     * 根据实验要求，第二行和第三行产生式不涉及错误分析。
     * 因此对第一行产生式进行分析。
     * ExtDef -> Specifier(out) -> ExtDecList -> 
     * (VarDec -> ID | (VarDec -> ...) | ...) | (ExtDecList -> ...)
     * */   

    // Specifier分析，得到该定义的type。
    Type specifier_type = Specifier(root->firstChild);

    // 进入$2，ExtDecList进行分析
    if (!strcmp(root->firstChild->nextSibling->value, "ExtDecList"))
        ExtDecList(root->firstChild->nextSibling, specifier_type);
    
    return ;
}

/**
 * Specifier 对应类型
 * Specifier : TYPE   
            | StructSpecifier  
;
*/
Type Specifier(pNode root){
    /**
     * 由于实验要求不涉及结构体相关的分析，
     * 因此这一步还要根据TYPE得到int/float类型即可
    */
    if(root->firstChild->type == T_TYPE){
        // printf("Specifier -> TYPE\n");
        if (!strcmp(root->firstChild->value, "int")){
            // printf("SPecifier -> TYPE -> INT\n");
            return createType(BASIC, 1, B_INT);
        }
        else{ 
            // printf("SPecifier -> TYPE -> FLOAT\n");
            return createType(BASIC, 1, B_FLOAT);
        }
    } 
    
    return NULL;
}

/**
 * ExtDecList : VarDec
            | VarDec COMMA ExtDecList  
*/
void ExtDecList(pNode root, Type type){
    // if(root == NULL)
    //     return ;


    // // 分析 VarDec
    // if (!strcmp(root->firstChild->value, "VarDec"))
    //     VarDec(root->firstChild, type);
    
    // // 递归分析 ExtDecList
    // if (root->firstChild->nextSibling->nextSibling != NULL)
    //     if(!strcmp(root->firstChild->nextSibling->nextSibling->value, "ExtDecList"))
    //         ExtDecList(root->firstChild->nextSibling->nextSibling, type);
        
    // return ;

    pNode p = root;
    while (p)
    {
        VarDec(p->firstChild, type);

        // 同时定义多个变量
        if (p->firstChild->nextSibling)
            p = p->firstChild->nextSibling->nextSibling;
        else
            break;
    }
}

/**
 * VarDec : ID
        | VarDec LB INT RB 
*/
void VarDec(pNode root, Type type){
    /**
     * 在 VarDec 部分，如果到了ID结点，则需要根据type以及ID在符号表/全局域中进行变量的记录。
     * 在这部分使用递归方式会导致数组定义部分的处理逻辑变得复杂。
     * 所以选择使用迭代方式。
    */

   // 首先找到变量名（无论是基本类型还是数组）
    // printf("VarDec\n");
    pNode id = root;
    while (id->firstChild)
        id = id->firstChild;

    // 为改变量创建新field
    FieldList newVar = createField();
    strcpy(newVar->name, id->value);
    // printf("VarDec %s\n", newVar->name);

    //基本数据类型
    if(root->firstChild->type == T_ID){
        newVar->type = type;
    } else { // 数组
        /**
         * 数组部分Symbol创建的逻辑较为复杂，大致流程如下：
         * 主要逻辑是迭代进入VarDec部分直到遇到ID。
         * 每一次迭代都标志着多一维数组，这标志着上一维的数组的elem需要指向下一维数组。
         * 在createType视角来看，对每一维数组需要createType，kind为ARRAY，num为2，
         * 后续不定参数为其size（INT）和type。
        */

       pNode vardec = root->firstChild;
       // 迭代多维数组的创建
       while(vardec->nextSibling){ // nextSibling存在说明不是ID而是VarDec
        // 这是一个串联多维数组逻辑的过程
        // 即，如果是一维数组，其type位INT，
        // 如果是高维数组，其elem类型即为低一维数组的 type
            Type array = createType(ARRAY, 2,  
                                    atoi(vardec->nextSibling->nextSibling->value),
                                    type);

            type = array;
            vardec = vardec->firstChild;            
       }

       newVar->type = type;
    }

    // 根据试验要求，不能出现重名变量，因此在这一步变量创建后，需要进行检查
    if (!checkSame(newVar))
    {
         printf("Error type 3 at Line %d: Redefined variable \"%s\".\n", 
            root->lineno, newVar->name);
        deleteField(newVar);
    } else
        addSymbol(newVar);

    // printSymbols();
}

/**
 * Def : Specifier DecList SEMI
*/
void Def(pNode root){
    /**
     * Def 分析部分重点在DecList下去。
        重要路径如下：Def -> Specifier(out) -> 
        DecList -> (DecList -> ...) | (Dec -> (VarDec -> ...) | (Exp -> ...))
    */

    // 作为分析起始结点，前部分处理和ExtDef类似

    Type specifier_type = Specifier(root->firstChild);

    if (!strcmp(root->firstChild->nextSibling->value, "DecList")) {
        DecList(root->firstChild->nextSibling, specifier_type);
    }

    return ;
}

/**
 * DecList : Dec   
        | Dec COMMA DecList
*/
void DecList(pNode root, Type type){
    /**
     * 
    */

    if(!strcmp(root->firstChild->value, "Dec"))
        Dec(root->firstChild, type);
    
    if(root->firstChild->nextSibling){
        DecList(root->firstChild->nextSibling->nextSibling, type);
    }

    return ;
}


/**
 * Dec : VarDec    
    | VarDec ASSIGNOP Exp   
*/
void Dec(pNode root, Type type){
    /**
     * 涉及变量声明和初始化的部分.
    */

    if(!strcmp(root->firstChild->value, "VarDec"))
        VarDec(root->firstChild, type);
    
    if(root->firstChild->nextSibling){
        // Type exp_type = Exp(root->firstChild->nextSibling->nextSibling);

        /**
         * 赋值号两边类型应该匹配。
         * 基本数据类型： int&int 或 float&float
         * 数组：
        */

    }
}


/**
 * Exp : Exp ASSIGNOP Exp  
    | Exp AND Exp  
    | Exp OR Exp   
    | Exp RELOP Exp 
    | Exp PLUS Exp 
    | Exp MINUS Exp 
    | Exp STAR Exp  
    | Exp DIV Exp  
    | LP Exp RP
    | MINUS Exp 
    | NOT Exp  
    | ID LP Args RP 
    | ID LP RP  
    | Exp LB Exp RB
    | Exp DOT ID   
    | ID   
    | INT  
    | FLOAT 
*/
// Type Exp(pNode root){
//     /**
//      * 先处理简单类型返回
//      * INT / FLOAT 直接返回类型
//      * ID searchSymbol()函数得到type并返回
//     */
//     // printf("In Exp;\n");
//     if (root->firstChild->type == T_INT)
//         return createType(BASIC, 1, B_INT);
//     else if (root->firstChild->type == T_FLOAT)
//         return createType(BASIC, 1, B_FLOAT);
//     else if (root->firstChild->type == T_ID){
//         FieldList idsym = searchSymbol(root->firstChild->value);
//         if(!idsym)
//             printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",
//                 root->firstChild->lineno, root->firstChild->value);
//         else    
//             return idsym->type;
//     }

//     /**
//      * 再处理数组以及二元运算
//     */
//     if (!strcmp(root->firstChild->value, "Exp")){
//         printf("In Exp->Exp;\n");
//         // printf("%s", root->firstChild->nextSibling->value);
//         // 处理数组
//         if (!strcmp(root->firstChild->nextSibling->value, "LB"))
//         {
//             /**
//              * 主要是判断
//              * 1. 第一个Exp类型是否为数组
//              * 2. []中Exp类型是否位INT
//             */
//             Type t1 = Exp(root->firstChild);
//             Type t2 = Exp(root->firstChild->nextSibling->nextSibling);
//             if (!t1 || !t2)
//                 return NULL;
//             if (t1->kind != ARRAY)
//                 printf("Error type 10 at Line %d: \"%s\" is not an array.\n",
//                     root->firstChild->lineno, root->firstChild->firstChild->value);
//             else if (t2->kind != BASIC || t2->u.basic != B_INT)
//                 printf("Error type 12 at Line %d: \"%s\" is not an integer.\n",
//                     root->firstChild->lineno, root->firstChild->nextSibling->nextSibling->firstChild->value);
//         }
//         else if (!strcmp(root->firstChild->nextSibling->value, "DOT"))
//         { // 二院运算
//             /**
//              * 主要判断
//              * 1. 赋值语句两端Exp类型是否相同
//              * 2. 运算二院运算参与的两个Exp类型是否相同
//             */

//             Type t1 = Exp(root->firstChild);
//             Type t2 = Exp(root->firstChild->nextSibling->nextSibling);

//             if (!t1 || !t2)
//                 return NULL;
            
//             if (!strcmp(root->firstChild->nextSibling->value, "ASSIGNOP"))
//             {   // 赋值
//                 printf("In Assignment;\n");
//                 if ((root->firstChild->firstChild->type == T_INT) ||
//                      (root->firstChild->firstChild->type == T_FLOAT))
//                     printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n", root->firstChild->lineno);
//                 else if (root->firstChild->firstChild->type == T_ID)
//                 {
//                     if (t1->u.basic != t2->u.basic)
//                         printf("Error type 5 at Line %d: Type mismatched for assignment.\n",
//                             root->firstChild->lineno);
//                 }
//             }
//         }
//     }

//     return NULL;
// }

Type Exp(pNode root){
    // printf("In Exp;\n");
    if (root->firstChild->type == T_INT)
        return createType(BASIC, 1, B_INT);
    else if (root->firstChild->type == T_FLOAT)
        return createType(BASIC, 1, B_FLOAT);
    else if (root->firstChild->type == T_ID) {
        FieldList idsym = searchSymbol(root->firstChild->value);
        if (!idsym) {
            printf("Error type 1 at Line %d: Undefined variable \"%s\".\n",
                root->firstChild->lineno, root->firstChild->value);
            return NULL;
        } else {
            return idsym->type;
        }
    }

    // 处理二元运算
    pNode expLeft = root->firstChild;
    pNode operator = expLeft->nextSibling;
    pNode expRight = operator->nextSibling;

    Type t1 = Exp(expLeft);
    Type t2 = Exp(expRight);

    if (!t1 || !t2)
        return NULL;

    // 检查数组访问
    if (!strcmp(operator->value, "LB")) {
        if (t1->kind != ARRAY) {
            printf("Error type 10 at Line %d: \"%s\" is not an array.\n",
                root->lineno, expLeft->firstChild->value);
        } else if (t2->kind != BASIC || t2->u.basic != B_INT) {
            printf("Error type 12 at Line %d: Index \"%s\" is not an integer.\n",
                root->lineno, expRight->firstChild->value);
        }
        return (t1->kind == ARRAY) ? t1->u.array.elem : NULL; // 返回数组元素类型
    }

    // 检查赋值和其他二元运算
    if (!strcmp(operator->value, "ASSIGNOP")) {
        // 赋值运算左侧必须是变量，非INT和FLOAT直接字面量
       
        // expLeft 的value在这里还是Exp
        // 所以要取firstChild来进行判断
        if (expLeft->firstChild->type != T_ID) {
            printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n", root->lineno);
        } else if (t1->u.basic != t2->u.basic) {
            printf("Error type 5 at Line %d: Type mismatched for assignment.\n",
                root->lineno);
        }
    } else if (t1->u.basic != t2->u.basic) { // 其他二元运算类型检查
        printf("Error type 7 at Line %d: Type mismatched for operands.\n",
            root->lineno);
    }

    return NULL; // 或者根据实际情况返回合适的类型
}

/**
 * 语法分析启动函数
 * 主要逻辑是遍历以root为根节点的语法分析树
 * 对特定类型的 Node 进行深入检查
 * num 代表当前层数
*/
void semanticAnalysis(pNode root){
    if(root == NULL)
        return;

    /**
     * 根据实验要求
     * 需要分析的根类型有
     * ExtDef
     * Def
     * Exp
    */
    if(!strcmp(root->value, "ExtDef"))
        ExtDef(root);
    if(!strcmp(root->value, "Def"))
        Def(root);
    if(!strcmp(root->value, "Exp"))
        Exp(root);
    
    semanticAnalysis(root->firstChild); 
    semanticAnalysis(root->nextSibling);
}