/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 61 "bison_parser.h"

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

#line 392 "bison_parser.h"

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
