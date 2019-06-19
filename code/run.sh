#!/bin/sh
if [ $# != 1 ] && [ $# != 2 ] 
then
    echo "wrong parameters, please get usage from readme.md"
elif [ $1 = "-g" ] 
then
    bison -d -o parse.c parse.y &&
    flex -o Lex_Analysis.c -i Lex_Analysis.l &&
    g++ -o main main.c parse.c Lex_Analysis.c AST.c codegen.cpp `llvm-config-6.0 --cxxflags --ldflags --system-libs --libs core`
elif [ $1 = "-c" ] && [ $# = 2 ]
then
    name=${2%.*}
    ./main <$2 >$name.ll 2>&1
    llc-6.0 -filetype=obj $name.ll &&
    clang $name.o -o $name && 
    echo "$name generated" && 
    echo "running $name" && 
    ./$name
else
    echo "wrong parameters, please get usage from readme.md"
fi
