#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#include "fndcms.h"
#include "../cmsProducer/appcomdef.h"
#else
#include <sys/time.h>

#include "fndcms.h"
#include "../cmsProducer/appcomdef.h"
#endif

class AsyncConsumerReceiver: public IAmqAsyncConsumerNotify
{
public:
	AsyncConsumerReceiver(){};
	~AsyncConsumerReceiver(){};

public:
	virtual void OnMessageText( const char* usrid, int type, const char* text )
	{
#ifdef _DEBUG
		static int n=1;
		printf( "Recv msg[%d] from usr [ %s ]:%s\n", n++, usrid, text );
#endif
	}

	virtual void OnMessageStream( const char* stream, CMS_HEADER &header  )
	{
		int nDataSize = header.datasize;
		int type = header.datatype;

		static int n=0;
		if (n == 0)
		{
			SYSTEMTIME st;
			GetLocalTime(&st);
			//nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
			long nTime = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
			std::cout << "start time" << nTime << std::endl;
		}
		n++;
		if (n == 1)
		{
			SYSTEMTIME st;
			GetLocalTime(&st);
			//nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
			long nTime = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
			std::cout << "end time" << nTime << std::endl;
		}
#if 0
		switch (type)
		{
		case 1://注册
			{
				if ( nDataSize!=sizeof(APP_REGISTER) )
					break;
				APP_REGISTER *ptrReg =  (APP_REGISTER *)stream;
				printf( "[%s_%d]注册\n", ptrReg->mobile, ++n );
			}
			break;
			
		case 2:	//Login
			{
				if ( nDataSize!=sizeof(struct tagLogin) )
					break;
				struct tagLogin login;
				memcpy( &login, stream, sizeof(struct tagLogin) );
				printf( "Recv stream msg[%d] :mobile=%s, password=%s\n", n++, login.mobile, login.password );
			}
			break;


		}//swtich
#endif
	}

	virtual void OnTransportInterrupted()
	{
	}
	virtual void OnTransportResumed()
	{

	}
};

int main(int argc, char* argv[])
{
#if 0
	/**
	* 传入参数格式：  0-Queue模式/1-发布订阅模式 消息中间件地址  queue/topic名称
	* 传入参数示例1： 无参数  -- 参数从配置文件fndcms.ini中读取
	* 传入参数示例2： 0 192.168.1.127:61616  [queue/topic名称]从配置文件fndcms.ini中读取
	* 传入参数示例3： 0 192.168.1.127:61616 FND.MD -- 消息队列模式
	* 传入参数示例4： 1 192.168.1.127:61616 FND.MD -- 发布订阅模式
	*/
	if ( argc==2 && (*argv[1])=='?' )
	{
		printf( "格式: 0-Queue/1-Topic broker地址          queue/topic名称\n" );
		printf( "usage:   0/1          192.168.1.127:61616 FND.MOM.TEST\n" );
		return 0;
	}

	bool bUseTopic=false;
	if (argc>1)
		bUseTopic = atoi( argv[1] )>0 ? true : false;
	
	char szAddress[32]={0};
	if (argc>2 && strlen(argv[2])>0 )
		strcpy( szAddress, argv[2] );

	char szQueueOrTopicName[64]={0};
	if (argc>3 && strlen(argv[3])>0 )
		strcpy( szQueueOrTopicName, argv[3] );
#endif
	bool bUseTopic=false;
	char szAddress[32]={0};	//192.168.1.65:61616
	strcpy( szAddress, "192.168.1.65:61616" );
	char szQueueOrTopicName[64]="Q.ME2MON.TEST";

	AsyncConsumerReceiver acr;
	IAmqAsyncConsumer * consumer = AmqCreateAsyncConsumer( &acr, bUseTopic, szAddress, szQueueOrTopicName );

	consumer->AmqStart();
#ifdef _WIN32
	system( "pause" );
#else
	getchar();
#endif

	AmqDeleteAsyncConsumer( consumer );

	return 0;
}

