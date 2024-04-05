#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>

/* TYPE DEFINITION */

// type definition of lexical unit
typedef enum Type
{
    T_INT,
    T_HEX,
    T_OCT,
    T_FLOAT,
    T_ID,
    T_TYPE,
    T_OTHER,
    NON_T // 非终结符
} Type;

// Node of the syntax tree
typedef struct TreeNode {
    int lineno; // line number of the lexical unit
    Type type; // type of the lexical unit
    char* value; // value of the lexical unit(yytext)
    struct TreeNode* firstChild, * nextSibling;
} TreeNode;

typedef TreeNode* pNode;

// create a new tree node to connect several child node
pNode createNode(int _lineno, Type _type, char* _value, int args, ...);
void delTree(pNode root);
void printTree(pNode root, int i);

#endif