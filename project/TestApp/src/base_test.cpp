#include <iostream>
#include <sstream>
#include <map>
#include <signal.h>
#include <stdio.h>
#include <memory>
#include <vector>
#include <set>
#include <assert.h>
#include <queue> 
#include <functional>
#include <numeric>

#include "base/dictionary.h"
#include "base/dtrans.h"
#include "base/alarm.h"
#include "base/pugixml.h"
#include "base/log_binder.h"

#include <fstream>
#include "jsoncpp/include/json/json.h"

#include <log4cplus/logger.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/layout.h>
#include <log4cplus/ndc.h>
#include <log4cplus/mdc.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/thread/threads.h>
#include <log4cplus/helpers/sleep.h>
#include <log4cplus/loggingmacros.h>
#include <iostream>
#include <string>

#include "database/dbconnectionkeepper.h"

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

using namespace std;

class A : public sigslot::has_slots<>
{
public:
	void alarm_callback(base::alarm_info& ainfo,struct tm* t)
	{
		cout << "call back" << endl;
	}
};

struct db_info
{
	std::string dbtype;              //db类型 eg：mysql
	naut::unidb_param dbparam;
};

int main_base(int argc,char *argv[])
{
	int ret = -1;

	pugi::xml_document config;
	if(!config.load_file("./httpmanager-config.xml"))
	{
		cout << "xml error" << endl;
	}

	pugi::xml_node xdb = config.child("http_manager").child("db");


	db_info dbinfo_;                        //db信息
	//db info
	std::string tmp;
	tmp = xdb.child("type").text().as_string();
	dbinfo_.dbtype = tmp;

	tmp = xdb.child("host").text().as_string();
	dbinfo_.dbparam.host = tmp;

	tmp = xdb.child("port").text().as_string();
	dbinfo_.dbparam.port = atoi(tmp.c_str());

	tmp = xdb.child("user").text().as_string();
	dbinfo_.dbparam.user = tmp;

	tmp = xdb.child("pwd").text().as_string();
	//base::aes rsapwd;
	//eplain = rsapwd.decrypt_base64(tmp.c_str(), tmp.length());
	dbinfo_.dbparam.password = tmp;

	tmp = xdb.child("dbname").text().as_string();
	dbinfo_.dbparam.database_name = tmp;

	tmp = xdb.child("charset").text().as_string();
	dbinfo_.dbparam.charset = tmp;

	dbinfo_.dbparam.create_database_if_not_exists = false;
	dbinfo_.dbparam.recreate_database_if_exists = false;

	naut::db_conn_pool tradepool_;          //交易数据库连接池
	ret = tradepool_.init(dbinfo_.dbparam,2, dbinfo_.dbtype);

	naut::db_connection_keepper db_keepper(tradepool_);
    naut::DBCONNECT* dbconn = db_keepper.get_db_conn();
	char sql[1024]={0};
	sprintf(sql,"select * from %s", "holidays");


	if(dbconn->_conn->query(sql)) {
		while(dbconn->_conn->fetch_row()) {
			cout << dbconn->_conn->get_string("holiday") << endl;
		}
	}

#if 0
	std::string log_config_file = "./log-config.xml";
	/* bind trace base log config file */
	if (!base::default_log_binder::bind_trace(log_config_file.c_str())) {
		printf("x6server bind trace failed\n");
	}
	base::trace::enable_std_output(false);

	TRACE_SYSTEM("SolutionSample","hello log:%s", "hello eric");

	cout << "Entering main()..." << endl;
	log4cplus::initialize ();
	LogLog::getLogLog()->setInternalDebugging(true);
	try {
		SharedObjectPtr<Appender> append_1(new ConsoleAppender());
		append_1->setName(LOG4CPLUS_TEXT("First"));

		log4cplus::getMDC ().put (LOG4CPLUS_TEXT ("key"),
			LOG4CPLUS_TEXT ("MDC value"));
		log4cplus::tstring pattern = LOG4CPLUS_TEXT("%d{%m/%d/%y %H:%M:%S,%Q} [%t] %-5p %c{2} %%%x%% - %X{key} - %m [%l]%n");
		//	std::tstring pattern = LOG4CPLUS_TEXT("%d{%c} [%t] %-5p [%.15c{3}] %%%x%% - %m [%l]%n");
		append_1->setLayout( std::auto_ptr<Layout>(new PatternLayout(pattern)) );
		Logger::getRoot().addAppender(append_1);

		Logger logger = Logger::getInstance(LOG4CPLUS_TEXT("test.a.long_logger_name.c.logger"));
		LOG4CPLUS_DEBUG(logger, "This is the FIRST log message...");

		sleep(1, 0);
		{
			NDCContextCreator ndc(LOG4CPLUS_TEXT("second"));
			LOG4CPLUS_INFO(logger, "This is the SECOND log message...");
		}

		sleep(1, 0);
		LOG4CPLUS_WARN(logger, "This is the THIRD log message...");

		sleep(1, 0);
		LOG4CPLUS_ERROR(logger, "This is the FOURTH log message...");

		sleep(1, 0);
		LOG4CPLUS_FATAL(logger, "This is the FIFTH log message...");
	}
	catch(...) {
		cout << "Exception..." << endl;
		Logger::getRoot().log(FATAL_LOG_LEVEL, LOG4CPLUS_TEXT("Exception occured..."));
	}

	cout << "Exiting main()..." << endl;

	base::dictionary dict;
	dict["one"] = 100;
	
	cout << base::djson::dict2str(dict) << endl;

	std::string strValue = "{\"hello\":99.99,\"jsonarray\":[{\"one\":\"value1\"},{\"two\":\"value2\"},{\"three\":3}]}";

	Json::Reader reader;
	Json::Value value;

	if (reader.parse(strValue, value)) {
		for (auto it = value.begin(); it!=value.end(); it++) {
			cout << it.key().asString() << " ";

			if ( value[it.key().asString()].isArray() ) {

				Json::Value temp = value[it.key().asString()];
				for (int i = 0; i < temp.size(); i++) {
					for ( auto it = temp[i].begin(); it != temp[i].end(); it++ ) {

						cout<< it.key().asString() <<" "<< (*it).asString() << endl;
					}
					
				}
			} else {
				cout << value[it.key().asString()].asDouble() << endl;
			}
		}
	}

	cout<<"测试json写入"<<endl;
	Json::Value jsonRoot;
	Json::Value jsonItem;
	jsonItem["item1"] = "第一个条目";
	jsonItem["item2"] = "第二个条目";
	jsonItem["item3"] = 3;
	jsonRoot.append(jsonItem);
	jsonItem.clear();//清除上面已经赋值的项
	jsonItem["First"]="1";
	jsonItem["Second"]=2;
	jsonItem["Third"]=3.0F;
	jsonRoot.append(jsonItem);
	cout<<jsonRoot.toStyledString()<<endl;

	cout<<"测试json写入到文件"<<endl;

	ofstream ofs;
	ofs.open("F:/EricBase/bin/Debug/test1.json");
	ofs<<jsonRoot.toStyledString();
	ofs.close();

	cout<<"测试json读取"<<endl;
	string sJson = jsonRoot.toStyledString();
	jsonRoot.clear();
	Json::Reader jsonReader;
	if (!jsonReader.parse(sJson,jsonRoot)) {
		return -1;
	}
	for (auto it = jsonRoot.begin(); it!=jsonRoot.end(); it++) {
		for (auto sit = it->begin(); sit != it->end(); sit++) {
			cout<<sit.key() <<" "<<sit->asString() <<endl;
		}
	}
	cout<<"测试读取json文件"<<endl;
	ifstream ifs;
	ifs.open("J:/EricBase/bin/Debug/test1.json");

	jsonRoot.clear();
	if (!jsonReader.parse(ifs, jsonRoot)) {
		return -1;
	}
	ifs.close();
	for (auto it = jsonRoot.begin(); it!=jsonRoot.end(); it++) {
		for (auto sit = it->begin(); sit != it->end(); sit++) {
			cout<<sit.key() <<" "<<sit->asString() <<endl;
		}
	}

#endif
	getchar();
	return 0;
}

