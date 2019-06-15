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
    G_error(p);
    return -1;
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
    G_error(p);
    return e_integer;
        
}
void CodeGen::G_program(AST_pNode_t p)
{
    
    AST_pNode_t p_NAME = p->child->child;
    theModule = llvm::make_unique<Module>(p_NAME->data.text, theContext);

    
    FunctionType * ftype = FunctionType::get(Type::getVoidTy(theContext), std::vector<Type*>(), false);
    Function * f_program = Function::Create(ftype, Function::ExternalLinkage, "main", theModule.get());
    BasicBlock *bblock = BasicBlock::Create(theContext, "entry", f_program);
    /* push a new context */
    pushBlock(bblock);
    theBuilder.SetInsertPoint(bblock);
    Init_write();
    Init_scanf();
    Init_printf();
    G_routine(p->child->sibling);
    theBuilder.CreateRetVoid();
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
        G_routine_part(p_routine_part);
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
    
    pushIdTable(std::string(p_NAME->data.text), pSym);
    return NULL;
}
SymTblItem * CodeGen::G_const_value(AST_pNode_t p)
{
    
    SymTblItem * pSym = new SymTblItem();
    pSym->isConst = 1;
    int v;
    /*TODO */
    switch (p->child->type)
    {
    case e_INTEGER:
        p->valueType = e_integer;
        pSym->myType = new BasicType(e_integer);
        pSym->value = ConstantInt::get(theContext, APInt(32, p->child->data.int_value));
        break;
    case e_REAL:
        p->valueType = e_real;
        pSym->myType = new BasicType(e_real);
        pSym->value = ConstantFP::get(theContext, APFloat(p->child->data.real_value));

        break;
    case e_CHAR:
        pSym->myType = new BasicType(e_char);
        pSym->value = ConstantInt::get(theContext, APInt(8, p->child->data.ch_value));
        break;
    case e_SYS_CON:
        v = G_SYS_CON(p->child);
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
    pushTypeTable(std::string(p_NAME->data.text), pSym);
    return NULL;
}
BasicType * CodeGen::G_type_decl(AST_pNode_t p)
{
    
    if(p->child->type == e_simple_type_decl)
        return G_simple_type_decl(p->child);
    // TODO: array and record
    G_error(p);
    return NULL;
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
    for(unsigned int i = 0; i < list.size(); i++)
    {
        SymTblItem * pSym = new SymTblItem;
        pSym->myType = G_type_decl(p_type_decl);
        AllocGlobal(pSym, list[i].c_str());
        pushIdTable(list[i], pSym);
    }
    return NULL;
}
void CodeGen::AllocLocal(SymTblItem * pSym, const char * name)
{
    
    pSym->type = typeOf(pSym->myType);
    AllocaInst *alloc = theBuilder.CreateAlloca(pSym->type, nullptr, name);
    pSym->value = alloc;
}
void CodeGen::AllocGlobal(SymTblItem * pSym, const char * name)
{
    pSym->type = typeOf(pSym->myType);
    theModule->getOrInsertGlobal(name, pSym->type);
    auto globalVar = theModule->getNamedGlobal(name);
    globalVar->setInitializer(ConstantAggregateZero::get(pSym->type));
    globalVar->setLinkage(GlobalVariable::InternalLinkage);
    globalVar->setAlignment(4);
    pSym->value = globalVar;
}

// translate our defined types to llvm Type*
// TODO: pointer?
Type* CodeGen::typeOf(BasicType * ty)
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
        return typeOf(findType(static_cast<UserDefinedType*>(ty)->name.c_str())->myType);
        break;
    default:
        return NULL;
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
    return NULL;
}
Function* CodeGen::G_function_decl(AST_pNode_t p)
{
    
    Function* func = G_function_head(p->child);
    G_routine(p->child->sibling);
    Value* retVal = currentTables()->findId(p->child->child->data.text)->value;
    theBuilder.CreateRet(theBuilder.CreateLoad(retVal));
    popBlock();
    // update the builder
    theBuilder.SetInsertPoint(currentBlock());
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
    BasicType * p_retType = G_simple_type_decl(p_simple_type_decl);
    Type* retType = typeOf(p_retType);
    
    // deal with parameters
    if(p_parameters->child != NULL)
        G_para_decl_list(p_parameters->child, argNames, argTypes);
    // create function
    FunctionType * ftype = FunctionType::get(retType, argTypes, false);
    Function * function = Function::Create(ftype, Function::ExternalLinkage, p_NAME->data.text, theModule.get());
    unsigned int index = 0;
    for(auto & Arg: function->args())
        Arg.setName(argNames[index++]);
    blocks.back()->block = BasicBlock::Create(theContext, "entry", function);
    theBuilder.SetInsertPoint(currentBlock());
    // set the return variable
    SymTblItem * pItem = new SymTblItem;
    pItem->myType = p_retType;
    AllocLocal(pItem, p_NAME->data.text);
    pushIdTable(std::string(p_NAME->data.text), pItem);
        // store the types of arguments
    lastLastTables()->funcArgTypes[std::string(p_NAME->data.text)] = argTypes;
    // allocate space for arguments
    index = 0;
    for (auto & Arg: function->args())
    {
        Value * addr = theBuilder.CreateAlloca(argTypes[index], nullptr, argNames[index]);
        theBuilder.CreateStore(&Arg, addr);
        currentTables()->idTable[argNames[index++]]->value = addr;
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
        G_para_decl_list(p->child, names, types);
        p_para_type_list = p->child->sibling;
    }
    //  G_para_type_list(p_para_type_list, list);
    vector<string> nameList;
    AST_pNode_t p_name_list = p_para_type_list->child->child;
    AST_pNode_t p_simple_type_decl = p_para_type_list->child->sibling;
    G_name_list(p_name_list, nameList);
    BasicType * myType = G_simple_type_decl(p_simple_type_decl);
    for(unsigned int i = 0; i < nameList.size(); i++)
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
            types.push_back(Type::getInt32PtrTy(theContext));
        }
        else
            types.push_back(typeOf(myType));
        pushIdTable(nameList[i], pItem);
        names.push_back(nameList[i]);
        
    }
}
//void CodeGen::G_para_type_list
/* code of litianhao begins */
Value* CodeGen::G_T_NAME_VAR(AST_pNode_t p){
    SymTblItem * pItem = CodeGen::findId(p->data.text);
    if(pItem->isPtr)
    {
        return theBuilder.CreateLoad(pItem->value);
    }
    else
        return pItem->value;
}
Function* CodeGen::G_T_NAME_FUNC(AST_pNode_t p){
    return CodeGen::findFunc(p->data.text);
}

Value* CodeGen::G_routine_body(AST_pNode_t p){ // routine_body : compound_stmt
    AST_pNode_t p_compound_stmt = p->child;
    return G_compound_stmt(p_compound_stmt); 
}
Value* CodeGen::G_compound_stmt(AST_pNode_t p){ // compound_stmt : T_BEGIN stmt_list T_END
    AST_pNode_t p_stmt_list = p->child;
    return G_stmt_list(p_stmt_list);
} 
Value* CodeGen::G_stmt_list(AST_pNode_t p){ // stmt_list : stmt_list stmt T_SEMI | /*empty*/
    if (p->child == NULL){
        return Constant::getNullValue(Type::getInt32PtrTy(theContext));
    } else {
        AST_pNode_t p_stmt_list = p->child;
        AST_pNode_t p_stmt = p_stmt_list->sibling;
        G_stmt_list(p_stmt_list);
        return G_stmt(p_stmt);

    }
}
Value* CodeGen::G_stmt(AST_pNode_t p){ // stmt : T_INTEGER T_COLON non_label_stmt | non_label_stmt
    if (p->child->type == e_INTEGER){
        AST_pNode_t p_t_integer = p->child;
        p->data.int_value = p_t_integer->data.int_value;
        AST_pNode_t p_non_label_stmt = p_t_integer->sibling;

        Function* theFunction = theBuilder.GetInsertBlock()->getParent();
        BasicBlock *BB = BasicBlock::Create(theContext, std::to_string(p_t_integer->data.int_value), theFunction);
        theBuilder.CreateBr(BB);
        theBuilder.SetInsertPoint(BB);

        labelTable[p_t_integer->data.int_value] = BB;
        return G_non_label_stmt(p_non_label_stmt);
    } else {
        return G_non_label_stmt(p->child);
    }
}
Value* CodeGen::G_non_label_stmt(AST_pNode_t p){
    if (p->child->type == e_assign_stmt){
        return G_assign_stmt(p->child);
    } else if (p->child->type == e_proc_stmt){
        return G_proc_stmt(p->child);
    } else if (p->child->type == e_compound_stmt){
        return G_compound_stmt(p->child);
    } else if (p->child->type == e_if_stmt){
        return G_if_stmt(p->child);
    } else if (p->child->type == e_repeat_stmt){
        return G_repeat_stmt(p->child);
    } else if (p->child->type == e_while_stmt){
        return G_while_stmt(p->child);
    } else if (p->child->type == e_for_stmt){
        return G_for_stmt(p->child);
    } else if (p->child->type == e_case_stmt){
        return G_case_stmt(p->child);
    } else if (p->child->type == e_goto_stmt){
        return G_goto_stmt(p->child);
    } 
    return nullptr;
}
Value* CodeGen::G_assign_stmt(AST_pNode_t p){
    AST_pNode_t p_T_NAME = p->child;
    if (p_T_NAME->sibling->sibling == NULL){ // assign_stmt : T_NAME T_ASSIGN expression
        AST_pNode_t p_expression = p_T_NAME->sibling;
        return theBuilder.CreateStore(G_expression(p_expression), G_T_NAME_VAR(p_T_NAME));
    } else if (p_T_NAME->sibling->type == e_expression){ // assign_stmt : T_NAME T_LB expression T_RB T_ASSIGN expression
        return nullptr;
    } else { //  assign_stmt : T_NAME T_DOT T_NAME T_ASSIGN expression
        return nullptr;
    }
    /* TODO */
}

Value* CodeGen::G_args_list(AST_pNode_t p, std::vector<Value*>* ArgsVPtr, std::vector<Type*> & argTypes){
    AST_pNode_t p_expression = p->child;
    if (p->child->sibling != NULL){
        p_expression = p->child->sibling;
        G_args_list(p->child, ArgsVPtr, argTypes);
    }
    if(argTypes[ArgsVPtr->size()]->isPointerTy())
    {
        (*ArgsVPtr).push_back(G_T_NAME_VAR(p_expression->child->child->child->child));
    }
        
    else
        (*ArgsVPtr).push_back(G_expression(p_expression));

    return nullptr;
}
Value* CodeGen::G_expression_list_write(AST_pNode_t p){
    if (p->child->sibling != NULL){
        
        G_expression_list_write(p->child);
        Value* Val =  G_expression(p->child->sibling);
        std::vector<llvm::Value *> values;
        llvm::Value * formatStr;
        
        if (p->child->sibling->valueType == e_integer)
            formatStr = theBuilder.CreateGlobalStringPtr("%d ");
        else
        {
            formatStr = theBuilder.CreateGlobalStringPtr("%f ");
        } 
        
        values.push_back(formatStr);
        values.push_back(Val);
        theBuilder.CreateCall(printfFunc, values);
    } else {
        Value* Val =  G_expression(p->child);
        std::vector<llvm::Value *> values;

        llvm::Value * formatStr;
        
        if (p->child->valueType == e_integer)
            formatStr = theBuilder.CreateGlobalStringPtr("%d ");
        else
        {
            formatStr = theBuilder.CreateGlobalStringPtr("%f ");
        }
        
        values.push_back(formatStr);
        values.push_back(Val);
        theBuilder.CreateCall(printfFunc, values);
    }
    return nullptr;
}
Value* CodeGen::G_proc_stmt(AST_pNode_t p){
    
    if (p->child->sibling == NULL) { 
        return nullptr;
        if (p->child->type == e_NAME){ // proc_stmt : T_NAME
            auto foo = G_T_NAME_FUNC(p->child);
            std::vector<Value*> ArgsV;
            return theBuilder.CreateCall(foo, ArgsV, "callproc");
        } else if (p->child->type == e_SYS_PROC){ // proc_stmt : T_SYS_PROC
            std::string s = p->child->data.text;
            if (s == "writeln"){
                
                return theBuilder.CreateCall(PUTS, newline);  //TODO: global variable PUTS should be initialized.
            } 
        }
    } else { 
        
        if (p->child->type == e_NAME){ // proc_stmt : T_NAME T_LP args_list T_RP
            auto foo = G_T_NAME_FUNC(p->child);
            std::vector<Value*> ArgsV;
            G_args_list(p->child->sibling, &ArgsV, findFuncArgTypes(p->child->data.text));
            return theBuilder.CreateCall(foo, ArgsV, "callproc with args");
        } else if (p->child->type == e_SYS_PROC) { // proc_stmt : T_SYS_PROC T_LP expression_list T_RP
            // TODO: write(a,b) and writeln(a,b)
            
            AST_pNode_t p_expression_list = p->child->sibling;
            G_expression_list_write(p_expression_list);
            std::string s = p->child->data.text;
            if (s == "writeln"){
                
                theBuilder.CreateCall(PUTS, newline);  
            } 
        } else if (p->child->type == e_READ){ // proc_stmt : T_READ T_LP factor T_RP
            AST_pNode_t p_factor = p->child->sibling;
            if (p_factor->child->type == e_NAME){
                G_factor(p_factor);
                Value* Var = G_T_NAME_VAR(p_factor->child);
                std::vector<llvm::Value *> values;
                llvm::Value *formatStrScanf;
                if (p_factor->valueType == e_integer)
                    formatStrScanf = theBuilder.CreateGlobalStringPtr("%d");
                else{
                    formatStrScanf = theBuilder.CreateGlobalStringPtr("%lf");
                }
                    
                values.push_back(formatStrScanf);
                values.push_back(Var); 

                theBuilder.CreateCall(scanfFunc, values); 
            }
        }
    }
}

Value* CodeGen::G_if_stmt(AST_pNode_t p){ // if_stmt : T_IF expression T_THEN stmt else_clause
    AST_pNode_t p_expression = p->child;
    AST_pNode_t p_stmt = p_expression->sibling;
    AST_pNode_t p_else_clause = p_stmt->sibling;

    //Value* CondV = G_expression(p_expression); debug
    
    Function* theFunction = theBuilder.GetInsertBlock()->getParent();

    BasicBlock *thenBlock = BasicBlock::Create(theContext, "then", theFunction);
    BasicBlock *elseBlock = BasicBlock::Create(theContext, "else");
    BasicBlock *mergeBlock = BasicBlock::Create(theContext, "ifcont");
    /* then */
    theBuilder.CreateCondBr(G_expression(p_expression), thenBlock, elseBlock);

    theBuilder.SetInsertPoint(thenBlock);

    Value* thenV = G_stmt(p_stmt);

    theBuilder.CreateBr(mergeBlock);
    thenBlock = theBuilder.GetInsertBlock();

    /* else */
    theFunction->getBasicBlockList().push_back(elseBlock);
    theBuilder.SetInsertPoint(elseBlock);
    G_else_clause(p_else_clause);

    theBuilder.CreateBr(mergeBlock);
    elseBlock = theBuilder.GetInsertBlock();

    /* merge */
    theFunction->getBasicBlockList().push_back(mergeBlock);
    theBuilder.SetInsertPoint(mergeBlock);

}
Value* CodeGen::G_else_clause(AST_pNode_t p){
    if (p->child == NULL){ // else_clause : /*empty*/
        return nullptr;
    } else { // else_clause : T_ELSE stmt
        return G_stmt(p->child);     
    }
}
Value* CodeGen::G_repeat_stmt(AST_pNode_t p){ // repeat_stmt : T_REPEAT stmt_list T_UNTIL expression
    AST_pNode_t p_stmt_list = p->child;
    AST_pNode_t p_expression = p_stmt_list->sibling;

    Function *theFunction = theBuilder.GetInsertBlock()->getParent();

    // Make the new basic block for the loop header, inserting after current
    // block.
    BasicBlock *loopBB = BasicBlock::Create(theContext, "loop", theFunction);

    // Insert an explicit fall through from the current block to the loopBB.
    theBuilder.CreateBr(loopBB);

    // Start insertion in loopBB.
    theBuilder.SetInsertPoint(loopBB);
    G_stmt_list(p_stmt_list);

    // Create the "after loop" block and insert it.
    BasicBlock *afterBB =
            BasicBlock::Create(theContext, "afterloop", theFunction);

    // Insert the conditional branch into the end of loopEndBB.
    theBuilder.CreateCondBr(G_expression(p_expression), afterBB, loopBB);

    // Any new code will be inserted in afterBB.
    theBuilder.SetInsertPoint(afterBB);

    return Constant::getNullValue(Type::getInt32PtrTy(theContext));
}
Value* CodeGen::G_while_stmt(AST_pNode_t p){ // while_stmt : T_WHILE expression T_DO stmt
    AST_pNode_t p_expression = p->child;
    AST_pNode_t p_stmt = p_expression->sibling;

    Function *theFunction = theBuilder.GetInsertBlock()->getParent();

    BasicBlock *entryBB = BasicBlock::Create(theContext, "entry", theFunction);

    // Insert an explicit fall through from the current block to the entryBB.
    theBuilder.CreateBr(entryBB);

    theBuilder.SetInsertPoint(entryBB);

    // Make the new basic block for the loop header, inserting after current
    // block.
    BasicBlock *loopBB = BasicBlock::Create(theContext, "loop");
    // Create the "after loop" block and insert it.
    BasicBlock *afterBB = BasicBlock::Create(theContext, "afterloop");

    // Insert the conditional branch into the end of loopEndBB.
    theBuilder.CreateCondBr(G_expression(p_expression), loopBB, afterBB);

    theFunction->getBasicBlockList().push_back(loopBB);
    // Start insertion in loopBB.
    theBuilder.SetInsertPoint(loopBB);

    G_stmt(p_stmt);

    // Insert an explicit fall through from the current block to the loopBB.
    theBuilder.CreateBr(entryBB);

    theFunction->getBasicBlockList().push_back(afterBB);
    // Any new code will be inserted in afterBB.
    theBuilder.SetInsertPoint(afterBB);

    return Constant::getNullValue(Type::getInt32PtrTy(theContext));
}
Value* CodeGen::G_for_stmt(AST_pNode_t p){ // for_stmt : T_FOR T_NAME T_ASSIGN expression direction expression T_DO stmt
    AST_pNode_t p_T_NAME = p->child;
    AST_pNode_t p_expression1 = p_T_NAME->sibling;
    AST_pNode_t p_direction = p_expression1->sibling;
    AST_pNode_t p_expression2 = p_direction->sibling;
    AST_pNode_t p_stmt = p_expression2->sibling;

    // Emit the start code first, without 'variable' in scope.
    Value *StartVal = G_expression(p_expression1);
    Value *EndCond = G_expression(p_expression2);
    Value* loopVar = G_T_NAME_VAR(p_T_NAME);
    theBuilder.CreateStore(StartVal, loopVar);
    // Make the new basic block for the loop header, inserting after current
    // block.
    Function *theFunction = theBuilder.GetInsertBlock()->getParent();
    BasicBlock *PreheaderBB = theBuilder.GetInsertBlock();
    BasicBlock *loopBB =
        BasicBlock::Create(theContext, "loop", theFunction);

    // Insert an explicit fall through from the current block to the loopBB.
    theBuilder.CreateBr(loopBB);

    // Start insertion in loopBB.
    theBuilder.SetInsertPoint(loopBB);
    /*
    // Start the PHI node with an entry for Start.
    PHINode *Variable = theBuilder.CreatePHI(Type::getInt32Ty(theContext),
                                        2, "forloop");
    Variable->addIncoming(StartVal, PreheaderBB); */
    /* TODO 
    // Within the loop, the variable is defined equal to the PHI node.  If it
    // shadows an existing variable, we have to restore it, so save it now.

    NamedValues[VarName] = Variable; */

    // Emit the body of the loop.  This, like any other expr, can change the
    // current BB.  Note that we ignore the value computed by the body, but don't
    // allow an error.
    G_stmt(p_stmt);

    // Emit the step value.
    Value *StepVal = G_direction(p_direction);
    Value* NextVar = theBuilder.CreateAdd(theBuilder.CreateLoad(loopVar), StepVal, "nextvar");
    theBuilder.CreateStore(NextVar, loopVar);

    // Compute the end condition.
    
    Value *Comp = theBuilder.CreateICmpULE(NextVar, EndCond, "cmptmp");


    // Create the "after loop" block and insert it.
    BasicBlock *loopEndBB = theBuilder.GetInsertBlock();
    BasicBlock *afterBB =
        BasicBlock::Create(theContext, "afterloop", theFunction);

    // Insert the conditional branch into the end of loopEndBB.
    theBuilder.CreateCondBr(Comp, loopBB, afterBB);

    // Any new code will be inserted in afterBB.
    theBuilder.SetInsertPoint(afterBB);
    /* 
    // Add a new entry to the PHI node for the backedge.
    Variable->addIncoming(NextVar, loopEndBB); */

    return Constant::getNullValue(Type::getInt32PtrTy(theContext));

}
Value* CodeGen::G_case_stmt(AST_pNode_t p){ // case_stmt : T_CASE expression T_OF case_expr_list T_END
    AST_pNode_t p_expression = p->child;
    AST_pNode_t p_case_expr_list = p_expression->sibling;
    std::vector<ConstantInt*>* testCases = new std::vector<ConstantInt*>;
    std::vector<AST_pNode_t>* statements = new std::vector<AST_pNode_t>;

    Function *theFunction = theBuilder.GetInsertBlock()->getParent();
    G_case_expr_list(p_case_expr_list, testCases, statements);

    BasicBlock *exitBB = BasicBlock::Create(theContext, "exit");
    SwitchInst *switchInst = theBuilder.CreateSwitch(G_expression(p_expression), exitBB, testCases->size());

    for (unsigned int i = 0; i < (testCases->size()); i++) {
        // Make the new basic block for the loop header, inserting after current
        // block.
        BasicBlock *caseBB = BasicBlock::Create(theContext, "case", theFunction);
        theBuilder.SetInsertPoint(caseBB);
        G_stmt((*statements)[i]);
        theBuilder.CreateBr(exitBB);
        switchInst->addCase((*testCases)[i], caseBB);
    }

    theFunction->getBasicBlockList().push_back(exitBB);
    theBuilder.SetInsertPoint(exitBB);
    return nullptr;
}
Value* CodeGen::G_case_expr_list(AST_pNode_t p, std::vector<ConstantInt*>*  testCases, std::vector<AST_pNode_t>* statements){
    if (p->child->sibling != NULL){//case_expr_list : case_expr_list case_expr
        G_case_expr_list(p->child, testCases, statements);
        G_case_expr(p->child->sibling, testCases, statements);
    } else { // case_expr_list : case_expr 
        G_case_expr(p->child, testCases, statements);
    }
    return nullptr;
}
Value* CodeGen::G_case_expr(AST_pNode_t p, std::vector<ConstantInt*>* testCases, std::vector<AST_pNode_t>* statements){
    if (p->child->type == e_const_value){ //case_expr : const_value T_COLON stmt T_SEMI
        testCases->push_back(ConstantInt::get(theContext, APInt(32, p->child->child->data.int_value)));
        statements->push_back(p->child->sibling);
    } else { //case_expr : T_NAME T_COLON stmt T_SEMI
        /* testCases->push_back(theBuilder.CreateLoad(G_T_NAME_VAR(p->child)));
        statements->push_back(p->child->sibling); */
    }
    return nullptr;
}
Value* CodeGen::G_direction(AST_pNode_t p){
    if (p->child->type == e_TO){
        return ConstantInt::get(theContext, APInt(32, 1));
    } else {
        return ConstantInt::get(theContext, APInt(32, -1));
    }
}


Value* CodeGen::G_goto_stmt(AST_pNode_t p){ // goto_stmt : T_GOTO T_INTEGER
    AST_pNode_t p_T_INTEGER = p->child;
    BasicBlock *des = labelTable[p_T_INTEGER->data.int_value];
    theBuilder.CreateBr(des);
    return nullptr;
}

/* code of litianhao ends */
/* code of zjh begins */

void CodeGen::LogError(const char *str)
{
    fprintf(stderr, "Error: %s\n", str);
}

Value* CodeGen::G_expression_list(AST_pNode_t p)
{
    AST_pNode_t expression_list;
    AST_pNode_t expression;

    if(p->child->sibling != NULL) //既有expression_list，也有expression，还应继续递归
    {
        expression_list = p->child;
        expression = expression_list->sibling;
        //先继续递归下去再处理，使得从前往后处理
        G_expression_list(expression_list); 
        return G_expression(expression);
    }
    else if(p->child->sibling == NULL) //只有expression了
    {
        expression = p->child;
        return G_expression(expression); //此时处理的为第一个expression
    }
    return NULL;
}
Value* CodeGen::G_expression(AST_pNode_t p)
{
    AST_pNode_t expression;
    AST_pNode_t expr;
    AST_pNode_t symbol; //大于号小于号等

    if(p->child->sibling != NULL)
    {   
        expression = p->child;
        symbol = expression->sibling;
        expr = symbol->sibling;
        Value* L = G_expression(expression);    //继续往下递归拿到左边参数
        Value* R = G_expr(expr);                //拿到右边参数
        
        //此时可以用expr的valueType进行判断
        if(expr->valueType == e_real)
        {
            switch(symbol->type) {
            case e_GE: 
                return theBuilder.CreateFCmpUGE(L, R, "cmptmp"); //>=
            case e_GT:
                return theBuilder.CreateFCmpUGT(L, R, "cmptmp"); //>
            case e_LE:
                return theBuilder.CreateFCmpULE(L, R, "cmptmp"); //<=
            case e_LT:
                return theBuilder.CreateFCmpULT(L, R, "cmptmp"); //<
            case e_EQUAL:
                return theBuilder.CreateFCmpUEQ(L, R, "cmptmp"); //=
            case e_UNEQUAL:
                return theBuilder.CreateFCmpUNE(L, R, "cmptmp"); //<>
            default:
                LogError("Expression Error"); //报错
            }
        }
        else
        {
            switch(symbol->type) {
            case e_GE: 
                return theBuilder.CreateICmpUGE(L, R, "cmptmp"); //>=
                
            case e_GT:
                return theBuilder.CreateICmpUGT(L, R, "cmptmp"); //>
            case e_LE:
                return theBuilder.CreateICmpULE(L, R, "cmptmp"); //<=
            case e_LT:
                return theBuilder.CreateICmpULT(L, R, "cmptmp"); //<
            case e_EQUAL:
                return theBuilder.CreateICmpEQ(L, R, "cmptmp"); //=
            case e_UNEQUAL:
                return theBuilder.CreateICmpNE(L, R, "cmptmp"); //<>
            default:
                LogError("Expression Error"); //报错
            }
        }
        
    }
    else if(p->child->sibling == NULL)
    {
        
        expr = p->child;
        Value* val = G_expr(expr);
        p->valueType = expr->valueType;
        return val;
    }
    return NULL;
}
Value* CodeGen::G_expr(AST_pNode_t p)
{
    AST_pNode_t expr;
    AST_pNode_t op;
    AST_pNode_t term;

    if(p->child->sibling != NULL)
    {
        expr = p->child;
        op = expr->sibling;
        term = op->sibling;
        Value* L = G_expr(expr);
        Value* R = G_term(term);
        p->valueType = term->valueType;
        //可以用term的valueType做判断
        if(term->valueType == e_real)
        {
            switch(op->type){
            case e_PLUS:
                return theBuilder.CreateFAdd(L, R, "addtmp");
            case e_MINUS:
                return theBuilder.CreateFSub(L, R, "subtmp");
            case e_OR:
                return theBuilder.CreateOr(L, R, "ortmp");
            default: 
                LogError("Expr Error"); //
            }
        }
        else
        {
            switch(op->type){
            case e_PLUS:
                return theBuilder.CreateAdd(L, R, "addtmp");
            case e_MINUS:
                return theBuilder.CreateSub(L, R, "subtmp");
            case e_OR:
                return theBuilder.CreateOr(L, R, "ortmp");
            default: 
                LogError("Expr Error"); //
            }
        }
        
    }
    else if(p->child->sibling == NULL)
    {
        term = p->child;
        Value* val = G_term(term);
        p->valueType = term->valueType;
        return val;
    }
    return NULL;
}
Value* CodeGen::G_term(AST_pNode_t p)
{
    AST_pNode_t term;
    AST_pNode_t op;
    AST_pNode_t factor;

    if(p->child->sibling != NULL)
    {
        term = p->child;
        op = term->sibling;
        factor = op->sibling;
        Value* L = G_term(term);
        Value* R = G_factor(factor);
        p->valueType = factor->valueType;
        //此时可以用factor的valueType作判断
        if(factor->valueType == e_real)
        {
            switch(op->type){
            case e_MUL:
                return theBuilder.CreateFMul(L, R, "multmp");
            case e_DIV:
                return theBuilder.CreateFDiv(L, R, "divtmp");
            case e_MOD:
                return theBuilder.CreateFRem(L, R, "modtmp");
            case e_AND:
                return theBuilder.CreateAnd(L, R, "andtmp");
            default:
                LogError("Term Error");
            }
        }   
        else
        {
            switch(op->type){
            case e_MUL:
                return theBuilder.CreateMul(L, R, "multmp");
            case e_DIV:
                return theBuilder.CreateUDiv(L, R, "divtmp");
            case e_MOD:
                return theBuilder.CreateURem(L, R, "modtmp");
            case e_AND:
                return theBuilder.CreateAnd(L, R, "andtmp");
            default:
                LogError("Term Error");
        }
        }
    }
    else if(p->child->sibling == NULL)
    {
        factor=p->child;
        Value* val = G_factor(factor);
        p->valueType = factor->valueType;
        return val;
    }
    return NULL;
}
Value* CodeGen::G_factor(AST_pNode_t p)
{
    if(p->child->type == e_const_value)
    {
        AST_pNode_t tmp = p->child->child;
        switch(tmp->valueType){
            case e_integer:
                p->valueType = e_integer; //此时解析到下面的结点先把值类型赋好以便往上传
                return ConstantInt::get(theContext, APInt(32, tmp->data.int_value));
            case e_real:
                p->valueType = e_real;
                return ConstantFP::get(theContext, APFloat(tmp->data.real_value));

            default:
                return NULL;
        }
    }
    else if(p->child->type == e_NAME)
    {   
        AST_pNode_t tmp = p->child; //NAME
        SymTblItem* idItem;
        if(tmp->sibling == NULL) //NAME
        {
            idItem = findId(tmp->data.text);
            if(idItem == NULL) LogError("Identifier Undefined");
            else
            {
                p->valueType = idItem->myType->type;
                return G_T_NAME_VALUE(tmp);
                //return idItem->value;
            }
        }
        
        else if(tmp->sibling != NULL) //NAME(args_list)
        {
            auto foo = G_T_NAME_FUNC(tmp); //从函数表取函数
            std::vector<Value*> ArgsV;
            G_args_list(tmp->sibling, &ArgsV, findFuncArgTypes(p->child->data.text)); //构建参数列表
            return theBuilder.CreateCall(foo, ArgsV, "callproc");
        }
    }
    else if(p->child->type == e_expression)
    {
        return G_expression(p->child);
    }
    return NULL;
}
void CodeGen::Init_write()
{
    newline = theBuilder.CreateGlobalStringPtr("\n");
    std::vector<llvm::Type *> putsArgs;
    putsArgs.push_back(theBuilder.getInt8Ty()->getPointerTo());
    llvm::ArrayRef<llvm::Type*>  argsRef(putsArgs);
 
    llvm::FunctionType *putsType = 
    llvm::FunctionType::get(theBuilder.getInt32Ty(), argsRef, false);
    PUTS = theModule->getOrInsertFunction("puts", putsType); 
}

void CodeGen::Init_scanf()
{ 
  std::vector<llvm::Type *> scanfArgs;
  scanfArgs.push_back(theBuilder.getInt8Ty()->getPointerTo());
  llvm::ArrayRef<llvm::Type*>  argsRef(scanfArgs);

  llvm::FunctionType *scanfType = 
  llvm::FunctionType::get(theBuilder.getInt32Ty(), argsRef, true);
  scanfFunc = theModule->getOrInsertFunction("scanf", scanfType); 

}

void CodeGen::Init_printf()
{
  std::vector<llvm::Type *> printfArgs;
  printfArgs.push_back(theBuilder.getInt8Ty()->getPointerTo());
  llvm::ArrayRef<llvm::Type*>  argsRef(printfArgs);

  llvm::FunctionType *printfType = 
  llvm::FunctionType::get(theBuilder.getInt32Ty(), argsRef, true);
  printfFunc = theModule->getOrInsertFunction("printf", printfType); 

}