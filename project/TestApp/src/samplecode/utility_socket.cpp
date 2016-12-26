#include <iostream>
#include <stdio.h>
#include <string>
#include "utility/QServerSocket.h"
#include "utility/QAddress.h"
#include "utility/QClientSocket.h"

using namespace std;
using namespace utility;

int main_utility_socket(int argc,char *argv[])
{
	QAddress address;
	address.host_name = "127.0.0.1";
	address.port = "8523";

	QServerSocket server;
	server.bindingAddr(address);

	server.listenConnection(10);

	QClientSocket* client = server.acceptClient();
	string data = "server utility socket";
	client->sendData(data);

	client->receiveData(data);

	cout << "receiveData:" << data << endl;
	getchar();
	return 0;
}

