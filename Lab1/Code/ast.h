#ifndef AST_H
#define AST_H

#include <stdio.h>

typedef enum {
    NodeType_SUnit, // 语法单元节点
    NodeType_LUnit // 词法单元节点
} NodeType;

typedef enum {
    LU_ID,
    LU_TYPE,
    LU_INT,
    LU_FLOAT,
    // more type of lexicalUnit...
} LUType;

typedef struct ASTNode {
    NodeType nodeType;
    int line; // 节点在源文件中的行号
    union {
        struct {
            struct ASTNode* child;
            struct ASTNode* next;
            char* unitName; // 语法单元名称
        } syntaxUnit;
        struct {
            LUType type; // 词法单元类型
            char* lexeme; // 词法单元词素
            union {
                int intValue;
                float floatValue;
                char* name;
                // 其他可能需要的值
            } value;
        } lexicalUnit;
    } data;
} ASTNode;

ASTNode* createNode_S(NodeType nodeType, int line, char* unitName);
ASTNode* createNode_L(NodeType nodeType, int line, LUType type, char* lexeme, auto value);
void printAST(ASTNode* node);

#endif