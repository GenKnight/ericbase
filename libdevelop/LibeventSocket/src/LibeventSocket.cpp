#include "LibeventSocket.h"
#include "TcpServer.h"
#include "TcpClient.h"

namespace libeventtcp
{
    ITcpServer * CreateTcpServer(int port, ILibeventNotify * ptrNotify)
	{
		return new TcpServer( port, ptrNotify );
	}

    ITcpClient * CreateTcpClient(const char *ip, int port, ILibeventNotify * ptrNotify)
	{
		return new TcpClient( ip, port, ptrNotify );
	}

	void DeleteTcpServer( ITcpServer * ptrObj )
	{
		if ( ptrObj )
		{
			delete ptrObj;
			ptrObj = NULL;
		}
	}

	void DeleteTcpClient( ITcpClient * ptrObj )
	{
		if ( ptrObj )
		{
			delete ptrObj;
			ptrObj = NULL;
		}
	}
}