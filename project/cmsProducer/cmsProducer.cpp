// cmsProducer.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>

#include <stdlib.h>
#include <string.h>

typedef unsigned char       BYTE;

#ifdef _WIN32
	#include <windows.h>
	#include "fndcms.h"
	#include "appcomdef.h"
#else
	#include <sys/time.h>

	#include "fndcms.h"
	#include "appcomdef.h"
#endif

#ifndef _WIN32
#include <sys/time.h>
int timeval_subtract(struct timeval* result, struct timeval* x, struct timeval* y) 
{ 
	int nsec; 

	if ( x->tv_sec>y->tv_sec ) 
		return -1; 

	if ( (x->tv_sec==y->tv_sec) && (x->tv_usec>y->tv_usec) ) 
		return -1; 

	result->tv_sec = ( y->tv_sec-x->tv_sec ); 
	result->tv_usec = ( y->tv_usec-x->tv_usec ); 

	if (result->tv_usec<0) 
	{ 
		result->tv_sec--; 
		result->tv_usec+=1000000; 
	} 
	return 0; 
}
#endif

void ShowTip()
{
	printf( "Please input cmd:q-退出\n" );
	printf( "1-注册 2-登录 3-修改密码 4-获取账户信息 5-获取基础信息\n" );
	printf( "6-申请配资 a-买入 b-卖出\n" );
	printf( "监控测试：m-监控（资产） n-监控（报警） o-请求仓位\n" );
	printf( "行情测试：p-回放行情数据\n" );
}

int main(int argc, char* argv[])
{
#if 0
	/**
	* 传入参数格式： 发送消息数量 usrid 0-不采用发布订阅模式/1-采用发布订阅模式 消息中间件地址 queue/topic名称
	* 传入参数示例1： 100 tester 其它参数从配置文件fndcms.ini中读取
	* 传入参数示例2： 100 tester 0 192.168.1.127:61616 [queue/topic名称]从配置文件fndcms.ini中读取
	* 传入参数示例3： 100 tester 0 192.168.1.127:61616 FND.MD -- 消息队列模式
	* 传入参数示例4： 100 tester 1 192.168.1.127:61616 FND.MD -- 发布订阅模式
	*/
	if ( argc==2 && (*argv[1])=='?' )
	{
		printf( "格式:数量 usrid 0-Queue/1-Topic broker地址          queue/topic名称\n" );
		printf( "usage:num usrid 0/1             192.168.1.127:61616 FND.MOM.TEST \n" );
		return 0;
	}

	int nMsgNum=100;
	if ( argc>1 )
	{
		int nNum = atoi( argv[1] );
		if ( nNum>0 )
			nMsgNum = nNum;
	}

	char usrid[32]="tester";
	if (argc>2)
		strcpy( usrid, argv[2] );

	bool bUseTopic=false;
	if (argc>3)
		bUseTopic = atoi( argv[3] )>0 ? true : false;

	char szAddress[32]={0};	//192.168.1.65:61616
	if (argc>4 && strlen(argv[4])>0 )
		strcpy( szAddress, argv[4] );

	char szQueueOrTopicName[64]="Q.ME2MON.TEST";
	if (argc>5 && strlen(argv[5])>0 )
		strcpy( szQueueOrTopicName, argv[5] );
#endif
	int nMsgNum=1;
	char usrid[32]="tester";
	bool bUseTopic=false;
	char szAddress[32]={0};	//192.168.1.65:61616
	strcpy( szAddress, "192.168.1.65:61616" );
	char szQueueOrTopicName[64]="Q.ME2MON.TEST";
	IAmqProducer * producer = AmqCreateProducer( usrid, bUseTopic, szAddress, szQueueOrTopicName );

	producer->AmqStart();

	CMS_HEADER header;
	header.datatype = 1;
	header.datasize = sizeof(APP_REGISTER);
	header.usrid = "13160906366";
	header.session_id = "producer_test";	
	header.security_type = "1";
	header.datasource = 10;
#if 1
	APP_REGISTER reg={0};
	strcpy(reg.mobile, "13162926360");
	std::cout << "开始测试" << std::endl;
	{
	
#ifdef _WIN32

#else
		struct timeval start1,stop1,diff1; 
		gettimeofday(&start1,0); 
#endif

		for ( int i = 0; i < nMsgNum; i++ )
		{	
			if (i == 0)
			{
				SYSTEMTIME st;
				GetLocalTime(&st);
				//nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
				long nTime = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
				std::cout << "start time" << nTime << std::endl;
			}
			if (i == 9999)
			{
				SYSTEMTIME st;
				GetLocalTime(&st);
				//nDate = st.wYear * 10000 + st.wMonth * 100 + st.wDay;
				long nTime = st.wHour * 10000 * 1000 + st.wMinute * 100 * 1000 + st.wSecond * 1000 + st.wMilliseconds;
				std::cout << "end time" << nTime << std::endl;
			}
			producer->AmqSendStream( (const char*)&reg, header );
		}

#ifdef CAPABILITY_TEST	//测试性能
#ifdef _WIN32
#else
		gettimeofday(&stop1,0); 
		timeval_subtract(&diff1,&start1,&stop1); 

		printf( "CAPABILITY_99999_3_SECS_%010u_USEC_%010u\n", diff1.tv_sec, diff1.tv_usec );
#endif
#endif
	}
#endif
	/*/ 发送消息 -- Text
	char szMsg[32]={0};
	for ( int i=0; i<nMsgNum; i++ )
	{
		printf( "[%d]Send text\n", i+1 );

		sprintf_s( szMsg, "Hellokitty - %d", i+1 );

		producer->AmqSendText( szMsg );

		Sleep( 2000 );
	}

	system( "pause" );
	*/
	
	ShowTip();

	int nCmd = getchar();
	getchar();

	bool bExit=false;
	// 发送消息 -- Stream
	while (1)
	{
		switch (nCmd )
		{
		case '1'://1、注册
			{
				APP_REGISTER reg={0};

				strcpy( reg.macAddress, "mac address" );
				strcpy( reg.remote_ip, "XXX.XXX.XXX.XXX" );

				printf( "请输入手机号：" );
				char szNumber[32]={0};
				gets( szNumber ); 
				strcpy( reg.mobile, /*"1310000001"*/szNumber );
				strcpy( reg.password, "123456" );

				header.datatype = 1;
				header.datasize = sizeof(APP_REGISTER);
				header.usrid = std::string(szNumber);

				printf( "注册命令发送完成\n" );
				producer->AmqSendStream( (const char*)&reg, header );
			}
			break;

		case '2'://2、登录
			{
				struct tagLogin login={0};
				
				printf( "请输入手机号：" );
				char szNumber[32]={0};
				//gets( szNumber ); 

				login.requestid = 10001;
				strcpy( login.mobile, "13162926360" );
				strcpy( login.password, "EEjynds244IsK8Q.bQRCcN9hROanH0S" );
				strcpy( login.remote_ip, "192.168.1.152" );
				strcpy( login.macAddress, "ASDBAEgADGAG" );

				header.datatype = 10001;
				header.datasize = sizeof(struct tagLogin);
				header.usrid = std::string(szNumber);

				printf( "登录命令发送完成\n" );
				producer->AmqSendStream( (const char*)&login, header );
			}
			break;

		case 'q':
		case 'Q':
			bExit=true;
			break;

		default:
			{
			}
			break;
		}

		if (bExit)
			break;

		ShowTip();
		nCmd = getchar();
		getchar();

	}//while

	//system( "pause" );

	AmqDeleteProducer( producer );

	return 0;
}

