#ifndef FUANDA_SERVER_H
#define FUANDA_SERVER_H
/*******************************************************************************
@名称

@功能


--------------------------------------------------------------------------------
@修改记录
日期			版本		修改人			修改内容
2015\05\20		1.0			uJoy			创建与初始化类。

--------------------------------------------------------------------------------
* 版权所有(c) 2015 - 2017, mrs corp, 保留所有权利。

*******************************************************************************/
#include "TcpServerHub.h"
#include "fndcms/fndcms.h"
#include "AmqEngine.h"
//#include "AsioEngine.h"
#include "LibeventEngine.h"
#include <string>

namespace serverframe{;

////////////////////////////////////////////////////////////////////////////////
typedef TcpServerHub::tcp_context AmqContext;
typedef std::shared_ptr<AmqContext> AmqContextPtr;

typedef TcpServerHub::message_dispatcher MessageDispather;


// request context
class RequestHandler
{
	virtual void OnRequest(IN AmqContext& context) = 0; 
};

////////////////////////////////////////////////////////////////////////////////
// 交易服务
class TradeServerNotify : public IAmqAsyncConsumerNotify
{
public:
	TradeServerNotify(IN TcpServerHub& hdl);

//////////////////////////////////////////////////////// IAmqAsyncConsumerNotify
protected:
	virtual void OnMessageText(
		IN const char* usrid,
		IN int type,
		IN const char* text) override;

	virtual void OnMessageStream(
		IN const char* data,
		IN CMS_HEADER& header) override;

	virtual void OnTransportInterrupted() override;

	virtual void OnTransportResumed() override;

private:
	TcpServerHub& m_hub;
};

////////////////////////////////////////////////////////////////////////////////
// Asio 测试消息回报
//class AsioTestMessageNotify : public itstation::ITcpMessageNotify
//{
//public:
//	AsioTestMessageNotify(IN TcpServerHub& hdl);
//
//	////////////////////////////////////////////////////////
//protected:
//	virtual void OnMessageStream( IN const std::string& stream ) override;
//
//private:
//	TcpServerHub& m_hub;
//};

////////////////////////////////////////////////////////////////////////////////
// libevent 测试消息回报
class LibeventTestMessageNotify : public libeventtcp::ILibeventNotify
{
public:
    LibeventTestMessageNotify(IN TcpServerHub& hdl);

    //////////////////////////////////////////////////////// 
protected:
    virtual void OnMessageStream(const std::string& stream) override;

private:
    TcpServerHub& m_hub;
};

////////////////////////////////////////////////////////////////////////////////
class Server
{
public:
	inline Server() 
        : m_hub(), 
        //m_ts_notify(m_hub), 
        //m_asio_notify(m_hub), 
        m_libevent_notify(m_hub)
	{}

	inline ~Server()
	{
		m_hub.Stop();
	}

	// 启动服务
	void Run(IN const size_t thread_num);

	// 等待线程完成
	void Join();

	// 注册消息处理器
	void Init(IN MessageDispather& dispatcher);

	// 停止服务
	void Stop();

	inline TcpServerHub& GetHub()
	{
		return m_hub;
	}

////////////////////////////////////////////////////////////////////////////////
private:
	// 消息处理
	TcpServerHub m_hub;

    //以下任选其一
	// activemq消息通知
	//TradeServerNotify m_ts_notify;

	// asio消息通知
	//AsioTestMessageNotify m_asio_notify;

    // libevent消息通知
    LibeventTestMessageNotify m_libevent_notify;
};


////////////////////////////////////////////////////////////////////////////////
}// ns::serverframe
#endif