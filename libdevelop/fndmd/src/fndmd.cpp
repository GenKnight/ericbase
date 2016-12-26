// fndmd.cpp : ���� DLL Ӧ�ó���ĵ���������
//
#include "IFndMdClient.h"
#include "FndMdClient.h"

#ifdef _WIN32

extern "C"
{
	/// \brief ��������ͻ��˶���
	/// \param poNotifyObj ͨ������ָ��
	/// \return ����ͻ��˶���ָ��
	__declspec(dllexport) IFndMdClient* FndCreateMdClient( IFndMdClientNotify* poNotifyObj )
	{
		return new CFndMdClient( poNotifyObj );
	}

	/// \brief �ͷ�����ͻ��˶���
	/// \param poClientInstance ����ͻ��˶���ָ��
	__declspec(dllexport) void FndDeleteMdClient( IFndMdClient* poClientInstance )
	{
		if ( poClientInstance )
		{
			delete poClientInstance;
		}
	}
}

#else
	IFndMdClient* FndCreateMdClient( IFndMdClientNotify* poNotifyObj )
	{
		return new CFndMdClient( poNotifyObj );
	}

	void FndDeleteMdClient( IFndMdClient* poClientInstance )
	{
		if ( poClientInstance )
		{
			delete poClientInstance;
		}
	}
#endif