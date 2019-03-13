#include "Router.h"
#include "Topic.h"
#include "ISubscriber.h"
#include "Publisher.h"
#include "IMessage.h"
#include "../Mutex/Mutex.h"
#include "../Thread/RouterThread.h"
#include "../Semaphore/Semaphore.h"
#include <algorithm>


// destrtoy func for "for_each"
void Destroyer(pair<string, Topic*> _topic);


Router::Router() throw (bad_alloc)
{
	try
	{
		m_topicsMutex = new Mutex;
	}
	catch (const exception& exp)
	{
		throw;
	}
	
	try
	{
		m_messageMutex = new Mutex;
	}
	catch (const exception& exp)
	{
		delete m_topicsMutex;
		throw;
	}
	
	try
	{
		m_queueSem = new Semaphore;
	}
	catch (const exception& exp)
	{
		delete m_topicsMutex;
		delete m_messageMutex;
		throw;
	}
}


Router::~Router()
{
	m_topicsMutex->Lock();
	for_each(m_topics.begin(), m_topics.end(), Destroyer);
	m_topicsMutex->Unlock();
	
	delete m_topicsMutex;
	delete m_messageMutex;
	delete m_queueSem;
	
	m_topicsMutex = 0;
	m_messageMutex = 0;
	m_queueSem = 0;
}

void Destroyer(pair<string, Topic*> _topic)
{
	delete _topic.second;
}

bool Router::Subscribe(ISubscriber* _sub, const string& _topicName)
{
	m_topicsMutex->Lock();
	TopicsMap_t::const_iterator itr = m_topics.find(_topicName);
	if (itr != m_topics.end())
	{
		itr->second->Attach(_sub);
	}
	else
	{
		Topic *topic = 0;
		try
		{
			topic = new Topic(_topicName);
		}
		catch (const exception& exp)
		{
			return false;
		}
		
		topic->Attach(_sub);
		m_topics.insert(pair<string, Topic*>(_topicName, topic));
	}

	m_topicsMutex->Unlock();
	return true;
}

bool Router::UnSubscribe(const ISubscriber* _sub, const string& _topicName)
{
	bool res = false;

	m_topicsMutex->Lock();

	TopicsMap_t::iterator itr = m_topics.find(_topicName);
	if (itr != m_topics.end())
	{
		itr->second->Detach(_sub);
		res = true;
	}

	m_topicsMutex->Unlock();
	return res;
}

bool Router::Publish(const Publisher* _publisher, const IMessage& _message)
{
	bool res = false;

	m_messageMutex->Lock();

	TopicsMap_t::const_iterator itr = m_topics.find(_message.GetTopic());
	
	if (itr != m_topics.end())
	{
		m_messages.push(&_message);
		m_queueSem->Post();
		res = true;
	}

	m_messageMutex->Unlock();
	return res;
}

pthread_t Router::RunRouter()
{
	try
	{
		m_routerThread = new RouterThread(this);
	}
	catch (const exception& exp)
	{
		 return 0;
	}
	
	if((m_routerThread->RunThread()) != 0)
	{
        return 0;
    }
    return m_routerThread->GetTid();
}

void Router::StopRouter()
{
	dynamic_cast<RouterThread*>(m_routerThread)->SetFlag(false);
	m_queueSem->Post();
	delete m_routerThread;
	m_routerThread = 0;
}



