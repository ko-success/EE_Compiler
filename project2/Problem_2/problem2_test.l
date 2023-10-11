%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}



%%

#define								                printf("DEFINE "); return DEFINE; 
int									                printf("INT "); return INT; 
void								                printf("VOID "); return VOID; 
if									                printf("IF "); return IF; 
for									                printf("FOR "); return FOR; 
continue                                            printf("CONTINUE "); return CONTINUE; 
[a-zA-Z_][a-zA-Z_0-9]*			                    printf("ID-%s ", strdup(yytext)); yylval.string=strdup(yytext); 	return ID;
"="|"+="							                printf("OP_ASSIGN "); return OP_ASSIGN;   
"++"								                printf("OP_INC "); return OP_INC;
"+"|"-"								                printf("OP_ADD "); return OP_ADD;
"*"|"/"								                printf("OP_MUL "); return OP_MUL;
"&&"|"||"							                printf("OP_LOGIC "); return OP_LOGIC;
"!="|"=="|"<"|">"|"<="|">="						    printf("OP_REL "); return OP_REL;
[0-9]+	 				                            printf("NUM-%d ", atoi(yytext)); yylval.number=atoi(yytext);	return NUM;     
"["|"]"|"{"|"}"|"("|")"|";"|","						printf("%c ", yytext[0]); return yytext[0];
\n 		                 	   	 			        printf("\n"); {yylineno ++;};
\/\/.*|\/\*.*\*\/							        ;/* ignore commnets */
[ \t]+   		               					    ;/* ignore whitespace */
%%
