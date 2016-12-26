//#include "include_common.h"
#include <string.h>
#include "EngineEnvironment.h"
#include "Applog.h"

namespace itstation {
	bool GetExeDir( char *exeDir, int size )
	{
#ifdef WIN32
		GetModuleFileName(NULL, exeDir, size);
		char drive[_MAX_DRIVE];
		char dir[_MAX_DIR];
		char fname[_MAX_FNAME];
		char ext[_MAX_EXT];

		_splitpath( exeDir, drive, dir, fname, ext);
		_makepath( exeDir, drive, dir, NULL, NULL);
		return true;
#else
		int rval;
		char* last_slash;

		//���������� /proc/self/exe ��Ŀ��
		rval = readlink ("/proc/self/exe", exeDir, size);
		if (rval == -1) //readlink����ʧ��
		{
			strcpy( exeDir, "./" );
			return false;
		}
		exeDir[rval] = '\0';
		last_slash = strrchr (exeDir, '/');
		if ( NULL == last_slash || exeDir == last_slash )//һЩ�쳣���ڷ���
		{
			strcpy( exeDir, "./" );
			return false;
		}
		size = last_slash - exeDir;
		exeDir[size+1] = '\0';
#endif
		return true;
	}

	EngineEnvironment EngineEnvironment::instance_;

	EngineEnvironment::EngineEnvironment() {
		do{
			char* env_data;
			env_data = getenv("CONFIG_FILE_PATH");
			if(env_data)
			{
				config_file_path = env_data;
			}else
			{
				char szExePath[260]={0};
				GetExeDir( szExePath, 256 );
				config_file_path = std::string(szExePath) + "db.conf";
			}

			return;
		}while(false);
	}

	EngineEnvironment::~EngineEnvironment() 
	{
	}

    EngineEnvironment* EngineEnvironment::getInstance()
    {        
        return &instance_;
    }

}  //namespace itstation
