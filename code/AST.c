#include "AST.h"
void InitNode(AST_pNode_t * ppNode)
{
    *ppNode = (AST_pNode_t)malloc(sizeof(AST_Node_t));
    (*ppNode)->child = (*ppNode)->sibling = NULL;
    (*ppNode)->line = 0;
}