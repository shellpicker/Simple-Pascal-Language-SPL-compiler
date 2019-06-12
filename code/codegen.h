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
    std::string name; // name for identifiers or user-defined types
    BasicType * myType; // the type of the name
    int isConst;
    // the corresponding ones in LLVM
    Value * value; 
    Type * type;
};
//used as symbol entry
class CodeGenBlock{
public:
    BasicBlock *block;
    std::vector<SymTblItem *> idTable;
    // table for user defined types
    std::vector<SymTblItem *> typeTable;
    // mapping of function and its representation in LLVM
    std::map<std::string, Function*> namedFuncs;
    /*
    // mapping of identifiers and Value* (used for llvm)
    std::map<std::string, Value*> namedValues;
    // mapping  of identifiers and its type
    std::map<std::string, std::string> valueType;
    // mapping of user-defined types and its representation in LLVM
    std::map<std::string, Type*> namedTypes;
    
    // type checks may be done by LLVM ? or we can left it to last.
    */
   // check if the identifier has been declared
    int checkId(char * id){
        for(int i = 0; i < idTable.size(); i++)
        {
            if(std::strcmp(idTable[i]->name.c_str(), id) == 0)
                return 1;
        }
        return 0;
    }
    int checkType(char *type){
        for(int i = 0; i < typeTable.size(); i++)
            if(std::strcmp(typeTable[i]->name.c_str(), type) == 0)
                return 1;
        return 0;
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
    void pushIdTable(SymTblItem * item){ blocks.back()->idTable.push_back(item);}
    void pushTypeTable(SymTblItem * item){ blocks.back()->typeTable.push_back(item);}
    // check if the identifier has been declared
    int checkId(char * id){
        for(int i = 0; i < blocks.size(); i++)
            if(blocks[i]->checkId())
                return 1;
        return 0;
    }
    void G_program(AST_pNode_t p);
    Value* G_routine(AST_pNode_t p);
    Value* G_routine_head(AST_pNode_t p);
    Value* G_compound_stmt(AST_pNode_t p); // routine_body->compound_stmt
    Value* G_const_expr_list(AST_pNode_t p); //const_part->const_expr_list
    Value* G_type_decl_list(AST_pNode_t p); // type_part->type_decl_list
    Value* G_var_decl_list(AST_pNode_t p); // var_part->var_decl_list
    Value* G_routine_part(AST_pNode_t p);

    Value* G_const_value(AST_pNode_t p);

    void G_error(AST_pNode_t p);
};

#endif