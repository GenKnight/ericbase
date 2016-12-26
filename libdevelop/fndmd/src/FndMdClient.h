#ifdef _WIN32
#pragma once
#endif

#ifndef _HEADER_IMPLEMENT_MD_CLIENT_
#define _HEADER_IMPLEMENT_MD_CLIENT_

//#include "ITCPClient.h"
#include "IFndMdClient.h"
//#include "MdsrvClient.h"

class CFndMdClient : public IFndMdClient, public IFndNetClientNotify
{
public:
	CFndMdClient( IFndMdClientNotify *ptrMdClientNotify );

	virtual ~CFndMdClient(void);

	/// \brief 连接有心跳的TCP服务器
	/// \param szIP 服务器IP
	/// \param usPort 服务器端口
	/// \param blAuth 是否验证(暂不支持)
	/// \param unTimeOut 超时时间(单位秒)
	virtual void ConnectMdServer( const char *szIP, unsigned short usPort, unsigned int unTimeOut = 0 );

	/// \brief 发送请求给服务器 -- 基础信息
	/// \param pbData 数据指针
	/// \param unDataSize 数据大小
	/// \return 是否发送成功
	virtual bool SendRequestBaseInfo( EN_BASE_INFO_ID enBaseInfoId, bool bGetOnce=false );

	/// \brief 发送请求给服务器 -- 股票快照
	/// \param pbData 数据指针
	/// \param unDataSize 数据大小
	/// \return 是否发送成功
	virtual bool SendRequestStockSnap( bool bSnapOnce=false );

	/// \brief 发送请求给服务器 -- CTP快照
	/// \param pbData 数据指针
	/// \param unDataSize 数据大小
	/// \return 是否发送成功
	virtual bool SendRequestCtpSnap( bool bSnapOnce=false );

	/// \brief 发送请求给服务器 -- [订阅/取消订阅]全市场实时行情
	/// \param enMarketId		[订阅/取消订阅]证券市场的Id
	/// \return 是否发送成功
	virtual bool SendRequestMarketSubscribe( EN_MD_ID enMarketId );

	/// \brief 发送请求给服务器 -- [订阅/取消订阅]股票市场实时行情
	/// \param bSubscribeFlag	订阅标志 true--订阅 false--取消订阅
	/// \param enMarketId		[订阅/取消订阅]代码的市场Id
	/// \param subCode			[订阅/取消订阅]代码
	/// \return 是否发送成功
	virtual bool SendRequestOneStockSubscribe( bool bSubscribeFlag, EN_MD_ID enMarketId, REQ_SUB_INSTRUMENT &subCode );

	/// \brief 发送请求给服务器 -- 订阅Ctp市场实时行情（预留--暂不支持！）
	/// \param bSubscribeFlag	订阅标志 true--订阅 false--取消订阅
	/// \param enMarketId		[订阅/取消订阅]代码的市场Id
	/// \param subCode			[订阅/取消订阅]代码
	/// \return 是否发送成功
	virtual bool SendRequestOneCtpSubscribe( bool bSubscribeFlag, EN_MD_ID enMarketId, REQ_SUB_INSTRUMENT &subCode );

	/// \brief 发送请求给服务器 -- 获取K线
	/// \param reqKLine	请求K线信息
	/// \return 是否发送成功
	virtual bool SendRequestHisKLine( REQ_HIS_KLINE & reqKLine );

	/// \brief 发送请求给服务器 -- 自定义
	/// \param pbData 数据指针
	/// \param unDataSize 数据大小
	/// \return 是否发送成功
	virtual bool SendRequestUserDefine( const unsigned char *pbData, unsigned int unDataSize );

	/// \brief 与服务器断开网络连接
	virtual void CloseSocket();

	/// --- IFndNetClientNotify重载接口 ---
	/*
		注意：由于线程时序的原因，有可能出现OnRawData，先于OnConnected被调用的情况，
		如有同步需求，请在回调函数内自行处理。
	*/
	/// \brief 连接服务器回调函数，由nStatus指定连接是否成功。
	virtual void OnConnected( int nStatus );

	/// \brief 从服务器接收到数据回调(回调函数应复制数据后，立即返回，否则影响接收效率，有心跳方式阻塞时间不得超过15s，否则断线)
	/// \param pbData 数据指针(函数调用后即释放，勿超范围使用，勿在函数中删除)
	/// \param unDataSize 数据大小
	virtual void OnRawData(const unsigned char* pbData, unsigned int unDataSize);

	/// \brief 从服务器接收数据异常回调
	virtual void OnServerDataError() {};

	/// \brief Socket连接断开回调
	virtual void OnDisconnected(int nStatus);

private:
	IFndNetClient * m_ptrNetClient;
	IFndMdClientNotify *m_ptrMdClientNotify;

	//CMdsrvClient m_objMdClient;
	bool m_bConnect;
	char m_szSrvIP[16];
	unsigned short m_usPort;
	unsigned int m_unTimeOut;
};

#endif

