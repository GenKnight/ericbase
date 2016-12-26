#ifndef LIBEVENT_TCP_LIBRARY_H_
#define LIBEVENT_TCP_LIBRARY_H_

#include "utility/Global.h"
#include "TcpSocket.h"

namespace libeventtcp
{

	class ITcpServer
	{ 
	public:

		virtual ~ITcpServer(){};

		virtual int StartUp( void ) = 0;
        virtual void SendMessages(session_ptr ptrSocket, const std::string &stream) = 0;
        virtual void SendMessagesALL(const std::string& stream) = 0;

	};

	class ITcpClient
	{ 
	public:

		virtual ~ITcpClient(){};

		virtual int StartUp( void ) = 0;
        virtual void SendMessages(const std::string &stream) = 0;
	};

	extern "C"
	{
        COMMON_API ITcpServer * CreateTcpServer(int port, ILibeventNotify * ptrNotify);

        COMMON_API ITcpClient * CreateTcpClient(const char *ip, int port, ILibeventNotify * ptrNotify);

		COMMON_API void DeleteTcpServer( ITcpServer * ptrObj );

		COMMON_API void DeleteTcpClient( ITcpClient * ptrObj );
	}

}
#endif
