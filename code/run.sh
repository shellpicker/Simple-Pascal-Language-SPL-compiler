bison -d -o parse.c parse.y
flex -o Lex_Analysis.c -i Lex_Analysis.l
g++ -o main main.c parse.c Lex_Analysis.c AST.c
