#include "OrderInsertHandler.h"

#include "../task/TaskInterfaceDef.h"
#include "../../../proto/ReqSubSystemInfo.pb.h"
#include "../../../proto/ReqSubProcessListInfo.pb.h"
#include "../../../proto/parse.h"
namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////
void OrderInsertHandler::OnRequest(IN AmqContext& context)
{
	try 
	{
		probuf_msg_ptr msg_ptr(decode(context));

		google::protobuf::Message* pMsg = msg_ptr.get();

		if ( pMsg && pMsg->GetDescriptor() == machine::ReqSubSystemInfo::descriptor() )
		{
			machine::ReqSubSystemInfo* pReq = dynamic_cast<machine::ReqSubSystemInfo*>(pMsg);

			if ( pReq && pReq->has_userid() )
			{
                std::cout << pReq->machine().ip() << std::endl;
                std::cout << pReq->machine().mac() << std::endl;
                std::cout << pReq->bissub() << std::endl;
				std::cout << pReq->userid() << std::endl;  
			}
			
		}

		return;
	}
	catch (...)
	{
		
	}
}


////////////////////////////////////////////////////////////////////////////////
}// serverframe