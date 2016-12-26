#include <iostream>
#include <stdio.h>
#include <string>
#include "unit_ph.h"

using namespace std;

class trade_unit
	: public stock_trade_callback
{
public:
	trade_unit()
	{
		string data;
		ph_server_params param;
		param.server_host = "127.0.0.1";
		param.server_port = 8523;

		trade_up.start_internal(param, this);
	};
	virtual ~trade_unit(){};

protected:
	/* stock_trade_callback */
	virtual int OnReceiveTradeInfo(std::string& data)
	{
		cout << "receiveData:" << data << endl;

		return 0;
	}
private:
	unit_ph trade_up;
};

int main(int argc,char *argv[])
{
	string data;
	trade_unit unit_object;

	//cout << "receiveData:" << data << endl;
	getchar();
	return 0;
}

