////////////////////////////////////////////////////////////////////////////////
/// Copyright (c) 2011, Shanghai Flagship Prime Brokerage Technology LTD
/// All rights reserved.
///
/// Create engine task based on task id;
///
/// @version $Id: TaskFactory.h 1068 2012-02-14 07:46:19Z liuzq $
////////////////////////////////////////////////////////////////////////////////

#ifndef WORKPLAN_TASKFACTORY_H
#define WORKPLAN_TASKFACTORY_H
#include <memory>
#include "Mutex.h"
#include "EngineTask.h"

namespace itstation 
{
	/*
	*task enum list -- APP�����������Ͷ���
	*/
	enum TaskID{
		eRegister = 1,		//�û�ע��
		eLogin = 2,			//�û���¼

		eUnknownTaskID = 9999
	};
//�򵥹���ģʽ
class TaskFactory {
  private:
    explicit TaskFactory();
	virtual ~TaskFactory();

  public:
	static TaskFactory* getInstance();
	TaskID TaskCodeToTaskID(const int& code);
	std::shared_ptr<EngineTask> createEngineTask(ASSET_MESSAGE_STRUCT Message, session_ptr ptrSocket);

  protected:
    static TaskFactory* instance_;     
  
    static utility::Mutex m_mutex;

};

} //namespace itstation 
#endif
