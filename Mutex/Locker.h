#ifndef __LOCKER_H__
#define __LOCKER_H__

#include <pthread.h>


class Locker
{
	public:
		explicit Locker(pthread_mutex_t *_mutex);
		virtual ~Locker();

	private:
		Locker(const Locker&);
		const Locker& operator=(const Locker&);
		
		pthread_mutex_t *m_mutex;
};



#endif /* __LOCKER_H__ */

