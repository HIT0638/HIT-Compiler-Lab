#ifndef __SEMANTIC_H
#define __SEMANTIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include "ast.h"

typedef struct Type_* Type;
typedef struct FieldList_* FieldList;
typedef enum {BASIC, ARRAY, STRUCTURE} Kind;
typedef enum {B_INT, B_FLOAT} Basic_Type;

typedef struct Type_ {
    Kind kind;
    union { 
        // 基本类型 INT/FLOAT
        Basic_Type basic;

        // 数组类型 
        struct { Type elem; int size; } array;

        // 结构体类型,FileList表示
        FieldList structure;
    } u;
} Type_;

// 结构体，用链表的形式来存储结构体数据
// 同时作链表设计的符号表数据结构
typedef struct FieldList_ {
    char* name;
    Type type;
    FieldList tail;
} FieldList_ ;

void initSymbolTable();
int checkSame(FieldList field);
void addSymbol(FieldList field);
FieldList searchSymbol(char* name);
void deleteField(FieldList field);

Type createType(Kind kind, int num, ...);
FieldList createField();


void ExtDef(pNode root);
Type Specifier(pNode root);
void ExtDecList(pNode root, Type type);
void VarDec(pNode root, Type type);
void Def(pNode root);
void DecList(pNode root, Type type);
void Dec(pNode root, Type type);
Type Exp(pNode root);

void semanticAnalysis(pNode root);

#endif

