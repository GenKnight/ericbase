#ifndef FUANDA_DISPATCH_SERVER_H
#define FUANDA_DISPATCH_SERVER_H
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



////////////////////////////////////////////////////////////////////////////////
#include "MessageServer.h"
#include "MessageDispatcher.h"

namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////
template<typename message_t>
class DispatchHandler
{
public:
	typedef MessageDispatcher<message_t> message_dispatcher;

	inline DispatchHandler()
	{

	}

	inline void operator()(IN std::shared_ptr<message_t>& msg)
	{
		m_dispatcher.Dispatch(msg);
	}

	message_dispatcher m_dispatcher;
};


////////////////////////////////////////////////////////////////////////////////
template<typename message_t>
class DispatchServer :
	public MessageServer< std::shared_ptr<message_t>, DispatchHandler<message_t> >
{
public:
	typedef MessageServer< std::shared_ptr<message_t>, DispatchHandler<message_t> > super;

	typedef typename DispatchHandler<message_t>::message_dispatcher message_dispatcher;

	typedef std::function<void (message_dispatcher&)> register_func;

	// constructor.
	inline DispatchServer()
	{}

	// init message handler map.
	inline void Register(IN register_func func)
	{
		if (func != nullptr)
		{
			func(GetDispatcher());
		}
	}

	// dispatcher
	inline message_dispatcher& GetDispatcher()
	{
		return super::m_message_handler.m_dispatcher;
	}
	inline const message_dispatcher& GetDispatcher() const
	{
		return super::m_message_handler.m_dispatcher;
	}
};


////////////////////////////////////////////////////////////////////////////////
}// serverframe
#endif