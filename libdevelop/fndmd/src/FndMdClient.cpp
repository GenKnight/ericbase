#include "FndMdClient.h"
#include <stdio.h>

#include "utility/include_common.h"
#include "DefMDBase.h"
#include "DefResponse.h"

CFndMdClient::CFndMdClient(  IFndMdClientNotify *ptrMdClientNotify )
	:m_ptrMdClientNotify(ptrMdClientNotify)
{
	//m_ptrNetClient = NetCreateClient( (IFndNetClientNotify*)&m_objMdClient );
	m_ptrNetClient = NetCreateClient( this );
}


CFndMdClient::~CFndMdClient(void)
{
}

/// \brief 连接有心跳的TCP服务器
/// \param szIP 服务器IP
/// \param usPort 服务器端口
/// \param blAuth 是否验证(暂不支持)
/// \param unTimeOut 超时时间(单位秒)
void CFndMdClient::ConnectMdServer( const char *szIP, unsigned short usPort, unsigned int unTimeOut )
{
	if ( m_ptrNetClient )
	{
		strcpy( m_szSrvIP, szIP );
		m_usPort	= usPort;
		m_unTimeOut = unTimeOut;

		m_ptrNetClient->ConnectServerWithHB( szIP, usPort, false, unTimeOut );
	}
}

/// \brief 发送请求给服务器 -- 基础信息
/// \param pbData 数据指针
/// \param unDataSize 数据大小
/// \return 是否发送成功
bool CFndMdClient::SendRequestBaseInfo( EN_BASE_INFO_ID enBaseInfoId, bool bGetOnce )
{
	MD_BASE mdrequest( BASE_INFO, bGetOnce ? BASE_INFO_STOCK_ONCE : BASE_INFO_STOCK, 0, NULL );

	return m_ptrNetClient->SendDataToServerWithHB( mdrequest.GetStream(), mdrequest.GetStreamLength() );
}

/// \brief 发送请求给服务器 -- 股票快照
/// \param pbData 数据指针
/// \param unDataSize 数据大小
/// \return 是否发送成功
bool CFndMdClient::SendRequestStockSnap( bool bSnapOnce )
{
	MD_BASE mdrequest( /*MARKET_TICK*/MARKET_SNAP, bSnapOnce ? STOCK_L1_ONCE : STOCK_L1, 0, NULL );

	return m_ptrNetClient->SendDataToServerWithHB( mdrequest.GetStream(), mdrequest.GetStreamLength() );
}

/// \brief 发送请求给服务器 -- CTP快照
/// \param pbData 数据指针
/// \param unDataSize 数据大小
/// \return 是否发送成功
bool CFndMdClient::SendRequestCtpSnap(  bool bSnapOnce )
{
	MD_BASE mdrequest( /*MARKET_TICK*/MARKET_SNAP, bSnapOnce ? CTP_ALL_ONCE : CTP_ALL, 0, NULL );

	return m_ptrNetClient->SendDataToServerWithHB( mdrequest.GetStream(), mdrequest.GetStreamLength() );
}

/// \brief 发送请求给服务器 -- 订阅全市场实时行情
/// \param pbData 数据指针
/// \param unDataSize 数据大小
/// \return 是否发送成功
bool CFndMdClient::SendRequestMarketSubscribe( EN_MD_ID enMarketId )
{
	MD_BASE mdrequest( MARKET_TICK, enMarketId/* STOCK_L1 | STOCK_L1_ONCE | CTP_ALL | CTP_ALL_ONCE*/, 0, NULL );

	return m_ptrNetClient->SendDataToServerWithHB( mdrequest.GetStream(), mdrequest.GetStreamLength() );
}

/// \brief 发送请求给服务器 -- 订阅股票市场实时行情
/// \param pbData 数据指针
/// \param unDataSize 数据大小
/// \return 是否发送成功
bool CFndMdClient::SendRequestOneStockSubscribe( bool bSubscribeFlag, EN_MD_ID enMarketId, REQ_SUB_INSTRUMENT &subCode )
{
	MD_BASE mdrequest( bSubscribeFlag ? MARKET_SUB : MARKET_UNSUB, STOCK_L1, sizeof(REQ_SUB_INSTRUMENT), (unsigned char *)&subCode );

	return m_ptrNetClient->SendDataToServerWithHB( mdrequest.GetStream(), mdrequest.GetStreamLength() );
}

/// \brief 发送请求给服务器 -- 订阅Ctp市场实时行情
/// \param pbData 数据指针
/// \param unDataSize 数据大小
/// \return 是否发送成功
bool CFndMdClient::SendRequestOneCtpSubscribe( bool bSubscribeFlag, EN_MD_ID enMarketId, REQ_SUB_INSTRUMENT &subCode )
{
	MD_BASE mdrequest( bSubscribeFlag ? MARKET_SUB : MARKET_UNSUB, CTP_ALL, sizeof(REQ_SUB_INSTRUMENT), (unsigned char *)&subCode );

	return m_ptrNetClient->SendDataToServerWithHB( mdrequest.GetStream(), mdrequest.GetStreamLength() );
}

/// \brief 发送请求给服务器 -- 请求历史数据（获取K线）
/// \param reqKLine	请求K线信息
/// \return 是否发送成功
bool CFndMdClient::SendRequestHisKLine( REQ_HIS_KLINE & reqKLine )
{
	MD_BASE mdrequest( MARKET_HIS, HIS_KLINE, sizeof(REQ_HIS_KLINE), (unsigned char *)&reqKLine );

	return m_ptrNetClient->SendDataToServerWithHB( mdrequest.GetStream(), mdrequest.GetStreamLength() );
}

/// \brief 发送请求给服务器 -- 自定义
/// \param pbData 数据指针
/// \param unDataSize 数据大小
/// \return 是否发送成功
bool CFndMdClient::SendRequestUserDefine( const unsigned char *pbData, unsigned int unDataSize )
{
	//if ( m_ptrNetClient && m_bConnect )
	//{
	//	return m_ptrNetClient->SendDataToServerWithHB( pbData, unDataSize );
	//}

	return false;
}

/// \brief 与服务器断开网络连接
void CFndMdClient::CloseSocket()
{
	if ( m_ptrNetClient )
	{
		m_ptrNetClient->CloseSocket();
	}
}


/// \brief 连接服务器回调函数，由nStatus指定连接是否成功。
void CFndMdClient::OnConnected(int nStatus)
{
	printf( "OnConnected, status=%d\n", nStatus );

	if ( nStatus==E_CONNECT_SUCCESS )
		m_bConnect = true;
	else
		m_bConnect = false;

	if ( m_ptrMdClientNotify )
		m_ptrMdClientNotify->OnConnected( (ENU_CONNECT_STATUS)nStatus );

	
	//不是用户请求断开，自动重连
	if ( E_CONNECT_SUCCESS!=nStatus )
	{
		q_sleep( 5000 );
		
		printf( "OnConnected 中重连\n" );
		m_ptrNetClient->ConnectServerWithHB( m_szSrvIP, m_usPort, false, m_unTimeOut );
	}
}

/// \brief Socket连接断开回调
void CFndMdClient::OnDisconnected(int nStatus)
{
	printf( "OnDisconnected, status=%d\n", nStatus );

	m_bConnect = false;

	if ( m_ptrMdClientNotify )
		m_ptrMdClientNotify->OnDisconnected( ENU_DISCONNECT_STATUS(nStatus) );

	//不是用户请求断开，自动重连
	if ( E_CONNECT_SUCCESS!=nStatus )
	{
		q_sleep( 5000 );
		
		printf( "OnDisconnected 中重连\n" );
		m_ptrNetClient->ConnectServerWithHB( m_szSrvIP, m_usPort, false, m_unTimeOut );
	}

}

/// \brief 从服务器接收到数据回调(回调函数应复制数据后，立即返回，否则影响接收效率，有心跳方式阻塞时间不得超过15s，否则断线)
/// \param pbData 数据指针(函数调用后即释放，勿超范围使用，勿在函数中删除)
/// \param unDataSize 数据大小
void CFndMdClient::OnRawData(const unsigned char* pbData, unsigned int unDataSize)
{
#if 1
	//printf( "Client recv data, len=%d\n", unDataSize );

	MD_BASE md( pbData, unDataSize );

	EN_MD_CMD enCmdID = md.GetCmd();

	switch ( enCmdID )
	{
	case BASE_INFO:	//基础信息
		{
			EN_BASE_INFO_ID id = (EN_BASE_INFO_ID)md.GetID();
			switch( id )
			{
			case BASE_INFO_STOCK:	//股票码表（码表）（逐一获取，服务器端逐一推送）
				{
					if ( md.GetBodyLength()!=sizeof(STOCK_CODE_ITEM) )
						return;	//Error

					// 提交给外部APP
					if ( m_ptrMdClientNotify )
					{
						//m_ptrMdClientNotify->OnBaseInfoStock( *((STOCK_CODE_ITEM*)md.GetBodyHeader()) );

						BASE_INFO_CODE_GROUP codetbl;
						codetbl.header.nNum = 1;
						codetbl.header.nID	= BASE_INFO_STOCK;
						codetbl.ptrCodes	= (STOCK_CODE_ITEM*)md.GetBodyHeader();

						m_ptrMdClientNotify->OnBaseInfoStock( codetbl );
					}
				}
				break;

			case BASE_INFO_STOCK_ONCE:	//股票基础信息（码表）	（一次性获取，服务器端一次性推送）
				{
					if ( md.GetBodyLength()<sizeof(BODY_HEADER) )
						return;	//Error

					BASE_INFO_CODE_GROUP codetbl;
					memcpy( (void*)(&(codetbl.header)), (void*)md.GetBodyHeader(), sizeof(BODY_HEADER) );
					if ( md.GetBodyLength() != codetbl.header.nNum * sizeof(STOCK_CODE_ITEM) + sizeof(BODY_HEADER) )
						return;	//Error

					codetbl.ptrCodes = (STOCK_CODE_ITEM *)( md.GetBodyHeader() + sizeof(BODY_HEADER) );

					// 提交给外部APP
					if ( m_ptrMdClientNotify )
					{
						//m_ptrMdClientNotify->OnBaseInfoStock( *((STOCK_CODE_ITEM*)md.GetBodyHeader()) );
						m_ptrMdClientNotify->OnBaseInfoStock( codetbl );
					}
				}
				break;

			default:
				{
				}
				break;
			}
		}
		break;

	case MARKET_TICK_SNAP:	//行情订阅 全市场 服务器端推送的快照
	case MARKET_SNAP:		//快照
		{
			EN_MD_ID id = (EN_MD_ID)md.GetID();
			switch( id )
			{
			case STOCK_L1_ONCE:
				{
					if ( md.GetBodyLength()<sizeof(BODY_HEADER) )
						return;	//Error

					SNAP_STOCK_GROUP snap;
					memcpy( &(snap.header), md.GetBodyHeader(), sizeof(BODY_HEADER) );
					if ( md.GetBodyLength() != snap.header.nNum * sizeof(STOCK_MARKET) + sizeof(BODY_HEADER) )
						return;	//Error

					snap.ptrStockSnap = (STOCK_MARKET *)( md.GetBodyHeader() + sizeof(BODY_HEADER) );

					// 提交给外部APP
					if ( m_ptrMdClientNotify )
					{
						m_ptrMdClientNotify->OnMarketDataStockSnap( enCmdID==MARKET_TICK_SNAP, snap );
					}
				}
				break;

			case CTP_ALL_ONCE:
				{
					if ( md.GetBodyLength()<sizeof(BODY_HEADER) )
						return;	//Error

					SNAP_CTP_GROUP snap;
					memcpy( &(snap.header), md.GetBodyHeader(), sizeof(BODY_HEADER) );
					if ( md.GetBodyLength() != snap.header.nNum * sizeof(CTP_MD_SNAP) + sizeof(BODY_HEADER) )
						return;	//Error

					snap.ptrCtpSnap = (CTP_MD_SNAP *)( md.GetBodyHeader() + sizeof(BODY_HEADER) );

					// 提交给外部APP
					if ( m_ptrMdClientNotify )
					{
						m_ptrMdClientNotify->OnMarketDataCtpSnap( enCmdID==MARKET_TICK_SNAP, snap );
					}
				}
				break;

			case STOCK_L1:
				{
					if ( md.GetBodyLength()!=sizeof(STOCK_MARKET) )
						return;	//Error

					// 提交给外部APP
					if ( m_ptrMdClientNotify )
					{
						SNAP_STOCK_GROUP snap_one;
						snap_one.header.nNum	= 1;
						snap_one.header.nID		= STOCK_L1;
						snap_one.ptrStockSnap	= (STOCK_MARKET*)md.GetBodyHeader();

						m_ptrMdClientNotify->OnMarketDataStockSnap( enCmdID==MARKET_TICK_SNAP, snap_one );
					}
				}
				break;

			case CTP_ALL:
				{
					if ( md.GetBodyLength()!=sizeof(CTP_MARKET_DATA_ITEM) )
						return;	//Error

					// 提交给外部APP
					if ( m_ptrMdClientNotify )
					{
						CTP_MARKET_DATA_ITEM *ctp_item = (CTP_MARKET_DATA_ITEM *)md.GetBodyHeader();

						SNAP_CTP_GROUP snap;
						snap.header.nID = CTP_ALL;
						snap.header.nNum = 1;
						snap.ptrCtpSnap = &(ctp_item->_field);

						m_ptrMdClientNotify->OnMarketDataCtpSnap( enCmdID==MARKET_TICK_SNAP, snap );
					}
				}
				break;

			default:
				{
				}
				break;
			}
		}
		break;

	case MARKET_SUB:	//行情订阅 单个代码 获取到的快照
		{
			EN_MD_ID id = (EN_MD_ID)md.GetID();

			switch( id )
			{
			case STOCK_L1:
				{
					if ( md.GetBodyLength()!=sizeof(STOCK_MARKET) )
						return;	//Error

					// 提交给外部APP
					if ( m_ptrMdClientNotify )
					{
						m_ptrMdClientNotify->OnSubscribeStock( *((PTR_STOCK_MARKET)md.GetBodyHeader()) );
					}
				}
			}//switch
		}
		break;
	
	case MARKET_TICK:		//行情订阅 全市场 服务器端主动推送的实时数据
		{
			EN_MD_ID id = (EN_MD_ID)md.GetID();

			switch( id )
			{
			case STOCK_L1:
				{
					if ( md.GetBodyLength()!=sizeof(STOCK_MARKET) )
						return;	//Error

					// 提交给外部APP
					if ( m_ptrMdClientNotify )
					{
						m_ptrMdClientNotify->OnSubscribeStock( *((PTR_STOCK_MARKET)md.GetBodyHeader()) );
					}
				}
				break;

			case CTP_ALL:	//
				{
					if ( md.GetBodyLength()!=sizeof(CTP_MARKET_DATA_ITEM) )
						return;	//Error

					// 提交给外部APP
					if ( m_ptrMdClientNotify )
					{
						CTP_MARKET_DATA_ITEM* ptrData = (CTP_MARKET_DATA_ITEM*)md.GetBodyHeader();

						m_ptrMdClientNotify->OnSubscribeCtp( ptrData->_field );
					}
				}
				break;
			/*
			case STOCK_L1_ONCE:
				{
					if ( md.GetBodyLength()<sizeof(BODY_HEADER) )
						return;	//Error

					SNAP_STOCK_GROUP snap;
					memcpy( &(snap.header), md.GetBodyHeader(), sizeof(BODY_HEADER) );
					if ( md.GetBodyLength() != snap.header.nNum * sizeof(STOCK_MARKET) + sizeof(BODY_HEADER) )
						return;	//Error

					snap.ptrStockSnap = (STOCK_MARKET *)( md.GetBodyHeader() + sizeof(BODY_HEADER) );

					// 提交给外部APP
					if ( m_ptrMdClientNotify )
					{
						//m_ptrMdClientNotify->OnSubscribeStock( *((PTR_STOCK_MARKET)md.GetBodyHeader()) );
						m_ptrMdClientNotify->OnMarketDataStockSnap( snap );	//返回订阅全市场的快照
					}
				}
				break;

			case CTP_ALL_ONCE:
				{
					if ( md.GetBodyLength()<sizeof(BODY_HEADER) )
						return;	//Error

					SNAP_CTP_GROUP snap;
					memcpy( &(snap.header), md.GetBodyHeader(), sizeof(BODY_HEADER) );
					if ( md.GetBodyLength() != snap.header.nNum * sizeof(CTP_MD_SNAP) + sizeof(BODY_HEADER) )
						return;	//Error

					snap.ptrCtpSnap = (CTP_MD_SNAP *)( md.GetBodyHeader() + sizeof(BODY_HEADER) );

					// 提交给外部APP
					if ( m_ptrMdClientNotify )
					{
						m_ptrMdClientNotify->OnMarketDataCtpSnap( snap );
					}
				}
				break;
				*/
			}//switch
		}
		break;

	case MARKET_UNSUB:	//取消行情订阅（没有Response）
		{
			EN_MD_ID id = (EN_MD_ID)md.GetID();
			switch( id )
			{
			case STOCK_L1:
				{
				}
				break;

			case CTP_ALL:
				{
				}
				break;
			}
		}
		break;

	case MARKET_HIS:	//历史数据
		{
			EN_HIS_DATA_TYPE type = (EN_HIS_DATA_TYPE)md.GetID();
			
			switch ( type )
			{
			case HIS_KLINE:
				{
					if ( md.GetBodyLength()<sizeof(REPLY_HIS_KLINE) )
						return;	//Error

					REPLY_HIS_KLINE body_header;
					memcpy( &body_header, md.GetBodyHeader(), sizeof(REPLY_HIS_KLINE) );
					switch( body_header.enKLineType )
					{
						case KLINE_DAY:
							{
								int nKLineNum = body_header.nCurKLineNum;
								if ( md.GetBodyLength()==sizeof(REPLY_HIS_KLINE) + nKLineNum*sizeof(KLINE_DAY_ITEM) )
								{
									// 解析出所有K线
									//KLINE_DAY_ITEM KLine;
									//for ( int i=0; i<nKLineNum; i++ )
									//{
									//	memcpy( &KLine, md.GetBodyHeader() + sizeof(REPLY_HIS_KLINE) + i*sizeof(KLINE_DAY_ITEM), sizeof(KLINE_DAY_ITEM) );
									//}

									// 提交给外部APP
									if ( m_ptrMdClientNotify )
									{
										m_ptrMdClientNotify->OnHisDataKline( body_header, (KLINE_DAY_ITEM*)(md.GetBodyHeader() + sizeof(REPLY_HIS_KLINE)) );
									}
								}

								//
							}
							break;

					case KLINE_WEEK:
					case KLINE_MONTH:
					case KLINE_QUARTER:
					case KLINE_HALFYEAR:
					case KLINE_YEAR:

					case KLINE_1MINUTE:
					case KLINE_5MINUTES:
					case KLINE_15MINUTES:
					case KLINE_30MINUTES:
					case KLINE_60MINUTES:
					case KLINE_4HOURS:
						{
						}
						break;
					}
				}
				break;

			case HIS_DEALS:
				{
				}
				break;

			case HIS_TREND:
				{
				}
				break;

			}
		}
	}//switch

#else
	char *szTmp = new char[unDataSize+1];
	memcpy( szTmp, pbData, unDataSize );
	szTmp[unDataSize]='\0';
	printf( "App recv:%s, len=%d\n", szTmp, unDataSize );
	delete szTmp;
#endif

}
