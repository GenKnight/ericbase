#ifndef LIBEVENT_TCP_CLIENT_H_
#define LIBEVENT_TCP_CLIENT_H_

#include "utility/Thread.h"
#include "LibeventSocket.h"

namespace libeventtcp
{

	class TcpClient : 
		public ITcpClient, public utility::Thread, public ISocketDisconNotify
	{
	public:
        TcpClient(const char *ip, int port, ILibeventNotify* ptrNotify = NULL);
		~TcpClient(void);

		int StartUp( void );
		void ShutDown();

		void SendMessages(const std::string& stream);

	private:
		bool ReConnect();
		virtual void OnDisconNotify(TcpSocket *tcp_sock);

		virtual void OnRun();

	private:
		std::string m_ip;
		int m_port;
        ILibeventNotify* m_ptrNotify;

		struct event_base *m_base;
		TcpSocket* m_tcp_socket;

	};

}

#endif

