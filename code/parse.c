/* A Bison parser, made by GNU Bison 3.3.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parse.y" /* yacc.c:337  */

    #include "AST.h"
    #include <stdio.h>
    AST_pNode_t root; // the root node of the AST
    extern int yylex();
    extern int cur_line_num;
    void yyerror(const char *s) { printf("ERROR: %s line %d \n", s, cur_line_num); }

#line 79 "parse.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
   by #include "parse.h".  */
#ifndef YY_YY_PARSE_H_INCLUDED
# define YY_YY_PARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_LP = 258,
    T_RP = 259,
    T_LB = 260,
    T_RB = 261,
    T_DOT = 262,
    T_COMMA = 263,
    T_COLON = 264,
    T_MUL = 265,
    T_DIV = 266,
    T_UNEQUAL = 267,
    T_NOT = 268,
    T_PLUS = 269,
    T_MINUS = 270,
    T_GE = 271,
    T_GT = 272,
    T_LE = 273,
    T_LT = 274,
    T_EQUAL = 275,
    T_ASSIGN = 276,
    T_MOD = 277,
    T_DOTDOT = 278,
    T_SEMI = 279,
    T_SYS_CON = 280,
    T_SYS_FUNCT = 281,
    T_SYS_PROC = 282,
    T_SYS_TYPE = 283,
    T_READ = 284,
    T_INTEGER = 285,
    T_REAL = 286,
    T_CHAR = 287,
    T_NAME = 288,
    T_AND = 289,
    T_OR = 290,
    T_DOWNTO = 291,
    T_TO = 292,
    T_ARRAY = 293,
    T_BEGIN = 294,
    T_CASE = 295,
    T_CONST = 296,
    T_DO = 297,
    T_ELSE = 298,
    T_END = 299,
    T_FOR = 300,
    T_FUNCTION = 301,
    T_GOTO = 302,
    T_IF = 303,
    T_OF = 304,
    T_PACKED = 305,
    T_PROCEDURE = 306,
    T_PROGRAM = 307,
    T_RECORD = 308,
    T_REPEAT = 309,
    T_THEN = 310,
    T_TYPE = 311,
    T_UNTIL = 312,
    T_VAR = 313,
    T_WHILE = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "parse.y" /* yacc.c:352  */

    int token;
    AST_pNode_t node;

#line 187 "parse.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_H_INCLUDED  */



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
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   335

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  260

#define YYUNDEFTOK  2
#define YYMAXUTOK   314

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    59,    62,    65,    68,    72,    74,    76,
      78,    81,    85,    87,    89,    91,    94,    96,   100,   104,
     108,   113,   116,   119,   123,   127,   130,   134,   138,   142,
     146,   150,   155,   159,   163,   167,   172,   176,   181,   184,
     188,   192,   196,   201,   205,   209,   212,   215,   219,   224,
     229,   234,   239,   242,   246,   250,   254,   258,   263,   267,
     271,   275,   279,   283,   287,   291,   295,   298,   301,   304,
     307,   310,   313,   316,   319,   323,   327,   331,   336,   341,
     344,   348,   352,   357,   362,   365,   369,   374,   379,   385,
     388,   392,   397,   401,   405,   409,   414,   418,   422,   426,
     430,   434,   438,   442,   446,   450,   454,   458,   462,   466,
     470,   474,   478,   482,   486,   490,   494,   497,   501,   504,
     507,   511,   515,   519,   524,   528,   532
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_LP", "T_RP", "T_LB", "T_RB", "T_DOT",
  "T_COMMA", "T_COLON", "T_MUL", "T_DIV", "T_UNEQUAL", "T_NOT", "T_PLUS",
  "T_MINUS", "T_GE", "T_GT", "T_LE", "T_LT", "T_EQUAL", "T_ASSIGN",
  "T_MOD", "T_DOTDOT", "T_SEMI", "T_SYS_CON", "T_SYS_FUNCT", "T_SYS_PROC",
  "T_SYS_TYPE", "T_READ", "T_INTEGER", "T_REAL", "T_CHAR", "T_NAME",
  "T_AND", "T_OR", "T_DOWNTO", "T_TO", "T_ARRAY", "T_BEGIN", "T_CASE",
  "T_CONST", "T_DO", "T_ELSE", "T_END", "T_FOR", "T_FUNCTION", "T_GOTO",
  "T_IF", "T_OF", "T_PACKED", "T_PROCEDURE", "T_PROGRAM", "T_RECORD",
  "T_REPEAT", "T_THEN", "T_TYPE", "T_UNTIL", "T_VAR", "T_WHILE", "$accept",
  "program", "program_head", "routine", "sub_routine", "routine_head",
  "label_part", "const_part", "const_expr_list", "const_value",
  "type_part", "type_decl_list", "type_definition", "type_decl",
  "simple_type_decl", "array_type_decl", "record_type_decl",
  "field_decl_list", "field_decl", "name_list", "var_part",
  "var_decl_list", "var_decl", "routine_part", "function_decl",
  "function_head", "procedure_decl", "procedure_head", "parameters",
  "para_decl_list", "para_type_list", "var_para_list", "val_para_list",
  "routine_body", "compound_stmt", "stmt_list", "stmt", "non_label_stmt",
  "assign_stmt", "proc_stmt", "if_stmt", "else_clause", "repeat_stmt",
  "while_stmt", "for_stmt", "direction", "case_stmt", "case_expr_list",
  "case_expr", "goto_stmt", "expression_list", "expression", "expr",
  "term", "factor", "args_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -182

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-182)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -25,    11,    34,  -182,    26,  -182,    40,    29,    32,  -182,
    -182,  -182,  -182,  -182,    54,    56,   111,    94,    87,    90,
      75,   133,   142,   148,    67,   225,  -182,   115,   141,   225,
    -182,   225,  -182,   145,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,    78,   143,   156,    90,  -182,   144,    13,
     225,   225,   135,   225,   225,   146,   225,   225,   225,   225,
    -182,   169,  -182,  -182,  -182,   110,  -182,    12,    27,    35,
    -182,   160,  -182,     3,   172,   247,  -182,   161,    78,    96,
    -182,  -182,   122,   144,  -182,   153,   155,    13,  -182,   166,
    -182,   168,     2,   309,   189,  -182,   309,    92,   291,   176,
     309,   274,  -182,  -182,   225,   225,   225,   167,   225,   225,
     225,   225,   225,   225,    50,   225,   225,   225,   225,   225,
     225,   225,   225,   194,   225,   194,  -182,   182,   144,    78,
    -182,   184,   204,   144,   193,   198,  -182,  -182,  -182,   185,
      96,  -182,   227,   227,  -182,  -182,  -182,  -182,  -182,   225,
    -182,  -182,   225,   211,   225,  -182,    98,   114,   300,  -182,
      27,    27,    27,    27,    27,    27,   216,   226,    60,  -182,
      35,    35,    35,  -182,  -182,  -182,  -182,   265,   200,   309,
    -182,  -182,   139,   213,   212,    23,    19,  -182,   152,    78,
    -182,  -182,   220,   -15,   228,  -182,   223,    29,   230,   309,
     309,   225,   309,  -182,  -182,  -182,   194,   194,  -182,  -182,
    -182,  -182,   225,   194,  -182,  -182,   183,  -182,   240,  -182,
    -182,    96,  -182,  -182,   144,   241,     1,  -182,   243,   251,
      23,  -182,  -182,  -182,   309,   237,   238,   256,  -182,    78,
    -182,   221,   245,   241,  -182,   -15,    23,    23,  -182,  -182,
    -182,   194,  -182,    96,  -182,  -182,  -182,  -182,  -182,  -182
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     7,     0,     1,     0,     0,     9,     3,
       2,    63,     4,    60,     0,    17,     0,     0,     8,     0,
      39,    81,     0,     0,    79,     0,    61,     0,     0,     0,
      63,     0,    68,     0,    65,    66,    67,    69,    70,    71,
      72,    73,    74,     0,     0,     0,    16,    19,     0,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,   116,    12,    13,    14,   124,   118,     0,   105,   109,
     114,     0,    96,     0,     0,     0,    62,     0,     0,     0,
      18,    37,     0,    38,    41,     0,     0,     6,    45,     0,
      46,     0,     0,    98,     0,    64,   126,     0,     0,     0,
      75,     0,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
      24,    30,     0,     0,     0,     0,    21,    22,    23,     0,
       0,    40,    53,    53,    43,    44,     7,     7,    80,     0,
      82,    78,     0,     0,     0,   119,     0,     0,     0,   123,
     104,    99,   100,   101,   102,   103,     0,     0,     0,    93,
     106,   107,   108,   110,   111,   112,   113,     0,    85,    86,
      87,    10,     0,     0,     0,     0,     0,    34,     0,     0,
      20,    36,     0,     0,     0,    51,     0,     0,     0,    97,
     125,     0,    77,   117,   115,   122,     0,     0,    91,    92,
      90,    89,     0,     0,    83,    25,     0,    29,     0,    32,
      33,     0,    26,    42,     0,    59,     0,    55,     0,     0,
       0,    48,     5,    50,    76,     0,     0,     0,    84,     0,
      27,     0,     0,    58,    52,     0,     0,     0,    49,    95,
      94,     0,    28,     0,    35,    54,    56,    57,    88,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,  -182,  -182,   124,   276,  -182,  -182,  -182,   -43,
    -182,  -182,   234,  -137,  -181,  -182,  -182,  -182,   101,  -126,
    -182,  -182,   205,  -182,   208,  -182,   209,  -182,   157,  -182,
      59,  -182,  -182,   102,    -6,   275,  -112,   261,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,   147,  -182,
    -182,   -17,   222,    37,   -42,    62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,   196,   197,     8,    15,    18,    66,
      20,    46,    47,   135,   136,   137,   138,   186,   187,    82,
      49,    83,    84,    87,    88,    89,    90,    91,   194,   226,
     227,   228,   229,    12,    32,    16,    33,    34,    35,    36,
      37,   214,    38,    39,    40,   212,    41,   168,   169,    42,
      92,    96,    68,    69,    70,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      77,    13,   182,   192,   218,   244,   148,   188,    67,    94,
     149,   178,    73,   180,    75,   108,   102,   103,    81,   109,
     110,   111,   112,   113,   108,   245,   128,     1,   109,   110,
     111,   112,   113,    93,     5,   127,   134,    98,   129,   100,
     101,   115,   116,   224,     4,   118,   119,    10,    60,   248,
       9,   130,    81,    62,    63,    64,   131,   120,   123,    85,
     188,   114,   117,   219,    86,   256,   257,   225,    11,   121,
      53,   167,    54,    14,    55,    60,   173,   174,   175,   176,
      62,    63,    64,   166,   242,    60,   183,    17,    56,   158,
      62,    63,    64,   166,   235,   236,   151,   134,   243,   128,
     152,   238,   203,    60,   208,   177,   152,   179,    62,    63,
      64,   129,    19,   105,    43,   106,   259,   107,   204,   225,
      44,    60,   152,    45,   130,   167,    62,    63,    64,   131,
     139,   140,   199,    48,   132,   200,    50,   202,    21,   258,
      22,    23,   134,   215,    24,    51,   222,   139,    71,   133,
      11,    25,   170,   171,   172,    26,    27,    52,    28,    29,
     139,   221,    21,    78,    22,    30,   156,   157,    24,    76,
      31,    72,   104,   240,    11,    25,    79,    81,   134,    99,
      27,   122,    28,    29,   234,   126,   142,   134,   143,    30,
     146,    13,   147,   150,    31,   237,   252,   154,   239,    21,
     159,    22,    23,   134,   134,    24,   181,   184,    60,   185,
     134,    11,    25,    62,    63,    64,   189,    27,   191,    28,
      29,    21,   190,    22,    23,   206,    30,    24,    57,   124,
     193,    31,   201,    11,    25,   207,   216,   230,    58,    27,
      59,    28,    29,   213,   223,   217,   241,   231,    30,   139,
      60,    61,   246,    31,   233,    62,    63,    64,    65,   108,
     247,   249,   250,   109,   110,   111,   112,   113,   108,   254,
     253,   198,   109,   110,   111,   112,   113,   108,   155,     7,
      80,   109,   110,   111,   112,   113,   108,   220,   141,   125,
     109,   110,   111,   112,   113,   144,   145,   153,   251,   232,
     195,   210,   211,   108,   255,    74,   205,   109,   110,   111,
     112,   113,   108,    95,     0,   209,   109,   110,   111,   112,
     113,   108,     0,     0,     0,   109,   110,   111,   112,   113,
     160,   161,   162,   163,   164,   165
};

static const yytype_int16 yycheck[] =
{
      43,     7,   128,   140,   185,     4,     4,   133,    25,    51,
       8,   123,    29,   125,    31,    12,    58,    59,    33,    16,
      17,    18,    19,    20,    12,    24,     3,    52,    16,    17,
      18,    19,    20,    50,     0,    78,    79,    54,    15,    56,
      57,    14,    15,    58,    33,    10,    11,     7,    25,   230,
      24,    28,    33,    30,    31,    32,    33,    22,    55,    46,
     186,    49,    35,    44,    51,   246,   247,   193,    39,    34,
       3,   114,     5,    41,     7,    25,   118,   119,   120,   121,
      30,    31,    32,    33,   221,    25,   129,    33,    21,   106,
      30,    31,    32,    33,   206,   207,     4,   140,   224,     3,
       8,   213,     4,    25,    44,   122,     8,   124,    30,    31,
      32,    15,    56,     3,    20,     5,   253,     7,     4,   245,
      33,    25,     8,    33,    28,   168,    30,    31,    32,    33,
       8,     9,   149,    58,    38,   152,     3,   154,    27,   251,
      29,    30,   185,     4,    33,     3,   189,     8,    33,    53,
      39,    40,   115,   116,   117,    44,    45,     9,    47,    48,
       8,     9,    27,    20,    29,    54,   104,   105,    33,    24,
      59,    30,     3,   216,    39,    40,    20,    33,   221,    33,
      45,    21,    47,    48,   201,    24,    33,   230,    33,    54,
      24,   197,    24,     4,    59,   212,   239,    21,    15,    27,
      33,    29,    30,   246,   247,    33,    24,    23,    25,     5,
     253,    39,    40,    30,    31,    32,    23,    45,    33,    47,
      48,    27,    24,    29,    30,     9,    54,    33,     3,    57,
       3,    59,    21,    39,    40,     9,    23,     9,    13,    45,
      15,    47,    48,    43,    24,    33,     6,    24,    54,     8,
      25,    26,     9,    59,    24,    30,    31,    32,    33,    12,
       9,    24,    24,    16,    17,    18,    19,    20,    12,    24,
      49,   147,    16,    17,    18,    19,    20,    12,     4,     3,
      46,    16,    17,    18,    19,    20,    12,   186,    83,    42,
      16,    17,    18,    19,    20,    87,    87,     6,    42,   197,
     143,    36,    37,    12,   245,    30,     6,    16,    17,    18,
      19,    20,    12,    52,    -1,   168,    16,    17,    18,    19,
      20,    12,    -1,    -1,    -1,    16,    17,    18,    19,    20,
     108,   109,   110,   111,   112,   113
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    52,    61,    62,    33,     0,    63,    65,    66,    24,
       7,    39,    93,    94,    41,    67,    95,    33,    68,    56,
      70,    27,    29,    30,    33,    40,    44,    45,    47,    48,
      54,    59,    94,    96,    97,    98,    99,   100,   102,   103,
     104,   106,   109,    20,    33,    33,    71,    72,    58,    80,
       3,     3,     9,     3,     5,     7,    21,     3,    13,    15,
      25,    26,    30,    31,    32,    33,    69,   111,   112,   113,
     114,    33,    30,   111,    95,   111,    24,    69,    20,    20,
      72,    33,    79,    81,    82,    46,    51,    83,    84,    85,
      86,    87,   110,   111,   114,    97,   111,   115,   111,    33,
     111,   111,   114,   114,     3,     3,     5,     7,    12,    16,
      17,    18,    19,    20,    49,    14,    15,    35,    10,    11,
      22,    34,    21,    55,    57,    42,    24,    69,     3,    15,
      28,    33,    38,    53,    69,    73,    74,    75,    76,     8,
       9,    82,    33,    33,    84,    86,    24,    24,     4,     8,
       4,     4,     8,     6,    21,     4,   115,   115,   111,    33,
     112,   112,   112,   112,   112,   112,    33,    69,   107,   108,
     113,   113,   113,   114,   114,   114,   114,   111,    96,   111,
      96,    24,    79,    69,    23,     5,    77,    78,    79,    23,
      24,    33,    73,     3,    88,    88,    64,    65,    64,   111,
     111,    21,   111,     4,     4,     6,     9,     9,    44,   108,
      36,    37,   105,    43,   101,     4,    23,    33,    74,    44,
      78,     9,    69,    24,    58,    79,    89,    90,    91,    92,
       9,    24,    93,    24,   111,    96,    96,   111,    96,    15,
      69,     6,    73,    79,     4,    24,     9,     9,    74,    24,
      24,    42,    69,    49,    24,    90,    74,    74,    96,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    63,    64,    65,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    71,    71,
      72,    73,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    75,    76,    77,    77,    78,    79,    79,    80,    80,
      81,    81,    82,    83,    83,    83,    83,    83,    84,    85,
      86,    87,    88,    88,    89,    89,    90,    90,    91,    92,
      93,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
      99,    99,    99,   100,   101,   101,   102,   103,   104,   105,
     105,   106,   107,   107,   108,   108,   109,   110,   110,   111,
     111,   111,   111,   111,   111,   111,   112,   112,   112,   112,
     113,   113,   113,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     5,     0,     2,     0,
       5,     4,     1,     1,     1,     1,     2,     0,     2,     1,
       4,     1,     1,     1,     1,     3,     3,     4,     5,     3,
       1,     6,     3,     2,     1,     4,     3,     1,     2,     0,
       2,     1,     4,     2,     2,     1,     1,     0,     4,     5,
       4,     3,     3,     0,     3,     1,     3,     3,     2,     1,
       1,     3,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     6,     5,     4,     1,
       4,     1,     4,     5,     2,     0,     4,     4,     8,     1,
       1,     5,     2,     1,     4,     4,     2,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     4,     1,     4,     1,     3,
       2,     2,     4,     3,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 55 "parse.y" /* yacc.c:1652  */
    { InitNode(&(yyval.node)); (yyval.node)->type = e_program;
        (yyval.node)->child = (yyvsp[-2].node); (yyvsp[-2].node)->sibling = (yyvsp[-1].node); root = (yyval.node);
    }
#line 1487 "parse.c" /* yacc.c:1652  */
    break;

  case 3:
#line 59 "parse.y" /* yacc.c:1652  */
    { InitNode(&(yyval.node)); (yyval.node)->type = e_program_head; 
        (yyval.node)->child = (yyvsp[-1].node);}
#line 1494 "parse.c" /* yacc.c:1652  */
    break;

  case 4:
#line 62 "parse.y" /* yacc.c:1652  */
    {InitNode(&(yyval.node)); (yyval.node)->type = e_routine;
        (yyval.node)->child = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);}
#line 1501 "parse.c" /* yacc.c:1652  */
    break;

  case 5:
#line 65 "parse.y" /* yacc.c:1652  */
    {InitNode(&(yyval.node)); (yyval.node)->type = e_sub_routine;
        (yyval.node)->child = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);}
#line 1508 "parse.c" /* yacc.c:1652  */
    break;

  case 6:
#line 68 "parse.y" /* yacc.c:1652  */
    {InitNode(&(yyval.node));
        (yyval.node)->type = e_routine_head; (yyval.node)->child = (yyvsp[-4].node); (yyvsp[-4].node)->sibling = (yyvsp[-3].node); (yyvsp[-3].node)->sibling = (yyvsp[-2].node);
        (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);}
#line 1516 "parse.c" /* yacc.c:1652  */
    break;

  case 7:
#line 72 "parse.y" /* yacc.c:1652  */
    {InitNode(&(yyval.node)); (yyval.node)->type = e_label_part;}
#line 1522 "parse.c" /* yacc.c:1652  */
    break;

  case 8:
#line 74 "parse.y" /* yacc.c:1652  */
    {InitNode(&(yyval.node));
        (yyval.node)->type = e_const_part; (yyval.node)->child = (yyvsp[0].node);}
#line 1529 "parse.c" /* yacc.c:1652  */
    break;

  case 9:
#line 76 "parse.y" /* yacc.c:1652  */
    {InitNode(&(yyval.node)); (yyval.node)->type = e_const_part;}
#line 1535 "parse.c" /* yacc.c:1652  */
    break;

  case 10:
#line 78 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_const_expr_list; (yyval.node)->child = (yyvsp[-4].node);
    (yyvsp[-4].node)->sibling = (yyvsp[-3].node); (yyvsp[-3].node)->sibling = (yyvsp[-1].node);}
#line 1543 "parse.c" /* yacc.c:1652  */
    break;

  case 11:
#line 81 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_const_expr_list; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);}
#line 1551 "parse.c" /* yacc.c:1652  */
    break;

  case 12:
#line 85 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_const_value; (yyval.node)->child = (yyvsp[0].node);}
#line 1558 "parse.c" /* yacc.c:1652  */
    break;

  case 13:
#line 87 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_const_value; (yyval.node)->child = (yyvsp[0].node);}
#line 1565 "parse.c" /* yacc.c:1652  */
    break;

  case 14:
#line 89 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_const_value; (yyval.node)->child = (yyvsp[0].node);}
#line 1572 "parse.c" /* yacc.c:1652  */
    break;

  case 15:
#line 91 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_const_value; (yyval.node)->child = (yyvsp[0].node);}
#line 1579 "parse.c" /* yacc.c:1652  */
    break;

  case 16:
#line 94 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_type_part; (yyval.node)->child = (yyvsp[0].node);}
#line 1586 "parse.c" /* yacc.c:1652  */
    break;

  case 17:
#line 96 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_type_part;
    }
#line 1594 "parse.c" /* yacc.c:1652  */
    break;

  case 18:
#line 100 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_type_decl_list; (yyval.node)->child = (yyvsp[-1].node);
    (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 1603 "parse.c" /* yacc.c:1652  */
    break;

  case 19:
#line 104 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_type_decl_list; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1611 "parse.c" /* yacc.c:1652  */
    break;

  case 20:
#line 108 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_type_definition; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 1620 "parse.c" /* yacc.c:1652  */
    break;

  case 21:
#line 113 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_type_decl; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1628 "parse.c" /* yacc.c:1652  */
    break;

  case 22:
#line 116 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_type_decl; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1636 "parse.c" /* yacc.c:1652  */
    break;

  case 23:
#line 119 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_type_decl; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1644 "parse.c" /* yacc.c:1652  */
    break;

  case 24:
#line 123 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_simple_type_decl; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1652 "parse.c" /* yacc.c:1652  */
    break;

  case 25:
#line 127 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_simple_type_decl; (yyval.node)->child = (yyvsp[-1].node);
    }
#line 1660 "parse.c" /* yacc.c:1652  */
    break;

  case 26:
#line 130 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_simple_type_decl; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 1669 "parse.c" /* yacc.c:1652  */
    break;

  case 27:
#line 134 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_simple_type_decl; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-2].node); (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 1678 "parse.c" /* yacc.c:1652  */
    break;

  case 28:
#line 138 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_simple_type_decl; (yyval.node)->child = (yyvsp[-4].node);
    (yyvsp[-4].node)->sibling = (yyvsp[-3].node); (yyvsp[-3].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 1687 "parse.c" /* yacc.c:1652  */
    break;

  case 29:
#line 142 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_simple_type_decl; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 1696 "parse.c" /* yacc.c:1652  */
    break;

  case 30:
#line 146 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_simple_type_decl; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1704 "parse.c" /* yacc.c:1652  */
    break;

  case 31:
#line 150 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_array_type_decl; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[0].node);
    }
#line 1713 "parse.c" /* yacc.c:1652  */
    break;

  case 32:
#line 155 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_record_type_decl; (yyval.node)->child = (yyvsp[-1].node);
    }
#line 1721 "parse.c" /* yacc.c:1652  */
    break;

  case 33:
#line 159 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_field_decl_list; (yyval.node)->child = (yyvsp[-1].node);
    (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 1730 "parse.c" /* yacc.c:1652  */
    break;

  case 34:
#line 163 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_field_decl_list; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1738 "parse.c" /* yacc.c:1652  */
    break;

  case 35:
#line 167 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_field_decl; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 1747 "parse.c" /* yacc.c:1652  */
    break;

  case 36:
#line 172 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_name_list; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 1756 "parse.c" /* yacc.c:1652  */
    break;

  case 37:
#line 176 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_name_list; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1764 "parse.c" /* yacc.c:1652  */
    break;

  case 38:
#line 181 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_var_part; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1772 "parse.c" /* yacc.c:1652  */
    break;

  case 39:
#line 184 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_var_part;
    }
#line 1780 "parse.c" /* yacc.c:1652  */
    break;

  case 40:
#line 188 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_var_decl_list; (yyval.node)->child = (yyvsp[-1].node);
    (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 1789 "parse.c" /* yacc.c:1652  */
    break;

  case 41:
#line 192 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_var_decl_list; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1797 "parse.c" /* yacc.c:1652  */
    break;

  case 42:
#line 196 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_var_decl; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 1806 "parse.c" /* yacc.c:1652  */
    break;

  case 43:
#line 201 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_routine_part; (yyval.node)->child = (yyvsp[-1].node);
    (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 1815 "parse.c" /* yacc.c:1652  */
    break;

  case 44:
#line 205 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_routine_part; (yyval.node)->child = (yyvsp[-1].node);
    (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 1824 "parse.c" /* yacc.c:1652  */
    break;

  case 45:
#line 209 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_routine_part; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1832 "parse.c" /* yacc.c:1652  */
    break;

  case 46:
#line 212 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_routine_part; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1840 "parse.c" /* yacc.c:1652  */
    break;

  case 47:
#line 215 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_routine_part;
    }
#line 1848 "parse.c" /* yacc.c:1652  */
    break;

  case 48:
#line 219 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_function_decl; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 1857 "parse.c" /* yacc.c:1652  */
    break;

  case 49:
#line 224 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_function_head; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-2].node); (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 1866 "parse.c" /* yacc.c:1652  */
    break;

  case 50:
#line 229 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_procedure_decl; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 1875 "parse.c" /* yacc.c:1652  */
    break;

  case 51:
#line 234 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_procedure_head; (yyval.node)->child = (yyvsp[-1].node);
    (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 1884 "parse.c" /* yacc.c:1652  */
    break;

  case 52:
#line 239 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_parameters; (yyval.node)->child = (yyvsp[-1].node);
    }
#line 1892 "parse.c" /* yacc.c:1652  */
    break;

  case 53:
#line 242 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_parameters;
    }
#line 1900 "parse.c" /* yacc.c:1652  */
    break;

  case 54:
#line 246 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_para_decl_list; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 1909 "parse.c" /* yacc.c:1652  */
    break;

  case 55:
#line 250 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_para_decl_list; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1917 "parse.c" /* yacc.c:1652  */
    break;

  case 56:
#line 254 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_para_type_list; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 1926 "parse.c" /* yacc.c:1652  */
    break;

  case 57:
#line 258 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_para_type_list; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 1935 "parse.c" /* yacc.c:1652  */
    break;

  case 58:
#line 263 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_var_para_list; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1943 "parse.c" /* yacc.c:1652  */
    break;

  case 59:
#line 267 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_val_para_list; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1951 "parse.c" /* yacc.c:1652  */
    break;

  case 60:
#line 271 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_routine_body; (yyval.node)->child = (yyvsp[0].node);
    }
#line 1959 "parse.c" /* yacc.c:1652  */
    break;

  case 61:
#line 275 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_compound_stmt; (yyval.node)->child = (yyvsp[-1].node);
    }
#line 1967 "parse.c" /* yacc.c:1652  */
    break;

  case 62:
#line 279 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_stmt_list; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling =(yyvsp[-1].node);
    }
#line 1976 "parse.c" /* yacc.c:1652  */
    break;

  case 63:
#line 283 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_stmt_list;
    }
#line 1984 "parse.c" /* yacc.c:1652  */
    break;

  case 64:
#line 287 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_stmt; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 1993 "parse.c" /* yacc.c:1652  */
    break;

  case 65:
#line 291 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2001 "parse.c" /* yacc.c:1652  */
    break;

  case 66:
#line 295 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_non_label_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2009 "parse.c" /* yacc.c:1652  */
    break;

  case 67:
#line 298 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_non_label_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2017 "parse.c" /* yacc.c:1652  */
    break;

  case 68:
#line 301 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_non_label_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2025 "parse.c" /* yacc.c:1652  */
    break;

  case 69:
#line 304 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_non_label_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2033 "parse.c" /* yacc.c:1652  */
    break;

  case 70:
#line 307 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_non_label_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2041 "parse.c" /* yacc.c:1652  */
    break;

  case 71:
#line 310 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_non_label_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2049 "parse.c" /* yacc.c:1652  */
    break;

  case 72:
#line 313 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_non_label_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2057 "parse.c" /* yacc.c:1652  */
    break;

  case 73:
#line 316 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_non_label_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2065 "parse.c" /* yacc.c:1652  */
    break;

  case 74:
#line 319 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_non_label_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2073 "parse.c" /* yacc.c:1652  */
    break;

  case 75:
#line 323 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_assign_stmt; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 2082 "parse.c" /* yacc.c:1652  */
    break;

  case 76:
#line 327 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_assign_stmt; (yyval.node)->child = (yyvsp[-5].node);
    (yyvsp[-5].node)->sibling = (yyvsp[-3].node); (yyvsp[-3].node)->sibling = (yyvsp[0].node);
    }
#line 2091 "parse.c" /* yacc.c:1652  */
    break;

  case 77:
#line 331 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_assign_stmt; (yyval.node)->child = (yyvsp[-4].node);
    (yyvsp[-4].node)->sibling = (yyvsp[-2].node); (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 2100 "parse.c" /* yacc.c:1652  */
    break;

  case 78:
#line 336 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_proc_stmt; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 2109 "parse.c" /* yacc.c:1652  */
    break;

  case 79:
#line 341 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_proc_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2117 "parse.c" /* yacc.c:1652  */
    break;

  case 80:
#line 344 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_proc_stmt; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 2126 "parse.c" /* yacc.c:1652  */
    break;

  case 81:
#line 348 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_proc_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2134 "parse.c" /* yacc.c:1652  */
    break;

  case 82:
#line 352 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_proc_stmt; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 2143 "parse.c" /* yacc.c:1652  */
    break;

  case 83:
#line 357 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_if_stmt; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2152 "parse.c" /* yacc.c:1652  */
    break;

  case 84:
#line 362 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_else_clause; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2160 "parse.c" /* yacc.c:1652  */
    break;

  case 85:
#line 365 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_else_clause;
    }
#line 2168 "parse.c" /* yacc.c:1652  */
    break;

  case 86:
#line 369 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_repeat_stmt; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 2177 "parse.c" /* yacc.c:1652  */
    break;

  case 87:
#line 374 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_while_stmt; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 2186 "parse.c" /* yacc.c:1652  */
    break;

  case 88:
#line 379 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_for_stmt; (yyval.node)->child = (yyvsp[-6].node);
    (yyvsp[-6].node)->sibling = (yyvsp[-4].node); (yyvsp[-4].node)->sibling = (yyvsp[-3].node); (yyvsp[-3].node)->sibling = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 2196 "parse.c" /* yacc.c:1652  */
    break;

  case 89:
#line 385 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_direction; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2204 "parse.c" /* yacc.c:1652  */
    break;

  case 90:
#line 388 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_direction; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2212 "parse.c" /* yacc.c:1652  */
    break;

  case 91:
#line 392 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_case_stmt; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 2221 "parse.c" /* yacc.c:1652  */
    break;

  case 92:
#line 397 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_case_expr_list; (yyval.node)->child = (yyvsp[-1].node);
    (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2230 "parse.c" /* yacc.c:1652  */
    break;

  case 93:
#line 401 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_case_expr_list; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2238 "parse.c" /* yacc.c:1652  */
    break;

  case 94:
#line 405 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_case_expr; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 2247 "parse.c" /* yacc.c:1652  */
    break;

  case 95:
#line 409 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_case_expr; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 2256 "parse.c" /* yacc.c:1652  */
    break;

  case 96:
#line 414 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_goto_stmt; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2264 "parse.c" /* yacc.c:1652  */
    break;

  case 97:
#line 418 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expression_list; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 2273 "parse.c" /* yacc.c:1652  */
    break;

  case 98:
#line 422 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expression_list; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2281 "parse.c" /* yacc.c:1652  */
    break;

  case 99:
#line 426 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expression; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2290 "parse.c" /* yacc.c:1652  */
    break;

  case 100:
#line 430 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expression; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2299 "parse.c" /* yacc.c:1652  */
    break;

  case 101:
#line 434 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expression; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2308 "parse.c" /* yacc.c:1652  */
    break;

  case 102:
#line 438 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expression; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2317 "parse.c" /* yacc.c:1652  */
    break;

  case 103:
#line 442 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expression; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2326 "parse.c" /* yacc.c:1652  */
    break;

  case 104:
#line 446 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expression; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2335 "parse.c" /* yacc.c:1652  */
    break;

  case 105:
#line 450 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expression; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2343 "parse.c" /* yacc.c:1652  */
    break;

  case 106:
#line 454 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expr; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2352 "parse.c" /* yacc.c:1652  */
    break;

  case 107:
#line 458 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expr; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2361 "parse.c" /* yacc.c:1652  */
    break;

  case 108:
#line 462 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expr; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2370 "parse.c" /* yacc.c:1652  */
    break;

  case 109:
#line 466 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_expr; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2378 "parse.c" /* yacc.c:1652  */
    break;

  case 110:
#line 470 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_term; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2387 "parse.c" /* yacc.c:1652  */
    break;

  case 111:
#line 474 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_term; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2396 "parse.c" /* yacc.c:1652  */
    break;

  case 112:
#line 478 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_term; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2405 "parse.c" /* yacc.c:1652  */
    break;

  case 113:
#line 482 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_term; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[-1].node); (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2414 "parse.c" /* yacc.c:1652  */
    break;

  case 114:
#line 486 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_term; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2422 "parse.c" /* yacc.c:1652  */
    break;

  case 115:
#line 490 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_factor; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 2431 "parse.c" /* yacc.c:1652  */
    break;

  case 116:
#line 494 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_factor; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2439 "parse.c" /* yacc.c:1652  */
    break;

  case 117:
#line 497 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_factor; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 2448 "parse.c" /* yacc.c:1652  */
    break;

  case 118:
#line 501 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_factor; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2456 "parse.c" /* yacc.c:1652  */
    break;

  case 119:
#line 504 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_factor; (yyval.node)->child = (yyvsp[-1].node);
    }
#line 2464 "parse.c" /* yacc.c:1652  */
    break;

  case 120:
#line 507 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_factor; (yyval.node)->child = (yyvsp[-1].node);
    (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2473 "parse.c" /* yacc.c:1652  */
    break;

  case 121:
#line 511 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_factor; (yyval.node)->child = (yyvsp[-1].node);
    (yyvsp[-1].node)->sibling = (yyvsp[0].node);
    }
#line 2482 "parse.c" /* yacc.c:1652  */
    break;

  case 122:
#line 515 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_factor; (yyval.node)->child = (yyvsp[-3].node);
    (yyvsp[-3].node)->sibling = (yyvsp[-1].node);
    }
#line 2491 "parse.c" /* yacc.c:1652  */
    break;

  case 123:
#line 519 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_factor; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 2500 "parse.c" /* yacc.c:1652  */
    break;

  case 124:
#line 524 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_factor; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2508 "parse.c" /* yacc.c:1652  */
    break;

  case 125:
#line 528 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_args_list; (yyval.node)->child = (yyvsp[-2].node);
    (yyvsp[-2].node)->sibling = (yyvsp[0].node);
    }
#line 2517 "parse.c" /* yacc.c:1652  */
    break;

  case 126:
#line 532 "parse.y" /* yacc.c:1652  */
    {
    InitNode(&(yyval.node)); (yyval.node)->type = e_args_list; (yyval.node)->child = (yyvsp[0].node);
    }
#line 2525 "parse.c" /* yacc.c:1652  */
    break;


#line 2529 "parse.c" /* yacc.c:1652  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 537 "parse.y" /* yacc.c:1918  */


