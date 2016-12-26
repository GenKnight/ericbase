#ifndef FUANDA_ASYN_COUNTER_H
#define FUANDA_ASYN_COUNTER_H
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
#include "Thread.h"



namespace serverframe{;
namespace thread{;
////////////////////////////////////////////////////////////////////////////////
// check whether object is release.
template<typename object_t>
inline bool IsReleased(IN std::weak_ptr<object_t>& obsv)
{
	return obsv.use_count() == 0;
}

// release shared_ptr object.
template<typename object_t>
inline void Release(IN std::shared_ptr<object_t>& obj)
{
	std::weak_ptr<object_t> obsv(obj);
	obj.reset();
	Wait(std::bind(&IsReleased<object_t>, std::ref(obsv)));
}//

////////////////////////////////////////////////////////////////////////////////
}// ns::thread
}//ns::afw
#endif