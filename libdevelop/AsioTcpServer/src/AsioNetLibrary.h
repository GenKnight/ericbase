////////////////////////////////////////////////////////////////////////////////
/// AsioNetLibrary.h
/// 
/// author: Shengkaishan
/// date: 2016/6/23
/// 
/// History:
/// 2016/6/23  Shengkaishan   Initial revision
/// 
////////////////////////////////////////////////////////////////////////////////

#ifndef NETWORK_LIBRARY_H_
#define NETWORK_LIBRARY_H_

#include "utility/Global.h"
#include "TcpSocket.h"
namespace itstation 
{

	class COMMON_API ITcpServer
	{ 
	public:

		virtual ~ITcpServer(){};

		// ��ָ���˿�����TCP����������
		virtual void StartUp( void ) = 0;

		// �������ݸ�ָ���Ŀͻ���
		virtual void SendMessages(session_ptr ptrSocket, const std::string &stream ) = 0;

		// �ر�TCP Server
		//virtual void CloseSocket() = 0;
	};

	class COMMON_API ITcpClient
	{ 
	public:

		virtual ~ITcpClient(){};

		// ��������TCP������
		virtual void StartUp( void ) = 0;

		// �������ݸ�ָ���Ŀͻ���
		virtual void SendMessages( const std::string &stream ) = 0;

		// �ر�TCP Server
		//virtual void CloseSocket() = 0;
	};

	extern "C"
	{
		COMMON_API ITcpServer * CreateTcpServer(int port, ITcpMessageNotify * ptrNotify );

		COMMON_API ITcpClient * CreateTcpClient(const char *ip, int port, ITcpMessageNotify * ptrNotify );

		COMMON_API void DeleteTcpServer( ITcpServer * ptrObj );

		COMMON_API void DeleteTcpClient( ITcpClient * ptrObj );
	}

}
#endif