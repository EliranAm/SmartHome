#ifndef __IMESSAGE_ROUTER_H__
#define __IMESSAGE_ROUTER_H__


#include <string>
#include <pthread.h>


using namespace std;

class ISubscriber;
class IMessage;
class Publisher;


class IRouter
{
	public:
		IRouter(){}	
		virtual ~IRouter(){}
		
		virtual bool Subscribe(ISubscriber* _sub, const string& _topicName) = 0;
		virtual bool UnSubscribe(const ISubscriber* _sub, const string& _topicName) = 0;
		virtual bool Publish(const Publisher* _publisher, const IMessage& _message) = 0;

		virtual pthread_t RunRouter() = 0;
		virtual void StopRouter() = 0;

	private:
		
};


#endif /* __IMESSAGE_ROUTER_H__ */
