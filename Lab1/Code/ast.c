/*
    some related data link；
        the introduce of 'strarg.h': https://cshihong.github.io/2017/10/23/stdarg-h%E7%AE%80%E4%BB%8B/
*/

#include "ast.h"

/*
    creatNode FUNC;
    create a new node.
    params:
        _lineno: the first line number of the Node(lexical unit)
        _type: the type of the lexical node
        _value: the value of the lexical node(yytext)
        args: the number of the childs of this node
        ...: childs(pNode) of this node
*/
pNode createNode(int _lineno, Type _type, char *_value, int args, ...)
{
    pNode currNode = (pNode)malloc(sizeof(TreeNode));
    assert(currNode == NULL);
    currNode->value = (char *)malloc(sizeof(char) * (strlen(_value) + 1));
    assert(currNode->value);

    // set values of currNode
    currNode->lineno = _lineno;
    currNode->type = _type;
    strncpy(currNode->value, _value, strlen(_value) + 1);

    currNode->firstChild = NULL;
    currNode->nextSibling = NULL;

    if (args > 0)
    { // if args == 0, means terminal nodes, no childs.
        va_list ap;
        va_start(ap, args);

        // set firstChild of currNode & set siblings of firstChild
        pNode tempNode = va_arg(ap, pNode);
        currNode->firstChild = tempNode;
        for (int i = 1; i < args; i++)
        {
            tempNode->nextSibling = va_arg(ap, pNode);
            if (tempNode->nextSibling == NULL)
            {
                break;
            }
            tempNode = tempNode->nextSibling;
        }
        va_end(ap);
    }

    return currNode;
}

/*
    delTree FUNC;
    Recursively delete a tree.
    params:
        root: pNode, the root of the tree to be deleted;
*/
void delTree(pNode root)
{
    if (root == NULL)
        return;

    pNode fChildNode = root->firstChild;
    free(root);
    while (fChildNode != NULL)
    {
        pNode nextNode = fChildNode->nextSibling;
        delTree(fChildNode);
        fChildNode = nextNode;
    }
}

/*
    printTree FUNC;

    params:
        root: pNode, the root of the tree to be printed;
        i: int, the line number of the node.
*/
void printTree(pNode root, int i)
{
    if (root == NULL)
        return;

    pNode nowNode = root;
    int n = i;

    while (nowNode != NULL)
    {
        while (n > 1)
        {
            print("  ");
            n--;
        }

        switch (nowNode->type)
        {
        case NON_T:
            printf("%s (%d)\n", nowNode->value, nowNode->lineno);
            break;

        case T_OTHER:
            printf("%s\n", nowNode->value);
            break;

        case T_TYPE:
            printf("TYPE: %s\n", nowNode->value);
            break;

        case T_INT:
            printf("INT: %d\n", atoi(nowNode->value));
            break;

        case T_HEX:
            printf("INT: %ld\n", strtol(nowNode->value, NULL, 16));
            break;

        case T_OCT:
            printf("INT: %ld\n", strtol(nowNode->value, NULL, 8));
            break;

        case T_FLOAT:
            printf("FLOAT: %f\n", atof(nowNode->value));
            break;

        case T_ID:
            printf("ID: %s\n", nowNode->value);
            break;

        default:
            
            break;
        }
        printTree(nowNode->firstChild, i + 1);
        nowNode = nowNode->nextSibling;
        n = i;
    }
}