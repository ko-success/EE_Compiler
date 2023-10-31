
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


%start goal
%type <node> goal c_code code define_header func_def func_arg_dec body statement assign_stmt continue_stmt expr decl_list decl_init al_expr rel_expr inc_expr variable value type clause init_stmt test_expr update_stmt

%%
//CFG

//todo: build parse tree in actions
goal:
	c_code
					{
						// initialize tree
						head = $1;
					}
	;

c_code:
	code 			
					{
						$$ = MakeNode("c_code");
						InsertChild($$, $1);
					}

	| c_code code 	
					{
						$$ = MakeNode("c_code");
						InsertChild($$, $1);
						InsertSibling($1, $2);
					}
	;

code:
	define_header 	{
						$$ = MakeNode("code");
						InsertChild($$, $1);
					}

	|func_def     	{
						$$ = MakeNode("code");
						InsertChild($$, $1);
					} 
	;

define_header:
	DEFINE ID NUM 	
					{
						$$ = MakeNode("define_header");

						char* defS = strdup("DEFINE: ");
						char* idS = strdup("ID: ");
						char* numS = strdup("NUM: ");

						strcat(defS, $1);
						strcat(idS, $2);
						strcat(numS, $3);

						NODE* defN = MakeNode(defS);
						NODE* idN = MakeNode(idS);
						NODE* numN = MakeNode(numS);

						InsertChild($$, defN);
						InsertSibling(defN, idN);
						InsertSibling(idN, numN);

						free(defS);
						free(idS);
						free(numS);
					}
	;

func_def:
	type ID LPAREN func_arg_dec RPAREN LBRACE body RBRACE  	
					{
						$$ = MakeNode("func_def");

						char* idS = strdup("ID: ");
						char* lparenS = strdup("LPAREN: ");
						char* rparenS = strdup("RPAREN: ");
						char* lbraceS = strdup("LBRACE: ");
						char* rbraceS = strdup("RBRACE: ");

						strcat(idS, $2);
						strcat(lparenS, $3);
						strcat(rparenS, $5);
						strcat(lbraceS, $6);
						strcat(rbraceS, $8);

						NODE* idN = MakeNode(idS);
						NODE* lparenN = MakeNode(lparenS);
						NODE* rparenN = MakeNode(rparenS);
						NODE* lbraceN = MakeNode(lbraceS);
						NODE* rbraceN = MakeNode(rbraceS);

						InsertChild($$, $1);
						InsertSibling($1, idN);
						InsertSibling(idN, lparenN);
						InsertSibling(lparenN, $4);
						InsertSibling($4, rparenN);
						InsertSibling(rparenN, lbraceN);
						InsertSibling(lbraceN, $7);
						InsertSibling($7, rbraceN);

						free(idS);
						free(lparenS);
						free(rparenS);
						free(lbraceS);
						free(rbraceS);
					}
	;

func_arg_dec:
	decl_list 	
					{
						$$ = MakeNode("func_arg_dec");
						InsertChild($$, $1);
					}
	;

body:
	clause     	
					{
						$$ = MakeNode("body");
						InsertChild($$, $1);
					}
	|statement 	
					{
						$$ = MakeNode("body");
						InsertChild($$, $1);
					}
	|body body 	
					{
						$$ = MakeNode("body");
						InsertChild($$, $1);
						InsertSibling($1, $2);
					}
	;

clause: 
    FOR LPAREN init_stmt test_expr SEMICOLON update_stmt RPAREN LBRACE body RBRACE 	
					{
						$$ = MakeNode("clause");

						char* forS = strdup("FOR: ");
						char* semicolonS = strdup("SEMICOLON: ");
						char* lparenS = strdup("LPAREN: ");
						char* rparenS = strdup("RPAREN: ");
						char* lbraceS = strdup("LBRACE: ");
						char* rbraceS = strdup("RBRACE: ");

						strcat(forS, $1);
						strcat(semicolonS, $5);
						strcat(lparenS, $2);
						strcat(rparenS, $7);
						strcat(lbraceS, $8);
						strcat(rbraceS, $10);

						NODE* forN = MakeNode(forS);
						NODE* semicolonN = MakeNode(semicolonS);
						NODE* lparenN = MakeNode(lparenS);
						NODE* rparenN = MakeNode(rparenS);
						NODE* lbraceN = MakeNode(lbraceS);
						NODE* rbraceN = MakeNode(rbraceS);

						InsertChild($$, forN);
						InsertSibling(forN, lparenN);
						InsertSibling(lparenN, $3);
						InsertSibling($3, $4);
						InsertSibling($4, semicolonN);
						InsertSibling(semicolonN, $6);
						InsertSibling($6, rparenN);
						InsertSibling(rparenN, lbraceN);
						InsertSibling(lbraceN, $9);
						InsertSibling($9, rbraceN);

						free(forS);
						free(semicolonS);
						free(lparenS);
						free(rparenS);
						free(lbraceS);
						free(rbraceS);
					}

    |IF LPAREN test_expr RPAREN LBRACE body RBRACE 			
					{
						$$ = MakeNode("clause");

						char* ifS = strdup("IF: ");
						char* lparenS = strdup("LPAREN: ");
						char* rparenS = strdup("RPAREN: ");
						char* lbraceS = strdup("LBRACE: ");
						char* rbraceS = strdup("RBRACE: ");

						strcat(ifS, $1);
						strcat(lparenS, $2);
						strcat(rparenS, $4);
						strcat(lbraceS, $5);
						strcat(rbraceS, $7);

						NODE* ifN = MakeNode(ifS);
						NODE* lparenN = MakeNode(lparenS);
						NODE* rparenN = MakeNode(rparenS);
						NODE* lbraceN = MakeNode(lbraceS);
						NODE* rbraceN = MakeNode(rbraceS);

						InsertChild($$, ifN);
						InsertSibling(ifN, lparenN);
						InsertSibling(lparenN, $3);
						InsertSibling($3, rparenN);
						InsertSibling(rparenN, lbraceN);
						InsertSibling(lbraceN, $6);
						InsertSibling($6, rbraceN);

						free(ifS);
						free(lparenS);
						free(rparenS);
						free(lbraceS);
						free(rbraceS);
					}

    |IF LPAREN test_expr RPAREN statement 			
					{
						$$ = MakeNode("clause");

						char* ifS = strdup("IF: ");
						char* lparenS = strdup("LPAREN: ");
						char* rparenS = strdup("RPAREN: ");

						strcat(ifS, $1);
						strcat(lparenS, $2);
						strcat(rparenS, $4);

						NODE* ifN = MakeNode(ifS);
						NODE* lparenN = MakeNode(lparenS);
						NODE* rparenN = MakeNode(rparenS);

						InsertChild($$, ifN);
						InsertSibling(ifN, lparenN);
						InsertSibling(lparenN, $3);
						InsertSibling($3, rparenN);
						InsertSibling(rparenN, $5);

						free(ifS);
						free(lparenS);
						free(rparenS);
					}
	;

statement:
    assign_stmt SEMICOLON  	
					{
						$$ = MakeNode("statement");

						char* semicolonS = strdup("SEMICOLON: ");

						strcat(semicolonS, $2);

						NODE* semicolonN = MakeNode(semicolonS);

						InsertChild($$, $1);
						InsertSibling($1, semicolonN);

						free(semicolonS);
					}

    |continue_stmt SEMICOLON 	
					{
						$$ = MakeNode("statement");

						char* semicolonS = strdup("SEMICOLON: ");

						strcat(semicolonS, $2);

						NODE* semicolonN = MakeNode(semicolonS);

						InsertChild($$, $1);
						InsertSibling($1, semicolonN);

						free(semicolonS);
					}

	|decl_list SEMICOLON 		
					{
						$$ = MakeNode("statement");

						char* semicolonS = strdup("SEMICOLON: ");

						strcat(semicolonS, $2);

						NODE* semicolonN = MakeNode(semicolonS);

						InsertChild($$, $1);
						InsertSibling($1, semicolonN);

						free(semicolonS);
					}

	|error SEMICOLON
	;

init_stmt:
	assign_stmt SEMICOLON 

					{
						$$ = MakeNode("init_stmt");

						char* semicolonS = strdup("SEMICOLON: ");

						strcat(semicolonS, $2);

						NODE* semicolonN = MakeNode(semicolonS);

						InsertChild($$, $1);
						InsertSibling($1, semicolonN);

						free(semicolonS);
					}

	|decl_list SEMICOLON  
					{
						$$ = MakeNode("init_stmt");

						char* semicolonS = strdup("SEMICOLON: ");

						strcat(semicolonS, $2);

						NODE* semicolonN = MakeNode(semicolonS);

						InsertChild($$, $1);
						InsertSibling($1, semicolonN);

						free(semicolonS);
					}
	;

update_stmt:
	inc_expr		
					{
						$$ = MakeNode("update_stmt");
						InsertChild($$, $1);
					}
	|decl_list		
					{
						$$ = MakeNode("update_stmt");
						InsertChild($$, $1);
					}
	;

assign_stmt:
    variable OP_ASSIGN al_expr 
					{
						$$ = MakeNode("assign_stmt");

						char* op_assignS = strdup("OP_ASSIGN: ");

						strcat(op_assignS, $2);

						NODE* op_assignN = MakeNode(op_assignS);

						InsertChild($$, $1);
						InsertSibling($1, op_assignN);
						InsertSibling(op_assignN, $3);

						free(op_assignS);	
					}
    ;

continue_stmt:
    CONTINUE   
					{
						$$ = MakeNode("continue_stmt");

						char* continueS = strdup("CONTINUE: ");

						strcat(continueS, $1);

						NODE* continueN = MakeNode(continueS);

						InsertChild($$, continueN);

						free(continueS);	
					}
    ;

expr:
	rel_expr   
					{
						$$ = MakeNode("expr");
						InsertChild($$, $1);
					}

	|inc_expr  
					{
						$$ = MakeNode("expr");
						InsertChild($$, $1);
					}

    |al_expr   
					{
						$$ = MakeNode("expr");
						InsertChild($$, $1);
					}
	;

test_expr:
	rel_expr  
					{
						$$ = MakeNode("test_expr");
						InsertChild($$, $1);
					}
	;

decl_list:
	decl_init  					
					{
						$$ = MakeNode("decl_list");
						InsertChild($$, $1);
					}

	|decl_list COMMA variable  	
					{
						$$ = MakeNode("decl_list");

						char* commaS = strdup("COMMA: ");

						strcat(commaS, $2);

						NODE* commaN = MakeNode(commaS);

						InsertChild($$, $1);
						InsertSibling($1, commaN);
						InsertSibling(commaN, $3);

						free(commaS);	
					}

	|decl_list COMMA decl_init 	
					{
						$$ = MakeNode("decl_list");

						char* commaS = strdup("COMMA: ");

						strcat(commaS, $2);

						NODE* commaN = MakeNode(commaS);

						InsertChild($$, $1);
						InsertSibling($1, commaN);
						InsertSibling(commaN, $3);

						free(commaS);	
					}
	;

decl_init:
	type variable 
					{
						$$ = MakeNode("decl_init");
						InsertChild($$, $1);
						InsertSibling($1, $2);
					}
	;

al_expr:
	NUM 						
					{
						$$ = MakeNode("al_expr");

						char* numS = strdup("NUM: ");

						strcat(numS, $1);

						NODE* numN = MakeNode(numS);

						InsertChild($$, numN);

						free(numS);	
					}

	| variable 					
					{
						$$ = MakeNode("al_expr");
						InsertChild($$, $1);
					}

	| al_expr OP_ADD al_expr 	
					{
						$$ = MakeNode("al_expr");

						char* op_addS = strdup("OP_ADD: ");

						strcat(op_addS, $2);

						NODE* op_addN = MakeNode(op_addS);

						InsertChild($$, $1);
						InsertSibling($1, op_addN);
						InsertSibling(op_addN, $3);

						free(op_addS);	
					}

	| al_expr OP_MUL al_expr 	
					{
						$$ = MakeNode("al_expr");

						char* op_mulS = strdup("OP_MUL: ");

						strcat(op_mulS, $2);

						NODE* op_mulN = MakeNode(op_mulS);

						InsertChild($$, $1);
						InsertSibling($1, op_mulN);
						InsertSibling(op_mulN, $3);

						free(op_mulS);	
						}
	;

rel_expr:
	value 							
					{
						$$ = MakeNode("rel_expr");
						InsertChild($$, $1);
					}

	| rel_expr OP_REL rel_expr  	
					{
						$$ = MakeNode("rel_expr");

						char* op_relS = strdup("OP_REL: ");

						strcat(op_relS, $2);

						NODE* op_relN = MakeNode(op_relS);

						InsertChild($$, $1);
						InsertSibling($1, op_relN);
						InsertSibling(op_relN, $3);

						free(op_relS);
					}

	| rel_expr OP_LOGIC rel_expr	
					{
						$$ = MakeNode("rel_expr");

						char* op_logicS = strdup("OP_LOGIC: ");

						strcat(op_logicS, $2);

						NODE* op_logicN = MakeNode(op_logicS);

						InsertChild($$, $1);
						InsertSibling($1, op_logicN);
						InsertSibling(op_logicN, $3);

						free(op_logicS);
					}
	;

inc_expr:
	variable OP_INC 
					{
						$$ = MakeNode("inc_expr");

						char* op_incS = strdup("OP_INC: ");

						strcat(op_incS, $2);

						NODE* op_incN = MakeNode(op_incS);

						InsertChild($$, $1);
						InsertSibling($1, op_incN);

						free(op_incS);
					}
	;

value:
	variable 		
					{
						$$ = MakeNode("value");
						InsertChild($$, $1);
					}

	| NUM	 		
					{
						$$ = MakeNode("value");

						char* numS = strdup("NUM: ");

						strcat(numS, $1);

						NODE* numN = MakeNode(numS);

						InsertChild($$, numN);

						free(numS);	
					}
	;

variable:
	ID 				
					{
						$$ = MakeNode("variable");

						char* idS = strdup("ID: ");

						strcat(idS, $1);

						NODE* idN = MakeNode(idS);

						InsertChild($$, idN);

						free(idS);
					}

	|variable LBRACKET RBRACKET			
					{
						$$ = MakeNode("variable");

						char* lbracketS = strdup("LBRACKET: ");
						char* rbracketS = strdup("RBRACKET: ");

						strcat(lbracketS, $2);
						strcat(rbracketS, $3);

						NODE* lbracketN = MakeNode(lbracketS);
						NODE* rbracketN = MakeNode(rbracketS);

						InsertChild($$, $1);
						InsertSibling($1, lbracketN);
						InsertSibling(lbracketN, rbracketN);

						free(lbracketS);
						free(rbracketS);
					}

	|variable LBRACKET NUM RBRACKET		
					{
						$$ = MakeNode("variable");

						char* numS = strdup("NUM: ");
						char* lbracketS = strdup("LBRACKET: ");
						char* rbracketS = strdup("RBRACKET: ");

						strcat(numS, $3);
						strcat(lbracketS, $2);
						strcat(rbracketS, $4);

						NODE* numN = MakeNode(numS);
						NODE* lbracketN = MakeNode(lbracketS);
						NODE* rbracketN = MakeNode(rbracketS);

						InsertChild($$, $1);
						InsertSibling($1, lbracketN);
						InsertSibling(lbracketN, numN);
						InsertSibling(numN, rbracketN);

						free(numS);
						free(lbracketS);
						free(rbracketS);
					}

	|variable LBRACKET al_expr RBRACKET	
					{
						$$ = MakeNode("variable");

						char* lbracketS = strdup("LBRACKET: ");
						char* rbracketS = strdup("RBRACKET: ");

						strcat(lbracketS, $2);
						strcat(rbracketS, $4);

						NODE* lbracketN = MakeNode(lbracketS);
						NODE* rbracketN = MakeNode(rbracketS);

						InsertChild($$, $1);
						InsertSibling($1, lbracketN);
						InsertSibling(lbracketN, $3);
						InsertSibling($3, rbracketN);

						free(lbracketS);
						free(rbracketS);
					}
	;

type:
	VOID		
					{
						$$ = MakeNode("type");

						char* voidS = strdup("VOID: ");

						strcat(voidS, $1);

						NODE* voidN = MakeNode(voidS);

						InsertChild($$, voidN);

						free(voidS);
					}
	| INT		
					{
						$$ = MakeNode("type");

						char* intS = strdup("INT: ");

						strcat(intS, $1);

						NODE* intN = MakeNode(intS);

						InsertChild($$, intN);

						free(intS);
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

	// initialize tree
	// head = MakeNode("c_code");

	yyparse();

	WalkTree(head);

	// need to deallocate tree

	return 0;
}
