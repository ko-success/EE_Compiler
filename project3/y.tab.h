/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "project3.y"
{
	int number;
	char *string;
	NODE *node;
}
/* Line 1529 of yacc.c.  */
#line 103 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

