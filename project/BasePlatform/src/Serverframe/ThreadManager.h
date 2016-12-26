#ifndef FUANDA_THREAD_MANAGER_H
#define FUANDA_THREAD_MANAGER_H
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
#include <boost/thread/thread.hpp>


namespace serverframe{;


////////////////////////////////////////////////////////////////////////////////
class ThreadManager : public boost::noncopyable
{
public:
	/*@ start thread.
	* @ para.func: std::function object, it can use the "std::bind" method.
	*/
	template<typename service_func>
	void Run(
		IN service_func func,
		IN size_t service_size = 1)
	{
		for (size_t srv=0; srv<service_size; ++srv)
		{
			m_thread_group.create_thread(func);
		}
	}

	/*@ interupt all this thread.
	*/
	void InterruptAll()
	{
		m_thread_group.interrupt_all();
	}

	/*@ join all this thread.
	*/
	void JoinAll()
	{
		m_thread_group.join_all();
	}

private:
	boost::thread_group m_thread_group;
};



}// serverframe


////////////////////////////////////////////////////////////////////////////////
#endif