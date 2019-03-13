#ifndef __IMESSAGE_H__
#define __IMESSAGE_H__

#include <string>

using namespace std;


class IMessage
{
	public:
		IMessage(){}
		virtual ~IMessage(){}

		virtual const string& GetTopic() const = 0;
		virtual const string& GetBody() const = 0;
		virtual int   GetPriority() const = 0;
		
		virtual void  SetTopic(const string& _newTopic) = 0;
		virtual void  SetBody(const string& _newBody) = 0;
		virtual void  SetPriority(int _priority) = 0;

	private:
};





#endif /* __IMESSAGE_H__ */
