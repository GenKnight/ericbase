#ifndef FUANDA_MESSAGE_QUEUE_H
#define FUANDA_MESSAGE_QUEUE_H
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
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <queue>
#include "Thread.h"
#include "State.h"
namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////
/*@ message queue state: this state is reference by ace message queue.
there are three state:
1.opened:
2.pulsed:
3.closed:
*/




////////////////////////////////////////////////////////////////////////////////
template<typename message_t>
class MessageQueue : public boost::noncopyable
{
////////////////////////////////////////////////////////////////////////////////
public:
	typedef message_t message;
	typedef MessageQueue<message_t> message_queue;

	// max size.
	enum {	kmax_size = 4096 };

	/*@ the message queue max message size.*/
	MessageQueue(IN const size_t full_size = kmax_size)
	{
		Open(full_size);
	}

	/*@ open message queue so that it can recv message.*/
	void Open(IN const size_t full_size = kmax_size)
	{
		m_full_size = (full_size > 0) ? full_size : kmax_size;
		m_state.Run();
	}

	inline bool IsOpen() const
	{
		return m_state.IsRunning();
	}

	/*@ close message queue so that it stop to recv message.*/
	void Close()
	{
		boost::unique_lock<boost::mutex> lock(m_mutex);

		// close message queue and wait all message be handled.
		m_state.Stop();
		thread::Wait(std::bind(&std::queue<message>::empty, &m_queue));

		// notify all thread to exit message queue.
		m_empty_cond_var.notify_all();
		m_full_cond_var.notify_all();
	}

	inline bool IsClose() const
	{
		return m_state.IsStoped();
	}

	/*@ post message to message queue.*/
	void Post(IN message& msg)
	{
		boost::unique_lock<boost::mutex> lock(m_mutex);
		while (IsFull() && !IsClose())
		{
			m_full_cond_var.wait(lock);
		}
		if (!IsFull() && !IsClose())
		{
			m_queue.push(msg);
			m_empty_cond_var.notify_one();
		}
	}

	/*@ pop message from this message queue.*/
	bool Take(message& msg)
	{
		boost::unique_lock<boost::mutex> lock(m_mutex);
		while (IsEmpty() && !IsClose())
		{
			m_empty_cond_var.wait(lock);
		}
		if (!IsEmpty() && !IsClose())
		{
			msg = m_queue.front();
			m_queue.pop();
			m_full_cond_var.notify_one();
			return true;
		}
		return false;
	}


private:
	inline bool IsEmpty() const
	{
		return m_queue.empty();
	}

	inline bool IsFull() const
	{
		return (m_queue.size() >= m_full_size);
	}

////////////////////////////////////////////////////////////////////////////////
private:
	State m_state;

	//  message queue max size.
	size_t m_full_size;

	// message queue data.
	std::queue<message> m_queue;

	// when message queue is full and empty, synchronous notify.
	boost::mutex m_mutex;
	boost::condition_variable m_full_cond_var;
	boost::condition_variable m_empty_cond_var;
};

}// serverframe
#endif