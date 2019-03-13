#include "Thread.h"


void* ThreadApp(void *_this)
{
	Thread* thread = (Thread*)_this;
	return thread->ThreadAction();
}


Thread::Thread(void* _args) : m_tArg(_args), m_tid(0)
{
}

int Thread::RunThread()
{
	return pthread_create(&m_tid, NULL, ThreadApp, this);
}

void* Thread::GetArgs() const
{
	return m_tArg;
}

pthread_t Thread::GetTid() const
{
	return m_tid;
}		
		
		
		
		
