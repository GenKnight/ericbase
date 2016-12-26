#ifndef FUANDA_TRADE_AMQ_ENGINE_H
#define FUANDA_TRADE_AMQ_ENGINE_H
/*******************************************************************************
@名称

@功能


--------------------------------------------------------------------------------
@修改记录
日期			版本		修改人			修改内容
2015\01\05		1.0			uJoy			创建与初始化类。

--------------------------------------------------------------------------------
* 版权所有(c) 2015 - 2017, mrs corp, 保留所有权利。

*******************************************************************************/



////////////////////////////////////////////////////////////////////////////////
#include "fndcms/fndcms.h"
#include <iostream>

#define  IN
namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class AmqEngine
{

public:
	// 初始化消息队列
	void Init(IN IAmqAsyncConsumerNotify& ts_notify);
	void Stop();

	static AmqEngine* Instance()
	{
		if ( m_pInstance == nullptr )
		{
			m_pInstance = new AmqEngine();
		}
		return m_pInstance;
	}

	static AmqEngine* GetInstance()
	{
		if ( m_pInstance == nullptr )
		{
			std::cout << "AmqEngine 未初始化" << std::endl;
		}
		return m_pInstance;
	}

	static void DestoryInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
private:
	AmqEngine();
	virtual ~AmqEngine();
	AmqEngine(const AmqEngine &);
	AmqEngine& operator = (const AmqEngine &);

	static AmqEngine *m_pInstance;

private:
	// 交易服务：回报
	IAmqProducer*		m_amq_future_ctpts_rsp;
	// 交易服务：请求
	IAmqAsyncConsumer*	m_amq_future_ctpts_req;
};

}// serverframe
#endif