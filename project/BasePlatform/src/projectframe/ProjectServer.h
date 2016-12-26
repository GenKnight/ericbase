#ifndef WORKPLAN_PROJECT_SERVER_H_
#define WORKPLAN_PROJECT_SERVER_H_

#include <iostream>
#include <string>
#include <string.h>
#include "Mutex.h"
#include "Thread.h"
#include "ClientSession.h"
#include "../Serverframe/Server.h"
#include "utility/singleton.h"

namespace itstation 
{
	class CProjectServer
		: public utility::singleton<CProjectServer>, public utility::Thread
	{ 
	public: 
        CProjectServer();
        virtual ~CProjectServer();

		void startServer();
		void stopServer();

		void SendMessages( int type, session_ptr ptrSocket, const char* stream, TCP_MSG_HEAD &header );

		//Implement Thread "run" interface
		virtual void OnRun();

	private: 
		bool m_status;

		//config_file_path path
		std::string config_file_path;
		
		ITcpMessageNotify *m_ptrNotify;
		ITcpServer *m_TcpServer;
		ITcpClient *m_TcpClient;

        IAmqAsyncConsumer*	m_amq_future_ctpts_req;

		serverframe::Server m_app_server;
	}; 

}
#endif
