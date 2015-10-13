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
extern "C" int yylex();
void yyerror( const char * );

/* Line 371 of yacc.c  */
#line 74 "parser.tab.cpp"

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
     BOOLEAN = 265,
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
#line 7 "parser.y"

	int ival;
	char sval[255];


/* Line 387 of yacc.c  */
#line 146 "parser.tab.cpp"
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
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 174 "parser.tab.cpp"

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
#define YYLAST   462

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  192

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
     293,   297,   304,   310,   314,   318,   322,   324,   326,   328,
     330,   332,   338,   343,   346,   350,   352,   355
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
      56,     8,    56,    -1,    56,     9,    56,    -1,    56,     3,
      56,    -1,    14,    -1,    29,    -1,    30,    -1,    15,    -1,
      33,    -1,    31,    17,    11,    56,    12,    -1,    31,    15,
      36,    37,    -1,    13,    56,    -1,    36,    56,    37,    -1,
      56,    -1,    57,    58,    -1,    40,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    49,    49,    50,    54,    58,    59,    63,    64,    65,
      66,    67,    68,    69,    70,    74,    75,    79,    80,    84,
      88,    89,    90,    91,    92,    93,    94,    95,    99,   100,
     104,   105,   109,   110,   114,   115,   116,   117,   121,   122,
     123,   124,   125,   126,   127,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   154,   155,   159
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'&'", "'+'", "'-'", "'*'", "'/'", "'<'",
  "'>'", "'.'", "'['", "']'", "'!'", "INTEGER_LITERAL", "ID", "STRING",
  "INT", "IF", "CLASS", "PUBLIC", "BOOLEAN", "EXTENDS", "RETURN", "WHILE",
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
      56,    56,    56,    56,    56,    57,    57,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,    17,     1,     2,     4,     5,     5,
       6,     6,     7,     7,     8,     1,     2,     1,     2,     3,
      10,    11,    11,    12,    11,    12,    12,    13,     1,     2,
       2,     3,     3,     4,     3,     1,     1,     1,     3,     2,
       7,     5,     5,     4,     7,     3,     3,     3,     3,     4,
       3,     6,     5,     3,     3,     3,     1,     1,     1,     1,
       1,     5,     4,     2,     3,     1,     2,     2
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
       0,    31,     0,     0,     0,     0,     0,    56,    59,    57,
      58,     0,    60,     0,     0,     0,     0,     0,    39,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,    43,     0,     0,     0,    64,    55,    45,    46,    47,
      48,    53,    54,     0,    50,     0,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
      62,     0,     0,    49,    41,    42,    21,     0,    22,    24,
       0,     0,     0,     0,     0,     0,    61,    52,    65,     0,
      23,    25,     0,    26,     4,    44,    40,    51,     0,    66,
      27,    67
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    22,    23,    24,    25,    67,
      53,    71,    26,    68,    84,   179,   189
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int16 yypact[] =
{
      13,    -9,    52,    35,    36,   -74,    45,    35,   -74,    47,
      92,   -74,    53,    75,   111,    66,    57,   -74,   102,   232,
     -74,   -74,   171,    25,   -74,   -74,   110,   103,   231,   138,
     136,   -74,    48,   -74,   -74,   -74,   148,   139,   -74,   300,
      50,   -74,   161,   -74,   -74,   157,   -74,   152,   -74,   307,
     197,   -74,   175,   195,   218,   199,   308,   177,   194,   230,
       0,   219,    44,   221,   222,   274,   324,   360,   -74,   337,
     232,   214,   258,    44,    44,    44,    44,   -74,   -74,   -74,
     -74,     3,   -74,    44,    91,    44,    44,     0,   -74,   275,
      44,   373,    44,   -74,    44,   350,   375,   241,   232,   261,
     421,   100,   233,   -74,   264,   292,   257,    44,    44,    44,
      44,    44,    44,    44,     1,    44,   266,   268,   277,   -74,
     113,    44,   137,   150,    44,   388,    44,   -74,   291,   322,
     270,   -74,   322,   279,    44,   -74,   127,   127,   127,   185,
     185,    72,    72,   271,   -74,   431,   -74,   322,   280,   289,
     159,   295,   296,   174,    44,   196,   -74,   298,    44,   286,
     -74,   441,    -6,   -74,   -74,   -74,   -74,   312,   -74,   -74,
     315,   211,   318,   325,   220,   322,   -74,   -74,   451,   134,
     -74,   -74,   328,   -74,   -74,   -74,   -74,   -74,    44,   -74,
     -74,   451
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   -74,   323,   -13,   269,   -17,    32,   -19,
     -74,   -74,    -5,   -63,   -73,   -74,   -74
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     100,   101,   102,   103,    93,    33,     4,    76,    77,    78,
     106,    73,   117,   118,    30,    39,   143,   120,   104,   122,
     105,   123,    33,    79,    80,    81,    93,    82,    93,   144,
      83,   177,     1,    93,   136,   137,   138,   139,   140,   141,
     142,    74,   145,    66,    54,    19,    89,    91,   150,    33,
      96,   153,     5,   155,     6,    35,    95,    76,    77,    78,
      10,   161,    93,    34,    35,    97,   157,    12,    19,   159,
      19,     9,    35,    79,    80,    81,   125,    82,    33,    35,
      83,   171,   114,   115,   164,   174,    43,    15,    48,   178,
      16,    27,    28,   128,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   186,    29,    13,   191,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    36,    17,    14,    18,    37,
     116,    19,    20,   110,   111,   112,   113,   114,   115,   131,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    21,
      41,    42,   149,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   187,    19,    50,   188,    45,   151,   107,   108,   109,
     110,   111,   112,   113,   114,   115,    17,    44,    18,   152,
      51,    19,    20,   112,   113,   114,   115,    49,   167,   107,
     108,   109,   110,   111,   112,   113,   114,   115,    55,    31,
      56,    59,    69,   170,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   107,   108,   109,   110,   111,   112,   113,
     114,   115,    57,    58,    70,   172,   107,   108,   109,   110,
     111,   112,   113,   114,   115,    72,    17,    17,    18,    18,
     182,    19,    20,    20,    98,    75,   127,    85,    86,   185,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    38,
     132,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     107,   108,   109,   110,   111,   112,   113,   114,   115,    87,
      87,    32,    61,    61,   135,    99,   129,    40,    63,    63,
     133,    64,    64,   134,   146,   147,   156,   162,    47,    65,
      65,   158,    88,   119,   148,    17,   160,    18,   175,   165,
      19,    20,    17,    60,    18,    18,    61,   166,    20,    20,
      11,    62,    63,   168,   169,    64,   173,    87,    46,    60,
      61,    18,    61,    65,    52,    20,    63,    90,    63,    64,
     180,    64,    60,   181,    18,    61,   183,    65,    20,    65,
      94,    63,     0,   184,    64,    60,   190,    18,    61,     0,
       0,    20,    65,   124,    63,    87,     0,    64,    61,     0,
       0,     0,     0,    92,    63,    65,     0,    64,    87,     0,
      87,    61,     0,    61,     0,    65,   121,    63,   126,    63,
      64,     0,    64,    87,     0,     0,    61,     0,    65,     0,
      65,   154,    63,     0,     0,    64,     0,     0,     0,     0,
       0,     0,     0,    65,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   130,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   163,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   176,   107,   108,   109,   110,   111,   112,
     113,   114,   115
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      73,    74,    75,    76,    67,    22,    15,    13,    14,    15,
      83,    11,    85,    86,    19,    28,    15,    90,    15,    92,
      17,    94,    39,    29,    30,    31,    89,    33,    91,    28,
      36,    37,    19,    96,   107,   108,   109,   110,   111,   112,
     113,    41,   115,    56,    49,    20,    65,    66,   121,    66,
      69,   124,     0,   126,    19,    23,    69,    13,    14,    15,
      15,   134,   125,    38,    32,    70,   129,    20,    20,   132,
      20,    35,    40,    29,    30,    31,    95,    33,    95,    47,
      36,   154,    10,    11,   147,   158,    38,    34,    38,   162,
      15,    25,    35,    98,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     3,     4,     5,     6,     7,     8,     9,
      10,    11,   175,    11,    22,   188,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    15,    15,    35,    17,    26,
      39,    20,    21,     6,     7,     8,     9,    10,    11,    39,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    38,
      12,    15,    39,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    37,    20,    16,    40,    36,    39,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    15,    39,    17,    39,
      38,    20,    21,     8,     9,    10,    11,    36,    39,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    11,    38,
      35,    12,    35,    39,     3,     4,     5,     6,     7,     8,
       9,    10,    11,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    37,    15,    40,    39,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    15,    15,    15,    17,    17,
      39,    20,    21,    21,    40,    36,    15,    36,    36,    39,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    38,
      37,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    15,
      15,    22,    18,    18,    37,    37,    35,    28,    24,    24,
      36,    27,    27,    11,    38,    37,    15,    36,    39,    35,
      35,    41,    38,    38,    37,    15,    37,    17,    32,    39,
      20,    21,    15,    15,    17,    17,    18,    38,    21,    21,
       7,    23,    24,    38,    38,    27,    38,    15,    38,    15,
      18,    17,    18,    35,    37,    21,    24,    23,    24,    27,
      38,    27,    15,    38,    17,    18,    38,    35,    21,    35,
      23,    24,    -1,    38,    27,    15,    38,    17,    18,    -1,
      -1,    21,    35,    23,    24,    15,    -1,    27,    18,    -1,
      -1,    -1,    -1,    23,    24,    35,    -1,    27,    15,    -1,
      15,    18,    -1,    18,    -1,    35,    23,    24,    23,    24,
      27,    -1,    27,    15,    -1,    -1,    18,    -1,    35,    -1,
      35,    23,    24,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    35,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     3,     4,     5,     6,     7,     8,
       9,    10,    11
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
       6,     7,     8,     9,    10,    11,    39,    56,    56,    38,
      56,    23,    56,    56,    23,    51,    23,    15,    54,    35,
      12,    39,    37,    36,    11,    37,    56,    56,    56,    56,
      56,    56,    56,    15,    28,    56,    38,    37,    37,    39,
      56,    39,    39,    56,    23,    56,    15,    55,    41,    55,
      37,    56,    36,    12,    55,    39,    38,    39,    38,    38,
      39,    56,    39,    38,    56,    32,    12,    37,    56,    57,
      38,    38,    39,    38,    38,    39,    55,    37,    40,    58,
      38,    56
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
      yyerror (YY_("syntax error: cannot back up")); \
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
#line 49 "parser.y"
    { }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 50 "parser.y"
    {}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 54 "parser.y"
    {}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 58 "parser.y"
    {}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 59 "parser.y"
    {}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 63 "parser.y"
    { std::cout << 1; }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 64 "parser.y"
    {}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 65 "parser.y"
    {}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 66 "parser.y"
    {}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 67 "parser.y"
    {}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 68 "parser.y"
    {}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 69 "parser.y"
    {}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 70 "parser.y"
    {}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 74 "parser.y"
    {}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 75 "parser.y"
    {}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 79 "parser.y"
    {}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 80 "parser.y"
    {}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 84 "parser.y"
    {}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 88 "parser.y"
    {}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 89 "parser.y"
    {}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 90 "parser.y"
    {}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 91 "parser.y"
    {}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 92 "parser.y"
    {}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    {}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 94 "parser.y"
    {}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 95 "parser.y"
    {}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 99 "parser.y"
    {}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 100 "parser.y"
    {}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 104 "parser.y"
    {}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 105 "parser.y"
    {}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 109 "parser.y"
    {}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 110 "parser.y"
    {}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 114 "parser.y"
    {}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 115 "parser.y"
    {}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 116 "parser.y"
    {}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 117 "parser.y"
    {}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 121 "parser.y"
    {}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 122 "parser.y"
    {}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    {}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 124 "parser.y"
    {}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 125 "parser.y"
    {}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 126 "parser.y"
    {}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 127 "parser.y"
    {}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 131 "parser.y"
    {}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 132 "parser.y"
    {}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 133 "parser.y"
    {}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 134 "parser.y"
    {}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    {}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 136 "parser.y"
    {}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 137 "parser.y"
    {}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 138 "parser.y"
    {}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 139 "parser.y"
    {}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    {}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
    {}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 142 "parser.y"
    {}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 143 "parser.y"
    {}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 144 "parser.y"
    {}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 145 "parser.y"
    {}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 146 "parser.y"
    {}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 147 "parser.y"
    {}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 148 "parser.y"
    {}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 149 "parser.y"
    {}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 150 "parser.y"
    {}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 154 "parser.y"
    {}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 155 "parser.y"
    {}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 159 "parser.y"
    {}
    break;


/* Line 1792 of yacc.c  */
#line 1968 "parser.tab.cpp"
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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
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
		  yystos[yystate], yyvsp);
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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 162 "parser.y"

/* Функция обработки ошибки. */
void yyerror( const char* str )
{
	std::cout << "ERROR!" << str << std::endl;
}