#ifndef FUANDA_MESSAGE_SERVER_H
#define FUANDA_MESSAGE_SERVER_H
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
#include "MessageQueue.h"
#include "ThreadManager.h"
#include "Thread.h"
#include "State.h"
#include "AsynCounter.h"

namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////
template<typename message_t, typename message_handler>
class MessageServer : public boost::noncopyable
{
public:
	typedef message_t message;
	typedef MessageQueue<message> message_queue;

	typedef MessageServer<message_t, message_handler> message_server;
////////////////////////////////////////////////////////////////////////////////
public:
	inline MessageServer()
	{}

	inline ~MessageServer()
	{
		Stop();
	}

	/*@ start message server: start dispatch message and process it.
	* @ para.thread_size: how many threads to start, if equal to "0", message 
	server will run in a synchronous mode, else it will start number of threads 
	(decicated by "thread_size")and message server run in a asynchronous mode.
	*/
	void Run(IN const size_t thread_size)
	{
		// stop server when it is in a running state.
		Stop();

		// update server state.
		m_state.Run();

		// start work thread, if "thread_size"==0, this server will run in a 
		// synchronous mode and message queue will not be init.
		if (thread_size != 0)	// asynchronous mode
		{
			CreateMessageQueue();
			m_thread_pool.reset(new ThreadManager);
			m_thread_pool->Run(
				std::bind(&message_server::Work, this), thread_size);
		}
		// else {}				// synchronous mode
	}

	/*@ stop message server: stop message queue and thread pool. */
	void Stop()
	{
		// update server state to notify work thread.
		m_state.Stop();

		// close message queue.
		if (m_message_queue != nullptr)
		{
			m_message_queue->Close();
		}
		
		Join();	// wait server stop.

		// release message queue and wait it's using end.
		thread::Release(m_message_queue);
		thread::Release(m_thread_pool);
	}

	/*@ wait server stop.*/
	inline void Join()
	{
		std::shared_ptr<ThreadManager> thread_p = m_thread_pool;
		if (thread_p != nullptr)
		{
			thread_p->JoinAll();
		}
	}

public:
	/*@ push message to message server.
	* @ if server running in synchronous mode, process this message.
	* @ else push this message in message queue.
	*/
	inline void Post(IN message& msg)
	{
		if (m_state.IsStoped())
		{
			throw std::logic_error("message server is stopped.");
		}

		std::shared_ptr<message_queue> msg_q = m_message_queue;
		if (msg_q == nullptr)	// synchronous mode
		{
			Handle(msg);
		}
		else					// asynchronous mode
		{
			msg_q->Post(msg);
		}
	}
	inline void PostValue(IN message msg)
	{
		Post(msg);
	}

	/*@ get the message handler.*/
	inline message_handler& GetHandler()
	{
		return m_message_handler;
	}

////////////////////////////////////////////////////////////////////////////////
protected:
	/*@ work thread method.	*/
	virtual void Work()
	{
		while (m_state.IsRunning())
		{
			message msg;
			if (m_message_queue->Take(msg))
			{
				Handle(msg);
			}
		}// end while

		m_state.Stop();
	}

	inline void Handle(IN message& msg)
	{
		try
		{
			m_message_handler(msg);
		}
		catch (std::exception& err)
		{
			std::cout << "message dispatch handle error: " << err.what();
		}
		catch (...)
		{
			std::cout << "message dispatch handle unknown error.";
		}
	}

	inline void CreateMessageQueue()
	{
		if (m_message_queue == nullptr)
		{
			m_message_queue.reset(new message_queue());
		}
	}

////////////////////////////////////////////////////////////////////////////////
protected:
	// thread pool.
	std::shared_ptr<ThreadManager> m_thread_pool;

	// message queue.
	std::shared_ptr<message_queue> m_message_queue;

	message_handler m_message_handler;

	// message server state.
	State m_state;
};


////////////////////////////////////////////////////////////////////////////////
}// serverframe
#endif