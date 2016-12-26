#include <iostream>
#include "Client.h"

using namespace std;
using namespace utility;

int main_client(int argc,char *argv[])
{
	bool bstop = false;

	client::instance();
	client::getinstance()->start_client();
	while(!bstop) {
		q_sleep(1000);
	}
	client::getinstance()->stop_client();

	getchar();
	return 0;
}

