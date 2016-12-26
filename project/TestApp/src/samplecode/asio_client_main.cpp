#include <stdio.h>
#include <iostream>
#include <sstream>
#include <map>
#include <memory>

#include "AsioTcpServer/AsioNetLibrary.h"
#include "utility/Applog.h"
#include "google/protobuf/message.h"
#include "ReqSubSystemInfo.pb.h"
#include "parse.h"

using namespace std;
using namespace itstation;
using namespace google::protobuf;

int asio_main(int argc,char *argv[])
{
    ITcpClient *asio_client = CreateTcpClient("127.0.0.1", 5566, NULL);
    asio_client->StartUp();

    machine::ReqSubSystemInfo req_sub_sysinfo;
    machine::MachineHead *machine_head = req_sub_sysinfo.mutable_machine();
    machine_head->set_ip("192.168.6.66");
    machine_head->set_mac("12:23:56:AB");
    req_sub_sysinfo.set_bissub(10000);
    req_sub_sysinfo.set_userid("Eric");

    for (int i = 0; i < 100; i++) {
        string date_str;
        encode(date_str, req_sub_sysinfo);
        asio_client->SendMessages(date_str);
    }
   
	getchar();
	return 0;
}

