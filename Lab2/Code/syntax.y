%{
    /* 注意 YYSTYPE 的define 需在前面，否则会造成yylval的type conflict*/
#define YYSTYPE TreeNode* 
#include "ast.h"
#include "lex.yy.c"
#define YYERROR_VERBOSE 1
extern int syntax_error;
void yyerror(const char* msg);

pNode root;

static int error_reported = 0;
%}

%error-verbose

// terminal tokens
%token INT
%token FLOAT
%token ID   // identifier
%token TYPE // type
%token RELOP
%token ASSIGNOP //=
%token PLUS MINUS STAR DIV  // operator
%token AND OR NOT // logical operator
%token DOT COMMA SEMI LP RP LB RB LC RC // punctuation
%token STRUCT RETURN IF ELSE WHILE    // keyword
%token ERRORNUM

// non-terminals
%type Program ExtDefList ExtDef ExtDecList   //  High-level Definitions
%type Specifier StructSpecifier OptTag Tag   //  Specifiers
%type VarDec FunDec VarList ParamDec         //  Declarators
%type CompSt StmtList Stmt                   //  Statements
%type DefList Def Dec DecList                //  Local Definitions
%type Exp Args                               //  Expressions

// precedence and associativity
/*
    %start: 开始符
    %left: 左结合
    %right: 右结合
    %nonassoc: 不可结合
    另外，排在后面的算符优先级高于排在前面的算符
*/
%start Program
%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS // 负号
%left STAR DIV
%right NOT
%left DOT
%left LB RB
%left LP RP
%nonassoc LOWER_THAN_ELSE /* 解决 悬空else问题 */ 
%nonassoc ELSE

%%

// High-level Definitions
/*
    Program 是整个程序的根节点，它包含一个或多个外部定义（如全局变量定义、函数定义等）。
*/
Program : ExtDefList {$$ = createNode(@$.first_line, NON_T, "Program", 1, $1); root = $$;}
;

/*
    ExtDefList 是一个递归结构，允许多个外部定义连续出现。当没有更多外部定义时，这个规则归约为空。
*/
ExtDefList : ExtDef ExtDefList {$$ = createNode(@$.first_line, NON_T, "ExtDefList", 2, $1, $2);}
|   { $$ = NULL;}
;

/*
    ExtDef 是外部定义
    第一个规则处理全局变量声明，如 int a, b, c;。
    第二个规则可能处理不带变量的类型声明，通常用于结构体或联合体的声明。
    第三个规则处理函数定义，包括函数的返回类型（由 Specifier 指定），函数名和参数（由 FunDec 指定），以及函数体（由 CompSt 即复合语句指定）。
*/
ExtDef : Specifier ExtDecList SEMI  { $$ = createNode(@$.first_line, NON_T, "ExtDef", 3, $1, $2, $3);}
| Specifier SEMI  {$$ = createNode(@$.first_line, NON_T, "ExtDef", 2, $1, $2);}
| Specifier FunDec CompSt   {$$ = createNode(@$.first_line, NON_T, "ExtDef", 3, $1, $2, $3);}
// error handling
| error SEMI  {syntax_error = 1;}
| Specifier error SEMI {syntax_error = 1;}
| error Specifier SEMI {syntax_error = 1;}
;
ExtDecList : VarDec {$$ = createNode(@$.first_line, NON_T, "ExtDecList", 1, $1);}
| VarDec COMMA ExtDecList   {$$ = createNode(@$.first_line, NON_T, "ExtDecList", 3, $1, $2, $3);}
// error handling
| VarDec error ExtDefList {syntax_error = 1;}
;

// Specifiers
/*
    Specifier 类型说明符
    处理基本类型（如 int、float）或结构体类型。
    类型的具体名字（如 int、float）是由 TYPE 词法单元提供的。
*/
Specifier : TYPE    {$$ = createNode(@$.first_line, NON_T, "Specifier", 1, $1);}
| StructSpecifier   {$$ = createNode(@$.first_line, NON_T, "Specifier", 1, $1);}
;

/*
    StructSpecifier 结构体说明符
    第一个规则定义了一个带有可选标签（名称）的完整结构体，其成员由 DefList 定义。
    第二个规则可能用于声明一个已命名的结构体类型，而不定义其内容。
*/
StructSpecifier : STRUCT OptTag LC DefList RC   { $$ = createNode(@$.first_line, NON_T, "StructSpecifier", 5, $1, $2, $3, $4, $5);}
| STRUCT Tag    { $$ = createNode(@$.first_line, NON_T, "StructSpecifier", 2, $1, $2);}
;
OptTag :  ID    {$$ = createNode(@$.first_line, NON_T, "OptTag", 1, $1);}
| {$$ = NULL;}
;
Tag : ID    {$$ = createNode(@$.first_line, NON_T, "Tag", 1, $1);}
;

// Declarators
/*
    VarDec 变量声明
    第一个规则处理单个变量名的声明。
    第二个规则处理数组声明，其中LB和RB代表左右方括号，INT是数组的大小。这允许递归定义多维数组，例如int a[10][20];。
*/
VarDec : ID { $$ = createNode(@$.first_line, NON_T, "VarDec", 1, $1);}
| VarDec LB INT RB  {$$ = createNode(@$.first_line, NON_T, "VarDec", 4, $1, $2, $3, $4);}
// error handling
| VarDec LB error RB { syntax_error = 1; }
| error RB { syntax_error = 1; }
;

/*
    FunDec 函数声明
    第一个规则定义了一个具有参数列表的函数，VarList描述了函数的参数。
    第二个规则定义了一个无参数的函数。ID代表函数名，LP和RP代表左右括号。
*/
FunDec : ID LP VarList RP   {$$ = createNode(@$.first_line, NON_T, "FunDec", 4, $1, $2, $3, $4);}
| ID LP RP  {$$ = createNode(@$.first_line, NON_T, "FunDec", 3, $1, $2, $3);}
// error handling
| ID LP error RP { syntax_error = 1; }
| error LP VarList RP { syntax_error = 1; }
;


VarList : ParamDec COMMA VarList    { $$ = createNode(@$.first_line, NON_T, "VarList", 3, $1, $2, $3);}
| ParamDec  { $$ = createNode(@$.first_line, NON_T, "VarList", 1, $1);}
;

/*
    参数声明
    这个规则用于声明函数的单个参数，其中Specifier确定参数的类型，VarDec确定参数的名字和可能的数组维度。
*/
ParamDec : Specifier VarDec { $$ = createNode(@$.first_line, NON_T, "ParamDec", 2, $1, $2);}
;

// Statements 移入规约冲突
/*
    ComSt 复合语句，即函数体
    描述了一个由大括号包围的代码块，其中可能包含局部变量定义（DefList）和一系列语句（StmtList）。
*/
CompSt : LC DefList StmtList RC {$$ = createNode(@$.first_line, NON_T, "CompSt", 4, $1, $2, $3, $4);}
// error handling
| error RC{ syntax_error = 1; }
;

/*
    StmtLits和Stmt 是语句列表和单个语句
    StmtList 表示一个可能为空的语句序列。
    Exp SEMI 是表达式语句，执行一个表达式并丢弃结果。
    CompSt 是复合语句，用于函数体或任何由花括号包围的代码块。
    RETURN Exp SEMI 处理返回语句。
    IF 和 WHILE 语句实现控制流，支持条件执行和循环。
*/
StmtList : Stmt StmtList { $$ = createNode(@$.first_line, NON_T, "StmtList", 2, $1, $2);}
| /* empty */  {$$ = NULL;}
;
Stmt : Exp SEMI {$$ = createNode(@$.first_line, NON_T, "Stmt", 2, $1, $2);}
| CompSt    { $$ = createNode(@$.first_line, NON_T, "Stmt", 1, $1);}
| RETURN Exp SEMI   { $$ = createNode(@$.first_line, NON_T, "Stmt", 3, $1, $2, $3);}
| IF LP Exp RP Stmt error {
    printf("Error at line %d: missing ';'\n", @5.last_line);
    syntax_error = 1;
}
| IF LP Exp RP Stmt %prec LOWER_THAN_ELSE   {$$ = createNode(@$.first_line, NON_T, "Stmt", 5, $1, $2, $3, $4, $5);}
| IF LP Exp RP Stmt ELSE Stmt   {$$ = createNode(@$.first_line, NON_T, "Stmt", 7, $1, $2, $3, $4, $5, $6, $7);}
| WHILE LP Exp RP Stmt  { $$ = createNode(@$.first_line, NON_T, "Stmt", 5, $1, $2, $3, $4, $5);}
// error handling
| error SEMI    {syntax_error = 1;}
| Exp error SEMI {syntax_error = 1;}
| RETURN Exp error  {syntax_error = 1;}
| RETURN error SEMI  {syntax_error = 1;}
;

// Local Definitions
/*
    DecList和Def 定义和声明列表
    DecList 允许多个声明在一个定义中出现，用逗号分隔。这常见于变量声明中，例如 int x, y, z;
    Def 处理局部或全局变量的定义，包括类型（由 Specifier 提供）和一个或多个具体的声明（由 DecList 提供），结尾有分号。
*/
DefList : Def DefList   {$$ = createNode(@$.first_line, NON_T, "DefList", 2, $1, $2);}
| /* empty */   {$$ = NULL;}
;
Def : Specifier DecList SEMI    {$$ = createNode(@$.first_line, NON_T, "Def", 3, $1, $2, $3);}
// error handling
| Specifier error SEMI {syntax_error = 1;}
| Specifier DecList error {syntax_error = 1;}
;
DecList : Dec   { $$ = createNode(@$.first_line, NON_T, "DecList", 1, $1);}
| Dec COMMA DecList {$$ = createNode(@$.first_line, NON_T, "DecList", 3, $1, $2, $3);}
;

/*
    Dec 单个声明
    Dec 用于处理单个变量的声明。如果有初始化（即赋值操作），则同时包括变量声明和初始化表达式。
*/
Dec : VarDec    {$$ = createNode(@$.first_line, NON_T, "Dec", 1, $1);}
| VarDec ASSIGNOP Exp   {$$ = createNode(@$.first_line, NON_T, "Dec", 3, $1, $2, $3);}
;

// Expressions
/*
    Exp 表达式
    这些规则涵盖了各种算术、逻辑、条件和函数调用表达式，以及数组和结构体的访问。
    表达式的结构和操作决定了它们的语义行为，例如赋值、比较、算术运算等。
*/
Exp : Exp ASSIGNOP Exp  {$$ = createNode(@$.first_line, NON_T, "Exp", 3, $1, $2, $3);}
| Exp AND Exp   {$$ = createNode(@$.first_line, NON_T, "Exp", 3, $1, $2, $3);}
| Exp OR Exp    {$$ = createNode(@$.first_line, NON_T, "Exp", 3, $1, $2, $3);}
| Exp RELOP Exp { $$ = createNode(@$.first_line, NON_T, "Exp", 3, $1, $2, $3);}
| Exp PLUS Exp  { $$ = createNode(@$.first_line, NON_T, "Exp", 3, $1, $2, $3);}
| Exp MINUS Exp {$$ = createNode(@$.first_line, NON_T, "Exp", 3, $1, $2, $3);}
| Exp STAR Exp  { $$ = createNode(@$.first_line, NON_T, "Exp", 3, $1, $2, $3);}
| Exp DIV Exp   { $$ = createNode(@$.first_line, NON_T, "Exp", 3, $1, $2, $3);}
| LP Exp RP {$$ = createNode(@$.first_line, NON_T, "Exp", 3, $1, $2, $3);}
| MINUS Exp { $$ = createNode(@$.first_line, NON_T, "Exp", 2, $1, $2);}
| NOT Exp   {$$ = createNode(@$.first_line, NON_T, "Exp", 2, $1, $2);}
| ID LP Args RP { // 函数调用
    $$ = createNode(@$.first_line, NON_T, "Exp", 4, $1, $2, $3, $4);}
| ID LP RP  {$$ = createNode(@$.first_line, NON_T, "Exp", 3, $1, $2, $3);}
| Exp LB Exp RB { // 数组
    $$ = createNode(@$.first_line, NON_T, "Exp", 4, $1, $2, $3, $4);}
| Exp DOT ID    { $$ = createNode(@$.first_line, NON_T, "Exp", 3, $1, $2, $3);}
| ID    {$$ = createNode(@$.first_line, NON_T, "Exp", 1, $1);}
| INT   {$$ = createNode(@$.first_line, NON_T, "Exp", 1, $1);}
| FLOAT { $$ = createNode(@$.first_line, NON_T, "Exp", 1, $1);}
// error handling
| ERRORNUM {$$ = createNode(@$.first_line, NON_T, "Exp", 1, $1);syntax_error = 1;}
| Exp LB Exp error RB { // 处理数组[...]中的错误
    syntax_error = 1;
    // yyerror("Missing \"]\"");
}
;

Args : Exp COMMA Args   {$$ = createNode(@$.first_line, NON_T, "Args", 3, $1, $2, $3);}
| Exp   {$$ = createNode(@$.first_line, NON_T, "Args", 1, $1);}
;

%%

// the yyerror function is mainly for the syntax error (type B)
void yyerror(const char* msg){
    fprintf(stderr, "Error type B at line %d: %s.\n", yylineno, msg);
}

