#ifndef __THREAD_H__
#define __THREAD_H__

#include <pthread.h>

class Thread
{
	public:
    	explicit Thread(void* _args);
    	virtual ~Thread(){}
    	
    	virtual int	  RunThread();
    	virtual void* ThreadAction() = 0;

    	virtual pthread_t GetTid() const;
    	virtual void* GetArgs() const;

	protected:
		void*	  m_tArg;
		pthread_t m_tid;

	private:
    	Thread(const Thread& _thread);
    	const Thread& operator=(const Thread& _thread);

};


#endif /* __THREAD_H__ */
