#include <iostream>
#include "Service.h"

using namespace std;
using namespace utility;

int main_server(int argc,char *argv[])
{
	bool bstop = false;

	server::instance();
	server::getinstance()->start_server();
	while(!bstop) {
		q_sleep(1000);
	}
	server::getinstance()->stop_server();

	getchar();
	return 0;
}

