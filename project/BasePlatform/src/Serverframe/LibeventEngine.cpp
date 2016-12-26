#include "LibeventEngine.h"
////////////////////////////////////////////////////////////////////////////////
#include "Server.h"
#include "Thread.h"
////////////////////////////////////////////////////////////////////////////////



namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////
CLibeventEngine* CLibeventEngine::m_pInstance = nullptr;

CLibeventEngine::CLibeventEngine()
{
	mTcpServer = nullptr;
	mTcpClient = nullptr;
}


////////////////////////////////////////////////////////////////////////////////
CLibeventEngine::~CLibeventEngine()
{
	Stop();
}


////////////////////////////////////////////////////////////////////////////////
void CLibeventEngine::Init(const char *ip, int port, 
    libeventtcp::ILibeventNotify& ptrNotify)
{
	// 客户端
	//mTcpClient = CreateTcpClient(ip, port, &ptrNotify);
	//mTcpClient->StartUp();

	// 服务端
	mTcpServer = libeventtcp::CreateTcpServer(port, &ptrNotify);
	mTcpServer->StartUp();

}


////////////////////////////////////////////////////////////////////////////////
void CLibeventEngine::Stop()
{
	// 先删除客户端再删除服务端
	if (mTcpClient != NULL)
	{
		libeventtcp::DeleteTcpClient(mTcpClient);
		mTcpClient = NULL;
	}
	if (mTcpServer != NULL)
	{
		libeventtcp::DeleteTcpServer(mTcpServer);
		mTcpServer = NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////
}// serverframe
