#ifndef FUANDA_SERVER_HUB_H
#define FUANDA_SERVER_HUB_H
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
#include "DispatchServer.h"

namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////
class TcpServerHub
{
public:

	typedef std::string tcp_context;
	typedef DispatchServer<tcp_context> dispatch_server;
	typedef dispatch_server::message_dispatcher message_dispatcher;
	typedef dispatch_server::register_func register_func;

////////////////////////////////////////////////////////////////////////////////
public:
	/*@constructor. */
	TcpServerHub()
	{
	}

	/*@init handler map which contain the relationship of request and handler.
	*/
	inline void Register(IN register_func func)
	{
		m_dispatch_server.Register(func);
	}

	/*@start message server and dedicated service size. */
	inline void Run(IN const size_t server_size)
	{
		m_dispatch_server.Run(server_size);
	}

	/*@wait message server end. */
	inline void Join()
	{
		m_dispatch_server.Join();
	}

	/*@stop message server. */
	inline void Stop()
	{
		m_dispatch_server.Stop();
	}

////////////////////////////////////////////////////////////////////////////////
public:
	/*@ receive data from exist connection. */
	inline void OnRead( IN std::string& data)
	{
		try
		{
			// package message context.
			std::shared_ptr<tcp_context> cont(new tcp_context(data));
			m_dispatch_server.Post(cont);
		}
		catch (std::exception& ec)
		{
			std::cout << ec.what();
		}
	}

////////////////////////////////////////////////////////////////////////////////
protected:
	// request queue server.
	dispatch_server m_dispatch_server;
};

}//serverframe
////////////////////////////////////////////////////////////////////////////////
#endif