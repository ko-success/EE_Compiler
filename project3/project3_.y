
%{
/**********PROLOGUE AREA**********/
//THIS AREA WILL BE COPIED TO y.tab.c CODE

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.c"


//Entry point of parse tree
NODE *head;
//String buffer
char buf[100];

extern FILE *yyin;
extern char *yytext;
extern int yylineno;
char * filename;

int yylex (void);

int yywrap() {
  return 1; 
}

void yyerror(const char *str)
{
	fprintf(stderr, "%s:%d: error: %s '%s' token \n", filename, yylineno, str, yytext);
}

%}

/**********GRAMMAR AREA**********/
%union {
	int number;
	char *string;
	NODE *node;
}

//Tokens & Nonterms
%token <string> DEFINE
%token <string> INT VOID
%token <string> IF FOR
%token <string> CONTINUE
%token <string> OP_ASSIGN OP_INC OP_ADD OP_MUL OP_LOGIC OP_REL
%token <string> ID
%token <string> NUM
%token <string> LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET COMMA SEMICOLON


%start c_code
%type <node> c_code code define_header func_def func_arg_dec body statement assign_stmt continue_stmt expr decl_list decl_init al_expr rel_expr inc_expr variable value type clause init_stmt test_expr update_stmt

%%
//CFG

//todo: build parse tree in actions
c_code:
	code 			
					{
						NODE* codeN = MakeNode("code");
						InsertChild($$, codeN);
					}

	| c_code code 	
					{
						NODE* c_codeN = MakeNode("c_code");
						NODE* codeN = MakeNode("code");
						InsertChild($$, c_codeN);
						InsertSibling(c_codeN, codeN);
					}
	;

code:
	define_header 	{

					}

	|func_def     	{
					
					} 
	;

define_header:
	DEFINE ID NUM 	
					{
					
					}
	;

func_def:
	type ID '(' func_arg_dec ')' '{' body '}'  	
					{
					
					}
	;

func_arg_dec:
	decl_list 	
					{
					
					}
	;

body:
	clause     	
					{
					
					}
	|statement 	
					{
					
					}
	|body body 	
					{
					
					}
	;

clause: 
    FOR '(' init_stmt test_expr ';' update_stmt ')' '{' body '}' 	
					{
					
					}

    |IF '(' test_expr ')' '{' body '}' 			
					{
					
					}

    |IF '(' test_expr ')' statement 			
					{
					
					}
	;

statement:
    assign_stmt ';'  	
					{
					
					}

    |continue_stmt ';' 	
					{
					
					}

	|decl_list ';' 		
					{
					
					}

	|error ';'
	;

init_stmt:
	assign_stmt ';' 

					{
					
					}

	|decl_list ';'  
					{
					
					}
	;

update_stmt:
	inc_expr		
					{
					
					}
	|decl_list		
					{
					
					}
	;

assign_stmt:
    variable OP_ASSIGN al_expr 
					{
					
					}
    ;

continue_stmt:
    CONTINUE   
					{
					
					}
    ;

expr:
	rel_expr   
					{
					
					}

	|inc_expr  
					{
					
					}

    |al_expr   
					{
					
					}
	;

test_expr:
	rel_expr  
					{
					
					}
	;

decl_list:
	decl_init  					
					{
					
					}

	|decl_list ',' variable  	
					{
					
					}

	|decl_list ',' decl_init 	
					{
					
					}
	;

decl_init:
	type variable 
					{
					
					}
	;

al_expr:
	NUM 						
					{
					
					}

	| variable 					
					{
					
					}

	| al_expr OP_ADD al_expr 	
					{
					
					}

	| al_expr OP_MUL al_expr 	
					{
					
					}
	;

rel_expr:
	value 							
					{
					
					}

	| rel_expr OP_REL rel_expr  	
					{
					
					}

	| rel_expr OP_LOGIC rel_expr	
					{
					
					}
	;

inc_expr:
	variable OP_INC 
					{
					
					}
	;

value:
	variable 		
					{
					
					}

	| NUM	 		
					{
					
					}
	;

variable:
	ID 				
					{
					
					}

	|variable '[' ']'			
					{
					
					}

	|variable '[' NUM ']'		
					{
					
					}

	|variable '[' al_expr ']'	
					{
					
					}
	;

type:
	VOID		
					{
					
					}
	| INT		
					{
					
					}
	;

%%

/**********EPILOGUE AREAR AREA**********/
//THIS AREA WILL BE COPIED TO y.tab.c CODE


int main(int argc, char **argv )
{
	++argv, --argc; /* skip over program name */
	if ( argc > 0 )
		yyin = fopen( argv[0], "r" );
	else
		yyin = stdin;
	filename = argv[0];

	// initializing
	head = MakeNode("c_code");

	yyparse();

	WalkTree(head);

	// delete tree

	return 0;
}
