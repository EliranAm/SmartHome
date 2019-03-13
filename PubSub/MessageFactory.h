#ifndef __MESSAGE_FACTORY_H__
#define __MESSAGE_FACTORY_H__

#include <string>
using namespace std;

class IMessage;


class MessageFactory
{
	public:
	static IMessage* Create(const string& _type);
		
	private:
		MessageFactory();
		virtual ~MessageFactory();


};



#endif /* __MESSAGE_FACTORY_H__ */
