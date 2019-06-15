#include "AST.h"
#include "codegen.h"
#include <stdio.h>
#include <queue>
extern AST_pNode_t root;
extern int yyparse();
std::queue<AST_pNode_t> q;
void traverse(AST_pNode_t p)
{
    q.push(p);
    while(!q.empty())
    {
        AST_pNode_t tmp = q.front();
        q.pop();
        printf("%d ", tmp->type);
        if(tmp->type == e_NAME || tmp->type == e_SYS_TYPE)
            printf("%s\n", tmp->data.text);
        AST_pNode_t tmp2 = tmp->child;
        if(tmp2 != NULL)
        {
            q.push(tmp2);
            tmp = tmp2->sibling;
            while(tmp != NULL)
            {
                q.push(tmp);
                tmp = tmp->sibling;
            }
        }
    }
}
int main(int argc, char** argv)
{
    yyparse();
    //AST_pNode_t p = root;
    //traverse(root);
    //printf("root : %d child : %d", root->type, root->child->sibling->type);
    CodeGen *ptr = new CodeGen;
    ptr->G_program(root);
    ptr->print();
    return 0;
}