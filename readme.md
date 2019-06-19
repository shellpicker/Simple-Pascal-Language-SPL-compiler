### A simple compiler for SPL

code/ 文件夹中
buildGraph.c用来生成语法树的可视化效果
Lex_Analysis.c是用flex解析Lex_Analysis.l得到的文件
parse.c parse.h是用bison解析parse.y得到的文件
AST.c AST.h定义了抽象语法树的节点
codegen.cpp codegen.h用于语义分析和代码生成
main.c 用来生成编译器(我们放了一个我们编译得到的main)
test2.spl test4.spl test6.spl为老师提供的测试样例
test.spl为我们自己的测试样例

run.sh 脚本使用方法如下：
生成编译器：
./run.sh -g

使用生成的编译器编译test.spl程序(可得到test.ll文件)并运行(需要安装clang)
./run.sh -c test.spl
(注：如果没装clang，可以在它提示错误之后执行
lli test.ll
使用llvm提供的lli运行test.ll

gen.sh使用方法如下：
获得test.spl程序的可视化语法树:
./gen.sh test.spl

