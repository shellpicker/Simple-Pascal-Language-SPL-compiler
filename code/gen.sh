#!/bin/bash
g++ buildGraph.c -o buildGraph parse.c Lex_Analysis.c AST.c
./buildGraph < $1
dot AST.dot -T png -o AST.png
rm AST.dot
