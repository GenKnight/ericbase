#ifndef TCP_CLIENT_H_
#define TCP_CLIENT_H_
#include <boost/thread/thread.hpp>  
#include "AsioNetLibrary.h"
#include "utility/Thread.h"

namespace itstation 
{
	class TcpClient 
		: public utility::Thread, public ITcpClient
	{
	public:
		TcpClient(const char *ip, int port, ITcpMessageNotify* ptrNotify = NULL);
		virtual ~TcpClient();

		void StartUp( void );

		void SendMessages( const std::string &stream );

		//void CloseSocket();

		virtual void OnRun();
	private:
		void __handleConnect(const boost::system::error_code& error);
		void __HandleConnectError(const boost::system::error_code& error);
		void __HandleRWError(int connid);
		void __CheckConnect();
		bool __IsConnected() const; 
		
		void __ThreadReconnect();
	private:
		boost::asio::io_service m_ioservice;
		tcp::endpoint m_serverAddr;

		session_ptr m_ptrClient; 
		bool m_isConnected;

		std::shared_ptr<boost::thread> m_chkThread; //专门检测重连的线程
		
		ITcpMessageNotify* m_ptrNotify;
	};

}

#endif

