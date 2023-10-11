%{
#include <stdio.h>
%}

DIGIT [0-9]
NUM   {DIGIT}+
ID    [_a-zA-Z][_a-zA-Z0-9]*

%%
#define           printf("DEFINE ");
#includ           printf("INCLUDE ");

const             printf("CONST ");
static            printf("STATIC ");
auto              printf("AUTO ");
extern            printf("EXTERN ");
volatile          printf("VOLATILE ");
signed            printf("SIGNED ");
unsigned          printf("UNSIGNED ");
restrict          printf("RESTRICT ");
inline            printf("INLINE ");

void              printf("VOID ");
short             printf("SHORT ");
int               printf("INT ");
long              printf("LONG ");
float             printf("FLOAT ");
double            printf("DOUBLE ");
char              printf("CHAR ");
_Bool             printf("BOOL ");
_Complex          printf("COMPLEX ");
_Imaginary        printf("IMAGINARY ");

enum              printf("ENUM ");
struct            printf("STRUCT ");
union             printf("UNION ");
typedef           printf("TYPEDEF ");
register          printf("REGISTER ");

for               printf("FOR ");
do                printf("DO ");
while             printf("WHILE ");
continue          printf("CONTINUE ");
break             printf("BREAK ");
goto              printf("GOTO ");

if                printf("IF ");
else              printf("ELSE ");
switch            printf("SWITCH ");
case              printf("CASE ");
default           printf("DEFAULT ");

return            printf("RETURN ");
sizeof            printf("SIZEOF ");

"+"                           printf("OP_ADD "); 
"-"                           printf("OP_SUB "); 
"*"                           printf("OP_MUL "); 
"/"                           printf("OP_DIV ");
"%"                           printf("OP_MOD ");

"++"                          printf("OP_INC ");
"--"                          printf("OP_DEC "); 

"="                           printf("OP_ASSIGN ");
"*="|"/="|"%="|"+="|"-="      printf("OP_ASSIGN "); // assign with arithmetic expression
"&="|"^="|"|="                printf("OP_ASSIGN "); // assign with logical expression

"&&"|"||"|"~"                 printf("OP_LOGIC "); // AND | OR | NOT
"&"|"|"|"!"|"^"               printf("OP_BIT_LOGIC "); // AND | OR | NOT | XOR - BIT
"<<"|">>"                     printf("OP_SHIFT ");

"=="|"!="|"<="|">="|"<"|">"   printf("OP_REL ");

"("|")"|"["|"]"|"{"|"}"|;|,   printf("%s ", yytext); // DELIMETER

\n                            printf("\n");
[ \t]+                        ; // ignore whitespace 
"//"(.)*                      printf("COMMENT ");
"/*"([^*]|\*+[^*/])*\*+"/"    printf("COMMENT ");  

{ID}                          printf("ID ");
{NUM}                         printf("NUM "); 
{NUM}"."{DIGIT}*              printf("FLOAT ");  // . -> ? :  ... <<= >>= # ## <: :> <% %> %: %:%:

%%

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage : %s <input_file>\n", argv[0]);
    return 1;
  }

  FILE* input_file = fopen(argv[1], "r" );

  if(!input_file) {
    perror("Error opening input file");
    return 1;
  }

  ++argv, --argc; /* skip over program name */

  if(argc > 0)
    yyin = input_file;
  else
    yyin = stdin ;

  yylex();

  fclose(input_file);

  return 0;
}