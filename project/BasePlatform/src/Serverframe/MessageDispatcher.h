#ifndef FUANDA_MESSAGE_DISPATCHER_H
#define FUANDA_MESSAGE_DISPATCHER_H
/*******************************************************************************
@ name


@ function


--------------------------------------------------------------------------------
@ history ver 1.0 @
@ records: ujoy modifyed on 2013-01-01.
1.create and init this class.


--------------------------------------------------------------------------------
* copyright(c) 2013 - 2015, ujoy, reserved all right.

*******************************************************************************/
#include "RequestAdapter.h"
#include <unordered_map>
#include <google/protobuf/message.h>
#include "../task/TaskInterfaceDef.h"
#include "../../../proto/parse.h"
namespace serverframe{;

////////////////////////////////////////////////////////////////////////////////
template<typename protocol_t>
class Dispatcher
{
public:
	typedef std::function<void (IN std::shared_ptr<protocol_t>&)> handler_func;

protected:
	// message and message handler map.
	typedef std::unordered_map<const google::protobuf::Descriptor*, handler_func> handler_map;
	typedef typename handler_map::const_iterator const_iterator;

public:
	/*@ constructor.*/
	Dispatcher() : m_default_handler(NULL)
	{}

	/*@ dispatch message to message handler.
	* @ para.msg: message to be dispatched.
	*/
	inline void Dispatch(IN std::shared_ptr<protocol_t>& msg) const
	{
		// get message type id.
		const google::protobuf::Descriptor *type = getDescriptor(*msg);
		//memcpy(&type, msg.get(), sizeof(int));

		const_iterator it = m_handler_map.find(type);
		if (it != m_handler_map.end())
		{
			it->second(msg);
		}
		else
		{
			m_default_handler(msg);
		}
	}

public:
	handler_map m_handler_map;

	// default message handler to process unregistered message type.
	handler_func m_default_handler;
};



////////////////////////////////////////////////////////////////////////////////
template<typename protocol_t>
class MessageDispatcher : public Dispatcher<protocol_t>
{
public:
	typedef Dispatcher<protocol_t> super;
	typedef typename super::handler_func handler_func;

	/*@ register message and message handler, and message dedicated by typeid.
	* @ tmpl.message: message type to be registered.
	* @ tmpl.handler_t: to handle "tmpl.message" type.
	* @ para.id: message type id to identify message type.
	*/
	template<typename handler_t>
	inline void Route(IN const google::protobuf::Descriptor* id)
	{
		handler_func func = &RequestAdapter::Handle<protocol_t, handler_t>;
		super::m_handler_map[id] = func;
	}

	/*@ register default message handler to process unregistered message type.
	* @ tmpl.handler_t: default message handler.
	*/
	template<typename handler_t>
	inline void RouteDefault()
	{
		handler_func func = &RequestAdapter::Handle<protocol_t, handler_t>;
		super::m_default_handler = func;
	}
};


////////////////////////////////////////////////////////////////////////////////
}// serverframe
#endif