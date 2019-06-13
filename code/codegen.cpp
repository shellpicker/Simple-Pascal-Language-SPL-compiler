#include "codegen.h"
using namespace std;
int CodeGen::G_SYS_CON(AST_pNode_t p)
{
    if(strcmp(p->child->data.text, "maxint") == 0)
        return MAXINT;
    if(strcmp(p->child->data.text, "true") == 0)
        return 1;
    if(strcmp(p->child->data.text, "false") == 0)
        return 0;
}
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
    Function * f_program = Function::Create(ftype, Function::InternalLinkage, p_NAME->data.text, theModule.get());
    BasicBlock *bblock = BasicBlock::Create(theContext, "entry", f_program);
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
    SymTblItem * pSym = G_const_value(p_const_value);;
    
    pushIdTable(std::string(p_Name->data.text), pSym);
    return NULL;
}
SymTblItem * CodeGen::G_const_value(AST_pNode_t p)
{
    SymTblItem * pSym = new SymTblItem();
    pSym->isConst = 1;
    /*TODO */
    switch (p->child->type)
    {
    case e_INTEGER:
        pSym->myType = new BasicType(e_integer);
        pSym->value = ConstantInt::get(theContext, APInt(32, p->child->data.int_value));
        break;
    case e_REAL:
        pSym->myType = new BasicType(e_real);
        pSym->value = ConstantFP::get(theContext, APFloat(p->child->data.real_value));
        break;
    case e_CHAR:
        pSym->myType = new BasicType(e_char);
        pSym->value = ConstantInt::get(theContext, APInt(8, p->child->data.ch_value));
        break;
    case e_SYS_CON:
        int v = G_SYS_CON(p->child);
        pSym->value = ConstantInt::get(theContext, APInt(32, v));
        if(v == MAXINT)
            pSym->myType = new BasicType(e_integer);
        else
            pSym->myType = new BasicType(e_boolean);
        break;
    default:
        break;
    }
    return pSym;
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
    SymTblItem * pSym = new SymTblItem;
    pSym->myType = G_type_decl(p_NAME->sibling);
    pushTypeTable(std::string(p_Name->data.text), pSym);
    return NULL;
}
BasicType * CodeGen::G_type_decl(AST_pNode_t p)
{
    if(p->child->type == e_simple_type_decl)
        return G_simple_type_decl(p->child);
    // TODO: array and record
}
BasicType * CodeGen::G_simple_type_decl(AST_pNode_t p)
{
    BasicType * myType;
    switch(p->child->type)
    {
        case e_SYS_TYPE:
            myType = new BasicType(G_SYS_TYPE(p->child));
            break;
        case e_NAME:
            if(!checkType(p->child->data.text))
            {// TODO: type undefined
                G_error(p);
                return NULL;
            }
            myType = new UserDefinedType;
            static_cast<UserDefinedType *>(myType)->name = 
                std::string(p->child->data.text);
            break;
        // TODO: enum, subrange
        default:
            return NULL;
    }
    return myType;
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
        SymTblItem * pSym = new SymTblItem;
        pSym->myType = G_type_decl(p_type_decl);
        AllocLocal(pSym);
        pushIdTable(list[i], pSym);
    }
}
void CodeGen::AllocLocal(SymTblItem * pSym)
{
    pSym->type = typeof(pSym->myType);
    AllocaInst *alloc = new AllocInst(pSym->type, pSym->name.cstr(), currentBlock());
    pSym->value = alloc;

}
// translate our defined types to llvm Type*
// TODO: pointer?
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
    AST_pNode_t p_function_decl = p->child;
    if(p->child->type == e_routine_part)
    {
        G_routine_part(p->child);
        p_function_decl = p->child->sibling;
    }
    if(p_function_decl->type == e_function_decl)
        G_function_decl(p_function_decl);
    else if(p_function_decl->type == e_procedure_decl)
        G_procedure_decl(p_function_decl);
    
}
Function* CodeGen::G_function_decl(AST_pNode_t p)
{
    Function* func = G_function_head(p->child);
    Value* retVal = G_routine(p->child->sibling);
    Builder.CreateRet(retVal);
    popBlock();
    // update the builder
    Builder.SetInsertPoint(currentBlock());
    return func;
}
Function* CodeGen::G_function_head(AST_pNode_t p)
{
    AST_pNode_t p_NAME = p->child;
    AST_pNode_t p_parameters = p->child->sibling;
    AST_pNode_t p_simple_type_decl = p_parameters->sibling;

    if(currentTables()->checkFunc(p_NAME->data.text))
    {
        // TODO function defined before
        return NULL;
    }
    vector<Type *> argTypes;
    vector<string> argNames;
    // push a null block first first so that parameters can
    // be stored in symbol table
    pushBlock(NULL); 
    if(p_parameters->child != NULL)
        G_para_decl_list(p_parameters->child, argNames, argTypes);
    BasicType * p_retType = G_simple_type_decl(p_simple_type_decl);
    retType = typeof(p_retType);
    FunctionType * ftype = FunctionType::get(retType, argTypes, false);
    Function * function = Function::Create(ftype, Function::ExternalLinkage, p_NAME->data.text, theModule.get());
    unsigned int index = 0;
    for(auto & Arg: function->args())
        Arg.setName(argNames[index++]);
    currentBlock() = BasicBlock::Create(theContext, p_NAME->data.text, function);
    Builder.SetInsertPoint(currentBlock());
    unsigned int index = 0;
    for (auto & Arg: function->args())
    {
        currentTables()->idTable[argNames[index++]]->value = &Arg;
    }
    // update the function table, remember not to update current function table
    lastLastTables()->namedFuncs[string(p_NAME->data.text)] = function;
    return function;
}
// inserting IDs to symbol table will be done here
void CodeGen::G_para_decl_list(AST_pNode_t p, vector<string>& names, vector<Type*> &types)
{
    AST_pNode_t p_para_type_list = p->child;
    if(p->child->type == e_para_decl_list)
    {
        G_para_decl_list(p->child);
        p_para_type_list = p->child->sibling;
    }
    //  G_para_type_list(p_para_type_list, list);
    vector<string> nameList;
    AST_pNode_t p_name_list = p_para_type_list->child->child;
    AST_pNode_t p_simple_type_decl = p_para_type_list->child->sibling;
    G_name_list(p_name_list, nameList);
    BasicType * myType = G_simple_type_decl(p_simple_type_decl);
    for(int i = 0; i < nameList.size(); i++)
    {
        if(currentTables()->checkId(nameList[i].c_str()))
        {
            //TODO: id defined before
            return;
        }
        SymTblItem * pItem = new SymTblItem;
        pItem->myType = myType;
        if(p_para_type_list->child->type == e_var_para_list)
        {
            pItem->isPtr = 1;

        }
        else
            types.push_back(typeof(myType));
        pushIdTable(nameList[i], pItem);
        names.push_back(nameList[i]);
        
    }
}
//void CodeGen::G_para_type_list