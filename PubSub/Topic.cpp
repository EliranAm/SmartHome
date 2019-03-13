#include "Topic.h"
#include "IMessage.h"
#include "ISubscriber.h"
#include <algorithm>


bool Topic::Attach(ISubscriber* _subscriber)
{
	SubscriberPair_t ret = m_subscribers.insert(_subscriber);
	return ret.second;
}

void Topic::Detach(const ISubscriber* _subscriber)
{
	m_subscribers.erase((ISubscriber*)_subscriber);
}

void Topic::Notify(const IMessage& _message) const
{
	SubscriberSet_t::const_iterator currItr = m_subscribers.begin();
	SubscriberSet_t::const_iterator endItr = m_subscribers.end();

	while(currItr != endItr)
	{
		(*currItr)->Action(_message);
		++currItr;
	}
}



