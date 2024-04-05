%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
// #include "y.tab.h" 
#include "tokens.h"
// #include "ast.h"

// yylineno = 1;
void yyerror(const char* msg);
void unrecognized_char(char c);

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
{STRUCT}             { printf("STRUCT\n");  }
{RETURN}               { printf("RETURN\n");  }           
{IF}                 { printf("IF\n");  }
{ELSE}                  { printf("ELSE\n");  }
{WHILE}                 { printf("WHILE\n"); }
{TYPE}                  { printf("TYPE\n"); }
{INT}               { printf("INT\n");  }
{HEX}           { printf("HEX\n"); }
{OCT}           { printf("OCT\n"); }
{RELOP}               { printf("RELOP\n"); }
{FLOAT}              { printf("FLOAT\n");  }
{ID}            { printf("ID\n");  }


";"                     { printf("SEMI\n"); } 
","                     { printf("COMMA\n"); }
"="                     { printf("ASSIGNOP\n");  }
"+"                     { printf("PLUS\n");  }
"-"                     { printf("MINUS\n"); }     
"*"                     { printf("STAR\n"); }
"/"                     { printf("DIV\n"); }
"&&"                    { printf("AND\n"); }
"||"                    { printf("OR\n");  }
"."                     { printf("DOT\n");  }
"!"                     { printf("NOT\n");  }
"("                     { printf("LP\n");  }
")"                     { printf("RP\n"); }
"["                     { printf("LB\n");  }
"]"                     { printf("RB\n");}
"{"                     { printf("LC\n"); }
"}"                     { printf("RC\n"); }


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

{OCTERROR}  {printf("Error type A at Line %d: Illegal octal number \'%s\'\n", yylineno, yytext); }
{HEXERROR} {printf("Error type A at Line %d: Illegal hexadecimal number \'%s\'\n", yylineno, yytext); }
{DECERROR} {printf("Error type A at Line %d: Illegal decimal number \'%s\'\n", yylineno, yytext); }
{FLOATERROR} {printf("Error type A at Line %d: Illegal floating number \'%s\'\n", yylineno, yytext);  }
.   {printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext); }

%%

int main(int argc, char** argv)
{
    if (argc > 1){
        // read the input file as yyin
        FILE* file;
        file = fopen(argv[1], "r");
        if(!file){
            fprintf(stderr, "Could not open file %s\n", argv[1]);
            exit(1);
        }

        yyin = file;
    }

    while(yylex() != 0);
}

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
