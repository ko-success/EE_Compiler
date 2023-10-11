%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
%}



%%

#define												printf("DEFINE "); 
int													printf("INT "); 
void												printf("VOID ");
if													printf("IF "); 
for													printf("FOR "); 
continue											printf("CONTINUE ");
[a-zA-Z_][a-zA-Z_0-9]*								printf("ID-%s ", strdup(yytext)); 
"="|"+="											printf("OP_ASSIGN "); 
"++"												printf("OP_INC "); 
"+"|"-"												printf("OP_ADD "); 
"*"|"/"												printf("OP_MUL "); 
"&&"|"||"											printf("OP_LOGIC ");
"!="|"=="|"<"|">"|"<="|">="							printf("OP_REL "); 
[0-9]+	 											printf("NUM-%d ", atoi(yytext)); 
"["|"]"|"{"|"}"|"("|")"|";"|","						printf("%c ", yytext[0]);
\n 													printf("\nLine "); 
\/\/.*|\/\*.*\*\/									;/* ignore commnets */
[ \t]+												;/* ignore whitespace */
%%


int main(int argc, char** argv) {
//   if (argc != 2) {
//     printf("Usage : %s <input_file>\n", argv[0]);
//     return 1;
//   }

//   FILE* input_file; = fopen(argv[1], "r" );

//   if(!input_file) {
//     perror("Error opening input file");
//     return 1;
//   }

  ++argv, --argc; /* skip over program name */

  if(argc > 0)
    // yyin = input_file;
	yyin = fopen(argv[0], "r");
  else
    yyin = stdin ;

  yylex();

//   fclose(input_file);

  return 0;
}