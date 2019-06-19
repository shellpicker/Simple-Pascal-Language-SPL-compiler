%{
    #include "AST.h"
    #include <stdio.h>
    AST_pNode_t root; // the root node of the AST
    extern int yylex();
    extern int cur_line_num;
    void yyerror(const char *s) { printf("ERROR: %s line %d \n", s, cur_line_num); }
%}

%union{
    int token;
    AST_pNode_t node;
}

%token <token> T_LP T_RP T_LB T_RB T_DOT
%token <token> T_COMMA T_COLON 
%token <node> T_MUL T_DIV T_UNEQUAL T_NOT T_PLUS
%token <node> T_MINUS T_GE T_GT T_LE T_LT
%token <node> T_EQUAL 
%token <token> T_ASSIGN 
%token <node> T_MOD
%token <token> T_DOTDOT T_SEMI
%token <node> T_SYS_CON T_SYS_FUNCT T_SYS_PROC T_SYS_TYPE
%token <node> T_READ /* what's this ? */
%token <node> T_INTEGER T_REAL T_CHAR 
/* deal with the keyword list */
%token <node> T_NAME T_AND T_OR T_DOWNTO T_TO 
%token <token> T_ARRAY T_BEGIN T_CASE T_CONST T_DO
%token <token> T_ELSE T_END T_FOR T_FUNCTION
%token <token> T_GOTO T_IF T_OF T_PACKED T_PROCEDURE 
%token <token> T_PROGRAM T_RECORD T_REPEAT T_THEN 
%token <token> T_TYPE T_UNTIL T_VAR T_WHILE


%type <node> program program_head routine sub_routine
%type <node> routine_head label_part const_part const_expr_list
%type <node> const_value type_part type_decl_list type_definition
%type <node> type_decl simple_type_decl array_type_decl record_type_decl
%type <node> field_decl_list field_decl name_list var_part
%type <node> var_decl_list var_decl routine_part function_decl
%type <node> function_head procedure_decl procedure_head parameters
%type <node> para_decl_list para_type_list var_para_list val_para_list
%type <node> routine_body compound_stmt stmt_list stmt
%type <node> non_label_stmt assign_stmt proc_stmt if_stmt
%type <node> else_clause repeat_stmt while_stmt for_stmt
%type <node> direction case_stmt case_expr_list case_expr
%type <node> goto_stmt expression_list expression expr
%type <node> term factor args_list


%start program

%%

program : program_head routine T_DOT { InitNode(&$$); $$->type = e_program;
        $$->child = $1; $1->sibling = $2; root = $$;
    }
    ;
program_head : T_PROGRAM T_NAME T_SEMI { InitNode(&$$); $$->type = e_program_head; 
        $$->child = $2;}
    ;
routine : routine_head routine_body {InitNode(&$$); $$->type = e_routine;
        $$->child = $1; $1->sibling = $2;}
    ;
sub_routine : routine_head routine_body {InitNode(&$$); $$->type = e_sub_routine;
        $$->child = $1; $1->sibling = $2;}
    ;
routine_head : label_part const_part type_part var_part routine_part {InitNode(&$$);
        $$->type = e_routine_head; $$->child = $1; $1->sibling = $2; $2->sibling = $3;
        $3->sibling = $4; $4->sibling = $5;}
    ;
label_part : /*empty*/{InitNode(&$$); $$->type = e_label_part;}
    ;
const_part : T_CONST const_expr_list {InitNode(&$$);
        $$->type = e_const_part; $$->child = $2;}
    | /*empty*/{InitNode(&$$); $$->type = e_const_part;}
    ;
const_expr_list : const_expr_list T_NAME T_EQUAL const_value T_SEMI {
    InitNode(&$$); $$->type = e_const_expr_list; $$->child = $1;
    $1->sibling = $2; $2->sibling = $4;}
    | T_NAME T_EQUAL const_value T_SEMI {
    InitNode(&$$); $$->type = e_const_expr_list; $$->child = $1;
    $1->sibling = $3;}
    ;
const_value :  T_INTEGER {
    InitNode(&$$); $$->type = e_const_value; $$->child = $1;}
    | T_REAL {
    InitNode(&$$); $$->type = e_const_value; $$->child = $1;}
    | T_CHAR {
    InitNode(&$$); $$->type = e_const_value; $$->child = $1;}
    | T_SYS_CON {
    InitNode(&$$); $$->type = e_const_value; $$->child = $1;}
    ;
type_part : T_TYPE type_decl_list {
    InitNode(&$$); $$->type = e_type_part; $$->child = $2;}
    | /*empty*/{
    InitNode(&$$); $$->type = e_type_part;
    }
    ;
type_decl_list : type_decl_list type_definition {
    InitNode(&$$); $$->type = e_type_decl_list; $$->child = $1;
    $1->sibling = $2;
    }
    | type_definition {
    InitNode(&$$); $$->type = e_type_decl_list; $$->child = $1;
    }
    ;
type_definition : T_NAME T_EQUAL type_decl T_SEMI {
    InitNode(&$$); $$->type = e_type_definition; $$->child = $1;
    $1->sibling = $3;
    }
    ;
type_decl : simple_type_decl {
    InitNode(&$$); $$->type = e_type_decl; $$->child = $1;
    }
    | array_type_decl {
    InitNode(&$$); $$->type = e_type_decl; $$->child = $1;
    }
    | record_type_decl {
    InitNode(&$$); $$->type = e_type_decl; $$->child = $1;
    }
    ;
simple_type_decl : T_SYS_TYPE {
    InitNode(&$$); $$->type = e_simple_type_decl; $$->child = $1;
    }
    
    | T_LP name_list T_RP {
    InitNode(&$$); $$->type = e_simple_type_decl; $$->child = $2;
    }
    | const_value T_DOTDOT const_value {
    InitNode(&$$); $$->type = e_simple_type_decl; $$->child = $1;
    $1->sibling = $3;
    }
    | T_MINUS const_value T_DOTDOT const_value{
    InitNode(&$$); $$->type = e_simple_type_decl; $$->child = $1;
    $1->sibling = $2; $2->sibling = $4;
    }
    | T_MINUS const_value T_DOTDOT T_MINUS const_value {
    InitNode(&$$); $$->type = e_simple_type_decl; $$->child = $1;
    $1->sibling = $2; $2->sibling = $4; $4->sibling = $5;
    }
    | T_NAME T_DOTDOT T_NAME {
    InitNode(&$$); $$->type = e_simple_type_decl; $$->child = $1;
    $1->sibling = $3;
    }
    | T_NAME {
    InitNode(&$$); $$->type = e_simple_type_decl; $$->child = $1;
    }
    ;
array_type_decl : T_ARRAY T_LB simple_type_decl T_RB T_OF type_decl{
    InitNode(&$$); $$->type = e_array_type_decl; $$->child = $3;
    $3->sibling = $6;
    }
    ;
record_type_decl : T_RECORD field_decl_list T_END {
    InitNode(&$$); $$->type = e_record_type_decl; $$->child = $2;
    }
    ;
field_decl_list : field_decl_list field_decl {
    InitNode(&$$); $$->type = e_field_decl_list; $$->child = $1;
    $1->sibling = $2;
    }
    | field_decl {
    InitNode(&$$); $$->type = e_field_decl_list; $$->child = $1;
    }
    ;
field_decl : name_list T_COLON type_decl T_SEMI {
    InitNode(&$$); $$->type = e_field_decl; $$->child = $1;
    $1->sibling = $3;
    }
    ;
name_list : name_list T_COMMA T_NAME {
    InitNode(&$$); $$->type = e_name_list; $$->child = $1;
    $1->sibling = $3;
    }
    | T_NAME {
    InitNode(&$$); $$->type = e_name_list; $$->child = $1;
    }
    ;

var_part : T_VAR var_decl_list {
    InitNode(&$$); $$->type = e_var_part; $$->child = $2;
    }
    | /*empty*/{
    InitNode(&$$); $$->type = e_var_part;
    }
    ;
var_decl_list : var_decl_list var_decl {
    InitNode(&$$); $$->type = e_var_decl_list; $$->child = $1;
    $1->sibling = $2;
    }
    | var_decl {
    InitNode(&$$); $$->type = e_var_decl_list; $$->child = $1;
    }
    ;
var_decl : name_list T_COLON type_decl T_SEMI {
    InitNode(&$$); $$->type = e_var_decl; $$->child = $1;
    $1->sibling = $3;
    }
    ;
routine_part : routine_part function_decl {
    InitNode(&$$); $$->type = e_routine_part; $$->child = $1;
    $1->sibling = $2;
    }
    | routine_part procedure_decl {
    InitNode(&$$); $$->type = e_routine_part; $$->child = $1;
    $1->sibling = $2;
    }
    | function_decl {
    InitNode(&$$); $$->type = e_routine_part; $$->child = $1;
    }
    | procedure_decl {
    InitNode(&$$); $$->type = e_routine_part; $$->child = $1;
    }
    | /*empty*/ {
    InitNode(&$$); $$->type = e_routine_part;
    }
    ;
function_decl : function_head T_SEMI sub_routine T_SEMI {
    InitNode(&$$); $$->type = e_function_decl; $$->child = $1;
    $1->sibling = $3;
    }
    ;
function_head : T_FUNCTION T_NAME parameters T_COLON simple_type_decl {
    InitNode(&$$); $$->type = e_function_head; $$->child = $2;
    $2->sibling = $3; $3->sibling = $5;
    }
    ;
procedure_decl : procedure_head T_SEMI sub_routine T_SEMI {
    InitNode(&$$); $$->type = e_procedure_decl; $$->child = $1;
    $1->sibling = $3;
    }
    ;
procedure_head : T_PROCEDURE T_NAME parameters {
    InitNode(&$$); $$->type = e_procedure_head; $$->child = $2;
    $2->sibling = $3;
    }
    ;
parameters : T_LP para_decl_list T_RP {
    InitNode(&$$); $$->type = e_parameters; $$->child = $2;
    }
    | /*empty*/{
    InitNode(&$$); $$->type = e_parameters;
    }
    ;
para_decl_list : para_decl_list T_SEMI para_type_list {
    InitNode(&$$); $$->type = e_para_decl_list; $$->child = $1;
    $1->sibling = $3;
    }
    | para_type_list {
    InitNode(&$$); $$->type = e_para_decl_list; $$->child = $1;
    }
    ;
para_type_list : var_para_list T_COLON simple_type_decl {
    InitNode(&$$); $$->type = e_para_type_list; $$->child = $1;
    $1->sibling = $3;
    }
    | val_para_list T_COLON simple_type_decl {
    InitNode(&$$); $$->type = e_para_type_list; $$->child = $1;
    $1->sibling = $3;
    }
    ;
var_para_list : T_VAR name_list {
    InitNode(&$$); $$->type = e_var_para_list; $$->child = $2;
    }
    ;
val_para_list : name_list {
    InitNode(&$$); $$->type = e_val_para_list; $$->child = $1;
    }
    ;
routine_body : compound_stmt {
    InitNode(&$$); $$->type = e_routine_body; $$->child = $1;
    }
    ;
compound_stmt : T_BEGIN stmt_list T_END {
    InitNode(&$$); $$->type = e_compound_stmt; $$->child = $2;
    }
    ;
stmt_list : stmt_list stmt T_SEMI {
    InitNode(&$$); $$->type = e_stmt_list; $$->child = $1;
    $1->sibling =$2;
    }
    | /*empty*/ {
    InitNode(&$$); $$->type = e_stmt_list;
    }
    ;
stmt : T_INTEGER T_COLON non_label_stmt {
    InitNode(&$$); $$->type = e_stmt; $$->child = $1;
    $1->sibling = $3;
    }
    | non_label_stmt {
    InitNode(&$$); $$->type = e_stmt; $$->child = $1;
    }
    ;
non_label_stmt : assign_stmt {
    InitNode(&$$); $$->type = e_non_label_stmt; $$->child = $1;
    }
    | proc_stmt {
    InitNode(&$$); $$->type = e_non_label_stmt; $$->child = $1;
    }
    | compound_stmt {
    InitNode(&$$); $$->type = e_non_label_stmt; $$->child = $1;
    }
    | if_stmt {
    InitNode(&$$); $$->type = e_non_label_stmt; $$->child = $1;
    }
    | repeat_stmt {
    InitNode(&$$); $$->type = e_non_label_stmt; $$->child = $1;
    }
    | while_stmt {
    InitNode(&$$); $$->type = e_non_label_stmt; $$->child = $1;
    }
    | for_stmt {
    InitNode(&$$); $$->type = e_non_label_stmt; $$->child = $1;
    }
    | case_stmt {
    InitNode(&$$); $$->type = e_non_label_stmt; $$->child = $1;
    }
    | goto_stmt {
    InitNode(&$$); $$->type = e_non_label_stmt; $$->child = $1;
    }
    ;
assign_stmt : T_NAME T_ASSIGN expression {
    InitNode(&$$); $$->type = e_assign_stmt; $$->child = $1;
    $1->sibling = $3;
    }
    | T_NAME T_LB expression T_RB T_ASSIGN expression {
    InitNode(&$$); $$->type = e_assign_stmt; $$->child = $1;
    $1->sibling = $3; $3->sibling = $6;
    }
    | T_NAME T_DOT T_NAME T_ASSIGN expression {
    InitNode(&$$); $$->type = e_assign_stmt; $$->child = $1;
    $1->sibling = $3; $3->sibling = $5;
    }
    ;
proc_stmt :  T_NAME T_LP args_list T_RP {
    InitNode(&$$); $$->type = e_proc_stmt; $$->child = $1;
    $1->sibling = $3;
    }
    |
    T_NAME {
    InitNode(&$$); $$->type = e_proc_stmt; $$->child = $1;
    }
    | T_SYS_PROC T_LP expression_list T_RP {
    InitNode(&$$); $$->type = e_proc_stmt; $$->child = $1;
    $1->sibling = $3;
    }
    | T_SYS_PROC {
    InitNode(&$$); $$->type = e_proc_stmt; $$->child = $1;
    }
    
    | T_READ T_LP factor T_RP {
    InitNode(&$$); $$->type = e_proc_stmt; $$->child = $1;
    $1->sibling = $3;
    }
    ;
if_stmt : T_IF expression T_THEN stmt else_clause {
    InitNode(&$$); $$->type = e_if_stmt; $$->child = $2;
    $2->sibling = $4; $4->sibling = $5;
    }
    ;
else_clause : T_ELSE stmt {
    InitNode(&$$); $$->type = e_else_clause; $$->child = $2;
    }
    | /*empty*/ {
    InitNode(&$$); $$->type = e_else_clause;
    }
    ;
repeat_stmt : T_REPEAT stmt_list T_UNTIL expression {
    InitNode(&$$); $$->type = e_repeat_stmt; $$->child = $2;
    $2->sibling = $4;
    }
    ;
while_stmt : T_WHILE expression T_DO stmt {
    InitNode(&$$); $$->type = e_while_stmt; $$->child = $2;
    $2->sibling = $4;
    }
    ;
for_stmt : T_FOR T_NAME T_ASSIGN expression direction expression T_DO stmt {
    InitNode(&$$); $$->type = e_for_stmt; $$->child = $2;
    $2->sibling = $4; $4->sibling = $5; $5->sibling = $6;
    $6->sibling = $8;
    }
    ;
direction : T_TO {
    InitNode(&$$); $$->type = e_direction; $$->child = $1;
    }
    | T_DOWNTO {
    InitNode(&$$); $$->type = e_direction; $$->child = $1;
    }
    ;
case_stmt : T_CASE expression T_OF case_expr_list T_END{
    InitNode(&$$); $$->type = e_case_stmt; $$->child = $2;
    $2->sibling = $4;
    }
    ;
case_expr_list : case_expr_list case_expr {
    InitNode(&$$); $$->type = e_case_expr_list; $$->child = $1;
    $1->sibling = $2;
    }
    | case_expr {
    InitNode(&$$); $$->type = e_case_expr_list; $$->child = $1;
    }
    ;
case_expr : const_value T_COLON stmt T_SEMI {
    InitNode(&$$); $$->type = e_case_expr; $$->child = $1;
    $1->sibling = $3;
    }
    | T_NAME T_COLON stmt T_SEMI {
    InitNode(&$$); $$->type = e_case_expr; $$->child = $1;
    $1->sibling = $3;
    }
    ;
goto_stmt : T_GOTO T_INTEGER {
    InitNode(&$$); $$->type = e_goto_stmt; $$->child = $2;
    }
    ;
expression_list : expression_list T_COMMA expression {
    InitNode(&$$); $$->type = e_expression_list; $$->child = $1;
    $1->sibling = $3;
    }
    | expression {
    InitNode(&$$); $$->type = e_expression_list; $$->child = $1;
    }
    ;
expression : expression T_GE expr {
    InitNode(&$$); $$->type = e_expression; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | expression T_GT expr {
    InitNode(&$$); $$->type = e_expression; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | expression T_LE expr {
    InitNode(&$$); $$->type = e_expression; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | expression T_LT expr {
    InitNode(&$$); $$->type = e_expression; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | expression T_EQUAL expr {
    InitNode(&$$); $$->type = e_expression; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | expression T_UNEQUAL expr {
    InitNode(&$$); $$->type = e_expression; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | expr {
    InitNode(&$$); $$->type = e_expression; $$->child = $1;
    }
    ;
expr : expr T_PLUS term {
    InitNode(&$$); $$->type = e_expr; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | expr T_MINUS term {
    InitNode(&$$); $$->type = e_expr; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | expr T_OR term {
    InitNode(&$$); $$->type = e_expr; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | term {
    InitNode(&$$); $$->type = e_expr; $$->child = $1;
    }
    ;
term : term T_MUL factor {
    InitNode(&$$); $$->type = e_term; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | term T_DIV factor {
    InitNode(&$$); $$->type = e_term; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | term T_MOD factor {
    InitNode(&$$); $$->type = e_term; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | term T_AND factor {
    InitNode(&$$); $$->type = e_term; $$->child = $1;
    $1->sibling = $2; $2->sibling = $3;
    }
    | factor {
    InitNode(&$$); $$->type = e_term; $$->child = $1;
    }
    ;
factor :  T_NAME T_LP args_list T_RP {
    InitNode(&$$); $$->type = e_factor; $$->child = $1;
    $1->sibling = $3;
    }
    | T_SYS_FUNCT {
    InitNode(&$$); $$->type = e_factor; $$->child = $1;
    }
    | T_SYS_FUNCT T_LP args_list T_RP {
    InitNode(&$$); $$->type = e_factor; $$->child = $1;
    $1->sibling = $3;
    }
    | const_value {
    InitNode(&$$); $$->type = e_factor; $$->child = $1;
    }
    | T_LP expression T_RP {
    InitNode(&$$); $$->type = e_factor; $$->child = $2;
    }
    | T_NOT factor {
    InitNode(&$$); $$->type = e_factor; $$->child = $1;
    $1->sibling = $2;
    }
    | T_MINUS factor {
    InitNode(&$$); $$->type = e_factor; $$->child = $1;
    $1->sibling = $2;
    }
    | T_NAME T_LB expression T_RB {
    InitNode(&$$); $$->type = e_factor; $$->child = $1;
    $1->sibling = $3;
    }
    | T_NAME T_DOT T_NAME {
    InitNode(&$$); $$->type = e_factor; $$->child = $1;
    $1->sibling = $3;
    }
    |
    T_NAME {
    InitNode(&$$); $$->type = e_factor; $$->child = $1;
    }
    ;
args_list : args_list T_COMMA expression {
    InitNode(&$$); $$->type = e_args_list; $$->child = $1;
    $1->sibling = $3;
    }
    | expression {
    InitNode(&$$); $$->type = e_args_list; $$->child = $1;
    }
    ;

%%

