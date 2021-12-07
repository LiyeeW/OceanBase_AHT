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
  YYSYMBOL_ORDER = 16,                     /* ORDER  */
  YYSYMBOL_ASC = 17,                       /* ASC  */
  YYSYMBOL_DESC = 18,                      /* DESC  */
  YYSYMBOL_SHOW = 19,                      /* SHOW  */
  YYSYMBOL_SYNC = 20,                      /* SYNC  */
  YYSYMBOL_INSERT = 21,                    /* INSERT  */
  YYSYMBOL_DELETE = 22,                    /* DELETE  */
  YYSYMBOL_UPDATE = 23,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 24,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 25,                    /* RBRACE  */
  YYSYMBOL_COMMA = 26,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 27,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 28,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 29,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 30,                     /* INT_T  */
  YYSYMBOL_STRING_T = 31,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 32,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 33,                    /* DATE_T  */
  YYSYMBOL_HELP = 34,                      /* HELP  */
  YYSYMBOL_EXIT = 35,                      /* EXIT  */
  YYSYMBOL_DOT = 36,                       /* DOT  */
  YYSYMBOL_INTO = 37,                      /* INTO  */
  YYSYMBOL_VALUES = 38,                    /* VALUES  */
  YYSYMBOL_FROM = 39,                      /* FROM  */
  YYSYMBOL_WHERE = 40,                     /* WHERE  */
  YYSYMBOL_AND = 41,                       /* AND  */
  YYSYMBOL_SET = 42,                       /* SET  */
  YYSYMBOL_ON = 43,                        /* ON  */
  YYSYMBOL_LOAD = 44,                      /* LOAD  */
  YYSYMBOL_DATA = 45,                      /* DATA  */
  YYSYMBOL_INFILE = 46,                    /* INFILE  */
  YYSYMBOL_EQ = 47,                        /* EQ  */
  YYSYMBOL_LT = 48,                        /* LT  */
  YYSYMBOL_GT = 49,                        /* GT  */
  YYSYMBOL_LE = 50,                        /* LE  */
  YYSYMBOL_GE = 51,                        /* GE  */
  YYSYMBOL_NE = 52,                        /* NE  */
  YYSYMBOL_NUMBER = 53,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 54,                     /* FLOAT  */
  YYSYMBOL_ID = 55,                        /* ID  */
  YYSYMBOL_PATH = 56,                      /* PATH  */
  YYSYMBOL_SSS = 57,                       /* SSS  */
  YYSYMBOL_STAR = 58,                      /* STAR  */
  YYSYMBOL_STRING_V = 59,                  /* STRING_V  */
  YYSYMBOL_NODOT = 60,                     /* NODOT  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_commands = 62,                  /* commands  */
  YYSYMBOL_command = 63,                   /* command  */
  YYSYMBOL_exit = 64,                      /* exit  */
  YYSYMBOL_help = 65,                      /* help  */
  YYSYMBOL_sync = 66,                      /* sync  */
  YYSYMBOL_begin = 67,                     /* begin  */
  YYSYMBOL_commit = 68,                    /* commit  */
  YYSYMBOL_rollback = 69,                  /* rollback  */
  YYSYMBOL_drop_table = 70,                /* drop_table  */
  YYSYMBOL_show_tables = 71,               /* show_tables  */
  YYSYMBOL_desc_table = 72,                /* desc_table  */
  YYSYMBOL_create_index = 73,              /* create_index  */
  YYSYMBOL_drop_index = 74,                /* drop_index  */
  YYSYMBOL_create_table = 75,              /* create_table  */
  YYSYMBOL_attr_def_list = 76,             /* attr_def_list  */
  YYSYMBOL_attr_def = 77,                  /* attr_def  */
  YYSYMBOL_number = 78,                    /* number  */
  YYSYMBOL_type = 79,                      /* type  */
  YYSYMBOL_ID_get = 80,                    /* ID_get  */
  YYSYMBOL_insert = 81,                    /* insert  */
  YYSYMBOL_value_list = 82,                /* value_list  */
  YYSYMBOL_value = 83,                     /* value  */
  YYSYMBOL_delete = 84,                    /* delete  */
  YYSYMBOL_update = 85,                    /* update  */
  YYSYMBOL_select = 86,                    /* select  */
  YYSYMBOL_order = 87,                     /* order  */
  YYSYMBOL_order_list = 88,                /* order_list  */
  YYSYMBOL_order_type = 89,                /* order_type  */
  YYSYMBOL_group = 90,                     /* group  */
  YYSYMBOL_group_list = 91,                /* group_list  */
  YYSYMBOL_select_attr = 92,               /* select_attr  */
  YYSYMBOL_agg_type = 93,                  /* agg_type  */
  YYSYMBOL_attr_list = 94,                 /* attr_list  */
  YYSYMBOL_rel_list = 95,                  /* rel_list  */
  YYSYMBOL_where = 96,                     /* where  */
  YYSYMBOL_condition_list = 97,            /* condition_list  */
  YYSYMBOL_condition = 98,                 /* condition  */
  YYSYMBOL_comOp = 99,                     /* comOp  */
  YYSYMBOL_load_data = 100                 /* load_data  */
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
#define YYLAST   227

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  233

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   151,   151,   153,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   180,   185,   190,   196,   202,   208,   214,   220,
     226,   233,   241,   248,   257,   259,   263,   274,   287,   290,
     291,   292,   293,   296,   305,   321,   323,   328,   331,   334,
     342,   352,   362,   380,   382,   386,   393,   395,   399,   407,
     408,   409,   412,   414,   417,   423,   425,   428,   435,   440,
     446,   451,   457,   462,   468,   473,   482,   485,   488,   491,
     496,   498,   503,   509,   514,   520,   525,   534,   536,   540,
     542,   546,   548,   553,   574,   594,   614,   636,   657,   678,
     700,   701,   702,   703,   704,   705,   710
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
  "INDEX", "SELECT", "ORDER", "ASC", "DESC", "SHOW", "SYNC", "INSERT",
  "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA", "TRX_BEGIN",
  "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T", "FLOAT_T", "DATE_T",
  "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM", "WHERE", "AND", "SET",
  "ON", "LOAD", "DATA", "INFILE", "EQ", "LT", "GT", "LE", "GE", "NE",
  "NUMBER", "FLOAT", "ID", "PATH", "SSS", "STAR", "STRING_V", "NODOT",
  "$accept", "commands", "command", "exit", "help", "sync", "begin",
  "commit", "rollback", "drop_table", "show_tables", "desc_table",
  "create_index", "drop_index", "create_table", "attr_def_list",
  "attr_def", "number", "type", "ID_get", "insert", "value_list", "value",
  "delete", "update", "select", "order", "order_list", "order_type",
  "group", "group_list", "select_attr", "agg_type", "attr_list",
  "rel_list", "where", "condition_list", "condition", "comOp", "load_data", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-177)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -177,    65,  -177,    19,    56,    77,    -2,   -31,    27,    44,
      32,    34,    -6,    78,    79,    93,    94,   105,    29,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,    61,    63,
      67,    72,  -177,  -177,  -177,  -177,    12,  -177,   106,   108,
     143,   145,  -177,    95,    96,   107,  -177,  -177,  -177,  -177,
    -177,   109,   128,   110,   151,   153,     4,    52,  -177,   102,
      83,  -177,  -177,   120,   119,   111,   103,   112,   113,  -177,
    -177,    15,   137,   136,   136,   138,     6,   140,   139,    60,
     166,   123,   134,  -177,   146,   104,   149,    84,  -177,   121,
    -177,  -177,   122,   119,   136,    85,  -177,    10,  -177,  -177,
     -22,  -177,    54,   133,  -177,    10,   163,   112,   154,  -177,
    -177,  -177,  -177,   156,   126,   136,   136,     7,   138,   174,
    -177,   157,   158,   159,   129,  -177,  -177,  -177,  -177,  -177,
    -177,    66,    71,    60,  -177,   119,   131,   146,   184,   135,
     164,  -177,  -177,   136,    89,  -177,   185,   175,   136,   136,
      10,   167,    54,  -177,  -177,   160,  -177,   133,   190,   191,
    -177,  -177,  -177,   170,   194,  -177,   173,   176,   144,   195,
     199,  -177,  -177,   159,   200,    76,   150,  -177,  -177,  -177,
    -177,  -177,   136,   136,    26,   152,  -177,  -177,  -177,   168,
    -177,  -177,  -177,  -177,   155,   161,  -177,     1,   162,    35,
     180,  -177,  -177,   165,   182,  -177,   169,  -177,  -177,    -1,
     171,  -177,   180,   182,     3,  -177,  -177,   172,   182,    -1,
    -177,   182,  -177
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
       0,     0,    76,    77,    78,    79,    80,    68,     0,     0,
       0,     0,    24,     0,     0,     0,    25,    26,    27,    23,
      22,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,    30,    29,     0,    89,     0,     0,     0,     0,    28,
      32,    80,     0,    80,    80,    87,     0,     0,     0,     0,
       0,     0,     0,    43,    34,     0,     0,     0,    81,     0,
      72,    74,     0,    89,    80,     0,    69,     0,    47,    48,
       0,    49,     0,    91,    50,     0,     0,     0,     0,    39,
      40,    41,    42,    37,     0,    80,    80,     0,    87,    62,
      71,     0,     0,    45,     0,   100,   101,   102,   103,   104,
     105,     0,     0,     0,    90,    89,     0,    34,     0,     0,
       0,    83,    85,    80,     0,    88,     0,    53,    80,    80,
       0,     0,     0,    95,    93,    96,    94,    91,     0,     0,
      35,    33,    38,     0,     0,    82,     0,     0,     0,     0,
       0,    73,    75,    45,     0,     0,     0,    92,    51,   106,
      36,    31,    80,    80,    65,     0,    52,    46,    44,     0,
      97,    98,    84,    86,     0,     0,    63,    59,     0,    65,
      65,    60,    61,     0,    56,    99,     0,    66,    64,    59,
       0,    54,    65,    56,    59,    67,    55,     0,    56,    59,
      57,    56,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,    62,    97,  -177,  -177,  -177,
    -177,    28,  -106,  -177,  -177,  -177,  -177,  -133,  -169,  -177,
    -176,  -177,   147,   -81,    87,   -88,    45,    75,  -104,  -177
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,   118,    94,   173,   123,    95,
      32,   161,   112,    33,    34,    35,   180,   221,   214,   157,
     206,    48,    49,    68,   103,    90,   144,   113,   141,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      98,   133,   100,   101,    42,    43,    44,    45,   142,   145,
      42,    43,    44,    45,   134,   129,   211,   212,   211,   212,
     211,   212,    37,   130,    50,   135,   136,   137,   138,   139,
     140,   104,   153,   217,   218,   164,   166,   213,    66,   227,
      51,    66,   105,   154,   151,   152,   225,    52,    67,    55,
     223,    97,   204,    46,   183,   228,    47,   168,   185,    81,
     231,   204,   205,   108,   109,     2,     3,   111,    38,    53,
      39,   216,   175,    54,    61,     4,     5,   181,   182,   200,
       6,    56,    57,     7,     8,     9,    10,    11,    12,    40,
     226,    41,    13,    14,    15,   230,    58,    59,   232,    16,
      17,   135,   136,   137,   138,   139,   140,    83,    60,    18,
      84,   202,   203,   108,   109,   110,    62,   111,    63,   108,
     109,   163,    64,   111,   108,   109,   165,    65,   111,   108,
     109,   199,    70,   111,   119,   120,   121,   122,    86,   125,
     131,    87,   126,   132,   176,    69,    71,   177,    72,    75,
      73,    74,    77,    78,    79,    76,    80,    85,    88,    89,
      92,    99,    66,   107,   102,   106,    91,    93,    96,   114,
     115,   116,   117,   124,   143,   146,   127,   128,   156,   148,
     149,   150,   158,   159,   162,   160,   169,   171,   172,   174,
     178,   179,   184,   188,   189,   190,   186,   191,   192,   194,
     195,   193,   196,   198,   208,   201,   204,   207,   220,   170,
     209,   197,   187,    82,   147,   155,   210,   215,   167,     0,
     219,     0,     0,     0,   222,     0,   224,   229
};

static const yytype_int16 yycheck[] =
{
      81,   107,    83,    84,     6,     7,     8,     9,   112,   115,
       6,     7,     8,     9,    36,   103,    17,    18,    17,    18,
      17,    18,     3,   104,    55,    47,    48,    49,    50,    51,
      52,    25,    25,   209,   210,   141,   142,    36,    26,    36,
      13,    26,    36,    36,   125,   126,   222,     3,    36,    55,
     219,    36,    26,    55,   160,   224,    58,   145,   162,    55,
     229,    26,    36,    53,    54,     0,     1,    57,    12,    37,
      14,    36,   153,    39,    45,    10,    11,   158,   159,   185,
      15,     3,     3,    18,    19,    20,    21,    22,    23,    12,
     223,    14,    27,    28,    29,   228,     3,     3,   231,    34,
      35,    47,    48,    49,    50,    51,    52,    55,     3,    44,
      58,   192,   193,    53,    54,    55,    55,    57,    55,    53,
      54,    55,    55,    57,    53,    54,    55,    55,    57,    53,
      54,    55,    24,    57,    30,    31,    32,    33,    55,    55,
      55,    58,    58,    58,    55,    39,     3,    58,     3,    42,
      55,    55,    24,    43,     3,    46,     3,    55,    38,    40,
      57,    24,    26,    24,    26,    25,    55,    55,    55,     3,
      47,    37,    26,    24,    41,    12,    55,    55,     4,    25,
      24,    55,    25,    25,    55,    26,    55,     3,    53,    25,
       5,    16,    25,     3,     3,    25,    36,     3,    25,    55,
       5,    25,     3,     3,    36,    55,    26,    55,    26,   147,
      55,   183,   167,    66,   117,   128,    55,    55,   143,    -1,
      55,    -1,    -1,    -1,    55,    -1,    55,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    62,     0,     1,    10,    11,    15,    18,    19,    20,
      21,    22,    23,    27,    28,    29,    34,    35,    44,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    81,    84,    85,    86,   100,     3,    12,    14,
      12,    14,     6,     7,     8,     9,    55,    58,    92,    93,
      55,    13,     3,    37,    39,    55,     3,     3,     3,     3,
       3,    45,    55,    55,    55,    55,    26,    36,    94,    39,
      24,     3,     3,    55,    55,    42,    46,    24,    43,     3,
       3,    55,    93,    55,    58,    55,    55,    58,    38,    40,
      96,    55,    57,    55,    77,    80,    55,    36,    94,    24,
      94,    94,    26,    95,    25,    36,    25,    24,    53,    54,
      55,    57,    83,    98,     3,    47,    37,    26,    76,    30,
      31,    32,    33,    79,    24,    55,    58,    55,    55,    96,
      94,    55,    58,    83,    36,    47,    48,    49,    50,    51,
      52,    99,    99,    41,    97,    83,    12,    77,    25,    24,
      55,    94,    94,    25,    36,    95,     4,    90,    25,    25,
      26,    82,    55,    55,    83,    55,    83,    98,    96,    55,
      76,     3,    53,    78,    25,    94,    55,    58,     5,    16,
      87,    94,    94,    83,    25,    99,    36,    97,     3,     3,
      25,     3,    25,    25,    55,     5,     3,    82,     3,    55,
      83,    55,    94,    94,    26,    36,    91,    55,    36,    55,
      55,    17,    18,    36,    89,    55,    36,    91,    91,    55,
      26,    88,    55,    89,    55,    91,    88,    36,    89,    55,
      88,    89,    88
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    76,    77,    77,    78,    79,
      79,    79,    79,    80,    81,    82,    82,    83,    83,    83,
      84,    85,    86,    87,    87,    87,    88,    88,    88,    89,
      89,    89,    90,    90,    90,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      99,    99,    99,    99,    99,    99,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     2,     2,     4,     3,
       3,     9,     4,     8,     0,     3,     5,     2,     1,     1,
       1,     1,     1,     1,     9,     0,     3,     1,     1,     1,
       5,     8,     9,     0,     5,     7,     0,     4,     6,     0,
       1,     1,     0,     4,     6,     0,     3,     5,     1,     4,
       2,     5,     4,     7,     4,     7,     1,     1,     1,     1,
       0,     3,     6,     5,     8,     5,     8,     0,     3,     0,
       3,     0,     3,     3,     3,     3,     3,     5,     5,     7,
       1,     1,     1,     1,     1,     1,     8
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
#line 174 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                          {
		yyerror(scanner, "ERROR");
	}
#line 1384 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 22: /* exit: EXIT SEMICOLON  */
#line 180 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                   {
        set_flag(SCF_EXIT);//"exit";
    }
#line 1392 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 23: /* help: HELP SEMICOLON  */
#line 185 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                   {
        set_flag(SCF_HELP);//"help";
    }
#line 1400 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 24: /* sync: SYNC SEMICOLON  */
#line 190 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                   {
      set_flag(SCF_SYNC);
    }
#line 1408 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 25: /* begin: TRX_BEGIN SEMICOLON  */
#line 196 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                        {
      set_flag(SCF_BEGIN);
    }
#line 1416 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 26: /* commit: TRX_COMMIT SEMICOLON  */
#line 202 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                         {
      set_flag(SCF_COMMIT);
    }
#line 1424 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 27: /* rollback: TRX_ROLLBACK SEMICOLON  */
#line 208 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                           {
      set_flag(SCF_ROLLBACK);
    }
#line 1432 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 28: /* drop_table: DROP TABLE ID SEMICOLON  */
#line 214 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                            {
        set_flag(SCF_DROP_TABLE);//"drop_table";
        drop_table_init(&CONTEXT->ssql->sstr.drop_table, (yyvsp[-1].string));
    }
#line 1441 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 29: /* show_tables: SHOW TABLES SEMICOLON  */
#line 220 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                          {
      set_flag(SCF_SHOW_TABLES);
    }
#line 1449 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 30: /* desc_table: DESC ID SEMICOLON  */
#line 226 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                      {
      set_flag(SCF_DESC_TABLE);
      desc_table_init(&CONTEXT->ssql->sstr.desc_table, (yyvsp[-1].string));
    }
#line 1458 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 31: /* create_index: CREATE INDEX ID ON ID LBRACE ID RBRACE SEMICOLON  */
#line 234 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			set_flag(SCF_CREATE_INDEX);//"create_index";
			create_index_init(&CONTEXT->ssql->sstr.create_index, (yyvsp[-6].string), (yyvsp[-4].string), (yyvsp[-2].string));
		}
#line 1467 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 32: /* drop_index: DROP INDEX ID SEMICOLON  */
#line 242 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			set_flag(SCF_DROP_INDEX);//"drop_index";
			drop_index_init(&CONTEXT->ssql->sstr.drop_index, (yyvsp[-1].string));
		}
#line 1476 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 33: /* create_table: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE SEMICOLON  */
#line 249 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			set_flag(SCF_CREATE_TABLE);//"create_table";
			// CONTEXT->ssql->sstr.create_table.attribute_count = CONTEXT->value_length;
			create_table_init_name(&CONTEXT->ssql->sstr.create_table, (yyvsp[-5].string));
			//临时变量清零	
			CONTEXT->value_length = 0;
		}
#line 1488 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 35: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 259 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                   {    }
#line 1494 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 36: /* attr_def: ID_get type LBRACE number RBRACE  */
#line 264 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
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
#line 1509 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 37: /* attr_def: ID_get type  */
#line 275 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
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
#line 1524 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 38: /* number: NUMBER  */
#line 287 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                       {(yyval.number) = (yyvsp[0].number);}
#line 1530 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 39: /* type: INT_T  */
#line 290 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
              { (yyval.number)=INTS; }
#line 1536 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 40: /* type: STRING_T  */
#line 291 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                  { (yyval.number)=CHARS; }
#line 1542 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 41: /* type: FLOAT_T  */
#line 292 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                 { (yyval.number)=FLOATS; }
#line 1548 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 42: /* type: DATE_T  */
#line 293 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                { (yyval.number)=DATES; }
#line 1554 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 43: /* ID_get: ID  */
#line 297 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
        {
		char *temp=(yyvsp[0].string); 
		snprintf(CONTEXT->id, sizeof(CONTEXT->id), "%s", temp);
	}
#line 1563 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 44: /* insert: INSERT INTO ID VALUES LBRACE value value_list RBRACE SEMICOLON  */
#line 306 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
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
#line 1582 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 46: /* value_list: COMMA value value_list  */
#line 323 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                              { 
  		// CONTEXT->values[CONTEXT->value_length++] = *$2;
	  }
#line 1590 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 47: /* value: NUMBER  */
#line 328 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
          {	
  		value_init_integer(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].number));
		}
#line 1598 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 48: /* value: FLOAT  */
#line 331 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
          {
  		value_init_float(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].floats));
		}
#line 1606 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 49: /* value: SSS  */
#line 334 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         {
			(yyvsp[0].string) = substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
  		 int ret = value_init_string(&CONTEXT->values[CONTEXT->value_length++], (yyvsp[0].string));
		 if(!ret) yyerror(scanner,"date");
		}
#line 1616 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 50: /* delete: DELETE FROM ID where SEMICOLON  */
#line 343 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			set_flag(SCF_DELETE);//"delete";
			deletes_init_relation(&CONTEXT->ssql->sstr.deletion, (yyvsp[-2].string));
			deletes_set_conditions(&CONTEXT->ssql->sstr.deletion, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;	
    }
#line 1628 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 51: /* update: UPDATE ID SET ID EQ value where SEMICOLON  */
#line 353 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			set_flag(SCF_UPDATE);//"update";
			Value *value = &CONTEXT->values[0];
			updates_init(&CONTEXT->ssql->sstr.update, (yyvsp[-6].string), (yyvsp[-4].string), value, 
					CONTEXT->conditions, CONTEXT->condition_length);
			CONTEXT->condition_length = 0;
		}
#line 1640 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 52: /* select: SELECT select_attr FROM ID rel_list where group order SEMICOLON  */
#line 363 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
			// CONTEXT->ssql->sstr.selection.relations[CONTEXT->from_length++]=$4;
			selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-5].string));

			selects_append_conditions(&CONTEXT->ssql->sstr.selection, CONTEXT->conditions, CONTEXT->condition_length);

			set_flag(SCF_SELECT);//"select";
			// CONTEXT->ssql->sstr.selection.attr_num = CONTEXT->select_length;

			//临时变量清零
			CONTEXT->condition_length=0;
			CONTEXT->from_length=0;
			CONTEXT->select_length=0;
			CONTEXT->value_length = 0;
	}
#line 1660 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 54: /* order: ORDER BY ID order_type order_list  */
#line 382 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                            {
		CONTEXT->ssql->sstr.selection.order_type[CONTEXT->ssql->sstr.selection.order_num] = (yyvsp[-1].number);
		CONTEXT->ssql->sstr.selection.order_attr[CONTEXT->ssql->sstr.selection.order_num ++] = strdup((yyvsp[-2].string));
	}
#line 1669 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 55: /* order: ORDER BY ID DOT ID order_type order_list  */
#line 386 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                   {
		CONTEXT->ssql->sstr.selection.order_type[CONTEXT->ssql->sstr.selection.order_num] = (yyvsp[-1].number);
		CONTEXT->ssql->sstr.selection.order_table[CONTEXT->ssql->sstr.selection.order_num] = strdup((yyvsp[-4].string));
		CONTEXT->ssql->sstr.selection.order_attr[CONTEXT->ssql->sstr.selection.order_num ++] = strdup((yyvsp[-2].string));
	}
#line 1679 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 57: /* order_list: COMMA ID order_type order_list  */
#line 395 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                         {
		CONTEXT->ssql->sstr.selection.order_type[CONTEXT->ssql->sstr.selection.order_num] = (yyvsp[-1].number);
		CONTEXT->ssql->sstr.selection.order_attr[CONTEXT->ssql->sstr.selection.order_num ++] = strdup((yyvsp[-2].string));
	}
#line 1688 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 58: /* order_list: COMMA ID DOT ID order_type order_list  */
#line 399 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                {
		CONTEXT->ssql->sstr.selection.order_type[CONTEXT->ssql->sstr.selection.order_num] = (yyvsp[-1].number);
		CONTEXT->ssql->sstr.selection.order_table[CONTEXT->ssql->sstr.selection.order_num] = strdup((yyvsp[-4].string));
		CONTEXT->ssql->sstr.selection.order_attr[CONTEXT->ssql->sstr.selection.order_num ++] = strdup((yyvsp[-2].string));
	}
#line 1698 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 59: /* order_type: %empty  */
#line 407 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
        {(yyval.number)=0;}
#line 1704 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 60: /* order_type: ASC  */
#line 408 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
              {(yyval.number)=0;}
#line 1710 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 61: /* order_type: DESC  */
#line 409 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
               {(yyval.number)=1;}
#line 1716 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 63: /* group: GROUP BY ID group_list  */
#line 414 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                 {
		CONTEXT->ssql->sstr.selection.group_attr[CONTEXT->ssql->sstr.selection.group_num ++] = strdup((yyvsp[-1].string));
	}
#line 1724 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 64: /* group: GROUP BY ID DOT ID group_list  */
#line 417 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                        {
		CONTEXT->ssql->sstr.selection.group_table[CONTEXT->ssql->sstr.selection.group_num] = strdup((yyvsp[-3].string));
		CONTEXT->ssql->sstr.selection.group_attr[CONTEXT->ssql->sstr.selection.group_num ++] = strdup((yyvsp[-1].string));
	}
#line 1733 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 66: /* group_list: COMMA ID group_list  */
#line 425 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                              {
		CONTEXT->ssql->sstr.selection.group_attr[CONTEXT->ssql->sstr.selection.group_num ++] = strdup((yyvsp[-1].string));
	}
#line 1741 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 67: /* group_list: COMMA ID DOT ID group_list  */
#line 428 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                     {
		CONTEXT->ssql->sstr.selection.group_table[CONTEXT->ssql->sstr.selection.group_num] = strdup((yyvsp[-3].string));
		CONTEXT->ssql->sstr.selection.group_attr[CONTEXT->ssql->sstr.selection.group_num ++] = strdup((yyvsp[-1].string));
	}
#line 1750 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 68: /* select_attr: STAR  */
#line 435 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1760 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 69: /* select_attr: agg_type LBRACE STAR RBRACE  */
#line 440 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                  {  
			RelAttr attr;
			relation_attr_init(&attr, NULL, "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-3].number));
		}
#line 1771 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 70: /* select_attr: ID attr_list  */
#line 446 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                   {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1781 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 71: /* select_attr: agg_type LBRACE ID RBRACE attr_list  */
#line 451 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                          {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-4].number));
		}
#line 1792 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 72: /* select_attr: ID DOT ID attr_list  */
#line 457 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                              {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1802 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 73: /* select_attr: agg_type LBRACE ID DOT ID RBRACE attr_list  */
#line 462 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                     {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-6].number));
		}
#line 1813 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 74: /* select_attr: ID DOT STAR attr_list  */
#line 468 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1823 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 75: /* select_attr: agg_type LBRACE ID DOT STAR RBRACE attr_list  */
#line 473 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                       {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-6].number));
		}
#line 1834 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 76: /* agg_type: MIN  */
#line 482 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
            {
		(yyval.number) = MIN_AGG;
	}
#line 1842 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 77: /* agg_type: MAX  */
#line 485 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
              {
		(yyval.number) = MAX_AGG;
	}
#line 1850 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 78: /* agg_type: AVG  */
#line 488 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
              {
		(yyval.number) = AVG_AGG;
	}
#line 1858 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 79: /* agg_type: COUNT  */
#line 491 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
		(yyval.number) = CNT_AGG;
	}
#line 1866 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 81: /* attr_list: COMMA ID attr_list  */
#line 498 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                         {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1876 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 82: /* attr_list: COMMA agg_type LBRACE ID RBRACE attr_list  */
#line 503 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                {
			RelAttr attr;
			relation_attr_init(&attr, NULL, (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-4].number));
		}
#line 1887 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 83: /* attr_list: COMMA ID DOT ID attr_list  */
#line 509 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                    {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), (yyvsp[-1].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1897 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 84: /* attr_list: COMMA agg_type LBRACE ID DOT ID RBRACE attr_list  */
#line 514 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                           {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), (yyvsp[-2].string));
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-6].number));
		}
#line 1908 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 85: /* attr_list: COMMA ID DOT STAR attr_list  */
#line 520 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                      {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-3].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
		}
#line 1918 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 86: /* attr_list: COMMA agg_type LBRACE ID DOT STAR RBRACE attr_list  */
#line 525 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                                             {
			RelAttr attr;
			relation_attr_init(&attr, (yyvsp[-4].string), "*");
			selects_append_attribute(&CONTEXT->ssql->sstr.selection, &attr);
			set_agg((yyvsp[-6].number));
		}
#line 1929 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 88: /* rel_list: COMMA ID rel_list  */
#line 536 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                        {	
				selects_append_relation(&CONTEXT->ssql->sstr.selection, (yyvsp[-1].string));
		  }
#line 1937 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 90: /* where: WHERE condition condition_list  */
#line 542 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                     {	
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 1945 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 92: /* condition_list: AND condition condition_list  */
#line 548 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                                   {
				// CONTEXT->conditions[CONTEXT->condition_length++]=*$2;
			}
#line 1953 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 93: /* condition: ID comOp value  */
#line 554 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
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
#line 1978 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 94: /* condition: value comOp value  */
#line 575 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
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
#line 2002 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 95: /* condition: ID comOp ID  */
#line 595 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
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
#line 2026 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 96: /* condition: value comOp ID  */
#line 615 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
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
#line 2052 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 97: /* condition: ID DOT ID comOp value  */
#line 637 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
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
#line 2077 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 98: /* condition: value comOp ID DOT ID  */
#line 658 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
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
#line 2102 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 99: /* condition: ID DOT ID comOp ID DOT ID  */
#line 679 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
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
#line 2125 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 100: /* comOp: EQ  */
#line 700 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
             { CONTEXT->comp = EQUAL_TO; }
#line 2131 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 101: /* comOp: LT  */
#line 701 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_THAN; }
#line 2137 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 102: /* comOp: GT  */
#line 702 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_THAN; }
#line 2143 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 103: /* comOp: LE  */
#line 703 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = LESS_EQUAL; }
#line 2149 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 104: /* comOp: GE  */
#line 704 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = GREAT_EQUAL; }
#line 2155 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 105: /* comOp: NE  */
#line 705 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
         { CONTEXT->comp = NOT_EQUAL; }
#line 2161 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;

  case 106: /* load_data: LOAD DATA INFILE SSS INTO TABLE ID SEMICOLON  */
#line 711 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"
                {
		  set_flag(SCF_LOAD_DATA);
			load_data_init(&CONTEXT->ssql->sstr.load_data, (yyvsp[-1].string), (yyvsp[-4].string));
		}
#line 2170 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"
    break;


#line 2174 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.tab.c"

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

#line 716 "/home/liye/OceanBase_AHT/src/observer/sql/parser/yacc_sql.y"

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
