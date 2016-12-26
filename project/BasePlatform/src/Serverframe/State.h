#ifndef FUANDA_STATE_H
#define FUANDA_STATE_H
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
#include <boost/atomic/atomic.hpp>




namespace serverframe{;
////////////////////////////////////////////////////////////////////////////////
class State
{
protected:
	/*@ state state flag. 
	* @
	*/
	enum {
		prepare = 0,
		running,
		paused,
		stoped,
	};

public:
	State() : m_value(prepare)
	{}

	/*@ set state: */
	inline void Run()
	{
		m_value = running;
	}
	inline void Pause()
	{
		m_value = paused;
	}
	inline void Stop()
	{
		m_value = stoped;
	}

public:
	/*@ get state: */
	inline bool IsRunning() const
	{
		return m_value == running;
	}
	inline bool IsPaused() const
	{
		return m_value == paused;
	}
	inline bool IsStoped() const
	{
		return m_value == stoped;
	}

private:
	boost::atomic<int> m_value;
};


////////////////////////////////////////////////////////////////////////////////
}// serverframe
#endif