#ifndef __TOPIC_H__
#define __TOPIC_H__


#include <string>
#include <set>

using namespace std;

class ISubscriber;
class IMessage;

typedef set<ISubscriber*> SubscriberSet_t;
typedef pair<SubscriberSet_t::iterator, bool> SubscriberPair_t;


class Topic
{
	public:
		explicit Topic(const string& _topicName) : m_topic(_topicName){}
		virtual ~Topic(){}
		
		virtual bool Attach(ISubscriber* _subscriber);
		virtual void Detach(const ISubscriber* _subscriber);
		virtual void Notify(const IMessage& _message) const;
		
		const string& GetTopic() const {return m_topic;}
        const SubscriberSet_t& GetSubscribers() const {return m_subscribers;}
	
	private:
		Topic(const Topic& _topic);
		const Topic& operator=(const Topic& _topic);
		
		SubscriberSet_t m_subscribers;
		const string m_topic; //Key
};



#endif /* __TOPIC_H__ */
