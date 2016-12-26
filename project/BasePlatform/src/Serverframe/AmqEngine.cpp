#include "AmqEngine.h"
////////////////////////////////////////////////////////////////////////////////
#include "Server.h"
#include "Thread.h"
////////////////////////////////////////////////////////////////////////////////



namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////
AmqEngine* AmqEngine::m_pInstance = nullptr;

AmqEngine::AmqEngine()
{
	m_amq_future_ctpts_req = nullptr;
	m_amq_future_ctpts_rsp = nullptr;
}


////////////////////////////////////////////////////////////////////////////////
AmqEngine::~AmqEngine()
{
	Stop();
}


////////////////////////////////////////////////////////////////////////////////
void AmqEngine::Init(IN IAmqAsyncConsumerNotify& ts_notify)
{
	// 交易服务：回报
	m_amq_future_ctpts_rsp = AmqCreateProducer(
		"one", false, "192.168.1.65:61616", "Q.NEWTEST.TO.ONE.15");
	m_amq_future_ctpts_rsp->AmqStart();

	//// 交易服务：请求
	m_amq_future_ctpts_req = AmqCreateAsyncConsumer(
		&ts_notify, false, "192.168.1.65:61616", "Q.ONE.TO.NEWTEST.15");
	m_amq_future_ctpts_req->AmqStart();

}


////////////////////////////////////////////////////////////////////////////////
void AmqEngine::Stop()
{
	// 先删除消费者再删除生产者
	if (m_amq_future_ctpts_req != NULL)
	{
		AmqDeleteAsyncConsumer(m_amq_future_ctpts_req);
		m_amq_future_ctpts_req = NULL;
	}
	if (m_amq_future_ctpts_rsp != NULL)
	{
		AmqDeleteProducer(m_amq_future_ctpts_rsp);
		m_amq_future_ctpts_rsp = NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////
}// serverframe
