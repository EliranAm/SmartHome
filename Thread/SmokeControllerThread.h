#ifndef __SMOKE_CONTROLLER_THREAD_H__
#define __SMOKE_CONTROLLER_THREAD_H__

#include <time.h>
#include <sys/time.h>
#include "Thread.h"
#include <vector>



class SmokeControllerThread : public Thread
{
	public:
    	explicit SmokeControllerThread(void* _args);
    	virtual ~SmokeControllerThread(){}

    	virtual void* ThreadAction();
    	
		virtual bool GetFlag() const {return m_stopFlag;}
		virtual void SetFlag(bool _flag) {m_stopFlag = _flag;}

	private:
    	SmokeControllerThread(const SmokeControllerThread& _thread);
    	const SmokeControllerThread& operator=(const SmokeControllerThread& _thread);
    	
		bool m_stopFlag;
        struct timespec m_sleep;
};




#endif /* __SMOKE_CONTROLLER_THREAD_H__ */
