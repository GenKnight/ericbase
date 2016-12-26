/***************************************************************************** 
A50-ZD Module Copyright (c) 2015. All Rights Reserved. 
FileName: unidbpool.cpp
Version: 1.0 
Date: 2015.10.25 
History: cwm     2015.10.25   1.0     Create 
******************************************************************************/

#include "unidbpool.h"
#include "base/trace.h"
#include "stdio.h"

namespace naut
{

db_conn_pool::db_conn_pool()
{
    m_nconns = 5;
    m_rwlock = new base::rwlock;
    m_vec_conn.clear();
    db_ = NULL;
    m_alarm_ = NULL;
}

db_conn_pool::~db_conn_pool()
{
    if(m_alarm_ != NULL) {
        m_alarm_->turn_off();
        delete m_alarm_;
        m_alarm_ = NULL;
    }

    release_all_conns();

    if(m_rwlock)
    {
        delete m_rwlock;
        m_rwlock = NULL;
    }

    if(db_)
    {
    	delete db_;
    	db_ = NULL;
    }

}

int db_conn_pool::init_db_conn()
{
    {
        base::write_lock_scope wl(m_rwlock);
        m_vec_conn.clear();
        db_ = new naut::unidb(m_stype);
        int ret = db_->open(m_param);
        if(ret != 0)
        {
            TRACE_ERROR("unidbpool",10000,"open database error:%d\n",ret);
            delete db_;
            db_ = NULL;
            return ret;
        }

        for(int i=0;i<m_nconns;i++)
        {
            DBCONNECT* dbconn = createconn();
            if(dbconn != NULL)
            {
                m_vec_conn.push_back(dbconn);
            }
        }
    }

    return m_vec_conn.size() > 0 ? 0: -1;
}

int db_conn_pool::init(naut::unidb_param param,int nconns,std::string &stype, std::string switch_time)
{
    m_param = param;
    m_nconns = nconns;
    m_stype = stype;

    base::alarm_info alarminfo;
    if(switch_time != "") {
        sscanf(switch_time.c_str(), "%d:%d:%d", &alarminfo.hour, &alarminfo.minute, &alarminfo.second);
    } else {
        alarminfo.hour = 4;
        alarminfo.minute = 0;
        alarminfo.second = 0;
    }
    m_alarm_ = new base::alarm(alarminfo.hour, alarminfo.minute, alarminfo.second);
    m_alarm_->signal_alarm_.connect(this, &db_conn_pool::alarm_callback);
    m_alarm_->turn_on();

    return init_db_conn();

}

DBCONNECT* db_conn_pool::getconn()
{
    base::write_lock_scope wl(m_rwlock);

    int i=0;
    for(i=0;i<(int)m_vec_conn.size();i++)
    {
        if(m_vec_conn[i] != NULL && m_vec_conn[i]->_status == IDLE)
        {
            if(m_vec_conn[i]->_conn->connected() == false)
            {
                m_vec_conn[i]->_status = EXCEPTION;
                continue;
            }
            m_vec_conn[i]->_status = USE;
            return m_vec_conn[i];
        }
    }

    if(i>=(int)m_vec_conn.size())
    {
        for(int j=0;j<5;j++)
        {
            DBCONNECT *dbconn = createconn();
            if(dbconn == NULL)
            {
                continue;
            }

            dbconn->_status = USE;
            m_vec_conn.push_back(dbconn);

            return dbconn;
        }
    }

    return NULL;
}

void db_conn_pool::retconn(DBCONNECT *dbconn)
{
	base::write_lock_scope wl(m_rwlock);

    if(dbconn == NULL)
    {
        return;
    }

    //20151111 david wang
    if(dbconn->_conn->is_transaction()) {
    	if(!dbconn->_conn->rollback()) {
    		TRACE_ERROR("unidbpool",10000,"rollback database error!\n");
    	}
    }


    for(int i=0;i<(int)m_vec_conn.size();i++)
    {
        if(m_vec_conn[i] == dbconn)
        {
            m_vec_conn[i]->_status = IDLE;
        }
    }
}

void db_conn_pool::release_all_conns()
{
	base::write_lock_scope wl(m_rwlock);

    for(int i=0;i<(int)m_vec_conn.size();i++)
    {
        if(m_vec_conn[i] != NULL)
        {
            if(m_vec_conn[i]->_conn != NULL)
            {
                m_vec_conn[i]->_conn->release_conn();
                delete m_vec_conn[i]->_conn;
                m_vec_conn[i]->_conn = NULL;
            }

            delete m_vec_conn[i];
            m_vec_conn[i] = NULL;
        }
    }
}

DBCONNECT* db_conn_pool::createconn()
{
    int ret = 0;
    
    DBCONNECT* dbconn = new DBCONNECT;

    dbconn->_conn = new naut::unidb_conn(db_);

    if(!dbconn->_conn->init_conn())
    {
        TRACE_ERROR("unidbpool",10000,"initialize unidb conn failed:%d\n", dbconn->_conn->get_errno());
        delete dbconn->_conn;
        dbconn->_conn = NULL;
        delete dbconn;
        dbconn = NULL;
        return NULL;
    }

    dbconn->_status = IDLE;
    
    return dbconn;
}

void db_conn_pool::alarm_callback(base::alarm_info& ainfo, struct tm* t)
{
    TRACE_SYSTEM("unidbpool", "db_conn_pool on alarm now~~~");
    release_all_conns();
    int ret = init_db_conn();
    if(ret != 0) {
        TRACE_ERROR("unidbpool", 10000, "init db pool failed :%d", ret);
    }
}

}

