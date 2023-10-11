%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}



%%

#define								                return DEFINE;
int									                return INT;
void								                return VOID;
if									                return IF;
for									                return FOR;
continue                                            return CONTINUE;
[a-zA-Z_][a-zA-Z_0-9]*			                    yylval.string=strdup(yytext); 	return ID;
"="|"+="							                return OP_ASSIGN;
"++"								                return OP_INC;
"+"|"-"								                return OP_ADD;
"*"|"/"								                return OP_MUL;
"&&"|"||"							                return OP_LOGIC;
"!="|"=="|"<"|">"|"<="|">="						    return OP_REL;
[0-9]+	 				yylval.number=atoi(yytext);	return NUM;
"["|"]"|"{"|"}"|"("|")"|";"|","						return yytext[0];
\n 		                 	   	 			        {yylineno ++;}
\/\/.*|\/\*.*\*\/							        /* ignore commnets */
[ \t]+   		               					    /* ignore whitespace */
%%


