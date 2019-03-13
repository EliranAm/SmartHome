#include "RouterThread.h"
#include "../PubSub/IMessage.h"
#include "../PubSub/Topic.h"
#include "../PubSub/IRouter.h"
#include "../PubSub/Router.h"
#include "../Mutex/Mutex.h"
#include "../Semaphore/Semaphore.h"




RouterThread::RouterThread(void* _args) : Thread(_args), m_stopFlag(true)
{
}

void* RouterThread::ThreadAction()
{
	Router *router = (Router*)m_tArg;

	while(m_stopFlag)
	{
		router->m_queueSem->Wait();
		if(!router->m_messages.empty())
		{
			router->m_messageMutex->Lock();
			const IMessage *newMessage = router->m_messages.top();
			router->m_messages.pop();
			router->m_messageMutex->Unlock();
			
			string newTopic = newMessage->GetTopic();
			Topic *topic = router->m_topics[newTopic];
			topic->Notify(*newMessage);
		}
	}	

	return 0;
}


