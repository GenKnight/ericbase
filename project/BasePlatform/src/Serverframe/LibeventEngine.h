#ifndef FUANDA_TRADE_LIBEVENT_ENGINE_H
#define FUANDA_TRADE_LIBEVENT_ENGINE_H
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
#include "LibeventSocket/LibeventSocket.h"
#include <iostream>

#define  IN
namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
class CLibeventEngine
{

public:
	// 初始化消息队列
	void Init(const char *ip, int port, libeventtcp::ILibeventNotify& ptrNotify);
	void Stop();

    static CLibeventEngine* Instance()
	{
		if ( m_pInstance == nullptr )
		{
            m_pInstance = new CLibeventEngine();
		}
		return m_pInstance;
	}

    static CLibeventEngine* GetInstance()
	{
		if ( m_pInstance == nullptr )
		{
			std::cout << "CLibevetEngine 未初始化" << std::endl;
		}
		return m_pInstance;
	}

	static void DestoryInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
private:
    CLibeventEngine();
    virtual ~CLibeventEngine();
    CLibeventEngine(const CLibeventEngine &);
    CLibeventEngine& operator = (const CLibeventEngine &);

    static CLibeventEngine *m_pInstance;

private:
	// 服务端
	libeventtcp::ITcpServer* mTcpServer;
	// 客户端
	libeventtcp::ITcpClient* mTcpClient;
};

}// serverframe
#endif