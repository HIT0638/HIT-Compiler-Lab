%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "syntax.tab.h" // from bison
// #include "tokens.h"
#include "ast.h"

extern int lexical_error;

void yyerror(const char* msg);
void unrecognized_char(char c);

// 维护语法单元对应的第一个词素的行号和列号
int ycolumn = 1;
#define YY_USER_ACTION
/* yylloc -> lex location 表示当前词法单元对应的信息位置 */
    yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; \
    yylloc.last_column = yycolumn + yyleng - 1;
    yycolumn += yyleng;
// #define _DUPTEXT { yyval = strdup(yytext) }
%}

/* 使用yylineno */
%option yylineno

/* TODO: the definition of TOKEN */
INT 0|([1-9][0-9]*)
DECERROR [0-9]+[a-wA-Wy-zY-Z]+[0-9a-dA-Df-zF-Z]*|[0-9]+[0-9]+[a-dA-Df-zF-Z]+[0-9]*[0-9a-dA-Df-zF-Z]*
OCT 0[0-7]+
OCTERROR 0[0-7]*[8-9]+[0-9]*
HEX 0[xX][0-9a-fA-F]+
HEXERROR 0[xX][0-9a-fA-F]*[g-zG-Z]+[0-9a-zA-Z]*
FLOAT   [0-9]+\.[0-9]+([eE][+-]?[0-9]+)?|[0-9]+[eE][+-]?[0-9]+|\.[0-9]+|[0-9]+\.|[eE][+-]?[0-9]+|[.][0-9]+[Ee][+-]?[0-9]+|[0-9]+\.[Ee][+-]?[0-9]+
FLOATERROR \.[eE][+-]?[0-9]+|[0-9]*\.[0-9]+[eE][+-]?|[0-9]+\.[0-9]*[eE][+-]?|[0-9]+[Ee][+-]?|\.[eE][+-]?
ID  [a-zA-Z_][a-zA-Z_0-9]*
RELOP       ">="|"<="|"=="|"!="|">"|"<"
TYPE    int|float
STRUCT  "struct"
RETURN  "return"
IF  "if"
ELSE    "else"
WHILE   "while"
BLANK   [ ]
TAB [\t]




%%
{STRUCT}          { yylval = createNode(yylineno, T_OTHER, "STRUCT", 0); return STRUCT; }
{RETURN}          { yylval = createNode(yylineno, T_OTHER, "RETURN", 0); return RETURN; }
{IF}              { yylval = createNode(yylineno, T_OTHER, "IF", 0); return IF; }
{ELSE}            { yylval = createNode(yylineno, T_OTHER, "ELSE", 0); return ELSE; }
{WHILE}           { yylval = createNode(yylineno, T_OTHER, "WHILE", 0); return WHILE; }
{TYPE}            { yylval = createNode(yylineno, T_TYPE, yytext, 0); return TYPE; }
{INT}             { yylval = createNode(yylineno, T_INT, yytext, 0); return INT; }
{HEX}             { yylval = createNode(yylineno, T_HEX, yytext, 0); return INT; } // HEX和OCT被视为INT类型
{OCT}             { yylval = createNode(yylineno, T_OCT, yytext, 0); return INT; }
{RELOP}           { yylval = createNode(yylineno, T_OTHER, "RELOP", 0); return RELOP; }
{FLOAT}           { yylval = createNode(yylineno, T_FLOAT, yytext, 0); return FLOAT; }
{ID}              { yylval = createNode(yylineno, T_ID, yytext, 0); return ID; }

";"               { yylval = createNode(yylineno, T_OTHER, "SEMI", 0); return SEMI; } 
","               { yylval = createNode(yylineno, T_OTHER, "COMMA", 0); return COMMA; }
"="               { yylval = createNode(yylineno, T_OTHER, "ASSIGNOP", 0); return ASSIGNOP; }
"+"               { yylval = createNode(yylineno, T_OTHER, "PLUS", 0); return PLUS; }
"-"               { yylval = createNode(yylineno, T_OTHER, "MINUS", 0); return MINUS; }     
"*"               { yylval = createNode(yylineno, T_OTHER, "STAR", 0); return STAR; }
"/"               { yylval = createNode(yylineno, T_OTHER, "DIV", 0); return DIV; }
"&&"              { yylval = createNode(yylineno, T_OTHER, "AND", 0); return AND; }
"||"              { yylval = createNode(yylineno, T_OTHER, "OR", 0); return OR; }
"."               { yylval = createNode(yylineno, T_OTHER, "DOT", 0); return DOT; }
"!"               { yylval = createNode(yylineno, T_OTHER, "NOT", 0); return NOT; }
"("               { yylval = createNode(yylineno, T_OTHER, "LP", 0); return LP; }
")"               { yylval = createNode(yylineno, T_OTHER, "RP", 0); return RP; }
"["               { yylval = createNode(yylineno, T_OTHER, "LB", 0); return LB; }
"]"               { yylval = createNode(yylineno, T_OTHER, "RB", 0); return RB; }
"{"               { yylval = createNode(yylineno, T_OTHER, "LC", 0); return LC; }
"}"               { yylval = createNode(yylineno, T_OTHER, "RC", 0); return RC; }


"//"                    {
    // 丢弃双斜线后，该行的所有字符
    char c = input();
    while(c != '\n') c = input();
}

"/*"                    {
    char a = input();
    char b = input();
    
    while( a != '*' || b != '/'){
        a = b;
        b = input();

        if( b == EOF ){
            printf("Error type B at Line %d: Missing */.\n",yylineno);
            break;
        }
    }
}
{BLANK} {}
{TAB}   { yycolumn += 3; }

\n|\r  { yycolumn = 1; }

{OCTERROR}  {printf("Error type A at Line %d: Illegal octal number \'%s\'\n", yylineno, yytext); yylval = NULL; lexical_error = 1; return ERRORNUM;}
{HEXERROR} {printf("Error type A at Line %d: Illegal hexadecimal number \'%s\'\n", yylineno, yytext); yylval = NULL; lexical_error = 1; return ERRORNUM;}
{DECERROR} {printf("Error type A at Line %d: Illegal decimal number \'%s\'\n", yylineno, yytext); yylval = NULL; lexical_error = 1; return ERRORNUM;}
{FLOATERROR} {printf("Error type A at Line %d: Illegal floating number \'%s\'\n", yylineno, yytext); yylval = NULL; lexical_error = 1; return ERRORNUM;}
.   {printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext); lexical_error = 1;}

%%

// the yyerror function is mainly for the syntax error (type B)
void yyerror(const char* msg){
    fprintf(stderr, "Error type B at line %d: %s.\n", yylineno, msg);
    return;
}
