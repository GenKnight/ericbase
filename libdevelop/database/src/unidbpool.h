/***************************************************************************** 
A50-ZD Module Copyright (c) 2015. All Rights Reserved. 
FileName: unidbpool.h
Version: 1.0 
Date: 2015.10.25 
History: cwm     2015.10.25   1.0     Create 
******************************************************************************/

#ifndef _UNIDB_POOL_H_
#define _UNIDB_POOL_H_

#include <vector>
#include <string>
#include "unidb.h"
#include "base/lock.h"
#include "base/alarm.h"
#include "base/sigslot.h"

using namespace std;

// david 20151112
//enum STATUS
//{
//  USE = 0,
//  IDLE = 1,
//  EXCEPTION = 2
//};

namespace naut
{	
//david 20151112
enum STATUS
{
  USE = 0,
  IDLE = 1,
  EXCEPTION = 2
};

struct DBCONNECT
{
    naut::unidb_conn* _conn;
    int _status;

    DBCONNECT()
    {
        _conn = NULL;
        _status = IDLE;
    }
};

class COMMON_API db_conn_pool : public sigslot::has_slots<>
{
public:
    db_conn_pool();
    ~db_conn_pool();
public:
    int init(naut::unidb_param param,int nconns,std::string &stype, std::string switch_time = "");
    DBCONNECT* getconn();
    void release_all_conns();
    void retconn(DBCONNECT *dbconn);
    void alarm_callback(base::alarm_info& ainfo, struct tm* t);

private:
    DBCONNECT* createconn();
    int init_db_conn();
private:
    vector<DBCONNECT*> m_vec_conn;
    int m_nconns;
    naut::unidb* db_;

    naut::unidb_param m_param;
    std::string m_stype;

    base::rwlock* m_rwlock;
    base::alarm* m_alarm_;
};

}

#endif //_UNIDB_POOL_H_
