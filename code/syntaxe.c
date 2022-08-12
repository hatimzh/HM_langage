
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntaxe.y"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern FILE* yyin;
int lineNumber;
int typeReturn;
FILE *file;

#define L 50
#define M 50
#define N 101

typedef union val{
	int b;
	float n;
	char *s;
} val;

typedef struct var{
	char *name;
	int type;
	val value;
	struct var *next;
} variable;

typedef struct f{
	char *name;
	int type;
	struct f *next;
} function;

function *functions[L];
variable *constants[M];
variable *variables[N];

int yylex(void);
void yyerror(const char *msg);
int hash(char *name);
variable* findVariable(char *name);
variable* findConstant(char *name);
function* findFunction(char *name);
int isVariableDeclared(char *name);
int isConstantDeclared(char *name);
int isFunctionDeclared(char *name);
variable* newDeclaredVariable(char *name, int type, variable *next);
variable* newConstant(char *name, int type, variable *next);
function* newFunction(char *name, int type, function *next);
void insertNewDeclaredVariable(char *name, int type);
void insertNewConstant(char *name, int type);
void insertNewFunction(char *name, int type);
int getType(char *name);
char* toCType(int type);
char* toCShortType(char *name);
char* toCPrint(char *string);
void listdeclation(char *s1, char *s2, char *del);
FILE* createfile();



/* Line 189 of yacc.c  */
#line 135 "syntaxe.c"

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

/* Line 214 of yacc.c  */
#line 62 "syntaxe.y"

	int type;
	int bval;
	float nval;
	char *sval;



/* Line 214 of yacc.c  */
#line 214 "syntaxe.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 226 "syntaxe.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNRULES -- Number of states.  */
#define YYNSTATES  215

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    47,     2,    36,
      37,    38,    48,    46,    41,    42,    50,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      44,    43,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    12,    16,    19,    20,
      24,    27,    31,    33,    36,    40,    42,    43,    44,    55,
      56,    57,    72,    73,    78,    80,    81,    84,    86,    88,
      90,    91,    94,    97,    99,   101,   103,   105,   107,   109,
     113,   116,   119,   121,   122,   129,   132,   134,   135,   142,
     143,   149,   150,   151,   163,   165,   167,   168,   177,   178,
     185,   188,   190,   192,   194,   196,   198,   200,   203,   209,
     215,   217,   224,   233,   238,   242,   246,   250,   252,   256,
     259,   261,   263,   265,   267,   271,   275,   279,   283,   287,
     291,   295,   299,   303,   305,   309,   313,   315,   319,   322,
     324,   326,   328,   330,   335,   339,   341,   342,   346,   350,
     352,   354,   356,   358
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    -1,    53,    54,    -1,    56,    67,    -1,
      67,    -1,    55,    56,    67,    -1,    55,    67,    -1,    -1,
       3,     4,    35,    -1,    56,    58,    -1,    56,    57,    58,
      -1,    58,    -1,    57,    58,    -1,    57,    36,    34,    -1,
      34,    -1,    -1,    -1,    15,    30,    37,    59,    63,    38,
      39,    60,    69,    40,    -1,    -1,    -1,    29,    15,    30,
      37,    61,    63,    38,    39,    62,    69,    16,    66,    35,
      40,    -1,    -1,    63,    41,    64,    65,    -1,    65,    -1,
      -1,    29,    30,    -1,    99,    -1,    95,    -1,   105,    -1,
      -1,    68,    69,    -1,    69,    70,    -1,    70,    -1,    71,
      -1,    79,    -1,    85,    -1,    83,    -1,    87,    -1,    72,
      74,    77,    -1,    72,    77,    -1,    72,    74,    -1,    72,
      -1,    -1,    17,    94,    39,    73,    69,    40,    -1,    74,
      75,    -1,    75,    -1,    -1,    18,    94,    39,    76,    69,
      40,    -1,    -1,    19,    39,    78,    69,    40,    -1,    -1,
      -1,    23,    30,    24,    82,    80,    42,    82,    39,    81,
      69,    40,    -1,    32,    -1,    30,    -1,    -1,    25,    39,
      84,    69,    40,    26,    94,    35,    -1,    -1,    26,    94,
      39,    86,    69,    40,    -1,    87,    88,    -1,    88,    -1,
      92,    -1,    93,    -1,    90,    -1,    89,    -1,    57,    -1,
     103,    35,    -1,    27,    37,    33,    38,    35,    -1,    28,
      37,    91,    38,    35,    -1,    30,    -1,    14,    30,    37,
      29,    38,    35,    -1,    14,    30,    37,    29,    38,    43,
     106,    35,    -1,    30,    43,   106,    35,    -1,    37,    95,
      38,    -1,    95,     6,    96,    -1,    95,     7,    96,    -1,
      96,    -1,    37,    95,    38,    -1,     5,    96,    -1,    97,
      -1,    98,    -1,    31,    -1,    30,    -1,    99,    10,    99,
      -1,    99,    11,    99,    -1,    99,    44,    99,    -1,    99,
      45,    99,    -1,    99,    12,    99,    -1,    99,    13,    99,
      -1,    99,    46,   100,    -1,    99,    42,   100,    -1,    99,
      47,   100,    -1,   100,    -1,   100,    48,   101,    -1,   100,
      49,   101,    -1,   101,    -1,    37,    99,    38,    -1,    42,
     101,    -1,   102,    -1,    32,    -1,    30,    -1,   103,    -1,
      30,    37,   104,    38,    -1,   104,    41,   106,    -1,   106,
      -1,    -1,   105,    50,    33,    -1,   105,    50,    30,    -1,
      33,    -1,    30,    -1,   105,    -1,    99,    -1,    95,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    89,    92,    93,    94,    95,    96,    99,
     102,   103,   104,   105,   108,   109,   112,   112,   112,   113,
     113,   113,   116,   116,   117,   118,   121,   124,   125,   126,
     129,   129,   132,   133,   136,   137,   138,   139,   140,   143,
     144,   145,   146,   149,   149,   152,   153,   156,   156,   159,
     159,   162,   162,   162,   165,   166,   169,   169,   172,   172,
     175,   176,   179,   180,   181,   182,   183,   184,   187,   189,
     207,   210,   228,   250,   264,   267,   268,   269,   272,   273,
     274,   277,   278,   279,   282,   283,   284,   285,   286,   287,
     290,   291,   292,   293,   297,   298,   299,   303,   304,   305,
     308,   309,   310,   313,   316,   317,   318,   321,   322,   323,
     324,   327,   328,   329
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IMPORT", "BIBLIO_NAMES", "NOT", "AND",
  "OR", "INCREMENT_SIGN", "DECREMENT_SIGN", "EQUALITY", "DIFFERENT",
  "LOWER_EQUAL", "GREATER_EQUAL", "VAR", "FUNCTION", "RETURN", "IF",
  "ELSEIF", "ELSE", "SWITCH", "CASE", "OTHERS", "FOR", "IN", "DO", "WHILE",
  "PRINT", "SCAN", "VARIABLE_TYPE", "VARIABLE_NAME", "BOOLEAN", "NUMBER",
  "STRING", "COMMENT", "';'", "'\\''", "'('", "')'", "'{'", "'}'", "','",
  "'-'", "'='", "'<'", "'>'", "'+'", "'%'", "'*'", "'/'", "'.'", "$accept",
  "program", "$@1", "code", "import", "functionList", "listComment",
  "function", "$@2", "$@3", "$@4", "$@5", "functionArgumentList", "$@6",
  "functionArgument", "functionTypes", "mainProgram", "$@7",
  "statementList", "statement", "ifStatement", "ifClause", "$@8",
  "elseIfClauses", "elseIfClause", "$@9", "elseClause", "$@10",
  "forStatement", "$@11", "$@12", "forTypes", "doWhileStatement", "$@13",
  "whileStatement", "$@14", "listInstruction", "instruction", "print",
  "scan", "scanType", "declaration", "assignment", "condition",
  "logicalExpression", "logicalTerm", "logicalTypes",
  "comparisionExpression", "arithmiticExpression", "arithmiticTerm",
  "arithmiticFactor", "arithmiticTypes", "calledFunction", "arguments",
  "concatenation", "types", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,    59,    39,    40,    41,   123,
     125,    44,    45,    61,    60,    62,    43,    37,    42,    47,
      46
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    53,    52,    54,    54,    54,    54,    54,    55,
      56,    56,    56,    56,    57,    57,    59,    60,    58,    61,
      62,    58,    64,    63,    63,    63,    65,    66,    66,    66,
      68,    67,    69,    69,    70,    70,    70,    70,    70,    71,
      71,    71,    71,    73,    72,    74,    74,    76,    75,    78,
      77,    80,    81,    79,    82,    82,    84,    83,    86,    85,
      87,    87,    88,    88,    88,    88,    88,    88,    89,    90,
      91,    92,    92,    93,    94,    95,    95,    95,    96,    96,
      96,    97,    97,    97,    98,    98,    98,    98,    98,    98,
      99,    99,    99,    99,   100,   100,   100,   101,   101,   101,
     102,   102,   102,   103,   104,   104,   104,   105,   105,   105,
     105,   106,   106,   106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     3,     2,     0,     3,
       2,     3,     1,     2,     3,     1,     0,     0,    10,     0,
       0,    14,     0,     4,     1,     0,     2,     1,     1,     1,
       0,     2,     2,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     1,     0,     6,     2,     1,     0,     6,     0,
       5,     0,     0,    11,     1,     1,     0,     8,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     2,     5,     5,
       1,     6,     8,     4,     3,     3,     3,     1,     3,     2,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     2,     1,
       1,     1,     1,     4,     3,     1,     0,     3,     3,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    30,     1,     0,     0,     0,    15,     3,    30,
      30,     0,    12,     5,     0,     0,     0,     0,    30,     7,
       0,    10,     4,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    31,    33,    34,    42,    35,    37,
      36,    38,    61,    65,    64,    62,    63,     0,     9,    16,
       0,     6,    11,    14,     0,     0,     0,     0,    56,     0,
       0,     0,   106,     0,    32,     0,     0,    41,    46,    40,
      60,    67,    25,    19,     0,     0,   101,    82,   100,     0,
       0,     0,    77,    80,    81,     0,    93,    96,    99,   102,
      43,     0,     0,    58,     0,    70,     0,   101,   109,   113,
     112,     0,   111,   105,     0,     0,    49,    45,    39,     0,
       0,    24,    25,     0,    79,     0,     0,   101,     0,    98,
       0,     0,    74,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    54,    51,     0,     0,
       0,     0,   103,     0,     0,    73,    47,     0,    26,     0,
      22,     0,     0,    78,    97,     0,    75,    76,    84,    85,
      88,    89,    91,    86,    87,    90,    92,    94,    95,     0,
       0,     0,     0,    68,    69,   104,   108,   107,     0,     0,
      17,     0,     0,    71,     0,    44,     0,     0,    59,     0,
      50,     0,    23,    20,     0,     0,     0,    48,     0,     0,
      72,    52,    57,    18,     0,     0,     0,     0,     0,    28,
      27,    29,    53,     0,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    10,    33,    12,    72,   191,
     112,   199,   110,   181,   111,   208,    13,    14,    34,    35,
      36,    37,   134,    67,    68,   178,    69,   147,    38,   170,
     205,   137,    39,    92,    40,   139,    41,    42,    43,    44,
      96,    45,    46,    56,    99,    82,    83,    84,    85,    86,
      87,    88,    89,   101,   102,   103
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -85
static const yytype_int16 yypact[] =
{
     -85,    19,   134,   -85,    24,    -7,    18,   -85,   -85,     2,
       2,     1,   -85,   -85,   311,     5,    27,    13,     2,   -85,
       1,   -85,   -85,    35,   -85,    47,    52,    88,    36,    52,
     110,   120,    10,    86,   311,   -85,   -85,    90,   -85,   -85,
     -85,    89,   -85,   -85,   -85,   -85,   -85,   138,   -85,   -85,
     137,   -85,   -85,   -85,   143,   108,   149,   176,   -85,   166,
     175,   181,    69,    69,   -85,    52,   177,    90,   -85,   -85,
     -85,   -85,   189,   -85,   191,   108,    45,   -85,   -85,   108,
      -8,     6,   -85,   -85,   -85,    85,    87,   -85,   -85,   -85,
     -85,   157,   311,   -85,   185,   -85,   186,     4,   -85,   136,
      85,    -6,   179,   -85,   190,   195,   -85,   -85,   -85,   196,
      38,   -85,   189,   198,   -85,     8,    46,   201,    -8,   -85,
     108,   108,   -85,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,   311,   -85,   -85,   -85,   169,   311,
     206,   207,   -85,    69,   126,   -85,   -85,   311,   -85,   204,
     -85,   128,   -17,   -85,   -85,   160,   -85,   -85,   125,   125,
     125,   125,    87,   125,   125,    87,    87,   -85,   -85,   187,
     202,   221,   205,   -85,   -85,   -85,   -85,   -85,   311,   223,
     -85,   189,   213,   -85,    69,   -85,   157,    52,   -85,   241,
     -85,   311,   -85,   -85,   219,   217,   224,   -85,   259,   311,
     -85,   -85,   -85,   -85,   296,   311,    69,   277,   225,   136,
      85,   179,   -85,   222,   -85
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   -85,   -85,   -85,   -85,   252,   144,    94,   -85,   -85,
     -85,   -85,   153,   -85,    91,   -85,    63,   -85,   -84,   -28,
     -85,   -85,   -85,   -85,   203,   -85,   210,   -85,   -85,   -85,
     -85,    92,   -85,   -85,   -85,   -85,   -85,   233,   -85,   -85,
     -85,   -85,   -85,   -27,   -54,   -72,   -85,   -85,   -58,    51,
     -71,   -85,   -14,   -85,    73,   -56
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -111
static const yytype_int16 yytable[] =
{
      47,    81,    59,   114,   100,   100,    64,   104,   138,   119,
     -83,   -83,   120,   121,   120,   121,     5,     5,   183,     3,
      47,   116,   117,    16,    78,   115,   184,    47,    15,   118,
       6,     6,   142,    17,    80,   143,     7,    23,   105,   -83,
      48,    62,   -83,    50,   122,   -83,   153,    62,   156,   157,
     169,   -83,   -83,    63,  -110,   172,   123,   124,   125,   126,
     155,   167,   168,   179,    49,   158,   159,   160,   161,    53,
     163,   164,    19,    22,    75,    58,   149,    54,    47,   150,
     -83,    51,    62,   -83,   154,   100,   -83,   175,   127,    55,
     128,   129,   130,   131,   189,   123,   124,   125,   126,    97,
      77,    78,    98,    25,    21,    24,    79,   198,    65,    66,
      64,    80,    21,    75,    52,   204,    30,    31,    57,    32,
      47,   207,    23,     7,    47,    47,   100,   127,   194,   128,
     129,   130,   131,    47,    -8,   132,   133,     4,    76,    77,
      78,    64,   120,   121,    64,    79,    11,    60,   210,     5,
      80,    64,   209,    11,    20,    47,   176,    61,    47,   177,
     196,    64,    20,     6,    47,    47,   182,   127,     7,   150,
      64,   130,   131,    71,    73,    47,    64,    47,   162,    64,
      74,   165,   166,    25,    47,    47,    26,   135,    90,   136,
      47,    47,    27,    47,    28,    29,    30,    31,   154,    32,
      91,    25,   127,     7,    26,    93,   130,   131,    94,   171,
      27,    95,    28,    29,    30,    31,   106,    32,   109,    25,
     113,     7,    26,   140,   141,   145,   148,   185,    27,   144,
      28,    29,    30,    31,   146,    32,   152,    25,    62,     7,
      26,   173,   174,   180,   186,   188,    27,   187,    28,    29,
      30,    31,   193,    32,   200,    25,   201,     7,    26,   202,
     213,    18,   214,   190,    27,   151,    28,    29,    30,    31,
     107,    32,   192,    25,    70,     7,    26,   108,   195,   211,
       0,   197,    27,     0,    28,    29,    30,    31,     0,    32,
       0,    25,     0,     7,    26,     0,     0,     0,     0,   203,
      27,     0,    28,    29,    30,    31,     0,    32,     0,     0,
      25,     7,   206,    26,     0,     0,     0,   212,     0,    27,
       0,    28,    29,    30,    31,    25,    32,     0,    26,     0,
       7,     0,     0,     0,    27,     0,    28,    29,    30,    31,
       0,    32,     0,     0,     0,     7
};

static const yytype_int16 yycheck[] =
{
      14,    55,    29,    75,    62,    63,    34,    63,    92,    80,
       6,     7,     6,     7,     6,     7,    15,    15,    35,     0,
      34,    79,    30,    30,    32,    79,    43,    41,     4,    37,
      29,    29,    38,    15,    42,    41,    34,    36,    65,    35,
      35,    37,    38,    30,    38,    41,    38,    37,   120,   121,
     134,     6,     7,    43,    50,   139,    10,    11,    12,    13,
     118,   132,   133,   147,    37,   123,   124,   125,   126,    34,
     128,   129,     9,    10,     5,    39,    38,    30,    92,    41,
      35,    18,    37,    38,    38,   143,    41,   143,    42,    37,
      44,    45,    46,    47,   178,    10,    11,    12,    13,    30,
      31,    32,    33,    14,    10,    11,    37,   191,    18,    19,
     138,    42,    18,     5,    20,   199,    27,    28,    30,    30,
     134,   205,    36,    34,   138,   139,   184,    42,   184,    44,
      45,    46,    47,   147,     0,    48,    49,     3,    30,    31,
      32,   169,     6,     7,   172,    37,     2,    37,   206,    15,
      42,   179,   206,     9,    10,   169,    30,    37,   172,    33,
     187,   189,    18,    29,   178,   179,    38,    42,    34,    41,
     198,    46,    47,    35,    37,   189,   204,   191,   127,   207,
      37,   130,   131,    14,   198,   199,    17,    30,    39,    32,
     204,   205,    23,   207,    25,    26,    27,    28,    38,    30,
      24,    14,    42,    34,    17,    39,    46,    47,    33,    40,
      23,    30,    25,    26,    27,    28,    39,    30,    29,    14,
      29,    34,    17,    38,    38,    35,    30,    40,    23,    50,
      25,    26,    27,    28,    39,    30,    38,    14,    37,    34,
      17,    35,    35,    39,    42,    40,    23,    26,    25,    26,
      27,    28,    39,    30,    35,    14,    39,    34,    17,    35,
      35,     9,    40,    40,    23,   112,    25,    26,    27,    28,
      67,    30,   181,    14,    41,    34,    17,    67,   186,   206,
      -1,    40,    23,    -1,    25,    26,    27,    28,    -1,    30,
      -1,    14,    -1,    34,    17,    -1,    -1,    -1,    -1,    40,
      23,    -1,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      14,    34,    16,    17,    -1,    -1,    -1,    40,    -1,    23,
      -1,    25,    26,    27,    28,    14,    30,    -1,    17,    -1,
      34,    -1,    -1,    -1,    23,    -1,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    -1,    34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,    53,     0,     3,    15,    29,    34,    54,    55,
      56,    57,    58,    67,    68,     4,    30,    15,    56,    67,
      57,    58,    67,    36,    58,    14,    17,    23,    25,    26,
      27,    28,    30,    57,    69,    70,    71,    72,    79,    83,
      85,    87,    88,    89,    90,    92,    93,   103,    35,    37,
      30,    67,    58,    34,    30,    37,    94,    30,    39,    94,
      37,    37,    37,    43,    70,    18,    19,    74,    75,    77,
      88,    35,    59,    37,    37,     5,    30,    31,    32,    37,
      42,    95,    96,    97,    98,    99,   100,   101,   102,   103,
      39,    24,    84,    39,    33,    30,    91,    30,    33,    95,
      99,   104,   105,   106,   106,    94,    39,    75,    77,    29,
      63,    65,    61,    29,    96,    95,    99,    30,    37,   101,
       6,     7,    38,    10,    11,    12,    13,    42,    44,    45,
      46,    47,    48,    49,    73,    30,    32,    82,    69,    86,
      38,    38,    38,    41,    50,    35,    39,    78,    30,    38,
      41,    63,    38,    38,    38,    99,    96,    96,    99,    99,
      99,    99,   100,    99,    99,   100,   100,   101,   101,    69,
      80,    40,    69,    35,    35,   106,    30,    33,    76,    69,
      39,    64,    38,    35,    43,    40,    42,    26,    40,    69,
      40,    60,    65,    39,   106,    82,    94,    40,    69,    62,
      35,    39,    35,    40,    69,    81,    16,    69,    66,    95,
      99,   105,    40,    35,    40
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 89 "syntaxe.y"
    {file = createfile();;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 89 "syntaxe.y"
    {fclose(file);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 96 "syntaxe.y"
    {fprintf(file,"int main(){ return 0;}");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 99 "syntaxe.y"
    {fprintf(file,"#include<%s.h>\n",(yyvsp[(2) - (3)].sval));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 112 "syntaxe.y"
    {if(isFunctionDeclared((yyvsp[(2) - (3)].sval))){ yyerror("Function already defined"); exit(-1);} insertNewFunction((yyvsp[(2) - (3)].sval), -1);fprintf(file, "void "); fprintf(file,"%s", (yyvsp[(2) - (3)].sval)); fprintf(file, "(");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 112 "syntaxe.y"
    {fprintf(file, "){\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 112 "syntaxe.y"
    {fprintf(file, "}\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 113 "syntaxe.y"
    {if(isFunctionDeclared((yyvsp[(3) - (4)].sval))){ yyerror("Function already defined"); exit(-1);} insertNewFunction((yyvsp[(3) - (4)].sval), (yyvsp[(1) - (4)].type)); switch((yyvsp[(1) - (4)].type)){ case 0 : {fprintf(file, "int ");break;} case 1 : {fprintf(file, "float ");break;} case 2 : {fprintf(file, "char *");break;} default : break;} fprintf(file,"%s", (yyvsp[(3) - (4)].sval)); fprintf(file, "(");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 113 "syntaxe.y"
    {fprintf(file, "){\n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 113 "syntaxe.y"
    {fprintf(file, "return "); fprintf(file, (yyvsp[(12) - (14)].sval)); fprintf(file, ";\n"); fprintf(file, "}\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 116 "syntaxe.y"
    {fprintf(file, ", ");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 118 "syntaxe.y"
    {;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 121 "syntaxe.y"
    {switch((yyvsp[(1) - (2)].type)){ case 0 : {fprintf(file, "int ");break;} case 1 : {fprintf(file, "float ");break;} case 2 : {fprintf(file, "char *");break;} default : break;} fprintf(file, " "); fprintf(file, (yyvsp[(2) - (2)].sval));;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 124 "syntaxe.y"
    {typeReturn = 1; (yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 125 "syntaxe.y"
    {typeReturn = 0; (yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 126 "syntaxe.y"
    {typeReturn = 2; (yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 129 "syntaxe.y"
    {fprintf(file,"\nint main(){\n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 129 "syntaxe.y"
    {fprintf(file,"printf(\" \\n\\nEnd of execution.\\nTape Enter to finish ...\\n\");getchar();getchar();\n}");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 149 "syntaxe.y"
    {fprintf(file,"if("); fprintf(file,(yyvsp[(2) - (3)].sval)); fprintf(file,"){\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 149 "syntaxe.y"
    {fprintf(file,"}\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 156 "syntaxe.y"
    {fprintf(file,"else if("); fprintf(file,(yyvsp[(2) - (3)].sval)); fprintf(file,"){\n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 156 "syntaxe.y"
    {fprintf(file,"}\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 159 "syntaxe.y"
    {fprintf(file,"else{\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 159 "syntaxe.y"
    {fprintf(file,"}\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 162 "syntaxe.y"
    {fprintf(file,"for(int "); fprintf(file,(yyvsp[(2) - (4)].sval)); fprintf(file,"= (int)"); fprintf(file,(yyvsp[(4) - (4)].sval));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 162 "syntaxe.y"
    {fprintf(file,";"); fprintf(file,(yyvsp[(2) - (8)].sval)); fprintf(file,"<="); fprintf(file,(yyvsp[(7) - (8)].sval)); fprintf(file,";"); fprintf(file,(yyvsp[(2) - (8)].sval)); fprintf(file,"++){\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 162 "syntaxe.y"
    {fprintf(file,"}\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 165 "syntaxe.y"
    { char tmp[32]="\0"; sprintf(tmp,"%f",(yyvsp[(1) - (1)].nval)); (yyval.sval) = tmp;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 166 "syntaxe.y"
    { char *tmp; tmp = strdup((yyvsp[(1) - (1)].sval)); (yyval.sval) = tmp;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 169 "syntaxe.y"
    {fprintf(file,"do{(");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 169 "syntaxe.y"
    {fprintf(file,"\n}while("); fprintf(file,(yyvsp[(7) - (8)].sval)); fprintf(file,");\n");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 172 "syntaxe.y"
    {fprintf(file,"while("); fprintf(file,(yyvsp[(2) - (3)].sval)); fprintf(file,"){\n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 172 "syntaxe.y"
    {fprintf(file,"}\n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 179 "syntaxe.y"
    {fprintf(file,"%s",(yyvsp[(1) - (1)].sval));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 180 "syntaxe.y"
    {fprintf(file,"%s",(yyvsp[(1) - (1)].sval));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 181 "syntaxe.y"
    {fprintf(file,"%s",(yyvsp[(1) - (1)].sval));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 182 "syntaxe.y"
    {fprintf(file,"%s",(yyvsp[(1) - (1)].sval));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 183 "syntaxe.y"
    {;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 184 "syntaxe.y"
    {fprintf(file,"%s;\n",(yyvsp[(1) - (2)].sval));}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 187 "syntaxe.y"
    {(yyval.sval) = strdup("printf("); strcat((yyval.sval), toCPrint((yyvsp[(3) - (5)].sval))); strcat((yyval.sval), ");\n");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 189 "syntaxe.y"
    {
															char out[1024];
															if(isFunctionDeclared((yyvsp[(3) - (5)].sval))){ yyerror("Can t affect value to functions"); exit(-1);}
															if(isConstantDeclared((yyvsp[(3) - (5)].sval))){ yyerror("Can t affect value to constant"); exit(-1);}
															if(!isVariableDeclared((yyvsp[(3) - (5)].sval))){ yyerror("Can t affect value to undeclared variable"); exit(-1);}
															else{
																strcpy(out, "scanf(\"");
																switch(getType((yyvsp[(3) - (5)].sval))){
																	case 0 :{strcat(out, "%d\",&"); strcat(out, (yyvsp[(3) - (5)].sval)); strcat(out, ");\n"); break;}
																	case 1 :{strcat(out, "%f\",&"); strcat(out, (yyvsp[(3) - (5)].sval)); strcat(out, ");\n"); break;}
																	case 2 :{strcat(out, "%s\","); strcat(out, (yyvsp[(3) - (5)].sval)); strcat(out, ");\n"); break;}
																	default :{exit(-1);}
																}
																(yyval.sval) = out;
															}
														;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 207 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 210 "syntaxe.y"
    {	char out[1024];
																								switch((yyvsp[(4) - (6)].type)){
																									case 0 :{strcpy(out, "int "); strcat(out, (yyvsp[(2) - (6)].sval)); break;}
																									case 1 :{strcpy(out, "float "); strcat(out, (yyvsp[(2) - (6)].sval)); break;}
																									case 2 :{strcpy(out, "char ");
																											 char* var = strtok((yyvsp[(2) - (6)].sval), ",");
																										     while(var != NULL){
																												strcat(out, "*"); strcat(out, var); strcat(out, ",");
																									        	var = strtok(NULL, ",");
																									         }
																											 out[strlen(out)-1] = ' ';
																									         break;}
																									default :{exit(-1);}
																								}
																								strcat(out, ";\n");
																								(yyval.sval) = out;
																								insertNewDeclaredVariable((yyvsp[(2) - (6)].sval), (yyvsp[(4) - (6)].type));
																							;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 228 "syntaxe.y"
    {	char *value = strdup((yyvsp[(7) - (8)].sval)), out[1024]="\0";
																								switch((yyvsp[(4) - (8)].type)){
																									case 0 :{	strcpy(out, "int "); strcat(out, (yyvsp[(2) - (8)].sval));
																												strcat(out, "="); !strcmp(value, "1")?strcat(out, "1"):strcat(out, "0"); break;
																											}
																									case 1 :{	strcpy(out, "float ");
																											 	strcat(out, (yyvsp[(2) - (8)].sval)); strcat(out, "="); strcat(out, value);
																												break;
																											}
																									case 2 :{	strcpy(out, "char *");
																												strcat(out, (yyvsp[(2) - (8)].sval)); strcat(out, "=strdup(\"");strcat(out, value); strcat(out, "\"),");
																												break;
																											}
																									default :{exit(-1);}
																								}
																								strcat(out, ";\n");
																								insertNewDeclaredVariable((yyvsp[(2) - (8)].sval), (yyvsp[(4) - (8)].type));
																								(yyval.sval) = out;

																							;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 250 "syntaxe.y"
    { 	if(isFunctionDeclared((yyvsp[(1) - (4)].sval))){ yyerror("Can t affect value to functions"); exit(-1);}
																	if(isConstantDeclared((yyvsp[(1) - (4)].sval))){ yyerror("Can t affect value to constanst"); exit(-1);}
																	if(!isVariableDeclared((yyvsp[(1) - (4)].sval))){ yyerror("Can t affect value to undeclared variable"); exit(-1);}
																	char *value =strdup((yyvsp[(3) - (4)].sval));
																	(yyval.sval) = (yyvsp[(1) - (4)].sval);
																	switch(getType((yyvsp[(1) - (4)].sval))){
																		case 0 :{strcat((yyval.sval), "="); !strcmp(value, "1")?strcat((yyval.sval), "1"):strcat((yyval.sval), "0"); break;}
																		case 1 :{strcat((yyval.sval), "="); strcat((yyval.sval), value); break;}
																		case 2 :{strcat((yyval.sval), "=strdup(\""); strcat((yyval.sval), value); strcat((yyval.sval), "\")"); break;}
																	}
																	strcat((yyval.sval), ";\n");
																;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 264 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(2) - (3)].sval);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 267 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), "&&"); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 268 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), "||"); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 269 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 272 "syntaxe.y"
    {strcpy((yyval.sval), "("); strcat((yyval.sval), (yyvsp[(2) - (3)].sval)); strcat((yyval.sval), ")");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 273 "syntaxe.y"
    {strcpy((yyval.sval), "!"); strcat((yyval.sval), (yyvsp[(2) - (2)].sval));;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 274 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 277 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 278 "syntaxe.y"
    {char tmp[2]; gcvt((yyvsp[(1) - (1)].bval), 1, tmp); (yyval.sval) = tmp;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 279 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 282 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), "=="); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 283 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), "!="); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 284 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), "<"); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 285 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), ">"); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 286 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), "<="); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 287 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), ">="); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 290 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), "+"); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 291 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), "-"); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 292 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), "%"); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 293 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 297 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), "*"); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 298 "syntaxe.y"
    {strcpy((yyval.sval), (yyvsp[(1) - (3)].sval)); strcat((yyval.sval), "/"); strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 299 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 303 "syntaxe.y"
    {strcpy((yyval.sval), "("); strcat((yyval.sval), (yyvsp[(2) - (3)].sval)); strcat((yyval.sval), ")");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 304 "syntaxe.y"
    { strcpy((yyval.sval), "-"); strcpy((yyval.sval), (yyvsp[(2) - (2)].sval));;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 305 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 308 "syntaxe.y"
    { char tmp[32]="\0"; sprintf(tmp,"%f",(yyvsp[(1) - (1)].nval)); (yyval.sval) = tmp; ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 309 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 310 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 313 "syntaxe.y"
    {if(!isFunctionDeclared((yyvsp[(1) - (4)].sval))){ yyerror("function is not declared"); exit(-1);} char *tmp; tmp = (yyvsp[(1) - (4)].sval); strcat(tmp, "("); strcat(tmp, (yyvsp[(3) - (4)].sval)); strcat(tmp, ")"); (yyval.sval) = tmp;;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 316 "syntaxe.y"
    {char *tmp; tmp = (yyval.sval); strcat(tmp, ", "); strcat(tmp, (yyvsp[(3) - (3)].sval)); (yyval.sval) = tmp;;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 317 "syntaxe.y"
    {(yyval.sval)=(yyvsp[(1) - (1)].sval);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 318 "syntaxe.y"
    {(yyval.sval) = " ";;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 321 "syntaxe.y"
    { strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 322 "syntaxe.y"
    { strcat((yyval.sval), (yyvsp[(3) - (3)].sval));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 323 "syntaxe.y"
    { (yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 324 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 327 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 328 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 329 "syntaxe.y"
    {(yyval.sval) = (yyvsp[(1) - (1)].sval);;}
    break;



/* Line 1455 of yacc.c  */
#line 2305 "syntaxe.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 331 "syntaxe.y"


void yyerror(const char *msg){
	printf("\nline %d : %s\n", lineNumber, msg);
}

int hash(char *name){
	int x = 0;
	while(*name != '\0')
		x = 23 * x + * (name++);
	return x % N;
}

variable* findVariable(char *name){
	variable *p;
	for(p = variables[hash(name)]; p != NULL ; p = p -> next){
		if(!strcmp(name, p->name))
			return p;
			}
	return NULL;
}

variable* findConstant(char *name){
	variable *p;
	for(p = constants[hash(name)]; p != NULL ; p = p -> next)
		if(!strcmp(name, p->name))
			return p;
	return NULL;
}

function* findFunction(char *name){
	function *p;
	for(p = functions[hash(name)]; p != NULL ; p = p -> next)
		if(!strcmp(name, p->name))
			return p;
	return NULL;
}

int isVariableDeclared(char *name){
	if(findVariable(name))
		return 1;
	return 0;
}

int isConstantDeclared(char *name){
	if(findConstant(name))
		return 1;
	return 0;
}

int isFunctionDeclared(char *name){
	if(findFunction(name))
		return 1;
	return 0;
}

variable* newDeclaredVariable(char *name, int type, variable *next){
	variable *r = (variable *)malloc(sizeof(variable));
	if(r == NULL){
		yyerror("ERROR : No enough space");
		exit(-1);
	}
	r->name = malloc(strlen(name) + 1);
	if(r->name == NULL){
		yyerror("\nERROR : No enough space\n");
		exit(-1);
	}
	strcpy(r->name, name);
	r->type = type;
	switch(type){
		case 0: r->value.b = 0;break;
		case 1: r->value.n = 0;break;
		case 2: r->value.s = strdup('\0');break;
	}
	r->next = next;
	return r;
}

variable* newConstant(char *name, int type, variable *next){
	variable *r = (variable *)malloc(sizeof(variable));
	if(r == NULL){
		yyerror("ERROR : No enough space");
		exit(-1);
	}
	r->name = malloc(strlen(name) + 1);
	if(r->name == NULL){
		yyerror("ERROR : No enough space");
		exit(-1);
	}
	strcpy(r->name, name);
	r->type = type;
	r->next = next;
	return r;
}

function* newFunction(char *name, int type, function *next){
	function *r = (function *)malloc(sizeof(function));
	if(r == NULL){
		yyerror("ERROR : No enough space");
		exit(-1);
	}
	r->name = malloc(strlen(name) + 1);
	if(r->name == NULL){
		yyerror("ERROR : No enough space");
		exit(-1);
	}
	strcpy(r->name, name);
	r->type = type;
	r->next = next;
	return r;
}

void insertNewDeclaredVariable(char *name, int type){
	if(isFunctionDeclared(name)){
		yyerror("Name already used by a function");
		exit(-1);
	}
	else if(isConstantDeclared(name)){
		yyerror("Name already used by a constant");
		exit(-1);
		 }
		 else if(!isVariableDeclared(name))
		 				variables[hash(name)] = newDeclaredVariable(name, type, variables[hash(name)]);
			  else{
		 		yyerror("Variable already declared");
		 		exit(-1);
		 	  }
}

void insertNewConstant(char *name, int type){
	if(isFunctionDeclared(name)){
		yyerror("Name already used by a function");
		exit(-1);
	}
	else if(isVariableDeclared(name)){
		yyerror("Name already used by a variable");
		exit(-1);
		 }
		 else if(!isConstantDeclared(name)){;
			constants[hash(name)] = newConstant(name, type, constants[hash(name)]);}
			  else{
		 		yyerror("constants already declared");
		 		exit(-1);
		 	  }
}

void insertNewFunction(char *name, int type){
	if(isConstantDeclared(name)){
		yyerror("Name already used by a constant");
		exit(-1);
	}
	else if(isVariableDeclared(name)){
		yyerror("Name already used by a variable");
		exit(-1);
		 }
		 else if(!isFunctionDeclared(name))
				functions[hash(name)] = newFunction(name, type, functions[hash(name)]);
			  else{
		 		yyerror("function already declared");
		 		exit(-1);
		 	  }
}

int getType(char *name){
	if(isVariableDeclared(name))
		return findVariable(name)->type;
	else if(isConstantDeclared(name))
			return findConstant(name)->type;
		 else{
			yyerror("Variable or constant is not declared");
			exit(-1);
		 }
}

char* toCType(int type){
	if(type == 1) return "float";
	else if(type == 0) return "int";
		 else return "char*";
}

char* toCShortType(char *name){
	int type = getType(name);
	if(type == 1) return "%.2f";
	else if(type == 0) return "%d";
		 else return "%s";
}

char* toCPrint(char *string){
	char *p = string;
	char message[4096] ="\0";
	char parameters[1024] ="\0";
	char var[32][256];
	int i=0;
	int k=0;

	for(p;*p;p++){
		if(*p =='|' && *(p-1) != '$'){
			char *q = ++p;
			int j=0;
			for(q;*q != '|';q++,j++,p++)
				var[i][j] = *q;
			strcat(message, toCShortType(var[i]));
			i++;p++;
		}
		k=(strlen(message));
		if(*p =='$'){
			p++;
		}
		else
			message[k++]=*p;
	}
	for(int j =0; j < i; j++){
			strcat(parameters, ",");
			strcat(parameters, var[j]);
	}
	char *out = malloc(strlen(message) + strlen(parameters));

	strcpy(out, "\"");
	strcat(out, message);
	strcat(out, "\"");
	strcat(out, parameters);
	return out;
}

void listdeclation(char *s1, char *s2, char *del){
	strcat(s1, del);
	strcat(s1, s2);
}

FILE* createfile(){
	char filename[] = "code.c";
	FILE *file;
	file = fopen(filename, "w");
	if(file == NULL){
		yyerror("Can't create file code.c");
		exit(-1);
	}
	fprintf(file, "#include<stdio.h>\n#include<stdlib.h>\n#include<string.h>\n");
	return file;
}

int main(int argc,char ** argv){
	if(argc>1) yyin=fopen(argv[1],"r");
	lineNumber=1;
	if(!yyparse())
			printf("--- CODE CORRECT ---");
}

