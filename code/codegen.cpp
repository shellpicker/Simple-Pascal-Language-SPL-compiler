#include "codegen.h"

void CodeGen::G_program(AST_pNode_t p)
{
    std::cout << "Generating program...\n";
    AST_pNode_t p_NAME = p->child->child;
    theModule = llvm::make_unique<Module>(p_NAME->data.text, theContext);

    FunctionType * ftype = FunctionType::get(Type::getVoidTy(theContext), std::vector<Type*>(), false);
    Function * f_program = Function::Create(ftype, GlobalValue::InternalLinkage, p_NAME->data.text, theModule);
    BasicBlock *bblock = BasicBlock::Create(theContext, "entry", f_program, 0);
    /* push a new context */
    pushBlock(bblock);
    G_routine(p->child->sibling);
    ReturnInst::Create(theContext, bblock);
    popBlock();
}
Value* CodeGen::G_routine(AST_pNode_t p)
{
    G_routine_head(p->child);
    AST_pNode_t p_routine_body = p->child->sibling;
    return G_compound_stmt(p_routine_body->child);
}
Value* CodeGen::G_routine_head(AST_pNode_t p)
{
    AST_pNode_t p_label_part, p_const_part, p_type_part, p_var_part, p_routine_part;
    p_label_part = p->child;
    p_const_part = p_label_part->sibling;
    p_type_part = p_const_part->sibling;
    p_var_part = p_type_part->sibling;
    p_routine_part = p_var_part->sibling;
    // label_part is ignored

    if(p_const_part->child != NULL)
        G_const_expr_list(p_const_part->child);
    if(p_type_part->child != NULL)
        G_type_decl_list(p_type_part->child);
    if(p_var_part->child != NULL)
        G_var_decl_list(p_var_part->child);
    if(p_routine_part->child != NULL)
        G_routine_part(p_routine_part->child);
    return NULL;
}
Value* CodeGen::G_const_expr_list(AST_pNode_t p)
{
    AST_pNode_t p_NAME, p_const_value;
    if(p->child->type == e_const_expr_list)
    {
        G_const_expr_list(p->child);
        p_NAME = p->child->sibling;
    }
    else
        p_NAME = p->child;
    p_const_value = p_NAME->sibling;

    if(checkId(p_NAME->data.text))
    {
        //TODO: generate error;
        G_error(p_NAME);
    }
    SymTblItem * pSym = new SymTblItem;
    pSym->isConst = 1;
    pSym->name = std::string(p_NAME->data.text);
    pSym->value = G_const_value(p_const_value);
    AST_pNode_t child = p_const_value->child;
    switch (child->type)
    {
    case e_INTEGER:
        pSym->myType = new BasicType(e_integer);
        break;
    case e_REAL:
        pSym->myType = new BasicType(e_real);
        break;
    case e_CHAR:
        pSym->myType = new BasicType(e_char);
        break;
    case e_SYS_CON:
    /*TODO */
        break;
    default:
        break;
    }
    pushIdTable(pSym); 
}