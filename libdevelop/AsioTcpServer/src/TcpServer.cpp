#include "TcpServer.h"
#include <numeric>
#include <functional>
namespace itstation {

	TcpServer::TcpServer( int port, ITcpMessageNotify* ptrNotify )
		: m_acceptor(m_ioservice, tcp::endpoint(tcp::v4(), port))
		, m_listCnnIdPool(MaxConnectionNum)
		, m_ptrNotify(ptrNotify)
		
	{
		m_listCnnIdPool.resize(MaxConnectionNum);
		std::iota(m_listCnnIdPool.begin(), m_listCnnIdPool.end(), 1);
	}
	TcpServer::~TcpServer()
	{
		Stop();
	}

	void TcpServer::OnRun()
	{
		while (IsRuning())
		{
			m_ioservice.run();
		}
	}

	void TcpServer::__ClientCallBackError(int connId)
	{
		utility::Locker locker(&m_SpinLock);
		auto it = m_mapClients.find(connId);
		if ( it != m_mapClients.end() )
		{
			m_mapClients.erase(it);
		}

		m_listCnnIdPool.push_back(connId);
	}

	itstation::session_ptr TcpServer::__CreateClient()
	{
		int connId = -1;
		{
			utility::Locker locker(&m_SpinLock);

			if ( m_listCnnIdPool.empty() )
			{
				return nullptr;
			}

			connId = m_listCnnIdPool.front();
			m_listCnnIdPool.pop_front();
		}

		session_ptr client = std::make_shared<clientSession>(m_ioservice, m_ptrNotify);
		client->SetConnId(connId);

		std::function<void(int)> fr = std::bind(&TcpServer::__ClientCallBackError, this, std::placeholders::_1);
		client->SetCallBackError(fr);

		//client->SetCallBackError([this](int connid){__ClientCallBackError(connid); });

		return client;
	}

	void TcpServer::StartUp()
	{
		session_ptr new_session = __CreateClient();

		if ( new_session == nullptr )
		{
			return;
		}

		m_acceptor.async_accept(new_session->GetSocket(),
			boost::bind(&TcpServer::__handle_accept,this,
			boost::asio::placeholders::error, new_session));

		Start();
	}

	void TcpServer::__handle_accept(const boost::system::error_code& error, session_ptr session)
	{
		if (error)
		{
			cout << error.value() << " " << error.message() << endl;
			session->CloseSocket();
			__StopAccept();
		} else
		{
			{
				utility::Locker locker(&m_SpinLock);
				m_mapClients.insert(std::make_pair(session->GetConnId(), session));
			}
			cout << "current connect count: " << m_mapClients.size() << endl;

			session->StartUp();

			StartUp();
		}
	}

	void TcpServer::__StopAccept()
	{
		boost::system::error_code ec;
		m_acceptor.cancel(ec);
		m_acceptor.close(ec);
		m_ioservice.stop();
	}

	void TcpServer::SendMessages( session_ptr ptrSocket, const std::string &stream )
	{
		ptrSocket->SendMessages(stream);
	}

	//void TcpServer::CloseSocket( )
	//{
	//	common::Locker locker(&m_SpinLock);
	//	for ( auto it = m_mapClients.begin(); it != m_mapClients.end(); it++ )
	//	{
	//		(it->second)->CloseSocket();
	//	}

	//	__StopAccept();
	//}
}
