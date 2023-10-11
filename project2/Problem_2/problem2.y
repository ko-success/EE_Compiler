%{ 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include "y.tab.h"

FILE *yyin;
char *filename;
char *yytext;
int yylineno;
int yyerrstatus;

int yylex (void);

int yywrap() {
  return 1; 
}

int yyerror(const char *str) {
    fprintf(stderr, "%s:%d: error: %s '%s' token\n", filename, yylineno, str, yytext);
    yyerrstatus = 0; // yyerrok; 에러 상태 초기화
    return 0;
}

%} 

%union {
    int number;
    char *string;
}

%token DEFINE IMPORT INT CHAR VOID IF FOR CONTINUE BREAK
%token OP_ASSIGN OP_INC OP_ADD OP_MUL OP_LOGIC OP_REL

%token <string> ID HFILE
%token <number> NUM 

%type <string> type_declaration ID_array assignment_statement initialize_statement

%right OP_ASSIGN
%left OP_LOGIC
%left OP_REL
%left OP_ADD
%left OP_MUL
%left OP_INC

%% 
Cprogram:
    Ccode
    ;

Ccode:
    preprocess body
    ;

preprocess:
    // epsilon production 
    | IMPORT head preprocess	{printf("Header(Import)\n");}
    | DEFINE definition preprocess {printf("Header(Define)\n");}
    ;

head:
	'<' HFILE '>'
    | '\"' HFILE '\"'
    ;

definition:
    function_declaration // {printf("Define(Funtion)");}
    | ID NUM // {printf("Define(Value)");}
    ;

body:
    // epsilon production 
    | function_declaration body
    ;

function_declaration:
    type_declaration '(' print_parameter ')' '{' statement '}'	{printf("Function (%s) matched!\n", $1);}
    | VOID ID '(' print_parameter ')' '{' statement '}'			{printf("Function (%s) matched!\n", $2);}
	;

type_declaration: 
	type ID_array		{$$=$2;}
	;

ID_array:
	ID array_dimention		{$$=$1;}
	;

type: // void를 제외한 모든 타입
    INT
    | CHAR
    ;

array_dimention:	// 2차원 이상의 경우 1차원을 제외한 차원은 개수를 정의해야하는데 이걸 어떻게 구현하지
	// epsilon production
	| '[' ']' array_dimention
	| '[' NUM ']' array_dimention
	| '[' ID ']' array_dimention 	// ID가 DEFINE된 숫자인지 확인 필요, 변수는 담지 못함
	;

print_parameter:
	parameter		{printf("Expression(FunctionArgsDec)\n");}
	;

parameter:	
	// epsilon production
	| type_declaration 
	| type_declaration ',' parameter
	;

statement:
    // epsilon production
	| single_statement statement
	| clause
	|'{' statement '}'
    ;

single_statement:
	initialize_statement ';'	
	{if(!strcmp($1, "")) printf("Statement(Declaration)\n"); 
		else printf("Statement(Assignment, %s)\n", $1);}
	| expression ';'
    | loop_control ';'
	| error ';'		 //{fprintf(stderr, "%s:%d: error: %s '%s' token\n", filename, yylineno, str, yytext);}
	//{fprintf(stderr, "Syntax error in %s at line %d: Unexpected token %s\n", filename, yylineno, yytext); yyerrok;}
	;

clause:
    if_statement statement
    | for_statement statement
	;

single_or_brace_statement:
	single_statement
	| '{' statement '}'
	;

initialize_statement:
	variable_declaration	{$$="";}
	| assignment_statement	{$$=$1;}
	;
	
variable_declaration:
    type_declaration vars
    ;

vars:
	// epsilon production
	| ',' ID vars
	| OP_ASSIGN expression
    ;

assignment_statement:
    ID_array OP_ASSIGN expression	{$$=$1;}
    ;

if_statement:
    IF '(' print_test ')' single_or_brace_statement     {printf("Clause(if) matched!\n");}
    ;

for_statement: 
    FOR '(' print_initialize ';' print_test ';' print_update ')' single_or_brace_statement		{printf("Clause(for) matched!\n");}
    ;

print_initialize:
	initialize_statement	{printf("Statement(Initialize)\n");}
	;
	
print_test:
	expression	{printf("Expression(Test)\n");}
	;

print_update:
	expression	{printf("Statement(Update)\n");}
	;

loop_control: // 반복문 or switch문에서만 사용 가능
    CONTINUE	{printf("Statement(Continue)\n");}
    | BREAK 
    ;

expression:
    ID_array OP_INC		// {printf("Variable Increase: %s\n", $1);}
    | factor operator_expression
    | '(' expression ')'
    ;

factor:
	NUM
	| ID_array
	;

operator_expression:
	// epsilon production
    | OP_ADD expression      // {printf("Addition Expression\n");}
    | OP_MUL expression      // {printf("Multiplication Expression\n");}
    | OP_LOGIC expression    // {printf("Logical Expression\n");}
    | OP_REL expression      // {printf("Relational Expression\n");}
	;

%%

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage : %s <input_file>\n", argv[0]);
    return 1;
  }

  FILE* input_file = fopen(argv[1], "r" );
  filename = argv[1];

  if(!input_file) {
    perror("Error opening input file");
    return 1;
  }

  ++argv, --argc; /* skip over program name */

  if(argc > 0)
    yyin = input_file;
  else
    yyin = stdin ;

  yyparse();

  fclose(input_file);

  return 0;
}


