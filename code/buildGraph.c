#include <stdio.h>
#include "AST.h"
#include <queue>
extern AST_pNode_t root;
extern int yyparse();
std::queue<AST_pNode_t> q;
char label[80][20] = {"e_program", "e_program_head", "e_routine", "e_sub_routine",
    "e_routine_head", "e_label_part", "e_const_part", "e_const_expr_list",
    "e_const_value", "e_type_part", "e_type_decl_list", "e_type_definition", "e_type_decl",
    "e_simple_type_decl", "e_array_type_decl", "e_record_type_decl", "e_field_decl_list",
    "e_field_decl", "e_name_list", "e_var_part", "e_var_decl_list", "e_var_decl", "e_routine_part",
    "e_function_decl", "e_function_head",
    "e_procedure_decl", "e_procedure_head",
    "e_parameters", "e_para_decl_list", "e_para_type_list", "e_var_para_list", "e_val_para_list",
    "e_routine_body", "e_compound_stmt", "e_stmt_list", "e_stmt",
    "e_non_label_stmt", "e_assign_stmt", "e_proc_stmt", "e_if_stmt",
    "e_else_clause", "e_repeat_stmt", "e_while_stmt", "e_for_stmt", "e_direction",
    "e_case_stmt", "e_case_expr_list", "e_case_expr", "e_goto_stmt",
    "e_expression_list", "e_expression", "e_expr", "e_term", "e_factor", "e_args_list",
    // some terminals also need to be defined
    "e_NAME", 
    //e_DOT, // TODO: is e_DOT needed?
    "e_MUL", "e_DIV", "e_UNEQUAL", "e_NOT", "e_PLUS", "e_MINUS", "e_GE", "e_GT",
    "e_LE", "e_LT", "e_EQUAL", "e_MOD", "e_AND", "e_OR",
    "e_SYS_CON", "e_SYS_FUNCT", "e_SYS_PROC", "e_SYS_TYPE", 
    "e_READ",//TODO: what's this?
    "e_INTEGER", "e_REAL", "e_CHAR",
    "e_TO", "e_DOWNTO" // note these two nodes}
};

void traverse(FILE * fp, AST_pNode_t p)
{
    q.push(p);
    while(!q.empty())
    {
        AST_pNode_t father = q.front();
        q.pop();
        fprintf(fp , "_%p[label=%s]\n", father, label[father->type]);
        AST_pNode_t child = father->child;
        while (child != NULL) {
          fprintf(fp, "_%p -> _%p\n", father, child);
          q.push(child);
          child = child->sibling;
        }
    }
}


int main()
{
    FILE * fp;

    fp = fopen("./AST.dot", "w+");
    fprintf(fp, "digraph AST {\n ");
    yyparse();
    AST_pNode_t p = root;
    traverse(fp, root);
    fprintf(fp, "}\n");

    return 0;
}
