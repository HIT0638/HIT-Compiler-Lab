%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "y.tab.h" 
#include "tokens.h"
#include "ast.h"

yylineno = 1;
void yyerror(const char* msg);
void unrecognized_char(char c);

// #define _DUPTEXT { yyval = strdup(yytext) }
%}

/* 使用yylineno */
%option yylineno

/* TODO: the definition of TOKEN */
INTEGER             0[xX][0-9a-fA-F]+ | 0[0-7]+ | [0-9]+ /* 十六进制， 八进制， 十进制 */
FLOATNUM               ([0-9]+\.[0-9]+|\.[0-9]+|[0-9]+[eE][-+]?[0-9]+)([eE][-+]?[0-9]+)? /* 包括科学计数法形式 */
IDENTIFIER          [a-zA-Z_][a-zA-Z_0-9]*
/* RELOPERATOR         ">="|"<="|"=="|"!="|">"|"<" */
WHITESPACE          ([ \t\n]+)
TYPE                int | float


%%
/* TODO : the definition of RULES */
{INTEGER}               { return INT;   }
/* {RELOPERATOR}           { return RELOP;         } */
{FLOATNUM}                 { return FLOAT;         }
{IDENTIFIER}            { return ID;            }
{TYPE}  { 
    // yylval = yytext;
    return TYPE;
}

">="                    { return RELOP; }
"<="                    { return RELOP; }
"=="                    { return RELOP; }
"!="                    { return RELOP; }
">"                     { return RELOP; }
"<"                     { return RELOP; }
"'"                     { return SEMI;      }
","                     { return COMMA;     }
"="                     { return ASSIGNOP;  }
"+"                     { return PLUS;      }
"-"                     { return MINUS;     }     
"*"                     { return STAR;      }
"/"                     { return DIV;       }
"&&"                    { return AND;       }
"||"                    { return OR;        }
"."                     { return DOT;       }
"!"                     { return NOT;       }
"("                     { return LP;        }
")"                     { return RP;        }
"["                     { return LB;        }
"]"                     { return RB;        }
"{"                     { return LC;        }
"}"                     { return RC;        }
"struct"                { return STRUCT;    }
"return"                { return RETURN;    }           
"if"                    { return IF;        }
"else"                  { return ELSE;      }
"while"                 { return WHILE;     }
/* other rules */

{WHITESPACE}            { /* ignore every whitespace & \t & lines*/}
/* \n                      { cur_line++; } */

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
            return;
        }
    }
}

.                       { unrecognized_char(yytext[0]); }

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

    yylex();
    fclose(file);
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
