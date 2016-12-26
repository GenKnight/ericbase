#ifndef FUANDA_REQUEST_ADAPTER_H
#define FUANDA_REQUEST_ADAPTER_H
/*******************************************************************************
@ name


@ function

@ exception
throw std::bad_cast exception.

--------------------------------------------------------------------------------
@ history ver 1.0 @
@ records: ujoy modifyed on 2013-01-01.
1.create and init this class.


--------------------------------------------------------------------------------
* copyright(c) 2013 - 2015, ujoy, reserved all right.

*******************************************************************************/

namespace serverframe{;

////////////////////////////////////////////////////////////////////////////////
class RequestAdapter
{
public:
	/*@ message handle function that translate "message" to "message" and
	dispatch it to "message_handler".
	* @ throw std::bad_cast exception.
	* @ tmpl.message: message being translate from "para.context".
	* @ tmpl.message_handler: message handler to handle message.
	* @ para.context: context message being dispatched to message handler.
	* @ para.id: context request typeid.
	*/
	template<typename tcp_context_t, typename handler_t>
	inline static void Handle(IN std::shared_ptr<tcp_context_t>& cont)
	{
		// handle request.
		std::shared_ptr<handler_t> handler(new handler_t);
		handler->OnRequest(*cont);
	}
};

////////////////////////////////////////////////////////////////////////////////
}// serverframe
#endif