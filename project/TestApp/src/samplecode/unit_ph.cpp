/*****************************************************************************
 base_ph Copyright (c) 2016. All Rights Reserved.

 FileName: base_ph.h
 Version: 1.0
 Date: 2016.09.01

 History:
 zjy     2016.09.01   1.0     Create
 ******************************************************************************/
#include <string>
#include <string.h>
#include <map>
#include <cmath>
#include "unit_ph.h"

unit_ph::unit_ph()
{
}

unit_ph::~unit_ph()
{
}

int unit_ph::start_internal(ph_server_params params_, stock_trade_callback* stc)
{
	int ret = 0;
	stc_ = stc;
	cs_.signal_socket_state_.connect(this, &unit_ph::on_socket_state);
	ret = cs_.connect(params_.server_host.c_str(),params_.server_port);


	return ret;
}

void unit_ph::on_socket_state(base::csocket* cs, int state, void* param)
{
	switch (state) {
	case base::CSOCKET_STATE_CONNECTED:
		printf("CSOCKET_STATE_CONNECTED\n");
		break;
	case base::CSOCKET_STATE_RECV_DATA:
		{
			printf("CSOCKET_STATE_RECV_DATA\n");

			base::mbuffer* recv_buffer = (base::mbuffer*)param;
			qdata qd;
			qd.data = new char[recv_buffer->size() + 1];
			memset(qd.data,0,recv_buffer->size() + 1);
			qd.size = recv_buffer->size();
			memcpy(qd.data, recv_buffer->data() + 16, qd.size-16);			
			stc_->OnReceiveTradeInfo(std::string(qd.data));

			recv_buffer->skip(qd.size);
		}
		break;
	case base::CSOCKET_STATE_DISCONNECTED:
		printf("CSOCKET_STATE_DISCONNECTED");
		break;
	case base::CSOCKET_STATE_CLOSED:
			printf("CSOCKET_STATE_CLOSED");
			break;
	default:
		break;
	}
}