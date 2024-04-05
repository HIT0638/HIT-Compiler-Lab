%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// #include "syntax.tab.h" // from bison
// #include "tokens.h"
// #include "ast.h"

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
{STRUCT}          { return STRUCT; }
{RETURN}          { return RETURN; }
{IF}              { return IF; }
{ELSE}            { return ELSE; }
{WHILE}           { return WHILE; }
{TYPE}            { return TYPE; }
{INT}             { return INT; }
{HEX}             { return INT; } // HEX和OCT被视为INT类型
{OCT}             { return INT; }
{RELOP}           { return RELOP; }
{FLOAT}           { return FLOAT; }
{ID}              { return ID; }

";"               { return SEMI; } 
","               { return COMMA; }
"="               { return ASSIGNOP; }
"+"               { return PLUS; }
"-"               { return MINUS; }     
"*"               { return STAR; }
"/"               { return DIV; }
"&&"              { return AND; }
"||"              { return OR; }
"."               { return DOT; }
"!"               { return NOT; }
"("               { return LP; }
")"               { return RP; }
"["               { return LB; }
"]"               { return RB; }
"{"               { return LC; }
"}"               { return RC; }


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


\n  { yycolumn = 1; }

{OCTERROR}  {printf("Error type A at Line %d: Illegal octal number \'%s\'\n", yylineno, yytext); }
{HEXERROR} {printf("Error type A at Line %d: Illegal hexadecimal number \'%s\'\n", yylineno, yytext); }
{DECERROR} {printf("Error type A at Line %d: Illegal decimal number \'%s\'\n", yylineno, yytext); }
{FLOATERROR} {printf("Error type A at Line %d: Illegal floating number \'%s\'\n", yylineno, yytext);  }
.   {printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext); }

%%


/* Handle with error type A*/
void unrecognized_char(char c)
{
    char buf[32] = "Unrecognized character: ?";
    buf[24] = c;
    yyerror(buf);
}

void yyerror(const char* msg)
{
    printf("Error type A at Line %d: %s.\n", yylineno, msg);
}
