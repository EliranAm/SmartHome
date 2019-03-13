#ifndef __ROUTER_THREAD_H__
#define __ROUTER_THREAD_H__


#include "Thread.h"

class RouterThread: public Thread
{
	public:
     	explicit RouterThread(void* _args);
    	virtual ~RouterThread(){}

    	virtual void* ThreadAction();
    	
		virtual bool GetFlag() const {return m_stopFlag;}
		virtual void SetFlag(bool _flag) {m_stopFlag = _flag;}

	private:
    	RouterThread(const RouterThread& _thread);
    	const RouterThread& operator=(const RouterThread& _thread);
    	
    	bool m_stopFlag;

};



#endif /* __ROUTER_THREAD_H__ */

