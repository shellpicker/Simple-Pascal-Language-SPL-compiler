#include "AST.h"
#include "codegen.h"
#include <stdio.h>
extern AST_pNode_t root;
extern int yyparse();
int main(int argc, char** argv)
{
    yyparse();
    CodeGen *ptr = new CodeGen;
    ptr->G_program(root);
    ptr->print();
    return 0;
}