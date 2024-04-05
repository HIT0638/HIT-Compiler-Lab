%{
#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"

extern int cur_line;

void yyerror(const char*);

// #define YYSTYPE char*;
%}

%union {
    int ival;
    float fval;
    char* sval;
    enum RelOp relOp;
}

%token <ival> INT TYPE_INT TYPE_FLOAT TYPE
%token <fval> FLOAT
%token <sval> ID
%token SEMI COMMA ASSIGNOP PLUS MINUS STAR DIV AND OR DOT NOT LP RP LB RB LC RC STRUCT RETURN IF ELSE WHILE
%token <relOp> RELOP

%type <ival> expression
%type <fval> float_expression

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
|   IF LP Exp RP Stmt           {}
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
        switch ($2) { // 根据第二个元素（RELOP Token）的值选择动作
            case GE:
                printf("Greater than or equal to operation\n");
                break;
            case LE:
                printf("Less than or equal to operation\n");
                break;
            case EQ:
                printf("Equal to operation\n");
                break;
            case NE:
                printf("Not equal to operation\n");
                break;
            case GT:
                printf("Greater than operation\n");
                break;
            case LT:
                printf("Less than operation\n");
                break;
            default:
                yyerror("Unknown relational operator");
        } 
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