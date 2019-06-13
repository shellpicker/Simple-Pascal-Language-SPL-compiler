#include "codegen.h"

Type_t CodeGen::G_SYS_TYPE(AST_pNode_t p)
{
    if(strcmp(p->data.text, "boolean") == 0)
        return e_boolean;
    if(strcmp(p->data.text, "char") == 0)
        return e_char;
    if(strcmp(p->data.text, "integer") == 0)
        return e_integer;
    if(strcmp(p->data.text, "real") == 0)
        return e_real;
}
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
    return NULL;
}
Value * CodeGen::G_type_decl_list(AST_pNode_t p)
{
    AST_pNode_t p_type_definition = p->child;
    if(p->child->type == e_type_decl_list)
    {
        G_type_decl_list(p->child);
        p_type_definition = p->child->sibling;
    }
    return G_type_definition(p_type_definition);
}
Value * CodeGen::G_type_definition(AST_pNode_t p)
{
    AST_pNode_t p_NAME = p->child;
    if(checkId(p_NAME->data.text) || checkType(p_NAME->data.text))
    {
        G_error(p_NAME);
    }
    SymTblItem * pSym = G_type_decl(p_NAME->sibling);
    pSym->name = std::string(p_NAME->data.text);
    pushTypeTable(pSym);
    return NULL;
}
SymTblItem * CodeGen::G_type_decl(AST_pNode_t p)
{
    if(p->child->type == e_simple_type_decl)
        return G_simple_type_decl(p->child);
    // TODO: array and record
}
SymTblItem * CodeGen::G_simple_type_decl(AST_pNode_t p)
{
    SymTblItem * pSym = new SymTblItem;
    switch(p->child->type)
    {
        case e_SYS_TYPE:
            pSym->myType = new BasicType(G_SYS_TYPE(p->child));
            break;
        case e_NAME:
            if(!checkType(p->child->data.text))
            {// TODO: type undefined
                G_error(p);
                return NULL;
            }
            pSym->myType = new UserDefinedType;
            static_cast<UserDefinedType *>(pSym->myType)->name = 
                std::string(p->child->data.text);
            break;
        // TODO: enum, subrange
        default:
            return NULL;
    }
    return pSym;
}
void CodeGen::G_name_list(AST_pNode_t p, std::vector<std::string> & list)
{
    AST_pNode_t p_NAME = p->child;
    if(p->child->type == e_name_list)
    {
        G_name_list(p->child, list);
        p_NAME = p->child->sibling;
    }
    list.push_back(std::string(p_NAME->data.text));
}
Value* CodeGen::G_var_decl_list(AST_pNode_t p)
{
    AST_pNode_t p_var_decl = p->child;
    if(p->child->type == e_var_decl_list)
    {
        G_var_decl_list(p->child);
        p_var_decl = p->child->sibling;
    }
    AST_pNode_t p_name_list = p_var_decl->child;
    AST_pNode_t p_type_decl = p_name_list->sibling;
    std::vector<std::string> list;
    G_name_list(p_name_list, list);
    for(int i = 0; i < list.size(); i++)
    {
        SymTblItem * pSym = G_type_decl(p_type_decl);
        pSym->name = list[i];
        AllocLocal(pSym);
        pushIdTable(pSym);
    }
}
void CodeGen::AllocLocal(SymTblItem * pSym)
{
    pSym->type = typeof(pSym->myType);
    AllocaInst *alloc = new AllocInst(pSym->type, pSym->name.cstr(), currentBlock());
    pSym->value = alloc;

}
Type* CodeGen::typeof(BasicType * ty)
{
    Type_t t = ty->type;
    switch (t)
    {
    case e_integer:
        return Type::getInt32Ty(theContext);
        break;
    case e_char:
        return Type::getInt8Ty(theContext);
        break;
    case e_boolean:
        return Type::getInt32Ty(theContext);
        break;
    case e_real:
        return Type::getDoubleTy(theContext);
        break;
    case e_userdefined:
        return typeof(findType(static_cast<UserDefinedType*>(ty)->name)->myType);
        break;
    default:
        break;
    }
}
Value* CodeGen::G_routine_part(AST_pNode_t p)
{
    if(p->child == NULL)
        return NULL;
    
}
Function* CodeGen::G_function_decl(AST_pNode_t p)
{

}