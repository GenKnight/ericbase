#include <iostream>
//#include "occi.h"
//#include "OcciDatabase.h"
#include <iostream>
#include <fspdbmanager.h>

using namespace DBAccess;


using namespace std;
//using namespace Q_Database;

struct TestTable1Data {
	int IntField;
	long LongField;
	unsigned int UIntField;
	float FloatField;
	double DoubleField;
	string StringField1;
	string StringField2;
	CDatetime DatetimeField;
};

class TestTable1Receive : public IReceive {
public:
	virtual void Read(std::vector<Parameters*>& row) {
		TestTable1Data data;
		bool res;
		data.IntField = DynamicTypeCast<SPNumber>(row[0])->Value.ToInt();
		data.LongField = DynamicTypeCast<SPNumber>(row[1])->Value.ToLong();
		data.UIntField = DynamicTypeCast<SPNumber>(row[2])->Value.ToUInt();
		data.FloatField = DynamicTypeCast<SPNumber>(row[3])->Value.ToFloat();
		data.DoubleField = DynamicTypeCast<SPNumber>(row[4])->Value.ToDouble();
		data.StringField1 = DynamicTypeCast<string>(row[5])->Value;
		data.StringField2 = DynamicTypeCast<string>(row[6])->Value;
		data.DatetimeField = DynamicTypeCast<CDatetime>(row[7])->Value;
		
		vec_data_.push_back(data);
	}

	void Print() {
		std::vector<TestTable1Data>::iterator iter = vec_data_.begin();
		stringstream ss;
		for (; iter != vec_data_.end(); ++iter) {
			
			std::cout << iter->IntField << " " << iter->LongField << " "
				<< iter->UIntField << " " << iter->FloatField << " "
				<< iter->DoubleField << " " << iter->StringField1 << " "
				<< iter->StringField2 << " "
				<< iter->DatetimeField.year << "-" << iter->DatetimeField.month << "-" << iter->DatetimeField.day
				<< " " << iter->DatetimeField.hour << ":" << iter->DatetimeField.minute << ":" << iter->DatetimeField.second
				<< "\n";
			
		}

		/*CPPUNIT_ASSERT_MESSAGE(ss.str(), false);*/
	}

private:
	std::vector<TestTable1Data> vec_data_;
};


void TestInsertTestTable1(DBDescription* desc) {
	IStoreProcedure* sp = desc->CreateStoreProcedure("insert_testtable1");
	for (int i = 0; i < 2; ++i) {
		sp->BindIntValue(1, "intparam", i);
		sp->BindLongValue(2, "longparam", 1000);
		sp->BindUIntValue(3, "uintparam", 1000);
		sp->BindFloatValue(4, "floatparam", 1000.1);
		sp->BindDoubleValue(5, "doubleparam", 1000.1);
		sp->BindStringValue(6, "stringparam1", "testt1");
		sp->BindStringValue(7, "stringparam2", "BD00000001");
		CDatetime dt;
		dt.year = 2011;
		dt.month = 12;
		dt.day = 20;
		dt.hour = 10;
		dt.minute = 23;
		dt.second = 10;
		dt.millsecond = 0;
		sp->BindCDatetimeValue(8, "datetimeparam", dt);

		bool ret = sp->Executed();
		if (!ret) {
			cout << sp->GetLastError() << endl;
		}
	}
	desc->ReleaseStoreProcedure(sp);
}

void TestGetOutputTestTable1(DBDescription* desc) {
	IStoreProcedure* sp = desc->CreateStoreProcedure("get_output_testtable1");
	sp->BindIntValue(1, "intparam", 0, EOut);
	sp->BindLongValue(2, "longparam", 1000, EOut);
	sp->BindUIntValue(3, "uintparam", 1000, EOut);
	sp->BindFloatValue(4, "floatparam", 1000.1, EOut);
	sp->BindDoubleValue(5, "doubleparam", 1000.1, EOut);
	sp->BindStringValue(6, "stringparam1", "testt1", EOut);
	sp->BindStringValue(7, "stringparam2", "BD00000001", EOut);
	CDatetime dt;
	dt.year = 2011;
	dt.month = 12;
	dt.day = 20;
	dt.hour = 10;
	dt.minute = 23;
	dt.second = 10;
	dt.millsecond = 0;
	sp->BindCDatetimeValue(8, "datetimeparam", dt, EOut);

	bool ret = sp->Executed();
	if (!ret) {
		std::cout << sp->GetLastError() << std::endl;
	}

	int val;
	sp->BoundIntValue(1, val);
	
	long lval;
	sp->BoundLongValue(2, lval);

	unsigned int uival;
	sp->BoundUIntValue(3, uival);
	
	float fval;
	sp->BoundFloatValue(4, fval);
	
	double dval;
	sp->BoundDoubleValue(5, dval);
	
	string str1;
	sp->BoundStringValue(6, str1);
	
	string str2;
	sp->BoundStringValue(7, str2);

	CDatetime cdt;
	sp->BoundCDatetimeValue(8, cdt);

	cout << val << " " << lval << " " << uival << " " << fval << " "
	     << dval << " " << str1 << " " << str2 << " "
	     << cdt.year << "-" << cdt.month << "-" << cdt.day << " "
	     << cdt.hour << ":" << cdt.minute << ":" << cdt.second;

	desc->ReleaseStoreProcedure(sp);
}

void TestGetTestTable1(DBDescription* desc) {
	IStoreProcedure* sp = desc->CreateStoreProcedure("get_testtable1");

	TestTable1Receive * rec = new TestTable1Receive();
	sp->BindReceive(1, rec);

	bool ret = sp->Executed();
	if (!ret) {
		std::cout << sp->GetLastError()<< std::endl;
	}

	rec->Print();

	desc->ReleaseStoreProcedure(sp);
}

struct SecurityTypeData {
	string SECURITY_TYPE_CD;
	string SECURITY_TYPE_GROUP;
	string SECURITY_TYPE_ENG_DESC;
	string SECURITY_TYPE_DESC;
	CDatetime EFFECTIVE_DATE;
	CDatetime EXPIRATION_DATE;
	string STATUS;
	CDatetime LAST_UPDATE_TIME;
	string LAST_UPDATE_USER;
};

class SecurityType {
protected:
	SecurityTypeData data_;

public:
	SecurityType() { }

	inline const string &get_security_type() const { return data_.SECURITY_TYPE_CD; }
	inline const string &get_security_type_group() const { return data_.SECURITY_TYPE_GROUP; }
	inline const string &get_security_type_end_desc() const { return data_.SECURITY_TYPE_ENG_DESC; }
	inline const string &get_security_type_desc() const { return data_.SECURITY_TYPE_DESC; }
	inline const CDatetime &get_effect_date() const { return data_.EFFECTIVE_DATE; }
	inline const CDatetime &get_expire_date() const { return data_.EXPIRATION_DATE; }
	inline const string &get_status() const { return data_.STATUS; }
	inline const CDatetime &get_updt_time() const { return data_.LAST_UPDATE_TIME; }
	inline const string &get_updt_user() const { return data_.LAST_UPDATE_USER; }
};

class SecurityTypeFeeder : public SecurityType{
public:
	SecurityTypeFeeder();
	SecurityTypeFeeder(const string&,const string&,const string&,const string&,const CDatetime&,const CDatetime&,const string&,const CDatetime&,const string&);
	
	inline void set_security_type(string);
	inline void set_security_type_group(string);
	inline void set_security_type_end_desc(string);
	inline void set_security_type_desc(string);
	inline void set_effect_date(CDatetime);
	inline void set_expire_date(CDatetime);
	inline void set_status(string);
	inline void set_updt_time(CDatetime);
	inline void set_updt_user(string);

};

SecurityTypeFeeder::SecurityTypeFeeder():SecurityType() {
}

SecurityTypeFeeder::SecurityTypeFeeder(const string& var1, 
									   const string& var2, 
									   const string& var3, 
									   const string& var4, 
									   const CDatetime& var5, 
									   const CDatetime& var6, 
									   const string& var7, 
									   const CDatetime& var8, 
									   const string& var9) {
	set_security_type(var1);
	set_security_type_group(var2);
	set_security_type_end_desc(var3);
	set_security_type_desc(var4);
	set_effect_date(var5);
	set_expire_date(var6);
	set_status(var7);
	set_updt_time(var8);
	set_updt_user(var9);
}


inline void SecurityTypeFeeder::set_security_type(string var) {
    data_.SECURITY_TYPE_CD = var;
}

inline void SecurityTypeFeeder::set_security_type_group(string var) {
    data_.SECURITY_TYPE_GROUP = var;
}

inline void SecurityTypeFeeder::set_security_type_end_desc(string var) {
    data_.SECURITY_TYPE_ENG_DESC = var;
}

inline void SecurityTypeFeeder::set_security_type_desc(string var) {
    data_.SECURITY_TYPE_DESC = var;
}

inline void SecurityTypeFeeder::set_effect_date(CDatetime var) {
    data_.EFFECTIVE_DATE = var;
}

inline void SecurityTypeFeeder::set_expire_date(CDatetime var) {
    data_.EXPIRATION_DATE = var;
}

inline void SecurityTypeFeeder::set_status(string var) {
    data_.STATUS = var;
}

inline void SecurityTypeFeeder::set_updt_time(CDatetime var) {
    data_.LAST_UPDATE_TIME = var;
}

inline void SecurityTypeFeeder::set_updt_user(string var) {
    data_.LAST_UPDATE_USER = var;
}


class SecurityTypeFeederReceive : public IReceive {
public:
	virtual void Read(std::vector<Parameters*>& row) {
		SecurityTypeFeeder* data = new SecurityTypeFeeder();
		bool res;
		try{
			data->set_security_type(DynamicTypeCast<string>(row[0])->Value);

			data->set_security_type_group(DynamicTypeCast<string>(row[1])->Value);

			data->set_security_type_end_desc(DynamicTypeCast<string>(row[2])->Value);

			data->set_security_type_desc(DynamicTypeCast<string>(row[3])->Value);

			data->set_effect_date(DynamicTypeCast<CDatetime>(row[4])->Value);

			data->set_expire_date(DynamicTypeCast<CDatetime>(row[5])->Value);

			data->set_status(DynamicTypeCast<string>(row[6])->Value);

			data->set_updt_time(DynamicTypeCast<CDatetime>(row[7])->Value);

			data->set_updt_user(DynamicTypeCast<string>(row[8])->Value);
		}catch(ParamerterCastException& ex){
			std::cout << ex.what() << std::endl;
		}
		vec_data_.push_back(data);
	}

	void Print() {
		std::vector<SecurityTypeFeeder*>::iterator iter = vec_data_.begin();
		stringstream ss;
		for (; iter != vec_data_.end(); ++iter) {
			
			ss << (*iter)->get_effect_date() << " " << (*iter)->get_expire_date() << " "
				<< (*iter)->get_security_type() << " " << (*iter)->get_security_type_desc() << " "
				<< (*iter)->get_security_type_end_desc() << " " << (*iter)->get_security_type_group() << " "
				<< (*iter)->get_status() << " "
				<< (*iter)->get_updt_time() << " "
				<< (*iter)->get_updt_user() << " "
				<< "\n";
			
		}

		ss << "count:" << vec_data_.size();

		std::cout << ss.str();
	}




private:
	std::vector<SecurityTypeFeeder*> vec_data_;
};

void TestGET_FND_SECURITY_TYPE(DBDescription* desc) {
	IStoreProcedure* sp = desc->CreateStoreProcedure("GET_FND_SECURITY_TYPE");

	SecurityTypeFeederReceive * rec = new SecurityTypeFeederReceive();
	sp->BindReceive(1, rec);

	bool ret = sp->Executed();
	if (!ret) {
		desc->ReleaseStoreProcedure(sp);
	}

	rec->Print();


	delete rec;

	std::cout << sp->GetLastError() << std::endl;
	desc->ReleaseStoreProcedure(sp);
}

void TestText(DBDescription* desc) {
	IStoreProcedure* sp = desc->CreateStoreProcedure("insert_texttable");
	string str;
	for (int i =0; i < 10000; ++i) {
		str += "111111";
	}
        sp->BindStringValue(1, "textparam", str);

        bool ret = sp->Executed();
        if (!ret) {
                desc->ReleaseStoreProcedure(sp);
        }

        std::cout << sp->GetLastError() << std::endl;
        desc->ReleaseStoreProcedure(sp);

}

class TextReceive : public IReceive {
public:
	void Read(std::vector<Parameters*>& row) {
		string text = DynamicTypeCast<string>(row[0])->Value;

		std::cout << text << std::endl;
	}
};

void GetText(DBDescription* desc) {
	IStoreProcedure* sp = desc->CreateStoreProcedure("get_texttable");

        TextReceive * rec = new TextReceive();
        sp->BindReceive(1, rec);

        bool ret = sp->Executed();
        if (!ret) {
                desc->ReleaseStoreProcedure(sp);
        }


        delete rec;

        std::cout << sp->GetLastError() << std::endl;
        desc->ReleaseStoreProcedure(sp);
	
}

int main()
{
	DBManager* dbmanager_ = DBManager::CreateInstance();
	DBDescription* desc = dbmanager_->CreateDBDesc("../db.conf");

	//TestInsertTestTable1(desc);
	//TestGetOutputTestTable1(desc);
	//TestGET_FND_SECURITY_TYPE(desc);
	TestText(desc);
	//GetText(desc);	
delete desc;

	 return 0;
}
