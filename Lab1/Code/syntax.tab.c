/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./syntax.y"

    /* 注意 YYSTYPE 的define 需在前面，否则会造成yylval的type conflict*/
#define YYSTYPE TreeNode* 
#include "ast.h"
#include "lex.yy.c"

extern int syntax_error;

pNode root;



#line 84 "./syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_TYPE = 6,                       /* TYPE  */
  YYSYMBOL_RELOP = 7,                      /* RELOP  */
  YYSYMBOL_ASSIGNOP = 8,                   /* ASSIGNOP  */
  YYSYMBOL_PLUS = 9,                       /* PLUS  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_STAR = 11,                      /* STAR  */
  YYSYMBOL_DIV = 12,                       /* DIV  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_DOT = 16,                       /* DOT  */
  YYSYMBOL_COMMA = 17,                     /* COMMA  */
  YYSYMBOL_SEMI = 18,                      /* SEMI  */
  YYSYMBOL_LP = 19,                        /* LP  */
  YYSYMBOL_RP = 20,                        /* RP  */
  YYSYMBOL_LB = 21,                        /* LB  */
  YYSYMBOL_RB = 22,                        /* RB  */
  YYSYMBOL_LC = 23,                        /* LC  */
  YYSYMBOL_RC = 24,                        /* RC  */
  YYSYMBOL_STRUCT = 25,                    /* STRUCT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_ERRORNUM = 30,                  /* ERRORNUM  */
  YYSYMBOL_LOWER_THAN_ELSE = 31,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_Program = 33,                   /* Program  */
  YYSYMBOL_ExtDefList = 34,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 35,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 36,                /* ExtDecList  */
  YYSYMBOL_Specifier = 37,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 38,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 39,                    /* OptTag  */
  YYSYMBOL_Tag = 40,                       /* Tag  */
  YYSYMBOL_VarDec = 41,                    /* VarDec  */
  YYSYMBOL_FunDec = 42,                    /* FunDec  */
  YYSYMBOL_VarList = 43,                   /* VarList  */
  YYSYMBOL_ParamDec = 44,                  /* ParamDec  */
  YYSYMBOL_CompSt = 45,                    /* CompSt  */
  YYSYMBOL_StmtList = 46,                  /* StmtList  */
  YYSYMBOL_Stmt = 47,                      /* Stmt  */
  YYSYMBOL_DefList = 48,                   /* DefList  */
  YYSYMBOL_Def = 49,                       /* Def  */
  YYSYMBOL_DecList = 50,                   /* DecList  */
  YYSYMBOL_Dec = 51,                       /* Dec  */
  YYSYMBOL_Exp = 52,                       /* Exp  */
  YYSYMBOL_Args = 53                       /* Args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    60,    60,    62,    63,    65,    66,    67,    69,    70,
      71,    73,    74,    76,    80,    81,    83,    84,    86,    87,
      89,    93,    94,    96,    97,    99,   100,   102,   103,   105,
     106,   108,   112,   114,   116,   117,   119,   120,   121,   122,
     123,   124,   126,   127,   128,   129,   133,   134,   136,   138,
     139,   141,   142,   144,   145,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   168,   171,   172
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "ID",
  "TYPE", "RELOP", "ASSIGNOP", "PLUS", "MINUS", "STAR", "DIV", "AND", "OR",
  "NOT", "DOT", "COMMA", "SEMI", "LP", "RP", "LB", "RB", "LC", "RC",
  "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "ERRORNUM", "LOWER_THAN_ELSE",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-121)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-36)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,   124,  -121,    42,    20,  -121,    90,     5,  -121,  -121,
      56,    38,    62,  -121,  -121,  -121,    85,    92,  -121,   104,
      48,    14,  -121,    75,  -121,    75,  -121,    72,  -121,   123,
      66,   133,   101,    75,  -121,    94,   103,    75,    66,   118,
     122,   120,  -121,   125,  -121,   136,  -121,  -121,   140,   141,
    -121,    53,   115,    43,     8,   130,  -121,  -121,   144,  -121,
      75,  -121,  -121,  -121,  -121,    -7,  -121,  -121,   155,   116,
     116,   116,   113,   157,   160,  -121,  -121,   154,    53,   143,
    -121,   116,  -121,  -121,    66,  -121,  -121,    40,   282,    73,
     190,   171,   159,   116,   116,  -121,  -121,   173,   116,   116,
     116,   116,   116,   116,   116,   116,   187,  -121,   116,   250,
    -121,  -121,   205,   185,  -121,  -121,  -121,  -121,   220,   235,
    -121,   279,   250,   282,   282,    73,    73,   271,   263,  -121,
     174,   116,  -121,    83,    83,  -121,  -121,   165,  -121,    83,
    -121
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    14,    19,     0,     2,     0,     0,    15,     8,
       0,    20,     0,    17,     1,     3,     0,    21,     6,     0,
       0,     0,    10,    47,     9,     0,    24,     0,     5,     0,
       0,     0,     0,    47,     7,     0,     0,    47,     0,     0,
      30,     0,    26,     0,    13,     0,    21,    12,     0,     0,
      33,     0,     0,    53,     0,    51,    16,    46,    31,    28,
       0,    27,    25,    23,    22,     0,    71,    72,    70,     0,
       0,     0,     0,     0,     0,    73,    37,     0,     0,     0,
      49,     0,    50,    48,     0,    29,    42,     0,    64,    65,
       0,     0,     0,     0,     0,    32,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,    54,
      52,    67,    75,     0,    63,    45,    44,    38,     0,     0,
      43,    58,    55,    59,    60,    61,    62,    56,    57,    69,
       0,     0,    66,     0,     0,    68,    74,    39,    41,     0,
      40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,    -1,  -121,   164,    15,  -121,  -121,  -121,   -31,
    -121,   -19,  -121,   186,   131,  -120,    68,  -121,   139,  -121,
     -69,    77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    19,     7,     8,    12,    13,    20,
      21,    39,    40,    76,    77,    78,    36,    37,    54,    55,
      79,   113
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,    89,    90,    92,    53,    15,    16,    58,    43,    82,
      17,    86,   109,   137,   138,    32,    10,    50,   112,   140,
      14,    -4,     1,    18,   118,   119,    83,     2,    44,   121,
     122,   123,   124,   125,   126,   127,   128,    33,    35,   130,
      38,    85,    38,    66,    67,    68,     3,    11,    35,    29,
      69,    81,    35,    53,    65,    70,    66,    67,    68,    71,
     111,   -18,   112,    69,    31,    30,   -11,    45,    70,    31,
      75,    46,    71,    41,    22,    38,    33,   -35,     2,    72,
      73,     2,    74,    75,    65,    23,    66,    67,    68,   106,
      -4,     1,    42,    69,   108,    52,     2,     3,    70,    46,
       3,    51,    71,    24,    25,    57,    33,    26,    -4,    72,
      73,    27,    74,    75,    91,     3,    66,    67,    68,    66,
      67,    68,    28,    69,     1,    50,    69,    56,    70,     2,
       2,    70,    71,    80,    48,    71,    49,    26,    59,    60,
      61,    -4,     9,    75,    97,    62,    75,    84,     3,     3,
      98,    99,   100,   101,   102,   103,   104,   105,    26,   106,
     116,   107,    63,    64,   108,    31,    98,    99,   100,   101,
     102,   103,   104,   105,    87,   106,    93,   117,    95,    94,
     108,    98,    99,   100,   101,   102,   103,   104,   105,   115,
     106,   120,   129,   139,    47,   108,   135,    98,    99,   100,
     101,   102,   103,   104,   105,   132,   106,    34,   136,    96,
     114,   108,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,   131,   110,     0,     0,   108,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,     0,     0,     0,
     133,   108,    98,    99,   100,   101,   102,   103,   104,   105,
       0,   106,     0,     0,     0,   134,   108,    98,    99,   100,
     101,   102,   103,   104,   105,     0,   106,     0,     0,     0,
      98,   108,   100,   101,   102,   103,   104,     0,    98,   106,
     100,   101,   102,   103,   108,     0,     0,   106,   100,   101,
     102,   103,   108,   102,   103,   106,     0,     0,   106,     0,
     108,     0,     0,   108
};

static const yytype_int16 yycheck[] =
{
      69,    70,    71,    72,    35,     6,     1,    38,    27,     1,
       5,    18,    81,   133,   134,     1,     1,    24,    87,   139,
       0,     0,     1,    18,    93,    94,    18,     6,    29,    98,
      99,   100,   101,   102,   103,   104,   105,    23,    23,   108,
      25,    60,    27,     3,     4,     5,    25,     5,    33,     1,
      10,     8,    37,    84,     1,    15,     3,     4,     5,    19,
      20,    23,   131,    10,    21,    17,    18,     1,    15,    21,
      30,     5,    19,     1,    18,    60,    23,    24,     6,    26,
      27,     6,    29,    30,     1,    23,     3,     4,     5,    16,
       0,     1,    20,    10,    21,     1,     6,    25,    15,     5,
      25,    33,    19,    18,    19,    37,    23,    22,    18,    26,
      27,    19,    29,    30,     1,    25,     3,     4,     5,     3,
       4,     5,    18,    10,     1,    24,    10,    24,    15,     6,
       6,    15,    19,    18,     1,    19,     3,    22,    20,    17,
      20,    18,    18,    30,     1,    20,    30,    17,    25,    25,
       7,     8,     9,    10,    11,    12,    13,    14,    22,    16,
       1,    18,    22,    22,    21,    21,     7,     8,     9,    10,
      11,    12,    13,    14,    19,    16,    19,    18,    24,    19,
      21,     7,     8,     9,    10,    11,    12,    13,    14,    18,
      16,    18,     5,    28,    30,    21,    22,     7,     8,     9,
      10,    11,    12,    13,    14,    20,    16,    21,   131,    78,
      20,    21,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    17,    84,    -1,    -1,    21,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
      20,    21,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    16,    -1,    -1,    -1,    20,    21,     7,     8,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    -1,    -1,
       7,    21,     9,    10,    11,    12,    13,    -1,     7,    16,
       9,    10,    11,    12,    21,    -1,    -1,    16,     9,    10,
      11,    12,    21,    11,    12,    16,    -1,    -1,    16,    -1,
      21,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     6,    25,    33,    34,    35,    37,    38,    18,
      37,     5,    39,    40,     0,    34,     1,     5,    18,    36,
      41,    42,    18,    23,    18,    19,    22,    19,    18,     1,
      17,    21,     1,    23,    45,    37,    48,    49,    37,    43,
      44,     1,    20,    43,    34,     1,     5,    36,     1,     3,
      24,    48,     1,    41,    50,    51,    24,    48,    41,    20,
      17,    20,    20,    22,    22,     1,     3,     4,     5,    10,
      15,    19,    26,    27,    29,    30,    45,    46,    47,    52,
      18,     8,     1,    18,    17,    43,    18,    19,    52,    52,
      52,     1,    52,    19,    19,    24,    46,     1,     7,     8,
       9,    10,    11,    12,    13,    14,    16,    18,    21,    52,
      50,    20,    52,    53,    20,    18,     1,    18,    52,    52,
      18,    52,    52,    52,    52,    52,    52,    52,    52,     5,
      52,    17,    20,    20,    20,    22,    53,    47,    47,    28,
      47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    36,    36,    36,    37,    37,    38,    38,    39,    39,
      40,    41,    41,    41,    41,    42,    42,    42,    42,    43,
      43,    44,    45,    45,    46,    46,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    48,    48,    49,    49,
      49,    50,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     2,     3,
       3,     1,     3,     3,     1,     1,     5,     2,     1,     0,
       1,     1,     4,     4,     2,     4,     3,     4,     4,     3,
       1,     2,     4,     2,     2,     0,     2,     1,     3,     5,
       7,     5,     2,     3,     3,     3,     2,     0,     3,     3,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     3,     4,     3,
       1,     1,     1,     1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ExtDefList  */
#line 60 "./syntax.y"
                     {yyval = createNode((yyloc).first_line, NON_T, "Program", 1, yyvsp[0]); root = yyval;}
#line 1362 "./syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 62 "./syntax.y"
                               {yyval = createNode((yyloc).first_line, NON_T, "ExtDefList", 2, yyvsp[-1], yyvsp[0]);}
#line 1368 "./syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 63 "./syntax.y"
    { yyval = NULL;}
#line 1374 "./syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 65 "./syntax.y"
                                    { yyval = createNode((yyloc).first_line, NON_T, "ExtDef", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1380 "./syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 66 "./syntax.y"
                  {yyval = createNode((yyloc).first_line, NON_T, "ExtDef", 2, yyvsp[-1], yyvsp[0]);}
#line 1386 "./syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 67 "./syntax.y"
                            {yyval = createNode((yyloc).first_line, NON_T, "ExtDef", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1392 "./syntax.tab.c"
    break;

  case 8: /* ExtDef: error SEMI  */
#line 69 "./syntax.y"
              {syntax_error = 1;}
#line 1398 "./syntax.tab.c"
    break;

  case 9: /* ExtDef: Specifier error SEMI  */
#line 70 "./syntax.y"
                       {syntax_error = 1;}
#line 1404 "./syntax.tab.c"
    break;

  case 10: /* ExtDef: error Specifier SEMI  */
#line 71 "./syntax.y"
                       {syntax_error = 1;}
#line 1410 "./syntax.tab.c"
    break;

  case 11: /* ExtDecList: VarDec  */
#line 73 "./syntax.y"
                    {yyval = createNode((yyloc).first_line, NON_T, "ExtDecList", 1, yyvsp[0]);}
#line 1416 "./syntax.tab.c"
    break;

  case 12: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 74 "./syntax.y"
                            {yyval = createNode((yyloc).first_line, NON_T, "ExtDecList", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1422 "./syntax.tab.c"
    break;

  case 13: /* ExtDecList: VarDec error ExtDefList  */
#line 76 "./syntax.y"
                          {syntax_error = 1;}
#line 1428 "./syntax.tab.c"
    break;

  case 14: /* Specifier: TYPE  */
#line 80 "./syntax.y"
                    {yyval = createNode((yyloc).first_line, NON_T, "Specifier", 1, yyvsp[0]);}
#line 1434 "./syntax.tab.c"
    break;

  case 15: /* Specifier: StructSpecifier  */
#line 81 "./syntax.y"
                    {yyval = createNode((yyloc).first_line, NON_T, "Specifier", 1, yyvsp[0]);}
#line 1440 "./syntax.tab.c"
    break;

  case 16: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 83 "./syntax.y"
                                                { yyval = createNode((yyloc).first_line, NON_T, "StructSpecifier", 5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1446 "./syntax.tab.c"
    break;

  case 17: /* StructSpecifier: STRUCT Tag  */
#line 84 "./syntax.y"
                { yyval = createNode((yyloc).first_line, NON_T, "StructSpecifier", 2, yyvsp[-1], yyvsp[0]);}
#line 1452 "./syntax.tab.c"
    break;

  case 18: /* OptTag: ID  */
#line 86 "./syntax.y"
                {yyval = createNode((yyloc).first_line, NON_T, "OptTag", 1, yyvsp[0]);}
#line 1458 "./syntax.tab.c"
    break;

  case 19: /* OptTag: %empty  */
#line 87 "./syntax.y"
  {yyval = NULL;}
#line 1464 "./syntax.tab.c"
    break;

  case 20: /* Tag: ID  */
#line 89 "./syntax.y"
            {yyval = createNode((yyloc).first_line, NON_T, "Tag", 1, yyvsp[0]);}
#line 1470 "./syntax.tab.c"
    break;

  case 21: /* VarDec: ID  */
#line 93 "./syntax.y"
            { yyval = createNode((yyloc).first_line, NON_T, "VarDec", 1, yyvsp[0]);}
#line 1476 "./syntax.tab.c"
    break;

  case 22: /* VarDec: VarDec LB INT RB  */
#line 94 "./syntax.y"
                    {yyval = createNode((yyloc).first_line, NON_T, "VarDec", 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1482 "./syntax.tab.c"
    break;

  case 23: /* VarDec: VarDec LB error RB  */
#line 96 "./syntax.y"
                     { syntax_error = 1; }
#line 1488 "./syntax.tab.c"
    break;

  case 24: /* VarDec: error RB  */
#line 97 "./syntax.y"
           { syntax_error = 1; }
#line 1494 "./syntax.tab.c"
    break;

  case 25: /* FunDec: ID LP VarList RP  */
#line 99 "./syntax.y"
                            {yyval = createNode((yyloc).first_line, NON_T, "FunDec", 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1500 "./syntax.tab.c"
    break;

  case 26: /* FunDec: ID LP RP  */
#line 100 "./syntax.y"
            {yyval = createNode((yyloc).first_line, NON_T, "FunDec", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1506 "./syntax.tab.c"
    break;

  case 27: /* FunDec: ID LP error RP  */
#line 102 "./syntax.y"
                 { syntax_error = 1; }
#line 1512 "./syntax.tab.c"
    break;

  case 28: /* FunDec: error LP VarList RP  */
#line 103 "./syntax.y"
                      { syntax_error = 1; }
#line 1518 "./syntax.tab.c"
    break;

  case 29: /* VarList: ParamDec COMMA VarList  */
#line 105 "./syntax.y"
                                    { yyval = createNode((yyloc).first_line, NON_T, "VarList", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1524 "./syntax.tab.c"
    break;

  case 30: /* VarList: ParamDec  */
#line 106 "./syntax.y"
            { yyval = createNode((yyloc).first_line, NON_T, "VarList", 1, yyvsp[0]);}
#line 1530 "./syntax.tab.c"
    break;

  case 31: /* ParamDec: Specifier VarDec  */
#line 108 "./syntax.y"
                            { yyval = createNode((yyloc).first_line, NON_T, "ParamDec", 2, yyvsp[-1], yyvsp[0]);}
#line 1536 "./syntax.tab.c"
    break;

  case 32: /* CompSt: LC DefList StmtList RC  */
#line 112 "./syntax.y"
                                {yyval = createNode((yyloc).first_line, NON_T, "CompSt", 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1542 "./syntax.tab.c"
    break;

  case 33: /* CompSt: error RC  */
#line 114 "./syntax.y"
          { syntax_error = 1; }
#line 1548 "./syntax.tab.c"
    break;

  case 34: /* StmtList: Stmt StmtList  */
#line 116 "./syntax.y"
                         { yyval = createNode((yyloc).first_line, NON_T, "StmtList", 2, yyvsp[-1], yyvsp[0]);}
#line 1554 "./syntax.tab.c"
    break;

  case 35: /* StmtList: %empty  */
#line 117 "./syntax.y"
               {yyval = NULL;}
#line 1560 "./syntax.tab.c"
    break;

  case 36: /* Stmt: Exp SEMI  */
#line 119 "./syntax.y"
                {yyval = createNode((yyloc).first_line, NON_T, "Stmt", 2, yyvsp[-1], yyvsp[0]);}
#line 1566 "./syntax.tab.c"
    break;

  case 37: /* Stmt: CompSt  */
#line 120 "./syntax.y"
            { yyval = createNode((yyloc).first_line, NON_T, "Stmt", 1, yyvsp[0]);}
#line 1572 "./syntax.tab.c"
    break;

  case 38: /* Stmt: RETURN Exp SEMI  */
#line 121 "./syntax.y"
                    { yyval = createNode((yyloc).first_line, NON_T, "Stmt", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1578 "./syntax.tab.c"
    break;

  case 39: /* Stmt: IF LP Exp RP Stmt  */
#line 122 "./syntax.y"
                                            {yyval = createNode((yyloc).first_line, NON_T, "Stmt", 5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1584 "./syntax.tab.c"
    break;

  case 40: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 123 "./syntax.y"
                                {yyval = createNode((yyloc).first_line, NON_T, "Stmt", 7, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1590 "./syntax.tab.c"
    break;

  case 41: /* Stmt: WHILE LP Exp RP Stmt  */
#line 124 "./syntax.y"
                        { yyval = createNode((yyloc).first_line, NON_T, "Stmt", 5, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1596 "./syntax.tab.c"
    break;

  case 42: /* Stmt: error SEMI  */
#line 126 "./syntax.y"
                {syntax_error = 1;}
#line 1602 "./syntax.tab.c"
    break;

  case 43: /* Stmt: Exp error SEMI  */
#line 127 "./syntax.y"
                 {syntax_error = 1;}
#line 1608 "./syntax.tab.c"
    break;

  case 44: /* Stmt: RETURN Exp error  */
#line 128 "./syntax.y"
                    {syntax_error = 1;}
#line 1614 "./syntax.tab.c"
    break;

  case 45: /* Stmt: RETURN error SEMI  */
#line 129 "./syntax.y"
                     {syntax_error = 1;}
#line 1620 "./syntax.tab.c"
    break;

  case 46: /* DefList: Def DefList  */
#line 133 "./syntax.y"
                        {yyval = createNode((yyloc).first_line, NON_T, "DefList", 2, yyvsp[-1], yyvsp[0]);}
#line 1626 "./syntax.tab.c"
    break;

  case 47: /* DefList: %empty  */
#line 134 "./syntax.y"
                {yyval = NULL;}
#line 1632 "./syntax.tab.c"
    break;

  case 48: /* Def: Specifier DecList SEMI  */
#line 136 "./syntax.y"
                                {yyval = createNode((yyloc).first_line, NON_T, "Def", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1638 "./syntax.tab.c"
    break;

  case 49: /* Def: Specifier error SEMI  */
#line 138 "./syntax.y"
                       {syntax_error = 1;}
#line 1644 "./syntax.tab.c"
    break;

  case 50: /* Def: Specifier DecList error  */
#line 139 "./syntax.y"
                          {syntax_error = 1;}
#line 1650 "./syntax.tab.c"
    break;

  case 51: /* DecList: Dec  */
#line 141 "./syntax.y"
                { yyval = createNode((yyloc).first_line, NON_T, "DecList", 1, yyvsp[0]);}
#line 1656 "./syntax.tab.c"
    break;

  case 52: /* DecList: Dec COMMA DecList  */
#line 142 "./syntax.y"
                    {yyval = createNode((yyloc).first_line, NON_T, "DecList", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1662 "./syntax.tab.c"
    break;

  case 53: /* Dec: VarDec  */
#line 144 "./syntax.y"
                {yyval = createNode((yyloc).first_line, NON_T, "Dec", 1, yyvsp[0]);}
#line 1668 "./syntax.tab.c"
    break;

  case 54: /* Dec: VarDec ASSIGNOP Exp  */
#line 145 "./syntax.y"
                        {yyval = createNode((yyloc).first_line, NON_T, "Dec", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1674 "./syntax.tab.c"
    break;

  case 55: /* Exp: Exp ASSIGNOP Exp  */
#line 149 "./syntax.y"
                        {yyval = createNode((yyloc).first_line, NON_T, "Exp", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1680 "./syntax.tab.c"
    break;

  case 56: /* Exp: Exp AND Exp  */
#line 150 "./syntax.y"
                {yyval = createNode((yyloc).first_line, NON_T, "Exp", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1686 "./syntax.tab.c"
    break;

  case 57: /* Exp: Exp OR Exp  */
#line 151 "./syntax.y"
                {yyval = createNode((yyloc).first_line, NON_T, "Exp", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1692 "./syntax.tab.c"
    break;

  case 58: /* Exp: Exp RELOP Exp  */
#line 152 "./syntax.y"
                { yyval = createNode((yyloc).first_line, NON_T, "Exp", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1698 "./syntax.tab.c"
    break;

  case 59: /* Exp: Exp PLUS Exp  */
#line 153 "./syntax.y"
                { yyval = createNode((yyloc).first_line, NON_T, "Exp", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1704 "./syntax.tab.c"
    break;

  case 60: /* Exp: Exp MINUS Exp  */
#line 154 "./syntax.y"
                {yyval = createNode((yyloc).first_line, NON_T, "Exp", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1710 "./syntax.tab.c"
    break;

  case 61: /* Exp: Exp STAR Exp  */
#line 155 "./syntax.y"
                { yyval = createNode((yyloc).first_line, NON_T, "Exp", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1716 "./syntax.tab.c"
    break;

  case 62: /* Exp: Exp DIV Exp  */
#line 156 "./syntax.y"
                { yyval = createNode((yyloc).first_line, NON_T, "Exp", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1722 "./syntax.tab.c"
    break;

  case 63: /* Exp: LP Exp RP  */
#line 157 "./syntax.y"
            {yyval = createNode((yyloc).first_line, NON_T, "Exp", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1728 "./syntax.tab.c"
    break;

  case 64: /* Exp: MINUS Exp  */
#line 158 "./syntax.y"
            { yyval = createNode((yyloc).first_line, NON_T, "Exp", 2, yyvsp[-1], yyvsp[0]);}
#line 1734 "./syntax.tab.c"
    break;

  case 65: /* Exp: NOT Exp  */
#line 159 "./syntax.y"
            {yyval = createNode((yyloc).first_line, NON_T, "Exp", 2, yyvsp[-1], yyvsp[0]);}
#line 1740 "./syntax.tab.c"
    break;

  case 66: /* Exp: ID LP Args RP  */
#line 160 "./syntax.y"
                { yyval = createNode((yyloc).first_line, NON_T, "Exp", 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1746 "./syntax.tab.c"
    break;

  case 67: /* Exp: ID LP RP  */
#line 161 "./syntax.y"
            {yyval = createNode((yyloc).first_line, NON_T, "Exp", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1752 "./syntax.tab.c"
    break;

  case 68: /* Exp: Exp LB Exp RB  */
#line 162 "./syntax.y"
                { yyval = createNode((yyloc).first_line, NON_T, "Exp", 4, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1758 "./syntax.tab.c"
    break;

  case 69: /* Exp: Exp DOT ID  */
#line 163 "./syntax.y"
                { yyval = createNode((yyloc).first_line, NON_T, "Exp", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1764 "./syntax.tab.c"
    break;

  case 70: /* Exp: ID  */
#line 164 "./syntax.y"
        {yyval = createNode((yyloc).first_line, NON_T, "Exp", 1, yyvsp[0]);}
#line 1770 "./syntax.tab.c"
    break;

  case 71: /* Exp: INT  */
#line 165 "./syntax.y"
        {yyval = createNode((yyloc).first_line, NON_T, "Exp", 1, yyvsp[0]);}
#line 1776 "./syntax.tab.c"
    break;

  case 72: /* Exp: FLOAT  */
#line 166 "./syntax.y"
        { yyval = createNode((yyloc).first_line, NON_T, "Exp", 1, yyvsp[0]);}
#line 1782 "./syntax.tab.c"
    break;

  case 73: /* Exp: ERRORNUM  */
#line 168 "./syntax.y"
           {yyval = createNode((yyloc).first_line, NON_T, "Exp", 1, yyvsp[0]);syntax_error = 1;}
#line 1788 "./syntax.tab.c"
    break;

  case 74: /* Args: Exp COMMA Args  */
#line 171 "./syntax.y"
                        {yyval = createNode((yyloc).first_line, NON_T, "Args", 3, yyvsp[-2], yyvsp[-1], yyvsp[0]);}
#line 1794 "./syntax.tab.c"
    break;

  case 75: /* Args: Exp  */
#line 172 "./syntax.y"
        {yyval = createNode((yyloc).first_line, NON_T, "Args", 1, yyvsp[0]);}
#line 1800 "./syntax.tab.c"
    break;


#line 1804 "./syntax.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 175 "./syntax.y"

