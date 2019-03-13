#include "Mutex.h"


Mutex::Mutex()
{
	m_mutex = new pthread_mutex_t; 
	pthread_mutex_init(m_mutex, 0);
}

Mutex::~Mutex()
{
	pthread_mutex_destroy(m_mutex);
	delete m_mutex;
	m_mutex = 0;
}

int Mutex::Lock()
{
	return pthread_mutex_lock(m_mutex);
}

int Mutex::Unlock()
{
	return pthread_mutex_unlock(m_mutex);
}

