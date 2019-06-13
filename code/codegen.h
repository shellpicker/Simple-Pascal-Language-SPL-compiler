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
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/Support/IRBuilder.h>
#include <llvm/ModuleProvider.h>
#include <llvm/Target/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/Support/raw_ostream.h>
#include <string>
#include "AST.h"
#include "types.hpp"
using namespace llvm;

class SymTblItem{
public:
    BasicType * myType; // the type of the name
    int isConst;
    // the corresponding ones in LLVM
    Value * value; 
    Type * type;
    SymTblItem():myType(NULL), value(NULL), type(NULL){}
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
    //std::map<int, 
    /*
    // mapping of user-defined types and its representation in LLVM
    std::map<std::string, Type*> namedTypes;
    
    // type checks may be done by LLVM ? or we can left it to last.
    */
   // check if the identifier has been declared
    int checkId(char * id){
        return !(idTable.find(std::string(id)) == idtable.end());
    }
    int checkType(char *type){
        return !(typeTable.find(std::string(id)) == typeTable.end());
    }
    SymTblItem * findType(char * type){
        if(!checkType(type))
            return NULL;
        return typeTable[std::string(type)];
    }
    SymTblItem * findId(char * id){
        if(!checkId(id))
            return NULL;
        return typeTable[std::string(id)];
    }
};

class CodeGen{
private:
    std::vector<CodeGenBlock *> blocks;
    LLVMContext theContext;
    IRBuilder<> theBuilder;
    std::unique_ptr<Module> theModule;
public:
    CodeGen():theBuilder(theContext){}
public:
    BasicBlock *currentBlock() { return blocks.back()->block; }
    CodeGenBlock *currentTables(){ return blocks.back();}
    void pushBlock(BasicBlock *block) { blocks.push_back(new CodeGenBlock()); blocks.back()->block = block; }
    void popBlock() { CodeGenBlock *top = blocks.back(); blocks.pop_back(); delete top; }
    void pushIdTable(std::string str, SymTblItem * item){ blocks.back()->idTable[str] = item;}
    void pushTypeTable(std::string str, SymTblItem * item){ blocks.back()->typeTable[str] = item;}
    // check if the identifier has been declared
    int checkId(char * id){
        for(int i = 0; i < blocks.size(); i++)
            if(blocks[i]->checkId(id))
                return 1;
        return 0;
    }
    int checkType(char *type){
        for(int i = 0; i < blocks.size(); i++)
            if(blocks[i]->checkType(type))
                return 1;
        return 0;
    }
    // search from back to front
    SymTblItem* findType(char * type){
        for(int i = blocks.size()-1; i >= 0; i--)
        {
            SymTblItem * p = blocks[i]->findType(type);
            if(p != NULL)
                return p;
        }
        return NULL;
    }
    SymTblItem* findId(char * id){
        for(int i = blocks.size()-1; i >= 0; i--)
        {
            SymTblItem * p = blocks[i]->findId(id);
            if(p != NULL)
                return p;
        }
        return NULL;
    }
    Type_t G_SYS_TYPE(AST_pNode_t p); 
    void G_program(AST_pNode_t p);
    Value* G_routine(AST_pNode_t p);
    Value* G_routine_head(AST_pNode_t p);
    Value* G_compound_stmt(AST_pNode_t p); // routine_body->compound_stmt
    Value* G_const_expr_list(AST_pNode_t p); //const_part->const_expr_list
    Value* G_const_value(AST_pNode_t p);
    Value* G_type_decl_list(AST_pNode_t p); // type_part->type_decl_list
    Value* G_type_definition(AST_pNode_t p);
    SymTblItem * G_type_decl(AST_pNode_t p);
    SymTblItem * G_simple_type_decl(AST_pNode_t p);

    Value* G_var_decl_list(AST_pNode_t p); // var_part->var_decl_list
    void G_name_list(AST_pNode_t p, std::vector<std::string> & list);
    // get the llvm type
    Type * typeOf(BasicType* ty);
    void AllocLocal(SymTblItem * pSym);


    Value* G_routine_part(AST_pNode_t p);
    Function* G_function_decl(AST_pNode_t p);
    

    void G_error(AST_pNode_t p);
};

#endif