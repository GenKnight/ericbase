#include "TcpServer.h"
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <string.h>

namespace libeventtcp 
{

    TcpServer::TcpServer(int port, ILibeventNotify* ptrNotify)
		: m_ptrNotify(ptrNotify), m_base(NULL), m_listener(NULL)
	{
		memset(&m_sin, 0, sizeof(m_sin));
		m_sin.sin_family = AF_INET;
		m_sin.sin_port = htons(port);
	}

	TcpServer::~TcpServer(void)
	{
        Stop();
		DleSocket();
		if (NULL != m_base) { 
			//event_base_loopexit(m_base, NULL); 
			if (NULL != m_listener) { 
				evconnlistener_free(m_listener); 
			}
			event_base_free(m_base);
			m_base = NULL;
		}	
	}

	int TcpServer::StartUp( void )
	{
		string err;
		if (!TcpSocket::WinStartUp(err)) { 
            return -1; 
        }

		if (!m_base) {
			m_base = event_base_new();
			if (!m_base) {
				err = "Could not create event_base";
				return -1;
			}
		}

		if (!m_listener) {
			m_listener = evconnlistener_new_bind(m_base, ListenerCb, (void *)this,
				LEV_OPT_REUSEABLE|LEV_OPT_CLOSE_ON_FREE, -1, (struct sockaddr*)&m_sin, sizeof(m_sin));
			if (!m_listener) {
				err = "Could not create evconnlistener";
				return -1;
			}
		}

		Start();

		return 0;
	}

	void TcpServer::ListenerCb(struct evconnlistener *listener, evutil_socket_t fd, struct sockaddr *sa, int socklen, void *user_data)
	{
		printf("new connect: %d\n", fd);

		TcpServer *this_ptr = (TcpServer*)user_data;

		TcpSocket* tcp_sock = new TcpSocket(this_ptr->m_base, this_ptr->m_ptrNotify, this_ptr);

		std::string err;
		/*����0�Ļ���������������ϵͳ��������socket�������Ŀ�����Ӱ�죬
		������ socket ��send�ڻ����������᷵�� 10035
		*/
		if (!tcp_sock->SetBufSize(fd, false, 1024 * 10000, err))
		{
			fprintf(stderr, err.c_str());
			return;
		}

		if (!tcp_sock->SetBufferevent(fd, err))
		{
			fprintf(stderr, err.c_str());
			return;
		}

		this_ptr->AddSocket(tcp_sock);
	}

	void TcpServer::SendMessagesALL( const std::string& stream)
	{
		utility::Locker locker(&m_SpinLock);
		for ( auto it = m_mapclients.begin(); it != m_mapclients.end(); it++ )
		{
			(it->second)->SendMessages(stream);
		}
	}

    void TcpServer::SendMessages(session_ptr ptrSocket, const std::string &stream)
    {
        ptrSocket->SendMessages(stream);
    }

	void TcpServer::AddSocket(TcpSocket* sock)
	{
		utility::Locker locker(&m_SpinLock);
		m_mapclients[sock->GetSocket()] = sock;
	}

	void TcpServer::DleSocket()
	{
		utility::Locker locker(&m_SpinLock);
		auto iter = m_mapclients.begin();
		while (iter != m_mapclients.end()) {
			if (!(iter->second)->GetInvalid()) {
				auto tmp = iter;
				delete (tmp->second);
				(tmp->second) = NULL;
				m_mapclients.erase( iter++ );
			} else {
				iter++;
			}
		}
	}

	void TcpServer::OnDisconNotify(TcpSocket *tcp_sock)
	{
		DleSocket();	//ɾ����Чsocket
	}

	void TcpServer::OnRun()
	{
        if (event_base_dispatch(m_base) < 0) {
            fprintf(stderr, "event_base_dispatch error\n");
        }
	}
}
