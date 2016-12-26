#include "TcpClient.h"
#include "utility/include_common.h"

namespace libeventtcp 
{

    TcpClient::TcpClient(const char *ip, int port, ILibeventNotify* ptrNotify)
		: m_ip(ip), m_port(port), m_ptrNotify(ptrNotify), m_base(NULL), m_tcp_socket(NULL)
	{

	}


	TcpClient::~TcpClient(void)
	{
        Stop();
        ShutDown();
        Join();
	}

    void TcpClient::ShutDown()
    {
        if (NULL != m_tcp_socket) {
            delete m_tcp_socket;
            m_tcp_socket = NULL;
        }
    }

	int TcpClient::StartUp( void )
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

		m_tcp_socket = new TcpSocket(m_base, m_ptrNotify, this);
		if (!m_tcp_socket->ConnectServer(m_ip.c_str(), m_port, err)) { 
			event_base_free(m_base);
			m_base = NULL;
			delete m_tcp_socket;
			m_tcp_socket = NULL;
			return -1; 
		}

        Start();

		return 0;
	}

	void TcpClient::SendMessages(const string& stream)
	{
		m_tcp_socket->SendMessages(stream);
	}

	void TcpClient::OnDisconNotify(TcpSocket *tcp_sock)
	{
		printf("Reconnect\n");

		while (1)
		{
			if (ReConnect())
			{
				break;
			}
			q_sleep(3000);
		}

		printf("connect succed\n");
	}

	bool TcpClient::ReConnect()
	{
		std::string err;
		if (!m_tcp_socket->ConnectServer(m_ip.c_str(), m_port, err))
		{
			return false;
		}
		m_tcp_socket->SetInvalid(true);

		return true;
	}

	void TcpClient::OnRun()
	{
        if (event_base_dispatch(m_base) < 0) {
            fprintf(stderr, "Dispatch event error\n");
        }
        if (m_base) {
            event_base_free(m_base);
        }
	}

}
