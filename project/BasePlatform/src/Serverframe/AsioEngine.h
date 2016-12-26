#ifndef FUANDA_TRADE_ASIO_ENGINE_H
#define FUANDA_TRADE_ASIO_ENGINE_H
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
#include "AsioNetLibrary.h"
#include <iostream>

#define  IN
namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class CAsioEngine
{

public:
	// 初始化消息队列
	void Init(const char *ip, int port, itstation::ITcpMessageNotify& ptrNotify);
	void Stop();

	static CAsioEngine* Instance()
	{
		if ( m_pInstance == nullptr )
		{
			m_pInstance = new CAsioEngine();
		}
		return m_pInstance;
	}

	static CAsioEngine* GetInstance()
	{
		if ( m_pInstance == nullptr )
		{
			std::cout << "CAsioEngine 未初始化" << std::endl;
		}
		return m_pInstance;
	}

	static void DestoryInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
private:
	CAsioEngine();
	virtual ~CAsioEngine();
	CAsioEngine(const CAsioEngine &);
	CAsioEngine& operator = (const CAsioEngine &);

	static CAsioEngine *m_pInstance;

private:
	// 服务端
	itstation::ITcpServer*	mTcpServer;
	// 客户端
	itstation::ITcpClient*	mTcpClient;
};

}// serverframe
#endif