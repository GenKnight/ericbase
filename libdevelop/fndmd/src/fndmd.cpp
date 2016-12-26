// fndmd.cpp : 定义 DLL 应用程序的导出函数。
//
#include "IFndMdClient.h"
#include "FndMdClient.h"

#ifdef _WIN32

extern "C"
{
	/// \brief 创建行情客户端对象
	/// \param poNotifyObj 通报对象指针
	/// \return 行情客户端对象指针
	__declspec(dllexport) IFndMdClient* FndCreateMdClient( IFndMdClientNotify* poNotifyObj )
	{
		return new CFndMdClient( poNotifyObj );
	}

	/// \brief 释放行情客户端对象
	/// \param poClientInstance 行情客户端对象指针
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