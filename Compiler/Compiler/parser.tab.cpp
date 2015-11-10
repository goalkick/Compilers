/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

#include <iostream>
#include "Classes.h"
#include "PrettyPrinter.h"
extern "C" int yylex();
void yyerror( std::shared_ptr<CProgram>& , const char * );

/* Line 371 of yacc.c  */
#line 76 "parser.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
/* Line 387 of yacc.c  */
#line 11 "parser.y"
 
	#include "Classes.h" 
	#include "PrettyPrinter.h" 


/* Line 387 of yacc.c  */
#line 114 "parser.tab.cpp"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER_LITERAL = 258,
     ID = 259,
     STRING = 260,
     INT = 261,
     IF = 262,
     CLASS = 263,
     PUBLIC = 264,
     BOOL = 265,
     EXTENDS = 266,
     RETURN = 267,
     WHILE = 268,
     VOID = 269,
     MAIN = 270,
     SYSTEM_OUT_PRINTLN = 271,
     LENGTH = 272,
     TRUE = 273,
     FALSE = 274,
     NEW = 275,
     ELSE = 276,
     THIS = 277,
     STATIC = 278
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 16 "parser.y"

	int ival;
	char sval[255];
	char* val;
	IProgram* programVal; 
	IMainClass* mainClassDeclarationVal; 
	IClassDeclsList* classDeclarationListVal; 
	IClassDecls* classDeclarationVal; 
	IVarDeclList* variableDeclarationListVal; 
	IVarDecl* variableDeclarationVal; 
	IMethodDecl* methodDeclarationVal; 
	IMethodDeclList* methodDeclarationListVal; 
	IFormalList* formalListVal; 
	IFormalRest* formalRestVal; 
	IStatement* statementVal; 
	IType* typeVal; 
	IExp* expressionVal; 
	IExpRest* expressionRest; 
	IExpList* expressionListVal; 
	IStatementList* statementListVal;


/* Line 387 of yacc.c  */
#line 175 "parser.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (std::shared_ptr<CProgram>& root);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 203 "parser.tab.cpp"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   463

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    13,     2,     2,     2,     2,     3,     2,
      36,    37,     6,     4,    40,     5,    10,     7,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       8,    41,     9,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    11,     2,    12,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    38,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    26,    28,    31,    36,    42,
      48,    55,    62,    70,    78,    87,    89,    92,    94,    97,
     101,   112,   124,   136,   149,   161,   174,   187,   201,   203,
     206,   209,   213,   217,   222,   226,   228,   230,   232,   236,
     239,   247,   253,   259,   264,   272,   276,   280,   284,   288,
     293,   297,   304,   310,   314,   318,   320,   322,   324,   326,
     328,   334,   339,   342,   346,   348,   351
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    44,    -1,    44,    45,    -1,    19,    15,
      35,    20,    34,    25,    26,    36,    16,    11,    12,    15,
      37,    35,    55,    38,    38,    -1,    46,    -1,    45,    46,
      -1,    19,    15,    35,    38,    -1,    19,    15,    35,    47,
      38,    -1,    19,    15,    35,    48,    38,    -1,    19,    15,
      35,    47,    48,    38,    -1,    19,    15,    22,    15,    35,
      38,    -1,    19,    15,    22,    15,    35,    47,    38,    -1,
      19,    15,    22,    15,    35,    48,    38,    -1,    19,    15,
      22,    15,    35,    47,    48,    38,    -1,    49,    -1,    47,
      49,    -1,    50,    -1,    48,    50,    -1,    54,    15,    39,
      -1,    20,    54,    15,    36,    37,    35,    23,    56,    39,
      38,    -1,    20,    54,    15,    36,    37,    35,    47,    23,
      56,    39,    38,    -1,    20,    54,    15,    36,    37,    35,
      51,    23,    56,    39,    38,    -1,    20,    54,    15,    36,
      37,    35,    47,    51,    23,    56,    39,    38,    -1,    20,
      54,    15,    36,    52,    37,    35,    23,    56,    39,    38,
      -1,    20,    54,    15,    36,    52,    37,    35,    47,    23,
      56,    39,    38,    -1,    20,    54,    15,    36,    52,    37,
      35,    51,    23,    56,    39,    38,    -1,    20,    54,    15,
      36,    52,    37,    35,    47,    51,    23,    56,    39,    38,
      -1,    55,    -1,    51,    55,    -1,    54,    15,    -1,    54,
      15,    53,    -1,    40,    54,    15,    -1,    53,    40,    54,
      15,    -1,    17,    11,    12,    -1,    21,    -1,    17,    -1,
      15,    -1,    35,    51,    38,    -1,    35,    38,    -1,    18,
      36,    56,    37,    55,    32,    55,    -1,    24,    36,    56,
      37,    55,    -1,    27,    36,    56,    37,    39,    -1,    15,
      41,    56,    39,    -1,    15,    11,    56,    12,    41,    56,
      39,    -1,    56,     4,    56,    -1,    56,     5,    56,    -1,
      56,     6,    56,    -1,    56,     7,    56,    -1,    56,    11,
      56,    12,    -1,    56,    10,    28,    -1,    56,    10,    15,
      36,    57,    37,    -1,    56,    10,    15,    36,    37,    -1,
      56,     8,    56,    -1,    56,     3,    56,    -1,    14,    -1,
      29,    -1,    30,    -1,    15,    -1,    33,    -1,    31,    17,
      11,    56,    12,    -1,    31,    15,    36,    37,    -1,    13,
      56,    -1,    36,    56,    37,    -1,    56,    -1,    57,    58,
      -1,    40,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    93,    93,    94,    98,   105,   106,   110,   111,   112,
     113,   114,   115,   116,   117,   121,   122,   126,   127,   131,
     135,   136,   137,   138,   139,   140,   141,   142,   146,   147,
     151,   152,   156,   157,   161,   162,   163,   164,   168,   169,
     170,   171,   172,   175,   176,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   202,   203,   207
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'&'", "'+'", "'-'", "'*'", "'/'", "'<'",
  "'>'", "'.'", "'['", "']'", "'!'", "INTEGER_LITERAL", "ID", "STRING",
  "INT", "IF", "CLASS", "PUBLIC", "BOOL", "EXTENDS", "RETURN", "WHILE",
  "VOID", "MAIN", "SYSTEM_OUT_PRINTLN", "LENGTH", "TRUE", "FALSE", "NEW",
  "ELSE", "THIS", "STATIC", "'{'", "'('", "')'", "'}'", "';'", "','",
  "'='", "$accept", "Program", "MainClass", "ClassDeclsList", "ClassDecls",
  "VarDeclList", "MethodDeclList", "VarDecl", "MethodDecl",
  "StatementList", "FormalList", "FormalRest", "Type", "Statement", "Exp",
  "ExpList", "ExpRest", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    38,    43,    45,    42,    47,    60,    62,
      46,    91,    93,    33,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   123,    40,    41,   125,    59,
      44,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    44,    45,    45,    46,    46,    46,
      46,    46,    46,    46,    46,    47,    47,    48,    48,    49,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    54,    54,    55,    55,
      55,    55,    55,    55,    55,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,    17,     1,     2,     4,     5,     5,
       6,     6,     7,     7,     8,     1,     2,     1,     2,     3,
      10,    11,    11,    12,    11,    12,    12,    13,     1,     2,
       2,     3,     3,     4,     3,     1,     1,     1,     3,     2,
       7,     5,     5,     4,     7,     3,     3,     3,     3,     4,
       3,     6,     5,     3,     3,     1,     1,     1,     1,     1,
       5,     4,     2,     3,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     3,     5,     0,
       0,     6,     0,     0,     0,     0,     0,    37,    36,     0,
      35,     7,     0,     0,    15,    17,     0,     0,     0,     0,
       0,     8,     0,    16,     9,    18,     0,     0,    11,     0,
       0,    34,     0,    10,    19,     0,    12,     0,    13,     0,
       0,    14,     0,     0,     0,     0,     0,     0,    30,     0,
      37,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,    31,     0,     0,     0,     0,     0,    55,    58,    56,
      57,     0,    59,     0,     0,     0,     0,     0,    39,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
      43,     0,     0,     0,    63,    54,    45,    46,    47,    48,
      53,     0,    50,     0,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    33,     0,     0,     0,    61,     0,
       0,    49,    41,    42,    21,     0,    22,    24,     0,     0,
       0,     0,     0,     0,    60,    52,    64,     0,    23,    25,
       0,    26,     4,    44,    40,    51,     0,    65,    27,    66
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    22,    23,    24,    25,    67,
      53,    71,    26,    68,    84,   177,   187
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int16 yypact[] =
{
      13,    49,    67,    56,    46,   -74,    71,    56,   -74,    77,
       9,   -74,    64,    93,    42,    84,    76,   -74,   101,   205,
     -74,   -74,   264,   -13,   -74,   -74,   105,    97,   295,   119,
     127,   -74,    -9,   -74,   -74,   -74,    95,   109,   -74,   302,
      10,   -74,   110,   -74,   -74,   131,   -74,    20,   -74,   237,
     137,   -74,   114,   120,   145,   156,   303,   136,   139,   167,
       5,   147,   263,   149,   150,   271,   324,   360,   -74,   337,
     205,   144,   157,   263,   263,   263,   263,   -74,   -74,   -74,
     -74,     3,   -74,   263,    66,   263,   263,     5,   -74,   273,
     263,   373,   263,   -74,   263,   350,   375,   182,   205,   173,
     422,    85,   196,   -74,   169,   210,   207,   263,   263,   263,
     263,   263,   263,    28,   263,   178,   224,   235,   -74,    96,
     263,   111,   122,   263,   388,   263,   -74,   208,   389,   209,
     -74,   389,   200,   263,   -74,   411,   411,   411,    -2,    -2,
      74,   217,   -74,   432,   -74,   389,   216,   218,   133,   219,
     221,   148,   263,   159,   -74,   231,   263,   230,   -74,   442,
     234,   -74,   -74,   -74,   -74,   242,   -74,   -74,   244,   170,
     245,   249,   185,   389,   -74,   -74,   452,    14,   -74,   -74,
     252,   -74,   -74,   -74,   -74,   -74,   263,   -74,   -74,   452
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   -74,   259,   -14,   197,   -17,   228,   -42,
     -74,   -74,    -4,   -63,   -73,   -74,   -74
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     100,   101,   102,   103,    93,    33,   112,    19,   113,   114,
     106,    19,   116,   117,    39,    30,    73,   119,   104,   121,
     105,   122,    33,    89,    91,    34,    93,    96,    93,    43,
      19,    13,     1,    93,   135,   136,   137,   138,   139,   140,
      19,   143,    66,   141,    14,    54,    74,   148,    48,    33,
     151,   185,   153,   124,   186,    95,   142,    17,    51,    18,
     159,    93,    19,    20,     4,   155,    97,     5,   157,   107,
     108,   109,   110,   111,   112,     6,   113,   114,    33,   169,
      21,     9,   162,   172,   113,   114,    10,   176,   107,   108,
     109,   110,   111,   112,   127,   113,   114,    12,    15,   107,
     108,   109,   110,   111,   112,   115,   113,   114,    16,    27,
     184,    28,    29,   189,   107,   108,   109,   110,   111,   112,
      36,   113,   114,    37,   130,   107,   108,   109,   110,   111,
     112,    41,   113,   114,    44,   147,   107,   108,   109,   110,
     111,   112,    42,   113,   114,    45,    49,    50,    55,    56,
     149,   107,   108,   109,   110,   111,   112,    57,   113,   114,
      58,   150,   107,   108,   109,   110,   111,   112,    59,   113,
     114,    69,   165,   107,   108,   109,   110,   111,   112,    70,
     113,   114,    72,    75,    98,    85,    86,   168,   107,   108,
     109,   110,   111,   112,    99,   113,   114,   126,   170,   107,
     108,   109,   110,   111,   112,   132,   113,   114,   128,   180,
     107,   108,   109,   110,   111,   112,   144,   113,   114,    32,
      17,   133,    18,   154,   183,    40,    20,   107,   108,   109,
     110,   111,   112,   131,   113,   114,    47,   158,   107,   108,
     109,   110,   111,   112,   134,   113,   114,    76,    77,    78,
     156,    35,    17,   160,    18,   163,   164,   166,    20,   167,
      35,   145,   173,    79,    80,    81,    11,    82,    35,   171,
      83,   175,   146,     0,    52,    35,    76,    77,    78,    17,
     178,    18,   179,   181,    19,    20,    87,   182,    87,    61,
     188,    61,    79,    80,    81,    63,    82,    63,    64,    83,
      64,     0,    31,     0,     0,     0,    65,     0,    65,    88,
      17,   118,    18,     0,     0,    19,    20,    17,    60,    18,
      18,    61,    19,    20,    20,     0,    62,    63,     0,     0,
      64,     0,     0,    38,     0,     0,     0,     0,    65,    60,
      46,    18,    61,     0,     0,    20,     0,    90,    63,     0,
       0,    64,    60,     0,    18,    61,     0,     0,    20,    65,
      94,    63,     0,     0,    64,    60,     0,    18,    61,     0,
       0,    20,    65,   123,    63,    87,     0,    64,    61,     0,
       0,     0,     0,    92,    63,    65,     0,    64,    87,     0,
      87,    61,     0,    61,     0,    65,   120,    63,   125,    63,
      64,     0,    64,    87,    87,     0,    61,    61,    65,     0,
      65,   152,    63,    63,     0,    64,    64,   110,   111,   112,
       0,   113,   114,    65,    65,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   129,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   161,   107,   108,   109,   110,   111,
     112,     0,   113,   114,   174,   107,   108,   109,   110,   111,
     112,     0,   113,   114
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      73,    74,    75,    76,    67,    22,     8,    20,    10,    11,
      83,    20,    85,    86,    28,    19,    11,    90,    15,    92,
      17,    94,    39,    65,    66,    38,    89,    69,    91,    38,
      20,    22,    19,    96,   107,   108,   109,   110,   111,   112,
      20,   114,    56,    15,    35,    49,    41,   120,    38,    66,
     123,    37,   125,    95,    40,    69,    28,    15,    38,    17,
     133,   124,    20,    21,    15,   128,    70,     0,   131,     3,
       4,     5,     6,     7,     8,    19,    10,    11,    95,   152,
      38,    35,   145,   156,    10,    11,    15,   160,     3,     4,
       5,     6,     7,     8,    98,    10,    11,    20,    34,     3,
       4,     5,     6,     7,     8,    39,    10,    11,    15,    25,
     173,    35,    11,   186,     3,     4,     5,     6,     7,     8,
      15,    10,    11,    26,    39,     3,     4,     5,     6,     7,
       8,    12,    10,    11,    39,    39,     3,     4,     5,     6,
       7,     8,    15,    10,    11,    36,    36,    16,    11,    35,
      39,     3,     4,     5,     6,     7,     8,    37,    10,    11,
      15,    39,     3,     4,     5,     6,     7,     8,    12,    10,
      11,    35,    39,     3,     4,     5,     6,     7,     8,    40,
      10,    11,    15,    36,    40,    36,    36,    39,     3,     4,
       5,     6,     7,     8,    37,    10,    11,    15,    39,     3,
       4,     5,     6,     7,     8,    36,    10,    11,    35,    39,
       3,     4,     5,     6,     7,     8,    38,    10,    11,    22,
      15,    11,    17,    15,    39,    28,    21,     3,     4,     5,
       6,     7,     8,    37,    10,    11,    39,    37,     3,     4,
       5,     6,     7,     8,    37,    10,    11,    13,    14,    15,
      41,    23,    15,    36,    17,    39,    38,    38,    21,    38,
      32,    37,    32,    29,    30,    31,     7,    33,    40,    38,
      36,    37,    37,    -1,    37,    47,    13,    14,    15,    15,
      38,    17,    38,    38,    20,    21,    15,    38,    15,    18,
      38,    18,    29,    30,    31,    24,    33,    24,    27,    36,
      27,    -1,    38,    -1,    -1,    -1,    35,    -1,    35,    38,
      15,    38,    17,    -1,    -1,    20,    21,    15,    15,    17,
      17,    18,    20,    21,    21,    -1,    23,    24,    -1,    -1,
      27,    -1,    -1,    38,    -1,    -1,    -1,    -1,    35,    15,
      38,    17,    18,    -1,    -1,    21,    -1,    23,    24,    -1,
      -1,    27,    15,    -1,    17,    18,    -1,    -1,    21,    35,
      23,    24,    -1,    -1,    27,    15,    -1,    17,    18,    -1,
      -1,    21,    35,    23,    24,    15,    -1,    27,    18,    -1,
      -1,    -1,    -1,    23,    24,    35,    -1,    27,    15,    -1,
      15,    18,    -1,    18,    -1,    35,    23,    24,    23,    24,
      27,    -1,    27,    15,    15,    -1,    18,    18,    35,    -1,
      35,    23,    24,    24,    -1,    27,    27,     6,     7,     8,
      -1,    10,    11,    35,    35,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    12,     3,     4,     5,     6,     7,
       8,    -1,    10,    11
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,    43,    44,    15,     0,    19,    45,    46,    35,
      15,    46,    20,    22,    35,    34,    15,    15,    17,    20,
      21,    38,    47,    48,    49,    50,    54,    25,    35,    11,
      54,    38,    48,    49,    38,    50,    15,    26,    38,    47,
      48,    12,    15,    38,    39,    36,    38,    48,    38,    36,
      16,    38,    37,    52,    54,    11,    35,    37,    15,    12,
      15,    18,    23,    24,    27,    35,    47,    51,    55,    35,
      40,    53,    15,    11,    41,    36,    13,    14,    15,    29,
      30,    31,    33,    36,    56,    36,    36,    15,    38,    51,
      23,    51,    23,    55,    23,    47,    51,    54,    40,    37,
      56,    56,    56,    56,    15,    17,    56,     3,     4,     5,
       6,     7,     8,    10,    11,    39,    56,    56,    38,    56,
      23,    56,    56,    23,    51,    23,    15,    54,    35,    12,
      39,    37,    36,    11,    37,    56,    56,    56,    56,    56,
      56,    15,    28,    56,    38,    37,    37,    39,    56,    39,
      39,    56,    23,    56,    15,    55,    41,    55,    37,    56,
      36,    12,    55,    39,    38,    39,    38,    38,    39,    56,
      39,    38,    56,    32,    12,    37,    56,    57,    38,    38,
      39,    38,    38,    39,    55,    37,    40,    58,    38,    56
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (root, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
		  Type, Value, root); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<CProgram>& root)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, root)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    std::shared_ptr<CProgram>& root;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (root);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, std::shared_ptr<CProgram>& root)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, root)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    std::shared_ptr<CProgram>& root;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, root);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, std::shared_ptr<CProgram>& root)
#else
static void
yy_reduce_print (yyvsp, yyrule, root)
    YYSTYPE *yyvsp;
    int yyrule;
    std::shared_ptr<CProgram>& root;
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
		       		       , root);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, root); \
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, std::shared_ptr<CProgram>& root)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, root)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    std::shared_ptr<CProgram>& root;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (root);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
yyparse (std::shared_ptr<CProgram>& root)
#else
int
yyparse (root)
    std::shared_ptr<CProgram>& root;
#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    { root = std::make_shared<CProgram>( (yyvsp[(1) - (1)].mainClassDeclarationVal), nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 94 "parser.y"
    { root = std::make_shared<CProgram>( (yyvsp[(1) - (2)].mainClassDeclarationVal), (yyvsp[(2) - (2)].classDeclarationListVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 99 "parser.y"
    { 
		(yyval.mainClassDeclarationVal) = new CMainClass( (yyvsp[(15) - (17)].statementVal), (yyvsp[(2) - (17)].sval), (yyvsp[(12) - (17)].sval), CLocation( 0, 0, 0, 0 ) );	
	}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 105 "parser.y"
    { (yyval.classDeclarationListVal) = new CClassDeclsList( (yyvsp[(1) - (1)].classDeclarationVal), nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 106 "parser.y"
    { (yyval.classDeclarationListVal) = new CClassDeclsList( (yyvsp[(2) - (2)].classDeclarationVal), (yyvsp[(1) - (2)].classDeclarationListVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 110 "parser.y"
    { (yyval.classDeclarationVal) = new CClassDecls( (yyvsp[(2) - (4)].sval), "", nullptr, nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 111 "parser.y"
    { (yyval.classDeclarationVal) = new CClassDecls( (yyvsp[(2) - (5)].sval), "", (yyvsp[(4) - (5)].variableDeclarationListVal), nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 112 "parser.y"
    { (yyval.classDeclarationVal) = new CClassDecls( (yyvsp[(2) - (5)].sval), "", nullptr, (yyvsp[(4) - (5)].methodDeclarationListVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 113 "parser.y"
    { (yyval.classDeclarationVal) = new CClassDecls( (yyvsp[(2) - (6)].sval), "", (yyvsp[(4) - (6)].variableDeclarationListVal), (yyvsp[(5) - (6)].methodDeclarationListVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 114 "parser.y"
    { (yyval.classDeclarationVal) = new CClassDecls( (yyvsp[(2) - (6)].sval), (yyvsp[(4) - (6)].sval), nullptr, nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 115 "parser.y"
    { (yyval.classDeclarationVal) = new CClassDecls( (yyvsp[(2) - (7)].sval), (yyvsp[(4) - (7)].sval), (yyvsp[(6) - (7)].variableDeclarationListVal), nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    { (yyval.classDeclarationVal) = new CClassDecls( (yyvsp[(2) - (7)].sval), (yyvsp[(4) - (7)].sval), nullptr, (yyvsp[(6) - (7)].methodDeclarationListVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 117 "parser.y"
    { (yyval.classDeclarationVal) = new CClassDecls( (yyvsp[(2) - (8)].sval), (yyvsp[(4) - (8)].sval), (yyvsp[(6) - (8)].variableDeclarationListVal), (yyvsp[(7) - (8)].methodDeclarationListVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 121 "parser.y"
    { (yyval.variableDeclarationListVal) = new CVarDeclList( nullptr, (yyvsp[(1) - (1)].variableDeclarationVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 122 "parser.y"
    { (yyval.variableDeclarationListVal) = new CVarDeclList( (yyvsp[(1) - (2)].variableDeclarationListVal), (yyvsp[(2) - (2)].variableDeclarationVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 126 "parser.y"
    { (yyval.methodDeclarationListVal) = new CMethodDeclList( (yyvsp[(1) - (1)].methodDeclarationVal), nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 127 "parser.y"
    { (yyval.methodDeclarationListVal) = new CMethodDeclList( (yyvsp[(2) - (2)].methodDeclarationVal), (yyvsp[(1) - (2)].methodDeclarationListVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 131 "parser.y"
    { (yyval.variableDeclarationVal) = new CVarDecl( (yyvsp[(1) - (3)].typeVal), (yyvsp[(2) - (3)].sval), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    { (yyval.methodDeclarationVal) = new CMethodDecl( (yyvsp[(2) - (10)].typeVal), (yyvsp[(3) - (10)].sval), nullptr, nullptr, nullptr, (yyvsp[(8) - (10)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 136 "parser.y"
    { (yyval.methodDeclarationVal) = new CMethodDecl( (yyvsp[(2) - (11)].typeVal), (yyvsp[(3) - (11)].sval), nullptr, (yyvsp[(7) - (11)].variableDeclarationListVal), nullptr, (yyvsp[(9) - (11)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 137 "parser.y"
    { (yyval.methodDeclarationVal) = new CMethodDecl( (yyvsp[(2) - (11)].typeVal), (yyvsp[(3) - (11)].sval), nullptr, nullptr, (yyvsp[(7) - (11)].statementListVal), (yyvsp[(9) - (11)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 138 "parser.y"
    { (yyval.methodDeclarationVal) = new CMethodDecl( (yyvsp[(2) - (12)].typeVal), (yyvsp[(3) - (12)].sval), nullptr, (yyvsp[(7) - (12)].variableDeclarationListVal), (yyvsp[(8) - (12)].statementListVal), (yyvsp[(10) - (12)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 139 "parser.y"
    { (yyval.methodDeclarationVal) = new CMethodDecl( (yyvsp[(2) - (11)].typeVal), (yyvsp[(3) - (11)].sval), (yyvsp[(5) - (11)].formalListVal), nullptr, nullptr, (yyvsp[(9) - (11)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    { (yyval.methodDeclarationVal) = new CMethodDecl( (yyvsp[(2) - (12)].typeVal), (yyvsp[(3) - (12)].sval), (yyvsp[(5) - (12)].formalListVal), (yyvsp[(8) - (12)].variableDeclarationListVal), nullptr, (yyvsp[(10) - (12)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
    { (yyval.methodDeclarationVal) = new CMethodDecl( (yyvsp[(2) - (12)].typeVal), (yyvsp[(3) - (12)].sval), (yyvsp[(5) - (12)].formalListVal), nullptr, (yyvsp[(8) - (12)].statementListVal), (yyvsp[(10) - (12)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 142 "parser.y"
    { (yyval.methodDeclarationVal) = new CMethodDecl( (yyvsp[(2) - (13)].typeVal), (yyvsp[(3) - (13)].sval), (yyvsp[(5) - (13)].formalListVal), (yyvsp[(8) - (13)].variableDeclarationListVal), (yyvsp[(9) - (13)].statementListVal), (yyvsp[(11) - (13)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 146 "parser.y"
    { (yyval.statementListVal) = new CStatementList( (yyvsp[(1) - (1)].statementVal), nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 147 "parser.y"
    { (yyval.statementListVal) = new CStatementList( (yyvsp[(2) - (2)].statementVal), (yyvsp[(1) - (2)].statementListVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 151 "parser.y"
    { (yyval.formalListVal) = new CFormalList( (yyvsp[(1) - (2)].typeVal), (yyvsp[(2) - (2)].sval), nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 152 "parser.y"
    { (yyval.formalListVal) = new CFormalList( (yyvsp[(1) - (3)].typeVal), (yyvsp[(2) - (3)].sval), (yyvsp[(3) - (3)].formalRestVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    { (yyval.formalRestVal) = new CFormalRest( (yyvsp[(2) - (3)].typeVal), (yyvsp[(3) - (3)].sval), nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    { (yyval.formalRestVal) = new CFormalRest( (yyvsp[(3) - (4)].typeVal), (yyvsp[(4) - (4)].sval), (yyvsp[(1) - (4)].formalRestVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
    { (yyval.typeVal) = new CType( CType::EType::INT_ARRAY, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    { (yyval.typeVal) = new CType( CType::EType::BOOL, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 163 "parser.y"
    { (yyval.typeVal) = new CType( CType::EType::INT, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 164 "parser.y"
    { (yyval.typeVal) = new CUserType( (yyvsp[(1) - (1)].sval), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 168 "parser.y"
    { (yyval.statementVal) = new CStatement( (yyvsp[(2) - (3)].statementListVal), CLocation(0, 0, 0, 0 ) ); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 169 "parser.y"
    { (yyval.statementVal) = new CStatement( nullptr, CLocation(0, 0, 0, 0 ) ); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 170 "parser.y"
    { (yyval.statementVal) = new CIfStatement( (yyvsp[(3) - (7)].expressionVal), (yyvsp[(5) - (7)].statementVal), (yyvsp[(7) - (7)].statementVal), CLocation(0, 0, 0, 0 ) ); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 171 "parser.y"
    { (yyval.statementVal) = new CWhileStatement( (yyvsp[(3) - (5)].expressionVal), (yyvsp[(5) - (5)].statementVal), CLocation(0, 0, 0, 0 ) ); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 172 "parser.y"
    { 
	(yyval.statementVal) = new CPrintStatement( (yyvsp[(3) - (5)].expressionVal), CLocation(0, 0, 0, 0 ) ); 
	}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    { (yyval.statementVal) = new CAssignStatement( (yyvsp[(1) - (4)].sval), (yyvsp[(3) - (4)].expressionVal), CLocation(0, 0, 0, 0 ) ); }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    { (yyval.statementVal) = new CArrayAssignStatement( (yyvsp[(1) - (7)].sval), (yyvsp[(3) - (7)].expressionVal), (yyvsp[(6) - (7)].expressionVal), CLocation(0, 0, 0, 0 ) ); }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    { (yyval.expressionVal) = new CBinOpExpression( (yyvsp[(1) - (3)].expressionVal), CBinOpExpression::PLUS, (yyvsp[(3) - (3)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 181 "parser.y"
    { (yyval.expressionVal) = new CBinOpExpression( (yyvsp[(1) - (3)].expressionVal), CBinOpExpression::MINUS, (yyvsp[(3) - (3)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 182 "parser.y"
    { (yyval.expressionVal) = new CBinOpExpression( (yyvsp[(1) - (3)].expressionVal), CBinOpExpression::TIMES, (yyvsp[(3) - (3)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    { (yyval.expressionVal) = new CBinOpExpression( (yyvsp[(1) - (3)].expressionVal), CBinOpExpression::DIVIDE, (yyvsp[(3) - (3)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 184 "parser.y"
    { (yyval.expressionVal) = new CIndexExpression( (yyvsp[(1) - (4)].expressionVal), (yyvsp[(3) - (4)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 185 "parser.y"
    { (yyval.expressionVal) = new CLenghtExpression( (yyvsp[(1) - (3)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    { (yyval.expressionVal) = new CMethodExpression( (yyvsp[(1) - (6)].expressionVal), (yyvsp[(3) - (6)].sval), (yyvsp[(5) - (6)].expressionListVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 187 "parser.y"
    { (yyval.expressionVal) = new CMethodExpression( (yyvsp[(1) - (5)].expressionVal), (yyvsp[(3) - (5)].sval), nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 188 "parser.y"
    { (yyval.expressionVal) = new CBinOpExpression( (yyvsp[(1) - (3)].expressionVal), CBinOpExpression::LESS, (yyvsp[(3) - (3)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 189 "parser.y"
    { (yyval.expressionVal) = new CBinOpExpression( (yyvsp[(1) - (3)].expressionVal), CBinOpExpression::AND, (yyvsp[(3) - (3)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    { (yyval.expressionVal) = new CIntLiteralExpression( std::to_string(yyval.ival), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 191 "parser.y"
    {}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 192 "parser.y"
    {}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 193 "parser.y"
    { (yyval.expressionVal) = new CIdentifierExpression( (yyvsp[(1) - (1)].sval), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 194 "parser.y"
    { (yyval.expressionVal) = new CThisExpression( CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 195 "parser.y"
    { (yyval.expressionVal) = new CNewIntArrayExpression( (yyvsp[(4) - (5)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 196 "parser.y"
    { (yyval.expressionVal) = new CNewExpression( (yyvsp[(2) - (4)].sval), CLocation( 0, 0, 0, 0) ); }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 197 "parser.y"
    { (yyval.expressionVal) =  new CUnaryOpExpression( CUnaryOpExpression::NOT, (yyvsp[(2) - (2)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 198 "parser.y"
    { (yyval.expressionVal) = new CBracesExpression( (yyvsp[(2) - (3)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 202 "parser.y"
    { (yyval.expressionListVal) = new CExpList( (yyvsp[(1) - (1)].expressionVal), nullptr, nullptr, CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 203 "parser.y"
    { (yyval.expressionListVal) = new CExpList( nullptr, (yyvsp[(1) - (2)].expressionListVal), (yyvsp[(2) - (2)].expressionRest), CLocation( 0, 0, 0, 0 ) ); }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 207 "parser.y"
    { (yyval.expressionRest) = new CExpRest( (yyvsp[(2) - (2)].expressionVal), CLocation( 0, 0, 0, 0 ) ); }
    break;


/* Line 1792 of yacc.c  */
#line 1998 "parser.tab.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (root, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (root, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
		      yytoken, &yylval, root);
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
      if (!yypact_value_is_default (yyn))
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
		  yystos[yystate], yyvsp, root);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (root, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, root);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, root);
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


/* Line 2055 of yacc.c  */
#line 210 "parser.y"

/* Функция обработки ошибки. */
void yyerror( std::shared_ptr<CProgram>& root, const char* str )
{
	std::cout << "ERROR!" << str << std::endl;
}