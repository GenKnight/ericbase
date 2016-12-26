#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>
#include <memory>

#include "LibeventSocket/LibeventSocket.h"
#include "utility/Applog.h"
#include "google/protobuf/message.h"
#include "ReqSubSystemInfo.pb.h"
#include "parse.h"

using namespace std;
using namespace libeventtcp;
using namespace google::protobuf;

int libevent_main(int argc,char *argv[])
{
    ITcpClient *libevet_client = CreateTcpClient("127.0.0.1", 5566, NULL);
    int ret = libevet_client->StartUp();
    if (ret != -1) {
        for (int i = 0; i < 10; i++) {
            machine::ReqSubSystemInfo req_sub_sysinfo;
            machine::MachineHead *machine_head = req_sub_sysinfo.mutable_machine();
            machine_head->set_ip("192.168.6.66");
            machine_head->set_mac("12:23:56:AB");
            req_sub_sysinfo.set_bissub(i);
            req_sub_sysinfo.set_userid("Eric");

            string date_str;
            encode(date_str, req_sub_sysinfo);
            cout << date_str.length() << endl;
            libevet_client->SendMessages(date_str);
        }
    }

    if (libevet_client != NULL) {
        DeleteTcpClient(libevet_client);
    }

	getchar();
	return 0;
}

