#ifndef CODEGEN_H_
#define CODEGEN_H_
#include <vector>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
//#include <llvm/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
//#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/IR/Verifier.h>
//#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/ADT/ArrayRef.h>
//#include <llvm/ModuleProvider.h>
//#include <llvm/Target/TargetSelect.h>
//#include <llvm/ExecutionEngine/GenericValue.h>
//#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/Support/raw_ostream.h>
#include <string>
#include <iostream>
#include "AST.h"
#include "types.hpp"
using namespace llvm;
#define MAXINT 0x7fffffff
class SymTblItem{
public:
    BasicType * myType; // the type of the name
    int isConst;
    int isPtr;
    // the corresponding ones in LLVM
    Value * value; 
    Type * type;
    SymTblItem():myType(NULL), isConst(0), isPtr(0), value(NULL), type(NULL){}
    
};
//used as symbol entry
class CodeGenBlock{
public:
    BasicBlock *block;
    
    std::map<std::string, SymTblItem*> idTable;
    // table for user defined types
    std::map<std::string, SymTblItem*> typeTable;
    // mapping of function and its representation in LLVM
    std::map<std::string, Function*> namedFuncs;
    std::map<std::string, std::vector<Type*>> funcArgTypes;
    //std::map<int, 
    /*
    // mapping of user-defined types and its representation in LLVM
    std::map<std::string, Type*> namedTypes;
    
    // type checks may be done by LLVM ? or we can left it to last.
    */
   // check if the identifier has been declared
    int checkId(const char * id){
        return !(idTable.find(std::string(id)) == idTable.end());
    }
    int checkType(const char *type){
        return !(typeTable.find(std::string(type)) == typeTable.end());
    }
    int checkFunc(const char * func){
        return !(namedFuncs.find(std::string(func)) == namedFuncs.end());
    }
    SymTblItem * findType(const char * type){
        if(!checkType(type))
            return NULL;
        return typeTable[std::string(type)];
    }
    SymTblItem * findId(const char * id){
        if(!checkId(id))
            return NULL;
        return idTable[std::string(id)];
    }
    Function* findFunc(const char * func){
        if(!checkFunc(func))
            return NULL;
        return namedFuncs[std::string(func)];
    }
};

class CodeGen{
private:
    std::vector<CodeGenBlock *> blocks;
    LLVMContext theContext;
    IRBuilder<> theBuilder;
    std::unique_ptr<Module> theModule;
    std::map<unsigned int, BasicBlock* > labelTable; // added by litianhao
    llvm::Constant *PUTS;
    llvm::Value *newline;
    llvm::Constant *printfFunc;
    llvm::Constant *scanfFunc;
public:
    CodeGen():theBuilder(theContext){}
public:
    void print(){theModule->print(llvm::errs(), nullptr);}
    Value *getGEP(IRBuilder<> &Builder, Value *Base, Value *Offset) { return Builder.CreateGEP(Builder.getInt32Ty(), Base, Offset, NULL);}
    BasicBlock *currentBlock() { return blocks.back()->block; }
    CodeGenBlock *currentTables(){ return blocks.back();}
    CodeGenBlock *lastLastTables(){if(blocks.size() < 2 ) return NULL; return blocks[blocks.size()-2];}
    void pushBlock(BasicBlock *block) { blocks.push_back(new CodeGenBlock()); blocks.back()->block = block; }
    void popBlock() { CodeGenBlock *top = blocks.back(); blocks.pop_back(); delete top; }
    void pushIdTable(std::string str, SymTblItem * item){ blocks.back()->idTable[str] = item;}
    void pushTypeTable(std::string str, SymTblItem * item){ blocks.back()->typeTable[str] = item;}
    // check if the identifier has been declared
    int checkId(const char * id){
        for(unsigned int i = 0; i < blocks.size(); i++)
            if(blocks[i]->checkId(id))
                return 1;
        return 0;
    }
    int checkType(const char *type){
        for(unsigned int i = 0; i < blocks.size(); i++)
            if(blocks[i]->checkType(type))
                return 1;
        return 0;
    }
    // search from back to front
    SymTblItem* findType(const char * type){
        for(int i = blocks.size()-1; i >= 0; i--)
        {
            SymTblItem * p = blocks[i]->findType(type);
            if(p != NULL)
                return p;
        }
        return NULL;
    }
    SymTblItem* findId(const char * id){
        for(int i = blocks.size()-1; i >= 0; i--)
        {
            SymTblItem * p = blocks[i]->findId(id);
            if(p != NULL)
                return p;
        }
        return NULL;
    }
    Function* findFunc(const char * func){
        for(int i = blocks.size()-1; i >= 0; i--)
        {
            Function * p = blocks[i]->findFunc(func);
            if(p != NULL)
                return p;
        }
        return NULL;
    }
    std::vector<Type*>& findFuncArgTypes(const char *func)
    {
        for(int i = blocks.size()-1; i>=0; i--)
        {
            if(blocks[i]->checkFunc(func))
                return blocks[i]->funcArgTypes[std::string(func)];
        }
    }
    int G_SYS_CON(AST_pNode_t p);
    Type_t G_SYS_TYPE(AST_pNode_t p); 
    void G_program(AST_pNode_t p);
    Value* G_routine(AST_pNode_t p);
    Value* G_routine_head(AST_pNode_t p);
    
    Value* G_const_expr_list(AST_pNode_t p); //const_part->const_expr_list
    SymTblItem* G_const_value(AST_pNode_t p);
    Value* G_type_decl_list(AST_pNode_t p); // type_part->type_decl_list
    Value* G_type_definition(AST_pNode_t p);
    BasicType * G_type_decl(AST_pNode_t p);
    BasicType * G_simple_type_decl(AST_pNode_t p);

    Value* G_var_decl_list(AST_pNode_t p); // var_part->var_decl_list
    void G_name_list(AST_pNode_t p, std::vector<std::string> & list);
    // get the llvm type
    Type * typeOf(BasicType* ty);
    Type_t myTypeOf(BasicType* ty);
    void AllocLocal(SymTblItem * pSym, const char *);
    void AllocGlobal(SymTblItem * pSym, const char * name);

    Value* G_routine_part(AST_pNode_t p);
    Function* G_function_decl(AST_pNode_t p);
    // TODO: procedure_decl
    Function* G_procedure_decl(AST_pNode_t p){}
    Function* G_function_head(AST_pNode_t p);
    void G_para_decl_list(AST_pNode_t p, std::vector<std::string>& names, 
            std::vector<Type*> &types);
    void G_para_type_list(AST_pNode_t p, std::vector<Type*> &list);
    void G_error(AST_pNode_t p){printf("error: line: %d\n",p->line);}
    
    /*
    Value* G_NAME(char * name){
        SymTblItem * pItem = findId(name);
        if(pItem->isPtr == 1)
            return theBuilder.CreateLoad(pItem->value);
        else
            return pItem->value;
    }*/
     /* code of litianhao begins*/
    Value* G_T_NAME_VAR(AST_pNode_t p); // get the addr
    Value* G_T_NAME_VALUE(AST_pNode_t p);// get value
    Function* G_T_NAME_FUNC(AST_pNode_t p);
    Value* G_routine_body(AST_pNode_t p);
    Value* G_compound_stmt(AST_pNode_t p); 
    Value* G_stmt_list(AST_pNode_t p);
    Value* G_stmt(AST_pNode_t p);
    Value* G_non_label_stmt(AST_pNode_t p);
    Value* G_assign_stmt(AST_pNode_t p);
    Value* G_args_list(AST_pNode_t p, std::vector<Value*>* ArgsVPtr, std::vector<Type*> & argTypes);
    Value* G_args_list(AST_pNode_t p, std::vector<Value*>* ArgsVPtr);
    Value* G_expression_list_write(AST_pNode_t p);
    Value* G_proc_stmt(AST_pNode_t p);
    Value* G_if_stmt(AST_pNode_t p);
    Value* G_else_clause(AST_pNode_t p);
    Value* G_repeat_stmt(AST_pNode_t p);
    Value* G_while_stmt(AST_pNode_t p);
    Value* G_for_stmt(AST_pNode_t p);
    Value* G_case_stmt(AST_pNode_t p);
    Value* G_direction(AST_pNode_t p);
    Value* G_case_expr_list(AST_pNode_t p, std::vector<ConstantInt*>*  testCases, std::vector<AST_pNode_t>* statements);
    Value* G_case_expr(AST_pNode_t p, std::vector<ConstantInt*>*  testCases, std::vector<AST_pNode_t>* statements);
    Value* G_goto_stmt(AST_pNode_t p);
    void Init_write();
    void Init_printf();
    void Init_scanf();
    /* code of litianhao ends */
    /* code of zjh begins */
    void LogError(const char *str);
    Value* G_expression_list(AST_pNode_t p);
    Value* G_expression(AST_pNode_t p);
    Value* G_expr(AST_pNode_t p);
    Value* G_term(AST_pNode_t p);
    Value* G_factor(AST_pNode_t p);
};

#endif