#include "Server.h"
#include "DefaultHandler.h"
#include "OrderInsertHandler.h"
#include "QryOrderHandler.h"
#include "Thread.h"
#include "../task/TaskInterfaceDef.h"
#include "../../../proto/ReqSubSystemInfo.pb.h"
#include "../../../proto/ReqSubProcessListInfo.pb.h"
namespace serverframe{;
//##############################################################################
//##############################################################################
////////////////////////////////////////////////////////////////////////////////
TradeServerNotify::TradeServerNotify(IN TcpServerHub& handler)
	: m_hub(handler)
{
	
}

////////////////////////////////////////////////////////////////////////////////
void TradeServerNotify::OnMessageText(
	IN const char* usrid,
	IN int type, 
	IN const char* text)
{}
void TradeServerNotify::OnTransportInterrupted()
{}
void TradeServerNotify::OnTransportResumed()
{}


////////////////////////////////////////////////////////////////////////////////
void TradeServerNotify::OnMessageStream(
	IN const char* data,
	IN CMS_HEADER& header)
{
	try 
	{
		std::string buff(data, header.datasize);
		m_hub.OnRead( buff );
	}
	catch (std::exception& err)
	{
		std::cout << "TradeServerNotify error: " << err.what();
	}
	catch (...)
	{
		std::cout << "TradeServerNotify unknown error.";
	}
}

//////////////////////////////////////////////////////////
//AsioTestMessageNotify::AsioTestMessageNotify(IN TcpServerHub& handler)
//	: m_hub(handler)
//{
//
//}
//
//void AsioTestMessageNotify::OnMessageStream( IN const std::string& stream )
//{
//	try 
//	{
//		std::string buff(stream);
//		m_hub.OnRead( buff );
//	}
//	catch (std::exception& err)
//	{
//		std::cout << "TradeServerNotify error: " << err.what();
//	}
//	catch (...)
//	{
//		std::cout << "TradeServerNotify unknown error.";
//	}
//}

/////////////////////////////////////////////////////////////
LibeventTestMessageNotify::LibeventTestMessageNotify(IN TcpServerHub& handler)
: m_hub(handler)
{

}

void LibeventTestMessageNotify::OnMessageStream(const std::string& stream)
{
    try
    {
        std::string buff(stream);
        m_hub.OnRead(buff);
    }
    catch (std::exception& err)
    {
        std::cout << "LibeventTestMessageNotify error: " << err.what();
    }
    catch (...)
    {
        std::cout << "LibeventTestMessageNotify unknown error.";
    }
}

//##############################################################################
//##############################################################################
////////////////////////////////////////////////////////////////////////////////
void Server::Run(IN const size_t thread_num)
{
	// 注册请求处理
	std::cout << "engine init begin" << std::endl;

	m_hub.Register(std::bind(&Server::Init, this, std::placeholders::_1));

	// 开启处理者线程
	m_hub.Run(thread_num);

	// activemq连接到消息总线
	//AmqEngine::Instance();
	//AmqEngine::GetInstance()->Init(m_ts_notify);
	
	// asio连接到消息
	//CAsioEngine::Instance();
	//CAsioEngine::GetInstance()->Init("127.0.0.1", 5566, m_asio_notify);

    // libevent连接到消息
    CLibeventEngine::Instance();
    CLibeventEngine::GetInstance()->Init("127.0.0.1", 5566,
        m_libevent_notify);


	std::cout << "engine init end" << std::endl;
}


////////////////////////////////////////////////////////////////////////////////
void Server::Join()
{
	m_hub.Join();
}


////////////////////////////////////////////////////////////////////////////////
void Server::Stop()
{
	m_hub.Stop();
	AmqEngine::GetInstance()->DestoryInstance();
}


////////////////////////////////////////////////////////////////////////////////
void Server::Init(IN MessageDispather& dispatcher)
{
	// 默认处理请求.
	dispatcher.RouteDefault<DefaultHandler>();

	// 插入订单。
	dispatcher.Route<OrderInsertHandler>(machine::ReqSubSystemInfo::descriptor());

	// 查询订单委托。
	dispatcher.Route<QryOrderHandler>(machine::ReqSubProcessListInfo::descriptor());
}


////////////////////////////////////////////////////////////////////////////////
}// ns::serverframe
