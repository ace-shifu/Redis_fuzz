%{
#include "bison_parser.h"
#include "flex_lexer.h"
#include <stdio.h>
#include <string.h>
int yyerror(YYLTYPE* llocp, Program * result, yyscan_t scanner, const char *msg) { return 0; }
%}
%code requires {
#include "../include/ast.h"
#include "parser_typedef.h"
}
%define api.prefix	{ff_}
%define parse.error	verbose
%define api.pure	full
%define api.token.prefix	{SQL_}
%locations

%initial-action {
    // Initialize
    @$.first_column = 0;
    @$.last_column = 0;
    @$.first_line = 0;
    @$.last_line = 0;
    @$.total_column = 0;
    @$.string_length = 0;
};
%lex-param { yyscan_t scanner }
%parse-param { Program* result }
%parse-param { yyscan_t scanner }
%union FF_STYPE{
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
}


%token DEL DUMP EXISTS EXPIRE EXPIREAT KEYS MIGRATE COPY REPLACE MOVE OBJECT REFCOUNT ENCODING IDLETIME PERSIST PEXPIRE PEXPIREAT PTTL RANDOMKEY RENAME RENAMENX RESTORE SORT GET STORE TTL TYPE       
%token APPEND BITCOUNT BITOP DECR DECRBY GETBIT GETRANGE GETSET INCR INCRBY INCRBYFLOAT MGET MSET MSETNX PSETEX SET
%token AND OR XOR NOT BY LIMIT ASC DESC ALPHA EX PX NX XX SETBIT SETEX SETNX SETRANGE STRLEN BEFORE AFTER SUM MIN MAX
%token HDEL HEXISTS HGET HGETALL HINCRBY HINCRBYFLOAT HKEYS HLEN HMGET HMSET HSET HSETNX HVALS 
%token LINDEX LINSERT LLEN LPOP LPUSH LPUSHX LRANGE LREM LSET LTRIM RPOP RPOPLPUSH RPUSH RPUSHX 
%token SADD SCARD SDIFF SDIFFSTORE SINTER SINTERSTORE SISMEMBER SMEMBERS SMOVE SPOP SRANDMEMBER SREM SUNION SUNIONSTORE ZADD ZCARD ZCOUNT ZINCRBY ZRANGE WITHSCORES ZRANGEBYSCORE ZRANK ZREM ZREMRANGEBYRANK ZREMRANGEBYSCORE ZREVRANGE ZREVRANGEBYSCORE ZREVRANK ZSCORE ZUNIONSTORE WEIGHTS AGGREGATE ZINTERSTORE SELECT


%token <ival> INTLITERAL

%token <fval> FLOATLITERAL

%token <sval> IDENTIFIER

%token <sval> STRINGLITERAL


%type <program_t> program;
%type <stmtlist_t> stmtlist;
%type <stmt_t> stmt;
%type <key_stmt_t> key_stmt;
%type <string_stmt_t> string_stmt;
%type <hash_stmt_t> hash_stmt;
%type <list_stmt_t> list_stmt;
%type <set_stmt_t> set_stmt;
%type <zset_stmt_t> zset_stmt;
%type <connect_stmt_t> connect_stmt;

%type <del_stmt_t> del_stmt;
%type <key_list_t> key_list;
%type <dump_stmt_t> dump_stmt;
%type <exists_stmt_t> exists_stmt;
%type <expire_stmt_t> expire_stmt;
%type <expireat_stmt_t> expireat_stmt;
%type <move_stmt_t> move_stmt;
%type <object_stmt_t> object_stmt;
%type <objoption_t> objoption;
%type <persist_stmt_t> persist_stmt;
%type <pexpire_stmt_t> pexpire_stmt;
%type <pexpireat_stmt_t> pexpireat_stmt;
%type <pttl_stmt_t> pttl_stmt;
%type <randomkey_stmt_t> randomkey_stmt;
%type <rename_stmt_t> rename_stmt;
%type <renamenx_stmt_t> renamenx_stmt;
%type <aliasname_t> aliasname;
%type <sort_stmt_t> sort_stmt;
%type <sort_clause_t> sort_clause;
%type <opt_by_clause_t> opt_by_clause;
%type <opt_limit_clause_t> opt_limit_clause;
%type <opt_store_clause_t> opt_store_clause;
%type <ttl_stmt_t> ttl_stmt;
%type <type_stmt_t> type_stmt;
%type <opt_sort_behavior_t> opt_sort_behavior;


%type <append_stmt_t> append_stmt;
%type <bicount_stmt_t> bicount_stmt;
%type <setbit_stmt_t> setbit_stmt;
%type <bitop_stmt_t> bitop_stmt;
%type <decr_stmt_t> decr_stmt;
%type <decrby_stmt_t> decrby_stmt;
%type <get_stmt_t> get_stmt;
%type <getbit_stmt_t> getbit_stmt;
%type <getrange_stmt_t> getrange_stmt;
%type <getset_stmt_t> getset_stmt;
%type <incr_stmt_t> incr_stmt;
%type <incrby_stmt_t> incrby_stmt;
%type <incrbyfloat_stmt_t> incrbyfloat_stmt;
%type <mget_stmt_t> mget_stmt;
%type <mset_stmt_t> mset_stmt;
%type <psetex_stmt_t> psetex_stmt;
%type <setkey_stmt_t> setkey_stmt;
%type <setkey_clause_t> setkey_clause;
%type <opt_expiretime_clause_t> opt_expiretime_clause;
%type <opt_setkey_behavior_t> opt_setkey_behavior;
%type <setex_stmt_t> setex_stmt;
%type <setnx_stmt_t> setnx_stmt;
%type <setrange_stmt_t> setrange_stmt;
%type <strlen_stmt_t> strlen_stmt;

%type <hdel_stmt_t> hdel_stmt;
%type <hexists_stmt_t> hexists_stmt;
%type <hget_stmt_t> hget_stmt;
%type <hgetall_stmt_t> hgetall_stmt;
%type <hincrby_stmt_t> hincrby_stmt;
%type <hincrbyfloat_stmt_t> hincrbyfloat_stmt;
%type <hkeys_stmt_t> hkeys_stmt;
%type <hlen_stmt_t> hlen_stmt;
%type <hmget_stmt_t> hmget_stmt;
%type <hmset_stmt_t> hmset_stmt;
%type <hset_stmt_t> hset_stmt;
%type <hsetnx_stmt_t> hsetnx_stmt;
%type <hvals_stmt_t> hvals_stmt;

%type <lindex_stmt_t> lindex_stmt;
%type <linsert_stmt_t> linsert_stmt;
%type <opt_linsert_behavior_t> opt_linsert_behavior; 
%type <llen_stmt_t> llen_stmt;
%type <lpop_stmt_t> lpop_stmt;
%type <lpush_stmt_t> lpush_stmt;
%type <lpushx_stmt_t> lpushx_stmt;
%type <lrange_stmt_t> lrange_stmt;
%type <lrem_stmt_t> lrem_stmt;
%type <lset_stmt_t> lset_stmt;
%type <ltrim_stmt_t> ltrim_stmt;
%type <rpop_stmt_t> rpop_stmt;
%type <rpoplpush_stmt_t> rpoplpush_stmt;
%type <rpush_stmt_t> rpush_stmt;
%type <rpushx_stmt_t> rpushx_stmt;

%type <sadd_stmt_t> sadd_stmt;
%type <scard_stmt_t> scard_stmt;
%type <sdiff_stmt_t> sdiff_stmt;
%type <sdiffstore_stmt_t> sdiffstore_stmt;
%type <sinter_stmt_t> sinter_stmt;
%type <sinterstore_stmt_t> sinterstore_stmt;
%type <sismember_stmt_t> sismember_stmt;
%type <smember_stmt_t> smember_stmt;
%type <smove_stmt_t> smove_stmt;
%type <spop_stmt_t> spop_stmt;
%type <srandmember_stmt_t> srandmember_stmt;
%type <srem_stmt_t> srem_stmt;
%type <sunion_stmt_t> sunion_stmt;
%type <sunionstore_stmt_t> sunionstore_stmt;

%type <zadd_stmt_t> zadd_stmt;
%type <zcard_stmt_t> zcard_stmt;
%type <zcount_stmt_t> zcount_stmt;
%type <zincrby_stmt_t> zincrby_stmt;
%type <zrange_stmt_t> zrange_stmt;
%type <opt_zrange_behavior_t> opt_zrange_behavior;
%type <zrangebyscore_stmt_t> zrangebyscore_stmt;
%type <zrangebyscore_clause_t> zrangebyscore_clause;
%type <zrank_stmt_t> zrank_stmt;
%type <zrem_stmt_t> zrem_stmt;
%type <zscore_stmt_t> zscore_stmt;
%type <zunionstore_stmt_t> zunionstore_stmt;
%type <zunionstore_clause_t> zunionstore_clause;
%type <zinterstore_clause_t> zinterstore_clause;
%type <opt_weight_clause_t> opt_weight_clause;
%type <opt_aggregate_clause_t> opt_aggregate_clause;
%type <zinterstore_stmt_t> zinterstore_stmt;

%type <select_stmt_t> select_stmt;
%type <keyname_t> keyname;
%type <key_string_name_t> key_string_name;
%type <key_hash_name_t> key_hash_name;
%type <key_list_name_t> key_list_name;
%type <key_set_name_t> key_set_name;
%type <key_zset_name_t> key_zset_name;
%type <key_string_list_t> key_string_list;
%type <key_string_value_list_t> key_string_value_list;
%type <key_string_value_t> key_string_value;
%type <key_set_list_t> key_set_list;
%type <del_key_set_list_t> del_key_set_list;
%type <key_zset_list_t> key_zset_list;
%type <value_list_t> value_list;
%type <value_t> value;
%type <field_list_t> field_list;
%type <del_field_list_t> del_field_list;
%type <field_name_t> field_name;
%type <field_value_t> field_value;
%type <zmember_name_t> zmember_name;
%type <zmember_name_list_t> zmember_name_list;
%type <zmember_value_t> zmember_value;
%type <zmember_value_list_t> zmember_value_list;
%type <smember_name_t> smember_name;
%type <smember_name_list_t> smember_name_list;
%type <field_value_list_t> field_value_list;
%type <operandnum_t> operandnum;
%type <operandnum_list_t> operandnum_list;
%type <operation_t> operation;
%type <identifier_t> identifier;
%type <timesecond_t> timesecond;
%type <timeunix_t> timeunix;
%type <literal_t> literal;
%type <string_literal_t> string_literal;
%type <num_literal_t> num_literal;
%type <int_literal_t> int_literal;
%type <float_literal_t> float_literal;


%left  OR
%left  AND
%left  NOT
%nonassoc  OP_NOTEQUAL MATCH LIKE OP_EQUAL
%nonassoc  OP_GREATERTHAN OP_LESSTHAN OP_GREATEREQ OP_LESSEQ
%nonassoc  ISNULL
%nonassoc  IS
%left  OP_ADD OP_SUB
%left  OP_MUL OP_MOD OP_DIVIDE
%left  OP_XOR
%right  UMINUS
%left  OP_LBRACKET OP_RBRACKET
%left  OP_RP OP_LP
%nonassoc  JOIN
%nonassoc  ON

%destructor{
	free( ($$) );
}  <sval>

%destructor{
	 
}  <fval> <ival>

%destructor { if($$!=NULL)$$->deep_delete(); } <*>

%%
program:
	stmtlist  {
		$$ = result;
		$$->case_idx_ = CASE0;
		$$->stmtlist_ = $1;
		$$ = NULL;

	}
  ;

stmtlist:
	stmt {
		$$ = new Stmtlist();
		$$->case_idx_ = CASE0;
		$$->stmt_ = $1;
	}
   |	stmt stmtlist {
	    $$ = new Stmtlist();
		$$->case_idx_ = CASE1;
		$$->stmt_ = $1;
		$$->stmtlist_ = $2;
   }
  ;

stmt:
	    key_stmt  {
		$$ = new Stmt();
		$$->case_idx_ = CASE0;
		$$->key_stmt_ = $1;
		
	}
   |	string_stmt  {
		$$ = new Stmt();
		$$->case_idx_ = CASE1;
		$$->string_stmt_ = $1;
		
	}
   |	hash_stmt  {
		$$ = new Stmt();
		$$->case_idx_ = CASE2;
		$$->hash_stmt_ = $1;
		
	}
   |	list_stmt  {
		$$ = new Stmt();
		$$->case_idx_ = CASE3;
		$$->list_stmt_ = $1;
		
	}
   |	set_stmt  {
		$$ = new Stmt();
		$$->case_idx_ = CASE4;
		$$->set_stmt_ = $1;
		
	}
   |	zset_stmt  {
		$$ = new Stmt();
		$$->case_idx_ = CASE5;
		$$->zset_stmt_ = $1;
		
	} 
   |    connect_stmt {
        $$ = new Stmt();
        $$->case_idx_ = CASE6;
		$$->connect_stmt_ = $1;
   }
  ;

key_stmt:
	    del_stmt  {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE0;
		$$->del_stmt_ = $1;
		
	}
   |	dump_stmt  {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE1;
		$$->dump_stmt_ = $1;
		
	}
   |	exists_stmt  {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE2;
		$$->exists_stmt_ = $1;
		
	}
   |	expire_stmt  {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE3;
		$$->expire_stmt_ = $1;
		
	}
   |	expireat_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE4;
		$$->expireat_stmt_ = $1;
	}
   |	move_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE5;
		$$->move_stmt_ = $1;
	}
   |	object_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE6;
		$$->object_stmt_ = $1;
	}
   |	persist_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE7;
		$$->persist_stmt_ = $1;
	}
   |	pexpire_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE8;
		$$->pexpire_stmt_ = $1;
	}
   |	pexpireat_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE9;
		$$->pexpireat_stmt_ = $1;
	}
   |	pttl_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE10;
		$$->pttl_stmt_ = $1;
	}
   |	randomkey_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE11;
		$$->randomkey_stmt_ = $1;
	}
   |	rename_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE12;
		$$->rname_stmt_ = $1;
	}
   |	renamenx_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE13;
		$$->renamenx_stmt_ = $1;
	}
   |	sort_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE14;
		$$->pttl_stmt_ = $1;
	}
   |	ttl_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE15;
		$$->ttl_stmt_ = $1;
	}
   |	type_stmt {
		$$ = new KeyStmt();
		$$->case_idx_ = CASE16;
		$$->type_stmt_ = $1;
	}
  ;


string_stmt:
	append_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE0;
		$$->append_stmt_ = $1;
		
	}
   |	bicount_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE1;
		$$->bicount_stmt_ = $1;
		
	}
   |	setbit_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE2;
		$$->setbit_stmt_ = $1;
		
	}
   |	bitop_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE3;
		$$->bitop_stmt_ = $1;
		
	}
   |	decr_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE4;
		$$->decr_stmt_ = $1;
		
	}
   |	decrby_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE5;
		$$->decrby_stmtt_ = $1;
		
	}
   |	get_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE6;
		$$->get_stmt_ = $1;
		
	}
   |	getbit_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE7;
		$$->getbit_stmt_ = $1;
		
	}
   |	getrange_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE8;
		$$->getrange_stmt_ = $1;
		
	}
   |	getset_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE9;
		$$->getset_stmt_ = $1;
		
	}
   |	incr_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE10;
		$$->incr_stmt_ = $1;
		
	}
   |	incrby_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE11;
		$$->incrby_stmt_ = $1;
		
	}
   |	incrbyfloat_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE12;
		$$->incrbyfloat_stmt_ = $1;
		
	}
   |	mget_stmt {
		$$ = new StringStmt();
		$$->case_idx_ = CASE13;
		$$->mget_stmt_ = $1;
		
	}
   |	mset_stmt {
		$$ = new StringStmt();
		$$->case_idx_ = CASE14;
		$$->mset_stmt_ = $1;
		
	}
   |	psetex_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE15;
		$$->psetex_stmt_ = $1;
		
	}
   |	setkey_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE16;
		$$->setkey_stmt_ = $1;
		
	}
   |	setex_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE17;
		$$->setex_stmt_ = $1;
		
	}
   |	setnx_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE18;
		$$->setnx_stmt_ = $1;
		
	}
   |	setrange_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE19;
		$$->setrange_stmt_ = $1;
		
	}
   |	strlen_stmt  {
		$$ = new StringStmt();
		$$->case_idx_ = CASE20;
		$$->strlen_stmt_ = $1;
		
	}
  ;


hash_stmt:
		hdel_stmt  {
		$$ = new HashStmt();
		$$->case_idx_ = CASE0;
		$$->hdel_stmt_ = $1;
		
	}
   |	hexists_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE1;
		$$->hexists_stmt_ = $1;	    
    }
   |	hget_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE2;
		$$->hget_stmt_ = $1;	    
    }
   |	hgetall_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE3;
		$$->hgetall_stmt_ = $1;	    
    }
   |	hincrby_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE4;
		$$->hincrby_stmt_ = $1;	    
    }
   |	hincrbyfloat_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE5;
		$$->hincrbyfloat_stmt_ = $1;	    
    }
   |	hkeys_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE6;
		$$->hkeys_stmt_ = $1;	    
    }
   |	hlen_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE7;
		$$->hlen_stmt_ = $1;	    
    }
   |	hmget_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE8;
		$$->hmget_stmt_ = $1;	    
    }
   |	hmset_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE9;
		$$->hmset_stmt_ = $1;	    
    }
   |	hset_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE10;
		$$->hset_stmt_ = $1;	    
    }
   |	hsetnx_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE11;
		$$->hsetnx_stmt_ = $1;	    
    }
   |	hvals_stmt {
		$$ = new HashStmt();
		$$->case_idx_ = CASE12;
		$$->hvals_stmt_ = $1;	    
    }
   ;


list_stmt:
		lindex_stmt  {
		$$ = new ListStmt();
		$$->case_idx_ = CASE0;
		$$->lindex_stmt_ = $1;
		
	}
   |	linsert_stmt { 
		$$ = new ListStmt();
		$$->case_idx_ = CASE1;
		$$->linsert_stmt_ = $1;	    
    }
   |	llen_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE2;
		$$->llen_stmt_ = $1;	    
    }
   |	lpop_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE3;
		$$->lpop_stmt_ = $1;	    
    }
   |	lpush_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE4;
		$$->lpush_stmt_ = $1;	    
    }
   |	lpushx_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE5;
		$$->lpushx_stmt_ = $1;	    
    }
   |	lrange_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE6;
		$$->lrange_stmt_ = $1;	    
    }
   |	lrem_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE7;
		$$->lrem_stmt_ = $1;	    
    }
   |	lset_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE8;
		$$->lset_stmt_ = $1;	    
    }
   |	ltrim_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE9;
		$$->ltrim_stmt_ = $1;	    
    }
   |	rpop_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE10;
		$$->rpop_stmt_ = $1;	    
    }
   |	rpoplpush_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE11;
		$$->rpoplpush_stmt_ = $1;	    
    }
   |	rpush_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE12;
		$$->rpush_stmt_ = $1;	    
    }
   |	rpushx_stmt {
		$$ = new ListStmt();
		$$->case_idx_ = CASE13;
		$$->rpushx_stmt_ = $1;	    
    }
  ;


set_stmt:
		sadd_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE0;
		$$->sadd_stmt__ = $1;
		
	}
   |	scard_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE1;
		$$->scard_stmt_ = $1;	    
    }
   |	sdiff_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE2;
		$$->sdiff_stmt_ = $1;	    
    }
   |	sdiffstore_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE3;
		$$->sdiffstore_stmt_ = $1;	    
    }
   |	sinter_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE4;
		$$->sinter_stmt_ = $1;	    
    }
   |	sinterstore_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE5;
		$$->sinterstore_stmt_ = $1;	    
    }
   |	sismember_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE6;
		$$->sismember_stmt_ = $1;	    
    }
   |	smember_stmt {
		$$ = new SmemberStmt();
		$$->case_idx_ = CASE7;
		$$->smember_stmt_  = $1;	    
    }
   |	smove_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE8;
		$$->smove_stmt_ = $1;	    
    }
   |	spop_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE9;
		$$->spop_stmt_ = $1;	    
    }
   |	srandmember_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE10;
		$$->srandmember_stmt_ = $1;	    
    }
   |	srem_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE11;
		$$->srem_stmt_ = $1;	    
    }
   |	sunion_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE12;
		$$->sunion_stmt_ = $1;	    
    }
   |	sunionstore_stmt {
		$$ = new SetStmt();
		$$->case_idx_ = CASE13;
		$$->sunionstore_stmt_ = $1;	    
    }
   ;

zset_stmt:
		zadd_stmt {
		$$ = new ZaddStmt();
		$$->case_idx_ = CASE0;
		$$->zadd_stmt__ = $1;
		
	}
   |	zcard_stmt {
		$$ = new ZaddStmt();
		$$->case_idx_ = CASE1;
		$$->zcard_stmt_ = $1;	    
    }	
   |	zcount_stmt {
		$$ = new ZaddStmt();
		$$->case_idx_ = CASE2;
		$$->zcount_stmt_ = $1;	    
    }
   |	zincrby_stmt {
		$$ = new ZaddStmt();
		$$->case_idx_ = CASE3;
		$$->zincrby_stmt_ = $1;	    
    }
   |	zrange_stmt {
		$$ = new ZaddStmt();
		$$->case_idx_ = CASE4;
		$$->zrange_stmt_ = $1;	    
    }
   |	zrangebyscore_stmt{
		$$ = new ZaddStmt();
		$$->case_idx_ = CASE5;
		$$->zrangebyscore_stmt_ = $1;	    
    }
   |	zrank_stmt {
		$$ = new ZaddStmt();
		$$->case_idx_ = CASE6;
		$$->zrank_stmt_ = $1;	    
    }
   |	zrem_stmt {
		$$ = new ZremStmt();
		$$->case_idx_ = CASE7;
		$$->zrem_stmt_ = $1;	    
    }
   |	zscore_stmt {
		$$ = new ZaddStmt();
		$$->case_idx_ = CASE8;
		$$->zscore_stmt_ = $1;	    
    }
   |	zunionstore_stmt {
		$$ = new ZaddStmt();
		$$->case_idx_ = CASE9;
		$$->zunionstore_stmt_ = $1;	    
    }
   |	zinterstore_stmt {
		$$ = new ZaddStmt();
		$$->case_idx_ = CASE10;
		$$->zinterstore_stmt_ = $1;	    
    }
   ;



connect_stmt:
		select_stmt {
		$$ = new ConnectStmt();
		$$->case_idx_ = CASE0;
		$$->select_stmt_ = $1;
		
	}	




del_stmt:
	DEL key_list {
		$$ = new DelStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_ = $2;
	}
  ;

dump_stmt:
	DUMP keyname {
		$$ = new DumpStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
	}
  ;

exists_stmt:
	EXISTS keyname {
		$$ = new ExistsStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
	}
  ;

expire_stmt:
	EXPIRE keyname timesecond {
		$$ = new ExpireStmt;
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
		$$->timesecond_ = $3;
	}
   ;

expireat_stmt:
	EXPIREAT keyname timeunix {
		$$ = new ExpireatStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
		$$->timeunix_ = $3;
	}
   ;

move_stmt:
	MOVE keyname operandnum {
		$$ = new MoveStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
		$$->operandnum_ = $3;
	}
   ;

object_stmt:
	OBJECT objoption keyname  {
		$$ = new ObjectStmt();
		$$->case_idx_ = CASE0;
		$$->objoption_ = $2;
		$$->keyname_ = $3;
	}
   ;

objoption:
	REFCOUNT {
		$$ = new Objoption();
		$$->case_idx_ = CASE0;
	}
   |
	ENCODING {
		$$ = new Objoption();
		$$->case_idx_ = CASE1;
	}
   |
	IDLETIME {
		$$ = new Objoption();
		$$->case_idx_ = CASE2;
	}
   ;


persist_stmt:
	PERSIST keyname {
		$$ = new PersistStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
	}
   ;

pexpire_stmt:
	PEXPIRE keyname timesecond {
		$$ = new PexpireStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
		$$->timesecond_ = $3;
	}
   ;

pexpireat_stmt:
	PEXPIREAT keyname timesecond {
		$$ = new PexpireatStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
		$$->timesecond_ = $3;
	}
   ;

pttl_stmt:
	PTTL keyname {
		$$ = new PttlStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
	}
   ;

randomkey_stmt:
	RANDOMKEY {
		$$ = new PttlStmt();
		$$->case_idx_ = CASE0;
	}
   ;

rename_stmt:
	RENAME keyname aliasname {
		$$ = new RenameStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
		$$->aliasname_ = $3;
	}
   ;

renamenx_stmt:
	RENAMENX keyname aliasname {
		$$ = new RenamenxStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
		$$->aliasname_ = $3;
	}
   ;

aliasname :
	identifier {
		$$ = new AliasName();
		$$->case_idx_ = CASE0;
		$$->identifier_ = $1;
		if(tmp1){
			auto tmp2 = tmp1->identifier_; 
			if(tmp2){
				tmp2->data_type_ = kDataKeyName; 
				tmp2->scope_ = 2; 
				tmp2->data_flag_ =(DATAFLAG)64; 
			}
		}
	}

sort_stmt :
	sort_clause opt_by_clause opt_limit_clause opt_sort_behavior opt_store_clause {
		$$ = new SortStmt();
		$$->case_idx_ = CASE0;
		$$->sort_clause_ = $1;
		$$->opt_by_clause_ = $2;
		$$->opt_limit_clause_ = $3;
		$$->opt_sort_behavior_ = $4;
		$$->opt_store_clause_ = $5;
	}
   ;

sort_clause :
	SORT keyname {
		$$ = new SortClause();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
	}
   ;
opt_by_clause :
	BY keyname {
		$$ = new OptByClause();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
	}
   |	{
		$$ = new OptByClause();
		$$->case_idx_ = CASE1;
   }
   ;

opt_limit_clause :
	LIMIT operandnum operandnum {
		$$ = new OptLimitClause();
		$$->case_idx_ = CASE0;
		$$->operandnum1_ = $2;
		$$->operandnum2_ = $3;
	}
   |	{
		$$ = new OptLimitClause();
		$$->case_idx_ = CASE1;
   }
   ;

opt_store_clause :
	STORE keyname {
		$$ = new OptStoreClause();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
	}
   |	{
		$$ = new OptStoreClause();
		$$->case_idx_ = CASE1;
   }
   ;

opt_sort_behavior :
	ASC {
		$$ = new OptSortBehavior();
		$$->case_idx_ = CASE0;
	}
   |	DESC {
	   $$ = new OptSortBehavior();
	   $$->case_idx_ = CASE1;
    }
   |	ALPHA {
	   $$ = new OptSortBehavior();
	   $$->case_idx_ = CASE2;
    }
   |	{
	   $$ = new OptSortBehavior();
	   $$->case_idx_ = CASE3;
   }
  ;


ttl_stmt:
	TTL keyname {
		$$ = new TtlStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
	}
   ;

type_stmt:
	TYPE keyname {
		$$ = new TypeStmt();
		$$->case_idx_ = CASE0;
		$$->keyname_ = $2;
	}
   ;


append_stmt:
	APPEND key_string_name value{
		$$ = new AppendStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->value_ = $3;
	}
   ;


bicount_stmt :
	BITCOUNT key_string_name {
		$$ = new BicountStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
	}
   ;

setbit_stmt:
	SETBIT key_string_name operandnum value{
		$$ = new SetbitStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->operandnum_ = $3;
		$$->value_ = $4;
	}
   ;

bitop_stmt:
	BITOP operation key_string_list{
		$$ = new BitopStmt();
		$$->case_idx_ = CASE0;
		$$->operation_ = $2;
		$$->key_string_list_ = $3;
	}
   ;

operation :
	AND {
		$$ = new Operation();
		$$->case_idx_ = CASE0;
	}	
   |	OR {
		$$ = new Operation();
		$$->case_idx_ = CASE1;
	}
   |	XOR {
		$$ = new Operation();
		$$->case_idx_ = CASE2;
	}	
   | 	NOT {
		$$ = new Operation();
		$$->case_idx_ = CASE3;
	}
   ;

decr_stmt:
	DECR key_string_name {
		$$ = new DecrStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
	}
   ;

decrby_stmt:
	DECRBY key_string_name num_literal {
		$$ = new DecrbyStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->num_literal_ = $3;
	}
   ;

get_stmt:
	GET key_string_name {
		$$ = new GetStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
	}
   ;

getbit_stmt:
	GETBIT key_string_name operandnum{
		$$ = new GetbitStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->operandnum_ = $3;
	}
   ;

getrange_stmt:
	GETRANGE key_string_name operandnum operandnum {
		$$ = new TypeStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->operandnum1_ = $3;
		$$->operandnum2_ = $4;
	}
   ;

getset_stmt:
	GETSET key_string_name value{
		$$ = new GetStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->value_ = $3;
	}
   ;

incr_stmt:
	INCR key_string_name {
		$$ = new IncrStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
	}
   ;

incrby_stmt:
	INCRBY key_string_name num_literal {
		$$ = new IncrbyStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->num_literal_ = $3;
	}
   ;

incrbyfloat_stmt:
	INCRBYFLOAT key_string_name float_literal {
		$$ = new TypeStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->float_literal_ = $3;
	}
   ;

mget_stmt:
	MGET key_string_list {
		$$ = new MgetStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_list_ = $2;
	}
   ;


mset_stmt:
	MSET key_string_value_list {
		$$ = new MsetStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_value_list_ = $2;
	}
  ;	



psetex_stmt:
	PSETEX key_string_name timesecond value {
		$$ = new TypeStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->timesecond_ = $3;
		$$->value_ = $4;
	}
   ;

setkey_stmt :
	SET setkey_clause opt_expiretime_clause opt_setkey_behavior {
		$$ = new SetkeyStmt();
		$$->case_idx_ = CASE0;
		$$->setkey_clause_ = $2;
		$$->opt_expiretime_clause_ = $3;
		$$->opt_setkey_behavior_ = $4;
	}
   ;

setkey_clause:
	key_string_name value {
		$$ = new SetkeyClause;
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $1;
		$$->value_ = $2;
		if($$){
			auto tmp1 = $$->key_string_name_;
			if(tmp1){
				tmp1->data_type_ = kDataStringName; 
				tmp1->scope_ = 1; 
				tmp1->data_flag_ =(DATAFLAG)1; 
			}
		}
	}
   ;

opt_expiretime_clause:
	EX timesecond {
		$$ = new OptExpireTimeClause();
		$$->case_idx_ = CASE0;
		$$->timesecond_ = $2;
	}
   |	PX timesecond {
	    $$ = new OptExpireTimeClause();
		$$->case_idx_ = CASE1;
		$$->timesecond_ = $2;
    }
   |	{
	    $$ = new OptExpireTimeClause();
		$$->case_idx_ = CASE2;
   }
   ;

opt_setkey_behavior:
	NX {
		$$ = OptSetkeyBehavior();
		$$->case_idx_ = CASE0;
	}
   |	XX {
	    $$ = OptSetkeyBehavior();
		$$->case_idx_ = CASE1;
    }
   |	{
	    $$ = OptSetkeyBehavior();
		$$->case_idx_ = CASE2;
   }
   ;



setex_stmt :
	SETEX key_string_name timesecond value {
		$$ = new TypeStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->timesecond_ = $3;
		$$->value_ = $4;
		if($$){
			auto tmp1 = $$->key_string_name_;
			if(tmp1){
				tmp1->data_type_ = kDataStringName; 
				tmp1->scope_ = 1; 
				tmp1->data_flag_ =(DATAFLAG)1; 
			}
		}
	}
   ;

setnx_stmt :
	SETNX key_string_name value{
		$$ = new SetnxStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->value_ = $3;
		if($$){
			auto tmp1 = $$->key_string_name_;
			if(tmp1){
				tmp1->data_type_ = kDataStringName; 
				tmp1->scope_ = 1; 
				tmp1->data_flag_ =(DATAFLAG)1; 
			}
		}
	}
   ;

setrange_stmt  :
	SETRANGE key_string_name operandnum value {
		$$ = new SetrangeStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
		$$->operandnum_ = $3;
		$$->value_ = $4;
	}
   ;
   
strlen_stmt:
	STRLEN key_string_name {
		$$ = new StrlenStmt();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $2;
	}
   ;



hdel_stmt :
	HDEL key_hash_name del_field_list {
		$$ = new HdelStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
		$$->del_field_list_ = $3;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataHashName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
	}
   ; 
 

hexists_stmt :
	HEXISTS key_hash_name field_name {
		$$ = new HexistsStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
		$$->field_name_ = $3;
	}
   ; 

hget_stmt :
	HGET key_hash_name field_name {
		$$ = new HgetStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
		$$->field_name_ = $3;
	}
   ;


hgetall_stmt :
	HGETALL key_hash_name {
		$$ = new HgetallStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
	}
   ; 

hincrby_stmt :
	HINCRBY key_hash_name field_name num_literal{
		$$ = new HincrbyStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
		$$->field_name_ = $3;
		$$->num_literal_ = $4;
	}
   ; 

hincrbyfloat_stmt :
	HINCRBYFLOAT key_hash_name field_name float_literal {
		$$ = new HincrbyfloatStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
		$$->field_name_ = $3;
		$$->float_literal_ = $4;
	}
   ; 

hkeys_stmt :
	HKEYS key_hash_name {
		$$ = new HkeysStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
	}
   ; 

hlen_stmt :
	HLEN key_hash_name {
		$$ = new HlenStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
	}
   ; 

hmget_stmt :
	HMGET key_hash_name field_list {
		$$ = new TypeStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
		$$->field_list_ = $3;
	}
   ; 

hmset_stmt :
	HMSET key_hash_name field_value_list {
		$$ = new HmsetStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
		$$->field_value_list_ = $3;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataHashName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
	}
   ; 

hset_stmt:
	HSET key_hash_name field_value {
		$$ = new HsetStmtt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
		$$->field_value_ = $3;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataHashName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
	}
   ; 

hsetnx_stmt :
	HSETNX key_hash_name field_value {
		$$ = new HsetnxStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
		$$->field_value_ = $3;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataHashName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
	}
   ; 

hvals_stmt :
	HVALS key_hash_name {
		$$ = new TypeStmt();
		$$->case_idx_ = CASE0;
		$$->key_hash_name_ = $2;
	}
   ; 


lindex_stmt :
	LINDEX key_list_name operandnum {
		$$ = new LindexStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
		$$->operandnum_ = $3;
	}
   ; 

linsert_stmt :
	LINSERT key_list_name opt_linsert_behavior value value {
		$$ = new TypeStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
		$$->opt_linsert_behavior_ = $3;
		$$->value1_ = $4;
		$$->value2_ = $5;
		if($$){
			auto tmp1 = $$->key_list_name_;
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
   ; 

opt_linsert_behavior :
	BEFORE {
		$$ = new OptLinsertBehavior();
		$$->case_idx_ = CASE0;
	}
   |	AFTER {
	    $$ = new OptLinsertBehavior();
		$$->case_idx_ = CASE1;
    }
   ;

llen_stmt :
	LLEN key_list_name {
		$$ = new LlenStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
	}
   ; 

lpop_stmt :
	LPOP key_list_name {
		$$ = new LpopStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
	}
   ; 

lpush_stmt :
	LPUSH key_list_name value_list {
		$$ = new TypeStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
		$$->value_list_ = $3;
		if($$){
			auto tmp1 = $$->key_list_name_;
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
   ; 

lpushx_stmt :
	LPUSHX key_list_name value{
		$$ = new LpushxStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
		$$->value_ = $3;
		if($$){
			auto tmp1 = $$->key_list_name_;
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
   ; 
lrange_stmt :
	LRANGE key_list_name operandnum operandnum {
		$$ = new LrangeStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
		$$->operandnum1_ = $3;
		$$->operandnum2_ = $4;
	}
   ; 


lrem_stmt :
	LREM key_list_name operandnum value {
		$$ = new LremStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
		$$->operandnum_ =$3;
		$$->value_ = $4;
		if($$){
			auto tmp1 = $$->key_list_name_;
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
   ; 

lset_stmt :
	LSET key_list_name operandnum value {
		$$ = new LsetStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
		$$->operandnum_ = $3;
		$$->value_ = $4;
		if($$){
			auto tmp1 = $$->key_list_name_;
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
   ; 

ltrim_stmt :
	LTRIM key_list_name operandnum operandnum {
		$$ = new LtrimStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
		$$->operandnum1_ = $3;
		$$->operandnum2_ = $4;
	}
   ; 

rpop_stmt :
	RPOP key_list_name {
		$$ = new RpopStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
	}
   ; 

rpoplpush_stmt :
	RPOPLPUSH key_list_name key_list_name {
		$$ = new TypeStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name1_ = $2;
		$$->key_list_name2_ = $3;
	}
   ; 

rpush_stmt :
	RPUSH key_list_name value_list {
		$$ = new RpushStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
		$$->value_list_ = $3;
		if($$){
			auto tmp1 = $$->key_list_name_;
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
   ; 

rpushx_stmt :
	RPUSHX key_list_name value {
		$$ = new RpushxStmt();
		$$->case_idx_ = CASE0;
		$$->key_list_name_ = $2;
		$$->value_ = $3;
		if($$){
			auto tmp1 = $$->key_list_name_;
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
   ; 


sadd_stmt :
	SADD key_set_name smember_name_list {
		 $$ = new SaddStmt();
		 $$->case_idx_ = CASE0;
		 $$->key_set_name_ = $2;
		 $$->smember_name_list_ = $3;
		if($$){
			auto tmp1 = $$->key_set_name_;
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
   ;

scard_stmt :
	SCARD key_set_name {
		$$ = new ScardStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_name_ = $2;
	}
   ;

sdiff_stmt :
	SDIFF key_set_list {
		$$ = new SdiffStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_list_ = $2;
	}
   ;

sdiffstore_stmt :
	SDIFFSTORE key_set_list {
		$$ = new SdiffStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_list_ = $2;
	}
   ;

sinter_stmt :
	SINTER key_set_list {
		$$ = new SinterStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_list_ = $2;
	}
   ;

sinterstore_stmt :
	SINTERSTORE key_set_list {
		$$ = new SinterstoreStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_list_ = $2;
	}
   ;

sismember_stmt :
	SISMEMBER key_set_name smember_name {
		$$ = new SismemberStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_name_ = $2;
		$$->smember_name_ = $3;
	}
   ;

smember_stmt :
	SMEMBERS key_set_name {
		$$ = new SmemberStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_name_ = $2;
	}
   ;

smove_stmt :
	SMOVE key_set_name key_set_name smember_name {
		$$ = new SmoveStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_name1_ = $2;
		$$->key_set_name2_ = $3;
		$$->smember_name_ = $4;
	}
   ;

spop_stmt :
	SPOP key_set_name {
		$$ = new SpopStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_name_ = $2;
		if($$){
			auto tmp1 = $$->key_set_name_;
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
   ;

srandmember_stmt :
	SRANDMEMBER key_set_name operandnum {
		$$ = new SrandmemberStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_name_ = $2;
		$$->operandnum_ = $3; 
	}
   ;

srem_stmt :
	SREM key_set_name del_key_set_list {
		$$ = new SrandmemberStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_name_ = $2;
		$$->del_key_set_list_ = $3;
	}
   ;

sunion_stmt :
	SUNION key_set_list {
		$$ = new SunionStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_list_ = $2;
	}
   ;

sunionstore_stmt :
	SUNIONSTORE key_set_list {
		$$ = new SunionstoreStmt();
		$$->case_idx_ = CASE0;
		$$->key_set_list_ = $2;
	}
   ;



zadd_stmt:
	ZADD key_zset_name zmember_value_list {
		$$ = new ZaddStmt();
		$$->case_idx_ = CASE0;
		$$->key_zset_name_ = $2;
		$$->zmember_value_list_ = $3;
		if($$){
			auto tmp1 = $$->key_zset_name_;
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
   ;

zcard_stmt :
	ZCARD key_zset_name {
		$$ = new ZcardStmt();
		$$->case_idx_ = CASE0;
		$$->key_zset_name_ = $2;
	}
   ;

zcount_stmt :
	ZCOUNT key_zset_name operandnum operandnum {
		$$ = new RpopStmt();
		$$->case_idx_ = CASE0;
		$$->key_zset_name_ = $2;
		$$->operandnum1_ = $3;
		$$->operandnum2_ = $4;
	}
   ;

zincrby_stmt :
	ZINCRBY key_zset_name operandnum zmember_name {
		$$ = new ZincrbyStmt();
		$$->case_idx_ = CASE0;
		$$->key_zset_name_ = $2;
		$$->operandnum_ = $3;
		$$->zmember_name_ = $4;
	}
   ;

zrange_stmt :
		ZRANGE key_zset_name operandnum operandnum opt_zrange_behavior{
		$$ = new ZrangeStmt();
		$$->case_idx_ = CASE1;
		$$->key_zset_name_ = $2;
		$$->operandnum1_ = $3;
		$$->operandnum2_ = $4;
		$$->opt_zrange_behavior_ = $5;	   	
   }
   ;

opt_zrange_behavior :
	WITHSCORES{
		$$ = new OptZrangeBehavior();
		$$->case_idx_ = CASE0;
	}
   |	{
		$$ = new OptZrangeBehavior();
		$$->case_idx_ = CASE1;
   }
   ;

zrangebyscore_stmt :
	zrangebyscore_clause opt_limit_clause {
		$$ = new ZrangebyscoreStmt();
		$$->case_idx_ = CASE0;
		$$->zrange_stmt_ = $1;
		$$->opt_limit_clause_ = $2;
	}
   ;
zrangebyscore_clause :
	ZRANGEBYSCORE key_zset_name operandnum operandnum {
		$$ = new ZrangebyscoreClause();
		$$->case_idx_ = CASE0;
		$$->key_zset_name_ = $2;
		$$->operandnum1_ = $3;
		$$->operandnum2_ = $4;
	}


zrank_stmt :
	ZRANK key_zset_name zmember_name {
		$$ = new ZrankStmt();
		$$->case_idx_ = CASE0;
		$$->key_zset_name_ = $2;
		$$->zmember_name_ = $3;
	}
   ;

zrem_stmt :
	ZREM key_zset_name zmember_name_list {
		$$ = new ZremStmt();
		$$->case_idx_ = CASE0;
		$$->key_zset_name_ = $2;
		$$->zmember_name_list_ = $3;
	}
   ;


zscore_stmt :
	ZSCORE key_zset_name zmember_name {
		$$ = new ZscoreStmt();
		$$->case_idx_ = CASE0;
		$$->key_zset_name_ = $2;
		$$->zmember_name_ = $3;
	}
   ;

zunionstore_stmt :
	zunionstore_clause opt_weight_clause opt_aggregate_clause {
		$$ = new ZunionstoreStmt();
		$$->case_idx_ = CASE0;
		$$->zunionstore_clause_ = $1;
		$$->opt_weight_clause_ = $2;
		$$->opt_aggregate_clause_ = $3;
	}
   ;

zunionstore_clause:
	ZUNIONSTORE key_zset_name operandnum key_zset_list {
		$$ = new ZunionstoreClause();
		$$->case_idx_ = CASE0;
		$$->key_zset_name_ = $2;
		$$->operandnum_ = $3;
		$$->key_zset_list_ = $4;
	}


opt_weight_clause:
	WEIGHTS operandnum_list {
		$$ = new OptWeightClause();
		$$->case_idx_ = CASE0;
		$$->operandnum_list_ = $2;
	}
   |	{
	    $$ = new OptWeightClause();
		$$->case_idx_ = CASE1;
   }
   ;


opt_aggregate_clause:
	AGGREGATE SUM {
		$$ = new OptAggregateClause();
		$$->case_idx_ = CASE0;

	}
   | 	AGGREGATE MIN {
	    $$ = new OptAggregateClause();
		$$->case_idx_ = CASE1;
   } 
   | 	AGGREGATE MAX {
	    $$ = new OptAggregateClause();
		$$->case_idx_ = CASE2;
    }
   |	{
	    $$ = new OptAggregateClause();
		$$->case_idx_ = CASE3;
   }
   ;


zinterstore_stmt :
	zinterstore_clause opt_weight_clause opt_aggregate_clause {
		$$ = new ZinterstoreStmt();
		$$->case_idx_ = CASE0;
		$$->zinterstore_clause_ = $1;
		$$->opt_weight_clause_ = $2;
		$$->opt_aggregate_clause_ = $3;
	}
   ;

zinterstore_clause :
	ZINTERSTORE key_zset_name operandnum key_zset_list {
		$$ = new ZinterstoreClause();
		$$->case_idx_ = CASE0;
		$$->key_zset_name_ = $2;
		$$->operandnum_ = $3;
		$$->key_zset_list_ = $4;
	}	
   ;


	
select_stmt :
	SELECT operandnum {
		$$ = new SelectStmt();
		$$->case_idx_ = CASE0;
		$$->operandnum_ = $2;
	}
   ;


key_list:
	keyname {
		$$ = new KeyList();
		$$->case_idx_  = CASE0;
		$$->keyname_ = $1;
		if($$){
			auto tmp1 = $$->keyname_;
			if(tmp1){
				tmp1->data_type_=kDataKeyName;
				tmp1->scope_ = 0;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
	}
   |	keyname key_list {
	    $$ = new KeyList();
		$$->case_idx_ = CASE1;
		$$->keyname_ = $1;
		$$->key_list_ = $2;
		if($$){
			auto tmp1 = $$->keyname_;
			if(tmp1){
				tmp1->data_type_=kDataKeyName;
				tmp1->scope_ = 0;
				tmp1->data_flag_ = (DATAFLAG)2; 
			}
		}
   }
  ;


keyname:
	identifier  {
		$$ = new KeyName();
		$$->case_idx_ = CASE0;
		$$->identifier_ = $1;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_=kDataKeyName;
				tmp1->scope_ = 0;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
  ;

value:
	literal {
		$$ = new Value();
		$$->case_idx_ = CASE0;
		$$->literal_ = $1;
	}
   ;

value_list:
	value {
		$$ = new ValueList();
		$$->case_idx_ = CASE0;
		$$->value_ = $1;
	}
   |	value value_list {
	    $$ = new ValueList();
		$$->case_idx_ = CASE0;
		$$->value_ = $1;
		$$->value_list_ = $2;
   }
  ;


key_string_name:
	identifier  {
		$$ = new KeyStringName();
		$$->case_idx_ = CASE0;
		$$->identifier_ = $1;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_=kDataStringName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
  ;	

key_string_list:
	key_string_name {
		$$ = new KeyStringList();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $1;
	}
   | 
    key_string_name key_string_list{
		$$ = new KeyStringList();
		$$->case_idx_ = CASE1;
		$$->key_string_name_ = $1;
		$$->key_string_list_ = $2;
	}
   ;


key_string_value_list:
	key_string_value {
		$$ = new KeyStringValueList();
		$$->case_idx_ = CASE0;
		$$->key_string_value_ = $1;
	}
   |
	key_string_value key_string_value_list {
		$$ = new KeyStringValueList();
		$$->case_idx_ = CASE1;
		$$->key_string_value_ = $1;
		$$->key_string_value_list_ = $2;
	}
   ;

key_string_value:
	key_string_name value {
		$$ = new KeyStringValue();
		$$->case_idx_ = CASE0;
		$$->key_string_name_ = $1;
		$$->value_ = $2;
		if($$){
			auto tmp1 = $$->key_string_name_;
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
   ;

key_hash_name:
	identifier  {
		$$ = new KeyHashName();
		$$->case_idx_ = CASE0;
		$$->identifier_ = $1;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataHashName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
  ;		



field_name:
	identifier {
		$$ = new FieldName();
		$$->case_idx_ = CASE0;
		$$->identifier_ = $1;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_=kDataFieldName;
				tmp1->scope_ = 2
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
   ;

del_field_list:
	field_name {
		$$ = new FieldList();
		$$->case_idx_ = CASE0;
		$$->field_name_ = $1;
		if($$){
			auto tmp1 = $$->field_name_;
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
   |	field_name field_list {
	    $$ = new FieldList();
		$$->case_idx_ = CASE1;
		$$->field_name_ = $1;
		$$->field_list_ = $2;
		if($$){
			auto tmp1 = $$->field_name_;
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
   ;




field_list:
	field_name {
		$$ = new FieldList();
		$$->case_idx_ = CASE0;
		$$->field_name_ = $1;
	}
   |	field_name field_list {
	    $$ = new FieldList();
		$$->case_idx_ = CASE1;
		$$->field_name_ = $1;
		$$->field_list_ = $2;
    }
   ;


field_value:
	field_name value {
		$$ = new FieldValue();
		$$->case_idx_ = CASE0;
		$$->field_name_ = $1;
		$$->value_ = $2;
		if($$){
			auto tmp1 = $$->field_name_;
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
   ;



field_value_list:
		field_value {
		$$ = new FieldValueList();
		$$->case_idx_ = CASE0;
		$$->field_value_ = $1;
	}
   |	field_value field_value_list {
		$$ = new FieldValueList();
		$$->case_idx_ = CASE1;
		$$->field_value_ = $1;
		$$->field_value_list_ = $2;
	}
   ;


key_list_name:
	identifier  {
		$$ = new KeyListName();
		$$->case_idx_ = CASE0;
		$$->identifier_ = $1;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataListName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
  ;		


key_set_name:
	identifier {
		$$ = new KeySetName();
		$$->case_idx_ = CASE0;
		$$->identifier_ = $1;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataSetName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
  ;	


del_key_set_list:
	key_set_name {
		$$ = new KeySetList();
		$$->case_idx_ = CASE0;
		$$->key_set_name_ = $1;
		if($$){
			auto tmp1 = $$->key_set_name_;
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
   | 
    key_set_name del_key_set_list {
		$$ = new KeySetList();
		$$->case_idx_ = CASE1;
		$$->key_set_name_ = $1;
		$$->del_key_set_list_ = $2;
		if($$){
			auto tmp1 = $$->key_set_name_;
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
   ;




key_set_list:
	key_set_name {
		$$ = new KeySetList();
		$$->case_idx_ = CASE0;
		$$->key_set_name_ = $1;
	}
   | 
    key_set_name key_set_list {
		$$ = new KeySetList();
		$$->case_idx_ = CASE1;
		$$->key_set_name_ = $1;
		$$->key_set_list_ = $2;
	}
   ;

smember_name:
	identifier {
		$$ = new SmemberName();
		$$->case_idx_ = CASE0;
		$$->identifier_ = $1;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataSmemberName;
				tmp1->scope_ = 2;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
  ;	


smember_name_list:
	smember_name {
		$$ = new KeySetList();
		$$->case_idx_ = CASE0;
		$$->smember_name_ = $1;
		if($$){
			auto tmp1 = $$->smember_name_;
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
   | 
    smember_name smember_name_list {
		$$ = new KeySetList();
		$$->case_idx_ = CASE1;
		$$->smember_name_ = $1;
		$$->smember_name_list_ = $2;
		if($$){
			auto tmp1 = $$->smember_name_;
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
   ;


key_zset_name:
	identifier {
		$$ = new KeyZsetName();
		$$->case_idx_ = CASE0;
		$$->identifier_ = $1;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataZsetName;
				tmp1->scope_ = 1;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
  ;	

key_zset_list:
	key_zset_name {
		$$ = new KeySetList();
		$$->case_idx_ = CASE0;
		$$->key_zset_name_ = $1;
	}
   | 
    key_zset_name key_zset_list {
		$$ = new KeySetList();
		$$->case_idx_ = CASE1;
		$$->key_zset_name_ = $1;
		$$->key_zset_list_ = $2;
	}
   ;



zmember_name:
	identifier {
		$$ = new ZmemberName();
		$$->case_idx_ = CASE0;
		$$->identifier_ = $1;
		if($$){
			auto tmp1 = $$->identifier_;
			if(tmp1){
				tmp1->data_type_= kDataZmemberName;
				tmp1->scope_ = 2;
				tmp1->data_flag_ = (DATAFLAG)8; 
			}
		}
	}
  ;	

zmember_name_list:
	zmember_name {
		$$ = new ZmemberNameList();
		$$->case_idx_ = CASE0;
		$$->zmember_name_ = $1;
		if($$){
			auto tmp1 = $$->zmember_name_;
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
   |	zmember_name zmember_name_list{
		$$ = new ZmemberNameList();
		$$->case_idx_ = CASE1;
		$$->zmember_name_ = $1;
		$$->zmember_name_list_ = $2;
		if($$){
			auto tmp1 = $$->zmember_name_;
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
   ;

zmember_value:
	value zmember_name {
		$$ = new ZmemberValue();
		$$->case_idx_ = CASE0;
		$$->value_ = $1;
		$$->zmember_name_ = $2;
		if($$){
			auto tmp1 = $$->zmember_name_;
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
   ;


zmember_value_list:
	zmember_value {
		$$ = new MemberValueList();
		$$->case_idx_ = CASE0;
		$$->zmember_value_ = $1;
	}
   | zmember_value zmember_value_list {
	    $$ = new MemberValueList();
		$$->case_idx_ = CASE1;
		$$->zmember_value_ = $1;
		$$->zmember_value_list_ = $2;
   }
   ;


timesecond:
	literal {
		$$ = new TimeSecond();
		$$->case_idx_ = CASE0;
		$$->literal_ = $1;
	}
   ;

timeunix:
	literal {
		$$ = new TimeUnix();
		$$->case_idx_ = CASE0;
		$$->literal_ = $1;
	}
   ;

operandnum :
	int_literal  {
		$$ = new Identifier();
		$$->case_idx_ = CASE0;
		$$->int_literal_ = $1;
	}
  ;


operandnum_list:
	operandnum {
		$$ = new OperandnumList();
		$$->case_idx_ = CASE0;
		$$->operandnum_ = $1;
	}
   |	operandnum operandnum_list {
	    $$ = new OperandnumList();
		$$->case_idx_ = CASE1;
		$$->operandnum_ = $1;
		$$->operandnum_list_ = $2;
    }
   ;


identifier:
	IDENTIFIER  {
		$$ = new Identifier();
		$$->string_val_ = $1;
		free($1);
	}
  ;

literal:
	string_literal  {
		$$ = new Literal();
		$$->case_idx_ = CASE0;
		$$->string_literal_ = $1;

	}
   |	num_literal  {
		$$ = new Literal();
		$$->case_idx_ = CASE2;
		$$->num_literal_ = $1;
		
	}
  ;

string_literal:
	STRINGLITERAL  {
		$$ = new StringLiteral();
		$$->string_val_ = $1;
		free($1);
		
	}
  ;

num_literal:
	int_literal  {
		$$ = new NumLiteral();
		$$->case_idx_ = CASE0;
		$$->int_literal_ = $1;
		
	}
   |	float_literal  {
		$$ = new NumLiteral();
		$$->case_idx_ = CASE1;
		$$->float_literal_ = $1;
		
	}
  ;

int_literal:
	INTLITERAL  {
		$$ = new IntLiteral();
		$$->int_val_ = $1;
		
	}
  ;

float_literal:
	FLOATLITERAL  {
		$$ = new FloatLiteral();
		$$->float_val_ = $1;
		
	}
  ;


%%
