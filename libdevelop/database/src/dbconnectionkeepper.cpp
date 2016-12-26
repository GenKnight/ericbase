/*
 * dbconnectionkeepper.cpp
 *
 *  Created on: Jul 28, 2016
 *      Author: tom
 */

#include "dbconnectionkeepper.h"

namespace naut{

db_connection_keepper::~db_connection_keepper()
{
    if (conn_){
        tradepool_.retconn(conn_);
    }
}

naut::DBCONNECT* db_connection_keepper::get_db_conn()
{
    conn_ = tradepool_.getconn();
    return conn_;
}

} /* namespace order_manager */
