#ifndef __SEMAPHORE_H__
#define __SEMAPHORE_H__

#include "ISemaphore.h"
#include <semaphore.h>
#include <exception>
#include <stdexcept>

using namespace std;


class Semaphore
{
	public:
		Semaphore();
		~Semaphore();

		void Post();
		void Wait();

	protected:
		sem_t m_semaphore;		
};



#endif /* __SEMAPHORE_H__ */
