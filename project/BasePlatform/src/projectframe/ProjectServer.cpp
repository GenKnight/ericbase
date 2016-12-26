#include "ProjectServer.h"
#include "Applog.h"
#include "EngineEnvironment.h"
#include "publicfun.h"
#include "../task/TaskInterfaceDef.h"
#include "MySqlWrapper.h"
namespace itstation 
{
	CProjectServer::CProjectServer() 
	{ 
	} 
	CProjectServer::~CProjectServer()
	{
	}

	void CProjectServer::startServer()
	{
		m_status = false;
        m_app_server.Run(1);
        m_app_server.Join();

#if 0
		APP_LOG(utility::Applog::LOG_INFO)<<"server initialize";
		config_file_path = EngineEnvironment::getInstance()->get_config_file_path();

		m_ptrNotify = new ClientSession(0);
		m_TcpServer = CreateTcpServer(99905, m_ptrNotify);
		m_TcpServer->StartUp();

		m_TcpClient = CreateTcpClient("127.0.0.1", 5566, NULL);
		m_TcpClient->StartUp();

		string value = "hellosock";
		int kHeaderLen = sizeof(int32_t);

		string result;
		result.resize(kHeaderLen);
		result.append(value.c_str(), value.length());
		int32_t len = htonl(result.size() - kHeaderLen);
		std::copy(reinterpret_cast<char*>(&len),
			reinterpret_cast<char*>(&len) + sizeof len,
			result.begin());

		for ( int i = 0; i < 10000; i++ )
		{
			if (i == 0)
			{
				SYSTEMTIME st;
				GetLocalTime(&st);
				//nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
				long nTime = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
				std::cout << "start time" << nTime << std::endl;
			}

			m_TcpClient->SendMessages(result);

			if (i == 9999)
			{
				SYSTEMTIME st;
				GetLocalTime(&st);
				//nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
				long nTime = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
				std::cout << "end time" << nTime << std::endl;
			}
		}

		std::string ip, username, password, dbname;
		int dbport=0;
		PUBLIC_FUN::GetMysqlConnectSetting( ip, username, password, dbname, dbport );
		cout << ip << " " << username << " " << password << " " << dbname << " " << dbport << endl;

		DBAccess::MySQLWrapper m_objMySQLWrapper;
		bool bRet = m_objMySQLWrapper.Connet( (char*)ip.c_str(), (char*)username.c_str(), \
			(char*)password.c_str(), (char*)dbname.c_str(), dbport );

		std::vector< std::vector<std::string> > vecFetchData;

		for ( int i = 0; i < 10000; i++ )
		{
			if (i == 0)
			{
				SYSTEMTIME st;
				GetLocalTime(&st);
				//nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
				long nTime = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
				std::cout << "start time" << nTime << std::endl;
			}

			char szSelect1[] = "SELECT asofdate FROM pz_jy_fuanda.base_date";
			bRet = m_objMySQLWrapper.FetchData( szSelect1, vecFetchData );
			
			vecFetchData.clear();

			if (i == 9999)
			{
				SYSTEMTIME st;
				GetLocalTime(&st);
				//nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
				long nTime = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
				std::cout << "end time" << nTime << std::endl;
			}
		}
#endif
		
		Start();
	}

	void CProjectServer::stopServer()
	{
		if ( m_ptrNotify )
		{
			delete m_ptrNotify;
			m_ptrNotify = NULL;
		}

		if ( m_TcpServer )
		{
			delete m_TcpServer;
			m_TcpServer = NULL;
		}

		m_status = true;
	}

	void CProjectServer::SendMessages( int type, session_ptr ptrSocket, const char* stream, TCP_MSG_HEAD &header )
	{
		//bool nRet=false;
		switch(type)
		{
		case 1:
			{
				//m_TcpServer->SendMessages( ptrSocket, stream, header );
				break;				   
			}			

		case 2:
			{
				//m_TcpClient->SendMessages( ptrSocket, stream, header );
				break;	
			}
		default:
			{
				break;
			}
		}

		//return nRet;
	}

	void CProjectServer::OnRun()
	{
		int cout = 0;
		while( !m_status )
		{
			//std::cout << cout++ << std::endl;
			q_sleep(1000);
		}
	}
}
