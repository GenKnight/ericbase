#ifndef FUANDA_THREAD_THREAD_H
#define FUANDA_THREAD_THREAD_H
/*******************************************************************************
@ name

@ function


@ note

--------------------------------------------------------------------------------
@ history ver 1.0 @
@ records: ujoy modifyed on 2013-01-01.
1.create and init this class.


--------------------------------------------------------------------------------
* copyright(c) 2013 - 2015, ujoy, reserved all right.

*******************************************************************************/
#include <boost/thread/thread.hpp>
#define IN


namespace serverframe{;
namespace thread{;
////////////////////////////////////////////////////////////////////////////////
inline void Sleep(IN const uint32_t mill_secs)
{
	if (mill_secs > 0)
	{
		boost::this_thread::sleep(boost::posix_time::milliseconds(mill_secs));
	}
}


////////////////////////////////////////////////////////////////////////////////
typedef std::function<bool (void)> checker_func;
////////////////////////////////////////////////////////////////////////////////
inline void Wait(
	IN checker_func checker,
	IN uint32_t unit_mill_sec = 50)
{
	if (unit_mill_sec < 10)
	{
		unit_mill_sec = 10;
	}

	// 条件不满足并且没有超时，则继续等待。
	while (!checker())
	{
		boost::this_thread::sleep(
			boost::posix_time::milliseconds(unit_mill_sec));
	}
}


////////////////////////////////////////////////////////////////////////////////
inline bool TimedWait(
	IN checker_func checker,
	IN const uint32_t timeout_mill_secs,
	IN uint32_t unit_mill_sec = 100)
{
	if (unit_mill_sec < 10)
	{
		unit_mill_sec = 10;
	}

	// 条件不满足并且没有超时，则继续等待。
	uint32_t count_mill_secs = 0;
	while (!checker() && count_mill_secs < timeout_mill_secs)
	{
		boost::this_thread::sleep(
			boost::posix_time::milliseconds(unit_mill_sec));
		count_mill_secs += unit_mill_sec;
	}
	// 条件满足返回成功，否则返回失败。
	return count_mill_secs < timeout_mill_secs;
}




////////////////////////////////////////////////////////////////////////////////
}//ns::thread
}//serverframe
#endif