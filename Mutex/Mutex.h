#ifndef __MUTEX_H__
#define __MUTEX_H__

#include "IMutex.h"
#include <pthread.h>



class Mutex : public IMutex
{
	public:
		Mutex();
		virtual ~Mutex();

		virtual int Lock();
		virtual int Unlock();
	
	protected:
		pthread_mutex_t *m_mutex;
		
	private:
		Mutex(const Mutex& _mutex);
		const Mutex& operator=(const Mutex& _mutex);
};


#endif /* __MUTEX_H__ */
