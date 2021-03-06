#pragma once
#ifndef __DEFINE_H__
#define __DEFINE_H__


#define ALLTYPE(V) \
    V(kUnknown) \
	/*第一层次*/V(kProgram) \
	V(kStmtlist) \
	V(kStmt) \
    V(kKeyStmt) \
    V(kStringStmt) \
    V(kHashStmt) \
    V(kListStmt) \
    V(kSetStmt) \
    V(kZsetStmt) \
    V(kConnectStmt) \
    /*Key操作类型*/V(kDelStmt) \
    V(kKeyList) \
    V(kDumpStmt) \
    V(kExistsStmt) \
    V(kExpireStmt) \
    V(kTimeSecond) \
    V(kExpireatStmt) \
    V(kTimeUnix) \
    V(kMoveStmt) \
    V(kObjectStmt) \
    V(kObjoption) \
    V(kPersistStmt) \
    V(kPexpireStmt) \
    V(kPexpireatStmt) \
    V(kPttlStmt) \
    V(kRandomkeyStmt) \
    V(kRnameStmt) \
    V(kAliasName) \
    V(kRnamenxStmt) \
    V(kSortStmt) \
    V(kSortClause) \
    V(kOptByClause) \
    V(kOptLimitClause) \
    V(kOptGetClauseList) \
    V(kOptStoreClause) \
    V(kOperandList) \
    V(kOptGetClause) \
    V(kOptSortBehavior) \
    V(kTtlStmt) \
    V(kTypeStmt) \
    /*String操作类型*/V(kAppendStmt) \
    V(kValue) \
    V(kBicountStmt) \
    V(kSetbitStmt) \
    V(kBitopStmt) \
    V(kOperation) \
    V(kDecrStmt) \
    V(kDecrbyStmt) \
    V(kGetStmt) \
    V(kGetbitStmt) \
    V(kGetrangeStmt) \
    V(kGetsetStmt) \
    V(kIncrStmt) \
    V(kIncrbyStmt) \
    V(kIncrbyfloatStmt) \
    V(kMgetStmt) \
    V(kMsetStmt) \
    V(kPsetexStmt) \
    V(kSetkeyStmt) \
    V(kSetkeyClause) \
    V(kOptExpireTimeClause) \
    V(kOptSetkeyBehavior) \
    V(kSetbitStmt) \
    V(kSetexStmt) \
    V(kSetnxStmt) \
    V(kSetrangeStmt) \
    V(kStrlenStmt) \
    /*hashstmt*/V(kHdelStmt) \
    V(kHexistsStmt) \
    V(kHgetStmt) \
    V(kHgetallStmt) \
    V(kHincrbyStmt) \
    V(kHincrbyfloatStmt) \
    V(kHkeysStmt) \
    V(kHlenStmt) \
    V(kHmgetStmt) \
    V(kHmsetStmt) \
    V(kSetStmt) \
    V(kHsetnxStmt) \
    V(kHvalsStmt) \
    /*liststmt*/V(kLindexStmt) \
    V(kLinsertStmt) \
    V(kOptLinsertBehavior) \
    V(kLlenStmt) \
    V(kLpopStmt) \
    V(kLpushStmt) \
    V(kLpushxStmt) \
    V(kLrangeStmt) \
    V(kLremStmt) \
    V(kLsetStmt) \
    V(kLtrimStmt) \
    V(kRpopStmt) \
    V(kPoplpushStmt) \
    V(kPushStmt) \
    V(kPushxStmt) \
    /*setstmt*/V(kSaddStmt) \
    V(kScardStmt) \
    V(kSdiffStmt) \
    V(kSdiffstoreStmt) \
    V(kSinterStmt) \
    V(kSinterstoreStmt) \
    V(kSismemberStmt) \
    V(kSmemberStmt) \
    V(kSmoveStmt) \
    V(kSpopStmt) \
    V(kSrandmemberStmt) \
    V(kSremStmt) \
    V(kSunionStmt) \
    V(kSunionstoreStmt) \
    /*zsetstmt*/V(kZaddStmt) \
    V(kZcardStmt) \
    V(kZcountStmt) \
    V(kZincrbyStmt) \
    V(kZrangeStmt) \
    V(kOptZrangeBehavior) \
    V(kZrangebyscoreStmt) \
    V(kZrangebyscoreClause) \
    V(kZrankStmt) \
    V(kZremStmt) \
    V(kZscoreStmt) \
    V(kZunionstoreStmt) \
    V(kZunionstoreClause) \
    V(kOptWeightClause) \
    V(kOptAggregateClause) \
    V(kZinterstoreStmt) \
    /*connect*/ V(kConnectStmt) \
    V(kKeyName) \
    V(kKeyStringName) \
    V(kKeyHashName)\
    V(kKeyListName) \
    V(kKeySetName) \
    V(kKeyZsetName) \
    V(kKeyStringList) \
    V(kKeyStringValueList) \
    V(kKeyStringValue) \
    V(kKeySetList) \
    V(kKeyZsetList) \
    V(kValueList) \
    V(kKeyValueList) \
    V(kKeyValue) \
    V(kFieldList) \
    V(kDelFieldList) \
    V(kFieldName) \
    V(kFieldValue) \
    V(kZmemberName) \
    V(kZmemberValue) \
    V(kZmemberValueList) \
    V(kSmemberName) \
    V(kSmemberNameList) \
    V(kFieldValueList) \
    V(kOperandnum) \
    V(kIdentifier) \
    V(kLiteral) \
    V(kStringLiteral) \
    V(kBoolLiteral) \
    V(kNumLiteral) \
    V(kIntLiteral) \
    V(kFloatLiteral) \


#define ALLCLASS(V) \
	/*第一层次*/V(Program) \
	V(Stmtlist) \
	V(Stmt) \
    V(KeyStmt) \
    V(StringStmt) \
    V(HashStmt) \
    V(ListStmt) \
    V(SetStmt) \
    V(ZsetStmt) \
    V(ConnectStmt) \
    /*Key操作类型*/V(DelStmt) \
    V(KeyList) \
    V(DumpStmt) \
    V(ExistsStmt) \
    V(ExpireStmt) \
    V(TimeSecond) \
    V(ExpireatStmt) \
    V(TimeUnix) \
    V(MoveStmt) \
    V(ObjectStmt) \
    V(Objoption) \
    V(PersistStmt) \
    V(PexpireStmt) \
    V(PexpireatStmt) \
    V(PttlStmt) \
    V(RandomkeyStmt) \
    V(RenameStmt) \
    V(AliasName) \
    V(RenamenxStmt) \
    V(SortStmt) \
    V(SortClause) \
    V(OptByClause) \
    V(OptLimitClause) \
    V(OptGetClauseList) \
    V(OptStoreClause) \
    V(OperandList) \
    V(OptGetClause) \
    V(OptSortBehavior) \
    V(TtlStmt) \
    V(TypeStmt) \
    /*String操作类型*/V(AppendStmt) \
    V(Value) \
    V(BicountStmt) \
    V(SetbitStmt) \
    V(BitopStmt) \
    V(Operation) \
    V(DecrStmt) \
    V(DecrbyStmt) \
    V(GetStmt) \
    V(GetbitStmt) \
    V(GetrangeStmt) \
    V(GetsetStmt) \
    V(IncrStmt) \
    V(IncrbyStmt) \
    V(IncrbyfloatStmt) \
    V(MgetStmt) \
    V(MsetStmt) \
    V(PsetexStmt) \
    V(SetkeyStmt) \
    V(SetkeyClause) \
    V(OptExpireTimeClause) \
    V(OptSetkeyBehavior) \
    V(SetbitStmt) \
    V(SetexStmt) \
    V(SetnxStmt) \
    V(SetrangeStmt) \
    V(StrlenStmt) \
    /*hashstmt*/V(HdelStmt) \
    V(HexistsStmt) \
    V(HgetStmt) \
    V(HgetallStmt) \
    V(HincrbyStmt) \
    V(HincrbyfloatStmt) \
    V(HkeysStmt) \
    V(HlenStmt) \
    V(HmgetStmt) \
    V(HmsetStmt) \
    V(HsetStmt) \
    V(HsetnxStmt) \
    V(HvalsStmt) \
    /*liststmt*/V(LindexStmt) \
    V(LinsertStmt) \
    V(OptLinsertBehavior) \
    V(LlenStmt) \
    V(LpopStmt) \
    V(LpushStmt) \
    V(LpushxStmt) \
    V(LrangeStmt) \
    V(LremStmt) \
    V(LsetStmt) \
    V(LtrimStmt) \
    V(RpopStmt) \
    V(RpoplpushStmt) \
    V(RpushStmt) \
    V(RpushxStmt) \
    /*setstmt*/V(SaddStmt) \
    V(ScardStmt) \
    V(SdiffStmt) \
    V(SdiffstoreStmt) \
    V(SinterStmt) \
    V(SinterstoreStmt) \
    V(SismemberStmt) \
    V(SmemberStmt) \
    V(SmoveStmt) \
    V(SpopStmt) \
    V(SrandmemberStmt) \
    V(SremStmt) \
    V(SunionStmt) \
    V(SunionstoreStmt) \
    /*zsetstmt*/V(ZaddStmt) \
    V(ZcardStmt) \
    V(ZcountStmt) \
    V(ZincrbyStmt) \
    V(ZrangeStmt) \
    V(OptZrangeBehavior) \
    V(ZrangebyscoreStmt) \
    V(ZrangebyscoreClause) \
    V(ZrankStmt) \
    V(ZremStmt) \
    V(ZscoreStmt) \
    V(ZunionstoreStmt) \
    V(ZunionstoreClause) \
    V(OptWeightClause) \
    V(OptAggregateClause) \
    V(ZinterstoreStmt) \
    /*connect*/ V(ConnectStmt) \
    V(KeyName) \
    V(KeyStringName) \
    V(KeyHashName)\
    V(KeyListName) \
    V(KeySetName) \
    V(KeyZsetName) \
    V(KeyStringList) \
    V(KeyStringValueList) \
    V(KeyStringValue) \
    V(KeySetList) \
    V(KeyZsetList) \
    V(ValueList) \
    V(KeyValueList) \
    V(KeyValue) \
    V(FieldList) \
    V(DelFieldList) \
    V(FieldName) \
    V(FieldValue) \
    V(ZmemberName) \
    V(ZmemberValue) \
    V(ZmemberValueList) \
    V(SmemberName) \
    V(SmemberNameList) \
    V(FieldValueList) \
    V(Operandnum) \
    V(Identifier) \
    V(Literal) \
    V(StringLiteral) \
    V(BoolLiteral) \
    V(NumLiteral) \
    V(IntLiteral) \
    V(FloatLiteral) \


#define ALLDATATYPE(V) \
	V(DataWhatever) \
	V(DataKeyName) \
    V(DataStringName) \
    V(DataHashName) \
    V(DataFieldName)
    V(DataListName) \
    V(DataSetName) \
    V(DataSmemberName) \
    V(DataZsetName) \
    V(DataZmemberName) \





#define SWITCHSTART \
    switch(case_idx_){ 

#define SWITCHEND \
    default: \
        \
        assert(0); \
        \
    }

#define CASESTART(idx) \
    case CASE##idx: {\


#define CASEEND \
            break;\
        }

#define TRANSLATESTART \
    IR *res = NULL; 

#define GENERATESTART(len) \
    case_idx_ = rand() % len ;

#define GENERATEEND \
    return ;

#define TRANSLATEEND \
     v_ir_collector.push_back(res); \
        \
     return res; 

#define TRANSLATEENDNOPUSH \
     return res; 

#define SAFETRANSLATE(a) \
    (assert(a != NULL), a->translate(v_ir_collector))

#define SAFEDELETE(a) \
    if(a != NULL) a->deep_delete()

#define SAFEDELETELIST(a) \
    for(auto _i: a) \
        SAFEDELETE(_i)

#define OP1(a) \
    new IROperator(a) 

#define OP2(a, b) \
    new IROperator(a,b)

#define OP3(a,b,c) \
    new IROperator(a,b,c)

#define OPSTART(a) \
    new IROperator(a)

#define OPMID(a) \
new IROperator("", a, "")

#define OPEND(a) \
    new IROperator("", "", a)

#define OP0() \
    new IROperator()


#define TRANSLATELIST(t, a, b) \
    res = SAFETRANSLATE(a[0]); \
    res = new IR(t, OP0(), res) ; \
    v_ir_collector.push_back(res); \
    for(int i = 1; i < a.size(); i++){ \
        IR * tmp = SAFETRANSLATE(a[i]); \
        res = new IR(t, OPMID(b), res, tmp); \
        v_ir_collector.push_back(res); \
    }

#define PUSH(a) \
    v_ir_collector.push_back(a)

#define MUTATESTART \
    IR * res = NULL;       \
    auto randint = get_rand_int(3); \
    switch(randint) { \

#define DOLEFT \
    case 0:{ \

#define DORIGHT \
    break; \
    } \
    \
    case 1: { \
     
#define DOBOTH  \
    break; }  \
    case 2:{ \

#define MUTATEEND \
    } \
    } \
    \
    return res; \
    
#endif