%{
#include "AST.h"
#include "parse.h"
#include <string.h>
#include <ctype.h>
int cur_line_num = 1;
void mystrcpy(char *a, char *b)
{
    while( *b != 0)
        *(a++) = tolower(*(b++));
}
%}

INTEGER         [0-9]+                        
REAL            INTEGER"."INTEGER
CHAR            \'[a-zA-Z]\'
READ            "read"
SYS_TYPE        (boolean|char|integer|real)
SYS_CON         (false|maxint|true)
SYS_FUNCT       (abs|chr|odd|ord|pred|sqr|sqrt|succ)
SYS_PROC        (write|writeln)
NAME            [a-zA-Z][_a-zA-Z0-9]* 
SINGLE_COMMENT1 "//"[^\n]*
SINGLE_COMMENT2 "{"[^\n}]*"}"
MUTI_COMMENT    "(*"[_a-zA-Z0-9\n \r\t]*"*)" 
   
%%

[\n]                {cur_line_num++;}
[ \t\r]+           {}                  //ignore spaces
{SINGLE_COMMENT1}   {}
{SINGLE_COMMENT2}  {}
{MUTI_COMMENT}   {}                  //skip comment

"("                 {return T_LP;}
")"                 {return T_RP;}
"["                 {return T_LB;}
"]"                 {return T_RB;}
"."                 {return T_DOT;}
","                 {return T_COMMA;}
":"                 {return T_COLON;}
"*"                 {
                    InitNode(&yylval.node);
                    yylval.node->type = e_MUL;
                    yylval.node->line = cur_line_num;
                    return T_MUL;
                    }
"/"                 {
                    InitNode(&yylval.node);
                    yylval.node->type = e_DIV;
                    yylval.node->line = cur_line_num;
                    return T_DIV;
                    }
"<>"                {
                    InitNode(&yylval.node);
                    yylval.node->type = e_UNEQUAL;
                    yylval.node->line = cur_line_num;
                    return T_UNEQUAL;
                    }
"not"               {
                    InitNode(&yylval.node);
                    yylval.node->type = e_NOT;
                    yylval.node->line = cur_line_num;
                    return T_NOT;
                    }
"+"                 {
                    InitNode(&yylval.node); 
                    yylval.node->type = e_PLUS;
                    yylval.node->line = cur_line_num;
                    return T_PLUS;
                    }
"-"                 {
                    InitNode(&yylval.node);
                    yylval.node->type = e_MINUS;
                    yylval.node->line = cur_line_num;
                    return T_MINUS;
                    }
">="                {
                    InitNode(&yylval.node);
                    yylval.node->type = e_GE;
                    yylval.node->line = cur_line_num;
                    return T_GE;
                    }
">"                 {
                    InitNode(&yylval.node);
                    yylval.node->type = e_GT;
                    yylval.node->line = cur_line_num;
                    return T_GT;
                    }
"<="                {
                    InitNode(&yylval.node);
                    yylval.node->type = e_LE;
                    yylval.node->line = cur_line_num;
                    return T_LE;
                    }
"<"                 {
                    InitNode(&yylval.node);
                    yylval.node->type = e_LT;
                    yylval.node->line = cur_line_num;
                    return T_LT;
                    }
"="                 {
                    InitNode(&yylval.node);
                    yylval.node->type = e_EQUAL;
                    yylval.node->line = cur_line_num;
                    return T_EQUAL;
                    }

":="                {return T_ASSIGN;}

"MOD"               {
                    InitNode(&yylval.node);
                    yylval.node->type = e_MOD;
                    yylval.node->line = cur_line_num;
                    return T_MOD;
                    }
".."                {return T_DOTDOT;}

";"                 {return T_SEMI;}


"and"               {
                    InitNode(&yylval.node);
                    yylval.node->type = e_AND;
                    yylval.node->line = cur_line_num;
                    return T_AND;
                    }
"array"             {return T_ARRAY;}
"begin"             {return T_BEGIN;}
"case"              {return T_CASE;}
"const"             {return T_CONST;}
"div"               {
                    InitNode(&yylval.node);
                    yylval.node->type = e_DIV;
                    yylval.node->line = cur_line_num;
                    return T_DIV;
                    }
"do"                {return T_DO;}
"downto"            {
                    InitNode(&yylval.node);
                    yylval.node->type = e_DOWNTO;
                    yylval.node->line = cur_line_num;
                    return T_DOWNTO;
                    }
"else"              {return T_ELSE;}
"end"               {return T_END;}
"for"               {return T_FOR;}
"function"          {return T_FUNCTION;}
"goto"              {return T_GOTO;}
"if"                {return T_IF;}
"of"                {return T_OF;}
"or"                {
                    InitNode(&yylval.node);
                    yylval.node->type = e_OR;
                    yylval.node->line = cur_line_num;
                    return T_OR;
                    }
"packed"            {return T_PACKED;}
"procedure"         {return T_PROCEDURE;}
"program"           {return T_PROGRAM;}
"record"            {return T_RECORD;}
"repeat"            {return T_REPEAT;}
"then"              {return T_THEN;}
"to"                {
                    InitNode(&yylval.node);
                    yylval.node->type = e_TO;
                    yylval.node->line = cur_line_num;
                    return T_TO;
                    }
"type"              {return T_TYPE;}
"until"             {return T_UNTIL;}
"var"               {return T_VAR;}
"while"             {return T_WHILE;}

{INTEGER}           {
                    InitNode(&yylval.node);
                    yylval.node->type = e_INTEGER;
                    yylval.node->line = cur_line_num;
                    yylval.node->data.int_value = atoi(yytext);
                    return T_INTEGER;
                    }
{REAL}              {
                    InitNode(&yylval.node);
                    yylval.node->type = e_REAL;
                    yylval.node->line = cur_line_num;
                    yylval.node->data.real_value = atof(yytext);
                    return T_REAL;
                    }
{CHAR}              {
                    InitNode(&yylval.node);
                    yylval.node->type = e_REAL;
                    yylval.node->line = cur_line_num;
                    yylval.node->data.ch_value = yytext[0];
                    return T_CHAR;
                    }

{READ}              {
/*TODO:these tokens aren't completely resolved, I just put the lower */
/*case of original text to the node.  And resolution may be done by*/
/*declaring some enums */
                    InitNode(&yylval.node);
                    yylval.node->type = e_READ;
                    yylval.node->line = cur_line_num;
                    return T_READ;
                    }
{SYS_CON}           {
                    InitNode(&yylval.node);
                    yylval.node->type = e_SYS_CON;
                    yylval.node->line = cur_line_num;
                    yylval.node->data.text = (char*)malloc(strlen(yytext)+1);
                    mystrcpy(yylval.node->data.text, yytext);
                    return T_SYS_CON;
                    }
{SYS_FUNCT}         {
                    InitNode(&yylval.node);
                    yylval.node->type = e_SYS_FUNCT;
                    yylval.node->line = cur_line_num;
                    yylval.node->data.text = (char*)malloc(strlen(yytext)+1);
                    mystrcpy(yylval.node->data.text, yytext);
                    return T_SYS_FUNCT;
                    }
{SYS_PROC}          {
                    InitNode(&yylval.node);
                    yylval.node->type = e_SYS_PROC;
                    yylval.node->line = cur_line_num;
                    yylval.node->data.text = (char*)malloc(strlen(yytext)+1);
                    mystrcpy(yylval.node->data.text, yytext);
                    return T_SYS_PROC;
                    }
{SYS_TYPE}          {
                    InitNode(&yylval.node);
                    yylval.node->type = e_SYS_TYPE;
                    yylval.node->line = cur_line_num;
                    yylval.node->data.text = (char*)malloc(strlen(yytext)+1);
                    mystrcpy(yylval.node->data.text, yytext);
                    return T_SYS_TYPE;
                    }  
{NAME}              {
                    InitNode(&yylval.node);
                    yylval.node->type = e_NAME;
                    yylval.node->line = cur_line_num;
                    yylval.node->data.text = (char*)malloc(strlen(yytext)+1);
                    mystrcpy(yylval.node->data.text, yytext);
                    return T_NAME;
                    }

<<EOF>>             {return 0;}

%%

int yywrap(void) {
    return 1;
}