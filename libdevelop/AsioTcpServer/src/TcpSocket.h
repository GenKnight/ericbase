#ifndef TCP_SOCKET_H_
#define TCP_SOCKET_H_

#ifdef WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#endif
#include <boost/asio/buffer.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <memory>
#include <iostream>
//#include "NetworkLibrary.h"

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost;

namespace itstation {

	class clientSession;
	typedef std::shared_ptr<clientSession> session_ptr;

	class ITcpMessageNotify 
	{
	public:
		/*
		注意：由于线程时序的原因，有可能出现OnMessageStream，先于OnAcceptOrConnected被调用的情况，
		如有同步需求，请在回调函数内自行处理。
		*/
		// 接收或连接回调函数，由nStatus指定接收连接是否成功。
		//virtual void OnAcceptOrConnected(int nStatus) = 0;

		// 从服务器接收到数据回调(回调函数应复制数据后，立即返回，否则影响接收效率，有心跳方式阻塞时间不得超过15s，否则断线)
		virtual void OnMessageStream( const std::string& stream ) = 0;

		// 接收数据异常回调
		//virtual void OnDataError() = 0;

		// Socket连接断开回调
		//virtual void OnDisconnected(int nStatus) = 0;

		void SetSessionPtr(session_ptr ptrSocket)
		{
			m_ptrSocket = ptrSocket;
		}

		session_ptr GetSessionPtr()
		{
			return m_ptrSocket;
		}

	private:
		session_ptr m_ptrSocket; 
	};

	class clientSession
		:public std::enable_shared_from_this<clientSession>
	{

	public:
		clientSession(boost::asio::io_service& ioservice, ITcpMessageNotify* ptrNotify);
		virtual ~clientSession();

		std::shared_ptr<clientSession> GetSelf()
		{
			return shared_from_this();
		}

		void SetCallBackError(const std::function<void(int)>& f);

		void StartUp();

		void SendMessages( const std::string &stream );

		boost::asio::ip::tcp::socket& GetSocket();
		void CloseSocket();

		void SetConnId(int connId);
		int GetConnId() const;
		
	private:

		void __HandleReadHead(const boost::system::error_code& error);
		void __HandleReadBody(const boost::system::error_code& error);
		void __handleWrite(const std::string &stream, const boost::system::error_code& error);

		void __HandleError(const boost::system::error_code& ec);
	private:
		const static int kHeaderLen = sizeof(int32_t);

		tcp::socket m_socket;
		char headlen[kHeaderLen+1];
		std::string messageStream;
		int m_connId;
		std::function<void(int)> m_callbackError;
		ITcpMessageNotify* m_ptrNotify;
	};
}

#endif
