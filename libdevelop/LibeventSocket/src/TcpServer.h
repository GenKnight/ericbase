#ifndef LIBEVENT_TCP_SERVER_H_
#define LIBEVENT_TCP_SERVER_H_

#include <map>
#include "utility/Thread.h"
#include "LibeventSocket.h"

namespace libeventtcp
{

	class TcpServer : 
		public ITcpServer, public utility::Thread, public ISocketDisconNotify
	{
	public:
        TcpServer(int port, ILibeventNotify* ptrNotify);
		~TcpServer(void);

		int StartUp( void );	
        void SendMessages(session_ptr ptrSocket, const std::string &stream);
        void SendMessagesALL(const string& stream);

	private:
		static void ListenerCb(struct evconnlistener *, evutil_socket_t, struct sockaddr *, int, void *);

		void AddSocket(TcpSocket* sock);
		void DleSocket();

		virtual void OnDisconNotify(TcpSocket *tcp_sock);

		virtual void OnRun();

	private:
		struct sockaddr_in m_sin;

        ILibeventNotify* m_ptrNotify;
		struct event_base *m_base;
		struct evconnlistener *m_listener;

		utility::SpinLock m_SpinLock;
		std::map< HSocket, TcpSocket* > m_mapclients;
	};

}


#endif


