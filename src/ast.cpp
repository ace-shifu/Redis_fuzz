#include "ast.h"
#include "define.h"
#include "../include/utils.h"
#include <cassert>

 
static string s_table_name;



Node* generate_ast_node_by_type(IRTYPE type){
    #define DECLARE_CASE(classname) \
    if (type == k##classname) return new classname();

    ALLCLASS(DECLARE_CASE);
    #undef DECLARE_CASE
    return NULL;
}

NODETYPE get_nodetype_by_string(string s){
    #define DECLARE_CASE(datatypename) \
    if(s == #datatypename) return k##datatypename;

    ALLCLASS(DECLARE_CASE);

    #undef DECLARE_CASE
    return kUnknown;
}

string get_string_by_nodetype(NODETYPE tt){
    #define DECLARE_CASE(datatypename) \
    if(tt == k##datatypename) return string(#datatypename);

    ALLCLASS(DECLARE_CASE);

    #undef DECLARE_CASE
    return string("");
}

string get_string_by_datatype(DATATYPE tt){
    #define DECLARE_CASE(datatypename) \
    if(tt == k##datatypename) return string(#datatypename);

    ALLDATATYPE(DECLARE_CASE);

    #undef DECLARE_CASE
    return string("");
}

DATATYPE get_datatype_by_string(string s){
    #define DECLARE_CASE(datatypename) \
    if(s == #datatypename) return k##datatypename;

    ALLDATATYPE(DECLARE_CASE);

    #undef DECLARE_CASE
    return kDataWhatever;
}

void deep_delete(IR * root){
    if(root->left_) deep_delete(root->left_);
    if(root->right_) deep_delete(root->right_);
    
    if(root->op_) delete root->op_;

    delete root;
}

IR * deep_copy(const IR * root){
    IR * left = NULL, * right = NULL, * copy_res;

    if(root->left_) left = deep_copy(root->left_); // do you have a second version for deep_copy that accept only one argument?                                                  
    if(root->right_) right = deep_copy(root->right_);//no I forget to update here

    copy_res = new IR(root, left, right);

    return copy_res;

}

string IR::to_string(){
    auto res = to_string_core();
    trim_string(res);
    return res;
}

string IR::to_string_core(){
    //cout << get_string_by_nodetype(this->type_) << endl;
    switch(type_){
	case kIntLiteral: return std::to_string(int_val_);
	case kFloatLiteral: return std::to_string(float_val_);
	case kIdentifier: return str_val_;
	case kStringLiteral: return str_val_;

}

    string res;
    
    if( op_!= NULL ){
        //if(op_->prefix_ == NULL)
            ///cout << "FUCK NULL prefix" << endl;
         //cout << "OP_Prex: " << op_->prefix_ << endl;
        res += op_->prefix_ + " ";
    }
     //cout << "OP_1_" << op_ << endl;
    if(left_ != NULL)
        //res += left_->to_string() + " ";
        res += left_->to_string_core() + " ";
    // cout << "OP_2_" << op_ << endl;
    if( op_!= NULL)
        res += op_->middle_ + " ";
     //cout << "OP_3_" << op_ << endl;
    if(right_ != NULL)
        //res += right_->to_string() + " ";
        res += right_->to_string_core() + " ";
     //cout << "OP_4_" << op_ << endl;
    if(op_!= NULL)
        res += op_->suffix_;
    
    //cout << "FUCK" << endl;
    //cout << "RETURN" << endl;
    return res;
}


IR* Node::translate(vector<IR *> &v_ir_collector){
    return NULL;
}
IR*  Program::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

		auto tmp1= SAFETRANSLATE(stmtlist_);
		res = new IR(kProgram, OP3("","",""), tmp1);

	TRANSLATEEND
}

void Program::deep_delete(){
	SAFEDELETE(stmtlist_);
	delete this;
};

void Program::generate(){
	GENERATESTART(1)

		stmtlist_ = new Stmtlist();
		stmtlist_->generate();

	GENERATEEND
}



IR*  Stmtlist::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(stmt_);
		res = new IR(kStmtlist, OP3("","",""), tmp1);
		CASEEND
        CASESTART(1)
		auto tmp1= SAFETRANSLATE(stmt_);
		auto tmp2= SAFETRANSLATE(stmtlist_);
		res = new IR(kStmtlist, OP3("","",""), tmp1, tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void Stmtlist::deep_delete(){
	SAFEDELETE(stmt_);
	SAFEDELETE(stmtlist_);
	delete this;
};

void Stmtlist::generate(){
	GENERATESTART(200)

	SWITCHSTART
		CASESTART(0)
		stmt_ = new Stmt();
		stmt_->generate();
		CASEEND
        CASESTART(1)
		stmt_ = new Stmt();
		stmt_->generate();
		stmtlist_ = new Stmtlist();
		stmtlist_->generate();
		CASEEND
    default:{
        int tmp_case_idx = rand() % 1;
        switch(tmp_case_idx){
        CASESTART(0)
		stmt_ = new Stmt();
		stmt_->generate();
        case_idx_ = 1;
        CASEEND

        }
    }
}
	GENERATEEND
}

IR*  Stmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_stmt_);
		res = new IR(kStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(string_stmt_);
		res = new IR(kStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(2)
		auto tmp1= SAFETRANSLATE(hash_stmt_);
		res = new IR(kStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(3)
		auto tmp1= SAFETRANSLATE(list_stmt_);
		res = new IR(kStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(4)
		auto tmp1= SAFETRANSLATE(set_stmt_);
		res = new IR(kStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(5)
		auto tmp1= SAFETRANSLATE(zset_stmt_);
		res = new IR(kStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(6)
		auto tmp1= SAFETRANSLATE(connect_stmt_);
		res = new IR(kStmt, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void Stmt::deep_delete(){
	SAFEDELETE(key_stmt_);
	SAFEDELETE(string_stmt_);
	SAFEDELETE(hash_stmt_);
	SAFEDELETE(list_stmt_);
	SAFEDELETE(set_stmt_);
	SAFEDELETE(zset_stmt_);
    SAFEDELETE(connect_stmt_);
	delete this;
};

void Stmt::generate(){
	GENERATESTART(7)

	SWITCHSTART
		CASESTART(0)
        key_stmt_ = new KeyStmt();
        key_stmt_->generate();
		CASEEND
		CASESTART(1)
		string_stmt_ = new StringStmt();
        string_stmt_->generate();
		CASEEND
		CASESTART(2)
		hash_stmt_ = new HashStmt();
        hash_stmt_->generate();
		CASEEND
		CASESTART(3)
		list_stmt_ = new ListStmt();
        list_stmt_->generate();
		CASEEND
		CASESTART(4)
		set_stmt_ = new SetStmt();
        set_stmt_->generate();
		CASEEND
		CASESTART(5)
		zset_stmt_ = new ZsetStmt();
        zset_stmt_->generate();
		CASEEND
		CASESTART(6)
		connect_stmt_ = new ConnectStmt();
        connect_stmt_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  KeyStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(del_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(dump_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(2)
		auto tmp1= SAFETRANSLATE(exists_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(3)
		auto tmp1= SAFETRANSLATE(expire_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(4)
		auto tmp1= SAFETRANSLATE(expireat_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(5)
		auto tmp1= SAFETRANSLATE(move_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(6)
		auto tmp1= SAFETRANSLATE(object_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(7)
		auto tmp1= SAFETRANSLATE(persist_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(8)
		auto tmp1= SAFETRANSLATE(pexpire_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(9)
		auto tmp1= SAFETRANSLATE(pexpireat_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(10)
		auto tmp1= SAFETRANSLATE(pttl_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(11)
		auto tmp1= SAFETRANSLATE(randomkey_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(12)
		auto tmp1= SAFETRANSLATE(rename_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(13)
		auto tmp1= SAFETRANSLATE(renamenx_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(14)
		auto tmp1= SAFETRANSLATE(sort_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(15)
		auto tmp1= SAFETRANSLATE(ttl_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(16)
		auto tmp1= SAFETRANSLATE(type_stmt_);
		res = new IR(kKeyStmt, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyStmt::deep_delete(){
	SAFEDELETE(del_stmt_);
	SAFEDELETE(dump_stmt_);
	SAFEDELETE(exists_stmt_);
	SAFEDELETE(expire_stmt_);
	SAFEDELETE(expireat_stmt_);
	SAFEDELETE(move_stmt_);
	SAFEDELETE(object_stmt_);
	SAFEDELETE(persist_stmt_);
	SAFEDELETE(pexpire_stmt_);
	SAFEDELETE(pttl_stmt_);
	SAFEDELETE(randomkey_stmt_);
	SAFEDELETE(rename_stmt_);
	SAFEDELETE(renamenx_stmt_);
	SAFEDELETE(sort_stmt_);
	SAFEDELETE(ttl_stmt_);
	SAFEDELETE(type_stmt_);
	delete this;
};


void KeyStmt::generate(){
	GENERATESTART(17)

	SWITCHSTART
		CASESTART(0)
		del_stmt_ = new DelStmt();
		del_stmt_->generate();
		CASEEND
		CASESTART(1)
		dump_stmt_ = new DumpStmt();
		dump_stmt_->generate();
		CASEEND
		CASESTART(2)
		exists_stmt_ = new ExistsStmt();
		exists_stmt_->generate();
		CASEEND
		CASESTART(3)
		expire_stmt_ = new ExpireStmt();
		expire_stmt_->generate();
		CASEEND
		CASESTART(4)
		expireat_stmt_ = new ExpireatStmt();
		expireat_stmt_->generate();
		CASEEND
		CASESTART(5)
		move_stmt_ = new MoveStmt();
		move_stmt_->generate();
		CASEEND
		CASESTART(6)
		object_stmt_ = new ObjectStmt();
		object_stmt_->generate();
		CASEEND
		CASESTART(7)
		persist_stmt_ = new PersistStmt();
		persist_stmt_->generate();
		CASEEND
		CASESTART(8)
		pexpire_stmt_ = new PexpireStmt();
		pexpire_stmt_->generate();
		CASEEND
		CASESTART(9)
		pexpireat_stmt_ = new PexpireatStmt();
		pexpireat_stmt_->generate();
		CASEEND
		CASESTART(10)
		pttl_stmt_ = new PttlStmt();
		pttl_stmt_->generate();
		CASEEND
		CASESTART(11)
		randomkey_stmt_ = new RandomkeyStmt();
		randomkey_stmt_->generate();
		CASEEND
		CASESTART(12)
		rename_stmt_ = new RenameStmt();
		rename_stmt_->generate();
		CASEEND
		CASESTART(13)
		renamenx_stmt_ = new RenamenxStmt();
		renamenx_stmt_->generate();
		CASEEND
		CASESTART(14)
		sort_stmt_ = new SortStmt();
		sort_stmt_->generate();
		CASEEND
		CASESTART(15)
		ttl_stmt_ = new TtlStmt();
		ttl_stmt_->generate();
		CASEEND
		CASESTART(16)
		type_stmt_ = new =TypeStmt();
		type_stmt_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}



IR*  StringStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(append_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(bicount_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(2)
		auto tmp1= SAFETRANSLATE(setbit_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(3)
		auto tmp1= SAFETRANSLATE(bitop_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(4)
		auto tmp1= SAFETRANSLATE(decr_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(5)
		auto tmp1= SAFETRANSLATE(decrby_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(6)
		auto tmp1= SAFETRANSLATE(get_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(7)
		auto tmp1= SAFETRANSLATE(getbit_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(8)
		auto tmp1= SAFETRANSLATE(getrange_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(9)
		auto tmp1= SAFETRANSLATE(getset_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(10)
		auto tmp1= SAFETRANSLATE(incr_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(11)
		auto tmp1= SAFETRANSLATE(incrby_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(12)
		auto tmp1= SAFETRANSLATE(incrbyfloat_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(13)
		auto tmp1= SAFETRANSLATE(mget_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(14)
		auto tmp1= SAFETRANSLATE(mset_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(15)
		auto tmp1= SAFETRANSLATE(psetex_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(16)
		auto tmp1= SAFETRANSLATE(setkey_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(17)
		auto tmp1= SAFETRANSLATE(setex_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(18)
		auto tmp1= SAFETRANSLATE(setnx_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(19)
		auto tmp1= SAFETRANSLATE(setrange_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(20)
		auto tmp1= SAFETRANSLATE(strlen_stmt_);
		res = new IR(kStringStmt, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void StringStmt::deep_delete(){
	SAFEDELETE(append_stmt_);
	SAFEDELETE(bicount_stmt_);
	SAFEDELETE(setbit_stmt_);
	SAFEDELETE(bitop_stmt_);
	SAFEDELETE(decr_stmt_);
	SAFEDELETE(decrby_stmt_);
	SAFEDELETE(get_stmt_);
	SAFEDELETE(getbit_stmt_);
	SAFEDELETE(getrange_stmt_);
	SAFEDELETE(getset_stmt_);
	SAFEDELETE(incr_stmt_);
	SAFEDELETE(incrby_stmt_);
	SAFEDELETE(incrbyfloat_stmt_);
	SAFEDELETE(mget_stmt_);
	SAFEDELETE(mset_stmt_);
	SAFEDELETE(psetex_stmt_);
	SAFEDELETE(setkey_stmt_);
	SAFEDELETE(setex_stmt_);
	SAFEDELETE(setnx_stmt_);
	SAFEDELETE(setrange_stmt_);	
	SAFEDELETE(strlen_stmt_);	
	delete this;
};


void StringStmt::generate(){
	GENERATESTART(21)

	SWITCHSTART
		CASESTART(0)
		append_stmt_ = new AppendStmt();
		append_stmt_->generate();
		CASEEND
		CASESTART(1)
		bicount_stmt_ = new BicountStmt();
		bicount_stmt_->generate();
		CASEEND
		CASESTART(2)
		exists_stmt_ = new SetbitStmt();
		exists_stmt_->generate();
		CASEEND
		CASESTART(3)
		bitop_stmt_ = new BitopStmt();
		bitop_stmt_->generate();
		CASEEND
		CASESTART(4)
		decr_stmt_ = new DecrStmt();
		decr_stmt_->generate();
		CASEEND
		CASESTART(5)
		decrby_stmt_ = new DecrbyStmt();
		decrby_stmt_->generate();
		CASEEND
		CASESTART(6)
		get_stmt_ = new GetStmt();
		get_stmt_->generate();
		CASEEND
		CASESTART(7)
		getbit_stmt_ = new GetbitStmt();
		getbit_stmt_->generate();
		CASEEND
		CASESTART(8)
		getrange_stmt_ = new GetrangeStmt();
		getrange_stmt_->generate();
		CASEEND
		CASESTART(9)
		getset_stmt_ = new GetStmt();
		getset_stmt_->generate();
		CASEEND
		CASESTART(10)
		incr_stmt_ = new IncrStmt();
		incr_stmt_->generate();
		CASEEND
		CASESTART(11)
		incrby_stmt_ = new IncrbyStmt();
		incrby_stmt_->generate();
		CASEEND
		CASESTART(12)
		incrbyfloat_stmt_ = new IncrbyfloatStmt();
		incrbyfloat_stmt_->generate();
		CASEEND
		CASESTART(13)
		mget_stmt_ = new MgetStmt();
		mget_stmt_->generate();
		CASEEND
		CASESTART(14)
		mset_stmt_ = new MsetStmt();
		mset_stmt_->generate();
		CASEEND
		CASESTART(15)
		psetex_stmt_ = new PsetexStmt();
		psetex_stmt_->generate();
		CASEEND
		CASESTART(16)
		setkey_stmt_ = new SetkeyStmt();
		setkey_stmt_->generate();
		CASEEND
		CASESTART(17)
		setex_stmt_ = new SetexStmt();
		setex_stmt_->generate();
		CASEEND
		CASESTART(18)
		setnx_stmt_ = new SetnxStmt();
		setnx_stmt_->generate();
		CASEEND
		CASESTART(19)
		setrange_stmt_ = new SetrangeStmt();
		setrange_stmt_->generate();
		CASEEND
		CASESTART(20)
		strlen_stmt_ = new StrlenStmt();
		strlen_stmt_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}



IR*  HashStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(hdel_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(hexists_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(2)
		auto tmp1= SAFETRANSLATE(hget_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(3)
		auto tmp1= SAFETRANSLATE(hgetall_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(4)
		auto tmp1= SAFETRANSLATE(hincrby_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(5)
		auto tmp1= SAFETRANSLATE(hincrbyfloat_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(6)
		auto tmp1= SAFETRANSLATE(hkeys_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(7)
		auto tmp1= SAFETRANSLATE(hlen_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(8)
		auto tmp1= SAFETRANSLATE(hmget_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(9)
		auto tmp1= SAFETRANSLATE(hmset_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(10)
		auto tmp1= SAFETRANSLATE(hset_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(11)
		auto tmp1= SAFETRANSLATE(hsetnx_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(12)
		auto tmp1= SAFETRANSLATE(hvals_stmt_);
		res = new IR(kHashStmt, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HashStmt::deep_delete(){
	SAFEDELETE(hdel_stmt_);
	SAFEDELETE(hexists_stmt_);
	SAFEDELETE(hget_stmt_);
	SAFEDELETE(hgetall_stmt_);
	SAFEDELETE(hincrby_stmt_);
	SAFEDELETE(hincrbyfloat_stmt_);
	SAFEDELETE(hkeys_stmt_);
	SAFEDELETE(hlen_stmt_);
	SAFEDELETE(hmget_stmt_);
	SAFEDELETE(hmset_stmt_);
	SAFEDELETE(hset_stmt_);
	SAFEDELETE(hsetnx_stmt_);
	SAFEDELETE(hvals_stmt_);
	delete this;
};


void HashStmt::generate(){
	GENERATESTART(13)

	SWITCHSTART
		CASESTART(0)
		hdel_stmt_ = new HdelStmt();
		hdel_stmt_->generate();
		CASEEND
		CASESTART(1)
		hexists_stmt_ = new HexistsStmt();
		hexists_stmt_->generate();
		CASEEND
		CASESTART(2)
		hget_stmt_ = new HgetStmt();
		hget_stmt_->generate();
		CASEEND
		CASESTART(3)
		hgetall_stmt_ = new HgetallStmt();
		hgetall_stmt_->generate();
		CASEEND
		CASESTART(4)
		hincrby_stmt_ = new HincrbyStmt();
		hincrby_stmt_->generate();
		CASEEND
		CASESTART(5)
		hincrbyfloat_stmt_ = new HincrbyfloatStmt();
		hincrbyfloat_stmt_->generate();
		CASEEND
		CASESTART(6)
		hkeys_stmt_ = new HkeysStmt();
		hkeys_stmt_->generate();
		CASEEND
		CASESTART(7)
		hlen_stmt_ = new HlenStmt();
		hlen_stmt_->generate();
		CASEEND
		CASESTART(8)
		hmget_stmt_ = new HmgetStmt();
		hmget_stmt_->generate();
		CASEEND
		CASESTART(9)
		hmset_stmt_ = new HmsetStmt();
		hmset_stmt_->generate();
		CASEEND
		CASESTART(10)
		hset_stmt_ = new HsetStmt();
		hset_stmt__->generate();
		CASEEND
		CASESTART(11)
		hsetnx_stmt_ = new HsetnxStmt();
		hsetnx_stmt_->generate();
		CASEEND
		CASESTART(12)
		hvals_stmt_ = new HvalsStmt();
		hvals_stmt_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  ListStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(lindex_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(linsert_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(2)
		auto tmp1= SAFETRANSLATE(llen_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(3)
		auto tmp1= SAFETRANSLATE(lpop_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(4)
		auto tmp1= SAFETRANSLATE(lpush_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(5)
		auto tmp1= SAFETRANSLATE(lpushx_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(6)
		auto tmp1= SAFETRANSLATE(lrange_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(7)
		auto tmp1= SAFETRANSLATE(lrem_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(8)
		auto tmp1= SAFETRANSLATE(lset_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(9)
		auto tmp1= SAFETRANSLATE(ltrim_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(10)
		auto tmp1= SAFETRANSLATE(rpop_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(11)
		auto tmp1= SAFETRANSLATE(rpoplpush_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(12)
		auto tmp1= SAFETRANSLATE(rpush_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(13)
		auto tmp1= SAFETRANSLATE(rpushx_stmt_);
		res = new IR(kListStmt, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HashStmt::deep_delete(){
	SAFEDELETE(hdel_stmt_);
	SAFEDELETE(hexists_stmt_);
	SAFEDELETE(hget_stmt_);
	SAFEDELETE(hgetall_stmt_);
	SAFEDELETE(hincrby_stmt_);
	SAFEDELETE(hincrbyfloat_stmt_);
	SAFEDELETE(hkeys_stmt_);
	SAFEDELETE(hlen_stmt_);
	SAFEDELETE(hmget_stmt_);
	SAFEDELETE(hmset_stmt_);
	SAFEDELETE(hset_stmt_);
	SAFEDELETE(hsetnx_stmt_);
	SAFEDELETE(hvals_stmt_);
	delete this;
};


void HashStmt::generate(){
	GENERATESTART(13)

	SWITCHSTART
		CASESTART(0)
		hdel_stmt_ = new HdelStmt();
		hdel_stmt_->generate();
		CASEEND
		CASESTART(1)
		hexists_stmt_ = new HexistsStmt();
		hexists_stmt_->generate();
		CASEEND
		CASESTART(2)
		hget_stmt_ = new HgetStmt();
		hget_stmt_->generate();
		CASEEND
		CASESTART(3)
		hgetall_stmt_ = new HgetallStmt();
		hgetall_stmt_->generate();
		CASEEND
		CASESTART(4)
		hincrby_stmt_ = new HincrbyStmt();
		hincrby_stmt_->generate();
		CASEEND
		CASESTART(5)
		hincrbyfloat_stmt_ = new HincrbyfloatStmt();
		hincrbyfloat_stmt_->generate();
		CASEEND
		CASESTART(6)
		hkeys_stmt_ = new HkeysStmt();
		hkeys_stmt_->generate();
		CASEEND
		CASESTART(7)
		hlen_stmt_ = new HlenStmt();
		hlen_stmt_->generate();
		CASEEND
		CASESTART(8)
		hmget_stmt_ = new HmgetStmt();
		hmget_stmt_->generate();
		CASEEND
		CASESTART(9)
		hmset_stmt_ = new HmsetStmt();
		hmset_stmt_->generate();
		CASEEND
		CASESTART(10)
		hset_stmt_ = new HsetStmt();
		hset_stmt_->generate();
		CASEEND
		CASESTART(11)
		hsetnx_stmt_ = new HsetnxStmt();
		hsetnx_stmt_->generate();
		CASEEND
		CASESTART(12)
		hvals_stmt_ = new HvalsStmt();
		hvals_stmt_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  SetStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(sadd_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(scard_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(2)
		auto tmp1= SAFETRANSLATE(sdiff_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(3)
		auto tmp1= SAFETRANSLATE(sdiffstore_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(4)
		auto tmp1= SAFETRANSLATE(sinter_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(5)
		auto tmp1= SAFETRANSLATE(sinterstore_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(6)
		auto tmp1= SAFETRANSLATE(sismember_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(7)
		auto tmp1= SAFETRANSLATE(smember_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(8)
		auto tmp1= SAFETRANSLATE(smove_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(9)
		auto tmp1= SAFETRANSLATE(spop_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(10)
		auto tmp1= SAFETRANSLATE(srandmember_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(11)
		auto tmp1= SAFETRANSLATE(srem_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(12)
		auto tmp1= SAFETRANSLATE(sunion_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(13)
		auto tmp1= SAFETRANSLATE(sunionstore_stmt_);
		res = new IR(kSetStmt, OP3("","",""), tmp1);

		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SetStmt::deep_delete(){
	SAFEDELETE(sadd_stmt_);
	SAFEDELETE(scard_stmt_);
	SAFEDELETE(sdiff_stmt_);
	SAFEDELETE(sdiffstore_stmt_);
	SAFEDELETE(sinter_stmt_);
	SAFEDELETE(sinterstore_stmt_);
	SAFEDELETE(sismember_stmt_);
	SAFEDELETE(smember_stmt_);
	SAFEDELETE(smove_stmt_);
	SAFEDELETE(spop_stmt_);
	SAFEDELETE(srandmember_stmt_);
	SAFEDELETE(srem_stmt_);
	SAFEDELETE(sunion_stmt_);
	SAFEDELETE(sunionstore_stmt_);
	delete this;
};


void SetStmt::generate(){
	GENERATESTART(14)

	SWITCHSTART
		CASESTART(0)
		sadd_stmt_ = new SaddStmt();
		sadd_stmt_->generate();
		CASEEND
		CASESTART(1)
		scard_stmt_ = new ScardStmt();
		scard_stmt_->generate();
		CASEEND
		CASESTART(2)
		sdiff_stmt_ = new SdiffStmt();
		sdiff_stmt_->generate();
		CASEEND
		CASESTART(3)
		sdiffstore_stmt_ = new SdiffstoreStmt();
		sdiffstore_stmt_->generate();
		CASEEND
		CASESTART(4)
		sinter_stmt_ = new SinterStmt();
		sinter_stmt_->generate();
		CASEEND
		CASESTART(5)
		sinterstore_stmt_ = new SinterstoreStmt();
		sinterstore_stmt_->generate();
		CASEEND
		CASESTART(6)
		sismember_stmt_ = new SismemberStmt();
		sismember_stmt_->generate();
		CASEEND
		CASESTART(7)
		smember_stmt_ = new SmemberStmt();
		smember_stmt_->generate();
		CASEEND
		CASESTART(8)
		smove_stmt_ = new SmoveStmt();
		smove_stmt_->generate();
		CASEEND
		CASESTART(9)
		spop_stmt_ = new SpopStmt();
		spop_stmt_->generate();
		CASEEND
		CASESTART(10)
		srandmember_stmt_ = new SrandmemberStmt();
		srandmember_stmt_->generate();
		CASEEND
		CASESTART(11)
		hsetnx_stmt_ = new SremStmt();
		hsetnx_stmt_->generate();
		CASEEND
		CASESTART(12)
		sunion_stmt_ = new SunionStmt();
		sunion_stmt_->generate();
		CASEEND
		CASESTART(13)
		sunionstore_stmt_ = new SunionstoreStmt();
		sunionstore_stmt_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ZsetStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(zadd_stmt_);
		res = new IR(kZsetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(zcard_stmt_);
		res = new IR(kZsetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(2)
		auto tmp1= SAFETRANSLATE(zcount_stmt_);
		res = new IR(kZsetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(3)
		auto tmp1= SAFETRANSLATE(zincrby_stmt_);
		res = new IR(kZsetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(4)
		auto tmp1= SAFETRANSLATE(zrange_stmt_);
		res = new IR(kZsetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(5)
		auto tmp1= SAFETRANSLATE(zrangebyscore_stmt_);
		res = new IR(kZsetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(6)
		auto tmp1= SAFETRANSLATE(zrank_stmt_);
		res = new IR(kZsetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(7)
		auto tmp1= SAFETRANSLATE(zrem_stmt_);
		res = new IR(kZsetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(8)
		auto tmp1= SAFETRANSLATE(zscore_stmt_);
		res = new IR(kZsetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(9)
		auto tmp1= SAFETRANSLATE(zunionstore_stmt_);
		res = new IR(kZsetStmt, OP3("","",""), tmp1);
		CASEEND
		CASESTART(10)
		auto tmp1= SAFETRANSLATE(zinterstore_stmt_);
		res = new IR(kZsetStmt, OP3("","",""), tmp1);
		CASEEND

		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZsetStmt::deep_delete(){
	SAFEDELETE(zadd_stmt_);
	SAFEDELETE(zcard_stmt_);
	SAFEDELETE(zcount_stmt_);
	SAFEDELETE(zincrby_stmt_);
	SAFEDELETE(zrange_stmt_);
	SAFEDELETE(zrangebyscore_stmt_);
	SAFEDELETE(zrank_stmt_);
	SAFEDELETE(zrem_stmt_);
	SAFEDELETE(zscore_stmt_);
	SAFEDELETE(zunionstore_stmt_);
	SAFEDELETE(zinterstore_stmt_);
	delete this;
};


void ZsetStmt::generate(){
	GENERATESTART(11)

	SWITCHSTART
		CASESTART(0)
		sadd_stmt_ = new ZaddStmt();
		sadd_stmt_->generate();
		CASEEND
		CASESTART(1)
		scard_stmt_ = new ZcardStmt();
		scard_stmt_->generate();
		CASEEND
		CASESTART(2)
		sdiff_stmt_ = new ZcountStmt();
		sdiff_stmt_->generate();
		CASEEND
		CASESTART(3)
		sdiffstore_stmt_ = new ZincrbyStmt();
		sdiffstore_stmt_->generate();
		CASEEND
		CASESTART(4)
		sinter_stmt_ = new ZrangeStmt();
		sinter_stmt_->generate();
		CASEEND
		CASESTART(5)
		sinterstore_stmt_ = new ZrangebyscoreStmt();
		sinterstore_stmt_->generate();
		CASEEND
		CASESTART(6)
		sismember_stmt_ = new ZrankStmt();
		sismember_stmt_->generate();
		CASEEND
		CASESTART(7)
		smember_stmt_ = new ZremStmt();
		smember_stmt_->generate();
		CASEEND
		CASESTART(8)
		smember_stmt_ = new ZscoreStmt();
		smember_stmt_->generate();
		CASEEND
		CASESTART(9)
		smove_stmt_ = new ZunionstoreStmt();
		smove_stmt_->generate();
		CASEEND
		CASESTART(10)
		spop_stmt_ = new ZinterstoreStmt();
		spop_stmt_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  ConnectStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(select_stmt_);
		res = new IR(kConnectStmt, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ConnectStmt::deep_delete(){
	SAFEDELETE(select_stmt_);
	delete this;
};

void ConnectStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		select_stmt_ = new SelectStmt();
		select_stmt_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  DelStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_list_);
		res = new IR(kDelStmt, OP3("DEL","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void DelStmt::deep_delete(){
	SAFEDELETE(key_list_);
	delete this;
};

void DelStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_list_ = new KeyList();
		key_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  DumpStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		res = new IR(kDumpStmt, OP3("DUMP","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void DumpStmt::deep_delete(){
	SAFEDELETE(keyname_);
	delete this;
};

void DumpStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ExistsStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		res = new IR(kExistsStmt, OP3("EXISTS","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ExistsStmt::deep_delete(){
	SAFEDELETE(keyname_);
	delete this;
};

void ExistsStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ExpireStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(keyname_);
		auto tmp2 = SAFETRANSLATE(timesecond_);
		res = new IR(kExpireStmt, OP3("EXPIRE","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ExpireStmt::deep_delete(){
	SAFEDELETE(keyname_);
	SAFEDELETE(timesecond_);
	delete this;
};

void ExpireStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		timesecond_ = new TimeSecond();
		timesecond_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  TimeSecond::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(literal_);
		res = new IR(kTimeSecond, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void TimeSecond::deep_delete(){
	SAFEDELETE(literal_);
	delete this;
};

void TimeSecond::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		literal_ = new Literal();
		literal_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ExpireatStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(keyname_);
		auto tmp2 = SAFETRANSLATE(timeunix_);
		res = new IR(kExpireatStmt, OP3("EXPIREAT","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ExpireatStmt::deep_delete(){
	SAFEDELETE(keyname_);
	SAFEDELETE(timeunix_);
	delete this;
};

void ExpireatStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		timeunix_ = new TimeUnix();
		timeunix_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  MoveStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(keyname_);
		auto tmp2 = SAFETRANSLATE(operandnum_);
		res = new IR(kMoveStmt, OP3("MOVE","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void MoveStmt::deep_delete(){
	SAFEDELETE(keyname_);
	SAFEDELETE(operandnum_);
	delete this;
};

void MoveStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		operandnum_ = new Operandnum();
		operandnum_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  TimeUnix::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(literal_);
		res = new IR(kTimeUnix, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void TimeUnix::deep_delete(){
	SAFEDELETE(literal_);
	delete this;
};

void TimeUnix::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		literal_ = new Literal();
		literal_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ObjectStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(objoption_);
		auto tmp2 = SAFETRANSLATE(keyname_);
		res = new IR(kObjectStmt, OP3("OBJECT","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ObjectStmt::deep_delete(){
	SAFEDELETE(objoption_);
	SAFEDELETE(keyname_);
	delete this;
};

void ObjectStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		objoption_ = new Objoption();
		objoption_->generate();
		keyname_ = new KeyName();
		keyname_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  Objoption::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		res = new IR(kObjoption, OP3("REFCOUNT","",""));
		CASEEND
		CASESTART(1)
		res = new IR(kObjoption, OP3("ENCODING","",""));
		CASEEND
		CASESTART(2)
		res = new IR(kObjoption, OP3("IDLETIME","",""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void Objoption::deep_delete(){
	delete this;
};

void Objoption::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		CASEEND
		CASESTART(1)
		CASEEND
		CASESTART(2)
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR* PersistStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		res = new IR(kPersistStmt, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void PersistStmt::deep_delete(){
	SAFEDELETE(keyname_);
	delete this;
};

void PersistStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  PexpireStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		auto tmp2= SAFETRANSLATE(timesecond_);
		res = new IR(kPexpireStmt, OP3("PEXPIRE","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void PexpireStmt::deep_delete(){
	SAFEDELETE(keyname_);
	SAFEDELETE(timesecond_);
	delete this;
};

void PexpireStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		timesecond_ = new TimeSecond();
		timesecond_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  PexpireatStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		auto tmp2= SAFETRANSLATE(timesecond_);
		res = new IR(kPexpireatStmt, OP3("PEXPIREAT","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void PexpireatStmt::deep_delete(){
	SAFEDELETE(keyname_);
	SAFEDELETE(timesecond_);
	delete this;
};

void PexpireatStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		timesecond_ = new TimeSecond();
		timesecond_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  PttlStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		res = new IR(kPttlStmt, OP3("PTTL","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void PttlStmt::deep_delete(){
	SAFEDELETE(keyname_);
	delete this;
};

void PttlStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  RandomkeyStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		res = new IR(kRandomkeyStmt, OP3("RANDOMKEY","",""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void RandomkeyStmt::deep_delete(){
	delete this;
};

void RandomkeyStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  RenameStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		auto tmp2= SAFETRANSLATE(aliasname_);
		res = new IR(kRenameStmt, OP3("RENAME","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void RenameStmt::deep_delete(){
	SAFEDELETE(keyname_);
	SAFEDELETE(aliasname_);
	delete this;
};

void RenameStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		aliasname_ = new AliasName();
		aliasname_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  AliasName::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(identifier_);
		res = new IR(kAliasName, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void AliasName::deep_delete(){
	SAFEDELETE(identifier_);
	delete this;
};

void AliasName::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		identifier_ = new Identifier();
		identifier_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  RenamenxStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		auto tmp2= SAFETRANSLATE(aliasname_);
		res = new IR(kRenamenxStmt, OP3("RENAMENX","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void RenamenxStmt::deep_delete(){
	SAFEDELETE(keyname_);
	SAFEDELETE(aliasname_);
	delete this;
};

void RenamenxStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		aliasname_ = new AliasName();
		aliasname_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SortStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(sort_clause_);
		auto tmp2= SAFETRANSLATE(opt_by_clause_);
		auto tmp3= SAFETRANSLATE(opt_limit_clause_);
		auto tmp4= SAFETRANSLATE(opt_sort_behavior_);
		auto tmp5= SAFETRANSLATE(opt_store_clause_);
		auto tmp6= new IR(kUnknown, OP3("SORT","",""),tmp1,tmp2);
		PUSH(tmp6);
		auto tmp7= new IR(kUnknown, OP3("","",""), tmp6,tmp3);
		PUSH(tmp7);
		auto tmp8= new IR(kUnknown, OP3("","",""), tmp7,tmp4);
		PUSH(tmp8);
		res = new IR(kSORT, OP3("","",""), tmp8,tmp5);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SortStmt::deep_delete(){
	SAFEDELETE(sort_clause_);
	SAFEDELETE(opt_by_clause_);
	SAFEDELETE(opt_limit_clause_);
	SAFEDELETE(opt_store_clause_);
	delete this;
};

void SortStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		sort_clause_ = new SortClause();
		sort_clause_->generate();
		opt_by_clause_ = new OptByClause();
		opt_by_clause_->generate();
		opt_limit_clause_ = new OptLimitClause();
		opt_limit_clause_->generate();
		opt_store_clause_ = new OptStoreClause();
		opt_store_clause_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SortClause::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		res = new IR(kSortClause, OP3("","",""), tmp1);
		CASEEND

	SWITCHEND

	TRANSLATEEND
}

void SortClause::deep_delete(){
	SAFEDELETE(keyname_);
	delete this;
};

void SortClause::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}
IR*  OptByClause::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		res = new IR(kOptByClause, OP3("BY","",""), tmp1);
		CASEEND
		CASESTART(1)
		res = new IR(kOptByClause, string(""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void OptByClause::deep_delete(){
	SAFEDELETE(keyname_);
	delete this;
};

void OptByClause::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		CASEEND
		CASESTART(1)
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  OptLimitClause::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(operandnum1_);
		auto tmp2= SAFETRANSLATE(operandnum2_);
		res = new IR(kOptLimitClause, OP3("LIMIT","",""), tmp1,tmp2);
		CASEEND
		CASESTART(0)
		res = new IR(kOptLimitClause, string(""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void OptLimitClause::deep_delete(){
	SAFEDELETE(operandnum1_);
	SAFEDELETE(operandnum2_);
	delete this;
};

void OptLimitClause::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		operandnum1_ = new Operandnum();
		operandnum1_->generate();
		operandnum2_ = new Operandnum();
		operandnum2_->generate();
		CASEEND
		CASESTART(1)
		CASEEND
	SWITCHEND

	GENERATEEND
}



IR*  OperandnumList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(operandnum_);
		res = new IR(kOperandnumList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(operandnum_);
		auto tmp2= SAFETRANSLATE(operandnum_list_);
		res = new IR(kOperandnumList, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void OperandnumList::deep_delete(){
	SAFEDELETE(operandnum_);
	SAFEDELETE(operandnum_list_);
	delete this;
};

void OperandnumList::generate(){
	GENERATESTART(2)

	SWITCHSTART
		CASESTART(0)
		operandnum_ = new Operandnum();
		operandnum_->generate();
		CASEEND
		CASESTART(1)
		operandnum_ = new Operandnum();
		operandnum_->generate();
		operandmum_list_ = new Operandnum();
		operandmum_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  OptStoreClause::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		res = new IR(kOptStoreClause, OP3("STORE","",""), tmp1);
		CASEEND
		CASESTART(1)
		res = new IR(kOptStoreClause, string(""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void OptStoreClause::deep_delete(){
	SAFEDELETE(keyname_);
	delete this;
};

void OptStoreClause::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		CASEEND
		CASESTART(1)
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  OptSortBehavior::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		res = new IR(kOptSortBehavior, OP3("ASC","",""));
		CASEEND
		CASESTART(1)
		res = new IR(kOptSortBehavior, OP3("DESC","",""));
		CASEEND
		CASESTART(2)
		res = new IR(kOptSortBehavior, OP3("ALPHA","",""));
		CASEEND
		CASESTART(3)
		res = new IR(kOptSortBehavior, string(""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void OptSortBehavior::deep_delete(){
	delete this;
};

void OptSortBehavior::generate(){
	GENERATESTART(4)

	SWITCHSTART
		CASESTART(0)
		CASEEND
		CASESTART(1)
		CASEEND
		CASESTART(2)
		CASEEND
		CASESTART(3)
		CASEEND
	SWITCHEND

	GENERATEEND
}




IR*  TtlStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		res = new IR(kTtlStmt, OP3("TTL","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void TtlStmt::deep_delete(){
	SAFEDELETE(keyname_);
	delete this;
};

void TtlStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  TypeStmt:translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		res = new IR(kTypeStmt, OP3("TYPE","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void TypeStmt::deep_delete(){
	SAFEDELETE(keyname_);
	delete this;
};

void TypeStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}
/*String部分*/
IR*  AppendStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(value_)
		res = new IR(kAppendStmt, OP3("APPEND","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void AppendStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(value_;
	delete this;
};

void AppendStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  BicountStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		res = new IR(kBicountStmt, OP3("BITCOUNT","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void BicountStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	delete this;
};

void BicountStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  SetbitStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(operandnum_);
		auto tmp3= SAFETRANSLATE(value_);
		auto tmp4= new IR(kUnknown,OP3("SETBIT","","") tmp1,tmp2);
		res = new IR(kSetbitStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SetbitStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(operandnum_);	
	SAFEDELETE(value_);
	delete this;
};

void SetbitStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		operandnum_ = new Operandnum();
		operandnum_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  BitopStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(operation_);
		auto tmp2= SAFETRANSLATE(key_string_list_);
		res = new IR(kBitopStmt, OP3("BITOP","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void BitopStmt::deep_delete(){
	SAFEDELETE(operation_);
	SAFEDELETE(key_string_list_);
	delete this;
};

void BitopStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		operation_ = new Operation();
		operation_->generate();
		key_string_list_ = new KeyList();
		key_string_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  DecrStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		res = new IR(kDecrStmt, OP3("DECR","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void DecrStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	delete this;
};

void DecrStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  DecrbyStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(num_literal_);
		res = new IR(kDecrbyStmt, OP3("DECRBY","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void DecrbyStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(num_literal_);
	delete this;
};

void DecrbyStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		num_literal_ = new NumLiteral();
		num_literal_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  GetStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		res = new IR(kGetStmt, OP3("GET","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void GetStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	delete this;
};

void GetStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  GetbitStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(key_string_name_);
		auto tmp2 = SAFETRANSLATE(operandnum_);
		res = new IR(kGetbitStmt, OP3("GETBIT","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void GetbitStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(operandnum_);
	delete this;
};

void GetbitStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		operandnum_ = new Operandnum();
		operandnum_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  GetrangeStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(operandnum1_);
		auto tmp3= SAFETRANSLATE(operandnum2_);
		auto tmp4= new IR(kUnknown, OP3("GETRANGE","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kGetrangeStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void GetrangeStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(operandnum1_);
	SAFEDELETE(operandnum1_);
	delete this;
};

void GetrangeStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		operandnum1_ = new Operandnum();
		Operandnum1_->generate();
		operandnum2_ = new Operandnum();
		Operandnum2_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  GetsetStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(value_);
		res = new IR(kGetsetStmt, OP3("GETSET","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void GetsetStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(value_);
	delete this;
};

void GetsetStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  IncrStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		res = new IR(kIncrStmt, OP3("INCR","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void IncrStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	delete this;
};

void IncrStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  IncrbyStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(num_literal_);
		res = new IR(kIncrbyStmt, OP3("INCRBY","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void IncrbyStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(num_literal_);
	delete this;
};

void IncrbyStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new SelectStmt();
		key_string_name_->generate();
		num_literal_ = new NumLiteral();
		num_literal_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  IncrbyfloatStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(float_literal_);
		res = new IR(kIncrbyfloatStmt, OP3("INCRBYFLOAT","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void IncrbyfloatStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(float_literal_);
	delete this;
};

void IncrbyfloatStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		float_literal_ = new FloatLiteral();
		float_literal_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  MgetStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_list_);
		res = new IR(kMgetStmt, OP3("MGET","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void MgetStmt::deep_delete(){
	SAFEDELETE(key_string_list_);
	delete this;
};

void MgetStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_list_ = new KeyStringList();
		key_string_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  MsetStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_value_list_);
		res = new IR(kMsetStmt, OP3("MSET","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void MsetStmt::deep_delete(){
	SAFEDELETE(key_string_value_list_);
	delete this;
};

void MsetStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_value_list_ = new KeyStringValueList();
		key_string_value_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  PsetexStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(timesecond_);
		auto tmp3= SAFETRANSLATE(value_);
		auto tmp4= new IR(kUnknown,OP3("PSETEX","",""),tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kPsetexStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void PsetexStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(timesecond_);
	SAFEDELETE(value_);
	delete this;
};

void PsetexStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		timesecond_ = new TimeSecond();
		timesecond_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SetkeyStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(setkey_clause_);
		auto tmp2= SAFETRANSLATE(opt_expiretime_clause_);
		auto tmp3= SAFETRANSLATE(opt_setkey_behavior_);
		auto tmp4= new IR(kUnknown, OP3("SET","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kSetkeyStmt,OP3("","",""), tmp4,tmp3)
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SetkeyStmt::deep_delete(){
	SAFEDELETE(setkey_clause_);
	SAFEDELETE(opt_expiretime_clause_);
	SAFEDELETE(opt_setkey_behavior_);
	delete this;
};

void SetkeyStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		setkey_clause_ = new SetkeyClause();
		setkey_clause_->generate();
		opt_expiretime_clause_ = new OptExpireTimeClause();
		opt_expiretime_clause_->generate();
		opt_setkey_behavior_ = new OptSetkeyBehavior();
		opt_setkey_behavior_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SetkeyClause::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(value_);
		res = new IR(kSetkeyClause, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SetkeyClause::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(value_);
	delete this;
};

void SetkeyClause::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  OptExpireTimeClause::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(timesecond_);
		res = new IR(kOptExpireTimeClause, OP3("EX","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(timesecond_);
		res = new IR(kOptExpireTimeClause, OP3("PX","",""), tmp1);
		CASEEND
		CASESTART(2)
		res = new IR(kOptExpireTimeClause, string(""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void OptExpireTimeClause::deep_delete(){
	SAFEDELETE(timesecond_);
	delete this;
};

void OptExpireTimeClause::generate(){
	GENERATESTART(3)

	SWITCHSTART
		CASESTART(0)
		timesecond_ = new TimeSecond();
		timesecond_->generate();
		CASEEND
		CASESTART(1)
		CASEEND
		CASESTART(2)
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  OptSetkeyBehavior::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		res = new IR(kOptSetkeyBehavior,OP3("NX","",""));
		CASEEND
		CASESTART(1)
		res = new IR(kOptSetkeyBehavior, OP3("XX","",""));
		CASEEND
		CASESTART(2)
		res = new IR(kOptSetkeyBehavior, string(""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void OptSetkeyBehavior::deep_delete(){
	delete this;
};

void OptSetkeyBehavior::generate(){
	GENERATESTART(3)

	SWITCHSTART
		CASESTART(0)
		CASEEND
		CASESTART(1)
		CASEEND
		CASESTART(2)
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SetexStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(timesecond_);
		auto tmp3= SAFETRANSLATE(value_);
		auto tmp4= new IR(kUnknown,OP3("SETEX","",""),tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kSetexStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SetexStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(timesecond_);
	SAFEDELETE(value_);
	delete this;
};

void SetexStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		timesecond_ = new TimeSecond();
		timesecond_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SetnxStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(value_);
		res = new IR(kSetnxStmt, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SetnxStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(value_);
	delete this;
};

void SetnxStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SetrangeStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(operandnum_);
		auto tmp3= SAFETRANSLATE(value_);
		auto tmp4= new IR(kUnknown, OP3("SETRANGE","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kSetrangeStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SetrangeStmt::deep_delete(){
	SAFEDELETE(select_stmt_);
	SAFEDELETE(operandnum_);
	SAFEDELETE(value_);
	delete this;
};

void SetrangeStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		operandnum_ = new Operandnum();
		Operandnum_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  StrlenStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		res = new IR(kStrlenStmt, OP3("STRLEN","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void StrlenStmt::deep_delete(){
	SAFEDELETE(key_string_name_);
	delete this;
};

void StrlenStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


/*Hash部分*/

IR*  HdelStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		auto tmp2= SAFETRANSLATE(del_field_list_);
		res = new IR(kHdelStmt, OP3("HDEL","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HdelStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	SAFEDELETE(del_field_list_)
	delete this;
};

void HdelStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		del_field_list_ = new DelFieldList();
		del_field_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HexistsStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(key_hash_name_);
		auto tmp2 = SAFETRANSLATE(field_name_)
		res = new IR(kHexistsStmt, OP3("HEXISTS","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HexistsStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	SAFEDELETE(field_name_);
	delete this;
};

void HexistsStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		field_name_ = new FieldName();
		field_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HgetStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		auto tmp2= SAFETRANSLATE(field_name_);
		res = new IR(kHgetStmt, OP3("HGET","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HgetStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	SAFEDELETE(field_name_);
	delete this;
};

void HgetStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		field_name_ = new FieldName();
		field_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HgetallStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		res = new IR(kHgetallStmt, OP3("HGETALL","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HgetallStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	delete this;
};

void HgetallStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HincrbyStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		auto tmp2= SAFETRANSLATE(field_name_);
		auto tmp3= SAFETRANSLATE(num_literal_);
		auto tmp4 = new IR(kUnknown, OP3("HINCRBY","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kHincrbyStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HincrbyStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	SAFEDELETE(field_name_);
	SAFEDELETE(num_literal_);
	delete this;
};

void HincrbyStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		field_name_ = new FieldName();
		field_name_->generate();
		num_literal_ = new NumLiteral();
		num_literal_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HincrbyfloatStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		auto tmp2= SAFETRANSLATE(field_name_);
		auto tmp3= SAFETRANSLATE(float_literal_);
		auto tmp4 = new IR(kUnknown, OP3("HINCRBYFLOAT","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kHincrbyfloatStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HincrbyfloatStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	SAFEDELETE(field_name_);
	SAFEDELETE(float_literal_);
	delete this;
};

void HincrbyfloatStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		field_name_ = new FieldName();
		field_name_->generate();
		float_literal_ = new FloatLiteral();
		float_literal_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HkeysStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		res = new IR(kHkeysStmt, OP3("HKEYS","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HkeysStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	delete this;
};

void HkeysStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HlenStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		res = new IR(kHlenStmt, OP3("HLEN","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HlenStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	delete this;
};

void HlenStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HmgetStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		auto tmp2= SAFETRANSLATE(field_list_);
		res = new IR(kHmgetStmt, OP3("HMGET","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HmgetStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	SAFEDELETE(field_list_)
	delete this;
};

void HmgetStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		field_list_ = new FieldList();
		field_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HmsetStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		auto tmp2= SAFETRANSLATE(field_value_list_);
		res = new IR(kHmsetStmt, OP3("HMSET","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HmsetStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	SAFEDELETE(field_value_list_);
	delete this;
};

void HmsetStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		field_value_list_ = new FieldValueList();
		field_value_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HsetStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		auto tmp2= SAFETRANSLATE(field_value_);
		res = new IR(kHsetStmt, OP3("HSET","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HsetStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	SAFEDELETE(field_value_);
	delete this;
};

void HsetStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		field_value_ = new FieldValue();
		field_value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HsetnxStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		auto tmp2= SAFETRANSLATE(field_value_);
		res = new IR(kHsetnxStmt, OP3("HSETNX","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HsetnxStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	SAFEDELETE(field_value_);
	delete this;
};

void HsetnxStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		field_value_ = new FieldValue();
		field_value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  HvalsStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_hash_name_);
		res = new IR(kHvalsStmt, OP3("HVALS","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void HvalsStmt::deep_delete(){
	SAFEDELETE(key_hash_name_);
	delete this;
};

void HvalsStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_hash_name_ = new KeyHashName();
		key_hash_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


/*List部分*/

IR*  LindexStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(key_list_name_);
		auto tmp2 = SAFETRANSLATE(operandnum_);
		res = new IR(kLindexStmt, OP3("LINDEX","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void LindexStmt::deep_delete(){
	SAFEDELETE(key_list_name_);
	SAFEDELETE(operandnum_);
	delete this;
};

void LindexStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_list_name_ = new KeyListName();
		key_list_name_->generate();
		operandnum_ = new Operandnum();
		operandnum_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  LinsertStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(key_list_name_);
		auto tmp2 = SAFETRANSLATE(opt_linsert_behavior_);
		auto tmp3= SAFETRANSLATE(value1_);
		auto tmp4= SAFETRANSLATE(value2_);
		auto tmp5= new IR(kUnknown,OP3("LINSERT","",""),tmp1,tmp2)
		PUSH(tmp5);
		auto tmp6= new IR(kUnknown,OP3("","",""),tmp5,tmp3);
		PUSH(tmp6);
		res = new IR(kLinsertStmt, OP3("","",""), tmp6,tmp4);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void LinsertStmt::deep_delete(){
	SAFEDELETE(key_list_name_);
	SAFEDELETE(opt_linsert_behavior_);
	SAFEDELETE(value1_);
	SAFEDELETE(value2_);
	delete this;
};

void LinsertStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_list_name_ = new KeyListName();
		key_list_name_->generate();
		opt_linsert_behavior_ = new OptLinsertBehavior();
		opt_linsert_behavior_->generate();
		value1_ = new Value();
		value1_->generate();
		value2_ = new Value();
		value2_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  OptLinsertBehavior::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		res = new IR(kOptLinsertBehavior, OP3("BEFORE","",""));
		CASEEND
	    CASESTART(1)
		res = new IR(kOptLinsertBehavior, OP3("AFTER","",""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void OptLinsertBehavior::deep_delete(){
	delete this;
};

void OptLinsertBehavior::generate(){
	GENERATESTART(2)

	SWITCHSTART
		CASESTART(0)
		CASEEND
		CASESTART(1)
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  LlenStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_list_name_);
		res = new IR(kLlenStmt, OP3("LLEN","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void LlenStmt::deep_delete(){
	SAFEDELETE(key_list_name_);
	delete this;
};

void LlenStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_list_name_ = new KeyListName();
		key_list_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  LpopStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_list_name_);
		res = new IR(kLpopStmt, OP3("LPOP","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void LpopStmt::deep_delete(){
	SAFEDELETE(key_list_name_);
	delete this;
};

void LpopStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_list_name_ = new KeyListName();
		key_list_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  LpushStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_list_name_);
		auto tmp2= SAFETRANSLATE(value_list_);
		res = new IR(kLpushStmt, OP3("LPUSH","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void LpushStmt::deep_delete(){
	SAFEDELETE(key_list_name_);
	SAFEDELETE(value_list_);
	delete this;
};

void LpushStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_list_name_ = new KeyListName();
		key_list_name_->generate();
		value_list_ = new ValueList();
		value_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  LpushxStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_list_name_);
		auto tmp2= SAFETRANSLATE(value_);
		res = new IR(kLpushxStmt, OP3("LPUSHX","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void LpushxStmt::deep_delete(){
	SAFEDELETE(key_list_name_);
	SAFEDELETE(value_);
	delete this;
};

void LpushxStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_list_name_ = new KeyListName();
		key_list_name_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  LrangeStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_list_name_);
		auto tmp2= SAFETRANSLATE(operandnum1_);
		auto tmp3= SAFETRANSLATE(operandnum2_);
		auto tmp4= new IR(kUnknown,OP3("LRANGE","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kLrangeStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void LrangeStmt::deep_delete(){
	SAFEDELETE(key_list_name_);
	SAFEDELETE(operandnum1_);
	SAFEDELETE(operandnum2_);
	delete this;
};

void LrangeStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_list_name_ = new KeyListName();
		key_list_name_->generate();
		operandnum1_ = new Operandnum();
		operandnum1_->generate();
		operandnum2_ = new Operandnum();
		operandnum2_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  LremStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(key_list_name_);
		auto tmp2 = SAFETRANSLATE(operandnum_);
		auto tmp3 = SAFETRANSLATE(value_);
		auto tmp4 = new IR(kUnknown, OP3("LREM","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kLremStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void LremStmt::deep_delete(){
	SAFEDELETE(key_list_name_);
	SAFEDELETE(operandnum_);
	SAFEDELETE(value_);
	delete this;
};

void LremStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_list_name_ = new KeyListName();
		key_list_name_->generate();
		operandnum_ = new Operandnum();
		operandnum_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  LsetStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(key_list_name_);
		auto tmp2 = SAFETRANSLATE(operandnum_);
		auto tmp3 = SAFETRANSLATE(value_);
		auto tmp4 = new IR(kUnknown, OP3("LSET","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kLsetStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void LsetStmt::deep_delete(){
	SAFEDELETE(key_list_name_);
	SAFEDELETE(operandnum_);
	SAFEDELETE(value_);
	delete this;
};

void LsetStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_list_name_ = new KeyListName();
		key_list_name_->generate();
		operandnum_ = new Operandnum();
		operandnum_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  LtrimStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(key_list_name_);
		auto tmp2 = SAFETRANSLATE(operandnum1_);
		auto tmp3 = SAFETRANSLATE(operandnum2_);
		auto tmp4 = new IR(kUnknown, OP3("LTRIM","",""), tmp1,tmp2);
		res = new IR(kLtrimStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void LtrimStmt::deep_delete(){
	SAFEDELETE(key_list_name_);
	SAFEDELETE(operandnum1_);
	SAFEDELETE(operandnum2_);
	delete this;
};

void LtrimStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_list_name_ = new KeyListName();
		key_list_name_->generate();
		operandnum1_ = new Operandnum();
		operandnum1_->generate();
		operandnum2_ = new Operandnum();
		operandnum2_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

/*Set部分*/
IR*  RpopStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		res = new IR(kRpopStmt, OP3("RPOP","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void RpopStmt::deep_delete(){
	SAFEDELETE(key_set_name_);
	delete this;
};

void RpopStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  RpoplpushStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keysetname1_);
		auto tmp2= SAFETRANSLATE(keysetname2_);
		res = new IR(kRpoplpushStmt, OP3("RPOPLPUSH","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void RpoplpushStmt::deep_delete(){
	SAFEDELETE(keysetname1_);
	SAFEDELETE(keysetname2_);
	delete this;
};

void RpoplpushStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keysetname1_ = new KeySetName();
		keysetname1_->generate();
		keysetname2_ = new KeySetName();
		keysetname2_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  RpushStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		auto tmp2= SAFETRANSLATE(value_list_);
		res = new IR(kRpushStmt, OP3("RPUSH","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void RpushStmt::deep_delete(){
	SAFEDELETE(key_set_name_);
	SAFEDELETE(value_list_);
	delete this;
};

void RpushStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		value_list_ = new ValueList();
		value_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  RpushxStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		auto tmp2= SAFETRANSLATE(value_)
		res = new IR(kRpushxStmt, OP3("RPUSHX","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void RpushxStmt::deep_delete(){
	SAFEDELETE(key_set_name_);
	SAFEDELETE(value_;
	delete this;
};

void RpushxStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SaddStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		auto tmp2= SAFETRANSLATE(smember_name_list_);
		res = new IR(kSaddStmt, OP3("SADD","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SaddStmt::deep_delete(){
	SAFEDELETE(key_set_name_);
	SAFEDELETE(smember_name_list_);
	delete this;
};

void SaddStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		smember_name_list_ = new SmemberNameList();
		smember_name_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ScardStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		res = new IR(kScardStmt, OP3("SCARD","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ScardStmt::deep_delete(){
	SAFEDELETE(key_set_name_);
	delete this;
};

void ScardStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SdiffStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_list_);
		res = new IR(kSdiffStmt, OP3("SDIFF","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SdiffStmt::deep_delete(){
	SAFEDELETE(key_set_list_);
	delete this;
};

void SdiffStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_list_ = new KeySetList();
		key_set_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SdiffstoreStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_list_);
		res = new IR(kSdiffstoreStmt, OP3("SDIFFSTORE","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SdiffstoreStmt::deep_delete(){
	SAFEDELETE(key_set_list_);
	delete this;
};

void SdiffstoreStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_list_ = new KeySetList();
		key_set_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SinterStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_list_);
		res = new IR(kSinterStmt, OP3("SINTER","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SinterStmt::deep_delete(){
	SAFEDELETE(key_set_list_);
	delete this;
};

void SinterStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_list_ = new KeySetList();
		key_set_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SinterstoreStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_list_);
		res = new IR(kSinterstoreStmt, OP3("SINTERSTORE","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SinterstoreStmt::deep_delete(){
	SAFEDELETE(key_set_list_);
	delete this;
};

void SinterstoreStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_list_ = new KeySetList();
		key_set_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SismemberStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		auto tmp2= SAFETRANSLATE(smember_name_);
		res = new IR(kSismemberStmt, OP3("SISMEMBER","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SismemberStmt::deep_delete(){
	SAFEDELETE(key_set_name_);
	SAFEDELETE(smember_name_);
	delete this;
};

void SismemberStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		smember_name_ = new SmemberName();
		smember_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SmemberStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		res = new IR(kSmemberStmt, OP3("SMEMBERS","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SmemberStmt::deep_delete(){
	SAFEDELETE(key_set_name_);
	delete this;
};

void SmemberStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SmoveStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keysetname1_);
		auto tmp2= SAFETRANSLATE(keysetname2_);
		auto tmp3= SAFETRANSLATE(smember_name_);
		auto tmp4= new IR(kUnknown,OP3("SMOVE","",""),tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kSmoveStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SmoveStmt::deep_delete(){
	SAFEDELETE(keysetname1_);
	SAFEDELETE(keysetname2_);
	SAFEDELETE(smember_name_);
	delete this;
};

void SmoveStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keysetname1_ = new KeySetName();
		keysetname1_->generate();
		keysetname2_ = new KeySetName();
		keysetname2_->generate();
		smember_name_ = new SmemberName();
		smember_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  SpopStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		res = new IR(kSpopStmt, OP3("SPOP","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SpopStmt::deep_delete(){
	SAFEDELETE(key_set_name_);
	delete this;
};

void SpopStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SrandmemberStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(key_set_name_);
		auto tmp2 = SAFETRANSLATE(operandnum_);
		res = new IR(kSrandmemberStmt, OP3("SRANDMEMBER","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SrandmemberStmt::deep_delete(){
	SAFEDELETE(key_set_name_);
	SAFEDELETE(operandnum_);
	delete this;
};

void SrandmemberStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		operandnum_ = new Operandnum();
		operandnum_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SremStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		auto tmp2= SAFETRANSLATE(key_set_list_);
		res = new IR(kSremStmt, OP3("SREM","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SremStmt::deep_delete(){
	SAFEDELETE(key_set_name_);
	SAFEDELETE(key_set_list_);
	delete this;
};

void SremStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		key_set_list_ = new KeySetList();
		key_set_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SunionStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_list_);
		res = new IR(kSunionStmt, OP3("SUNION","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SunionStmt::deep_delete(){
	SAFEDELETE(key_set_list_);
	delete this;
};

void SunionStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_list_ = new KeySetList();
		key_set_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SunionstoreStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_list_);
		res = new IR(kSunionstoreStmt, OP3("SUNIONSTORE","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SunionstoreStmt::deep_delete(){
	SAFEDELETE(key_set_list_);
	delete this;
};

void SunionstoreStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_set_list_ = new KeySetList();
		key_set_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}



/*zset部分*/

IR*  ZaddStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		auto tmp2= SAFETRANSLATE(zmember_value_list_);
		res = new IR(kZaddStmt, OP3("ZADD","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZaddStmt::deep_delete(){
	SAFEDELETE(key_zset_name_);
	SAFEDELETE(zmember_value_list_);
	delete this;
};

void ZaddStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		zmember_value_list_ = new kMemberValueList();
		zmember_value_lis_t->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ZcardStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		res = new IR(kZcardStmt, OP3("ZCARD","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZcardStmt::deep_delete(){
	SAFEDELETE(key_zset_name_);
	delete this;
};

void ZcardStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ZcountStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		auto tmp2= SAFETRANSLATE(operandnum1_);
		auto tmp3= SAFETRANSLATE(operandnum2_);
		auto tmp4= new IR(kUnknown,OP3("ZCOUNT","",""),tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kZcountStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZcountStmt::deep_delete(){
	SAFEDELETE(key_zset_name_);
	SAFEDELETE(operandnum1_);
	SAFEDELETE(operandnum2_);
	delete this;
};

void ZcountStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		operandnum1_ = new Operandnum();
		operandnum1_->generate();
		operandnum2_ = new Operandnum();
		operandnum2_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ZincrbyStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1 = SAFETRANSLATE(key_zset_name_);
		auto tmp2 = SAFETRANSLATE(operandnum_);
		auto tmp3 = SAFETRANSLATE(zmember_name_);
		auto tmp4 = new IR(kUnknown, OP3("ZINCRBY","",""), tmp1,tmp2);
		res = new IR(ZincrbyStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZincrbyStmt::deep_delete(){
	SAFEDELETE(key_zset_name_);
	SAFEDELETE(operandnum_);
	SAFEDELETE(zmember_name_);
	delete this;
};

void ZincrbyStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		operandnum_ = new Operandnum();
		operandnum_->generate();
		zmember_name_ = new ZmemberName();
		zmember_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ZrangeStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		auto tmp2= SAFETRANSLATE(operandnum1_);
		auto tmp3= SAFETRANSLATE(operandnum2_);
		auto tmp4= new IR(kUnknown, OP3("ZRANGE","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kZrangeStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND


	TRANSLATEEND
}

void ZrangeStmt::deep_delete(){
	SAFEDELETE(key_zset_name_);
	SAFEDELETE(operandnum1_);
	SAFEDELETE(operandnum2_);
	delete this;
};

void ZrangeStmt::generate(){
	GENERATESTART(3)

	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		operandnum1_ = new Operandnum();
		operandnum1_->generate();
		operandnum2_ = new Operandnum();
		operandnum2_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  OptZrangeBehavior::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		res = new IR(kOptZrangeBehavior, OP3("WITHSCORES","",""));
		CASEEND
		CASESTART(1)
		res = new IR(kOptZrangeBehavior, string(""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void OptZrangeBehavior::deep_delete(){
	delete this;
};

void OptZrangeBehavior::generate(){
	GENERATESTART(2)

	SWITCHSTART
		CASESTART(0)
		CASEEND
		CASESTART(1)
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ZrangebyscoreClause::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		auto tmp2= SAFETRANSLATE(operandnum1_);
		auto tmp3= SAFETRANSLATE(operandnum2_);
		auto tmp4= new IR(kUnknown, OP3("ZRANGEBYSCORE","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kZrangebyscoreClause, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZrangebyscoreClause::deep_delete(){
	SAFEDELETE(key_zset_name_);
	SAFEDELETE(operandnum1_);
	SAFEDELETE(operandnum1_);
	delete this;
};

void ZrangebyscoreClause::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		operandnum1_ = new Operandnum();
		Operandnum1_->generate();
		operandnum2_ = new Operandnum();
		Operandnum2_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  ZrangebyscoreStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(zrangebyscore_clause_);
		auto tmp2= SAFETRANSLATE(opt_limit_clause_);
		res = new IR(kZrangebyscoreStmt, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZrangebyscoreStmt::deep_delete(){
	SAFEDELETE(zrangebyscore_clause_);
	SAFEDELETE(opt_limit_clause_);
	delete this;
};

void ZrangebyscoreStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		zrangebyscore_clause_ = new ZrangebyscoreClause();
		zrangebyscore_clause_->generate();
		opt_limit_clause_ = new OptLimitClause();
		opt_limit_clause_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  ZrankStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		auto tmp2= SAFETRANSLATE(zmember_name_);
		res = new IR(kZrankStmt, OP3("ZRANK","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZrankStmt::deep_delete(){
	SAFEDELETE(key_zset_name_);
	SAFEDELETE(zmember_name_);
	delete this;
};

void ZrankStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new SelectStmt();
		key_zset_name_->generate();
		zmember_name_ = new ZmemberName();
		zmember_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ZremStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		auto tmp2= SAFETRANSLATE(zmember_name_list_);
		res = new IR(kZremStmt, OP3("ZREM","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZremStmt::deep_delete(){
	SAFEDELETE(key_zset_name_);
	SAFEDELETE(zmember_name_list_);
	delete this;
};

void ZremStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		zmember_name_list_ = new ZmemberNameList();
		zmember_name_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  ZscoreStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		auto tmp2= SAFETRANSLATE(zmember_name_);
		res = new IR(kZscoreStmt, OP3("ZSCORE","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZscoreStmt::deep_delete(){
	SAFEDELETE(key_zset_name_);
	SAFEDELETE(zmember_name_);
	delete this;
};

void ZscoreStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		zmember_name_ = new ZmemberName();
		zmember_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  ZunionstoreStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(zunionstore_clause_);
		auto tmp2= SAFETRANSLATE(opt_weight_clause_);
		auto tmp3= SAFETRANSLATE(opt_aggregate_clause_);
		auto tmp4= new IR(kZunionstoreStmt, OP3("","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kZunionstoreStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZunionstoreStmt::deep_delete(){
	SAFEDELETE(zunionstore_clause_);
	SAFEDELETE(opt_weight_clause_);
	SAFEDELETE(opt_aggregate_clause_);
	delete this;
};

void ZunionstoreStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		zunionstore_clause_ = new ZunionstoreClause();
		zunionstore_clause_->generate();
		opt_weight_clause_ = new OptWeightClause();
		opt_weight_clause_->generate();
		opt_aggregate_clause_ = new OptAggregateClause();
		opt_aggregate_clause_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ZunionstoreClause::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		auto tmp2= SAFETRANSLATE(operandnum_);
		auto tmp3= SAFETRANSLATE(key_zset_list_);
		auto tmp4= new IR(kUnknown, OP3("ZUNIONSTORE","",""), tmp1,tmp2);
		PUSH(tmp4);
		auto tmp5= new IR(kZunionstoreClause,OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZunionstoreClause::deep_delete(){
	SAFEDELETE(key_zset_name_);
	SAFEDELETE(operandnum_);
	SAFEDELETE(key_zset_list_);
	delete this;
};

void ZunionstoreClause::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		operandnum_ = new Operandnum();
		operandnum_->generate();
		key_zset_list_ = new KeyKzetList();
		key_zset_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  OptWeightClause::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(operandnum_list_);
		res = new IR(kOptWeightClause, OP3("WEIGHTS","",""), tmp1);
		CASEEND
		CASESTART(1)
		res = new IR(kOptWeightClause, string(""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void OptWeightClause::deep_delete(){
	SAFEDELETE(operandnum_list_);
	delete this;
};

void OptWeightClause::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		operandnum_list_ = new OperandnumList();
		operandnum_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  OptAggregateClause::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		res = new IR(kOptAggregateClause, OP3("AGGREGATE SUM","",""));
		CASEEND
		CASESTART(1)
		res = new IR(kOptAggregateClause, OP3("AGGREGATE MIN","",""));
		CASEEND
		CASESTART(2)
		res = new IR(kOptAggregateClause, OP3("AGGREGATE MAX","",""));
		CASEEND
		CASESTART(3)
		res = new IR(kOptAggregateClause, string(""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void OptAggregateClause::deep_delete(){
	delete this;
};

void OptAggregateClause::generate(){
	GENERATESTART(4)

	SWITCHSTART
		CASESTART(0)
		CASEEND
		CASESTART(1)
		CASEEND
		CASESTART(2)
		CASEEND
		CASESTART(3)
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ZinterstoreStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(zunionstore_clause_);
		auto tmp2= SAFETRANSLATE(opt_weight_clause_);
		auto tmp3= SAFETRANSLATE(opt_aggregate_clause_);
		auto tmp4= new IR(kZinterstoreStmt, OP3("","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kZinterstoreStmt, OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZinterstoreStmt::deep_delete(){
	SAFEDELETE(zunionstore_clause_);
	SAFEDELETE(opt_weight_clause_);
	SAFEDELETE(opt_aggregate_clause_);
	delete this;
};

void ZinterstoreStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		zunionstore_clause_ = new ZinterstoreStmt();
		zunionstore_clause_->generate();
		opt_weight_clause_ = new OptWeightClause();
		opt_weight_clause_->generate();
		opt_aggregate_clause_ = new OptAggregateClause();
		opt_aggregate_clause_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  ZinterstoreClause::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		auto tmp2= SAFETRANSLATE(operandnum_);
		auto tmp3= SAFETRANSLATE(key_zset_list_);
		auto tmp4= new IR(kUnknown, OP3("ZINTERSTORE","",""), tmp1,tmp2);
		PUSH(tmp4);
		res = new IR(kZinterstoreClause,OP3("","",""), tmp4,tmp3);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZinterstoreClause::deep_delete(){
	SAFEDELETE(key_zset_name_);
	SAFEDELETE(operandnum_);
	SAFEDELETE(key_zset_list_);
	delete this;
};

void ZinterstoreClause::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		operandnum_ = new Operandnum();
		operandnum_->generate();
		key_zset_list_ = new KeyKzetList();
		key_zset_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}





IR*  SelectStmt::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(operandnum_);
		res = new IR(kSelectStmt, OP3("SELECT","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SelectStmt::deep_delete(){
	SAFEDELETE(operandnum_);
	delete this;
};

void SelectStmt::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		operandnum_ = new Operandnum();
		soperandnum_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  KeyList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		res = new IR(kKeyList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(keyname_);
		auto tmp2= SAFETRANSLATE(key_list_);
		res = new IR(kKeyList, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyList::deep_delete(){
	SAFEDELETE(keyname_);
	SAFEDELETE(key_list_);
	delete this;
};

void KeyList::generate(){
	GENERATESTART(2)
	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		CASEEND
		CASESTART(1)
		keyname_ = new KeyName();
		keyname_->generate();
		key_list_ = new KeyList();
		key_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  KeyName::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(identifier_);
		res = new IR(kKeyName, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND
	TRANSLATEEND
}

void KeyName::deep_delete(){
	SAFEDELETE(identifier_);
	delete this;
};

void KeyName::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		identifier_ = new Identifier();
		identifier_->generate();
		CASEEND
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  KeyStringName::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(identifier_);
		res = new IR(kKeyStringName, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyStringName::deep_delete(){
	SAFEDELETE(identifier_);
	delete this;
};

void KeyStringName::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		identifier_ = new Identifier();
		identifier_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  KeyStringList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		res = new IR(kKeyStringList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(key_string_list_);
		res = new IR(kKeyStringList, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyStringList::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(key_string_list_);
	delete this;
};

void KeyStringList::generate(){
	GENERATESTART(2)
	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		CASEEND
		CASESTART(1)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		key_string_list_ = new KeyStringList();
		key_string_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}



IR*  KeyStringValueList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_value_);
		res = new IR(kKeyStringValueList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(key_string_value_);
		auto tmp2= SAFETRANSLATE(key_string_value_list_);
		res = new IR(kKeyStringValueList,, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyStringValueList::deep_delete(){
	SAFEDELETE(key_string_value_);
	SAFEDELETE(key_string_value_list_);
	delete this;
};

void KeyStringValueList::generate(){
	GENERATESTART(2)
	SWITCHSTART
		CASESTART(0)
		key_string_value_ = new KeyStringValue();
		key_string_value_->generate();
		CASEEND
		CASESTART(1)
		key_string_value_ = new KeyStringValue();
		key_string_value_->generate();
		key_string_value_list_ = new KeyStringValueList();
		key_string_value_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  KeyStringValue::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		res = new IR(kKeyStringValue, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(key_string_name_);
		auto tmp2= SAFETRANSLATE(value_);
		res = new IR(kKeyStringValue,, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyStringValue::deep_delete(){
	SAFEDELETE(key_string_name_);
	SAFEDELETE(value_);
	delete this;
};

void KeyStringValue::generate(){
	GENERATESTART(2)
	SWITCHSTART
		CASESTART(0)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		CASEEND
		CASESTART(1)
		key_string_name_ = new KeyStringName();
		key_string_name_->generate();
		value_ = new KeyStringName();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

/*Hash部分*/
IR*  KeyHashName::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(identifier_);
		res = new IR(kKeyHashName, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyHashName::deep_delete(){
	SAFEDELETE(identifier_);
	delete this;
};

void KeyHashName::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		identifier_ = new Identifier();
		identifier_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

/*list部分*/
IR*  KeyListName::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(identifier_);
		res = new IR(kKeyListName, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyListName::deep_delete(){
	SAFEDELETE(identifier_);
	delete this;
};

void KeyListName::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		identifier_ = new Identifier();
		identifier_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

/**keyset类型*/

IR*  KeySetName::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(identifier_);
		res = new IR(kKeySetName, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeySetName::deep_delete(){
	SAFEDELETE(identifier_);
	delete this;
};

void KeySetName::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		identifier_ = new Identifier();
		identifier_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  KeySetList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		res = new IR(kKeySetList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		auto tmp2= SAFETRANSLATE(key_set_list_);
		res = new IR(kKeySetList,, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeySetList::deep_delete(){
	SAFEDELETE(key_set_name_);
	SAFEDELETE(key_set_list_);
	delete this;
};

void KeySetList::generate(){
	GENERATESTART(2)
	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		CASEEND
		CASESTART(1)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		key_set_list_ = new KeySetList();
		key_set_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  DelKeySetList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		res = new IR(kKeySetList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(key_set_name_);
		auto tmp2= SAFETRANSLATE(del_key_set_list_);
		res = new IR(kDelKeySetList,, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void DelKeySetList::deep_delete(){
	SAFEDELETE(key_set_name_);
	SAFEDELETE(del_key_set_list_);
	delete this;
};

void DelKeySetList::generate(){
	GENERATESTART(2)
	SWITCHSTART
		CASESTART(0)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		CASEEND
		CASESTART(1)
		key_set_name_ = new KeySetName();
		key_set_name_->generate();
		del_key_set_list_ = new DelKeySetList();
		del_key_set_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SmemberName::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(identifier_);
		res = new IR(kSmemberName, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SmemberName::deep_delete(){
	SAFEDELETE(identifier_);
	delete this;
};

void SmemberName::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		identifier_ = new Identifier();
		identifier_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  SmemberNameList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(smember_name_);
		res = new IR(kSmemberNameList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(smember_name_);
		auto tmp2= SAFETRANSLATE(smember_name_list_);
		res = new IR(kSmemberNameList,, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void SmemberNameList::deep_delete(){
	SAFEDELETE(smember_name_);
	SAFEDELETE(smember_name_list_);
	delete this;
};

void SmemberNameList::generate(){
	GENERATESTART(2)
	SWITCHSTART
		CASESTART(0)
		smember_name_ = new SmemberName();
		smember_name_->generate();
		CASEEND
		CASESTART(1)
		smember_name_ = new SmemberName();
		smember_name_->generate();
		smember_name_list_ = new SmemberNameList();
		smember_name_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

/*zset类型*/


IR*  KeyZsetName::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(identifier_);
		res = new IR(kKeyZsetName, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyZsetName::deep_delete(){
	SAFEDELETE(identifier_);
	delete this;
};

void KeyZsetName::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		identifier_ = new Identifier();
		identifier_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  KeyZsetList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		res = new IR(kKeyZsetList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(key_zset_name_);
		auto tmp2= SAFETRANSLATE(key_zset_list_);
		res = new IR(kKeyZsetList,, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyZsetList::deep_delete(){
	SAFEDELETE(key_zset_name_);
	SAFEDELETE(key_zset_list_);
	delete this;
};

void KeyZsetList::generate(){
	GENERATESTART(2)
	SWITCHSTART
		CASESTART(0)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		CASEEND
		CASESTART(1)
		key_zset_name_ = new KeyZsetName();
		key_zset_name_->generate();
		key_zset_list_ = new KeyKzetList();
		key_zset_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ZmemberName::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(identifier_);
		res = new IR(kZmemberName, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZmemberName::deep_delete(){
	SAFEDELETE(identifier_);
	delete this;
};

void ZmemberName::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		identifier_ = new Identifier();
		identifier_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  ZmemberNameList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(zmember_name_);
		res = new IR(kZmemberNameList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(zmember_name_);
		auto tmp2= SAFETRANSLATE(zmember_name_list_);
		res = new IR(kZmemberNameList,, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZmemberNameList::deep_delete(){
	SAFEDELETE(zmember_name_);
	SAFEDELETE(zmember_name_list_);
	delete this;
};

void ZmemberNameList::generate(){
	GENERATESTART(2)
	SWITCHSTART
		CASESTART(0)
		zmember_name_ = new ZmemberName();
		zmember_name_->generate();
		CASEEND
		CASESTART(1)
		zmember_name_ = new ZmemberName();
		zmember_name_->generate();
		zmember_name_list_ = new ZmemberNameList();
		zmember_name_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ZmemberValue::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(value_);
		res = new IR(kZmemberValue, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(value_);
		auto tmp2= SAFETRANSLATE(zmember_name_);
		res = new IR(kZmemberValue,, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZmemberValue::deep_delete(){
	SAFEDELETE(value_);
	SAFEDELETE(zmember_name_);
	delete this;
};

void ZmemberValue::generate(){
	GENERATESTART(2)
	SWITCHSTART
		CASESTART(0)
		value_ = new Value();
		value_->generate();
		CASEEND
		CASESTART(1)
		value_ = new Value();
		value_->generate();
		zmember_name_ = new ZmemberName();
		zmember_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  ZmemberValueList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(zmember_value_);
		res = new IR(kZmemberValueList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(zmember_value_);
		auto tmp2= SAFETRANSLATE(zmember_value_list_);
		res = new IR(kZmemberValueList,, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ZmemberValueList::deep_delete(){
	SAFEDELETE(zmember_value_);
	SAFEDELETE(zmember_value_list_);
	delete this;
};

void ZmemberValueList::generate(){
	GENERATESTART(2)
	SWITCHSTART
		CASESTART(0)
		zmember_value_ = new ZmemberValue();
		zmember_value_->generate();
		CASEEND
		CASESTART(1)
		zmember_value_ = new ZmemberValue();
		zmember_value_->generate();
		zmember_value_list_ = new ZmemberValueList();
		zmember_value_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}


IR*  Value::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(literal_);
		res = new IR(kValue, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void Value::deep_delete(){
	SAFEDELETE(literal_);
	delete this;
};

void Value::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		literal_ = new Literal();
		literal_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  ValueList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(value_);
		res = new IR(kValueList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(value_);
		auto tmp2= SAFETRANSLATE(value_list_);
		res = new IR(kValueList, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void ValueList::deep_delete(){
	SAFEDELETE(value_);
	SAFEDELETE(value_list_);
	delete this;
};

void ValueList::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		value_ = new SelectStmt();
		value_->generate();
		value_list_ = new ValueList();
		value_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  KeyValueList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyvalue_);
		res = new IR(kKeyValueList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyvalue_);
		auto tmp2= SAFETRANSLATE(key_value_list_);
		res = new IR(kKeyValueList, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyValueList::deep_delete(){
	SAFEDELETE(keyvalue_);
	SAFEDELETE(key_value_list_);
	delete this;
};

void KeyValueList::generate(){
	GENERATESTART(2)

	SWITCHSTART
		CASESTART(0)
		keyvalue_ = new KeyName();
		keyvalue_->generate();
		CASEEND
		CASESTART(1)
		keyvalue_ = new KeyName();
		keyvalue_->generate();
		key_value_list_ = new KeyValueList();
		key_value_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  KeyValue::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(keyname_);
		auto tmp2= SAFETRANSLATE(value_);
		res = new IR(kKeyValue, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void KeyValue::deep_delete(){
	SAFEDELETE(keyname_);
	SAFEDELETE(value_);
	delete this;
};

void KeyValue::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		keyname_ = new KeyName();
		keyname_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  FieldList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(field_name_);
		res = new IR(kFieldList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(field_name_);
		auto tmp2= SAFETRANSLATE(field_list_);
		res = new IR(kFieldList, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void FieldList::deep_delete(){
	SAFEDELETE(field_name_);
	SAFEDELETE(field_list_);
	delete this;
};

void FieldList::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		field_name_ = new FieldName();
		field_name_->generate();
		CASEEND
		CASESTART(1)
		field_name_ = new FieldName();
		field_name_->generate();
		field_list_ = new FieldList();
		field_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  DelFieldList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(field_name_);
		res = new IR(kDelFieldList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(field_name_);
		auto tmp2= SAFETRANSLATE(del_field_list_);
		res = new IR(kDelFieldList, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void DelFieldList::deep_delete(){
	SAFEDELETE(field_name_);
	SAFEDELETE(del_field_list_);
	delete this;
};

void DelFieldList::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		field_name_ = new FieldName();
		field_name_->generate();
		CASEEND
		CASESTART(1)
		field_name_ = new FieldName();
		field_name_->generate();
		del_field_list_ = new DelFieldList();
		del_field_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  FieldName::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(identifier_);
		res = new IR(kFieldName, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void FieldName::deep_delete(){
	SAFEDELETE(identifier_);
	delete this;
};

void FieldName::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		identifier_ = new Identifier();
		identifier_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  FieldValue::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(field_name_);
		auto tmp2= SAFETRANSLATE(value_);
		res = new IR(kFieldValue, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void FieldValue::deep_delete(){
	SAFEDELETE(field_name_);
	SAFEDELETE(value_);
	delete this;
};

void FieldValue::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		field_name_ = new FieldName();
		field_name_->generate();
		value_ = new Value();
		value_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  MemberName::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(identifier_);
		res = new IR(kMemberName, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void MemberName::deep_delete(){
	SAFEDELETE(identifier_);
	delete this;
};

void MemberName::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		identifier_ = new Identifier();
		identifier_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  MemberValue::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(value_);
		auto tmp2= SAFETRANSLATE(member_name_);
		res = new IR(kMemberValue, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void MemberValue::deep_delete(){
	SAFEDELETE(value_);
	SAFEDELETE(member_name_);
	delete this;
};

void MemberValue::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		value_ = new Value();
		value_->generate();
		member_name_ = new MemberName();
		member_name_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  MemberValueList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(member_value_);
		res = new IR(kMemberValueList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(member_value_);
		auto tmp2= SAFETRANSLATE(member_value_list_);
		res = new IR(kMemberValueList, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void MemberValueList::deep_delete(){
	SAFEDELETE(member_value_);
	SAFEDELETE(member_value_list_);
	delete this;
};

void MemberValueList::generate(){
	GENERATESTART(2)

	SWITCHSTART
		CASESTART(0)
		member_value_ = new MemberValue();
		member_value_->generate();
		CASEEND
		CASESTART(1)
		member_value_ = new MemberValue();
		member_value_->generate();
		member_value_list_ = new MemberValueList();
		member_value_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  FieldValueList::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(field_value_);
		res = new IR(kFieldValueList, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(field_value_);
		auto tmp2= SAFETRANSLATE(field_value_list_);
		res = new IR(kFieldValueList, OP3("","",""), tmp1,tmp2);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void FieldValueList::deep_delete(){
	SAFEDELETE(field_value_);
	SAFEDELETE(field_value_list_);
	delete this;
};

void FieldValueList::generate(){
	GENERATESTART(2)

	SWITCHSTART
		CASESTART(0)
		field_value_ = new FieldValue();
		field_value_->generate();
		CASEEND
		CASESTART(0)
		field_value_ = new FieldValue();
		field_value_->generate();
		field_value_list_ = new FieldValueList();
		field_value_list_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  Operandnum::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(int_literal_);
		res = new IR(kOperandnum, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void Operandnum::deep_delete(){
	SAFEDELETE(int_literal_);
	delete this;
};

void Operandnum::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		int_literal_ = new Operandnum();
		int_literal_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  Operation::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		res = new IR(kOperation, OP3("AND","",""));
		CASEEND
		CASESTART(1)
		res = new IR(kOperation, OP3("OR","",""));
		CASEEND
		CASESTART(2)
		res = new IR(kOperation, OP3("XOR","",""));
		CASEEND
		CASESTART(3)
		res = new IR(kOperation, OP3("NOT","",""));
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void Operation::deep_delete(){
	delete this;
};

void Operation::generate(){
	GENERATESTART(1)

	SWITCHSTART
		CASESTART(0)
		CASEEND
		CASESTART(1)
		CASEEND
		CASESTART(2)
		CASEEND
		CASESTART(3)
		CASEEND
	SWITCHEND

	GENERATEEND
}

IR*  Identifier::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

		res = new IR(kIdentifier, string_val_, data_type_, scope_, data_flag_);

	TRANSLATEEND
}

void Identifier::deep_delete(){
	delete this;
};

void Identifier::generate(){
	GENERATESTART(1)

		string_val_ = gen_string();

	GENERATEEND
}


IR*  Literal::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(string_literal_);
		res = new IR(kLiteral, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(num_literal_);
		res = new IR(kLiteral, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void Literal::deep_delete(){
	SAFEDELETE(string_literal_);
	SAFEDELETE(num_literal_);
	delete this;
};

void Literal::generate(){
	GENERATESTART(3)

	SWITCHSTART
		CASESTART(0)
		string_literal_ = new StringLiteral();
		string_literal_->generate();
		CASEEND
		CASESTART(1)
		num_literal_ = new NumLiteral();
		num_literal_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}



IR*  StringLiteral::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

		res = new IR(kStringLiteral, string_val_, data_type_, scope_, data_flag_);

	TRANSLATEEND
}

void StringLiteral::deep_delete(){
	delete this;
};

void StringLiteral::generate(){
	GENERATESTART(1)

		string_val_ = gen_string();

	GENERATEEND
}


IR*  NumLiteral::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

	SWITCHSTART
		CASESTART(0)
		auto tmp1= SAFETRANSLATE(int_literal_);
		res = new IR(kNumLiteral, OP3("","",""), tmp1);
		CASEEND
		CASESTART(1)
		auto tmp1= SAFETRANSLATE(float_literal_);
		res = new IR(kNumLiteral, OP3("","",""), tmp1);
		CASEEND
	SWITCHEND

	TRANSLATEEND
}

void NumLiteral::deep_delete(){
	SAFEDELETE(int_literal_);
	SAFEDELETE(float_literal_);
	delete this;
};

void NumLiteral::generate(){
	GENERATESTART(2)

	SWITCHSTART
		CASESTART(0)
		int_literal_ = new IntLiteral();
		int_literal_->generate();
		CASEEND
		CASESTART(1)
		float_literal_ = new FloatLiteral();
		float_literal_->generate();
		CASEEND
	SWITCHEND

	GENERATEEND
}



IR*  IntLiteral::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

		res = new IR(kIntLiteral, int_val_, data_type_, scope_, data_flag_);

	TRANSLATEEND
}

void IntLiteral::deep_delete(){
	delete this;
};

void IntLiteral::generate(){
	GENERATESTART(1)

		int_val_ = gen_int();

	GENERATEEND
}




IR*  FloatLiteral::translate(vector<IR *> &v_ir_collector){
	TRANSLATESTART

		res = new IR(kFloatLiteral, float_val_, data_type_, scope_, data_flag_);

	TRANSLATEEND
}

void FloatLiteral::deep_delete(){
	delete this;
};

void FloatLiteral::generate(){
	GENERATESTART(1)

		float_val_ = gen_float();

	GENERATEEND
}
