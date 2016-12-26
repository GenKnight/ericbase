/*****************************************************************************
 base_ph Copyright (c) 2016. All Rights Reserved.

 FileName: base_ph.h
 Version: 1.0
 Date: 2016.09.01

 History:
 zjy     2016.09.01   1.0     Create
 ******************************************************************************/

#ifndef UNIT_PH_H_
#define UNIT_PH_H_

#include <map>
#include <string>
#include "base/socket_client.h"
#include "base/mbuffer.h"
#include "base/sigslot.h"

struct ph_server_params
{
	std::string server_host;
	int server_port;
	std::string site;
	std::string station;
	std::string user;
	std::string password;
};

struct qdata
{
	char* data;
	int size;
};

class stock_trade_callback
{
public:
	virtual int OnReceiveTradeInfo(std::string& data) = 0;
};

class unit_ph
	:public sigslot::has_slots<>
{
public:
	unit_ph();
	~unit_ph();

public:
	int start_internal(ph_server_params params_, stock_trade_callback* stc);
	void on_socket_state(base::csocket* cs, int state, void* param);

private:
	stock_trade_callback* stc_;
	base::csocket cs_;
};
#endif /* UNIT_PH_H_ */
