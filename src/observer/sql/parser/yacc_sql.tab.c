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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"


#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.tab.h"
#include "sql/parser/lex.yy.h"
// #include "common/log/log.h" // 包含C++中的头文件

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ParserContext {
  Query * ssql;
  size_t select_length;
  size_t condition_length;
  size_t from_length;
  size_t value_length;
  Value values[MAX_NUM];
  Condition conditions[MAX_NUM];
  CompOp comp;
	char id[MAX_NUM];
} ParserContext;

//获取子串
char *substr(const char *s,int n1,int n2)/*从s中提取下标为n1~n2的字符组成一个新字符串，然后返回这个新串的首地址*/
{
  char *sp = malloc(sizeof(char) * (n2 - n1 + 2));
  int i, j = 0;
  for (i = n1; i <= n2; i++) {
    sp[j++] = s[i];
  }
  sp[j] = 0;
  return sp;
}

ParserContext *get_context(yyscan_t scanner)
{
  return (ParserContext *)yyget_extra(scanner);
}

#define CONTEXT get_context(scanner)

void yyerror(yyscan_t scanner, const char *str)
{
  ParserContext *context = CONTEXT;
  query_reset(context->ssql);
  context->ssql->flag = SCF_ERROR;
  context->condition_length = 0;
  context->from_length = 0;
  context->select_length = 0;
  context->value_length = 0;
  context->ssql->sstr.insertion.value_num = 0;
  printf("parse sql failed. error=%s", str);
}



#define set_flag(a) do{if(CONTEXT->ssql->flag!=SCF_ERROR) CONTEXT->ssql->flag=a;}while(0);
#define set_agg(a) do{CONTEXT->ssql->sstr.selection.attributes[CONTEXT->ssql->sstr.selection.attr_num-1].aggregate_type = a;}while(0);


#line 133 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"

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

#include "yacc_sql.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_GROUP = 4,                      /* GROUP  */
  YYSYMBOL_BY = 5,                         /* BY  */
  YYSYMBOL_MIN = 6,                        /* MIN  */
  YYSYMBOL_MAX = 7,                        /* MAX  */
  YYSYMBOL_AVG = 8,                        /* AVG  */
  YYSYMBOL_COUNT = 9,                      /* COUNT  */
  YYSYMBOL_CREATE = 10,                    /* CREATE  */
  YYSYMBOL_DROP = 11,                      /* DROP  */
  YYSYMBOL_TABLE = 12,                     /* TABLE  */
  YYSYMBOL_TABLES = 13,                    /* TABLES  */
  YYSYMBOL_INDEX = 14,                     /* INDEX  */
  YYSYMBOL_SELECT = 15,                    /* SELECT  */
  YYSYMBOL_DESC = 16,                      /* DESC  */
  YYSYMBOL_SHOW = 17,                      /* SHOW  */
  YYSYMBOL_SYNC = 18,                      /* SYNC  */
  YYSYMBOL_INSERT = 19,                    /* INSERT  */
  YYSYMBOL_DELETE = 20,                    /* DELETE  */
  YYSYMBOL_UPDATE = 21,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 22,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 23,                    /* RBRACE  */
  YYSYMBOL_COMMA = 24,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 25,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 26,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 27,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 28,                     /* INT_T  */
  YYSYMBOL_STRING_T = 29,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 30,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 31,                    /* DATE_T  */
  YYSYMBOL_HELP = 32,                      /* HELP  */
  YYSYMBOL_EXIT = 33,                      /* EXIT  */
  YYSYMBOL_DOT = 34,                       /* DOT  */
  YYSYMBOL_INTO = 35,                      /* INTO  */
  YYSYMBOL_VALUES = 36,                    /* VALUES  */
  YYSYMBOL_FROM = 37,                      /* FROM  */
  YYSYMBOL_WHERE = 38,                     /* WHERE  */
  YYSYMBOL_AND = 39,                       /* AND  */
  YYSYMBOL_SET = 40,                       /* SET  */
  YYSYMBOL_ON = 41,                        /* ON  */
  YYSYMBOL_LOAD = 42,                      /* LOAD  */
  YYSYMBOL_DATA = 43,                      /* DATA  */
  YYSYMBOL_INFILE = 44,                    /* INFILE  */
  YYSYMBOL_EQ = 45,                        /* EQ  */
  YYSYMBOL_LT = 46,                        /* LT  */
  YYSYMBOL_GT = 47,                        /* GT  */
  YYSYMBOL_LE = 48,                        /* LE  */
  YYSYMBOL_GE = 49,                        /* GE  */
  YYSYMBOL_NE = 50,                        /* NE  */
  YYSYMBOL_NUMBER = 51,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 52,                     /* FLOAT  */
  YYSYMBOL_ID = 53,                        /* ID  */
  YYSYMBOL_PATH = 54,                      /* PATH  */
  YYSYMBOL_SSS = 55,                       /* SSS  */
  YYSYMBOL_STAR = 56,                      /* STAR  */
  YYSYMBOL_STRING_V = 57,                  /* STRING_V  */
  YYSYMBOL_NODOT = 58,                     /* NODOT  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_commands = 60,                  /* commands  */
  YYSYMBOL_command = 61,                   /* command  */
  YYSYMBOL_exit = 62,                      /* exit  */
  YYSYMBOL_help = 63,                      /* help  */
  YYSYMBOL_sync = 64,                      /* sync  */
  YYSYMBOL_begin = 65,                     /* begin  */
  YYSYMBOL_commit = 66,                    /* commit  */
  YYSYMBOL_rollback = 67,                  /* rollback  */
  YYSYMBOL_drop_table = 68,                /* drop_table  */
  YYSYMBOL_show_tables = 69,               /* show_tables  */
  YYSYMBOL_desc_table = 70,                /* desc_table  */
  YYSYMBOL_create_index = 71,              /* create_index  */
  YYSYMBOL_drop_index = 72,                /* drop_index  */
  YYSYMBOL_create_table = 73,              /* create_table  */
  YYSYMBOL_attr_def_list = 74,             /* attr_def_list  */
  YYSYMBOL_attr_def = 75,                  /* attr_def  */
  YYSYMBOL_number = 76,                    /* number  */
  YYSYMBOL_type = 77,                      /* type  */
  YYSYMBOL_ID_get = 78,                    /* ID_get  */
  YYSYMBOL_insert = 79,                    /* insert  */
  YYSYMBOL_value_list = 80,                /* value_list  */
  YYSYMBOL_value = 81,                     /* value  */
  YYSYMBOL_delete = 82,                    /* delete  */
  YYSYMBOL_update = 83,                    /* update  */
  YYSYMBOL_select = 84,                    /* select  */
  YYSYMBOL_group = 85,                     /* group  */
  YYSYMBOL_select_attr = 86,               /* select_attr  */
  YYSYMBOL_agg_type = 87,                  /* agg_type  */
  YYSYMBOL_attr_list = 88,                 /* attr_list  */
  YYSYMBOL_rel_list = 89,                  /* rel_list  */
  YYSYMBOL_where = 90,                     /* where  */
  YYSYMBOL_condition_list = 91,            /* condition_list  */
  YYSYMBOL_condition = 92,                 /* condition  */
  YYSYMBOL_comOp = 93,                     /* comOp  */
  YYSYMBOL_load_data = 94                  /* load_data  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   193

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  205

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   313


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   148,   148,   150,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   177,   182,   187,   193,   199,   205,   211,   217,
     223,   230,   238,   245,   254,   256,   260,   271,   284,   287,
     288,   289,   290,   293,   302,   318,   320,   325,   328,   331,
     339,   349,   359,   377,   379,   382,   390,   395,   401,   406,
     412,   417,   423,   428,   437,   440,   443,   446,   451,   453,
     458,   464,   469,   475,   480,   489,   491,   495,   497,   501,
     503,   508,   529,   549,   569,   591,   612,   633,   655,   656,
     657,   658,   659,   660,   665
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "GROUP",
  "BY", "MIN", "MAX", "AVG", "COUNT", "CREATE", "DROP", "TABLE", "TABLES",
  "INDEX", "SELECT", "DESC", "SHOW", "SYNC", "INSERT", "DELETE", "UPDATE",
  "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK",
  "INT_T", "STRING_T", "FLOAT_T", "DATE_T", "HELP", "EXIT", "DOT", "INTO",
  "VALUES", "FROM", "WHERE", "AND", "SET", "ON", "LOAD", "DATA", "INFILE",
  "EQ", "LT", "GT", "LE", "GE", "NE", "NUMBER", "FLOAT", "ID", "PATH",
  "SSS", "STAR", "STRING_V", "NODOT", "$accept", "commands", "command",
  "exit", "help", "sync", "begin", "commit", "rollback", "drop_table",
  "show_tables", "desc_table", "create_index", "drop_index",
  "create_table", "attr_def_list", "attr_def", "number", "type", "ID_get",
  "insert", "value_list", "value", "delete", "update", "select", "group",
  "select_attr", "agg_type", "attr_list", "rel_list", "where",
  "condition_list", "condition", "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-112)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -112,    73,  -112,    24,    83,    89,    -1,   -27,    36,    33,
       2,    17,     5,    72,    77,    84,    93,    99,    26,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,    51,    54,
      55,    56,  -112,  -112,  -112,  -112,     0,  -112,    49,    98,
     122,   124,  -112,    75,    76,    90,  -112,  -112,  -112,  -112,
    -112,    87,   110,    92,   131,   132,     7,     3,  -112,    85,
      14,  -112,  -112,   100,   101,    88,    82,    91,    94,  -112,
    -112,     1,   118,   119,   119,   121,   -14,   123,   120,    -5,
     145,   104,   115,  -112,   127,    12,   130,    15,  -112,   102,
    -112,  -112,   103,   101,   119,    23,  -112,   -33,  -112,  -112,
     -17,  -112,    16,   114,  -112,   -33,   142,    91,   134,  -112,
    -112,  -112,  -112,   136,   106,   119,   119,   -13,   121,   156,
    -112,   138,   139,   140,   112,  -112,  -112,  -112,  -112,  -112,
    -112,    61,    66,    -5,  -112,   101,   113,   127,   160,   116,
     146,  -112,  -112,   119,    29,  -112,   163,   167,   119,   119,
     -33,   148,    16,  -112,  -112,   141,  -112,   114,   169,   170,
    -112,  -112,  -112,   151,   173,  -112,   154,   155,   126,  -112,
    -112,  -112,   140,   177,    71,   128,  -112,  -112,  -112,  -112,
    -112,   119,   119,   149,  -112,  -112,   150,  -112,  -112,  -112,
    -112,   129,   133,  -112,  -112
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
      20,    19,    14,    15,    16,    17,     9,    10,    11,    12,
      13,     8,     5,     7,     6,     4,    18,    21,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    56,     0,     0,
       0,     0,    24,     0,     0,     0,    25,    26,    27,    23,
      22,     0,     0,     0,     0,     0,     0,     0,    58,     0,
       0,    30,    29,     0,    77,     0,     0,     0,     0,    28,
      32,    68,     0,    68,    68,    75,     0,     0,     0,     0,
       0,     0,     0,    43,    34,     0,     0,     0,    69,     0,
      60,    62,     0,    77,    68,     0,    57,     0,    47,    48,
       0,    49,     0,    79,    50,     0,     0,     0,     0,    39,
      40,    41,    42,    37,     0,    68,    68,     0,    75,    53,
      59,     0,     0,    45,     0,    88,    89,    90,    91,    92,
      93,     0,     0,     0,    78,    77,     0,    34,     0,     0,
       0,    71,    73,    68,     0,    76,     0,     0,    68,    68,
       0,     0,     0,    83,    81,    84,    82,    79,     0,     0,
      35,    33,    38,     0,     0,    70,     0,     0,     0,    52,
      61,    63,    45,     0,     0,     0,    80,    51,    94,    36,
      31,    68,    68,    54,    46,    44,     0,    85,    86,    72,
      74,     0,     0,    55,    87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,    38,    70,  -112,  -112,  -112,
    -112,     6,  -103,  -112,  -112,  -112,  -112,  -112,   125,   -81,
      62,   -92,    22,    50,  -111,  -112
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   118,    94,   173,   123,    95,
      32,   161,   112,    33,    34,    35,   157,    48,    49,    68,
     103,    90,   144,   113,   141,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      98,   142,   100,   101,   133,    42,    43,    44,    45,   104,
     153,   129,   145,    42,    43,    44,    45,   134,   108,   109,
     105,   154,   111,   130,    66,    66,    50,    37,   135,   136,
     137,   138,   139,   140,    67,    97,    52,    53,   164,   166,
     119,   120,   121,   122,   151,   152,   108,   109,   110,    51,
     111,   184,    46,   168,    54,    47,    83,   182,    55,    84,
      81,   135,   136,   137,   138,   139,   140,    86,   125,    61,
      87,   126,   175,     2,     3,    56,   131,   180,   181,   132,
      57,   197,   176,     4,     5,   177,    69,    58,     6,     7,
       8,     9,    10,    11,    12,    38,    59,    39,    13,    14,
      15,    40,    60,    41,    62,    16,    17,    63,    64,    65,
     199,   200,   108,   109,   163,    18,   111,   108,   109,   165,
      70,   111,   108,   109,   196,    71,   111,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    88,    92,    85,    89,
      99,    91,   107,    66,    93,   102,   106,    96,   114,   115,
     116,   117,   124,   143,   146,   127,   128,   148,   149,   150,
     156,   158,   159,   171,   160,   162,   169,   172,   178,   174,
     179,   183,   187,   188,   189,   185,   190,   191,   192,   193,
     195,   198,   203,   201,   202,   170,   204,   147,   194,   186,
     155,    82,     0,   167
};

static const yytype_int16 yycheck[] =
{
      81,   112,    83,    84,   107,     6,     7,     8,     9,    23,
      23,   103,   115,     6,     7,     8,     9,    34,    51,    52,
      34,    34,    55,   104,    24,    24,    53,     3,    45,    46,
      47,    48,    49,    50,    34,    34,     3,    35,   141,   142,
      28,    29,    30,    31,   125,   126,    51,    52,    53,    13,
      55,   162,    53,   145,    37,    56,    53,   160,    53,    56,
      53,    45,    46,    47,    48,    49,    50,    53,    53,    43,
      56,    56,   153,     0,     1,     3,    53,   158,   159,    56,
       3,   184,    53,    10,    11,    56,    37,     3,    15,    16,
      17,    18,    19,    20,    21,    12,     3,    14,    25,    26,
      27,    12,     3,    14,    53,    32,    33,    53,    53,    53,
     191,   192,    51,    52,    53,    42,    55,    51,    52,    53,
      22,    55,    51,    52,    53,     3,    55,     3,    53,    53,
      40,    44,    22,    41,     3,     3,    36,    55,    53,    38,
      22,    53,    22,    24,    53,    24,    23,    53,     3,    45,
      35,    24,    22,    39,    12,    53,    53,    23,    22,    53,
       4,    23,    23,     3,    24,    53,    53,    51,     5,    23,
       3,    23,     3,     3,    23,    34,     3,    23,    23,    53,
       3,    53,    53,    34,    34,   147,    53,   117,   182,   167,
     128,    66,    -1,   143
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    60,     0,     1,    10,    11,    15,    16,    17,    18,
      19,    20,    21,    25,    26,    27,    32,    33,    42,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    79,    82,    83,    84,    94,     3,    12,    14,
      12,    14,     6,     7,     8,     9,    53,    56,    86,    87,
      53,    13,     3,    35,    37,    53,     3,     3,     3,     3,
       3,    43,    53,    53,    53,    53,    24,    34,    88,    37,
      22,     3,     3,    53,    53,    40,    44,    22,    41,     3,
       3,    53,    87,    53,    56,    53,    53,    56,    36,    38,
      90,    53,    55,    53,    75,    78,    53,    34,    88,    22,
      88,    88,    24,    89,    23,    34,    23,    22,    51,    52,
      53,    55,    81,    92,     3,    45,    35,    24,    74,    28,
      29,    30,    31,    77,    22,    53,    56,    53,    53,    90,
      88,    53,    56,    81,    34,    45,    46,    47,    48,    49,
      50,    93,    93,    39,    91,    81,    12,    75,    23,    22,
      53,    88,    88,    23,    34,    89,     4,    85,    23,    23,
      24,    80,    53,    53,    81,    53,    81,    92,    90,    53,
      74,     3,    51,    76,    23,    88,    53,    56,     5,     3,
      88,    88,    81,    23,    93,    34,    91,     3,     3,    23,
       3,    23,    23,    53,    80,     3,    53,    81,    53,    88,
      88,    34,    34,    53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    74,    75,    75,    76,    77,
      77,    77,    77,    78,    79,    80,    80,    81,    81,    81,
      82,    83,    84,    85,    85,    85,    86,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    87,    87,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    90,    90,    91,
      91,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     4,     3,
       3,     9,     4,     8,     0,     3,     5,     2,     1,     1,
       1,     1,     1,     1,     9,     0,     3,     1,     1,     1,
       5,     8,     8,     0,     3,     5,     1,     4,     2,     5,
       4,     7,     4,     7,     1,     1,     1,     1,     0,     3,
       6,     5,     8,     5,     8,     0,     3,     0,     3,     0,
       3,     3,     3,     3,     3,     5,     5,     7,     1,     1,
       1,     1,     1,     1,     8
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
        yyerror (scanner, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner);
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
                 int yyrule, void *scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *scanner)
{
  YY_USE (yyvaluep);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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
      yychar = yylex (&yylval, scanner);
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
  case 21: /* command: error SEMICOLON  */
#line 171 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                          {
		yyerror(scanner, "ERROR");
	}
#line 1359 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 22: /* exit: EXIT SEMICOLON  */
#line 177 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                   {
        set_flag(SCF_EXIT);//"exit";
    }
#line 1367 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 182 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                   {
        set_flag(SCF_HELP);//"help";
    }
#line 1375 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 187 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                   {
      set_flag(SCF_SYNC);
    }
#line 1383 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 193 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                        {
      set_flag(SCF_BEGIN);
    }
#line 1391 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 199 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                         {
      set_flag(SCF_COMMIT);
    }
#line 1399 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 205 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                           {
      set_flag(SCF_ROLLBACK);
    }
#line 1407 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 211 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                            {
        set_flag(SCF_DROP_TABLE);//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1416 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 217 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                          {
      set_flag(SCF_SHOW_TABLES);
    }
#line 1424 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 30: /* desc_table: DESC ID SEMICOLON  */
#line 223 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                      {
      set_flag(SCF_DESC_TABLE);
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1433 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID RBRACE SEMICOLON  */
#line 231 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			set_flag(SCF_CREATE_INDEX);//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string));
		}
#line 1442 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 32: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 239 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			set_flag(SCF_DROP_INDEX);//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1451 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 33: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 246 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			set_flag(SCF_CREATE_TABLE);//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1463 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 35: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 256 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                   {    }
#line 1469 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 36: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 261 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[-3].number), (yyvsp[-1].number));
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name =(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type = $2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length = $4;
			CONTEXT->value_length++;
		}
#line 1484 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID_get type  */
#line 272 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			AttrInfo attribute;
			attr_info_init(&attribute, CONTEXT->id, (yyvsp[0].number), 4);
			create_table_append_attribute(&CONTEXT->ssql->sstr.create_table, &attribute);
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name=(char*)malloc(sizeof(char));
			// strcpy(CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].name, CONTEXT->id); 
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].type=$2;  
			// CONTEXT->ssql->sstr.create_table.attributes[CONTEXT->value_length].length=4; // default attribute length
			CONTEXT->value_length++;
		}
#line 1499 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 38: /* number: NUMBER  */
#line 284 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1505 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 39: /* type: INT_T  */
#line 287 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1511 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 40: /* type: STRING_T  */
#line 288 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1517 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 41: /* type: FLOAT_T  */
#line 289 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1523 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 42: /* type: DATE_T  */
#line 290 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                { (yyval.number)=DATES; }
#line 1529 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 43: /* ID_get: ID  */
#line 294 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1538 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 44: /* insert: INSERT INTO ID VALUES LBRACE value value_list RBRACE SEMICOLON  */
#line 303 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			// CONTEXT->values[CONTEXT->value_length++] = *$6;

			set_flag(SCF_INSERT);//"insert";
			// CONTEXT->ssql->sstr.insertion.relation_name = $3;
			// CONTEXT->ssql->sstr.insertion.value_num = CONTEXT->value_length;
			// for(i = 0; i < CONTEXT->value_length; i++){
			// 	CONTEXT->ssql->sstr.insertion.values[i] = CONTEXT->values[i];
      // }
			inserts_init(&CONTEXT->ssql->sstr.insertion, (yyvsp[-6].string), CONTEXT->values, CONTEXT->value_length);

      //临时变量清零
      CONTEXT->value_length=0;
    }
#line 1557 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 46: /* value_list: COMMA value value_list  */
#line 320 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1565 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 47: /* value: NUMBER  */
#line 325 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1573 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 48: /* value: FLOAT  */
#line 328 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1581 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 49: /* value: SSS  */
#line 331 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		 int ret = value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		 if(!ret) yyerror(scanner,"date");
		}
#line 1591 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 50: /* delete: DELETE FROM ID where SEMICOLON  */
#line 340 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			set_flag(SCF_DELETE);//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1603 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 51: /* update: UPDATE ID SET ID EQ value where SEMICOLON  */
#line 350 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			set_flag(SCF_UPDATE);//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1615 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 52: /* select: SELECT select_attr FROM ID rel_list where group SEMICOLON  */
#line 360 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-4].string));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			set_flag(SCF_SELECT);//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
	}
#line 1635 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 54: /* group: GROUP BY ID  */
#line 379 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                      {
		CONTEXT->ssql->sstr.selection.group_attr = strdup((yyvsp[0].string));
	}
#line 1643 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 55: /* group: GROUP BY ID DOT ID  */
#line 382 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                             {
		CONTEXT->ssql->sstr.selection.group_table = strdup((yyvsp[-2].string));
		CONTEXT->ssql->sstr.selection.group_attr = strdup((yyvsp[0].string));
	}
#line 1652 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 56: /* select_attr: STAR  */
#line 390 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1662 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 57: /* select_attr: agg_type LBRACE STAR RBRACE  */
#line 395 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                  {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-3].number));
		}
#line 1673 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 58: /* select_attr: ID attr_list  */
#line 401 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1683 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 59: /* select_attr: agg_type LBRACE ID RBRACE attr_list  */
#line 406 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-4].number));
		}
#line 1694 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 60: /* select_attr: ID DOT ID attr_list  */
#line 412 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1704 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 61: /* select_attr: agg_type LBRACE ID DOT ID RBRACE attr_list  */
#line 417 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-6].number));
		}
#line 1715 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 62: /* select_attr: ID DOT STAR attr_list  */
#line 423 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1725 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 63: /* select_attr: agg_type LBRACE ID DOT STAR RBRACE attr_list  */
#line 428 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                       {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-6].number));
		}
#line 1736 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 64: /* agg_type: MIN  */
#line 437 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
            {
		(yyval.number) = MIN_AGG;
	}
#line 1744 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 65: /* agg_type: MAX  */
#line 440 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
              {
		(yyval.number) = MAX_AGG;
	}
#line 1752 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 66: /* agg_type: AVG  */
#line 443 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
              {
		(yyval.number) = AVG_AGG;
	}
#line 1760 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 67: /* agg_type: COUNT  */
#line 446 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
		(yyval.number) = CNT_AGG;
	}
#line 1768 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 69: /* attr_list: COMMA ID attr_list  */
#line 453 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1778 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 70: /* attr_list: COMMA agg_type LBRACE ID RBRACE attr_list  */
#line 458 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-4].number));
		}
#line 1789 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 71: /* attr_list: COMMA ID DOT ID attr_list  */
#line 464 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1799 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 72: /* attr_list: COMMA agg_type LBRACE ID DOT ID RBRACE attr_list  */
#line 469 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                           {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-6].number));
		}
#line 1810 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 73: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 475 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1820 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 74: /* attr_list: COMMA agg_type LBRACE ID DOT STAR RBRACE attr_list  */
#line 480 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                             {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-6].number));
		}
#line 1831 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 76: /* rel_list: COMMA ID rel_list  */
#line 491 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 1839 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 78: /* where: WHERE condition condition_list  */
#line 497 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 1847 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 80: /* condition_list: AND condition condition_list  */
#line 503 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 1855 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 81: /* condition: ID comOp value  */
#line 509 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));

			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name = NULL;
			// $$->left_attr.attribute_name= $1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 1880 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 82: /* condition: value comOp value  */
#line 530 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 2];
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$ = ( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 0;
			// $$->right_attr.relation_name = NULL;
			// $$->right_attr.attribute_name = NULL;
			// $$->right_value = *$3;

		}
#line 1904 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 83: /* condition: ID comOp ID  */
#line 550 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, NULL, (yyvsp[-2].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=$1;
			// $$->comp = CONTEXT->comp;
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;

		}
#line 1928 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 84: /* condition: value comOp ID  */
#line 570 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];
			RelAttr right_attr;
			relation_attr_init(&right_attr, NULL, (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp=CONTEXT->comp;
			
			// $$->right_is_attr = 1;
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=$3;
		
		}
#line 1954 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 85: /* condition: ID DOT ID comOp value  */
#line 592 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-4].string), (yyvsp[-2].string));
			Value *right_value = &CONTEXT->values[CONTEXT->value_length - 1];

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 0, NULL, right_value);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;

			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp=CONTEXT->comp;
			// $$->right_is_attr = 0;   //属性值
			// $$->right_attr.relation_name=NULL;
			// $$->right_attr.attribute_name=NULL;
			// $$->right_value =*$5;			
							
    }
#line 1979 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 86: /* condition: value comOp ID DOT ID  */
#line 613 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			Value *left_value = &CONTEXT->values[CONTEXT->value_length - 1];

			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 0, NULL, left_value, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 0;//属性值
			// $$->left_attr.relation_name=NULL;
			// $$->left_attr.attribute_name=NULL;
			// $$->left_value = *$1;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;//属性
			// $$->right_attr.relation_name = $3;
			// $$->right_attr.attribute_name = $5;
									
    }
#line 2004 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 87: /* condition: ID DOT ID comOp ID DOT ID  */
#line 634 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			RelAttr left_attr;
			relation_attr_init(&left_attr, (yyvsp[-6].string), (yyvsp[-4].string));
			RelAttr right_attr;
			relation_attr_init(&right_attr, (yyvsp[-2].string), (yyvsp[0].string));

			Condition condition;
			condition_init(&condition, CONTEXT->comp, 1, &left_attr, NULL, 1, &right_attr, NULL);
			CONTEXT->conditions[CONTEXT->condition_length++] = condition;
			// $$=( Condition *)malloc(sizeof( Condition));
			// $$->left_is_attr = 1;		//属性
			// $$->left_attr.relation_name=$1;
			// $$->left_attr.attribute_name=$3;
			// $$->comp =CONTEXT->comp;
			// $$->right_is_attr = 1;		//属性
			// $$->right_attr.relation_name=$5;
			// $$->right_attr.attribute_name=$7;
    }
#line 2027 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 88: /* comOp: EQ  */
#line 655 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2033 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 89: /* comOp: LT  */
#line 656 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2039 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 90: /* comOp: GT  */
#line 657 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2045 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 91: /* comOp: LE  */
#line 658 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2051 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 92: /* comOp: GE  */
#line 659 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2057 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 93: /* comOp: NE  */
#line 660 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2063 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 94: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 666 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
		  set_flag(SCF_LOAD_DATA);
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2072 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;


#line 2076 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"

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
      yyerror (scanner, YY_("syntax error"));
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
                      yytoken, &yylval, scanner);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner);
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
  yyerror (scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 671 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, Query *sqls){
	ParserContext context;
	memset(&context, 0, sizeof(context));

	yyscan_t scanner;
	yylex_init_extra(&context, &scanner);
	context.ssql = sqls;
	context.ssql->flag = SCF_SELECT;
	scan_string(s, scanner);
	int result = yyparse(scanner);
	yylex_destroy(scanner);
	return result;
}
