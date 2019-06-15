bison -d -o parse.c parse.y
flex -o Lex_Analysis.c -i Lex_Analysis.l
g++ -o main main.c parse.c Lex_Analysis.c AST.c codegen.cpp `llvm-config-6.0 --cxxflags --ldflags --system-libs --libs core`
./main <test4.spl >test4.ll 2>&1
llc test4.ll
lli test4.ll
