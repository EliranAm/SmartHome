#include "Locker.h"


Locker::Locker(pthread_mutex_t *_mutex)
{
	if (_mutex)
	{
		m_mutex = _mutex;
		pthread_mutex_lock(_mutex);
	}
}


Locker::~Locker()
{
	if (m_mutex)
	{
		pthread_mutex_unlock(m_mutex);
		m_mutex = 0;
	}
}
