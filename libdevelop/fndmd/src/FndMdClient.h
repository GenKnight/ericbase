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

	/// \brief ������������TCP������
	/// \param szIP ������IP
	/// \param usPort �������˿�
	/// \param blAuth �Ƿ���֤(�ݲ�֧��)
	/// \param unTimeOut ��ʱʱ��(��λ��)
	virtual void ConnectMdServer( const char *szIP, unsigned short usPort, unsigned int unTimeOut = 0 );

	/// \brief ��������������� -- ������Ϣ
	/// \param pbData ����ָ��
	/// \param unDataSize ���ݴ�С
	/// \return �Ƿ��ͳɹ�
	virtual bool SendRequestBaseInfo( EN_BASE_INFO_ID enBaseInfoId, bool bGetOnce=false );

	/// \brief ��������������� -- ��Ʊ����
	/// \param pbData ����ָ��
	/// \param unDataSize ���ݴ�С
	/// \return �Ƿ��ͳɹ�
	virtual bool SendRequestStockSnap( bool bSnapOnce=false );

	/// \brief ��������������� -- CTP����
	/// \param pbData ����ָ��
	/// \param unDataSize ���ݴ�С
	/// \return �Ƿ��ͳɹ�
	virtual bool SendRequestCtpSnap( bool bSnapOnce=false );

	/// \brief ��������������� -- [����/ȡ������]ȫ�г�ʵʱ����
	/// \param enMarketId		[����/ȡ������]֤ȯ�г���Id
	/// \return �Ƿ��ͳɹ�
	virtual bool SendRequestMarketSubscribe( EN_MD_ID enMarketId );

	/// \brief ��������������� -- [����/ȡ������]��Ʊ�г�ʵʱ����
	/// \param bSubscribeFlag	���ı�־ true--���� false--ȡ������
	/// \param enMarketId		[����/ȡ������]������г�Id
	/// \param subCode			[����/ȡ������]����
	/// \return �Ƿ��ͳɹ�
	virtual bool SendRequestOneStockSubscribe( bool bSubscribeFlag, EN_MD_ID enMarketId, REQ_SUB_INSTRUMENT &subCode );

	/// \brief ��������������� -- ����Ctp�г�ʵʱ���飨Ԥ��--�ݲ�֧�֣���
	/// \param bSubscribeFlag	���ı�־ true--���� false--ȡ������
	/// \param enMarketId		[����/ȡ������]������г�Id
	/// \param subCode			[����/ȡ������]����
	/// \return �Ƿ��ͳɹ�
	virtual bool SendRequestOneCtpSubscribe( bool bSubscribeFlag, EN_MD_ID enMarketId, REQ_SUB_INSTRUMENT &subCode );

	/// \brief ��������������� -- ��ȡK��
	/// \param reqKLine	����K����Ϣ
	/// \return �Ƿ��ͳɹ�
	virtual bool SendRequestHisKLine( REQ_HIS_KLINE & reqKLine );

	/// \brief ��������������� -- �Զ���
	/// \param pbData ����ָ��
	/// \param unDataSize ���ݴ�С
	/// \return �Ƿ��ͳɹ�
	virtual bool SendRequestUserDefine( const unsigned char *pbData, unsigned int unDataSize );

	/// \brief ��������Ͽ���������
	virtual void CloseSocket();

	/// --- IFndNetClientNotify���ؽӿ� ---
	/*
		ע�⣺�����߳�ʱ���ԭ���п��ܳ���OnRawData������OnConnected�����õ������
		����ͬ���������ڻص����������д���
	*/
	/// \brief ���ӷ������ص���������nStatusָ�������Ƿ�ɹ���
	virtual void OnConnected( int nStatus );

	/// \brief �ӷ��������յ����ݻص�(�ص�����Ӧ�������ݺ��������أ�����Ӱ�����Ч�ʣ���������ʽ����ʱ�䲻�ó���15s���������)
	/// \param pbData ����ָ��(�������ú��ͷţ��𳬷�Χʹ�ã����ں�����ɾ��)
	/// \param unDataSize ���ݴ�С
	virtual void OnRawData(const unsigned char* pbData, unsigned int unDataSize);

	/// \brief �ӷ��������������쳣�ص�
	virtual void OnServerDataError() {};

	/// \brief Socket���ӶϿ��ص�
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

