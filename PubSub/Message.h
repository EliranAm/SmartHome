#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include <string>
#include "IMessage.h"



using namespace std;


class Message : public IMessage
{
	public:
		Message(){}
		Message(const string& _topic, const string& _body, int _priority);

		virtual ~Message(){}
		
		virtual const string& GetTopic() const {return m_topic;} 
		virtual const string& GetBody() const {return m_body;}
		virtual int  GetPriority() const {return m_priority;}

		virtual void SetTopic(const string& _newTopic) {m_topic = _newTopic;}
		virtual void SetBody(const string& _newBody) {m_body = _newBody;}
		virtual void SetPriority(int _priority) {m_priority = _priority;}
		
		virtual bool operator<(const Message& _message) {return (m_priority < _message.m_priority);} //for priority_queue

	private:
		Message(const Message& _message);
		const Message& operator=(const Message& _message);
	
		string m_topic;
		string m_body;
		int  m_priority;
};



#endif /* __MESSAGE_H__ */

