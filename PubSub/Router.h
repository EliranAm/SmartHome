#ifndef __MESSAGE_ROUTER_H__
#define __MESSAGE_ROUTER_H__

#include <map>
#include <queue>

#include "IRouter.h"


using namespace std;

class Publisher;
class ISubscriber;
class IMessage;
class Topic;
class Mutex;
class Thread;
class Semaphore;


typedef map<string, Topic*> TopicsMap_t;
typedef priority_queue<const IMessage*> MessageQueue_t;


class Router : public IRouter
{
	friend class RouterThread;
	public:
		Router() throw (bad_alloc);
		virtual ~Router();
		
		virtual bool Subscribe(ISubscriber* _sub, const string& _topicName);
		virtual bool UnSubscribe(const ISubscriber* _sub, const string& _topicName);
		virtual bool Publish(const Publisher* _publisher, const IMessage& _message);
		
		virtual pthread_t RunRouter();
		virtual void StopRouter();
		
	private:
		Router(const Router& _router);
		const Router& operator=(const Router& _router);


		Thread			*m_routerThread;
		TopicsMap_t      m_topics;
		MessageQueue_t   m_messages;
		Semaphore		*m_queueSem;
		Mutex			*m_topicsMutex;
		Mutex			*m_messageMutex;
};



#endif /* __MESSAGE_ROUTER_H__ */
