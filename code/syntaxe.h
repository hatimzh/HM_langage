
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     IMPORT = 258,
     BIBLIO_NAMES = 259,
     NOT = 260,
     AND = 261,
     OR = 262,
     INCREMENT_SIGN = 263,
     DECREMENT_SIGN = 264,
     EQUALITY = 265,
     DIFFERENT = 266,
     LOWER_EQUAL = 267,
     GREATER_EQUAL = 268,
     VAR = 269,
     FUNCTION = 270,
     RETURN = 271,
     IF = 272,
     ELSEIF = 273,
     ELSE = 274,
     SWITCH = 275,
     CASE = 276,
     OTHERS = 277,
     FOR = 278,
     IN = 279,
     DO = 280,
     WHILE = 281,
     PRINT = 282,
     SCAN = 283,
     VARIABLE_TYPE = 284,
     VARIABLE_NAME = 285,
     BOOLEAN = 286,
     NUMBER = 287,
     STRING = 288,
     COMMENT = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 62 "syntaxe.y"

	int type;
	int bval;
	float nval;
	char *sval;



/* Line 1676 of yacc.c  */
#line 95 "syntaxe.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


