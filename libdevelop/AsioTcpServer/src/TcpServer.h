#ifndef TCP_SERVER_H_
#define TCP_SERVER_H_

#include <unordered_map>
#include <list>
#include "AsioNetLibrary.h"
#include "utility/Thread.h"

namespace itstation 
{
	const int MaxConnectionNum = 65536;

	class TcpServer
		: public utility::Thread, public ITcpServer
	{
	public:
		TcpServer( int port, ITcpMessageNotify* ptrNotify );
		virtual ~TcpServer();

		void StartUp();
		void SendMessages( session_ptr ptrSocket, const std::string &stream );
		//void CloseSocket();

		virtual void OnRun();
		
	private:
		void __ClientCallBackError(int connId);
		session_ptr __CreateClient();

		void __handle_accept(const boost::system::error_code& error, session_ptr session);

		void __StopAccept();
		
	private:
		io_service m_ioservice;
		tcp::acceptor m_acceptor;

		utility::SpinLock m_SpinLock; //对下面两个容器加锁
		std::unordered_map< int, session_ptr > m_mapClients;
		std::list<int> m_listCnnIdPool;

		ITcpMessageNotify* m_ptrNotify;
	};

}
#endif


