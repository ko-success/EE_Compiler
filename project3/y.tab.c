/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DEFINE = 258,
     INT = 259,
     VOID = 260,
     IF = 261,
     FOR = 262,
     CONTINUE = 263,
     OP_ASSIGN = 264,
     OP_INC = 265,
     OP_ADD = 266,
     OP_MUL = 267,
     OP_LOGIC = 268,
     OP_REL = 269,
     ID = 270,
     NUM = 271,
     LPAREN = 272,
     RPAREN = 273,
     LBRACE = 274,
     RBRACE = 275,
     LBRACKET = 276,
     RBRACKET = 277,
     COMMA = 278,
     SEMICOLON = 279
   };
#endif
/* Tokens.  */
#define DEFINE 258
#define INT 259
#define VOID 260
#define IF 261
#define FOR 262
#define CONTINUE 263
#define OP_ASSIGN 264
#define OP_INC 265
#define OP_ADD 266
#define OP_MUL 267
#define OP_LOGIC 268
#define OP_REL 269
#define ID 270
#define NUM 271
#define LPAREN 272
#define RPAREN 273
#define LBRACE 274
#define RBRACE 275
#define LBRACKET 276
#define RBRACKET 277
#define COMMA 278
#define SEMICOLON 279




/* Copy the first part of user declarations.  */
#line 2 "project3.y"

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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "project3.y"
{
	int number;
	char *string;
	NODE *node;
}
/* Line 193 of yacc.c.  */
#line 184 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 197 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNRULES -- Number of states.  */
#define YYNSTATES  90

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    18,    27,
      29,    31,    33,    36,    47,    55,    61,    64,    67,    70,
      73,    76,    79,    81,    83,    87,    89,    91,    93,    97,
     101,   104,   106,   108,   112,   116,   118,   122,   126,   129,
     131,   133,   135,   139,   144,   149,   151
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      26,     0,    -1,    27,    -1,    28,    -1,    27,    28,    -1,
      29,    -1,    30,    -1,     3,    15,    16,    -1,    47,    15,
      17,    31,    18,    19,    32,    20,    -1,    40,    -1,    33,
      -1,    34,    -1,    32,    32,    -1,     7,    17,    35,    39,
      24,    36,    18,    19,    32,    20,    -1,     6,    17,    39,
      18,    19,    32,    20,    -1,     6,    17,    39,    18,    34,
      -1,    37,    24,    -1,    38,    24,    -1,    40,    24,    -1,
       1,    24,    -1,    37,    24,    -1,    40,    24,    -1,    44,
      -1,    40,    -1,    46,     9,    42,    -1,     8,    -1,    43,
      -1,    41,    -1,    40,    23,    46,    -1,    40,    23,    41,
      -1,    47,    46,    -1,    16,    -1,    46,    -1,    42,    11,
      42,    -1,    42,    12,    42,    -1,    45,    -1,    43,    14,
      43,    -1,    43,    13,    43,    -1,    46,    10,    -1,    46,
      -1,    16,    -1,    15,    -1,    46,    21,    22,    -1,    46,
      21,    16,    22,    -1,    46,    21,    42,    22,    -1,     5,
      -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    70,    76,    85,    90,    97,   124,   164,
     172,   177,   182,   191,   235,   272,   301,   317,   333,   349,
     353,   370,   388,   393,   401,   420,   457,   465,   471,   488,
     507,   516,   531,   537,   554,   573,   579,   596,   615,   633,
     639,   656,   671,   692,   718,   742,   756
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINE", "INT", "VOID", "IF", "FOR",
  "CONTINUE", "OP_ASSIGN", "OP_INC", "OP_ADD", "OP_MUL", "OP_LOGIC",
  "OP_REL", "ID", "NUM", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACKET", "RBRACKET", "COMMA", "SEMICOLON", "$accept", "goal",
  "c_code", "code", "define_header", "func_def", "func_arg_dec", "body",
  "clause", "statement", "init_stmt", "update_stmt", "assign_stmt",
  "continue_stmt", "test_expr", "decl_list", "decl_init", "al_expr",
  "rel_expr", "inc_expr", "value", "variable", "type", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    25,    26,    27,    27,    28,    28,    29,    30,    31,
      32,    32,    32,    33,    33,    33,    34,    34,    34,    34,
      35,    35,    36,    36,    37,    38,    39,    40,    40,    40,
      41,    42,    42,    42,    42,    43,    43,    43,    44,    45,
      45,    46,    46,    46,    46,    47,    47
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     8,     1,
       1,     1,     2,    10,     7,     5,     2,     2,     2,     2,
       2,     2,     1,     1,     3,     1,     1,     1,     3,     3,
       2,     1,     1,     3,     3,     1,     3,     3,     2,     1,
       1,     1,     3,     4,     4,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    46,    45,     0,     2,     3,     5,     6,     0,
       0,     1,     4,     0,     7,     0,     0,     9,    27,     0,
       0,     0,    41,    30,     0,    29,    28,     0,     0,     0,
       0,    25,     0,    10,    11,     0,     0,     0,     0,    31,
      42,     0,    32,    19,     0,     0,     8,     0,    16,    17,
      18,     0,    43,     0,     0,    44,    40,     0,    26,    35,
      39,     0,     0,     0,    31,    24,    33,    34,     0,     0,
       0,     0,    20,    21,     0,    15,    37,    36,     0,     0,
       0,    23,    22,     0,    14,     0,    38,     0,     0,    13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    16,    47,    33,    34,
      61,    80,    35,    36,    57,    37,    18,    41,    58,    82,
      59,    38,    19
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -25
static const yytype_int8 yypact[] =
{
      21,   -12,   -25,   -25,    20,    21,   -25,   -25,   -25,    14,
      17,   -25,   -25,    63,   -25,    43,    33,    69,   -25,    82,
      80,     3,   -25,    57,   102,   -25,    57,    55,    76,    85,
      87,   -25,     8,   -25,   -25,    88,    89,    32,    -4,    92,
     -25,    10,    57,   -25,    42,     3,   -25,    34,   -25,   -25,
     -25,    44,   -25,    44,    44,   -25,   -25,    93,    59,   -25,
      57,    42,    91,    51,   -25,    77,    77,    77,    86,    42,
      42,    94,   -25,   -25,   102,   -25,    59,    59,     3,    61,
      98,    69,   -25,     9,   -25,   100,   -25,   102,    78,   -25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -25,   115,   -25,   -25,   -25,   -24,   -25,    53,
     -25,   -25,    79,   -25,    62,   -14,   101,    -8,    26,   -25,
     -25,   -17,     6
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -13
static const yytype_int8 yytable[] =
{
      32,    17,    23,    10,    26,    51,     9,     2,     3,    28,
      42,     9,     2,     3,    29,    30,    31,    27,    22,    86,
      11,    53,    54,    22,     1,     2,     3,    60,    46,    13,
      27,    63,    55,    14,    42,    28,    42,    42,     2,     3,
      29,    30,    31,    65,    60,    66,    67,     2,     3,    22,
      79,    20,    60,    60,   -12,    21,    50,    22,    56,    22,
      64,    83,    28,    88,    81,     2,     3,    29,    30,    31,
      22,    39,    69,    70,    21,    73,    22,    40,    27,    28,
      15,    84,     2,     3,    29,    30,    31,    28,    53,    54,
       2,     3,    21,    22,    31,    76,    77,    22,    89,    24,
      43,    22,    44,    28,    45,    74,     2,     3,    29,    30,
      31,    68,    48,    49,    52,    72,    85,    22,    78,    87,
      12,    75,    25,    71,    62
};

static const yytype_uint8 yycheck[] =
{
      24,    15,    19,    15,    21,     9,     0,     4,     5,     1,
      27,     5,     4,     5,     6,     7,     8,    21,    15,    10,
       0,    11,    12,    15,     3,     4,     5,    44,    20,    15,
      21,    45,    22,    16,    51,     1,    53,    54,     4,     5,
       6,     7,     8,    51,    61,    53,    54,     4,     5,    15,
      74,    18,    69,    70,    20,    23,    24,    15,    16,    15,
      16,    78,     1,    87,    78,     4,     5,     6,     7,     8,
      15,    16,    13,    14,    23,    24,    15,    22,    21,     1,
      17,    20,     4,     5,     6,     7,     8,     1,    11,    12,
       4,     5,    23,    15,     8,    69,    70,    15,    20,    19,
      24,    15,    17,     1,    17,    19,     4,     5,     6,     7,
       8,    18,    24,    24,    22,    24,    18,    15,    24,    19,
       5,    68,    21,    61,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    26,    27,    28,    29,    30,    47,
      15,     0,    28,    15,    16,    17,    31,    40,    41,    47,
      18,    23,    15,    46,    19,    41,    46,    21,     1,     6,
       7,     8,    32,    33,    34,    37,    38,    40,    46,    16,
      22,    42,    46,    24,    17,    17,    20,    32,    24,    24,
      24,     9,    22,    11,    12,    22,    16,    39,    43,    45,
      46,    35,    37,    40,    16,    42,    42,    42,    18,    13,
      14,    39,    24,    24,    19,    34,    43,    43,    24,    32,
      36,    40,    44,    46,    20,    18,    10,    19,    32,    20
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 63 "project3.y"
    {
						// initialize tree
						head = (yyvsp[(1) - (1)].node);
					}
    break;

  case 3:
#line 71 "project3.y"
    {
						(yyval.node) = MakeNode("c_code");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 4:
#line 77 "project3.y"
    {
						(yyval.node) = MakeNode("c_code");
						InsertChild((yyval.node), (yyvsp[(1) - (2)].node));
						InsertSibling((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
					}
    break;

  case 5:
#line 85 "project3.y"
    {
						(yyval.node) = MakeNode("code");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 6:
#line 90 "project3.y"
    {
						(yyval.node) = MakeNode("code");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 7:
#line 98 "project3.y"
    {
						(yyval.node) = MakeNode("define_header");

						char* defS = strdup("DEFINE: ");
						char* idS = strdup("ID: ");
						char* numS = strdup("NUM: ");

						strcat(defS, (yyvsp[(1) - (3)].string));
						strcat(idS, (yyvsp[(2) - (3)].string));
						strcat(numS, (yyvsp[(3) - (3)].string));

						NODE* defN = MakeNode(defS);
						NODE* idN = MakeNode(idS);
						NODE* numN = MakeNode(numS);

						InsertChild((yyval.node), defN);
						InsertSibling(defN, idN);
						InsertSibling(idN, numN);

						free(defS);
						free(idS);
						free(numS);
					}
    break;

  case 8:
#line 125 "project3.y"
    {
						(yyval.node) = MakeNode("func_def");

						char* idS = strdup("ID: ");
						char* lparenS = strdup("LPAREN: ");
						char* rparenS = strdup("RPAREN: ");
						char* lbraceS = strdup("LBRACE: ");
						char* rbraceS = strdup("RBRACE: ");

						strcat(idS, (yyvsp[(2) - (8)].string));
						strcat(lparenS, (yyvsp[(3) - (8)].string));
						strcat(rparenS, (yyvsp[(5) - (8)].string));
						strcat(lbraceS, (yyvsp[(6) - (8)].string));
						strcat(rbraceS, (yyvsp[(8) - (8)].string));

						NODE* idN = MakeNode(idS);
						NODE* lparenN = MakeNode(lparenS);
						NODE* rparenN = MakeNode(rparenS);
						NODE* lbraceN = MakeNode(lbraceS);
						NODE* rbraceN = MakeNode(rbraceS);

						InsertChild((yyval.node), (yyvsp[(1) - (8)].node));
						InsertSibling((yyvsp[(1) - (8)].node), idN);
						InsertSibling(idN, lparenN);
						InsertSibling(lparenN, (yyvsp[(4) - (8)].node));
						InsertSibling((yyvsp[(4) - (8)].node), rparenN);
						InsertSibling(rparenN, lbraceN);
						InsertSibling(lbraceN, (yyvsp[(7) - (8)].node));
						InsertSibling((yyvsp[(7) - (8)].node), rbraceN);

						free(idS);
						free(lparenS);
						free(rparenS);
						free(lbraceS);
						free(rbraceS);
					}
    break;

  case 9:
#line 165 "project3.y"
    {
						(yyval.node) = MakeNode("func_arg_dec");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 10:
#line 173 "project3.y"
    {
						(yyval.node) = MakeNode("body");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 11:
#line 178 "project3.y"
    {
						(yyval.node) = MakeNode("body");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 12:
#line 183 "project3.y"
    {
						(yyval.node) = MakeNode("body");
						InsertChild((yyval.node), (yyvsp[(1) - (2)].node));
						InsertSibling((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
					}
    break;

  case 13:
#line 192 "project3.y"
    {
						(yyval.node) = MakeNode("clause");

						char* forS = strdup("FOR: ");
						char* semicolonS = strdup("SEMICOLON: ");
						char* lparenS = strdup("LPAREN: ");
						char* rparenS = strdup("RPAREN: ");
						char* lbraceS = strdup("LBRACE: ");
						char* rbraceS = strdup("RBRACE: ");

						strcat(forS, (yyvsp[(1) - (10)].string));
						strcat(semicolonS, (yyvsp[(5) - (10)].string));
						strcat(lparenS, (yyvsp[(2) - (10)].string));
						strcat(rparenS, (yyvsp[(7) - (10)].string));
						strcat(lbraceS, (yyvsp[(8) - (10)].string));
						strcat(rbraceS, (yyvsp[(10) - (10)].string));

						NODE* forN = MakeNode(forS);
						NODE* semicolonN = MakeNode(semicolonS);
						NODE* lparenN = MakeNode(lparenS);
						NODE* rparenN = MakeNode(rparenS);
						NODE* lbraceN = MakeNode(lbraceS);
						NODE* rbraceN = MakeNode(rbraceS);

						InsertChild((yyval.node), forN);
						InsertSibling(forN, lparenN);
						InsertSibling(lparenN, (yyvsp[(3) - (10)].node));
						InsertSibling((yyvsp[(3) - (10)].node), (yyvsp[(4) - (10)].node));
						InsertSibling((yyvsp[(4) - (10)].node), semicolonN);
						InsertSibling(semicolonN, (yyvsp[(6) - (10)].node));
						InsertSibling((yyvsp[(6) - (10)].node), rparenN);
						InsertSibling(rparenN, lbraceN);
						InsertSibling(lbraceN, (yyvsp[(9) - (10)].node));
						InsertSibling((yyvsp[(9) - (10)].node), rbraceN);

						free(forS);
						free(semicolonS);
						free(lparenS);
						free(rparenS);
						free(lbraceS);
						free(rbraceS);
					}
    break;

  case 14:
#line 236 "project3.y"
    {
						(yyval.node) = MakeNode("clause");

						char* ifS = strdup("IF: ");
						char* lparenS = strdup("LPAREN: ");
						char* rparenS = strdup("RPAREN: ");
						char* lbraceS = strdup("LBRACE: ");
						char* rbraceS = strdup("RBRACE: ");

						strcat(ifS, (yyvsp[(1) - (7)].string));
						strcat(lparenS, (yyvsp[(2) - (7)].string));
						strcat(rparenS, (yyvsp[(4) - (7)].string));
						strcat(lbraceS, (yyvsp[(5) - (7)].string));
						strcat(rbraceS, (yyvsp[(7) - (7)].string));

						NODE* ifN = MakeNode(ifS);
						NODE* lparenN = MakeNode(lparenS);
						NODE* rparenN = MakeNode(rparenS);
						NODE* lbraceN = MakeNode(lbraceS);
						NODE* rbraceN = MakeNode(rbraceS);

						InsertChild((yyval.node), ifN);
						InsertSibling(ifN, lparenN);
						InsertSibling(lparenN, (yyvsp[(3) - (7)].node));
						InsertSibling((yyvsp[(3) - (7)].node), rparenN);
						InsertSibling(rparenN, lbraceN);
						InsertSibling(lbraceN, (yyvsp[(6) - (7)].node));
						InsertSibling((yyvsp[(6) - (7)].node), rbraceN);

						free(ifS);
						free(lparenS);
						free(rparenS);
						free(lbraceS);
						free(rbraceS);
					}
    break;

  case 15:
#line 273 "project3.y"
    {
						(yyval.node) = MakeNode("clause");

						char* ifS = strdup("IF: ");
						char* lparenS = strdup("LPAREN: ");
						char* rparenS = strdup("RPAREN: ");

						strcat(ifS, (yyvsp[(1) - (5)].string));
						strcat(lparenS, (yyvsp[(2) - (5)].string));
						strcat(rparenS, (yyvsp[(4) - (5)].string));

						NODE* ifN = MakeNode(ifS);
						NODE* lparenN = MakeNode(lparenS);
						NODE* rparenN = MakeNode(rparenS);

						InsertChild((yyval.node), ifN);
						InsertSibling(ifN, lparenN);
						InsertSibling(lparenN, (yyvsp[(3) - (5)].node));
						InsertSibling((yyvsp[(3) - (5)].node), rparenN);
						InsertSibling(rparenN, (yyvsp[(5) - (5)].node));

						free(ifS);
						free(lparenS);
						free(rparenS);
					}
    break;

  case 16:
#line 302 "project3.y"
    {
						(yyval.node) = MakeNode("statement");

						char* semicolonS = strdup("SEMICOLON: ");

						strcat(semicolonS, (yyvsp[(2) - (2)].string));

						NODE* semicolonN = MakeNode(semicolonS);

						InsertChild((yyval.node), (yyvsp[(1) - (2)].node));
						InsertSibling((yyvsp[(1) - (2)].node), semicolonN);

						free(semicolonS);
					}
    break;

  case 17:
#line 318 "project3.y"
    {
						(yyval.node) = MakeNode("statement");

						char* semicolonS = strdup("SEMICOLON: ");

						strcat(semicolonS, (yyvsp[(2) - (2)].string));

						NODE* semicolonN = MakeNode(semicolonS);

						InsertChild((yyval.node), (yyvsp[(1) - (2)].node));
						InsertSibling((yyvsp[(1) - (2)].node), semicolonN);

						free(semicolonS);
					}
    break;

  case 18:
#line 334 "project3.y"
    {
						(yyval.node) = MakeNode("statement");

						char* semicolonS = strdup("SEMICOLON: ");

						strcat(semicolonS, (yyvsp[(2) - (2)].string));

						NODE* semicolonN = MakeNode(semicolonS);

						InsertChild((yyval.node), (yyvsp[(1) - (2)].node));
						InsertSibling((yyvsp[(1) - (2)].node), semicolonN);

						free(semicolonS);
					}
    break;

  case 20:
#line 355 "project3.y"
    {
						(yyval.node) = MakeNode("init_stmt");

						char* semicolonS = strdup("SEMICOLON: ");

						strcat(semicolonS, (yyvsp[(2) - (2)].string));

						NODE* semicolonN = MakeNode(semicolonS);

						InsertChild((yyval.node), (yyvsp[(1) - (2)].node));
						InsertSibling((yyvsp[(1) - (2)].node), semicolonN);

						free(semicolonS);
					}
    break;

  case 21:
#line 371 "project3.y"
    {
						(yyval.node) = MakeNode("init_stmt");

						char* semicolonS = strdup("SEMICOLON: ");

						strcat(semicolonS, (yyvsp[(2) - (2)].string));

						NODE* semicolonN = MakeNode(semicolonS);

						InsertChild((yyval.node), (yyvsp[(1) - (2)].node));
						InsertSibling((yyvsp[(1) - (2)].node), semicolonN);

						free(semicolonS);
					}
    break;

  case 22:
#line 389 "project3.y"
    {
						(yyval.node) = MakeNode("update_stmt");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 23:
#line 394 "project3.y"
    {
						(yyval.node) = MakeNode("update_stmt");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 24:
#line 402 "project3.y"
    {
						(yyval.node) = MakeNode("assign_stmt");

						char* op_assignS = strdup("OP_ASSIGN: ");

						strcat(op_assignS, (yyvsp[(2) - (3)].string));

						NODE* op_assignN = MakeNode(op_assignS);

						InsertChild((yyval.node), (yyvsp[(1) - (3)].node));
						InsertSibling((yyvsp[(1) - (3)].node), op_assignN);
						InsertSibling(op_assignN, (yyvsp[(3) - (3)].node));

						free(op_assignS);	
					}
    break;

  case 25:
#line 421 "project3.y"
    {
						(yyval.node) = MakeNode("continue_stmt");

						char* continueS = strdup("CONTINUE: ");

						strcat(continueS, (yyvsp[(1) - (1)].string));

						NODE* continueN = MakeNode(continueS);

						InsertChild((yyval.node), continueN);

						free(continueS);	
					}
    break;

  case 26:
#line 458 "project3.y"
    {
						(yyval.node) = MakeNode("test_expr");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 27:
#line 466 "project3.y"
    {
						(yyval.node) = MakeNode("decl_list");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 28:
#line 472 "project3.y"
    {
						(yyval.node) = MakeNode("decl_list");

						char* commaS = strdup("COMMA: ");

						strcat(commaS, (yyvsp[(2) - (3)].string));

						NODE* commaN = MakeNode(commaS);

						InsertChild((yyval.node), (yyvsp[(1) - (3)].node));
						InsertSibling((yyvsp[(1) - (3)].node), commaN);
						InsertSibling(commaN, (yyvsp[(3) - (3)].node));

						free(commaS);	
					}
    break;

  case 29:
#line 489 "project3.y"
    {
						(yyval.node) = MakeNode("decl_list");

						char* commaS = strdup("COMMA: ");

						strcat(commaS, (yyvsp[(2) - (3)].string));

						NODE* commaN = MakeNode(commaS);

						InsertChild((yyval.node), (yyvsp[(1) - (3)].node));
						InsertSibling((yyvsp[(1) - (3)].node), commaN);
						InsertSibling(commaN, (yyvsp[(3) - (3)].node));

						free(commaS);	
					}
    break;

  case 30:
#line 508 "project3.y"
    {
						(yyval.node) = MakeNode("decl_init");
						InsertChild((yyval.node), (yyvsp[(1) - (2)].node));
						InsertSibling((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
					}
    break;

  case 31:
#line 517 "project3.y"
    {
						(yyval.node) = MakeNode("al_expr");

						char* numS = strdup("NUM: ");

						strcat(numS, (yyvsp[(1) - (1)].string));

						NODE* numN = MakeNode(numS);

						InsertChild((yyval.node), numN);

						free(numS);	
					}
    break;

  case 32:
#line 532 "project3.y"
    {
						(yyval.node) = MakeNode("al_expr");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 33:
#line 538 "project3.y"
    {
						(yyval.node) = MakeNode("al_expr");

						char* op_addS = strdup("OP_ADD: ");

						strcat(op_addS, (yyvsp[(2) - (3)].string));

						NODE* op_addN = MakeNode(op_addS);

						InsertChild((yyval.node), (yyvsp[(1) - (3)].node));
						InsertSibling((yyvsp[(1) - (3)].node), op_addN);
						InsertSibling(op_addN, (yyvsp[(3) - (3)].node));

						free(op_addS);	
					}
    break;

  case 34:
#line 555 "project3.y"
    {
						(yyval.node) = MakeNode("al_expr");

						char* op_mulS = strdup("OP_MUL: ");

						strcat(op_mulS, (yyvsp[(2) - (3)].string));

						NODE* op_mulN = MakeNode(op_mulS);

						InsertChild((yyval.node), (yyvsp[(1) - (3)].node));
						InsertSibling((yyvsp[(1) - (3)].node), op_mulN);
						InsertSibling(op_mulN, (yyvsp[(3) - (3)].node));

						free(op_mulS);	
						}
    break;

  case 35:
#line 574 "project3.y"
    {
						(yyval.node) = MakeNode("rel_expr");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 36:
#line 580 "project3.y"
    {
						(yyval.node) = MakeNode("rel_expr");

						char* op_relS = strdup("OP_REL: ");

						strcat(op_relS, (yyvsp[(2) - (3)].string));

						NODE* op_relN = MakeNode(op_relS);

						InsertChild((yyval.node), (yyvsp[(1) - (3)].node));
						InsertSibling((yyvsp[(1) - (3)].node), op_relN);
						InsertSibling(op_relN, (yyvsp[(3) - (3)].node));

						free(op_relS);
					}
    break;

  case 37:
#line 597 "project3.y"
    {
						(yyval.node) = MakeNode("rel_expr");

						char* op_logicS = strdup("OP_LOGIC: ");

						strcat(op_logicS, (yyvsp[(2) - (3)].string));

						NODE* op_logicN = MakeNode(op_logicS);

						InsertChild((yyval.node), (yyvsp[(1) - (3)].node));
						InsertSibling((yyvsp[(1) - (3)].node), op_logicN);
						InsertSibling(op_logicN, (yyvsp[(3) - (3)].node));

						free(op_logicS);
					}
    break;

  case 38:
#line 616 "project3.y"
    {
						(yyval.node) = MakeNode("inc_expr");

						char* op_incS = strdup("OP_INC: ");

						strcat(op_incS, (yyvsp[(2) - (2)].string));

						NODE* op_incN = MakeNode(op_incS);

						InsertChild((yyval.node), (yyvsp[(1) - (2)].node));
						InsertSibling((yyvsp[(1) - (2)].node), op_incN);

						free(op_incS);
					}
    break;

  case 39:
#line 634 "project3.y"
    {
						(yyval.node) = MakeNode("value");
						InsertChild((yyval.node), (yyvsp[(1) - (1)].node));
					}
    break;

  case 40:
#line 640 "project3.y"
    {
						(yyval.node) = MakeNode("value");

						char* numS = strdup("NUM: ");

						strcat(numS, (yyvsp[(1) - (1)].string));

						NODE* numN = MakeNode(numS);

						InsertChild((yyval.node), numN);

						free(numS);	
					}
    break;

  case 41:
#line 657 "project3.y"
    {
						(yyval.node) = MakeNode("variable");

						char* idS = strdup("ID: ");

						strcat(idS, (yyvsp[(1) - (1)].string));

						NODE* idN = MakeNode(idS);

						InsertChild((yyval.node), idN);

						free(idS);
					}
    break;

  case 42:
#line 672 "project3.y"
    {
						(yyval.node) = MakeNode("variable");

						char* lbracketS = strdup("LBRACKET: ");
						char* rbracketS = strdup("RBRACKET: ");

						strcat(lbracketS, (yyvsp[(2) - (3)].string));
						strcat(rbracketS, (yyvsp[(3) - (3)].string));

						NODE* lbracketN = MakeNode(lbracketS);
						NODE* rbracketN = MakeNode(rbracketS);

						InsertChild((yyval.node), (yyvsp[(1) - (3)].node));
						InsertSibling((yyvsp[(1) - (3)].node), lbracketN);
						InsertSibling(lbracketN, rbracketN);

						free(lbracketS);
						free(rbracketS);
					}
    break;

  case 43:
#line 693 "project3.y"
    {
						(yyval.node) = MakeNode("variable");

						char* numS = strdup("NUM: ");
						char* lbracketS = strdup("LBRACKET: ");
						char* rbracketS = strdup("RBRACKET: ");

						strcat(numS, (yyvsp[(3) - (4)].string));
						strcat(lbracketS, (yyvsp[(2) - (4)].string));
						strcat(rbracketS, (yyvsp[(4) - (4)].string));

						NODE* numN = MakeNode(numS);
						NODE* lbracketN = MakeNode(lbracketS);
						NODE* rbracketN = MakeNode(rbracketS);

						InsertChild((yyval.node), (yyvsp[(1) - (4)].node));
						InsertSibling((yyvsp[(1) - (4)].node), lbracketN);
						InsertSibling(lbracketN, numN);
						InsertSibling(numN, rbracketN);

						free(numS);
						free(lbracketS);
						free(rbracketS);
					}
    break;

  case 44:
#line 719 "project3.y"
    {
						(yyval.node) = MakeNode("variable");

						char* lbracketS = strdup("LBRACKET: ");
						char* rbracketS = strdup("RBRACKET: ");

						strcat(lbracketS, (yyvsp[(2) - (4)].string));
						strcat(rbracketS, (yyvsp[(4) - (4)].string));

						NODE* lbracketN = MakeNode(lbracketS);
						NODE* rbracketN = MakeNode(rbracketS);

						InsertChild((yyval.node), (yyvsp[(1) - (4)].node));
						InsertSibling((yyvsp[(1) - (4)].node), lbracketN);
						InsertSibling(lbracketN, (yyvsp[(3) - (4)].node));
						InsertSibling((yyvsp[(3) - (4)].node), rbracketN);

						free(lbracketS);
						free(rbracketS);
					}
    break;

  case 45:
#line 743 "project3.y"
    {
						(yyval.node) = MakeNode("type");

						char* voidS = strdup("VOID: ");

						strcat(voidS, (yyvsp[(1) - (1)].string));

						NODE* voidN = MakeNode(voidS);

						InsertChild((yyval.node), voidN);

						free(voidS);
					}
    break;

  case 46:
#line 757 "project3.y"
    {
						(yyval.node) = MakeNode("type");

						char* intS = strdup("INT: ");

						strcat(intS, (yyvsp[(1) - (1)].string));

						NODE* intN = MakeNode(intS);

						InsertChild((yyval.node), intN);

						free(intS);
					}
    break;


/* Line 1267 of yacc.c.  */
#line 2207 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 772 "project3.y"


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

