/*
 * dbconnectionkeepper.h
 *
 *  Created on: Jul 28, 2016
 *      Author: tom
 */

#ifndef MODULES_SIGMA_TM_STOCK_SOURCE_ORDER_MANAGER_SRC_DBCONNECTIONKEEPPER_H_
#define MODULES_SIGMA_TM_STOCK_SOURCE_ORDER_MANAGER_SRC_DBCONNECTIONKEEPPER_H_
#include "unidbpool.h"

namespace naut{

class COMMON_API db_connection_keepper
{
public:
    explicit db_connection_keepper(naut::db_conn_pool &pool_):tradepool_(pool_),conn_(0){};
    naut::DBCONNECT* get_db_conn();
    virtual ~db_connection_keepper();
private:
    naut::db_conn_pool &tradepool_;
    naut::DBCONNECT* conn_;
};

} /* namespace order_manager */

#endif /* MODULES_SIGMA_TM_STOCK_SOURCE_ORDER_MANAGER_SRC_DBCONNECTIONKEEPPER_H_ */
