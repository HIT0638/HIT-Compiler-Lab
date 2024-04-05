%{
#define YYSTYPE TreeNode*;

#include "lex.yy.c"
#include "ast.h"

pNode root;

void yyerror(const char*);

%}

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
%token ERRORNUM ERRORID

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
%left PLUS MINUS UMINUS // 负号
%left STAR DIV
%right NOT
%left DOT
%left LB RB
%left LP RP
%nonassoc LOWER_THAN_ELSE /* 解决 悬空else问题 */ 
%nonassoc ELSE

%%

/* Hight-level Definitioins */
Program: ExtDefList
;

ExtDefList: ExtDef ExtDefList
|   { }
;

ExtDef: Specifier ExtDecList SEMI{}
|   Specifier SEMI             {}
|   Specifier FunDec CompSt     {}
;

ExtDecList: VarDec              {}
|   VarDec COMMA ExtDecList     {}
;

/* Specifiers */
Specifier: TYPE                 {}
|   StructSpecifier             {}
;

StructSpecifier: STRUCT OptTag LC DefList RC {}
|   STRUCT Tag                  {}
;

OptTag: ID                      {}
|                               {}
;

Tag: ID                         {}
;


/* Declarators */
VarDec: ID                      {}
|   VarDec LB INT RB            {}
;

FunDec: ID LP VarList RP        {}
| ID LP RP                      {}
;

VarList: ParamDec COMMA VarList {}
| ParamDec                      {}
;

ParamDec: Specifier VarDec      {}
;

/* Statements */
CompSt: LC DefList StmtList RC  {}
;

StmtList: Stmt StmtList         {}
|                               {}
;

Stmt: Exp SEMI                  {}
|   CompSt                      {}
|   RETURN Exp SEMI             {}
|   IF LP Exp RP Stmt %prec LOWER_THAN_ELSE    {}
|   IF LP Exp RP Stmt ELSE  Stmt{}
|   WHILE LP Exp RP Stmt        {}
;

/* Local Definitions */
DefList: Def DefList            {}
|                               {}
;

Def: Specifier DecList SEMI     {}
;

DecList: Dec                    {}
|   Dec COMMA DecList           {}
;

Dec: VarDec                     {}
| VarDec ASSIGNOP Exp           {}
;

/* Expressions */
Exp: Exp ASSIGNOP Exp           {}
| Exp AND Exp                   {}
| Exp OR  Exp                   {}
| Exp RELOP Exp                 
    {
         
    }
| Exp PLUS Exp                  {}
| Exp MINUS Exp                 {}
| Exp STAR Exp                  {}
| Exp DIV Exp                   {}
| LP Exp RP                     {}
| MINUS Exp                     {}
| NOT Exp                       {}
| ID LP Args RP                 {}
| ID LP RP                      {}
| Exp LB Exp RB                 {}
| Exp DOT ID                    {}
| ID                            {}
| INT                           {}
| FLOAT                         {}
;

Args:
;

%%

int main() {
    return yyparse();
}

void yyerror(const char* msg) {
    print("Error type A at Line %d: %s.\n", cur_line, msg)
}