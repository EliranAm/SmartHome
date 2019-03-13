#ifndef __TEMP_CONTROLLER_THREAD_H__
#define __TEMP_CONTROLLER_THREAD_H__

#include <time.h>
#include <sys/time.h>
#include "Thread.h"
#include <vector>


class TempControllerThread : public Thread
{
	public:
    	explicit TempControllerThread(void* _args);
    	virtual ~TempControllerThread(){}

    	virtual void* ThreadAction();
		
		virtual bool GetFlag() const {return m_stopFlag;}
		virtual void SetFlag(bool _flag) {m_stopFlag = _flag;}

	private:
    	TempControllerThread(const TempControllerThread& _thread);
    	const TempControllerThread& operator=(const TempControllerThread& _thread);
    	
		bool m_stopFlag;
		struct timespec m_sleep;
};



#endif /* __TEMP_CONTROLLER_THREAD_H__ */
