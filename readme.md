### A simple compiler for SPL

code/ �ļ�����
buildGraph.c���������﷨���Ŀ��ӻ�Ч��
Lex_Analysis.c����flex����Lex_Analysis.l�õ����ļ�
parse.c parse.h����bison����parse.y�õ����ļ�
AST.c AST.h�����˳����﷨���Ľڵ�
codegen.cpp codegen.h������������ʹ�������
main.c �������ɱ�����(���Ƿ���һ�����Ǳ���õ���main)
test2.spl test4.spl test6.splΪ��ʦ�ṩ�Ĳ�������
test.splΪ�����Լ��Ĳ�������

run.sh �ű�ʹ�÷������£�
���ɱ�������
./run.sh -g

ʹ�����ɵı���������test.spl����(�ɵõ�test.ll�ļ�)������(��Ҫ��װclang)
./run.sh -c test.spl
(ע�����ûװclang������������ʾ����֮��ִ��
lli test.ll
ʹ��llvm�ṩ��lli����test.ll

gen.shʹ�÷������£�
���test.spl����Ŀ��ӻ��﷨��:
./gen.sh test.spl

