#include "TcpClient.h"

namespace itstation {

	TcpClient::TcpClient(const char *ip, int port, ITcpMessageNotify* ptrNotify)
		: m_serverAddr(tcp::endpoint(address_v4::from_string(ip), port))
		, m_isConnected(false)
		, m_chkThread(nullptr)
		, m_ptrNotify(ptrNotify)
	{
		m_ptrClient = std::make_shared<clientSession>(m_ioservice, m_ptrNotify);
	}
	TcpClient::~TcpClient()
	{
		Stop();
	}

	void TcpClient::StartUp()
	{
		std::function<void(int)> fr = std::bind(&TcpClient::__HandleRWError, this, std::placeholders::_1);
		m_ptrClient->SetCallBackError(fr);
		//m_ptrClient->SetCallBackError([this](int connid){__HandleRWError(connid); });

		//连接服务端 connect
		m_ptrClient->GetSocket().async_connect(m_serverAddr,
			boost::bind(&TcpClient::__handleConnect, this, boost::asio::placeholders::error));

		Start();
	}

	void TcpClient::__handleConnect(const boost::system::error_code& error)
	{
		if ( error )
		{
			if ( !__IsConnected() )
			{
				__HandleConnectError(error);
			}

			return;
		}
		cout << "connect ok" << endl;
		m_isConnected = true;
		m_ptrClient->StartUp(); //连接成功后发起一个异步读的操作
	}

	void TcpClient::__HandleConnectError( const boost::system::error_code& error )
	{
		if ( !__IsConnected() )
		{
			cout << error.message() << endl;
		}

	}

	void TcpClient::__HandleRWError( int connid )
	{
		m_isConnected = false;
		__CheckConnect();
	}

	void TcpClient::__ThreadReconnect()
	{
		while (1)
		{
			if ( !__IsConnected() )
			{
				//连接服务端 connect
				m_ptrClient->GetSocket().async_connect(m_serverAddr,
					boost::bind(&TcpClient::__handleConnect, this, boost::asio::placeholders::error));
			}

			boost::this_thread::sleep(boost::posix_time::seconds(1));
		}
	}

	void TcpClient::__CheckConnect()
	{
		if (m_chkThread != nullptr)
			return;

		m_chkThread = std::make_shared<boost::thread>(boost::bind(&TcpClient::__ThreadReconnect, this));
	}

	bool TcpClient::__IsConnected() const
	{
		return m_isConnected;
	}

	void TcpClient::SendMessages( const std::string &stream )
	{
		while ( !m_isConnected )
		{
			q_sleep(1000);
		}

		m_ptrClient->SendMessages(stream);
	}

	//void TcpClient::CloseSocket( )
	//{
	//	m_ptrClient->CloseSocket();
	//}

	void TcpClient::OnRun()
	{
		while (IsRuning())
		{
			m_ioservice.run();
			q_sleep(3000);
		}

        cout << "tcpclient close" << endl;
	}
}
