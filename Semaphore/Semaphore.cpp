#include "Semaphore.h"




Semaphore::Semaphore()
{
	sem_init(&m_semaphore, 0, 0);
}

Semaphore::~Semaphore()
{
	sem_destroy(&m_semaphore);
}

void Semaphore::Post()
{
	sem_post(&m_semaphore);
}

void Semaphore::Wait()
{
	sem_wait(&m_semaphore);
}

