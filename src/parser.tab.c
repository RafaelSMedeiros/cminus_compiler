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
#line 1 "./syntactic/parser.y"

    #define YYPARSER /* distinguishes Yacc output from other code files */

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "globals.h"
    #include "util.h"
    #include "symtab.h"
    #include "cgen.h"

    #define MAXTOKENLEN 40
    extern char tokenID[MAXTOKENLEN+1];  // Declaração externa de tokenID

    extern int yylex();
    extern int yylineno; 
    extern char *yytext; 
    void yyerror(const char *s);
    extern FILE *yyin;

    #define YYSTYPE TreeNode *
    static TreeNode * arvoreSintatica; /* Armazena a árvore sintática */


#line 96 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_ELSE = 5,                       /* ELSE  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_VOID = 9,                       /* VOID  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_SOM = 11,                       /* SOM  */
  YYSYMBOL_SUB = 12,                       /* SUB  */
  YYSYMBOL_MUL = 13,                       /* MUL  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_MEN = 15,                       /* MEN  */
  YYSYMBOL_MMI = 16,                       /* MMI  */
  YYSYMBOL_MIG = 17,                       /* MIG  */
  YYSYMBOL_MAI = 18,                       /* MAI  */
  YYSYMBOL_IGU = 19,                       /* IGU  */
  YYSYMBOL_DIF = 20,                       /* DIF  */
  YYSYMBOL_ATR = 21,                       /* ATR  */
  YYSYMBOL_PEV = 22,                       /* PEV  */
  YYSYMBOL_VIR = 23,                       /* VIR  */
  YYSYMBOL_APA = 24,                       /* APA  */
  YYSYMBOL_FPA = 25,                       /* FPA  */
  YYSYMBOL_ACO = 26,                       /* ACO  */
  YYSYMBOL_FCO = 27,                       /* FCO  */
  YYSYMBOL_ACH = 28,                       /* ACH  */
  YYSYMBOL_FCH = 29,                       /* FCH  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_Programa = 31,                  /* Programa  */
  YYSYMBOL_DeclLista = 32,                 /* DeclLista  */
  YYSYMBOL_Decl = 33,                      /* Decl  */
  YYSYMBOL_VarDecl = 34,                   /* VarDecl  */
  YYSYMBOL_varID = 35,                     /* varID  */
  YYSYMBOL_vetID = 36,                     /* vetID  */
  YYSYMBOL_tam = 37,                       /* tam  */
  YYSYMBOL_TipoEspec = 38,                 /* TipoEspec  */
  YYSYMBOL_FunDecl = 39,                   /* FunDecl  */
  YYSYMBOL_funID = 40,                     /* funID  */
  YYSYMBOL_Params = 41,                    /* Params  */
  YYSYMBOL_ParamLista = 42,                /* ParamLista  */
  YYSYMBOL_Param = 43,                     /* Param  */
  YYSYMBOL_CompostoDecl = 44,              /* CompostoDecl  */
  YYSYMBOL_LocalDecl = 45,                 /* LocalDecl  */
  YYSYMBOL_ComandoLista = 46,              /* ComandoLista  */
  YYSYMBOL_Comando = 47,                   /* Comando  */
  YYSYMBOL_ExpDecl = 48,                   /* ExpDecl  */
  YYSYMBOL_SelecaoDecl = 49,               /* SelecaoDecl  */
  YYSYMBOL_IteracaoDecl = 50,              /* IteracaoDecl  */
  YYSYMBOL_RetornoDecl = 51,               /* RetornoDecl  */
  YYSYMBOL_Exp = 52,                       /* Exp  */
  YYSYMBOL_Var = 53,                       /* Var  */
  YYSYMBOL_SimplesExp = 54,                /* SimplesExp  */
  YYSYMBOL_Relacional = 55,                /* Relacional  */
  YYSYMBOL_SomaExp = 56,                   /* SomaExp  */
  YYSYMBOL_Soma = 57,                      /* Soma  */
  YYSYMBOL_Termo = 58,                     /* Termo  */
  YYSYMBOL_Mult = 59,                      /* Mult  */
  YYSYMBOL_Fator = 60,                     /* Fator  */
  YYSYMBOL_Ativacao = 61,                  /* Ativacao  */
  YYSYMBOL_ArgLista = 62                   /* ArgLista  */
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
typedef yytype_int8 yy_state_t;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    35,    35,    39,    48,    52,    53,    57,    64,    73,
      80,    89,    98,   107,   112,   121,   130,   133,   140,   149,
     150,   159,   167,   168,   175,   182,   193,   206,   210,   220,
     224,   225,   226,   227,   228,   232,   233,   234,   238,   245,
     254,   265,   272,   279,   280,   288,   295,   299,   304,   313,
     319,   323,   327,   331,   335,   339,   343,   351,   356,   360,
     364,   372,   377,   381,   385,   393,   394,   395,   396,   405,
     411,   420,   429
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID", "ELSE",
  "IF", "INT", "RETURN", "VOID", "WHILE", "SOM", "SUB", "MUL", "DIV",
  "MEN", "MMI", "MIG", "MAI", "IGU", "DIF", "ATR", "PEV", "VIR", "APA",
  "FPA", "ACO", "FCO", "ACH", "FCH", "$accept", "Programa", "DeclLista",
  "Decl", "VarDecl", "varID", "vetID", "tam", "TipoEspec", "FunDecl",
  "funID", "Params", "ParamLista", "Param", "CompostoDecl", "LocalDecl",
  "ComandoLista", "Comando", "ExpDecl", "SelecaoDecl", "IteracaoDecl",
  "RetornoDecl", "Exp", "Var", "SimplesExp", "Relacional", "SomaExp",
  "Soma", "Termo", "Mult", "Fator", "Ativacao", "ArgLista", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-55)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -55,     9,    91,   -55,    35,   -55,   -55,   -55,   -55,    16,
     -55,   -55,    92,    37,    19,    -3,    25,    48,    42,    90,
      82,    93,   -55,   -55,   110,    95,    88,    89,    94,    86,
      88,   -55,    97,    80,    98,   -55,    99,   -55,   -55,   -55,
     103,    86,    86,   -55,     7,   -55,   -55,   -55,   -55,    36,
     105,   -55,    37,   104,    29,   106,   -55,    66,   -55,   107,
     108,   -55,   -55,   -55,   -55,   -55,   -55,     6,   101,   -55,
      69,    96,   -55,   -55,   -55,    66,   -55,   109,     1,   111,
      66,    52,   -55,   -55,    66,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,    66,    66,   -55,   -55,    66,   112,   -55,
     113,   114,   -55,   102,   -55,   -55,    83,   -55,   -55,   100,
      96,   -55,    44,    44,    44,   -55,    66,   -55,   116,   -55,
     -55,   -55,    44,   -55
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     0,    13,    14,     3,     5,     0,
       6,     9,     0,    10,     0,     0,     0,     0,    14,     0,
       0,    19,    22,     7,     0,     0,     0,    24,     0,     0,
       0,    12,     0,     0,     0,    23,     0,     4,    16,    21,
       0,     0,     0,    25,     0,    29,     8,    17,    15,     0,
       0,    68,    47,     0,     0,     0,    36,     0,    26,     0,
       0,    31,    28,    30,    32,    33,    34,     0,    66,    46,
      50,    58,    62,    67,    37,     0,    43,     0,     0,     0,
       0,     0,    38,    35,     0,    59,    60,    51,    52,    53,
      54,    55,    56,     0,     0,    63,    64,     0,     0,    44,
       0,     0,    65,     0,    70,    72,     0,    45,    66,    49,
      57,    61,     0,     0,     0,    48,     0,    69,    40,    42,
      41,    71,     0,    39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,    81,   -55,   -55,   -55,     3,   -55,    -1,   -55,
     125,   115,   -55,     8,   -23,   -55,   -55,   -39,   -55,   -55,
     -55,   -55,   -54,   -15,   -55,   -55,    24,   -55,    41,   -55,
      22,   -55,   -55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     7,     8,    14,    59,    32,    19,    10,
      60,    20,    21,    22,    61,    45,    49,    62,    63,    64,
      65,    66,    67,    68,    69,    93,    70,    94,    71,    97,
      72,    73,   106
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      77,     9,   100,    79,    51,    52,    38,    82,     4,     3,
     -27,   -27,    15,   -27,     5,   -27,     6,   -27,    47,    48,
      13,    98,    28,    24,   101,    57,   103,   105,    83,   -27,
     107,   -27,    51,    52,    35,   -27,   -27,    50,    39,    51,
      52,    23,    53,     9,    54,    50,    55,    51,    52,    25,
      53,    76,    54,    57,    55,    51,    52,    11,    56,    12,
      57,   -18,   121,   -11,    37,    58,    56,   -20,    57,    51,
      52,    26,    37,   118,   119,   120,    57,   104,   108,   108,
      85,    86,   108,   123,    87,    88,    89,    90,    91,    92,
      57,    -2,     4,    17,    27,     5,    33,     6,     5,     5,
       6,    18,     5,    26,    18,    41,   116,    29,   117,    95,
      96,    85,    86,    31,    37,   -11,    30,   109,    44,   111,
      36,   122,    84,    42,    40,    46,    43,    74,    75,   115,
      78,    99,    81,    80,    16,   110,   102,   112,   113,   114,
      34
};

static const yytype_int8 yycheck[] =
{
      54,     2,     1,    57,     3,     4,    29,     1,     1,     0,
       3,     4,     9,     6,     7,     8,     9,    10,    41,    42,
       4,    75,    19,    26,    78,    24,    80,    81,    22,    22,
      84,    24,     3,     4,    26,    28,    29,     1,    30,     3,
       4,    22,     6,    44,     8,     1,    10,     3,     4,    24,
       6,    22,     8,    24,    10,     3,     4,    22,    22,    24,
      24,    24,   116,    26,    28,    29,    22,    25,    24,     3,
       4,    23,    28,   112,   113,   114,    24,    25,    93,    94,
      11,    12,    97,   122,    15,    16,    17,    18,    19,    20,
      24,     0,     1,     1,     4,     7,     1,     9,     7,     7,
       9,     9,     7,    23,     9,    25,    23,    25,    25,    13,
      14,    11,    12,     3,    28,    26,    23,    93,    37,    97,
      26,     5,    21,    25,    27,    22,    27,    22,    24,    27,
      24,    22,    24,    26,     9,    94,    25,    25,    25,    25,
      25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    31,    32,     0,     1,     7,     9,    33,    34,    38,
      39,    22,    24,     4,    35,    36,    40,     1,     9,    38,
      41,    42,    43,    22,    26,    24,    23,     4,    36,    25,
      23,     3,    37,     1,    41,    43,    26,    28,    44,    43,
      27,    25,    25,    27,    32,    45,    22,    44,    44,    46,
       1,     3,     4,     6,     8,    10,    22,    24,    29,    36,
      40,    44,    47,    48,    49,    50,    51,    52,    53,    54,
      56,    58,    60,    61,    22,    24,    22,    52,    24,    52,
      26,    24,     1,    22,    21,    11,    12,    15,    16,    17,
      18,    19,    20,    55,    57,    13,    14,    59,    52,    22,
       1,    52,    25,    52,    25,    52,    62,    52,    53,    56,
      58,    60,    25,    25,    25,    27,    23,    25,    47,    47,
      47,    52,     5,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    34,    34,    34,
      35,    36,    37,    38,    38,    39,    39,    39,    40,    41,
      41,    42,    42,    42,    43,    43,    44,    45,    46,    46,
      47,    47,    47,    47,    47,    48,    48,    48,    48,    49,
      49,    50,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    55,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    60,    60,    61,
      61,    62,    62
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     3,     6,     2,
       1,     1,     1,     1,     1,     6,     5,     6,     1,     1,
       1,     3,     1,     3,     2,     4,     4,     1,     2,     0,
       1,     1,     1,     1,     1,     2,     1,     2,     2,     7,
       5,     5,     5,     2,     3,     3,     1,     1,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       3,     3,     1
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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Programa: DeclLista  */
#line 35 "./syntactic/parser.y"
              { arvoreSintatica = yyvsp[0]; }
#line 1232 "parser.tab.c"
    break;

  case 3: /* DeclLista: DeclLista Decl  */
#line 39 "./syntactic/parser.y"
                   { 
        YYSTYPE t = yyvsp[-1];
        if (t != NULL){
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = yyvsp[0];
            yyval = yyvsp[-1];
        }
        else yyval = yyvsp[0];
    }
#line 1247 "parser.tab.c"
    break;

  case 4: /* DeclLista: %empty  */
#line 48 "./syntactic/parser.y"
                      { yyval = NULL; }
#line 1253 "parser.tab.c"
    break;

  case 5: /* Decl: VarDecl  */
#line 52 "./syntactic/parser.y"
            { yyval = yyvsp[0]; }
#line 1259 "parser.tab.c"
    break;

  case 6: /* Decl: FunDecl  */
#line 53 "./syntactic/parser.y"
              { yyval = yyvsp[0]; }
#line 1265 "parser.tab.c"
    break;

  case 7: /* VarDecl: TipoEspec varID PEV  */
#line 57 "./syntactic/parser.y"
                        {
        yyval = newExpNode(VarDeclK);
        yyval->attr.name = yyvsp[-1]->attr.name;
        yyval->kind.exp = VarDeclK;
        yyval->child[0] = yyvsp[-2];
        yyval->lineno = yyvsp[-1]->lineno;
        yyval->type = yyvsp[-2]->type;
    }
#line 1278 "parser.tab.c"
    break;

  case 8: /* VarDecl: TipoEspec vetID ACO tam FCO PEV  */
#line 64 "./syntactic/parser.y"
                                        {
        yyval = newExpNode(VetDeclK);
        yyval->attr.name = yyvsp[-4]->attr.name;
        yyval->kind.exp = VetDeclK;
        yyval->lineno = yyvsp[-4]->lineno;
        yyval->child[0] = yyvsp[-5];
        yyval->child[1] = yyvsp[-2];
        yyval->type = yyvsp[-5]->type;
    }
#line 1292 "parser.tab.c"
    break;

  case 9: /* VarDecl: error PEV  */
#line 73 "./syntactic/parser.y"
                 { 
        yyerrok; 
        yyval = NULL;
    }
#line 1301 "parser.tab.c"
    break;

  case 10: /* varID: ID  */
#line 80 "./syntactic/parser.y"
       {
        yyval = newExpNode(IdK);
        yyval->attr.name = copyString(tokenID);
        yyval->kind.exp = IdK;
        yyval->lineno = lineno;
    }
#line 1312 "parser.tab.c"
    break;

  case 11: /* vetID: ID  */
#line 89 "./syntactic/parser.y"
       {
        yyval = newExpNode(IdK);
        yyval->attr.name = copyString(tokenID);
        yyval->kind.exp = IdK;
        yyval->lineno = lineno;
    }
#line 1323 "parser.tab.c"
    break;

  case 12: /* tam: NUM  */
#line 98 "./syntactic/parser.y"
        {
        yyval = newExpNode(ConstK);
        yyval->attr.name = copyString(yytext);
        yyval->attr.val = atoi(yytext);
        yyval->type = INT_TYPE;
    }
#line 1334 "parser.tab.c"
    break;

  case 13: /* TipoEspec: INT  */
#line 107 "./syntactic/parser.y"
        {
        yyval = newExpNode(TypeK);
        yyval->attr.name = copyString(yytext);
        yyval->kind.exp = TypeK; 
        yyval->type = INT_TYPE;
    }
#line 1345 "parser.tab.c"
    break;

  case 14: /* TipoEspec: VOID  */
#line 112 "./syntactic/parser.y"
             {
        yyval = newExpNode(TypeK);
        yyval->attr.name = copyString(yytext);
        yyval->kind.exp = TypeK;
        yyval->type = VOID_TYPE;
    }
#line 1356 "parser.tab.c"
    break;

  case 15: /* FunDecl: TipoEspec funID APA Params FPA CompostoDecl  */
#line 121 "./syntactic/parser.y"
                                                {
        yyval = newExpNode(FunDeclK);
        yyval->kind.exp = FunDeclK;
        yyval->attr.name = yyvsp[-4]->attr.name;
        yyval->lineno = yyvsp[-4]->lineno;
        yyval->child[0] = yyvsp[-5];
        yyval->child[1] = yyvsp[-2];
        yyval->child[2] = yyvsp[0];
        yyval->type = yyvsp[-5]->type;
    }
#line 1371 "parser.tab.c"
    break;

  case 16: /* FunDecl: error APA Params FPA CompostoDecl  */
#line 130 "./syntactic/parser.y"
                                           { 
        yyerrok; 
        yyval = NULL;
    }
#line 1380 "parser.tab.c"
    break;

  case 17: /* FunDecl: TipoEspec funID APA error FPA CompostoDecl  */
#line 133 "./syntactic/parser.y"
                                                   { 
        yyerrok; 
        yyval = NULL;
    }
#line 1389 "parser.tab.c"
    break;

  case 18: /* funID: ID  */
#line 140 "./syntactic/parser.y"
       {
        yyval = newExpNode(IdK);
        yyval->attr.name = copyString(tokenID);
        yyval->kind.exp = IdK;
        yyval->lineno = lineno;
    }
#line 1400 "parser.tab.c"
    break;

  case 19: /* Params: ParamLista  */
#line 149 "./syntactic/parser.y"
               { yyval = yyvsp[0]; }
#line 1406 "parser.tab.c"
    break;

  case 20: /* Params: VOID  */
#line 150 "./syntactic/parser.y"
           {
        yyval = newExpNode(TypeK);
        yyval->attr.name = copyString(tokenID);
        yyval->child[0] = NULL;
        yyval->lineno = lineno;
    }
#line 1417 "parser.tab.c"
    break;

  case 21: /* ParamLista: ParamLista VIR Param  */
#line 159 "./syntactic/parser.y"
                         {
        YYSTYPE t = yyvsp[-2];
        if (t != NULL){
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = yyvsp[0];
            yyval = yyvsp[-2];
        }
    }
#line 1431 "parser.tab.c"
    break;

  case 22: /* ParamLista: Param  */
#line 167 "./syntactic/parser.y"
              { yyval = yyvsp[0]; }
#line 1437 "parser.tab.c"
    break;

  case 23: /* ParamLista: error VIR Param  */
#line 168 "./syntactic/parser.y"
                       { 
        yyerrok; 
        yyval = NULL;
    }
#line 1446 "parser.tab.c"
    break;

  case 24: /* Param: TipoEspec ID  */
#line 175 "./syntactic/parser.y"
                 {
        yyval = newExpNode(VarParamK);
        yyval->attr.name = copyString(tokenID);
        yyval->kind.exp = VarParamK;
        yyval->lineno = lineno;
        yyval->child[0] = yyvsp[-1];
        yyval->type = yyvsp[-1]->type;
    }
#line 1459 "parser.tab.c"
    break;

  case 25: /* Param: TipoEspec vetID ACO FCO  */
#line 182 "./syntactic/parser.y"
                                {
        yyval = newExpNode(VetParamK);
        yyval->attr.name = yyvsp[-2]->attr.name;
        yyval->kind.exp = VetParamK;
        yyval->lineno = lineno;
        yyval->child[0] = yyvsp[-3];
        yyval->type = yyvsp[-3]->type;
    }
#line 1472 "parser.tab.c"
    break;

  case 26: /* CompostoDecl: ACH LocalDecl ComandoLista FCH  */
#line 193 "./syntactic/parser.y"
                                   {
        YYSTYPE t = yyvsp[-2];
        if (t != NULL){
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = yyvsp[-1];
            yyval = yyvsp[-2];
        }
        else yyval = yyvsp[-1];
    }
#line 1487 "parser.tab.c"
    break;

  case 27: /* LocalDecl: DeclLista  */
#line 206 "./syntactic/parser.y"
              { yyval = yyvsp[0]; }
#line 1493 "parser.tab.c"
    break;

  case 28: /* ComandoLista: ComandoLista Comando  */
#line 210 "./syntactic/parser.y"
                         {
        YYSTYPE t = yyvsp[-1];
        if (t != NULL){
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = yyvsp[0];
            yyval = yyvsp[-1];
        }
        else yyval = yyvsp[0];
    }
#line 1508 "parser.tab.c"
    break;

  case 29: /* ComandoLista: %empty  */
#line 220 "./syntactic/parser.y"
                    { yyval = NULL; }
#line 1514 "parser.tab.c"
    break;

  case 30: /* Comando: ExpDecl  */
#line 224 "./syntactic/parser.y"
            { yyval = yyvsp[0]; }
#line 1520 "parser.tab.c"
    break;

  case 31: /* Comando: CompostoDecl  */
#line 225 "./syntactic/parser.y"
                   { yyval = yyvsp[0]; }
#line 1526 "parser.tab.c"
    break;

  case 32: /* Comando: SelecaoDecl  */
#line 226 "./syntactic/parser.y"
                  { yyval = yyvsp[0]; }
#line 1532 "parser.tab.c"
    break;

  case 33: /* Comando: IteracaoDecl  */
#line 227 "./syntactic/parser.y"
                   { yyval = yyvsp[0]; }
#line 1538 "parser.tab.c"
    break;

  case 34: /* Comando: RetornoDecl  */
#line 228 "./syntactic/parser.y"
                  { yyval = yyvsp[0]; }
#line 1544 "parser.tab.c"
    break;

  case 35: /* ExpDecl: Exp PEV  */
#line 232 "./syntactic/parser.y"
            { yyval = yyvsp[-1]; }
#line 1550 "parser.tab.c"
    break;

  case 37: /* ExpDecl: error PEV  */
#line 234 "./syntactic/parser.y"
                { 
        yyerrok; 
        yyval = NULL;
    }
#line 1559 "parser.tab.c"
    break;

  case 38: /* ExpDecl: Exp error  */
#line 238 "./syntactic/parser.y"
                { 
        yyerrok; 
        yyval = NULL;
    }
#line 1568 "parser.tab.c"
    break;

  case 39: /* SelecaoDecl: IF APA Exp FPA Comando ELSE Comando  */
#line 245 "./syntactic/parser.y"
                                        {
        yyval = newStmtNode(IfK);
        yyval->attr.name = copyString(yytext);
        yyval->kind.stmt = IfK;
        yyval->lineno = lineno;
        yyval->child[0] = yyvsp[-4];
        yyval->child[1] = yyvsp[-2];
        yyval->child[2] = yyvsp[0];
    }
#line 1582 "parser.tab.c"
    break;

  case 40: /* SelecaoDecl: IF APA Exp FPA Comando  */
#line 254 "./syntactic/parser.y"
                             {
        yyval = newStmtNode(IfK);
        yyval->attr.name = copyString(yytext);
        yyval->kind.stmt = IfK;
        yyval->lineno = lineno;
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1595 "parser.tab.c"
    break;

  case 41: /* IteracaoDecl: WHILE APA Exp FPA Comando  */
#line 265 "./syntactic/parser.y"
                              {
        yyval = newStmtNode(WhileK);
        yyval->attr.name = copyString(yytext);
        yyval->kind.stmt = WhileK;
        yyval->lineno = lineno;
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1608 "parser.tab.c"
    break;

  case 42: /* IteracaoDecl: WHILE APA error FPA Comando  */
#line 272 "./syntactic/parser.y"
                                    {
        yyerrok;
        yyval = NULL;
    }
#line 1617 "parser.tab.c"
    break;

  case 43: /* RetornoDecl: RETURN PEV  */
#line 279 "./syntactic/parser.y"
               { yyval = newStmtNode(ReturnVOID); }
#line 1623 "parser.tab.c"
    break;

  case 44: /* RetornoDecl: RETURN Exp PEV  */
#line 280 "./syntactic/parser.y"
                     {
        yyval = newStmtNode(ReturnINT);
        yyval->lineno = lineno;
        yyval->child[0] = yyvsp[-1];
    }
#line 1633 "parser.tab.c"
    break;

  case 45: /* Exp: Var ATR Exp  */
#line 288 "./syntactic/parser.y"
                {
        yyval = newStmtNode(AssignK);
        yyval->kind.stmt = AssignK;
        yyval->attr.name= yyvsp[-2]->attr.name;
        yyval->lineno = lineno;
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1646 "parser.tab.c"
    break;

  case 46: /* Exp: SimplesExp  */
#line 295 "./syntactic/parser.y"
                   { yyval = yyvsp[0]; }
#line 1652 "parser.tab.c"
    break;

  case 47: /* Var: ID  */
#line 299 "./syntactic/parser.y"
       {
        yyval = newExpNode(IdK);
        yyval->lineno = lineno;
        yyval->attr.name = copyString(tokenID);

    }
#line 1663 "parser.tab.c"
    break;

  case 48: /* Var: vetID ACO Exp FCO  */
#line 304 "./syntactic/parser.y"
                          {
        yyval = newExpNode(IdK);
        yyval->attr.name = yyvsp[-3]->attr.name;
        yyval->lineno = lineno;
        yyval->child[0] = yyvsp[-1];
    }
#line 1674 "parser.tab.c"
    break;

  case 49: /* SimplesExp: SomaExp Relacional SomaExp  */
#line 313 "./syntactic/parser.y"
                               {
        yyval = newStmtNode(AssignK);
        yyval = yyvsp[-1];
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1685 "parser.tab.c"
    break;

  case 50: /* SimplesExp: SomaExp  */
#line 319 "./syntactic/parser.y"
              { yyval = yyvsp[0]; }
#line 1691 "parser.tab.c"
    break;

  case 51: /* Relacional: MEN  */
#line 323 "./syntactic/parser.y"
        {
        yyval = newExpNode(OpK);
        yyval->attr.op = MEN;
        yyval->lineno = lineno;
    }
#line 1701 "parser.tab.c"
    break;

  case 52: /* Relacional: MMI  */
#line 327 "./syntactic/parser.y"
            {
        yyval = newExpNode(OpK);
        yyval->attr.op = MMI;
        yyval->lineno = lineno;
    }
#line 1711 "parser.tab.c"
    break;

  case 53: /* Relacional: MIG  */
#line 331 "./syntactic/parser.y"
            {
        yyval = newExpNode(OpK);
        yyval->attr.op = MIG;
        yyval->lineno = lineno;
    }
#line 1721 "parser.tab.c"
    break;

  case 54: /* Relacional: MAI  */
#line 335 "./syntactic/parser.y"
            {
        yyval = newExpNode(OpK);
        yyval->attr.op = MAI;
        yyval->lineno = lineno;
    }
#line 1731 "parser.tab.c"
    break;

  case 55: /* Relacional: IGU  */
#line 339 "./syntactic/parser.y"
            {
        yyval = newExpNode(OpK);
        yyval->attr.op = IGU;
        yyval->lineno = lineno;
    }
#line 1741 "parser.tab.c"
    break;

  case 56: /* Relacional: DIF  */
#line 343 "./syntactic/parser.y"
             {
        yyval = newExpNode(OpK);
        yyval->attr.op = DIF;
        yyval->lineno = lineno;
    }
#line 1751 "parser.tab.c"
    break;

  case 57: /* SomaExp: SomaExp Soma Termo  */
#line 351 "./syntactic/parser.y"
                       {
        yyval = yyvsp[-1];
        yyval->lineno = lineno;
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1762 "parser.tab.c"
    break;

  case 58: /* SomaExp: Termo  */
#line 356 "./syntactic/parser.y"
              { yyval = yyvsp[0]; }
#line 1768 "parser.tab.c"
    break;

  case 59: /* Soma: SOM  */
#line 360 "./syntactic/parser.y"
        {
        yyval = newExpNode(OpK);
        yyval->attr.op = SOM;
        yyval->lineno = lineno;
    }
#line 1778 "parser.tab.c"
    break;

  case 60: /* Soma: SUB  */
#line 364 "./syntactic/parser.y"
            {
        yyval = newExpNode(OpK);
        yyval->attr.op = SUB;
        yyval->lineno = lineno;
    }
#line 1788 "parser.tab.c"
    break;

  case 61: /* Termo: Termo Mult Fator  */
#line 372 "./syntactic/parser.y"
                     {
        yyval = yyvsp[-1];
        yyval->lineno = lineno;
        yyval->child[0] = yyvsp[-2];
        yyval->child[1] = yyvsp[0];
    }
#line 1799 "parser.tab.c"
    break;

  case 62: /* Termo: Fator  */
#line 377 "./syntactic/parser.y"
              { yyval = yyvsp[0]; }
#line 1805 "parser.tab.c"
    break;

  case 63: /* Mult: MUL  */
#line 381 "./syntactic/parser.y"
        {
        yyval = newExpNode(OpK);
        yyval->attr.op = MUL;
        yyval->lineno = lineno;
    }
#line 1815 "parser.tab.c"
    break;

  case 64: /* Mult: DIV  */
#line 385 "./syntactic/parser.y"
            {
        yyval = newExpNode(OpK);
        yyval->attr.op = DIV;
        yyval->lineno = lineno;
    }
#line 1825 "parser.tab.c"
    break;

  case 65: /* Fator: APA Exp FPA  */
#line 393 "./syntactic/parser.y"
                { yyval = yyvsp[-1]; }
#line 1831 "parser.tab.c"
    break;

  case 66: /* Fator: Var  */
#line 394 "./syntactic/parser.y"
          { yyval = yyvsp[0]; }
#line 1837 "parser.tab.c"
    break;

  case 67: /* Fator: Ativacao  */
#line 395 "./syntactic/parser.y"
               { yyval = yyvsp[0]; }
#line 1843 "parser.tab.c"
    break;

  case 68: /* Fator: NUM  */
#line 396 "./syntactic/parser.y"
          {
        yyval = newExpNode(ConstK);
        yyval->attr.name = copyString(yytext);
        yyval->attr.val = atoi(yytext);
        yyval->type = INT_TYPE;
    }
#line 1854 "parser.tab.c"
    break;

  case 69: /* Ativacao: funID APA ArgLista FPA  */
#line 405 "./syntactic/parser.y"
                           {
        yyval = newExpNode(AtivK);
        yyval->attr.name = yyvsp[-3]->attr.name;
        yyval->kind.exp = AtivK;
        yyval->lineno = lineno;
        yyval->child[0] = yyvsp[-1];
    }
#line 1866 "parser.tab.c"
    break;

  case 70: /* Ativacao: funID APA FPA  */
#line 411 "./syntactic/parser.y"
                      {
        yyval = newExpNode(AtivK);
        yyval->attr.name = yyvsp[-2]->attr.name;
        yyval->kind.exp = AtivK;
        yyval->lineno = lineno;
    }
#line 1877 "parser.tab.c"
    break;

  case 71: /* ArgLista: ArgLista VIR Exp  */
#line 420 "./syntactic/parser.y"
                     {
        YYSTYPE t = yyvsp[-2];
        if (t != NULL){
            while (t->sibling != NULL)
                t = t->sibling;
            t->sibling = yyvsp[0];
            yyval = yyvsp[-2];
        }
        else yyval = yyvsp[0];
    }
#line 1892 "parser.tab.c"
    break;

  case 72: /* ArgLista: Exp  */
#line 429 "./syntactic/parser.y"
            { yyval = yyvsp[0]; }
#line 1898 "parser.tab.c"
    break;


#line 1902 "parser.tab.c"

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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 432 "./syntactic/parser.y"


// Função para tratamento de erros sintaticos
void yyerror(const char *s) {
    fprintf(stderr, "ERRO SINTÁTICO: '%s' LINHA: %d\n", yytext, lineno);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    yyin = file;  // Redefine yyin para o arquivo

    printf("Analisando o arquivo: %s\n", argv[1]);
    int parse_result = yyparse();  // Chama o analisador gerado pelo Bison

    fclose(file);  // Fecha o arquivo após a análise

    // Verifica o resultado da análise
    if (parse_result == 0) {
        printf("Análise sintática bem-sucedida! A sintaxe está correta.\n");
        printTree(arvoreSintatica);
        printf("\n");
        buildSymtab(arvoreSintatica);
    } else {
        printf("Erro na análise sintática.\n");
    }

    printf("Gerando código intermediário...\n");
    codeGen(arvoreSintatica);

    return 0;
}
