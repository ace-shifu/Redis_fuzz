/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         FF_STYPE
#define YYLTYPE         FF_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         ff_parse
#define yylex           ff_lex
#define yyerror         ff_error
#define yydebug         ff_debug
#define yynerrs         ff_nerrs

/* First part of user prologue.  */
#line 1 "bison.y"

#include "bison_parser.h"
#include "flex_lexer.h"
#include <stdio.h>
#include <string.h>
int yyerror(YYLTYPE* llocp, Program * result, yyscan_t scanner, const char *msg) { return 0; }

#line 85 "bison_parser.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_FF_BISON_PARSER_H_INCLUDED
# define YY_FF_BISON_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef FF_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define FF_DEBUG 1
#  else
#   define FF_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define FF_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined FF_DEBUG */
#if FF_DEBUG
extern int ff_debug;
#endif
/* "%code requires" blocks.  */
#line 8 "bison.y"

#include "../include/ast.h"
#include "parser_typedef.h"

#line 141 "bison_parser.cpp"

/* Token type.  */
#ifndef FF_TOKENTYPE
# define FF_TOKENTYPE
  enum ff_tokentype
  {
    SQL_DEL = 258,
    SQL_DUMP = 259,
    SQL_EXISTS = 260,
    SQL_EXPIRE = 261,
    SQL_EXPIREAT = 262,
    SQL_KEYS = 263,
    SQL_MIGRATE = 264,
    SQL_COPY = 265,
    SQL_REPLACE = 266,
    SQL_MOVE = 267,
    SQL_OBJECT = 268,
    SQL_REFCOUNT = 269,
    SQL_ENCODING = 270,
    SQL_IDLETIME = 271,
    SQL_PERSIST = 272,
    SQL_PEXPIRE = 273,
    SQL_PEXPIREAT = 274,
    SQL_PTTL = 275,
    SQL_RANDOMKEY = 276,
    SQL_RENAME = 277,
    SQL_RENAMENX = 278,
    SQL_RESTORE = 279,
    SQL_SORT = 280,
    SQL_GET = 281,
    SQL_STORE = 282,
    SQL_TTL = 283,
    SQL_TYPE = 284,
    SQL_APPEND = 285,
    SQL_BITCOUNT = 286,
    SQL_BITOP = 287,
    SQL_DECR = 288,
    SQL_DECRBY = 289,
    SQL_GETBIT = 290,
    SQL_GETRANGE = 291,
    SQL_GETSET = 292,
    SQL_INCR = 293,
    SQL_INCRBY = 294,
    SQL_INCRBYFLOAT = 295,
    SQL_MGET = 296,
    SQL_MSET = 297,
    SQL_MSETNX = 298,
    SQL_PSETEX = 299,
    SQL_SET = 300,
    SQL_AND = 301,
    SQL_OR = 302,
    SQL_XOR = 303,
    SQL_NOT = 304,
    SQL_BY = 305,
    SQL_LIMIT = 306,
    SQL_ASC = 307,
    SQL_DESC = 308,
    SQL_ALPHA = 309,
    SQL_EX = 310,
    SQL_PX = 311,
    SQL_NX = 312,
    SQL_XX = 313,
    SQL_SETBIT = 314,
    SQL_SETEX = 315,
    SQL_SETNX = 316,
    SQL_SETRANGE = 317,
    SQL_STRLEN = 318,
    SQL_BEFORE = 319,
    SQL_AFTER = 320,
    SQL_SUM = 321,
    SQL_MIN = 322,
    SQL_MAX = 323,
    SQL_HDEL = 324,
    SQL_HEXISTS = 325,
    SQL_HGET = 326,
    SQL_HGETALL = 327,
    SQL_HINCRBY = 328,
    SQL_HINCRBYFLOAT = 329,
    SQL_HKEYS = 330,
    SQL_HLEN = 331,
    SQL_HMGET = 332,
    SQL_HMSET = 333,
    SQL_HSET = 334,
    SQL_HSETNX = 335,
    SQL_HVALS = 336,
    SQL_LINDEX = 337,
    SQL_LINSERT = 338,
    SQL_LLEN = 339,
    SQL_LPOP = 340,
    SQL_LPUSH = 341,
    SQL_LPUSHX = 342,
    SQL_LRANGE = 343,
    SQL_LREM = 344,
    SQL_LSET = 345,
    SQL_LTRIM = 346,
    SQL_RPOP = 347,
    SQL_RPOPLPUSH = 348,
    SQL_RPUSH = 349,
    SQL_RPUSHX = 350,
    SQL_SADD = 351,
    SQL_SCARD = 352,
    SQL_SDIFF = 353,
    SQL_SDIFFSTORE = 354,
    SQL_SINTER = 355,
    SQL_SINTERSTORE = 356,
    SQL_SISMEMBER = 357,
    SQL_SMEMBERS = 358,
    SQL_SMOVE = 359,
    SQL_SPOP = 360,
    SQL_SRANDMEMBER = 361,
    SQL_SREM = 362,
    SQL_SUNION = 363,
    SQL_SUNIONSTORE = 364,
    SQL_ZADD = 365,
    SQL_ZCARD = 366,
    SQL_ZCOUNT = 367,
    SQL_ZINCRBY = 368,
    SQL_ZRANGE = 369,
    SQL_WITHSCORES = 370,
    SQL_ZRANGEBYSCORE = 371,
    SQL_ZRANK = 372,
    SQL_ZREM = 373,
    SQL_ZREMRANGEBYRANK = 374,
    SQL_ZREMRANGEBYSCORE = 375,
    SQL_ZREVRANGE = 376,
    SQL_ZREVRANGEBYSCORE = 377,
    SQL_ZREVRANK = 378,
    SQL_ZSCORE = 379,
    SQL_ZUNIONSTORE = 380,
    SQL_WEIGHTS = 381,
    SQL_AGGREGATE = 382,
    SQL_ZINTERSTORE = 383,
    SQL_SELECT = 384,
    SQL_INTLITERAL = 385,
    SQL_FLOATLITERAL = 386,
    SQL_IDENTIFIER = 387,
    SQL_STRINGLITERAL = 388,
    SQL_OP_NOTEQUAL = 389,
    SQL_MATCH = 390,
    SQL_LIKE = 391,
    SQL_OP_EQUAL = 392,
    SQL_OP_GREATERTHAN = 393,
    SQL_OP_LESSTHAN = 394,
    SQL_OP_GREATEREQ = 395,
    SQL_OP_LESSEQ = 396,
    SQL_ISNULL = 397,
    SQL_IS = 398,
    SQL_OP_ADD = 399,
    SQL_OP_SUB = 400,
    SQL_OP_MUL = 401,
    SQL_OP_MOD = 402,
    SQL_OP_DIVIDE = 403,
    SQL_OP_XOR = 404,
    SQL_UMINUS = 405,
    SQL_OP_LBRACKET = 406,
    SQL_OP_RBRACKET = 407,
    SQL_OP_RP = 408,
    SQL_OP_LP = 409,
    SQL_JOIN = 410,
    SQL_ON = 411
  };
#endif

/* Value type.  */
#if ! defined FF_STYPE && ! defined FF_STYPE_IS_DECLARED
#line 30 "bison.y"
union FF_STYPE
{
#line 30 "bison.y"

	long	ival;
	char*	sval;
	double	fval;
	Program * program_t;
	Stmtlist * stmtlist_t;
	Stmt * stmt_t;
    KeyStmt * key_stmt_t;
    StringStmt * string_stmt_t;
    HashStmt * hash_stmt_t;
    ListStmt * list_stmt_t;
    SetStmt * set_stmt_t;
    ZsetStmt * zset_stmt_t;
    ConnectStmt * connect_stmt_t;
    DelStmt * del_stmt_t;
    KeyList * key_list_t;
    DumpStmt * dump_stmt_t;
    ExistsStmt * exists_stmt_t;
    ExpireStmt * expire_stmt_t;
    ExpireatStmt * expireat_stmt_t;
    MoveStmt * move_stmt_t;
    ObjectStmt * object_stmt_t;
	Objoption * objoption_t;
    PersistStmt * persist_stmt_t;
    PexpireStmt * pexpire_stmt_t;
    PexpireatStmt * pexpireat_stmt_t;
    PttlStmt * pttl_stmt_t;
    RandomkeyStmt * randomkey_stmt_t;
    RenameStmt * rename_stmt_t;
    RenamenxStmt * renamenx_stmt_t;
	AliasName * aliasname_t;
    SortStmt * sort_stmt_t;
	SortClause * sort_clause_t;
	OptByClause * opt_by_clause_t;
    OptLimitClause * opt_limit_clause_t;
    OptStoreClause * opt_store_clause_t;
	OptSortBehavior * opt_sort_behavior_t;
    TtlStmt * ttl_stmt_t;
    TypeStmt * type_stmt_t;
    AppendStmt * append_stmt_t;
    BicountStmt * bicount_stmt_t;
    SetbitStmt * setbit_stmt_t;
    BitopStmt * bitop_stmt_t;
    DecrStmt * decr_stmt_t;
    DecrbyStmt * decrby_stmt_t;
    GetStmt * get_stmt_t;
    GetbitStmt * getbit_stmt_t;
    GetrangeStmt * getrange_stmt_t;
    GetsetStmt * getset_stmt_t;
    IncrStmt * incr_stmt_t;
    IncrbyStmt * incrby_stmt_t;
    IncrbyfloatStmt * incrbyfloat_stmt_t;
    MgetStmt * mget_stmt_t;
	MsetStmt * mset_stmt_t;
    PsetexStmt * psetex_stmt_t;
    SetkeyStmt * setkey_stmt_t;
	SetkeyClause * setkey_clause_t;
    OptExpireTimeClause * opt_expiretime_clause_t;
    OptSetkeyBehavior * opt_setkey_behavior_t;
    SetexStmt * setex_stmt_t;
    SetnxStmt * setnx_stmt_t;
    SetrangeStmt * setrange_stmt_t;
    StrlenStmt * strlen_stmt_t;
    HdelStmt * hdel_stmt_t;
    HexistsStmt * hexists_stmt_t;
    HgetStmt * hget_stmt_t;
    HgetallStmt * hgetall_stmt_t;
    HincrbyStmt * hincrby_stmt_t;
    HincrbyfloatStmt * hincrbyfloat_stmt_t;
    HkeysStmt * hkeys_stmt_t;
    HlenStmt * hlen_stmt_t;
    HmgetStmt * hmget_stmt_t;
	HmsetStmt * hmset_stmt_t;
    HsetStmt * hset_stmt_t;
    HsetnxStmt * hsetnx_stmt_t;
    HvalsStmt * hvals_stmt_t;
    LindexStmt * lindex_stmt_t;
    LinsertStmt * linsert_stmt_t;
    OptLinsertBehavior * opt_linsert_behavior_t; 
    LlenStmt * llen_stmt_t;
    LpopStmt * lpop_stmt_t;
    LpushStmt * lpush_stmt_t;
    LpushxStmt * lpushx_stmt_t;
    LrangeStmt * lrange_stmt_t;
    LremStmt * lrem_stmt_t;
    LsetStmt * lset_stmt_t;
    LtrimStmt * ltrim_stmt_t;
    RpopStmt * rpop_stmt_t;
    RpoplpushStmt * rpoplpush_stmt_t;
    RpushStmt * rpush_stmt_t;
    RpushxStmt * rpushx_stmt_t;
    SaddStmt * sadd_stmt_t;
    ScardStmt * scard_stmt_t;
    SdiffStmt * sdiff_stmt_t;
    SdiffstoreStmt * sdiffstore_stmt_t;
    SinterStmt * sinter_stmt_t;
    SinterstoreStmt * sinterstore_stmt_t;
    SismemberStmt * sismember_stmt_t;
	SmemberStmt * smember_stmt_t;
    SmoveStmt * smove_stmt_t;
    SpopStmt * spop_stmt_t;
    SrandmemberStmt * srandmember_stmt_t;
    SremStmt * srem_stmt_t;
    SunionStmt * sunion_stmt_t;
    SunionstoreStmt * sunionstore_stmt_t;
    ZaddStmt * zadd_stmt_t;
    ZcardStmt * zcard_stmt_t;
    ZcountStmt * zcount_stmt_t;
    ZincrbyStmt * zincrby_stmt_t;
    ZrangeStmt * zrange_stmt_t;
    OptZrangeBehavior * opt_zrange_behavior_t;
    ZrangebyscoreStmt * zrangebyscore_stmt_t;
	ZrangebyscoreClause * zrangebyscore_clause_t;
    ZrankStmt * zrank_stmt_t;
	ZremStmt * zrem_stmt_t;
    ZscoreStmt * zscore_stmt_t;
    ZunionstoreStmt * zunionstore_stmt_t;
    ZunionstoreClause * zunionstore_clause_t;
	ZinterstoreClause * zinterstore_clause_t;
    OptWeightClause * opt_weight_clause_t;
    OptAggregateClause * opt_aggregate_clause_t;
    ZinterstoreStmt * zinterstore_stmt_t;
    SelectStmt * select_stmt_t; 
    KeyName * keyname_t;
	KeyStringName * key_string_name_t;
	KeyHashName * key_hash_name_t;
	KeyListName * key_list_name_t;
	KeySetName * key_set_name_t;
	KeyZsetName * key_zset_name_t;
	KeyStringList * key_string_list_t;
	KeyStringValueList * key_string_value_list_t;
	KeyStringValue * key_string_value_t;
	KeySetList * key_set_list_t;
	DelKeySetList * del_key_set_list_t;
	KeyZsetList * key_zset_list_t;
    ValueList * value_list_t;
	Value * value_t;
    FieldList * field_list_t;
	DelFieldList * del_field_list_t;
    FieldName * field_name_t;
    FieldValue * field_value_t;
    ZmemberName * zmember_name_t;
	ZmemberNameList * zmember_name_list_t;
    ZmemberValue * zmember_value_t;
    ZmemberValueList * zmember_value_list_t;
	SmemberName * smember_name_t;
	SmemberNameList * smember_name_list_t;
    FieldValueList * field_value_list_t;
    Operandnum * operandnum_t;
	OperandnumList * operandnum_list_t;
	Operation * operation_t;
    Identifier * identifier_t;
	TimeSecond * timesecond_t;
	TimeUnix * timeunix_t;
    Literal *literal_t;
    StringLiteral * string_literal_t;
    NumLiteral * num_literal_t;
    IntLiteral * int_literal_t;
    FloatLiteral * float_literal_t;
	OptEnforced *	opt_enforced_t;

#line 472 "bison_parser.cpp"

};
#line 30 "bison.y"
typedef union FF_STYPE FF_STYPE;
# define FF_STYPE_IS_TRIVIAL 1
# define FF_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined FF_LTYPE && ! defined FF_LTYPE_IS_DECLARED
typedef struct FF_LTYPE FF_LTYPE;
struct FF_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define FF_LTYPE_IS_DECLARED 1
# define FF_LTYPE_IS_TRIVIAL 1
#endif



int ff_parse (Program* result, yyscan_t scanner);

#endif /* !YY_FF_BISON_PARSER_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
         || (defined FF_LTYPE_IS_TRIVIAL && FF_LTYPE_IS_TRIVIAL \
             && defined FF_STYPE_IS_TRIVIAL && FF_STYPE_IS_TRIVIAL)))

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
#define YYFINAL  309
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   726

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  157
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  156
/* YYNRULES -- Number of rules.  */
#define YYNRULES  284
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  467

#define YYUNDEFTOK  2
#define YYMAXUTOK   411


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156
};

#if FF_DEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   403,   403,   413,   418,   427,   433,   439,   445,   451,
     457,   463,   471,   477,   483,   489,   495,   500,   505,   510,
     515,   520,   525,   530,   535,   540,   545,   550,   555,   564,
     570,   576,   582,   588,   594,   600,   606,   612,   618,   624,
     630,   636,   642,   648,   654,   660,   666,   672,   678,   684,
     694,   700,   705,   710,   715,   720,   725,   730,   735,   740,
     745,   750,   755,   764,   770,   775,   780,   785,   790,   795,
     800,   805,   810,   815,   820,   825,   830,   839,   845,   850,
     855,   860,   865,   870,   875,   880,   885,   890,   895,   900,
     905,   913,   919,   924,   929,   934,   939,   944,   949,   954,
     959,   964,   974,   985,   993,  1001,  1009,  1018,  1027,  1036,
    1045,  1050,  1055,  1063,  1071,  1080,  1089,  1097,  1104,  1113,
    1122,  1137,  1149,  1156,  1161,  1168,  1174,  1181,  1186,  1193,
    1197,  1201,  1205,  1213,  1221,  1230,  1240,  1248,  1258,  1267,
    1271,  1275,  1279,  1286,  1294,  1303,  1311,  1320,  1330,  1339,
    1347,  1356,  1365,  1374,  1384,  1394,  1404,  1421,  1426,  1431,
    1438,  1442,  1446,  1455,  1473,  1490,  1500,  1510,  1528,  1537,
    1547,  1555,  1565,  1575,  1583,  1591,  1600,  1617,  1634,  1651,
    1660,  1669,  1691,  1695,  1702,  1710,  1718,  1738,  1757,  1768,
    1789,  1810,  1820,  1828,  1837,  1857,  1878,  1898,  1906,  1914,
    1922,  1930,  1938,  1947,  1955,  1965,  1984,  1993,  2002,  2010,
    2020,  2040,  2048,  2058,  2068,  2079,  2083,  2090,  2098,  2108,
    2117,  2127,  2136,  2146,  2156,  2161,  2169,  2174,  2178,  2182,
    2190,  2200,  2212,  2221,  2234,  2252,  2268,  2276,  2281,  2291,
    2307,  2313,  2323,  2329,  2338,  2358,  2376,  2392,  2408,  2431,
    2436,  2446,  2468,  2473,  2483,  2500,  2517,  2534,  2557,  2563,
    2572,  2589,  2606,  2627,  2643,  2649,  2660,  2676,  2692,  2712,
    2733,  2738,  2748,  2756,  2764,  2773,  2778,  2788,  2796,  2802,
    2811,  2820,  2826,  2835,  2843
};
#endif

#if FF_DEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEL", "DUMP", "EXISTS", "EXPIRE",
  "EXPIREAT", "KEYS", "MIGRATE", "COPY", "REPLACE", "MOVE", "OBJECT",
  "REFCOUNT", "ENCODING", "IDLETIME", "PERSIST", "PEXPIRE", "PEXPIREAT",
  "PTTL", "RANDOMKEY", "RENAME", "RENAMENX", "RESTORE", "SORT", "GET",
  "STORE", "TTL", "TYPE", "APPEND", "BITCOUNT", "BITOP", "DECR", "DECRBY",
  "GETBIT", "GETRANGE", "GETSET", "INCR", "INCRBY", "INCRBYFLOAT", "MGET",
  "MSET", "MSETNX", "PSETEX", "SET", "AND", "OR", "XOR", "NOT", "BY",
  "LIMIT", "ASC", "DESC", "ALPHA", "EX", "PX", "NX", "XX", "SETBIT",
  "SETEX", "SETNX", "SETRANGE", "STRLEN", "BEFORE", "AFTER", "SUM", "MIN",
  "MAX", "HDEL", "HEXISTS", "HGET", "HGETALL", "HINCRBY", "HINCRBYFLOAT",
  "HKEYS", "HLEN", "HMGET", "HMSET", "HSET", "HSETNX", "HVALS", "LINDEX",
  "LINSERT", "LLEN", "LPOP", "LPUSH", "LPUSHX", "LRANGE", "LREM", "LSET",
  "LTRIM", "RPOP", "RPOPLPUSH", "RPUSH", "RPUSHX", "SADD", "SCARD",
  "SDIFF", "SDIFFSTORE", "SINTER", "SINTERSTORE", "SISMEMBER", "SMEMBERS",
  "SMOVE", "SPOP", "SRANDMEMBER", "SREM", "SUNION", "SUNIONSTORE", "ZADD",
  "ZCARD", "ZCOUNT", "ZINCRBY", "ZRANGE", "WITHSCORES", "ZRANGEBYSCORE",
  "ZRANK", "ZREM", "ZREMRANGEBYRANK", "ZREMRANGEBYSCORE", "ZREVRANGE",
  "ZREVRANGEBYSCORE", "ZREVRANK", "ZSCORE", "ZUNIONSTORE", "WEIGHTS",
  "AGGREGATE", "ZINTERSTORE", "SELECT", "INTLITERAL", "FLOATLITERAL",
  "IDENTIFIER", "STRINGLITERAL", "OP_NOTEQUAL", "MATCH", "LIKE",
  "OP_EQUAL", "OP_GREATERTHAN", "OP_LESSTHAN", "OP_GREATEREQ", "OP_LESSEQ",
  "ISNULL", "IS", "OP_ADD", "OP_SUB", "OP_MUL", "OP_MOD", "OP_DIVIDE",
  "OP_XOR", "UMINUS", "OP_LBRACKET", "OP_RBRACKET", "OP_RP", "OP_LP",
  "JOIN", "ON", "$accept", "program", "stmtlist", "stmt", "key_stmt",
  "string_stmt", "hash_stmt", "list_stmt", "set_stmt", "zset_stmt",
  "connect_stmt", "del_stmt", "dump_stmt", "exists_stmt", "expire_stmt",
  "expireat_stmt", "move_stmt", "object_stmt", "objoption", "persist_stmt",
  "pexpire_stmt", "pexpireat_stmt", "pttl_stmt", "randomkey_stmt",
  "rename_stmt", "renamenx_stmt", "aliasname", "sort_stmt", "sort_clause",
  "opt_by_clause", "opt_limit_clause", "opt_store_clause",
  "opt_sort_behavior", "ttl_stmt", "type_stmt", "append_stmt",
  "bicount_stmt", "setbit_stmt", "bitop_stmt", "operation", "decr_stmt",
  "decrby_stmt", "get_stmt", "getbit_stmt", "getrange_stmt", "getset_stmt",
  "incr_stmt", "incrby_stmt", "incrbyfloat_stmt", "mget_stmt", "mset_stmt",
  "psetex_stmt", "setkey_stmt", "setkey_clause", "opt_expiretime_clause",
  "opt_setkey_behavior", "setex_stmt", "setnx_stmt", "setrange_stmt",
  "strlen_stmt", "hdel_stmt", "hexists_stmt", "hget_stmt", "hgetall_stmt",
  "hincrby_stmt", "hincrbyfloat_stmt", "hkeys_stmt", "hlen_stmt",
  "hmget_stmt", "hmset_stmt", "hset_stmt", "hsetnx_stmt", "hvals_stmt",
  "lindex_stmt", "linsert_stmt", "opt_linsert_behavior", "llen_stmt",
  "lpop_stmt", "lpush_stmt", "lpushx_stmt", "lrange_stmt", "lrem_stmt",
  "lset_stmt", "ltrim_stmt", "rpop_stmt", "rpoplpush_stmt", "rpush_stmt",
  "rpushx_stmt", "sadd_stmt", "scard_stmt", "sdiff_stmt",
  "sdiffstore_stmt", "sinter_stmt", "sinterstore_stmt", "sismember_stmt",
  "smember_stmt", "smove_stmt", "spop_stmt", "srandmember_stmt",
  "srem_stmt", "sunion_stmt", "sunionstore_stmt", "zadd_stmt",
  "zcard_stmt", "zcount_stmt", "zincrby_stmt", "zrange_stmt",
  "opt_zrange_behavior", "zrangebyscore_stmt", "zrangebyscore_clause",
  "zrank_stmt", "zrem_stmt", "zscore_stmt", "zunionstore_stmt",
  "zunionstore_clause", "opt_weight_clause", "opt_aggregate_clause",
  "zinterstore_stmt", "zinterstore_clause", "select_stmt", "key_list",
  "keyname", "value", "value_list", "key_string_name", "key_string_list",
  "key_string_value_list", "key_string_value", "key_hash_name",
  "field_name", "del_field_list", "field_list", "field_value",
  "field_value_list", "key_list_name", "key_set_name", "del_key_set_list",
  "key_set_list", "smember_name", "smember_name_list", "key_zset_name",
  "key_zset_list", "zmember_name", "zmember_name_list", "zmember_value",
  "zmember_value_list", "timesecond", "timeunix", "operandnum",
  "operandnum_list", "identifier", "literal", "string_literal",
  "num_literal", "int_literal", "float_literal", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411
};
# endif

#define YYPACT_NINF (-292)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     597,  -121,  -121,  -121,  -121,  -121,  -121,    21,  -121,  -121,
    -121,  -121,  -292,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,   139,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,   -23,   147,  -292,   597,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,   105,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,   111,  -292,
    -292,  -292,  -292,    39,  -292,    39,  -292,  -292,  -292,  -121,
    -292,  -292,  -292,    38,    38,   -23,  -292,  -292,  -292,  -121,
    -292,    38,    38,  -292,  -121,  -121,  -292,  -292,  -292,  -292,
    -292,    38,  -292,  -292,  -292,  -292,  -292,  -121,  -292,   -36,
     -23,   -23,    38,  -292,   -36,    41,  -121,  -292,    38,  -292,
    -121,    38,    48,    38,   -23,    38,    38,   -23,  -292,  -121,
    -292,  -121,  -121,  -292,  -121,  -121,  -292,  -292,  -121,  -121,
    -121,  -121,  -292,   -23,  -292,    94,  -292,  -292,    38,    38,
     -23,   -23,   -23,   -23,  -292,  -121,    38,    38,  -121,  -292,
    -292,  -121,  -292,  -292,  -292,  -292,  -121,  -292,  -121,  -292,
     -23,  -121,  -292,  -292,    38,  -292,  -292,   -23,   -23,   -23,
     -23,  -121,  -121,  -121,   -23,   -23,  -292,  -292,  -292,  -292,
    -292,  -121,   111,   -23,  -292,   -23,    46,    46,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,   -23,  -292,  -292,  -292,  -292,  -292,  -292,    38,    38,
      38,   132,  -292,    38,    38,  -292,    38,  -121,  -292,  -292,
    -292,  -292,   -36,    41,  -121,  -292,    38,  -121,  -292,  -292,
    -292,  -292,  -292,  -292,    38,    38,  -292,  -292,   -23,    38,
      38,   -23,  -292,  -292,  -292,  -121,  -292,  -292,  -292,  -292,
    -121,  -292,  -121,  -292,  -121,    38,  -292,   -23,  -121,   -23,
     -23,  -292,  -292,  -121,  -292,  -292,  -121,  -121,  -292,   123,
     -23,   -23,  -292,   115,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,    38,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,    64,  -292,  -292,  -121,  -292,
    -292,  -292,  -292,  -292,   164,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -121,  -292,  -292
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     3,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   124,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,   126,    97,
      98,    99,   100,   225,   101,   225,   102,   277,   103,   233,
     235,   104,   105,     0,     0,     0,   110,   111,   112,     0,
     113,     0,     0,   116,     0,     0,   122,   145,   239,   133,
     134,     0,   136,   139,   140,   141,   142,     0,   143,     0,
       0,     0,     0,   149,     0,     0,   240,   152,     0,   153,
     242,     0,   159,     0,     0,     0,     0,     0,   166,     0,
     245,     0,     0,   170,     0,     0,   173,   174,     0,     0,
       0,     0,   179,     0,   254,     0,   184,   185,     0,     0,
       0,     0,     0,     0,   192,     0,     0,     0,     0,   255,
     197,   258,   198,   199,   200,   201,     0,   203,     0,   205,
       0,     0,   208,   209,     0,   263,   211,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   283,   232,   274,     1,
       4,     0,   126,     0,   217,     0,   229,   229,   234,   284,
     280,   106,   272,   278,   279,   281,   282,   107,   273,   108,
     109,   114,   115,   118,   120,   119,   135,   236,   138,   144,
     146,     0,   148,   150,   151,   241,   244,   243,     0,     0,
       0,   162,   156,     0,     0,   164,     0,   247,   167,   246,
     168,   169,     0,     0,   249,   175,     0,   252,   176,   177,
     178,   180,   182,   183,     0,   237,   186,   187,     0,     0,
       0,     0,   193,   194,   195,   261,   196,   260,   259,   202,
       0,   206,   256,   207,     0,   270,   210,     0,     0,     0,
       0,   219,   266,   267,   220,   221,     0,     0,   123,   132,
       0,   275,   224,     0,   222,   230,   147,   154,   157,   158,
     160,   161,   155,   137,   163,   165,   248,   171,   172,   250,
     251,   253,     0,   238,   188,   189,   190,   191,   262,   204,
     257,   269,   271,   212,   213,   216,   218,   268,   264,   223,
     231,   129,   130,   131,   128,   125,   276,   226,   227,   228,
     181,   215,   214,   265,     0,   121,   127
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -292,  -292,    99,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,   -18,  -292,  -292,  -292,
    -113,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,     5,  -116,  -292,  -292,  -292,
       3,    16,   218,  -183,    86,  -221,   -37,  -292,   425,   -88,
    -292,  -211,   -66,  -163,    73,    24,  -187,    70,  -194,  -179,
     337,  -291,  -149,  -196,  -292,  -186,   -67,  -292,   138,  -201,
      -1,   -61,  -292,  -206,    34,  -203
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   209,   109,
     110,   111,   112,   113,   114,   115,   333,   116,   117,   312,
     314,   465,   454,   118,   119,   120,   121,   122,   123,   227,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   242,   351,   422,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   374,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   462,   187,   188,
     189,   190,   191,   192,   193,   316,   414,   194,   195,   196,
     198,   199,   375,   376,   236,   237,   239,   240,   249,   366,
     358,   365,   367,   368,   263,   281,   393,   282,   385,   386,
     448,   449,   403,   404,   395,   396,   321,   327,   411,   412,
     218,   337,   323,   324,   325,   326
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     200,   200,   200,   200,   200,   200,   338,   200,   200,   200,
     200,   197,   200,   200,   200,   345,   200,   200,   201,   202,
     203,   204,   205,   339,   210,   211,   212,   213,   343,   214,
     215,   216,   344,   219,   220,   206,   207,   208,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     278,   280,   389,   383,   306,   319,   286,   287,   288,   289,
     290,   291,   217,   349,   350,   221,   222,   306,   228,   229,
     230,   231,   232,   233,   234,   235,   450,   238,   241,   243,
     244,   245,   246,   247,   248,   308,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   283,
     284,   285,   322,   328,   331,   332,   426,   309,   292,   293,
     322,   322,   401,   429,   405,   311,   427,   463,   372,   373,
     428,   357,   313,   360,   361,   315,   362,   363,   306,   319,
     364,   320,   319,   413,   348,   451,   452,   453,   354,   461,
     322,   457,   458,   459,   322,   223,   224,   225,   226,   420,
     421,   464,   433,   310,   369,   370,   439,   335,   200,   409,
     317,   415,   318,   347,   431,   440,   438,   447,   200,   442,
     456,     0,     0,   334,   334,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   330,     0,     0,     0,   307,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   308,
       0,     0,     0,     0,     0,   441,     0,     0,   359,   444,
     359,   359,     0,   359,   359,     0,     0,   359,   359,   359,
     359,     0,     0,     0,   308,   308,     0,     0,     0,   364,
       0,     0,     0,     0,   264,     0,   364,   387,   308,     0,
     279,   308,   418,   419,     0,   387,     0,   279,   322,   322,
     279,     0,     0,     0,     0,     0,     0,   308,     0,     0,
     402,   402,   402,     0,   308,   308,   308,   308,     0,     0,
     200,     0,   390,     0,     0,   392,     0,     0,     0,     0,
       0,     0,     0,     0,   308,     0,   238,   408,     0,     0,
       0,   308,   308,   308,   308,     0,     0,     0,   308,   308,
       0,     0,     0,   329,     0,     0,     0,   308,   382,   308,
       0,   388,     0,     0,     0,     0,   359,     0,     0,     0,
       0,     0,     0,   359,     0,     0,   359,     0,   340,   341,
       0,     0,     0,     0,     0,   308,     0,     0,     0,     0,
       0,     0,   353,     0,   387,   356,     0,     0,     0,   387,
       0,   279,     0,   402,     0,     0,     0,   402,     0,     0,
       0,   371,   402,     0,     0,   295,   295,     0,   378,   379,
     380,   381,   308,     0,     0,   308,   392,   294,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   391,     0,
       0,   308,     0,   308,   308,   397,   398,   399,   400,   336,
       0,     0,   406,   407,   308,   308,     0,   295,     0,     0,
     342,   410,     0,     0,     0,     0,   346,     0,     0,     0,
       0,   352,     0,   200,   355,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,     0,     0,   416,
     466,     0,     0,     0,     0,     0,     0,   377,     0,     0,
       0,     0,     0,     0,     0,   384,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   394,     0,     0,     0,   434,     0,     0,   437,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   443,     0,   445,   446,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   455,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   417,     0,     0,     0,
       0,   423,   424,     0,   425,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   430,     0,     0,     0,     0,     0,
       0,     0,   432,     0,     0,     0,     0,   435,   436,     0,
       1,     2,     3,     4,     5,     0,     0,     0,     0,     6,
       7,     0,     0,   394,     8,     9,    10,    11,    12,    13,
      14,     0,    15,    16,     0,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       0,    32,    33,     0,     0,     0,     0,     0,     0,     0,
     460,     0,     0,     0,     0,     0,    34,    35,    36,    37,
      38,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,     0,    85,    86,    87,     0,     0,     0,     0,
       0,    88,    89,     0,     0,    90,    91
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,     4,     5,     6,   227,     8,     9,    10,
      11,   132,    13,    14,    15,   236,    17,    18,     2,     3,
       4,     5,     6,   229,     8,     9,    10,    11,   234,    13,
      14,    15,   235,    17,    18,    14,    15,    16,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      66,    67,   286,   276,   130,   131,    72,    73,    74,    75,
      76,    77,    16,    55,    56,    19,    20,   130,    22,    23,
      24,    25,    26,    27,    28,    29,   407,    31,    32,    33,
      34,    35,    36,    37,    38,    91,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    69,
      70,    71,   203,   204,   211,   212,   357,     0,    78,    79,
     211,   212,   301,   364,   303,    50,   362,   448,    64,    65,
     363,   249,    51,   251,   252,   126,   254,   255,   130,   131,
     258,   133,   131,   127,   241,    52,    53,    54,   245,   115,
     241,    66,    67,    68,   245,    46,    47,    48,    49,    57,
      58,    27,   375,    94,   260,   261,   390,   215,   199,   312,
     195,   317,   199,   240,   367,   392,   385,   403,   209,   395,
     411,    -1,    -1,   214,   215,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,    -1,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
      -1,    -1,    -1,    -1,    -1,   394,    -1,    -1,   249,   398,
     251,   252,    -1,   254,   255,    -1,    -1,   258,   259,   260,
     261,    -1,    -1,    -1,   230,   231,    -1,    -1,    -1,   357,
      -1,    -1,    -1,    -1,   275,    -1,   364,   278,   244,    -1,
     281,   247,   349,   350,    -1,   286,    -1,   288,   349,   350,
     291,    -1,    -1,    -1,    -1,    -1,    -1,   263,    -1,    -1,
     301,   302,   303,    -1,   270,   271,   272,   273,    -1,    -1,
     311,    -1,   288,    -1,    -1,   291,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   290,    -1,   240,   311,    -1,    -1,
      -1,   297,   298,   299,   300,    -1,    -1,    -1,   304,   305,
      -1,    -1,    -1,   205,    -1,    -1,    -1,   313,   275,   315,
      -1,   281,    -1,    -1,    -1,    -1,   357,    -1,    -1,    -1,
      -1,    -1,    -1,   364,    -1,    -1,   367,    -1,   230,   231,
      -1,    -1,    -1,    -1,    -1,   341,    -1,    -1,    -1,    -1,
      -1,    -1,   244,    -1,   385,   247,    -1,    -1,    -1,   390,
      -1,   392,    -1,   394,    -1,    -1,    -1,   398,    -1,    -1,
      -1,   263,   403,    -1,    -1,   406,   407,    -1,   270,   271,
     272,   273,   378,    -1,    -1,   381,   392,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,   290,    -1,
      -1,   397,    -1,   399,   400,   297,   298,   299,   300,   221,
      -1,    -1,   304,   305,   410,   411,    -1,   448,    -1,    -1,
     232,   313,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,
      -1,   243,    -1,   464,   246,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    -1,    -1,   341,
     464,    -1,    -1,    -1,    -1,    -1,    -1,   269,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   294,    -1,    -1,    -1,   378,    -1,    -1,   381,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   397,    -1,   399,   400,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   410,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   348,    -1,    -1,    -1,
      -1,   353,   354,    -1,   356,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   374,    -1,    -1,    -1,    -1,   379,   380,    -1,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    12,
      13,    -1,    -1,   395,    17,    18,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     432,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,   124,   125,    -1,    -1,   128,   129
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,     4,     5,     6,     7,    12,    13,    17,    18,
      19,    20,    21,    22,    23,    25,    26,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    44,    45,    59,    60,    61,    62,    63,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   116,   117,   118,   124,   125,
     128,   129,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   176,
     177,   178,   179,   180,   181,   182,   184,   185,   190,   191,
     192,   193,   194,   195,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   265,   266,   267,
     268,   269,   270,   271,   274,   275,   276,   132,   277,   278,
     307,   278,   278,   278,   278,   278,    14,    15,    16,   175,
     278,   278,   278,   278,   278,   278,   278,   281,   307,   278,
     278,   281,   281,    46,    47,    48,    49,   196,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   282,   281,   283,
     284,   281,   210,   281,   281,   281,   281,   281,   281,   285,
     307,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   291,   307,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   292,   307,
     292,   292,   294,   294,   294,   294,   292,   292,   292,   292,
     292,   292,   294,   294,   297,   307,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   130,   305,   311,     0,
     159,    50,   186,    51,   187,   126,   272,   272,   277,   131,
     133,   303,   308,   309,   310,   311,   312,   304,   308,   305,
     278,   303,   303,   183,   307,   183,   279,   308,   282,   310,
     305,   305,   279,   310,   312,   282,   279,   283,   303,    55,
      56,   211,   279,   305,   303,   279,   305,   286,   287,   307,
     286,   286,   286,   286,   286,   288,   286,   289,   290,   289,
     289,   305,    64,    65,   232,   279,   280,   279,   305,   305,
     305,   305,   291,   280,   279,   295,   296,   307,   294,   295,
     292,   305,   292,   293,   279,   301,   302,   305,   305,   305,
     305,   299,   307,   299,   300,   299,   305,   305,   278,   187,
     305,   305,   306,   127,   273,   273,   305,   279,   303,   303,
      57,    58,   212,   279,   279,   279,   288,   310,   312,   288,
     279,   290,   279,   280,   305,   279,   279,   305,   296,   295,
     293,   299,   302,   305,   299,   305,   305,   300,   297,   298,
     298,    52,    53,    54,   189,   305,   306,    66,    67,    68,
     279,   115,   264,   298,    27,   188,   278
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   157,   158,   159,   159,   160,   160,   160,   160,   160,
     160,   160,   161,   161,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     163,   163,   163,   163,   163,   163,   163,   163,   163,   163,
     163,   163,   163,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   164,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   175,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   186,   187,   187,   188,   188,   189,
     189,   189,   189,   190,   191,   192,   193,   194,   195,   196,
     196,   196,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   211,   211,
     212,   212,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   272,   273,   273,   273,   273,
     274,   275,   276,   277,   277,   278,   279,   280,   280,   281,
     282,   282,   283,   283,   284,   285,   286,   287,   287,   288,
     288,   289,   290,   290,   291,   292,   293,   293,   294,   294,
     295,   296,   296,   297,   298,   298,   299,   300,   300,   301,
     302,   302,   303,   304,   305,   306,   306,   307,   308,   308,
     309,   310,   310,   311,   312
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     3,     3,     3,     3,
       1,     1,     1,     2,     3,     3,     2,     1,     3,     3,
       1,     5,     2,     2,     0,     3,     0,     2,     0,     1,
       1,     1,     0,     2,     2,     3,     2,     4,     3,     1,
       1,     1,     1,     2,     3,     2,     3,     4,     3,     2,
       3,     3,     2,     2,     4,     4,     2,     2,     2,     0,
       1,     1,     0,     4,     3,     4,     2,     3,     3,     3,
       2,     4,     4,     2,     2,     3,     3,     3,     3,     2,
       3,     5,     1,     1,     2,     2,     3,     3,     4,     4,
       4,     4,     2,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     3,     2,     4,     2,     3,     3,     2,     2,
       3,     2,     4,     4,     5,     1,     0,     2,     4,     3,
       3,     3,     3,     4,     2,     0,     2,     2,     2,     0,
       3,     4,     2,     1,     2,     1,     1,     1,     2,     1,
       1,     2,     1,     2,     2,     1,     1,     1,     2,     1,
       2,     2,     1,     2,     1,     1,     1,     2,     1,     2,
       1,     1,     2,     1,     1,     2,     1,     1,     2,     2,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1
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
        yyerror (&yylloc, result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


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
#if FF_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined FF_LTYPE_IS_TRIVIAL && FF_LTYPE_IS_TRIVIAL

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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Program* result, yyscan_t scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Program* result, yyscan_t scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, result, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, Program* result, yyscan_t scanner)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !FF_DEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !FF_DEBUG */


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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, Program* result, yyscan_t scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
    case 130: /* INTLITERAL  */
#line 395 "bison.y"
           {
	 
}
#line 1951 "bison_parser.cpp"
        break;

    case 131: /* FLOATLITERAL  */
#line 395 "bison.y"
           {
	 
}
#line 1959 "bison_parser.cpp"
        break;

    case 132: /* IDENTIFIER  */
#line 391 "bison.y"
           {
	free( (((*yyvaluep).sval)) );
}
#line 1967 "bison_parser.cpp"
        break;

    case 133: /* STRINGLITERAL  */
#line 391 "bison.y"
           {
	free( (((*yyvaluep).sval)) );
}
#line 1975 "bison_parser.cpp"
        break;

    case 158: /* program  */
#line 399 "bison.y"
            { if(((*yyvaluep).program_t)!=NULL)((*yyvaluep).program_t)->deep_delete(); }
#line 1981 "bison_parser.cpp"
        break;

    case 159: /* stmtlist  */
#line 399 "bison.y"
            { if(((*yyvaluep).stmtlist_t)!=NULL)((*yyvaluep).stmtlist_t)->deep_delete(); }
#line 1987 "bison_parser.cpp"
        break;

    case 160: /* stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).stmt_t)!=NULL)((*yyvaluep).stmt_t)->deep_delete(); }
#line 1993 "bison_parser.cpp"
        break;

    case 161: /* key_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_stmt_t)!=NULL)((*yyvaluep).key_stmt_t)->deep_delete(); }
#line 1999 "bison_parser.cpp"
        break;

    case 162: /* string_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).string_stmt_t)!=NULL)((*yyvaluep).string_stmt_t)->deep_delete(); }
#line 2005 "bison_parser.cpp"
        break;

    case 163: /* hash_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hash_stmt_t)!=NULL)((*yyvaluep).hash_stmt_t)->deep_delete(); }
#line 2011 "bison_parser.cpp"
        break;

    case 164: /* list_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).list_stmt_t)!=NULL)((*yyvaluep).list_stmt_t)->deep_delete(); }
#line 2017 "bison_parser.cpp"
        break;

    case 165: /* set_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).set_stmt_t)!=NULL)((*yyvaluep).set_stmt_t)->deep_delete(); }
#line 2023 "bison_parser.cpp"
        break;

    case 166: /* zset_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zset_stmt_t)!=NULL)((*yyvaluep).zset_stmt_t)->deep_delete(); }
#line 2029 "bison_parser.cpp"
        break;

    case 167: /* connect_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).connect_stmt_t)!=NULL)((*yyvaluep).connect_stmt_t)->deep_delete(); }
#line 2035 "bison_parser.cpp"
        break;

    case 168: /* del_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).del_stmt_t)!=NULL)((*yyvaluep).del_stmt_t)->deep_delete(); }
#line 2041 "bison_parser.cpp"
        break;

    case 169: /* dump_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).dump_stmt_t)!=NULL)((*yyvaluep).dump_stmt_t)->deep_delete(); }
#line 2047 "bison_parser.cpp"
        break;

    case 170: /* exists_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).exists_stmt_t)!=NULL)((*yyvaluep).exists_stmt_t)->deep_delete(); }
#line 2053 "bison_parser.cpp"
        break;

    case 171: /* expire_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).expire_stmt_t)!=NULL)((*yyvaluep).expire_stmt_t)->deep_delete(); }
#line 2059 "bison_parser.cpp"
        break;

    case 172: /* expireat_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).expireat_stmt_t)!=NULL)((*yyvaluep).expireat_stmt_t)->deep_delete(); }
#line 2065 "bison_parser.cpp"
        break;

    case 173: /* move_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).move_stmt_t)!=NULL)((*yyvaluep).move_stmt_t)->deep_delete(); }
#line 2071 "bison_parser.cpp"
        break;

    case 174: /* object_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).object_stmt_t)!=NULL)((*yyvaluep).object_stmt_t)->deep_delete(); }
#line 2077 "bison_parser.cpp"
        break;

    case 175: /* objoption  */
#line 399 "bison.y"
            { if(((*yyvaluep).objoption_t)!=NULL)((*yyvaluep).objoption_t)->deep_delete(); }
#line 2083 "bison_parser.cpp"
        break;

    case 176: /* persist_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).persist_stmt_t)!=NULL)((*yyvaluep).persist_stmt_t)->deep_delete(); }
#line 2089 "bison_parser.cpp"
        break;

    case 177: /* pexpire_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).pexpire_stmt_t)!=NULL)((*yyvaluep).pexpire_stmt_t)->deep_delete(); }
#line 2095 "bison_parser.cpp"
        break;

    case 178: /* pexpireat_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).pexpireat_stmt_t)!=NULL)((*yyvaluep).pexpireat_stmt_t)->deep_delete(); }
#line 2101 "bison_parser.cpp"
        break;

    case 179: /* pttl_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).pttl_stmt_t)!=NULL)((*yyvaluep).pttl_stmt_t)->deep_delete(); }
#line 2107 "bison_parser.cpp"
        break;

    case 180: /* randomkey_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).randomkey_stmt_t)!=NULL)((*yyvaluep).randomkey_stmt_t)->deep_delete(); }
#line 2113 "bison_parser.cpp"
        break;

    case 181: /* rename_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).rename_stmt_t)!=NULL)((*yyvaluep).rename_stmt_t)->deep_delete(); }
#line 2119 "bison_parser.cpp"
        break;

    case 182: /* renamenx_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).renamenx_stmt_t)!=NULL)((*yyvaluep).renamenx_stmt_t)->deep_delete(); }
#line 2125 "bison_parser.cpp"
        break;

    case 183: /* aliasname  */
#line 399 "bison.y"
            { if(((*yyvaluep).aliasname_t)!=NULL)((*yyvaluep).aliasname_t)->deep_delete(); }
#line 2131 "bison_parser.cpp"
        break;

    case 184: /* sort_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).sort_stmt_t)!=NULL)((*yyvaluep).sort_stmt_t)->deep_delete(); }
#line 2137 "bison_parser.cpp"
        break;

    case 185: /* sort_clause  */
#line 399 "bison.y"
            { if(((*yyvaluep).sort_clause_t)!=NULL)((*yyvaluep).sort_clause_t)->deep_delete(); }
#line 2143 "bison_parser.cpp"
        break;

    case 186: /* opt_by_clause  */
#line 399 "bison.y"
            { if(((*yyvaluep).opt_by_clause_t)!=NULL)((*yyvaluep).opt_by_clause_t)->deep_delete(); }
#line 2149 "bison_parser.cpp"
        break;

    case 187: /* opt_limit_clause  */
#line 399 "bison.y"
            { if(((*yyvaluep).opt_limit_clause_t)!=NULL)((*yyvaluep).opt_limit_clause_t)->deep_delete(); }
#line 2155 "bison_parser.cpp"
        break;

    case 188: /* opt_store_clause  */
#line 399 "bison.y"
            { if(((*yyvaluep).opt_store_clause_t)!=NULL)((*yyvaluep).opt_store_clause_t)->deep_delete(); }
#line 2161 "bison_parser.cpp"
        break;

    case 189: /* opt_sort_behavior  */
#line 399 "bison.y"
            { if(((*yyvaluep).opt_sort_behavior_t)!=NULL)((*yyvaluep).opt_sort_behavior_t)->deep_delete(); }
#line 2167 "bison_parser.cpp"
        break;

    case 190: /* ttl_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).ttl_stmt_t)!=NULL)((*yyvaluep).ttl_stmt_t)->deep_delete(); }
#line 2173 "bison_parser.cpp"
        break;

    case 191: /* type_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).type_stmt_t)!=NULL)((*yyvaluep).type_stmt_t)->deep_delete(); }
#line 2179 "bison_parser.cpp"
        break;

    case 192: /* append_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).append_stmt_t)!=NULL)((*yyvaluep).append_stmt_t)->deep_delete(); }
#line 2185 "bison_parser.cpp"
        break;

    case 193: /* bicount_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).bicount_stmt_t)!=NULL)((*yyvaluep).bicount_stmt_t)->deep_delete(); }
#line 2191 "bison_parser.cpp"
        break;

    case 194: /* setbit_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).setbit_stmt_t)!=NULL)((*yyvaluep).setbit_stmt_t)->deep_delete(); }
#line 2197 "bison_parser.cpp"
        break;

    case 195: /* bitop_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).bitop_stmt_t)!=NULL)((*yyvaluep).bitop_stmt_t)->deep_delete(); }
#line 2203 "bison_parser.cpp"
        break;

    case 196: /* operation  */
#line 399 "bison.y"
            { if(((*yyvaluep).operation_t)!=NULL)((*yyvaluep).operation_t)->deep_delete(); }
#line 2209 "bison_parser.cpp"
        break;

    case 197: /* decr_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).decr_stmt_t)!=NULL)((*yyvaluep).decr_stmt_t)->deep_delete(); }
#line 2215 "bison_parser.cpp"
        break;

    case 198: /* decrby_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).decrby_stmt_t)!=NULL)((*yyvaluep).decrby_stmt_t)->deep_delete(); }
#line 2221 "bison_parser.cpp"
        break;

    case 199: /* get_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).get_stmt_t)!=NULL)((*yyvaluep).get_stmt_t)->deep_delete(); }
#line 2227 "bison_parser.cpp"
        break;

    case 200: /* getbit_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).getbit_stmt_t)!=NULL)((*yyvaluep).getbit_stmt_t)->deep_delete(); }
#line 2233 "bison_parser.cpp"
        break;

    case 201: /* getrange_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).getrange_stmt_t)!=NULL)((*yyvaluep).getrange_stmt_t)->deep_delete(); }
#line 2239 "bison_parser.cpp"
        break;

    case 202: /* getset_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).getset_stmt_t)!=NULL)((*yyvaluep).getset_stmt_t)->deep_delete(); }
#line 2245 "bison_parser.cpp"
        break;

    case 203: /* incr_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).incr_stmt_t)!=NULL)((*yyvaluep).incr_stmt_t)->deep_delete(); }
#line 2251 "bison_parser.cpp"
        break;

    case 204: /* incrby_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).incrby_stmt_t)!=NULL)((*yyvaluep).incrby_stmt_t)->deep_delete(); }
#line 2257 "bison_parser.cpp"
        break;

    case 205: /* incrbyfloat_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).incrbyfloat_stmt_t)!=NULL)((*yyvaluep).incrbyfloat_stmt_t)->deep_delete(); }
#line 2263 "bison_parser.cpp"
        break;

    case 206: /* mget_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).mget_stmt_t)!=NULL)((*yyvaluep).mget_stmt_t)->deep_delete(); }
#line 2269 "bison_parser.cpp"
        break;

    case 207: /* mset_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).mset_stmt_t)!=NULL)((*yyvaluep).mset_stmt_t)->deep_delete(); }
#line 2275 "bison_parser.cpp"
        break;

    case 208: /* psetex_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).psetex_stmt_t)!=NULL)((*yyvaluep).psetex_stmt_t)->deep_delete(); }
#line 2281 "bison_parser.cpp"
        break;

    case 209: /* setkey_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).setkey_stmt_t)!=NULL)((*yyvaluep).setkey_stmt_t)->deep_delete(); }
#line 2287 "bison_parser.cpp"
        break;

    case 210: /* setkey_clause  */
#line 399 "bison.y"
            { if(((*yyvaluep).setkey_clause_t)!=NULL)((*yyvaluep).setkey_clause_t)->deep_delete(); }
#line 2293 "bison_parser.cpp"
        break;

    case 211: /* opt_expiretime_clause  */
#line 399 "bison.y"
            { if(((*yyvaluep).opt_expiretime_clause_t)!=NULL)((*yyvaluep).opt_expiretime_clause_t)->deep_delete(); }
#line 2299 "bison_parser.cpp"
        break;

    case 212: /* opt_setkey_behavior  */
#line 399 "bison.y"
            { if(((*yyvaluep).opt_setkey_behavior_t)!=NULL)((*yyvaluep).opt_setkey_behavior_t)->deep_delete(); }
#line 2305 "bison_parser.cpp"
        break;

    case 213: /* setex_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).setex_stmt_t)!=NULL)((*yyvaluep).setex_stmt_t)->deep_delete(); }
#line 2311 "bison_parser.cpp"
        break;

    case 214: /* setnx_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).setnx_stmt_t)!=NULL)((*yyvaluep).setnx_stmt_t)->deep_delete(); }
#line 2317 "bison_parser.cpp"
        break;

    case 215: /* setrange_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).setrange_stmt_t)!=NULL)((*yyvaluep).setrange_stmt_t)->deep_delete(); }
#line 2323 "bison_parser.cpp"
        break;

    case 216: /* strlen_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).strlen_stmt_t)!=NULL)((*yyvaluep).strlen_stmt_t)->deep_delete(); }
#line 2329 "bison_parser.cpp"
        break;

    case 217: /* hdel_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hdel_stmt_t)!=NULL)((*yyvaluep).hdel_stmt_t)->deep_delete(); }
#line 2335 "bison_parser.cpp"
        break;

    case 218: /* hexists_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hexists_stmt_t)!=NULL)((*yyvaluep).hexists_stmt_t)->deep_delete(); }
#line 2341 "bison_parser.cpp"
        break;

    case 219: /* hget_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hget_stmt_t)!=NULL)((*yyvaluep).hget_stmt_t)->deep_delete(); }
#line 2347 "bison_parser.cpp"
        break;

    case 220: /* hgetall_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hgetall_stmt_t)!=NULL)((*yyvaluep).hgetall_stmt_t)->deep_delete(); }
#line 2353 "bison_parser.cpp"
        break;

    case 221: /* hincrby_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hincrby_stmt_t)!=NULL)((*yyvaluep).hincrby_stmt_t)->deep_delete(); }
#line 2359 "bison_parser.cpp"
        break;

    case 222: /* hincrbyfloat_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hincrbyfloat_stmt_t)!=NULL)((*yyvaluep).hincrbyfloat_stmt_t)->deep_delete(); }
#line 2365 "bison_parser.cpp"
        break;

    case 223: /* hkeys_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hkeys_stmt_t)!=NULL)((*yyvaluep).hkeys_stmt_t)->deep_delete(); }
#line 2371 "bison_parser.cpp"
        break;

    case 224: /* hlen_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hlen_stmt_t)!=NULL)((*yyvaluep).hlen_stmt_t)->deep_delete(); }
#line 2377 "bison_parser.cpp"
        break;

    case 225: /* hmget_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hmget_stmt_t)!=NULL)((*yyvaluep).hmget_stmt_t)->deep_delete(); }
#line 2383 "bison_parser.cpp"
        break;

    case 226: /* hmset_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hmset_stmt_t)!=NULL)((*yyvaluep).hmset_stmt_t)->deep_delete(); }
#line 2389 "bison_parser.cpp"
        break;

    case 227: /* hset_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hset_stmt_t)!=NULL)((*yyvaluep).hset_stmt_t)->deep_delete(); }
#line 2395 "bison_parser.cpp"
        break;

    case 228: /* hsetnx_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hsetnx_stmt_t)!=NULL)((*yyvaluep).hsetnx_stmt_t)->deep_delete(); }
#line 2401 "bison_parser.cpp"
        break;

    case 229: /* hvals_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).hvals_stmt_t)!=NULL)((*yyvaluep).hvals_stmt_t)->deep_delete(); }
#line 2407 "bison_parser.cpp"
        break;

    case 230: /* lindex_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).lindex_stmt_t)!=NULL)((*yyvaluep).lindex_stmt_t)->deep_delete(); }
#line 2413 "bison_parser.cpp"
        break;

    case 231: /* linsert_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).linsert_stmt_t)!=NULL)((*yyvaluep).linsert_stmt_t)->deep_delete(); }
#line 2419 "bison_parser.cpp"
        break;

    case 232: /* opt_linsert_behavior  */
#line 399 "bison.y"
            { if(((*yyvaluep).opt_linsert_behavior_t)!=NULL)((*yyvaluep).opt_linsert_behavior_t)->deep_delete(); }
#line 2425 "bison_parser.cpp"
        break;

    case 233: /* llen_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).llen_stmt_t)!=NULL)((*yyvaluep).llen_stmt_t)->deep_delete(); }
#line 2431 "bison_parser.cpp"
        break;

    case 234: /* lpop_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).lpop_stmt_t)!=NULL)((*yyvaluep).lpop_stmt_t)->deep_delete(); }
#line 2437 "bison_parser.cpp"
        break;

    case 235: /* lpush_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).lpush_stmt_t)!=NULL)((*yyvaluep).lpush_stmt_t)->deep_delete(); }
#line 2443 "bison_parser.cpp"
        break;

    case 236: /* lpushx_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).lpushx_stmt_t)!=NULL)((*yyvaluep).lpushx_stmt_t)->deep_delete(); }
#line 2449 "bison_parser.cpp"
        break;

    case 237: /* lrange_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).lrange_stmt_t)!=NULL)((*yyvaluep).lrange_stmt_t)->deep_delete(); }
#line 2455 "bison_parser.cpp"
        break;

    case 238: /* lrem_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).lrem_stmt_t)!=NULL)((*yyvaluep).lrem_stmt_t)->deep_delete(); }
#line 2461 "bison_parser.cpp"
        break;

    case 239: /* lset_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).lset_stmt_t)!=NULL)((*yyvaluep).lset_stmt_t)->deep_delete(); }
#line 2467 "bison_parser.cpp"
        break;

    case 240: /* ltrim_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).ltrim_stmt_t)!=NULL)((*yyvaluep).ltrim_stmt_t)->deep_delete(); }
#line 2473 "bison_parser.cpp"
        break;

    case 241: /* rpop_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).rpop_stmt_t)!=NULL)((*yyvaluep).rpop_stmt_t)->deep_delete(); }
#line 2479 "bison_parser.cpp"
        break;

    case 242: /* rpoplpush_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).rpoplpush_stmt_t)!=NULL)((*yyvaluep).rpoplpush_stmt_t)->deep_delete(); }
#line 2485 "bison_parser.cpp"
        break;

    case 243: /* rpush_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).rpush_stmt_t)!=NULL)((*yyvaluep).rpush_stmt_t)->deep_delete(); }
#line 2491 "bison_parser.cpp"
        break;

    case 244: /* rpushx_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).rpushx_stmt_t)!=NULL)((*yyvaluep).rpushx_stmt_t)->deep_delete(); }
#line 2497 "bison_parser.cpp"
        break;

    case 245: /* sadd_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).sadd_stmt_t)!=NULL)((*yyvaluep).sadd_stmt_t)->deep_delete(); }
#line 2503 "bison_parser.cpp"
        break;

    case 246: /* scard_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).scard_stmt_t)!=NULL)((*yyvaluep).scard_stmt_t)->deep_delete(); }
#line 2509 "bison_parser.cpp"
        break;

    case 247: /* sdiff_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).sdiff_stmt_t)!=NULL)((*yyvaluep).sdiff_stmt_t)->deep_delete(); }
#line 2515 "bison_parser.cpp"
        break;

    case 248: /* sdiffstore_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).sdiffstore_stmt_t)!=NULL)((*yyvaluep).sdiffstore_stmt_t)->deep_delete(); }
#line 2521 "bison_parser.cpp"
        break;

    case 249: /* sinter_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).sinter_stmt_t)!=NULL)((*yyvaluep).sinter_stmt_t)->deep_delete(); }
#line 2527 "bison_parser.cpp"
        break;

    case 250: /* sinterstore_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).sinterstore_stmt_t)!=NULL)((*yyvaluep).sinterstore_stmt_t)->deep_delete(); }
#line 2533 "bison_parser.cpp"
        break;

    case 251: /* sismember_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).sismember_stmt_t)!=NULL)((*yyvaluep).sismember_stmt_t)->deep_delete(); }
#line 2539 "bison_parser.cpp"
        break;

    case 252: /* smember_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).smember_stmt_t)!=NULL)((*yyvaluep).smember_stmt_t)->deep_delete(); }
#line 2545 "bison_parser.cpp"
        break;

    case 253: /* smove_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).smove_stmt_t)!=NULL)((*yyvaluep).smove_stmt_t)->deep_delete(); }
#line 2551 "bison_parser.cpp"
        break;

    case 254: /* spop_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).spop_stmt_t)!=NULL)((*yyvaluep).spop_stmt_t)->deep_delete(); }
#line 2557 "bison_parser.cpp"
        break;

    case 255: /* srandmember_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).srandmember_stmt_t)!=NULL)((*yyvaluep).srandmember_stmt_t)->deep_delete(); }
#line 2563 "bison_parser.cpp"
        break;

    case 256: /* srem_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).srem_stmt_t)!=NULL)((*yyvaluep).srem_stmt_t)->deep_delete(); }
#line 2569 "bison_parser.cpp"
        break;

    case 257: /* sunion_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).sunion_stmt_t)!=NULL)((*yyvaluep).sunion_stmt_t)->deep_delete(); }
#line 2575 "bison_parser.cpp"
        break;

    case 258: /* sunionstore_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).sunionstore_stmt_t)!=NULL)((*yyvaluep).sunionstore_stmt_t)->deep_delete(); }
#line 2581 "bison_parser.cpp"
        break;

    case 259: /* zadd_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zadd_stmt_t)!=NULL)((*yyvaluep).zadd_stmt_t)->deep_delete(); }
#line 2587 "bison_parser.cpp"
        break;

    case 260: /* zcard_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zcard_stmt_t)!=NULL)((*yyvaluep).zcard_stmt_t)->deep_delete(); }
#line 2593 "bison_parser.cpp"
        break;

    case 261: /* zcount_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zcount_stmt_t)!=NULL)((*yyvaluep).zcount_stmt_t)->deep_delete(); }
#line 2599 "bison_parser.cpp"
        break;

    case 262: /* zincrby_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zincrby_stmt_t)!=NULL)((*yyvaluep).zincrby_stmt_t)->deep_delete(); }
#line 2605 "bison_parser.cpp"
        break;

    case 263: /* zrange_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zrange_stmt_t)!=NULL)((*yyvaluep).zrange_stmt_t)->deep_delete(); }
#line 2611 "bison_parser.cpp"
        break;

    case 264: /* opt_zrange_behavior  */
#line 399 "bison.y"
            { if(((*yyvaluep).opt_zrange_behavior_t)!=NULL)((*yyvaluep).opt_zrange_behavior_t)->deep_delete(); }
#line 2617 "bison_parser.cpp"
        break;

    case 265: /* zrangebyscore_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zrangebyscore_stmt_t)!=NULL)((*yyvaluep).zrangebyscore_stmt_t)->deep_delete(); }
#line 2623 "bison_parser.cpp"
        break;

    case 266: /* zrangebyscore_clause  */
#line 399 "bison.y"
            { if(((*yyvaluep).zrangebyscore_clause_t)!=NULL)((*yyvaluep).zrangebyscore_clause_t)->deep_delete(); }
#line 2629 "bison_parser.cpp"
        break;

    case 267: /* zrank_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zrank_stmt_t)!=NULL)((*yyvaluep).zrank_stmt_t)->deep_delete(); }
#line 2635 "bison_parser.cpp"
        break;

    case 268: /* zrem_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zrem_stmt_t)!=NULL)((*yyvaluep).zrem_stmt_t)->deep_delete(); }
#line 2641 "bison_parser.cpp"
        break;

    case 269: /* zscore_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zscore_stmt_t)!=NULL)((*yyvaluep).zscore_stmt_t)->deep_delete(); }
#line 2647 "bison_parser.cpp"
        break;

    case 270: /* zunionstore_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zunionstore_stmt_t)!=NULL)((*yyvaluep).zunionstore_stmt_t)->deep_delete(); }
#line 2653 "bison_parser.cpp"
        break;

    case 271: /* zunionstore_clause  */
#line 399 "bison.y"
            { if(((*yyvaluep).zunionstore_clause_t)!=NULL)((*yyvaluep).zunionstore_clause_t)->deep_delete(); }
#line 2659 "bison_parser.cpp"
        break;

    case 272: /* opt_weight_clause  */
#line 399 "bison.y"
            { if(((*yyvaluep).opt_weight_clause_t)!=NULL)((*yyvaluep).opt_weight_clause_t)->deep_delete(); }
#line 2665 "bison_parser.cpp"
        break;

    case 273: /* opt_aggregate_clause  */
#line 399 "bison.y"
            { if(((*yyvaluep).opt_aggregate_clause_t)!=NULL)((*yyvaluep).opt_aggregate_clause_t)->deep_delete(); }
#line 2671 "bison_parser.cpp"
        break;

    case 274: /* zinterstore_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).zinterstore_stmt_t)!=NULL)((*yyvaluep).zinterstore_stmt_t)->deep_delete(); }
#line 2677 "bison_parser.cpp"
        break;

    case 275: /* zinterstore_clause  */
#line 399 "bison.y"
            { if(((*yyvaluep).zinterstore_clause_t)!=NULL)((*yyvaluep).zinterstore_clause_t)->deep_delete(); }
#line 2683 "bison_parser.cpp"
        break;

    case 276: /* select_stmt  */
#line 399 "bison.y"
            { if(((*yyvaluep).select_stmt_t)!=NULL)((*yyvaluep).select_stmt_t)->deep_delete(); }
#line 2689 "bison_parser.cpp"
        break;

    case 277: /* key_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_list_t)!=NULL)((*yyvaluep).key_list_t)->deep_delete(); }
#line 2695 "bison_parser.cpp"
        break;

    case 278: /* keyname  */
#line 399 "bison.y"
            { if(((*yyvaluep).keyname_t)!=NULL)((*yyvaluep).keyname_t)->deep_delete(); }
#line 2701 "bison_parser.cpp"
        break;

    case 279: /* value  */
#line 399 "bison.y"
            { if(((*yyvaluep).value_t)!=NULL)((*yyvaluep).value_t)->deep_delete(); }
#line 2707 "bison_parser.cpp"
        break;

    case 280: /* value_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).value_list_t)!=NULL)((*yyvaluep).value_list_t)->deep_delete(); }
#line 2713 "bison_parser.cpp"
        break;

    case 281: /* key_string_name  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_string_name_t)!=NULL)((*yyvaluep).key_string_name_t)->deep_delete(); }
#line 2719 "bison_parser.cpp"
        break;

    case 282: /* key_string_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_string_list_t)!=NULL)((*yyvaluep).key_string_list_t)->deep_delete(); }
#line 2725 "bison_parser.cpp"
        break;

    case 283: /* key_string_value_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_string_value_list_t)!=NULL)((*yyvaluep).key_string_value_list_t)->deep_delete(); }
#line 2731 "bison_parser.cpp"
        break;

    case 284: /* key_string_value  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_string_value_t)!=NULL)((*yyvaluep).key_string_value_t)->deep_delete(); }
#line 2737 "bison_parser.cpp"
        break;

    case 285: /* key_hash_name  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_hash_name_t)!=NULL)((*yyvaluep).key_hash_name_t)->deep_delete(); }
#line 2743 "bison_parser.cpp"
        break;

    case 286: /* field_name  */
#line 399 "bison.y"
            { if(((*yyvaluep).field_name_t)!=NULL)((*yyvaluep).field_name_t)->deep_delete(); }
#line 2749 "bison_parser.cpp"
        break;

    case 287: /* del_field_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).del_field_list_t)!=NULL)((*yyvaluep).del_field_list_t)->deep_delete(); }
#line 2755 "bison_parser.cpp"
        break;

    case 288: /* field_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).field_list_t)!=NULL)((*yyvaluep).field_list_t)->deep_delete(); }
#line 2761 "bison_parser.cpp"
        break;

    case 289: /* field_value  */
#line 399 "bison.y"
            { if(((*yyvaluep).field_value_t)!=NULL)((*yyvaluep).field_value_t)->deep_delete(); }
#line 2767 "bison_parser.cpp"
        break;

    case 290: /* field_value_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).field_value_list_t)!=NULL)((*yyvaluep).field_value_list_t)->deep_delete(); }
#line 2773 "bison_parser.cpp"
        break;

    case 291: /* key_list_name  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_list_name_t)!=NULL)((*yyvaluep).key_list_name_t)->deep_delete(); }
#line 2779 "bison_parser.cpp"
        break;

    case 292: /* key_set_name  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_set_name_t)!=NULL)((*yyvaluep).key_set_name_t)->deep_delete(); }
#line 2785 "bison_parser.cpp"
        break;

    case 293: /* del_key_set_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).del_key_set_list_t)!=NULL)((*yyvaluep).del_key_set_list_t)->deep_delete(); }
#line 2791 "bison_parser.cpp"
        break;

    case 294: /* key_set_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_set_list_t)!=NULL)((*yyvaluep).key_set_list_t)->deep_delete(); }
#line 2797 "bison_parser.cpp"
        break;

    case 295: /* smember_name  */
#line 399 "bison.y"
            { if(((*yyvaluep).smember_name_t)!=NULL)((*yyvaluep).smember_name_t)->deep_delete(); }
#line 2803 "bison_parser.cpp"
        break;

    case 296: /* smember_name_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).smember_name_list_t)!=NULL)((*yyvaluep).smember_name_list_t)->deep_delete(); }
#line 2809 "bison_parser.cpp"
        break;

    case 297: /* key_zset_name  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_zset_name_t)!=NULL)((*yyvaluep).key_zset_name_t)->deep_delete(); }
#line 2815 "bison_parser.cpp"
        break;

    case 298: /* key_zset_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).key_zset_list_t)!=NULL)((*yyvaluep).key_zset_list_t)->deep_delete(); }
#line 2821 "bison_parser.cpp"
        break;

    case 299: /* zmember_name  */
#line 399 "bison.y"
            { if(((*yyvaluep).zmember_name_t)!=NULL)((*yyvaluep).zmember_name_t)->deep_delete(); }
#line 2827 "bison_parser.cpp"
        break;

    case 300: /* zmember_name_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).zmember_name_list_t)!=NULL)((*yyvaluep).zmember_name_list_t)->deep_delete(); }
#line 2833 "bison_parser.cpp"
        break;

    case 301: /* zmember_value  */
#line 399 "bison.y"
            { if(((*yyvaluep).zmember_value_t)!=NULL)((*yyvaluep).zmember_value_t)->deep_delete(); }
#line 2839 "bison_parser.cpp"
        break;

    case 302: /* zmember_value_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).zmember_value_list_t)!=NULL)((*yyvaluep).zmember_value_list_t)->deep_delete(); }
#line 2845 "bison_parser.cpp"
        break;

    case 303: /* timesecond  */
#line 399 "bison.y"
            { if(((*yyvaluep).timesecond_t)!=NULL)((*yyvaluep).timesecond_t)->deep_delete(); }
#line 2851 "bison_parser.cpp"
        break;

    case 304: /* timeunix  */
#line 399 "bison.y"
            { if(((*yyvaluep).timeunix_t)!=NULL)((*yyvaluep).timeunix_t)->deep_delete(); }
#line 2857 "bison_parser.cpp"
        break;

    case 305: /* operandnum  */
#line 399 "bison.y"
            { if(((*yyvaluep).operandnum_t)!=NULL)((*yyvaluep).operandnum_t)->deep_delete(); }
#line 2863 "bison_parser.cpp"
        break;

    case 306: /* operandnum_list  */
#line 399 "bison.y"
            { if(((*yyvaluep).operandnum_list_t)!=NULL)((*yyvaluep).operandnum_list_t)->deep_delete(); }
#line 2869 "bison_parser.cpp"
        break;

    case 307: /* identifier  */
#line 399 "bison.y"
            { if(((*yyvaluep).identifier_t)!=NULL)((*yyvaluep).identifier_t)->deep_delete(); }
#line 2875 "bison_parser.cpp"
        break;

    case 308: /* literal  */
#line 399 "bison.y"
            { if(((*yyvaluep).literal_t)!=NULL)((*yyvaluep).literal_t)->deep_delete(); }
#line 2881 "bison_parser.cpp"
        break;

    case 309: /* string_literal  */
#line 399 "bison.y"
            { if(((*yyvaluep).string_literal_t)!=NULL)((*yyvaluep).string_literal_t)->deep_delete(); }
#line 2887 "bison_parser.cpp"
        break;

    case 310: /* num_literal  */
#line 399 "bison.y"
            { if(((*yyvaluep).num_literal_t)!=NULL)((*yyvaluep).num_literal_t)->deep_delete(); }
#line 2893 "bison_parser.cpp"
        break;

    case 311: /* int_literal  */
#line 399 "bison.y"
            { if(((*yyvaluep).int_literal_t)!=NULL)((*yyvaluep).int_literal_t)->deep_delete(); }
#line 2899 "bison_parser.cpp"
        break;

    case 312: /* float_literal  */
#line 399 "bison.y"
            { if(((*yyvaluep).float_literal_t)!=NULL)((*yyvaluep).float_literal_t)->deep_delete(); }
#line 2905 "bison_parser.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (Program* result, yyscan_t scanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined FF_LTYPE_IS_TRIVIAL && FF_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 18 "bison.y"
{
    // Initialize
    yylloc.first_column = 0;
    yylloc.last_column = 0;
    yylloc.first_line = 0;
    yylloc.last_line = 0;
    yylloc.total_column = 0;
    yylloc.string_length = 0;
}

#line 3023 "bison_parser.cpp"

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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval, &yylloc, scanner);
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
  case 2:
#line 403 "bison.y"
                  {
		(yyval.program_t) = result;
		(yyval.program_t)->case_idx_ = CASE0;
		(yyval.program_t)->stmtlist_ = (yyvsp[0].stmtlist_t);
		(yyval.program_t) = NULL;

	}
#line 3228 "bison_parser.cpp"
    break;

  case 3:
#line 413 "bison.y"
             {
		(yyval.stmtlist_t) = new Stmtlist();
		(yyval.stmtlist_t)->case_idx_ = CASE0;
		(yyval.stmtlist_t)->stmt_ = (yyvsp[0].stmt_t);
	}
#line 3238 "bison_parser.cpp"
    break;

  case 4:
#line 418 "bison.y"
                      {
	    (yyval.stmtlist_t) = new Stmtlist();
		(yyval.stmtlist_t)->case_idx_ = CASE1;
		(yyval.stmtlist_t)->stmt_ = (yyvsp[-1].stmt_t);
		(yyval.stmtlist_t)->stmtlist_ = (yyvsp[0].stmtlist_t);
   }
#line 3249 "bison_parser.cpp"
    break;

  case 5:
#line 427 "bison.y"
                      {
		(yyval.stmt_t) = new Stmt();
		(yyval.stmt_t)->case_idx_ = CASE0;
		(yyval.stmt_t)->key_stmt_ = (yyvsp[0].key_stmt_t);
		
	}
#line 3260 "bison_parser.cpp"
    break;

  case 6:
#line 433 "bison.y"
                     {
		(yyval.stmt_t) = new Stmt();
		(yyval.stmt_t)->case_idx_ = CASE1;
		(yyval.stmt_t)->string_stmt_ = (yyvsp[0].string_stmt_t);
		
	}
#line 3271 "bison_parser.cpp"
    break;

  case 7:
#line 439 "bison.y"
                   {
		(yyval.stmt_t) = new Stmt();
		(yyval.stmt_t)->case_idx_ = CASE2;
		(yyval.stmt_t)->hash_stmt_ = (yyvsp[0].hash_stmt_t);
		
	}
#line 3282 "bison_parser.cpp"
    break;

  case 8:
#line 445 "bison.y"
                   {
		(yyval.stmt_t) = new Stmt();
		(yyval.stmt_t)->case_idx_ = CASE3;
		(yyval.stmt_t)->list_stmt_ = (yyvsp[0].list_stmt_t);
		
	}
#line 3293 "bison_parser.cpp"
    break;

  case 9:
#line 451 "bison.y"
                  {
		(yyval.stmt_t) = new Stmt();
		(yyval.stmt_t)->case_idx_ = CASE4;
		(yyval.stmt_t)->set_stmt_ = (yyvsp[0].set_stmt_t);
		
	}
#line 3304 "bison_parser.cpp"
    break;

  case 10:
#line 457 "bison.y"
                   {
		(yyval.stmt_t) = new Stmt();
		(yyval.stmt_t)->case_idx_ = CASE5;
		(yyval.stmt_t)->zset_stmt_ = (yyvsp[0].zset_stmt_t);
		
	}
#line 3315 "bison_parser.cpp"
    break;

  case 11:
#line 463 "bison.y"
                     {
        (yyval.stmt_t) = new Stmt();
        (yyval.stmt_t)->case_idx_ = CASE6;
		(yyval.stmt_t)->connect_stmt_ = (yyvsp[0].connect_stmt_t);
   }
#line 3325 "bison_parser.cpp"
    break;

  case 12:
#line 471 "bison.y"
                      {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE0;
		(yyval.key_stmt_t)->del_stmt_ = (yyvsp[0].del_stmt_t);
		
	}
#line 3336 "bison_parser.cpp"
    break;

  case 13:
#line 477 "bison.y"
                   {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE1;
		(yyval.key_stmt_t)->dump_stmt_ = (yyvsp[0].dump_stmt_t);
		
	}
#line 3347 "bison_parser.cpp"
    break;

  case 14:
#line 483 "bison.y"
                     {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE2;
		(yyval.key_stmt_t)->exists_stmt_ = (yyvsp[0].exists_stmt_t);
		
	}
#line 3358 "bison_parser.cpp"
    break;

  case 15:
#line 489 "bison.y"
                     {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE3;
		(yyval.key_stmt_t)->expire_stmt_ = (yyvsp[0].expire_stmt_t);
		
	}
#line 3369 "bison_parser.cpp"
    break;

  case 16:
#line 495 "bison.y"
                      {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE4;
		(yyval.key_stmt_t)->expireat_stmt_ = (yyvsp[0].expireat_stmt_t);
	}
#line 3379 "bison_parser.cpp"
    break;

  case 17:
#line 500 "bison.y"
                  {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE5;
		(yyval.key_stmt_t)->move_stmt_ = (yyvsp[0].move_stmt_t);
	}
#line 3389 "bison_parser.cpp"
    break;

  case 18:
#line 505 "bison.y"
                    {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE6;
		(yyval.key_stmt_t)->object_stmt_ = (yyvsp[0].object_stmt_t);
	}
#line 3399 "bison_parser.cpp"
    break;

  case 19:
#line 510 "bison.y"
                     {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE7;
		(yyval.key_stmt_t)->persist_stmt_ = (yyvsp[0].persist_stmt_t);
	}
#line 3409 "bison_parser.cpp"
    break;

  case 20:
#line 515 "bison.y"
                     {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE8;
		(yyval.key_stmt_t)->pexpire_stmt_ = (yyvsp[0].pexpire_stmt_t);
	}
#line 3419 "bison_parser.cpp"
    break;

  case 21:
#line 520 "bison.y"
                       {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE9;
		(yyval.key_stmt_t)->pexpireat_stmt_ = (yyvsp[0].pexpireat_stmt_t);
	}
#line 3429 "bison_parser.cpp"
    break;

  case 22:
#line 525 "bison.y"
                  {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE10;
		(yyval.key_stmt_t)->pttl_stmt_ = (yyvsp[0].pttl_stmt_t);
	}
#line 3439 "bison_parser.cpp"
    break;

  case 23:
#line 530 "bison.y"
                       {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE11;
		(yyval.key_stmt_t)->randomkey_stmt_ = (yyvsp[0].randomkey_stmt_t);
	}
#line 3449 "bison_parser.cpp"
    break;

  case 24:
#line 535 "bison.y"
                    {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE12;
		(yyval.key_stmt_t)->rname_stmt_ = (yyvsp[0].rename_stmt_t);
	}
#line 3459 "bison_parser.cpp"
    break;

  case 25:
#line 540 "bison.y"
                      {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE13;
		(yyval.key_stmt_t)->renamenx_stmt_ = (yyvsp[0].renamenx_stmt_t);
	}
#line 3469 "bison_parser.cpp"
    break;

  case 26:
#line 545 "bison.y"
                  {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE14;
		(yyval.key_stmt_t)->pttl_stmt_ = (yyvsp[0].sort_stmt_t);
	}
#line 3479 "bison_parser.cpp"
    break;

  case 27:
#line 550 "bison.y"
                 {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE15;
		(yyval.key_stmt_t)->ttl_stmt_ = (yyvsp[0].ttl_stmt_t);
	}
#line 3489 "bison_parser.cpp"
    break;

  case 28:
#line 555 "bison.y"
                  {
		(yyval.key_stmt_t) = new KeyStmt();
		(yyval.key_stmt_t)->case_idx_ = CASE16;
		(yyval.key_stmt_t)->type_stmt_ = (yyvsp[0].type_stmt_t);
	}
#line 3499 "bison_parser.cpp"
    break;

  case 29:
#line 564 "bison.y"
                     {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE0;
		(yyval.string_stmt_t)->append_stmt_ = (yyvsp[0].append_stmt_t);
		
	}
#line 3510 "bison_parser.cpp"
    break;

  case 30:
#line 570 "bison.y"
                      {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE1;
		(yyval.string_stmt_t)->bicount_stmt_ = (yyvsp[0].bicount_stmt_t);
		
	}
#line 3521 "bison_parser.cpp"
    break;

  case 31:
#line 576 "bison.y"
                     {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE2;
		(yyval.string_stmt_t)->setbit_stmt_ = (yyvsp[0].setbit_stmt_t);
		
	}
#line 3532 "bison_parser.cpp"
    break;

  case 32:
#line 582 "bison.y"
                    {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE3;
		(yyval.string_stmt_t)->bitop_stmt_ = (yyvsp[0].bitop_stmt_t);
		
	}
#line 3543 "bison_parser.cpp"
    break;

  case 33:
#line 588 "bison.y"
                   {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE4;
		(yyval.string_stmt_t)->decr_stmt_ = (yyvsp[0].decr_stmt_t);
		
	}
#line 3554 "bison_parser.cpp"
    break;

  case 34:
#line 594 "bison.y"
                     {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE5;
		(yyval.string_stmt_t)->decrby_stmtt_ = (yyvsp[0].decrby_stmt_t);
		
	}
#line 3565 "bison_parser.cpp"
    break;

  case 35:
#line 600 "bison.y"
                  {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE6;
		(yyval.string_stmt_t)->get_stmt_ = (yyvsp[0].get_stmt_t);
		
	}
#line 3576 "bison_parser.cpp"
    break;

  case 36:
#line 606 "bison.y"
                     {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE7;
		(yyval.string_stmt_t)->getbit_stmt_ = (yyvsp[0].getbit_stmt_t);
		
	}
#line 3587 "bison_parser.cpp"
    break;

  case 37:
#line 612 "bison.y"
                       {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE8;
		(yyval.string_stmt_t)->getrange_stmt_ = (yyvsp[0].getrange_stmt_t);
		
	}
#line 3598 "bison_parser.cpp"
    break;

  case 38:
#line 618 "bison.y"
                     {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE9;
		(yyval.string_stmt_t)->getset_stmt_ = (yyvsp[0].getset_stmt_t);
		
	}
#line 3609 "bison_parser.cpp"
    break;

  case 39:
#line 624 "bison.y"
                   {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE10;
		(yyval.string_stmt_t)->incr_stmt_ = (yyvsp[0].incr_stmt_t);
		
	}
#line 3620 "bison_parser.cpp"
    break;

  case 40:
#line 630 "bison.y"
                     {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE11;
		(yyval.string_stmt_t)->incrby_stmt_ = (yyvsp[0].incrby_stmt_t);
		
	}
#line 3631 "bison_parser.cpp"
    break;

  case 41:
#line 636 "bison.y"
                          {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE12;
		(yyval.string_stmt_t)->incrbyfloat_stmt_ = (yyvsp[0].incrbyfloat_stmt_t);
		
	}
#line 3642 "bison_parser.cpp"
    break;

  case 42:
#line 642 "bison.y"
                  {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE13;
		(yyval.string_stmt_t)->mget_stmt_ = (yyvsp[0].mget_stmt_t);
		
	}
#line 3653 "bison_parser.cpp"
    break;

  case 43:
#line 648 "bison.y"
                  {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE14;
		(yyval.string_stmt_t)->mset_stmt_ = (yyvsp[0].mset_stmt_t);
		
	}
#line 3664 "bison_parser.cpp"
    break;

  case 44:
#line 654 "bison.y"
                     {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE15;
		(yyval.string_stmt_t)->psetex_stmt_ = (yyvsp[0].psetex_stmt_t);
		
	}
#line 3675 "bison_parser.cpp"
    break;

  case 45:
#line 660 "bison.y"
                     {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE16;
		(yyval.string_stmt_t)->setkey_stmt_ = (yyvsp[0].setkey_stmt_t);
		
	}
#line 3686 "bison_parser.cpp"
    break;

  case 46:
#line 666 "bison.y"
                    {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE17;
		(yyval.string_stmt_t)->setex_stmt_ = (yyvsp[0].setex_stmt_t);
		
	}
#line 3697 "bison_parser.cpp"
    break;

  case 47:
#line 672 "bison.y"
                    {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE18;
		(yyval.string_stmt_t)->setnx_stmt_ = (yyvsp[0].setnx_stmt_t);
		
	}
#line 3708 "bison_parser.cpp"
    break;

  case 48:
#line 678 "bison.y"
                       {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE19;
		(yyval.string_stmt_t)->setrange_stmt_ = (yyvsp[0].setrange_stmt_t);
		
	}
#line 3719 "bison_parser.cpp"
    break;

  case 49:
#line 684 "bison.y"
                     {
		(yyval.string_stmt_t) = new StringStmt();
		(yyval.string_stmt_t)->case_idx_ = CASE20;
		(yyval.string_stmt_t)->strlen_stmt_ = (yyvsp[0].strlen_stmt_t);
		
	}
#line 3730 "bison_parser.cpp"
    break;

  case 50:
#line 694 "bison.y"
                           {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE0;
		(yyval.hash_stmt_t)->hdel_stmt_ = (yyvsp[0].hdel_stmt_t);
		
	}
#line 3741 "bison_parser.cpp"
    break;

  case 51:
#line 700 "bison.y"
                     {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE1;
		(yyval.hash_stmt_t)->hexists_stmt_ = (yyvsp[0].hexists_stmt_t);	    
    }
#line 3751 "bison_parser.cpp"
    break;

  case 52:
#line 705 "bison.y"
                  {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE2;
		(yyval.hash_stmt_t)->hget_stmt_ = (yyvsp[0].hget_stmt_t);	    
    }
#line 3761 "bison_parser.cpp"
    break;

  case 53:
#line 710 "bison.y"
                     {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE3;
		(yyval.hash_stmt_t)->hgetall_stmt_ = (yyvsp[0].hgetall_stmt_t);	    
    }
#line 3771 "bison_parser.cpp"
    break;

  case 54:
#line 715 "bison.y"
                     {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE4;
		(yyval.hash_stmt_t)->hincrby_stmt_ = (yyvsp[0].hincrby_stmt_t);	    
    }
#line 3781 "bison_parser.cpp"
    break;

  case 55:
#line 720 "bison.y"
                          {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE5;
		(yyval.hash_stmt_t)->hincrbyfloat_stmt_ = (yyvsp[0].hincrbyfloat_stmt_t);	    
    }
#line 3791 "bison_parser.cpp"
    break;

  case 56:
#line 725 "bison.y"
                   {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE6;
		(yyval.hash_stmt_t)->hkeys_stmt_ = (yyvsp[0].hkeys_stmt_t);	    
    }
#line 3801 "bison_parser.cpp"
    break;

  case 57:
#line 730 "bison.y"
                  {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE7;
		(yyval.hash_stmt_t)->hlen_stmt_ = (yyvsp[0].hlen_stmt_t);	    
    }
#line 3811 "bison_parser.cpp"
    break;

  case 58:
#line 735 "bison.y"
                   {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE8;
		(yyval.hash_stmt_t)->hmget_stmt_ = (yyvsp[0].hmget_stmt_t);	    
    }
#line 3821 "bison_parser.cpp"
    break;

  case 59:
#line 740 "bison.y"
                   {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE9;
		(yyval.hash_stmt_t)->hmset_stmt_ = (yyvsp[0].hmset_stmt_t);	    
    }
#line 3831 "bison_parser.cpp"
    break;

  case 60:
#line 745 "bison.y"
                  {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE10;
		(yyval.hash_stmt_t)->hset_stmt_ = (yyvsp[0].hset_stmt_t);	    
    }
#line 3841 "bison_parser.cpp"
    break;

  case 61:
#line 750 "bison.y"
                    {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE11;
		(yyval.hash_stmt_t)->hsetnx_stmt_ = (yyvsp[0].hsetnx_stmt_t);	    
    }
#line 3851 "bison_parser.cpp"
    break;

  case 62:
#line 755 "bison.y"
                   {
		(yyval.hash_stmt_t) = new HashStmt();
		(yyval.hash_stmt_t)->case_idx_ = CASE12;
		(yyval.hash_stmt_t)->hvals_stmt_ = (yyvsp[0].hvals_stmt_t);	    
    }
#line 3861 "bison_parser.cpp"
    break;

  case 63:
#line 764 "bison.y"
                             {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE0;
		(yyval.list_stmt_t)->lindex_stmt_ = (yyvsp[0].lindex_stmt_t);
		
	}
#line 3872 "bison_parser.cpp"
    break;

  case 64:
#line 770 "bison.y"
                     { 
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE1;
		(yyval.list_stmt_t)->linsert_stmt_ = (yyvsp[0].linsert_stmt_t);	    
    }
#line 3882 "bison_parser.cpp"
    break;

  case 65:
#line 775 "bison.y"
                  {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE2;
		(yyval.list_stmt_t)->llen_stmt_ = (yyvsp[0].llen_stmt_t);	    
    }
#line 3892 "bison_parser.cpp"
    break;

  case 66:
#line 780 "bison.y"
                  {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE3;
		(yyval.list_stmt_t)->lpop_stmt_ = (yyvsp[0].lpop_stmt_t);	    
    }
#line 3902 "bison_parser.cpp"
    break;

  case 67:
#line 785 "bison.y"
                   {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE4;
		(yyval.list_stmt_t)->lpush_stmt_ = (yyvsp[0].lpush_stmt_t);	    
    }
#line 3912 "bison_parser.cpp"
    break;

  case 68:
#line 790 "bison.y"
                    {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE5;
		(yyval.list_stmt_t)->lpushx_stmt_ = (yyvsp[0].lpushx_stmt_t);	    
    }
#line 3922 "bison_parser.cpp"
    break;

  case 69:
#line 795 "bison.y"
                    {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE6;
		(yyval.list_stmt_t)->lrange_stmt_ = (yyvsp[0].lrange_stmt_t);	    
    }
#line 3932 "bison_parser.cpp"
    break;

  case 70:
#line 800 "bison.y"
                  {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE7;
		(yyval.list_stmt_t)->lrem_stmt_ = (yyvsp[0].lrem_stmt_t);	    
    }
#line 3942 "bison_parser.cpp"
    break;

  case 71:
#line 805 "bison.y"
                  {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE8;
		(yyval.list_stmt_t)->lset_stmt_ = (yyvsp[0].lset_stmt_t);	    
    }
#line 3952 "bison_parser.cpp"
    break;

  case 72:
#line 810 "bison.y"
                   {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE9;
		(yyval.list_stmt_t)->ltrim_stmt_ = (yyvsp[0].ltrim_stmt_t);	    
    }
#line 3962 "bison_parser.cpp"
    break;

  case 73:
#line 815 "bison.y"
                  {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE10;
		(yyval.list_stmt_t)->rpop_stmt_ = (yyvsp[0].rpop_stmt_t);	    
    }
#line 3972 "bison_parser.cpp"
    break;

  case 74:
#line 820 "bison.y"
                       {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE11;
		(yyval.list_stmt_t)->rpoplpush_stmt_ = (yyvsp[0].rpoplpush_stmt_t);	    
    }
#line 3982 "bison_parser.cpp"
    break;

  case 75:
#line 825 "bison.y"
                   {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE12;
		(yyval.list_stmt_t)->rpush_stmt_ = (yyvsp[0].rpush_stmt_t);	    
    }
#line 3992 "bison_parser.cpp"
    break;

  case 76:
#line 830 "bison.y"
                    {
		(yyval.list_stmt_t) = new ListStmt();
		(yyval.list_stmt_t)->case_idx_ = CASE13;
		(yyval.list_stmt_t)->rpushx_stmt_ = (yyvsp[0].rpushx_stmt_t);	    
    }
#line 4002 "bison_parser.cpp"
    break;

  case 77:
#line 839 "bison.y"
                          {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE0;
		(yyval.set_stmt_t)->sadd_stmt__ = (yyvsp[0].sadd_stmt_t);
		
	}
#line 4013 "bison_parser.cpp"
    break;

  case 78:
#line 845 "bison.y"
                   {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE1;
		(yyval.set_stmt_t)->scard_stmt_ = (yyvsp[0].scard_stmt_t);	    
    }
#line 4023 "bison_parser.cpp"
    break;

  case 79:
#line 850 "bison.y"
                   {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE2;
		(yyval.set_stmt_t)->sdiff_stmt_ = (yyvsp[0].sdiff_stmt_t);	    
    }
#line 4033 "bison_parser.cpp"
    break;

  case 80:
#line 855 "bison.y"
                        {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE3;
		(yyval.set_stmt_t)->sdiffstore_stmt_ = (yyvsp[0].sdiffstore_stmt_t);	    
    }
#line 4043 "bison_parser.cpp"
    break;

  case 81:
#line 860 "bison.y"
                    {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE4;
		(yyval.set_stmt_t)->sinter_stmt_ = (yyvsp[0].sinter_stmt_t);	    
    }
#line 4053 "bison_parser.cpp"
    break;

  case 82:
#line 865 "bison.y"
                         {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE5;
		(yyval.set_stmt_t)->sinterstore_stmt_ = (yyvsp[0].sinterstore_stmt_t);	    
    }
#line 4063 "bison_parser.cpp"
    break;

  case 83:
#line 870 "bison.y"
                       {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE6;
		(yyval.set_stmt_t)->sismember_stmt_ = (yyvsp[0].sismember_stmt_t);	    
    }
#line 4073 "bison_parser.cpp"
    break;

  case 84:
#line 875 "bison.y"
                     {
		(yyval.set_stmt_t) = new SmemberStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE7;
		(yyval.set_stmt_t)->smember_stmt_  = (yyvsp[0].smember_stmt_t);	    
    }
#line 4083 "bison_parser.cpp"
    break;

  case 85:
#line 880 "bison.y"
                   {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE8;
		(yyval.set_stmt_t)->smove_stmt_ = (yyvsp[0].smove_stmt_t);	    
    }
#line 4093 "bison_parser.cpp"
    break;

  case 86:
#line 885 "bison.y"
                  {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE9;
		(yyval.set_stmt_t)->spop_stmt_ = (yyvsp[0].spop_stmt_t);	    
    }
#line 4103 "bison_parser.cpp"
    break;

  case 87:
#line 890 "bison.y"
                         {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE10;
		(yyval.set_stmt_t)->srandmember_stmt_ = (yyvsp[0].srandmember_stmt_t);	    
    }
#line 4113 "bison_parser.cpp"
    break;

  case 88:
#line 895 "bison.y"
                  {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE11;
		(yyval.set_stmt_t)->srem_stmt_ = (yyvsp[0].srem_stmt_t);	    
    }
#line 4123 "bison_parser.cpp"
    break;

  case 89:
#line 900 "bison.y"
                    {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE12;
		(yyval.set_stmt_t)->sunion_stmt_ = (yyvsp[0].sunion_stmt_t);	    
    }
#line 4133 "bison_parser.cpp"
    break;

  case 90:
#line 905 "bison.y"
                         {
		(yyval.set_stmt_t) = new SetStmt();
		(yyval.set_stmt_t)->case_idx_ = CASE13;
		(yyval.set_stmt_t)->sunionstore_stmt_ = (yyvsp[0].sunionstore_stmt_t);	    
    }
#line 4143 "bison_parser.cpp"
    break;

  case 91:
#line 913 "bison.y"
                          {
		(yyval.zset_stmt_t) = new ZaddStmt();
		(yyval.zset_stmt_t)->case_idx_ = CASE0;
		(yyval.zset_stmt_t)->zadd_stmt__ = (yyvsp[0].zadd_stmt_t);
		
	}
#line 4154 "bison_parser.cpp"
    break;

  case 92:
#line 919 "bison.y"
                   {
		(yyval.zset_stmt_t) = new ZaddStmt();
		(yyval.zset_stmt_t)->case_idx_ = CASE1;
		(yyval.zset_stmt_t)->zcard_stmt_ = (yyvsp[0].zcard_stmt_t);	    
    }
#line 4164 "bison_parser.cpp"
    break;

  case 93:
#line 924 "bison.y"
                    {
		(yyval.zset_stmt_t) = new ZaddStmt();
		(yyval.zset_stmt_t)->case_idx_ = CASE2;
		(yyval.zset_stmt_t)->zcount_stmt_ = (yyvsp[0].zcount_stmt_t);	    
    }
#line 4174 "bison_parser.cpp"
    break;

  case 94:
#line 929 "bison.y"
                     {
		(yyval.zset_stmt_t) = new ZaddStmt();
		(yyval.zset_stmt_t)->case_idx_ = CASE3;
		(yyval.zset_stmt_t)->zincrby_stmt_ = (yyvsp[0].zincrby_stmt_t);	    
    }
#line 4184 "bison_parser.cpp"
    break;

  case 95:
#line 934 "bison.y"
                    {
		(yyval.zset_stmt_t) = new ZaddStmt();
		(yyval.zset_stmt_t)->case_idx_ = CASE4;
		(yyval.zset_stmt_t)->zrange_stmt_ = (yyvsp[0].zrange_stmt_t);	    
    }
#line 4194 "bison_parser.cpp"
    break;

  case 96:
#line 939 "bison.y"
                          {
		(yyval.zset_stmt_t) = new ZaddStmt();
		(yyval.zset_stmt_t)->case_idx_ = CASE5;
		(yyval.zset_stmt_t)->zrangebyscore_stmt_ = (yyvsp[0].zrangebyscore_stmt_t);	    
    }
#line 4204 "bison_parser.cpp"
    break;

  case 97:
#line 944 "bison.y"
                   {
		(yyval.zset_stmt_t) = new ZaddStmt();
		(yyval.zset_stmt_t)->case_idx_ = CASE6;
		(yyval.zset_stmt_t)->zrank_stmt_ = (yyvsp[0].zrank_stmt_t);	    
    }
#line 4214 "bison_parser.cpp"
    break;

  case 98:
#line 949 "bison.y"
                  {
		(yyval.zset_stmt_t) = new ZremStmt();
		(yyval.zset_stmt_t)->case_idx_ = CASE7;
		(yyval.zset_stmt_t)->zrem_stmt_ = (yyvsp[0].zrem_stmt_t);	    
    }
#line 4224 "bison_parser.cpp"
    break;

  case 99:
#line 954 "bison.y"
                    {
		(yyval.zset_stmt_t) = new ZaddStmt();
		(yyval.zset_stmt_t)->case_idx_ = CASE8;
		(yyval.zset_stmt_t)->zscore_stmt_ = (yyvsp[0].zscore_stmt_t);	    
    }
#line 4234 "bison_parser.cpp"
    break;

  case 100:
#line 959 "bison.y"
                         {
		(yyval.zset_stmt_t) = new ZaddStmt();
		(yyval.zset_stmt_t)->case_idx_ = CASE9;
		(yyval.zset_stmt_t)->zunionstore_stmt_ = (yyvsp[0].zunionstore_stmt_t);	    
    }
#line 4244 "bison_parser.cpp"
    break;

  case 101:
#line 964 "bison.y"
                         {
		(yyval.zset_stmt_t) = new ZaddStmt();
		(yyval.zset_stmt_t)->case_idx_ = CASE10;
		(yyval.zset_stmt_t)->zinterstore_stmt_ = (yyvsp[0].zinterstore_stmt_t);	    
    }
#line 4254 "bison_parser.cpp"
    break;

  case 102:
#line 974 "bison.y"
                            {
		(yyval.connect_stmt_t) = new ConnectStmt();
		(yyval.connect_stmt_t)->case_idx_ = CASE0;
		(yyval.connect_stmt_t)->select_stmt_ = (yyvsp[0].select_stmt_t);
		
	}
#line 4265 "bison_parser.cpp"
    break;

  case 103:
#line 985 "bison.y"
                     {
		(yyval.del_stmt_t) = new DelStmt();
		(yyval.del_stmt_t)->case_idx_ = CASE0;
		(yyval.del_stmt_t)->key_list_ = (yyvsp[0].key_list_t);
	}
#line 4275 "bison_parser.cpp"
    break;

  case 104:
#line 993 "bison.y"
                     {
		(yyval.dump_stmt_t) = new DumpStmt();
		(yyval.dump_stmt_t)->case_idx_ = CASE0;
		(yyval.dump_stmt_t)->keyname_ = (yyvsp[0].keyname_t);
	}
#line 4285 "bison_parser.cpp"
    break;

  case 105:
#line 1001 "bison.y"
                       {
		(yyval.exists_stmt_t) = new ExistsStmt();
		(yyval.exists_stmt_t)->case_idx_ = CASE0;
		(yyval.exists_stmt_t)->keyname_ = (yyvsp[0].keyname_t);
	}
#line 4295 "bison_parser.cpp"
    break;

  case 106:
#line 1009 "bison.y"
                                  {
		(yyval.expire_stmt_t) = new ExpireStmt;
		(yyval.expire_stmt_t)->case_idx_ = CASE0;
		(yyval.expire_stmt_t)->keyname_ = (yyvsp[-1].keyname_t);
		(yyval.expire_stmt_t)->timesecond_ = (yyvsp[0].timesecond_t);
	}
#line 4306 "bison_parser.cpp"
    break;

  case 107:
#line 1018 "bison.y"
                                  {
		(yyval.expireat_stmt_t) = new ExpireatStmt();
		(yyval.expireat_stmt_t)->case_idx_ = CASE0;
		(yyval.expireat_stmt_t)->keyname_ = (yyvsp[-1].keyname_t);
		(yyval.expireat_stmt_t)->timeunix_ = (yyvsp[0].timeunix_t);
	}
#line 4317 "bison_parser.cpp"
    break;

  case 108:
#line 1027 "bison.y"
                                {
		(yyval.move_stmt_t) = new MoveStmt();
		(yyval.move_stmt_t)->case_idx_ = CASE0;
		(yyval.move_stmt_t)->keyname_ = (yyvsp[-1].keyname_t);
		(yyval.move_stmt_t)->operandnum_ = (yyvsp[0].operandnum_t);
	}
#line 4328 "bison_parser.cpp"
    break;

  case 109:
#line 1036 "bison.y"
                                  {
		(yyval.object_stmt_t) = new ObjectStmt();
		(yyval.object_stmt_t)->case_idx_ = CASE0;
		(yyval.object_stmt_t)->objoption_ = (yyvsp[-1].objoption_t);
		(yyval.object_stmt_t)->keyname_ = (yyvsp[0].keyname_t);
	}
#line 4339 "bison_parser.cpp"
    break;

  case 110:
#line 1045 "bison.y"
                 {
		(yyval.objoption_t) = new Objoption();
		(yyval.objoption_t)->case_idx_ = CASE0;
	}
#line 4348 "bison_parser.cpp"
    break;

  case 111:
#line 1050 "bison.y"
                 {
		(yyval.objoption_t) = new Objoption();
		(yyval.objoption_t)->case_idx_ = CASE1;
	}
#line 4357 "bison_parser.cpp"
    break;

  case 112:
#line 1055 "bison.y"
                 {
		(yyval.objoption_t) = new Objoption();
		(yyval.objoption_t)->case_idx_ = CASE2;
	}
#line 4366 "bison_parser.cpp"
    break;

  case 113:
#line 1063 "bison.y"
                        {
		(yyval.persist_stmt_t) = new PersistStmt();
		(yyval.persist_stmt_t)->case_idx_ = CASE0;
		(yyval.persist_stmt_t)->keyname_ = (yyvsp[0].keyname_t);
	}
#line 4376 "bison_parser.cpp"
    break;

  case 114:
#line 1071 "bison.y"
                                   {
		(yyval.pexpire_stmt_t) = new PexpireStmt();
		(yyval.pexpire_stmt_t)->case_idx_ = CASE0;
		(yyval.pexpire_stmt_t)->keyname_ = (yyvsp[-1].keyname_t);
		(yyval.pexpire_stmt_t)->timesecond_ = (yyvsp[0].timesecond_t);
	}
#line 4387 "bison_parser.cpp"
    break;

  case 115:
#line 1080 "bison.y"
                                     {
		(yyval.pexpireat_stmt_t) = new PexpireatStmt();
		(yyval.pexpireat_stmt_t)->case_idx_ = CASE0;
		(yyval.pexpireat_stmt_t)->keyname_ = (yyvsp[-1].keyname_t);
		(yyval.pexpireat_stmt_t)->timesecond_ = (yyvsp[0].timesecond_t);
	}
#line 4398 "bison_parser.cpp"
    break;

  case 116:
#line 1089 "bison.y"
                     {
		(yyval.pttl_stmt_t) = new PttlStmt();
		(yyval.pttl_stmt_t)->case_idx_ = CASE0;
		(yyval.pttl_stmt_t)->keyname_ = (yyvsp[0].keyname_t);
	}
#line 4408 "bison_parser.cpp"
    break;

  case 117:
#line 1097 "bison.y"
                  {
		(yyval.randomkey_stmt_t) = new PttlStmt();
		(yyval.randomkey_stmt_t)->case_idx_ = CASE0;
	}
#line 4417 "bison_parser.cpp"
    break;

  case 118:
#line 1104 "bison.y"
                                 {
		(yyval.rename_stmt_t) = new RenameStmt();
		(yyval.rename_stmt_t)->case_idx_ = CASE0;
		(yyval.rename_stmt_t)->keyname_ = (yyvsp[-1].keyname_t);
		(yyval.rename_stmt_t)->aliasname_ = (yyvsp[0].aliasname_t);
	}
#line 4428 "bison_parser.cpp"
    break;

  case 119:
#line 1113 "bison.y"
                                   {
		(yyval.renamenx_stmt_t) = new RenamenxStmt();
		(yyval.renamenx_stmt_t)->case_idx_ = CASE0;
		(yyval.renamenx_stmt_t)->keyname_ = (yyvsp[-1].keyname_t);
		(yyval.renamenx_stmt_t)->aliasname_ = (yyvsp[0].aliasname_t);
	}
#line 4439 "bison_parser.cpp"
    break;

  case 120:
#line 1122 "bison.y"
                   {
		(yyval.aliasname_t) = new AliasName();
		(yyval.aliasname_t)->case_idx_ = CASE0;
		(yyval.aliasname_t)->identifier_ = (yyvsp[0].identifier_t);
		if(tmp1){
			auto tmp2 = tmp1->identifier_; 
			if(tmp2){
				tmp2->data_type_ = kDataKeyName; 
				tmp2->scope_ = 2; 
				tmp2->data_flag_ =(DATAFLAG)64; 
			}
		}
	}
#line 4457 "bison_parser.cpp"
    break;

  case 121:
#line 1137 "bison.y"
                                                                                      {
		(yyval.sort_stmt_t) = new SortStmt();
		(yyval.sort_stmt_t)->case_idx_ = CASE0;
		(yyval.sort_stmt_t)->sort_clause_ = (yyvsp[-4].sort_clause_t);
		(yyval.sort_stmt_t)->opt_by_clause_ = (yyvsp[-3].opt_by_clause_t);
		(yyval.sort_stmt_t)->opt_limit_clause_ = (yyvsp[-2].opt_limit_clause_t);
		(yyval.sort_stmt_t)->opt_sort_behavior_ = (yyvsp[-1].opt_sort_behavior_t);
		(yyval.sort_stmt_t)->opt_store_clause_ = (yyvsp[0].opt_store_clause_t);
	}
#line 4471 "bison_parser.cpp"
    break;

  case 122:
#line 1149 "bison.y"
                     {
		(yyval.sort_clause_t) = new SortClause();
		(yyval.sort_clause_t)->case_idx_ = CASE0;
		(yyval.sort_clause_t)->keyname_ = (yyvsp[0].keyname_t);
	}
#line 4481 "bison_parser.cpp"
    break;

  case 123:
#line 1156 "bison.y"
                   {
		(yyval.opt_by_clause_t) = new OptByClause();
		(yyval.opt_by_clause_t)->case_idx_ = CASE0;
		(yyval.opt_by_clause_t)->keyname_ = (yyvsp[0].keyname_t);
	}
#line 4491 "bison_parser.cpp"
    break;

  case 124:
#line 1161 "bison.y"
        {
		(yyval.opt_by_clause_t) = new OptByClause();
		(yyval.opt_by_clause_t)->case_idx_ = CASE1;
   }
#line 4500 "bison_parser.cpp"
    break;

  case 125:
#line 1168 "bison.y"
                                    {
		(yyval.opt_limit_clause_t) = new OptLimitClause();
		(yyval.opt_limit_clause_t)->case_idx_ = CASE0;
		(yyval.opt_limit_clause_t)->operandnum1_ = (yyvsp[-1].operandnum_t);
		(yyval.opt_limit_clause_t)->operandnum2_ = (yyvsp[0].operandnum_t);
	}
#line 4511 "bison_parser.cpp"
    break;

  case 126:
#line 1174 "bison.y"
        {
		(yyval.opt_limit_clause_t) = new OptLimitClause();
		(yyval.opt_limit_clause_t)->case_idx_ = CASE1;
   }
#line 4520 "bison_parser.cpp"
    break;

  case 127:
#line 1181 "bison.y"
                      {
		(yyval.opt_store_clause_t) = new OptStoreClause();
		(yyval.opt_store_clause_t)->case_idx_ = CASE0;
		(yyval.opt_store_clause_t)->keyname_ = (yyvsp[0].keyname_t);
	}
#line 4530 "bison_parser.cpp"
    break;

  case 128:
#line 1186 "bison.y"
        {
		(yyval.opt_store_clause_t) = new OptStoreClause();
		(yyval.opt_store_clause_t)->case_idx_ = CASE1;
   }
#line 4539 "bison_parser.cpp"
    break;

  case 129:
#line 1193 "bison.y"
            {
		(yyval.opt_sort_behavior_t) = new OptSortBehavior();
		(yyval.opt_sort_behavior_t)->case_idx_ = CASE0;
	}
#line 4548 "bison_parser.cpp"
    break;

  case 130:
#line 1197 "bison.y"
             {
	   (yyval.opt_sort_behavior_t) = new OptSortBehavior();
	   (yyval.opt_sort_behavior_t)->case_idx_ = CASE1;
    }
#line 4557 "bison_parser.cpp"
    break;

  case 131:
#line 1201 "bison.y"
              {
	   (yyval.opt_sort_behavior_t) = new OptSortBehavior();
	   (yyval.opt_sort_behavior_t)->case_idx_ = CASE2;
    }
#line 4566 "bison_parser.cpp"
    break;

  case 132:
#line 1205 "bison.y"
        {
	   (yyval.opt_sort_behavior_t) = new OptSortBehavior();
	   (yyval.opt_sort_behavior_t)->case_idx_ = CASE3;
   }
#line 4575 "bison_parser.cpp"
    break;

  case 133:
#line 1213 "bison.y"
                    {
		(yyval.ttl_stmt_t) = new TtlStmt();
		(yyval.ttl_stmt_t)->case_idx_ = CASE0;
		(yyval.ttl_stmt_t)->keyname_ = (yyvsp[0].keyname_t);
	}
#line 4585 "bison_parser.cpp"
    break;

  case 134:
#line 1221 "bison.y"
                     {
		(yyval.type_stmt_t) = new TypeStmt();
		(yyval.type_stmt_t)->case_idx_ = CASE0;
		(yyval.type_stmt_t)->keyname_ = (yyvsp[0].keyname_t);
	}
#line 4595 "bison_parser.cpp"
    break;

  case 135:
#line 1230 "bison.y"
                                    {
		(yyval.append_stmt_t) = new AppendStmt();
		(yyval.append_stmt_t)->case_idx_ = CASE0;
		(yyval.append_stmt_t)->key_string_name_ = (yyvsp[-1].key_string_name_t);
		(yyval.append_stmt_t)->value_ = (yyvsp[0].value_t);
	}
#line 4606 "bison_parser.cpp"
    break;

  case 136:
#line 1240 "bison.y"
                                 {
		(yyval.bicount_stmt_t) = new BicountStmt();
		(yyval.bicount_stmt_t)->case_idx_ = CASE0;
		(yyval.bicount_stmt_t)->key_string_name_ = (yyvsp[0].key_string_name_t);
	}
#line 4616 "bison_parser.cpp"
    break;

  case 137:
#line 1248 "bison.y"
                                               {
		(yyval.setbit_stmt_t) = new SetbitStmt();
		(yyval.setbit_stmt_t)->case_idx_ = CASE0;
		(yyval.setbit_stmt_t)->key_string_name_ = (yyvsp[-2].key_string_name_t);
		(yyval.setbit_stmt_t)->operandnum_ = (yyvsp[-1].operandnum_t);
		(yyval.setbit_stmt_t)->value_ = (yyvsp[0].value_t);
	}
#line 4628 "bison_parser.cpp"
    break;

  case 138:
#line 1258 "bison.y"
                                       {
		(yyval.bitop_stmt_t) = new BitopStmt();
		(yyval.bitop_stmt_t)->case_idx_ = CASE0;
		(yyval.bitop_stmt_t)->operation_ = (yyvsp[-1].operation_t);
		(yyval.bitop_stmt_t)->key_string_list_ = (yyvsp[0].key_string_list_t);
	}
#line 4639 "bison_parser.cpp"
    break;

  case 139:
#line 1267 "bison.y"
            {
		(yyval.operation_t) = new Operation();
		(yyval.operation_t)->case_idx_ = CASE0;
	}
#line 4648 "bison_parser.cpp"
    break;

  case 140:
#line 1271 "bison.y"
           {
		(yyval.operation_t) = new Operation();
		(yyval.operation_t)->case_idx_ = CASE1;
	}
#line 4657 "bison_parser.cpp"
    break;

  case 141:
#line 1275 "bison.y"
            {
		(yyval.operation_t) = new Operation();
		(yyval.operation_t)->case_idx_ = CASE2;
	}
#line 4666 "bison_parser.cpp"
    break;

  case 142:
#line 1279 "bison.y"
            {
		(yyval.operation_t) = new Operation();
		(yyval.operation_t)->case_idx_ = CASE3;
	}
#line 4675 "bison_parser.cpp"
    break;

  case 143:
#line 1286 "bison.y"
                             {
		(yyval.decr_stmt_t) = new DecrStmt();
		(yyval.decr_stmt_t)->case_idx_ = CASE0;
		(yyval.decr_stmt_t)->key_string_name_ = (yyvsp[0].key_string_name_t);
	}
#line 4685 "bison_parser.cpp"
    break;

  case 144:
#line 1294 "bison.y"
                                           {
		(yyval.decrby_stmt_t) = new DecrbyStmt();
		(yyval.decrby_stmt_t)->case_idx_ = CASE0;
		(yyval.decrby_stmt_t)->key_string_name_ = (yyvsp[-1].key_string_name_t);
		(yyval.decrby_stmt_t)->num_literal_ = (yyvsp[0].num_literal_t);
	}
#line 4696 "bison_parser.cpp"
    break;

  case 145:
#line 1303 "bison.y"
                            {
		(yyval.get_stmt_t) = new GetStmt();
		(yyval.get_stmt_t)->case_idx_ = CASE0;
		(yyval.get_stmt_t)->key_string_name_ = (yyvsp[0].key_string_name_t);
	}
#line 4706 "bison_parser.cpp"
    break;

  case 146:
#line 1311 "bison.y"
                                         {
		(yyval.getbit_stmt_t) = new GetbitStmt();
		(yyval.getbit_stmt_t)->case_idx_ = CASE0;
		(yyval.getbit_stmt_t)->key_string_name_ = (yyvsp[-1].key_string_name_t);
		(yyval.getbit_stmt_t)->operandnum_ = (yyvsp[0].operandnum_t);
	}
#line 4717 "bison_parser.cpp"
    break;

  case 147:
#line 1320 "bison.y"
                                                       {
		(yyval.getrange_stmt_t) = new TypeStmt();
		(yyval.getrange_stmt_t)->case_idx_ = CASE0;
		(yyval.getrange_stmt_t)->key_string_name_ = (yyvsp[-2].key_string_name_t);
		(yyval.getrange_stmt_t)->operandnum1_ = (yyvsp[-1].operandnum_t);
		(yyval.getrange_stmt_t)->operandnum2_ = (yyvsp[0].operandnum_t);
	}
#line 4729 "bison_parser.cpp"
    break;

  case 148:
#line 1330 "bison.y"
                                    {
		(yyval.getset_stmt_t) = new GetStmt();
		(yyval.getset_stmt_t)->case_idx_ = CASE0;
		(yyval.getset_stmt_t)->key_string_name_ = (yyvsp[-1].key_string_name_t);
		(yyval.getset_stmt_t)->value_ = (yyvsp[0].value_t);
	}
#line 4740 "bison_parser.cpp"
    break;

  case 149:
#line 1339 "bison.y"
                             {
		(yyval.incr_stmt_t) = new IncrStmt();
		(yyval.incr_stmt_t)->case_idx_ = CASE0;
		(yyval.incr_stmt_t)->key_string_name_ = (yyvsp[0].key_string_name_t);
	}
#line 4750 "bison_parser.cpp"
    break;

  case 150:
#line 1347 "bison.y"
                                           {
		(yyval.incrby_stmt_t) = new IncrbyStmt();
		(yyval.incrby_stmt_t)->case_idx_ = CASE0;
		(yyval.incrby_stmt_t)->key_string_name_ = (yyvsp[-1].key_string_name_t);
		(yyval.incrby_stmt_t)->num_literal_ = (yyvsp[0].num_literal_t);
	}
#line 4761 "bison_parser.cpp"
    break;

  case 151:
#line 1356 "bison.y"
                                                  {
		(yyval.incrbyfloat_stmt_t) = new TypeStmt();
		(yyval.incrbyfloat_stmt_t)->case_idx_ = CASE0;
		(yyval.incrbyfloat_stmt_t)->key_string_name_ = (yyvsp[-1].key_string_name_t);
		(yyval.incrbyfloat_stmt_t)->float_literal_ = (yyvsp[0].float_literal_t);
	}
#line 4772 "bison_parser.cpp"
    break;

  case 152:
#line 1365 "bison.y"
                             {
		(yyval.mget_stmt_t) = new MgetStmt();
		(yyval.mget_stmt_t)->case_idx_ = CASE0;
		(yyval.mget_stmt_t)->key_string_list_ = (yyvsp[0].key_string_list_t);
	}
#line 4782 "bison_parser.cpp"
    break;

  case 153:
#line 1374 "bison.y"
                                   {
		(yyval.mset_stmt_t) = new MsetStmt();
		(yyval.mset_stmt_t)->case_idx_ = CASE0;
		(yyval.mset_stmt_t)->key_string_value_list_ = (yyvsp[0].key_string_value_list_t);
	}
#line 4792 "bison_parser.cpp"
    break;

  case 154:
#line 1384 "bison.y"
                                                {
		(yyval.psetex_stmt_t) = new TypeStmt();
		(yyval.psetex_stmt_t)->case_idx_ = CASE0;
		(yyval.psetex_stmt_t)->key_string_name_ = (yyvsp[-2].key_string_name_t);
		(yyval.psetex_stmt_t)->timesecond_ = (yyvsp[-1].timesecond_t);
		(yyval.psetex_stmt_t)->value_ = (yyvsp[0].value_t);
	}
#line 4804 "bison_parser.cpp"
    break;

  case 155:
#line 1394 "bison.y"
                                                                    {
		(yyval.setkey_stmt_t) = new SetkeyStmt();
		(yyval.setkey_stmt_t)->case_idx_ = CASE0;
		(yyval.setkey_stmt_t)->setkey_clause_ = (yyvsp[-2].setkey_clause_t);
		(yyval.setkey_stmt_t)->opt_expiretime_clause_ = (yyvsp[-1].opt_expiretime_clause_t);
		(yyval.setkey_stmt_t)->opt_setkey_behavior_ = (yyvsp[0].opt_setkey_behavior_t);
	}
#line 4816 "bison_parser.cpp"
    break;

  case 156:
#line 1404 "bison.y"
                              {
		(yyval.setkey_clause_t) = new SetkeyClause;
		(yyval.setkey_clause_t)->case_idx_ = CASE0;
		(yyval.setkey_clause_t)->key_string_name_ = (yyvsp[-1].key_string_name_t);
		(yyval.setkey_clause_t)->value_ = (yyvsp[0].value_t);
		if((yyval.setkey_clause_t)){
			auto tmp1 = (yyval.setkey_clause_t)->key_string_name_;
			if(tmp1){
				tmp1->data_type_ = kDataStringName; 
				tmp1->scope_ = 1; 
				tmp1->data_flag_ =(DATAFLAG)1; 
			}
		}
	}
#line 4835 "bison_parser.cpp"
    break;

  case 157:
#line 1421 "bison.y"
                      {
		(yyval.opt_expiretime_clause_t) = new OptExpireTimeClause();
		(yyval.opt_expiretime_clause_t)->case_idx_ = CASE0;
		(yyval.opt_expiretime_clause_t)->timesecond_ = (yyvsp[0].timesecond_t);
	}
#line 4845 "bison_parser.cpp"
    break;

  case 158:
#line 1426 "bison.y"
                      {
	    (yyval.opt_expiretime_clause_t) = new OptExpireTimeClause();
		(yyval.opt_expiretime_clause_t)->case_idx_ = CASE1;
		(yyval.opt_expiretime_clause_t)->timesecond_ = (yyvsp[0].timesecond_t);
    }
#line 4855 "bison_parser.cpp"
    break;

  case 159:
#line 1431 "bison.y"
        {
	    (yyval.opt_expiretime_clause_t) = new OptExpireTimeClause();
		(yyval.opt_expiretime_clause_t)->case_idx_ = CASE2;
   }
#line 4864 "bison_parser.cpp"
    break;

  case 160:
#line 1438 "bison.y"
           {
		(yyval.opt_setkey_behavior_t) = OptSetkeyBehavior();
		(yyval.opt_setkey_behavior_t)->case_idx_ = CASE0;
	}
#line 4873 "bison_parser.cpp"
    break;

  case 161:
#line 1442 "bison.y"
           {
	    (yyval.opt_setkey_behavior_t) = OptSetkeyBehavior();
		(yyval.opt_setkey_behavior_t)->case_idx_ = CASE1;
    }
#line 4882 "bison_parser.cpp"
    break;

  case 162:
#line 1446 "bison.y"
        {
	    (yyval.opt_setkey_behavior_t) = OptSetkeyBehavior();
		(yyval.opt_setkey_behavior_t)->case_idx_ = CASE2;
   }
#line 4891 "bison_parser.cpp"
    break;

  case 163:
#line 1455 "bison.y"
                                               {
		(yyval.setex_stmt_t) = new TypeStmt();
		(yyval.setex_stmt_t)->case_idx_ = CASE0;
		(yyval.setex_stmt_t)->key_string_name_ = (yyvsp[-2].key_string_name_t);
		(yyval.setex_stmt_t)->timesecond_ = (yyvsp[-1].timesecond_t);
		(yyval.setex_stmt_t)->value_ = (yyvsp[0].value_t);
		if((yyval.setex_stmt_t)){
			auto tmp1 = (yyval.setex_stmt_t)->key_string_name_;
			if(tmp1){
				tmp1->data_type_ = kDataStringName; 
				tmp1->scope_ = 1; 
				tmp1->data_flag_ =(DATAFLAG)1; 
			}
		}
	}
#line 4911 "bison_parser.cpp"
    break;

  case 164:
#line 1473 "bison.y"
                                   {
		(yyval.setnx_stmt_t) = new SetnxStmt();
		(yyval.setnx_stmt_t)->case_idx_ = CASE0;
		(yyval.setnx_stmt_t)->key_string_name_ = (yyvsp[-1].key_string_name_t);
		(yyval.setnx_stmt_t)->value_ = (yyvsp[0].value_t);
		if((yyval.setnx_stmt_t)){
			auto tmp1 = (yyval.setnx_stmt_t)->key_string_name_;
			if(tmp1){
				tmp1->data_type_ = kDataStringName; 
				tmp1->scope_ = 1; 
				tmp1->data_flag_ =(DATAFLAG)1; 
			}
		}
	}
#line 4930 "bison_parser.cpp"
    break;

  case 165:
#line 1490 "bison.y"
                                                  {
		(yyval.setrange_stmt_t) = new SetrangeStmt();
		(yyval.setrange_stmt_t)->case_idx_ = CASE0;
		(yyval.setrange_stmt_t)->key_string_name_ = (yyvsp[-2].key_string_name_t);
		(yyval.setrange_stmt_t)->operandnum_ = (yyvsp[-1].operandnum_t);
		(yyval.setrange_stmt_t)->value_ = (yyvsp[0].value_t);
	}
#line 4942 "bison_parser.cpp"
    break;

  case 166:
#line 1500 "bison.y"
                               {
		(yyval.strlen_stmt_t) = new StrlenStmt();
		(yyval.strlen_stmt_t)->case_idx_ = CASE0;
		(yyval.strlen_stmt_t)->key_string_name_ = (yyvsp[0].key_string_name_t);
	}
#line 4952 "bison_parser.cpp"
    break;

  case 167:
#line 1510 "bison.y"
                                          {
		(yyval.hdel_stmt_t) = new HdelStmt();
		(yyval.hdel_stmt_t)->case_idx_ = CASE0;
		(yyval.hdel_stmt_t)->key_hash_name_ = (yyvsp[-1].key_hash_name_t);
		(yyval.hdel_stmt_t)->del_field_list_ = (yyvsp[0].del_field_list_t);
		if((yyval.hdel_stmt_t)){
			auto tmp1 = (yyval.hdel_stmt_t)->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataHashName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
	}
#line 4971 "bison_parser.cpp"
    break;

  case 168:
#line 1528 "bison.y"
                                         {
		(yyval.hexists_stmt_t) = new HexistsStmt();
		(yyval.hexists_stmt_t)->case_idx_ = CASE0;
		(yyval.hexists_stmt_t)->key_hash_name_ = (yyvsp[-1].key_hash_name_t);
		(yyval.hexists_stmt_t)->field_name_ = (yyvsp[0].field_name_t);
	}
#line 4982 "bison_parser.cpp"
    break;

  case 169:
#line 1537 "bison.y"
                                      {
		(yyval.hget_stmt_t) = new HgetStmt();
		(yyval.hget_stmt_t)->case_idx_ = CASE0;
		(yyval.hget_stmt_t)->key_hash_name_ = (yyvsp[-1].key_hash_name_t);
		(yyval.hget_stmt_t)->field_name_ = (yyvsp[0].field_name_t);
	}
#line 4993 "bison_parser.cpp"
    break;

  case 170:
#line 1547 "bison.y"
                              {
		(yyval.hgetall_stmt_t) = new HgetallStmt();
		(yyval.hgetall_stmt_t)->case_idx_ = CASE0;
		(yyval.hgetall_stmt_t)->key_hash_name_ = (yyvsp[0].key_hash_name_t);
	}
#line 5003 "bison_parser.cpp"
    break;

  case 171:
#line 1555 "bison.y"
                                                    {
		(yyval.hincrby_stmt_t) = new HincrbyStmt();
		(yyval.hincrby_stmt_t)->case_idx_ = CASE0;
		(yyval.hincrby_stmt_t)->key_hash_name_ = (yyvsp[-2].key_hash_name_t);
		(yyval.hincrby_stmt_t)->field_name_ = (yyvsp[-1].field_name_t);
		(yyval.hincrby_stmt_t)->num_literal_ = (yyvsp[0].num_literal_t);
	}
#line 5015 "bison_parser.cpp"
    break;

  case 172:
#line 1565 "bison.y"
                                                            {
		(yyval.hincrbyfloat_stmt_t) = new HincrbyfloatStmt();
		(yyval.hincrbyfloat_stmt_t)->case_idx_ = CASE0;
		(yyval.hincrbyfloat_stmt_t)->key_hash_name_ = (yyvsp[-2].key_hash_name_t);
		(yyval.hincrbyfloat_stmt_t)->field_name_ = (yyvsp[-1].field_name_t);
		(yyval.hincrbyfloat_stmt_t)->float_literal_ = (yyvsp[0].float_literal_t);
	}
#line 5027 "bison_parser.cpp"
    break;

  case 173:
#line 1575 "bison.y"
                            {
		(yyval.hkeys_stmt_t) = new HkeysStmt();
		(yyval.hkeys_stmt_t)->case_idx_ = CASE0;
		(yyval.hkeys_stmt_t)->key_hash_name_ = (yyvsp[0].key_hash_name_t);
	}
#line 5037 "bison_parser.cpp"
    break;

  case 174:
#line 1583 "bison.y"
                           {
		(yyval.hlen_stmt_t) = new HlenStmt();
		(yyval.hlen_stmt_t)->case_idx_ = CASE0;
		(yyval.hlen_stmt_t)->key_hash_name_ = (yyvsp[0].key_hash_name_t);
	}
#line 5047 "bison_parser.cpp"
    break;

  case 175:
#line 1591 "bison.y"
                                       {
		(yyval.hmget_stmt_t) = new TypeStmt();
		(yyval.hmget_stmt_t)->case_idx_ = CASE0;
		(yyval.hmget_stmt_t)->key_hash_name_ = (yyvsp[-1].key_hash_name_t);
		(yyval.hmget_stmt_t)->field_list_ = (yyvsp[0].field_list_t);
	}
#line 5058 "bison_parser.cpp"
    break;

  case 176:
#line 1600 "bison.y"
                                             {
		(yyval.hmset_stmt_t) = new HmsetStmt();
		(yyval.hmset_stmt_t)->case_idx_ = CASE0;
		(yyval.hmset_stmt_t)->key_hash_name_ = (yyvsp[-1].key_hash_name_t);
		(yyval.hmset_stmt_t)->field_value_list_ = (yyvsp[0].field_value_list_t);
		if((yyval.hmset_stmt_t)){
			auto tmp1 = (yyval.hmset_stmt_t)->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataHashName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
	}
#line 5077 "bison_parser.cpp"
    break;

  case 177:
#line 1617 "bison.y"
                                       {
		(yyval.hset_stmt_t) = new HsetStmtt();
		(yyval.hset_stmt_t)->case_idx_ = CASE0;
		(yyval.hset_stmt_t)->key_hash_name_ = (yyvsp[-1].key_hash_name_t);
		(yyval.hset_stmt_t)->field_value_ = (yyvsp[0].field_value_t);
		if((yyval.hset_stmt_t)){
			auto tmp1 = (yyval.hset_stmt_t)->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataHashName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
	}
#line 5096 "bison_parser.cpp"
    break;

  case 178:
#line 1634 "bison.y"
                                         {
		(yyval.hsetnx_stmt_t) = new HsetnxStmt();
		(yyval.hsetnx_stmt_t)->case_idx_ = CASE0;
		(yyval.hsetnx_stmt_t)->key_hash_name_ = (yyvsp[-1].key_hash_name_t);
		(yyval.hsetnx_stmt_t)->field_value_ = (yyvsp[0].field_value_t);
		if((yyval.hsetnx_stmt_t)){
			auto tmp1 = (yyval.hsetnx_stmt_t)->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataHashName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
	}
#line 5115 "bison_parser.cpp"
    break;

  case 179:
#line 1651 "bison.y"
                            {
		(yyval.hvals_stmt_t) = new TypeStmt();
		(yyval.hvals_stmt_t)->case_idx_ = CASE0;
		(yyval.hvals_stmt_t)->key_hash_name_ = (yyvsp[0].key_hash_name_t);
	}
#line 5125 "bison_parser.cpp"
    break;

  case 180:
#line 1660 "bison.y"
                                        {
		(yyval.lindex_stmt_t) = new LindexStmt();
		(yyval.lindex_stmt_t)->case_idx_ = CASE0;
		(yyval.lindex_stmt_t)->key_list_name_ = (yyvsp[-1].key_list_name_t);
		(yyval.lindex_stmt_t)->operandnum_ = (yyvsp[0].operandnum_t);
	}
#line 5136 "bison_parser.cpp"
    break;

  case 181:
#line 1669 "bison.y"
                                                               {
		(yyval.linsert_stmt_t) = new TypeStmt();
		(yyval.linsert_stmt_t)->case_idx_ = CASE0;
		(yyval.linsert_stmt_t)->key_list_name_ = (yyvsp[-3].key_list_name_t);
		(yyval.linsert_stmt_t)->opt_linsert_behavior_ = (yyvsp[-2].opt_linsert_behavior_t);
		(yyval.linsert_stmt_t)->value1_ = (yyvsp[-1].value_t);
		(yyval.linsert_stmt_t)->value2_ = (yyvsp[0].value_t);
		if((yyval.linsert_stmt_t)){
			auto tmp1 = (yyval.linsert_stmt_t)->key_list_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_; 
				if(tmp2){
					tmp2->data_type_ = kDataListName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}
			}
		}
	}
#line 5160 "bison_parser.cpp"
    break;

  case 182:
#line 1691 "bison.y"
               {
		(yyval.opt_linsert_behavior_t) = new OptLinsertBehavior();
		(yyval.opt_linsert_behavior_t)->case_idx_ = CASE0;
	}
#line 5169 "bison_parser.cpp"
    break;

  case 183:
#line 1695 "bison.y"
              {
	    (yyval.opt_linsert_behavior_t) = new OptLinsertBehavior();
		(yyval.opt_linsert_behavior_t)->case_idx_ = CASE1;
    }
#line 5178 "bison_parser.cpp"
    break;

  case 184:
#line 1702 "bison.y"
                           {
		(yyval.llen_stmt_t) = new LlenStmt();
		(yyval.llen_stmt_t)->case_idx_ = CASE0;
		(yyval.llen_stmt_t)->key_list_name_ = (yyvsp[0].key_list_name_t);
	}
#line 5188 "bison_parser.cpp"
    break;

  case 185:
#line 1710 "bison.y"
                           {
		(yyval.lpop_stmt_t) = new LpopStmt();
		(yyval.lpop_stmt_t)->case_idx_ = CASE0;
		(yyval.lpop_stmt_t)->key_list_name_ = (yyvsp[0].key_list_name_t);
	}
#line 5198 "bison_parser.cpp"
    break;

  case 186:
#line 1718 "bison.y"
                                       {
		(yyval.lpush_stmt_t) = new TypeStmt();
		(yyval.lpush_stmt_t)->case_idx_ = CASE0;
		(yyval.lpush_stmt_t)->key_list_name_ = (yyvsp[-1].key_list_name_t);
		(yyval.lpush_stmt_t)->value_list_ = (yyvsp[0].value_list_t);
		if((yyval.lpush_stmt_t)){
			auto tmp1 = (yyval.lpush_stmt_t)->key_list_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_; 
				if(tmp2){
					tmp2->data_type_ = kDataListName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}
			}
		}
	}
#line 5220 "bison_parser.cpp"
    break;

  case 187:
#line 1738 "bison.y"
                                  {
		(yyval.lpushx_stmt_t) = new LpushxStmt();
		(yyval.lpushx_stmt_t)->case_idx_ = CASE0;
		(yyval.lpushx_stmt_t)->key_list_name_ = (yyvsp[-1].key_list_name_t);
		(yyval.lpushx_stmt_t)->value_ = (yyvsp[0].value_t);
		if((yyval.lpushx_stmt_t)){
			auto tmp1 = (yyval.lpushx_stmt_t)->key_list_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_; 
				if(tmp2){
					tmp2->data_type_ = kDataListName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}
			}
		}
	}
#line 5242 "bison_parser.cpp"
    break;

  case 188:
#line 1757 "bison.y"
                                                   {
		(yyval.lrange_stmt_t) = new LrangeStmt();
		(yyval.lrange_stmt_t)->case_idx_ = CASE0;
		(yyval.lrange_stmt_t)->key_list_name_ = (yyvsp[-2].key_list_name_t);
		(yyval.lrange_stmt_t)->operandnum1_ = (yyvsp[-1].operandnum_t);
		(yyval.lrange_stmt_t)->operandnum2_ = (yyvsp[0].operandnum_t);
	}
#line 5254 "bison_parser.cpp"
    break;

  case 189:
#line 1768 "bison.y"
                                            {
		(yyval.lrem_stmt_t) = new LremStmt();
		(yyval.lrem_stmt_t)->case_idx_ = CASE0;
		(yyval.lrem_stmt_t)->key_list_name_ = (yyvsp[-2].key_list_name_t);
		(yyval.lrem_stmt_t)->operandnum_ =(yyvsp[-1].operandnum_t);
		(yyval.lrem_stmt_t)->value_ = (yyvsp[0].value_t);
		if((yyval.lrem_stmt_t)){
			auto tmp1 = (yyval.lrem_stmt_t)->key_list_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_; 
				if(tmp2){
					tmp2->data_type_ = kDataListName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)2; 
				}
			}
		}
	}
#line 5277 "bison_parser.cpp"
    break;

  case 190:
#line 1789 "bison.y"
                                            {
		(yyval.lset_stmt_t) = new LsetStmt();
		(yyval.lset_stmt_t)->case_idx_ = CASE0;
		(yyval.lset_stmt_t)->key_list_name_ = (yyvsp[-2].key_list_name_t);
		(yyval.lset_stmt_t)->operandnum_ = (yyvsp[-1].operandnum_t);
		(yyval.lset_stmt_t)->value_ = (yyvsp[0].value_t);
		if((yyval.lset_stmt_t)){
			auto tmp1 = (yyval.lset_stmt_t)->key_list_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_; 
				if(tmp2){
					tmp2->data_type_ = kDataListName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}
			}
		}
	}
#line 5300 "bison_parser.cpp"
    break;

  case 191:
#line 1810 "bison.y"
                                                  {
		(yyval.ltrim_stmt_t) = new LtrimStmt();
		(yyval.ltrim_stmt_t)->case_idx_ = CASE0;
		(yyval.ltrim_stmt_t)->key_list_name_ = (yyvsp[-2].key_list_name_t);
		(yyval.ltrim_stmt_t)->operandnum1_ = (yyvsp[-1].operandnum_t);
		(yyval.ltrim_stmt_t)->operandnum2_ = (yyvsp[0].operandnum_t);
	}
#line 5312 "bison_parser.cpp"
    break;

  case 192:
#line 1820 "bison.y"
                           {
		(yyval.rpop_stmt_t) = new RpopStmt();
		(yyval.rpop_stmt_t)->case_idx_ = CASE0;
		(yyval.rpop_stmt_t)->key_list_name_ = (yyvsp[0].key_list_name_t);
	}
#line 5322 "bison_parser.cpp"
    break;

  case 193:
#line 1828 "bison.y"
                                              {
		(yyval.rpoplpush_stmt_t) = new TypeStmt();
		(yyval.rpoplpush_stmt_t)->case_idx_ = CASE0;
		(yyval.rpoplpush_stmt_t)->key_list_name1_ = (yyvsp[-1].key_list_name_t);
		(yyval.rpoplpush_stmt_t)->key_list_name2_ = (yyvsp[0].key_list_name_t);
	}
#line 5333 "bison_parser.cpp"
    break;

  case 194:
#line 1837 "bison.y"
                                       {
		(yyval.rpush_stmt_t) = new RpushStmt();
		(yyval.rpush_stmt_t)->case_idx_ = CASE0;
		(yyval.rpush_stmt_t)->key_list_name_ = (yyvsp[-1].key_list_name_t);
		(yyval.rpush_stmt_t)->value_list_ = (yyvsp[0].value_list_t);
		if((yyval.rpush_stmt_t)){
			auto tmp1 = (yyval.rpush_stmt_t)->key_list_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_; 
				if(tmp2){
					tmp2->data_type_ = kDataListName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}
			}
		}
	}
#line 5355 "bison_parser.cpp"
    break;

  case 195:
#line 1857 "bison.y"
                                   {
		(yyval.rpushx_stmt_t) = new RpushxStmt();
		(yyval.rpushx_stmt_t)->case_idx_ = CASE0;
		(yyval.rpushx_stmt_t)->key_list_name_ = (yyvsp[-1].key_list_name_t);
		(yyval.rpushx_stmt_t)->value_ = (yyvsp[0].value_t);
		if((yyval.rpushx_stmt_t)){
			auto tmp1 = (yyval.rpushx_stmt_t)->key_list_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_; 
				if(tmp2){
					tmp2->data_type_ = kDataListName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}
			}
		}
	}
#line 5377 "bison_parser.cpp"
    break;

  case 196:
#line 1878 "bison.y"
                                            {
		 (yyval.sadd_stmt_t) = new SaddStmt();
		 (yyval.sadd_stmt_t)->case_idx_ = CASE0;
		 (yyval.sadd_stmt_t)->key_set_name_ = (yyvsp[-1].key_set_name_t);
		 (yyval.sadd_stmt_t)->smember_name_list_ = (yyvsp[0].smember_name_list_t);
		if((yyval.sadd_stmt_t)){
			auto tmp1 = (yyval.sadd_stmt_t)->key_set_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataSetName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}	
			}
		}
	}
#line 5399 "bison_parser.cpp"
    break;

  case 197:
#line 1898 "bison.y"
                           {
		(yyval.scard_stmt_t) = new ScardStmt();
		(yyval.scard_stmt_t)->case_idx_ = CASE0;
		(yyval.scard_stmt_t)->key_set_name_ = (yyvsp[0].key_set_name_t);
	}
#line 5409 "bison_parser.cpp"
    break;

  case 198:
#line 1906 "bison.y"
                           {
		(yyval.sdiff_stmt_t) = new SdiffStmt();
		(yyval.sdiff_stmt_t)->case_idx_ = CASE0;
		(yyval.sdiff_stmt_t)->key_set_list_ = (yyvsp[0].key_set_list_t);
	}
#line 5419 "bison_parser.cpp"
    break;

  case 199:
#line 1914 "bison.y"
                                {
		(yyval.sdiffstore_stmt_t) = new SdiffStmt();
		(yyval.sdiffstore_stmt_t)->case_idx_ = CASE0;
		(yyval.sdiffstore_stmt_t)->key_set_list_ = (yyvsp[0].key_set_list_t);
	}
#line 5429 "bison_parser.cpp"
    break;

  case 200:
#line 1922 "bison.y"
                            {
		(yyval.sinter_stmt_t) = new SinterStmt();
		(yyval.sinter_stmt_t)->case_idx_ = CASE0;
		(yyval.sinter_stmt_t)->key_set_list_ = (yyvsp[0].key_set_list_t);
	}
#line 5439 "bison_parser.cpp"
    break;

  case 201:
#line 1930 "bison.y"
                                 {
		(yyval.sinterstore_stmt_t) = new SinterstoreStmt();
		(yyval.sinterstore_stmt_t)->case_idx_ = CASE0;
		(yyval.sinterstore_stmt_t)->key_set_list_ = (yyvsp[0].key_set_list_t);
	}
#line 5449 "bison_parser.cpp"
    break;

  case 202:
#line 1938 "bison.y"
                                            {
		(yyval.sismember_stmt_t) = new SismemberStmt();
		(yyval.sismember_stmt_t)->case_idx_ = CASE0;
		(yyval.sismember_stmt_t)->key_set_name_ = (yyvsp[-1].key_set_name_t);
		(yyval.sismember_stmt_t)->smember_name_ = (yyvsp[0].smember_name_t);
	}
#line 5460 "bison_parser.cpp"
    break;

  case 203:
#line 1947 "bison.y"
                              {
		(yyval.smember_stmt_t) = new SmemberStmt();
		(yyval.smember_stmt_t)->case_idx_ = CASE0;
		(yyval.smember_stmt_t)->key_set_name_ = (yyvsp[0].key_set_name_t);
	}
#line 5470 "bison_parser.cpp"
    break;

  case 204:
#line 1955 "bison.y"
                                                     {
		(yyval.smove_stmt_t) = new SmoveStmt();
		(yyval.smove_stmt_t)->case_idx_ = CASE0;
		(yyval.smove_stmt_t)->key_set_name1_ = (yyvsp[-2].key_set_name_t);
		(yyval.smove_stmt_t)->key_set_name2_ = (yyvsp[-1].key_set_name_t);
		(yyval.smove_stmt_t)->smember_name_ = (yyvsp[0].smember_name_t);
	}
#line 5482 "bison_parser.cpp"
    break;

  case 205:
#line 1965 "bison.y"
                          {
		(yyval.spop_stmt_t) = new SpopStmt();
		(yyval.spop_stmt_t)->case_idx_ = CASE0;
		(yyval.spop_stmt_t)->key_set_name_ = (yyvsp[0].key_set_name_t);
		if((yyval.spop_stmt_t)){
			auto tmp1 = (yyval.spop_stmt_t)->key_set_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataSetName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)2; 
				}	
			}
		}
	}
#line 5503 "bison_parser.cpp"
    break;

  case 206:
#line 1984 "bison.y"
                                            {
		(yyval.srandmember_stmt_t) = new SrandmemberStmt();
		(yyval.srandmember_stmt_t)->case_idx_ = CASE0;
		(yyval.srandmember_stmt_t)->key_set_name_ = (yyvsp[-1].key_set_name_t);
		(yyval.srandmember_stmt_t)->operandnum_ = (yyvsp[0].operandnum_t); 
	}
#line 5514 "bison_parser.cpp"
    break;

  case 207:
#line 1993 "bison.y"
                                           {
		(yyval.srem_stmt_t) = new SrandmemberStmt();
		(yyval.srem_stmt_t)->case_idx_ = CASE0;
		(yyval.srem_stmt_t)->key_set_name_ = (yyvsp[-1].key_set_name_t);
		(yyval.srem_stmt_t)->del_key_set_list_ = (yyvsp[0].del_key_set_list_t);
	}
#line 5525 "bison_parser.cpp"
    break;

  case 208:
#line 2002 "bison.y"
                            {
		(yyval.sunion_stmt_t) = new SunionStmt();
		(yyval.sunion_stmt_t)->case_idx_ = CASE0;
		(yyval.sunion_stmt_t)->key_set_list_ = (yyvsp[0].key_set_list_t);
	}
#line 5535 "bison_parser.cpp"
    break;

  case 209:
#line 2010 "bison.y"
                                 {
		(yyval.sunionstore_stmt_t) = new SunionstoreStmt();
		(yyval.sunionstore_stmt_t)->case_idx_ = CASE0;
		(yyval.sunionstore_stmt_t)->key_set_list_ = (yyvsp[0].key_set_list_t);
	}
#line 5545 "bison_parser.cpp"
    break;

  case 210:
#line 2020 "bison.y"
                                              {
		(yyval.zadd_stmt_t) = new ZaddStmt();
		(yyval.zadd_stmt_t)->case_idx_ = CASE0;
		(yyval.zadd_stmt_t)->key_zset_name_ = (yyvsp[-1].key_zset_name_t);
		(yyval.zadd_stmt_t)->zmember_value_list_ = (yyvsp[0].zmember_value_list_t);
		if((yyval.zadd_stmt_t)){
			auto tmp1 = (yyval.zadd_stmt_t)->key_zset_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataZsetName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}	
			}
		}
	}
#line 5567 "bison_parser.cpp"
    break;

  case 211:
#line 2040 "bison.y"
                            {
		(yyval.zcard_stmt_t) = new ZcardStmt();
		(yyval.zcard_stmt_t)->case_idx_ = CASE0;
		(yyval.zcard_stmt_t)->key_zset_name_ = (yyvsp[0].key_zset_name_t);
	}
#line 5577 "bison_parser.cpp"
    break;

  case 212:
#line 2048 "bison.y"
                                                   {
		(yyval.zcount_stmt_t) = new RpopStmt();
		(yyval.zcount_stmt_t)->case_idx_ = CASE0;
		(yyval.zcount_stmt_t)->key_zset_name_ = (yyvsp[-2].key_zset_name_t);
		(yyval.zcount_stmt_t)->operandnum1_ = (yyvsp[-1].operandnum_t);
		(yyval.zcount_stmt_t)->operandnum2_ = (yyvsp[0].operandnum_t);
	}
#line 5589 "bison_parser.cpp"
    break;

  case 213:
#line 2058 "bison.y"
                                                      {
		(yyval.zincrby_stmt_t) = new ZincrbyStmt();
		(yyval.zincrby_stmt_t)->case_idx_ = CASE0;
		(yyval.zincrby_stmt_t)->key_zset_name_ = (yyvsp[-2].key_zset_name_t);
		(yyval.zincrby_stmt_t)->operandnum_ = (yyvsp[-1].operandnum_t);
		(yyval.zincrby_stmt_t)->zmember_name_ = (yyvsp[0].zmember_name_t);
	}
#line 5601 "bison_parser.cpp"
    break;

  case 214:
#line 2068 "bison.y"
                                                                              {
		(yyval.zrange_stmt_t) = new ZrangeStmt();
		(yyval.zrange_stmt_t)->case_idx_ = CASE1;
		(yyval.zrange_stmt_t)->key_zset_name_ = (yyvsp[-3].key_zset_name_t);
		(yyval.zrange_stmt_t)->operandnum1_ = (yyvsp[-2].operandnum_t);
		(yyval.zrange_stmt_t)->operandnum2_ = (yyvsp[-1].operandnum_t);
		(yyval.zrange_stmt_t)->opt_zrange_behavior_ = (yyvsp[0].opt_zrange_behavior_t);	   	
   }
#line 5614 "bison_parser.cpp"
    break;

  case 215:
#line 2079 "bison.y"
                  {
		(yyval.opt_zrange_behavior_t) = new OptZrangeBehavior();
		(yyval.opt_zrange_behavior_t)->case_idx_ = CASE0;
	}
#line 5623 "bison_parser.cpp"
    break;

  case 216:
#line 2083 "bison.y"
        {
		(yyval.opt_zrange_behavior_t) = new OptZrangeBehavior();
		(yyval.opt_zrange_behavior_t)->case_idx_ = CASE1;
   }
#line 5632 "bison_parser.cpp"
    break;

  case 217:
#line 2090 "bison.y"
                                              {
		(yyval.zrangebyscore_stmt_t) = new ZrangebyscoreStmt();
		(yyval.zrangebyscore_stmt_t)->case_idx_ = CASE0;
		(yyval.zrangebyscore_stmt_t)->zrange_stmt_ = (yyvsp[-1].zrangebyscore_clause_t);
		(yyval.zrangebyscore_stmt_t)->opt_limit_clause_ = (yyvsp[0].opt_limit_clause_t);
	}
#line 5643 "bison_parser.cpp"
    break;

  case 218:
#line 2098 "bison.y"
                                                          {
		(yyval.zrangebyscore_clause_t) = new ZrangebyscoreClause();
		(yyval.zrangebyscore_clause_t)->case_idx_ = CASE0;
		(yyval.zrangebyscore_clause_t)->key_zset_name_ = (yyvsp[-2].key_zset_name_t);
		(yyval.zrangebyscore_clause_t)->operandnum1_ = (yyvsp[-1].operandnum_t);
		(yyval.zrangebyscore_clause_t)->operandnum2_ = (yyvsp[0].operandnum_t);
	}
#line 5655 "bison_parser.cpp"
    break;

  case 219:
#line 2108 "bison.y"
                                         {
		(yyval.zrank_stmt_t) = new ZrankStmt();
		(yyval.zrank_stmt_t)->case_idx_ = CASE0;
		(yyval.zrank_stmt_t)->key_zset_name_ = (yyvsp[-1].key_zset_name_t);
		(yyval.zrank_stmt_t)->zmember_name_ = (yyvsp[0].zmember_name_t);
	}
#line 5666 "bison_parser.cpp"
    break;

  case 220:
#line 2117 "bison.y"
                                             {
		(yyval.zrem_stmt_t) = new ZremStmt();
		(yyval.zrem_stmt_t)->case_idx_ = CASE0;
		(yyval.zrem_stmt_t)->key_zset_name_ = (yyvsp[-1].key_zset_name_t);
		(yyval.zrem_stmt_t)->zmember_name_list_ = (yyvsp[0].zmember_name_list_t);
	}
#line 5677 "bison_parser.cpp"
    break;

  case 221:
#line 2127 "bison.y"
                                          {
		(yyval.zscore_stmt_t) = new ZscoreStmt();
		(yyval.zscore_stmt_t)->case_idx_ = CASE0;
		(yyval.zscore_stmt_t)->key_zset_name_ = (yyvsp[-1].key_zset_name_t);
		(yyval.zscore_stmt_t)->zmember_name_ = (yyvsp[0].zmember_name_t);
	}
#line 5688 "bison_parser.cpp"
    break;

  case 222:
#line 2136 "bison.y"
                                                                  {
		(yyval.zunionstore_stmt_t) = new ZunionstoreStmt();
		(yyval.zunionstore_stmt_t)->case_idx_ = CASE0;
		(yyval.zunionstore_stmt_t)->zunionstore_clause_ = (yyvsp[-2].zunionstore_clause_t);
		(yyval.zunionstore_stmt_t)->opt_weight_clause_ = (yyvsp[-1].opt_weight_clause_t);
		(yyval.zunionstore_stmt_t)->opt_aggregate_clause_ = (yyvsp[0].opt_aggregate_clause_t);
	}
#line 5700 "bison_parser.cpp"
    break;

  case 223:
#line 2146 "bison.y"
                                                           {
		(yyval.zunionstore_clause_t) = new ZunionstoreClause();
		(yyval.zunionstore_clause_t)->case_idx_ = CASE0;
		(yyval.zunionstore_clause_t)->key_zset_name_ = (yyvsp[-2].key_zset_name_t);
		(yyval.zunionstore_clause_t)->operandnum_ = (yyvsp[-1].operandnum_t);
		(yyval.zunionstore_clause_t)->key_zset_list_ = (yyvsp[0].key_zset_list_t);
	}
#line 5712 "bison_parser.cpp"
    break;

  case 224:
#line 2156 "bison.y"
                                {
		(yyval.opt_weight_clause_t) = new OptWeightClause();
		(yyval.opt_weight_clause_t)->case_idx_ = CASE0;
		(yyval.opt_weight_clause_t)->operandnum_list_ = (yyvsp[0].operandnum_list_t);
	}
#line 5722 "bison_parser.cpp"
    break;

  case 225:
#line 2161 "bison.y"
        {
	    (yyval.opt_weight_clause_t) = new OptWeightClause();
		(yyval.opt_weight_clause_t)->case_idx_ = CASE1;
   }
#line 5731 "bison_parser.cpp"
    break;

  case 226:
#line 2169 "bison.y"
                      {
		(yyval.opt_aggregate_clause_t) = new OptAggregateClause();
		(yyval.opt_aggregate_clause_t)->case_idx_ = CASE0;

	}
#line 5741 "bison_parser.cpp"
    break;

  case 227:
#line 2174 "bison.y"
                      {
	    (yyval.opt_aggregate_clause_t) = new OptAggregateClause();
		(yyval.opt_aggregate_clause_t)->case_idx_ = CASE1;
   }
#line 5750 "bison_parser.cpp"
    break;

  case 228:
#line 2178 "bison.y"
                      {
	    (yyval.opt_aggregate_clause_t) = new OptAggregateClause();
		(yyval.opt_aggregate_clause_t)->case_idx_ = CASE2;
    }
#line 5759 "bison_parser.cpp"
    break;

  case 229:
#line 2182 "bison.y"
        {
	    (yyval.opt_aggregate_clause_t) = new OptAggregateClause();
		(yyval.opt_aggregate_clause_t)->case_idx_ = CASE3;
   }
#line 5768 "bison_parser.cpp"
    break;

  case 230:
#line 2190 "bison.y"
                                                                  {
		(yyval.zinterstore_stmt_t) = new ZinterstoreStmt();
		(yyval.zinterstore_stmt_t)->case_idx_ = CASE0;
		(yyval.zinterstore_stmt_t)->zinterstore_clause_ = (yyvsp[-2].zinterstore_clause_t);
		(yyval.zinterstore_stmt_t)->opt_weight_clause_ = (yyvsp[-1].opt_weight_clause_t);
		(yyval.zinterstore_stmt_t)->opt_aggregate_clause_ = (yyvsp[0].opt_aggregate_clause_t);
	}
#line 5780 "bison_parser.cpp"
    break;

  case 231:
#line 2200 "bison.y"
                                                           {
		(yyval.zinterstore_clause_t) = new ZinterstoreClause();
		(yyval.zinterstore_clause_t)->case_idx_ = CASE0;
		(yyval.zinterstore_clause_t)->key_zset_name_ = (yyvsp[-2].key_zset_name_t);
		(yyval.zinterstore_clause_t)->operandnum_ = (yyvsp[-1].operandnum_t);
		(yyval.zinterstore_clause_t)->key_zset_list_ = (yyvsp[0].key_zset_list_t);
	}
#line 5792 "bison_parser.cpp"
    break;

  case 232:
#line 2212 "bison.y"
                          {
		(yyval.select_stmt_t) = new SelectStmt();
		(yyval.select_stmt_t)->case_idx_ = CASE0;
		(yyval.select_stmt_t)->operandnum_ = (yyvsp[0].operandnum_t);
	}
#line 5802 "bison_parser.cpp"
    break;

  case 233:
#line 2221 "bison.y"
                {
		(yyval.key_list_t) = new KeyList();
		(yyval.key_list_t)->case_idx_  = CASE0;
		(yyval.key_list_t)->keyname_ = (yyvsp[0].keyname_t);
		if((yyval.key_list_t)){
			auto tmp1 = (yyval.key_list_t)->keyname_;
			if(tmp1){
				tmp1->data_type_=kDataKeyName;
				tmp1->scope_ = 0;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
	}
#line 5820 "bison_parser.cpp"
    break;

  case 234:
#line 2234 "bison.y"
                         {
	    (yyval.key_list_t) = new KeyList();
		(yyval.key_list_t)->case_idx_ = CASE1;
		(yyval.key_list_t)->keyname_ = (yyvsp[-1].keyname_t);
		(yyval.key_list_t)->key_list_ = (yyvsp[0].key_list_t);
		if((yyval.key_list_t)){
			auto tmp1 = (yyval.key_list_t)->keyname_;
			if(tmp1){
				tmp1->data_type_=kDataKeyName;
				tmp1->scope_ = 0;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
   }
#line 5839 "bison_parser.cpp"
    break;

  case 235:
#line 2252 "bison.y"
                    {
		(yyval.keyname_t) = new KeyName();
		(yyval.keyname_t)->case_idx_ = CASE0;
		(yyval.keyname_t)->identifier_ = (yyvsp[0].identifier_t);
		if((yyval.keyname_t)){
			auto tmp1 = (yyval.keyname_t)->identifier_;
			if(tmp1){
				tmp1->data_type_=kDataKeyName;
				tmp1->scope_ = 0;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
#line 5857 "bison_parser.cpp"
    break;

  case 236:
#line 2268 "bison.y"
                {
		(yyval.value_t) = new Value();
		(yyval.value_t)->case_idx_ = CASE0;
		(yyval.value_t)->literal_ = (yyvsp[0].literal_t);
	}
#line 5867 "bison_parser.cpp"
    break;

  case 237:
#line 2276 "bison.y"
              {
		(yyval.value_list_t) = new ValueList();
		(yyval.value_list_t)->case_idx_ = CASE0;
		(yyval.value_list_t)->value_ = (yyvsp[0].value_t);
	}
#line 5877 "bison_parser.cpp"
    break;

  case 238:
#line 2281 "bison.y"
                         {
	    (yyval.value_list_t) = new ValueList();
		(yyval.value_list_t)->case_idx_ = CASE0;
		(yyval.value_list_t)->value_ = (yyvsp[-1].value_t);
		(yyval.value_list_t)->value_list_ = (yyvsp[0].value_list_t);
   }
#line 5888 "bison_parser.cpp"
    break;

  case 239:
#line 2291 "bison.y"
                    {
		(yyval.key_string_name_t) = new KeyStringName();
		(yyval.key_string_name_t)->case_idx_ = CASE0;
		(yyval.key_string_name_t)->identifier_ = (yyvsp[0].identifier_t);
		if((yyval.key_string_name_t)){
			auto tmp1 = (yyval.key_string_name_t)->identifier_;
			if(tmp1){
				tmp1->data_type_=kDataStringName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
#line 5906 "bison_parser.cpp"
    break;

  case 240:
#line 2307 "bison.y"
                        {
		(yyval.key_string_list_t) = new KeyStringList();
		(yyval.key_string_list_t)->case_idx_ = CASE0;
		(yyval.key_string_list_t)->key_string_name_ = (yyvsp[0].key_string_name_t);
	}
#line 5916 "bison_parser.cpp"
    break;

  case 241:
#line 2313 "bison.y"
                                   {
		(yyval.key_string_list_t) = new KeyStringList();
		(yyval.key_string_list_t)->case_idx_ = CASE1;
		(yyval.key_string_list_t)->key_string_name_ = (yyvsp[-1].key_string_name_t);
		(yyval.key_string_list_t)->key_string_list_ = (yyvsp[0].key_string_list_t);
	}
#line 5927 "bison_parser.cpp"
    break;

  case 242:
#line 2323 "bison.y"
                         {
		(yyval.key_string_value_list_t) = new KeyStringValueList();
		(yyval.key_string_value_list_t)->case_idx_ = CASE0;
		(yyval.key_string_value_list_t)->key_string_value_ = (yyvsp[0].key_string_value_t);
	}
#line 5937 "bison_parser.cpp"
    break;

  case 243:
#line 2329 "bison.y"
                                               {
		(yyval.key_string_value_list_t) = new KeyStringValueList();
		(yyval.key_string_value_list_t)->case_idx_ = CASE1;
		(yyval.key_string_value_list_t)->key_string_value_ = (yyvsp[-1].key_string_value_t);
		(yyval.key_string_value_list_t)->key_string_value_list_ = (yyvsp[0].key_string_value_list_t);
	}
#line 5948 "bison_parser.cpp"
    break;

  case 244:
#line 2338 "bison.y"
                              {
		(yyval.key_string_value_t) = new KeyStringValue();
		(yyval.key_string_value_t)->case_idx_ = CASE0;
		(yyval.key_string_value_t)->key_string_name_ = (yyvsp[-1].key_string_name_t);
		(yyval.key_string_value_t)->value_ = (yyvsp[0].value_t);
		if((yyval.key_string_value_t)){
			auto tmp1 = (yyval.key_string_value_t)->key_string_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataStringName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}	
			}
		}
	}
#line 5970 "bison_parser.cpp"
    break;

  case 245:
#line 2358 "bison.y"
                    {
		(yyval.key_hash_name_t) = new KeyHashName();
		(yyval.key_hash_name_t)->case_idx_ = CASE0;
		(yyval.key_hash_name_t)->identifier_ = (yyvsp[0].identifier_t);
		if((yyval.key_hash_name_t)){
			auto tmp1 = (yyval.key_hash_name_t)->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataHashName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
#line 5988 "bison_parser.cpp"
    break;

  case 246:
#line 2376 "bison.y"
                   {
		(yyval.field_name_t) = new FieldName();
		(yyval.field_name_t)->case_idx_ = CASE0;
		(yyval.field_name_t)->identifier_ = (yyvsp[0].identifier_t);
		if((yyval.field_name_t)){
			auto tmp1 = (yyval.field_name_t)->identifier_;
			if(tmp1){
				tmp1->data_type_=kDataFieldName;
				tmp1->scope_ = 2
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
#line 6006 "bison_parser.cpp"
    break;

  case 247:
#line 2392 "bison.y"
                   {
		(yyval.del_field_list_t) = new FieldList();
		(yyval.del_field_list_t)->case_idx_ = CASE0;
		(yyval.del_field_list_t)->field_name_ = (yyvsp[0].field_name_t);
		if((yyval.del_field_list_t)){
			auto tmp1 = (yyval.del_field_list_t)->field_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataFieldName;
					tmp2->scope_ = 2;
					tmp2->data_flag_ = (DATAFLAG)2; 
				}	
			}
		}
	}
#line 6027 "bison_parser.cpp"
    break;

  case 248:
#line 2408 "bison.y"
                              {
	    (yyval.del_field_list_t) = new FieldList();
		(yyval.del_field_list_t)->case_idx_ = CASE1;
		(yyval.del_field_list_t)->field_name_ = (yyvsp[-1].field_name_t);
		(yyval.del_field_list_t)->field_list_ = (yyvsp[0].field_list_t);
		if((yyval.del_field_list_t)){
			auto tmp1 = (yyval.del_field_list_t)->field_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataFieldName;
					tmp2->scope_ = 2;
					tmp2->data_flag_ = (DATAFLAG)2; 
				}	
			}
		}
    }
#line 6049 "bison_parser.cpp"
    break;

  case 249:
#line 2431 "bison.y"
                   {
		(yyval.field_list_t) = new FieldList();
		(yyval.field_list_t)->case_idx_ = CASE0;
		(yyval.field_list_t)->field_name_ = (yyvsp[0].field_name_t);
	}
#line 6059 "bison_parser.cpp"
    break;

  case 250:
#line 2436 "bison.y"
                              {
	    (yyval.field_list_t) = new FieldList();
		(yyval.field_list_t)->case_idx_ = CASE1;
		(yyval.field_list_t)->field_name_ = (yyvsp[-1].field_name_t);
		(yyval.field_list_t)->field_list_ = (yyvsp[0].field_list_t);
    }
#line 6070 "bison_parser.cpp"
    break;

  case 251:
#line 2446 "bison.y"
                         {
		(yyval.field_value_t) = new FieldValue();
		(yyval.field_value_t)->case_idx_ = CASE0;
		(yyval.field_value_t)->field_name_ = (yyvsp[-1].field_name_t);
		(yyval.field_value_t)->value_ = (yyvsp[0].value_t);
		if((yyval.field_value_t)){
			auto tmp1 = (yyval.field_value_t)->field_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataFieldName;
					tmp2->scope_ = 2;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}	
			}
		}
	}
#line 6092 "bison_parser.cpp"
    break;

  case 252:
#line 2468 "bison.y"
                            {
		(yyval.field_value_list_t) = new FieldValueList();
		(yyval.field_value_list_t)->case_idx_ = CASE0;
		(yyval.field_value_list_t)->field_value_ = (yyvsp[0].field_value_t);
	}
#line 6102 "bison_parser.cpp"
    break;

  case 253:
#line 2473 "bison.y"
                                     {
		(yyval.field_value_list_t) = new FieldValueList();
		(yyval.field_value_list_t)->case_idx_ = CASE1;
		(yyval.field_value_list_t)->field_value_ = (yyvsp[-1].field_value_t);
		(yyval.field_value_list_t)->field_value_list_ = (yyvsp[0].field_value_list_t);
	}
#line 6113 "bison_parser.cpp"
    break;

  case 254:
#line 2483 "bison.y"
                    {
		(yyval.key_list_name_t) = new KeyListName();
		(yyval.key_list_name_t)->case_idx_ = CASE0;
		(yyval.key_list_name_t)->identifier_ = (yyvsp[0].identifier_t);
		if((yyval.key_list_name_t)){
			auto tmp1 = (yyval.key_list_name_t)->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataListName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
#line 6131 "bison_parser.cpp"
    break;

  case 255:
#line 2500 "bison.y"
                   {
		(yyval.key_set_name_t) = new KeySetName();
		(yyval.key_set_name_t)->case_idx_ = CASE0;
		(yyval.key_set_name_t)->identifier_ = (yyvsp[0].identifier_t);
		if((yyval.key_set_name_t)){
			auto tmp1 = (yyval.key_set_name_t)->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataSetName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
#line 6149 "bison_parser.cpp"
    break;

  case 256:
#line 2517 "bison.y"
                     {
		(yyval.del_key_set_list_t) = new KeySetList();
		(yyval.del_key_set_list_t)->case_idx_ = CASE0;
		(yyval.del_key_set_list_t)->key_set_name_ = (yyvsp[0].key_set_name_t);
		if((yyval.del_key_set_list_t)){
			auto tmp1 = (yyval.del_key_set_list_t)->key_set_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataSetName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)2; 
				}	
			}
		}
	}
#line 6170 "bison_parser.cpp"
    break;

  case 257:
#line 2534 "bison.y"
                                  {
		(yyval.del_key_set_list_t) = new KeySetList();
		(yyval.del_key_set_list_t)->case_idx_ = CASE1;
		(yyval.del_key_set_list_t)->key_set_name_ = (yyvsp[-1].key_set_name_t);
		(yyval.del_key_set_list_t)->del_key_set_list_ = (yyvsp[0].del_key_set_list_t);
		if((yyval.del_key_set_list_t)){
			auto tmp1 = (yyval.del_key_set_list_t)->key_set_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataSetName;
					tmp2->scope_ = 1;
					tmp2->data_flag_ = (DATAFLAG)2; 
				}	
			}
		}
	}
#line 6192 "bison_parser.cpp"
    break;

  case 258:
#line 2557 "bison.y"
                     {
		(yyval.key_set_list_t) = new KeySetList();
		(yyval.key_set_list_t)->case_idx_ = CASE0;
		(yyval.key_set_list_t)->key_set_name_ = (yyvsp[0].key_set_name_t);
	}
#line 6202 "bison_parser.cpp"
    break;

  case 259:
#line 2563 "bison.y"
                              {
		(yyval.key_set_list_t) = new KeySetList();
		(yyval.key_set_list_t)->case_idx_ = CASE1;
		(yyval.key_set_list_t)->key_set_name_ = (yyvsp[-1].key_set_name_t);
		(yyval.key_set_list_t)->key_set_list_ = (yyvsp[0].key_set_list_t);
	}
#line 6213 "bison_parser.cpp"
    break;

  case 260:
#line 2572 "bison.y"
                   {
		(yyval.smember_name_t) = new SmemberName();
		(yyval.smember_name_t)->case_idx_ = CASE0;
		(yyval.smember_name_t)->identifier_ = (yyvsp[0].identifier_t);
		if((yyval.smember_name_t)){
			auto tmp1 = (yyval.smember_name_t)->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataSmemberName;
				tmp1->scope_ = 2;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
#line 6231 "bison_parser.cpp"
    break;

  case 261:
#line 2589 "bison.y"
                     {
		(yyval.smember_name_list_t) = new KeySetList();
		(yyval.smember_name_list_t)->case_idx_ = CASE0;
		(yyval.smember_name_list_t)->smember_name_ = (yyvsp[0].smember_name_t);
		if((yyval.smember_name_list_t)){
			auto tmp1 = (yyval.smember_name_list_t)->smember_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataSmemberName;
					tmp2->scope_ = 2;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}	
			}
		}
	}
#line 6252 "bison_parser.cpp"
    break;

  case 262:
#line 2606 "bison.y"
                                   {
		(yyval.smember_name_list_t) = new KeySetList();
		(yyval.smember_name_list_t)->case_idx_ = CASE1;
		(yyval.smember_name_list_t)->smember_name_ = (yyvsp[-1].smember_name_t);
		(yyval.smember_name_list_t)->smember_name_list_ = (yyvsp[0].smember_name_list_t);
		if((yyval.smember_name_list_t)){
			auto tmp1 = (yyval.smember_name_list_t)->smember_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataSmemberName;
					tmp2->scope_ = 2;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}	
			}
		}
	}
#line 6274 "bison_parser.cpp"
    break;

  case 263:
#line 2627 "bison.y"
                   {
		(yyval.key_zset_name_t) = new KeyZsetName();
		(yyval.key_zset_name_t)->case_idx_ = CASE0;
		(yyval.key_zset_name_t)->identifier_ = (yyvsp[0].identifier_t);
		if((yyval.key_zset_name_t)){
			auto tmp1 = (yyval.key_zset_name_t)->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataZsetName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
#line 6292 "bison_parser.cpp"
    break;

  case 264:
#line 2643 "bison.y"
                      {
		(yyval.key_zset_list_t) = new KeySetList();
		(yyval.key_zset_list_t)->case_idx_ = CASE0;
		(yyval.key_zset_list_t)->key_zset_name_ = (yyvsp[0].key_zset_name_t);
	}
#line 6302 "bison_parser.cpp"
    break;

  case 265:
#line 2649 "bison.y"
                                {
		(yyval.key_zset_list_t) = new KeySetList();
		(yyval.key_zset_list_t)->case_idx_ = CASE1;
		(yyval.key_zset_list_t)->key_zset_name_ = (yyvsp[-1].key_zset_name_t);
		(yyval.key_zset_list_t)->key_zset_list_ = (yyvsp[0].key_zset_list_t);
	}
#line 6313 "bison_parser.cpp"
    break;

  case 266:
#line 2660 "bison.y"
                   {
		(yyval.zmember_name_t) = new ZmemberName();
		(yyval.zmember_name_t)->case_idx_ = CASE0;
		(yyval.zmember_name_t)->identifier_ = (yyvsp[0].identifier_t);
		if((yyval.zmember_name_t)){
			auto tmp1 = (yyval.zmember_name_t)->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataZmemberName;
				tmp1->scope_ = 2;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
#line 6331 "bison_parser.cpp"
    break;

  case 267:
#line 2676 "bison.y"
                     {
		(yyval.zmember_name_list_t) = new ZmemberNameList();
		(yyval.zmember_name_list_t)->case_idx_ = CASE0;
		(yyval.zmember_name_list_t)->zmember_name_ = (yyvsp[0].zmember_name_t);
		if((yyval.zmember_name_list_t)){
			auto tmp1 = (yyval.zmember_name_list_t)->zmember_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataZmemberName;
					tmp2->scope_ = 2;
					tmp2->data_flag_ = (DATAFLAG)2; 
				}	
			}
		}
	}
#line 6352 "bison_parser.cpp"
    break;

  case 268:
#line 2692 "bison.y"
                                      {
		(yyval.zmember_name_list_t) = new ZmemberNameList();
		(yyval.zmember_name_list_t)->case_idx_ = CASE1;
		(yyval.zmember_name_list_t)->zmember_name_ = (yyvsp[-1].zmember_name_t);
		(yyval.zmember_name_list_t)->zmember_name_list_ = (yyvsp[0].zmember_name_list_t);
		if((yyval.zmember_name_list_t)){
			auto tmp1 = (yyval.zmember_name_list_t)->zmember_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataZmemberName;
					tmp2->scope_ = 2;
					tmp2->data_flag_ = (DATAFLAG)2; 
				}	
			}
		}
   }
#line 6374 "bison_parser.cpp"
    break;

  case 269:
#line 2712 "bison.y"
                           {
		(yyval.zmember_value_t) = new ZmemberValue();
		(yyval.zmember_value_t)->case_idx_ = CASE0;
		(yyval.zmember_value_t)->value_ = (yyvsp[-1].value_t);
		(yyval.zmember_value_t)->zmember_name_ = (yyvsp[0].zmember_name_t);
		if((yyval.zmember_value_t)){
			auto tmp1 = (yyval.zmember_value_t)->zmember_name_;
			if(tmp1){
				auto tmp2 = tmp1->identifier_;
				if(tmp2){
					tmp2->data_type_=kDataZmemberName;
					tmp2->scope_ = 2;
					tmp2->data_flag_ = (DATAFLAG)1; 
				}	
			}
		}
	}
#line 6396 "bison_parser.cpp"
    break;

  case 270:
#line 2733 "bison.y"
                      {
		(yyval.zmember_value_list_t) = new MemberValueList();
		(yyval.zmember_value_list_t)->case_idx_ = CASE0;
		(yyval.zmember_value_list_t)->zmember_value_ = (yyvsp[0].zmember_value_t);
	}
#line 6406 "bison_parser.cpp"
    break;

  case 271:
#line 2738 "bison.y"
                                      {
	    (yyval.zmember_value_list_t) = new MemberValueList();
		(yyval.zmember_value_list_t)->case_idx_ = CASE1;
		(yyval.zmember_value_list_t)->zmember_value_ = (yyvsp[-1].zmember_value_t);
		(yyval.zmember_value_list_t)->zmember_value_list_ = (yyvsp[0].zmember_value_list_t);
   }
#line 6417 "bison_parser.cpp"
    break;

  case 272:
#line 2748 "bison.y"
                {
		(yyval.timesecond_t) = new TimeSecond();
		(yyval.timesecond_t)->case_idx_ = CASE0;
		(yyval.timesecond_t)->literal_ = (yyvsp[0].literal_t);
	}
#line 6427 "bison_parser.cpp"
    break;

  case 273:
#line 2756 "bison.y"
                {
		(yyval.timeunix_t) = new TimeUnix();
		(yyval.timeunix_t)->case_idx_ = CASE0;
		(yyval.timeunix_t)->literal_ = (yyvsp[0].literal_t);
	}
#line 6437 "bison_parser.cpp"
    break;

  case 274:
#line 2764 "bison.y"
                     {
		(yyval.operandnum_t) = new Identifier();
		(yyval.operandnum_t)->case_idx_ = CASE0;
		(yyval.operandnum_t)->int_literal_ = (yyvsp[0].int_literal_t);
	}
#line 6447 "bison_parser.cpp"
    break;

  case 275:
#line 2773 "bison.y"
                   {
		(yyval.operandnum_list_t) = new OperandnumList();
		(yyval.operandnum_list_t)->case_idx_ = CASE0;
		(yyval.operandnum_list_t)->operandnum_ = (yyvsp[0].operandnum_t);
	}
#line 6457 "bison_parser.cpp"
    break;

  case 276:
#line 2778 "bison.y"
                                   {
	    (yyval.operandnum_list_t) = new OperandnumList();
		(yyval.operandnum_list_t)->case_idx_ = CASE1;
		(yyval.operandnum_list_t)->operandnum_ = (yyvsp[-1].operandnum_t);
		(yyval.operandnum_list_t)->operandnum_list_ = (yyvsp[0].operandnum_list_t);
    }
#line 6468 "bison_parser.cpp"
    break;

  case 277:
#line 2788 "bison.y"
                    {
		(yyval.identifier_t) = new Identifier();
		(yyval.identifier_t)->string_val_ = (yyvsp[0].sval);
		free((yyvsp[0].sval));
	}
#line 6478 "bison_parser.cpp"
    break;

  case 278:
#line 2796 "bison.y"
                        {
		(yyval.literal_t) = new Literal();
		(yyval.literal_t)->case_idx_ = CASE0;
		(yyval.literal_t)->string_literal_ = (yyvsp[0].string_literal_t);

	}
#line 6489 "bison_parser.cpp"
    break;

  case 279:
#line 2802 "bison.y"
                     {
		(yyval.literal_t) = new Literal();
		(yyval.literal_t)->case_idx_ = CASE2;
		(yyval.literal_t)->num_literal_ = (yyvsp[0].num_literal_t);
		
	}
#line 6500 "bison_parser.cpp"
    break;

  case 280:
#line 2811 "bison.y"
                       {
		(yyval.string_literal_t) = new StringLiteral();
		(yyval.string_literal_t)->string_val_ = (yyvsp[0].sval);
		free((yyvsp[0].sval));
		
	}
#line 6511 "bison_parser.cpp"
    break;

  case 281:
#line 2820 "bison.y"
                     {
		(yyval.num_literal_t) = new NumLiteral();
		(yyval.num_literal_t)->case_idx_ = CASE0;
		(yyval.num_literal_t)->int_literal_ = (yyvsp[0].int_literal_t);
		
	}
#line 6522 "bison_parser.cpp"
    break;

  case 282:
#line 2826 "bison.y"
                       {
		(yyval.num_literal_t) = new NumLiteral();
		(yyval.num_literal_t)->case_idx_ = CASE1;
		(yyval.num_literal_t)->float_literal_ = (yyvsp[0].float_literal_t);
		
	}
#line 6533 "bison_parser.cpp"
    break;

  case 283:
#line 2835 "bison.y"
                    {
		(yyval.int_literal_t) = new IntLiteral();
		(yyval.int_literal_t)->int_val_ = (yyvsp[0].ival);
		
	}
#line 6543 "bison_parser.cpp"
    break;

  case 284:
#line 2843 "bison.y"
                      {
		(yyval.float_literal_t) = new FloatLiteral();
		(yyval.float_literal_t)->float_val_ = (yyvsp[0].fval);
		
	}
#line 6553 "bison_parser.cpp"
    break;


#line 6557 "bison_parser.cpp"

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, result, scanner, YY_("syntax error"));
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
        yyerror (&yylloc, result, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval, &yylloc, result, scanner);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp, result, scanner);
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
#line 2851 "bison.y"

