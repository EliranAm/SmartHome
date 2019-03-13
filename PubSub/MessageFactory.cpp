#include "MessageFactory.h"
#include "../PubSub/IMessage.h"
#include "../PubSub/Message.h"



IMessage* MessageFactory::Create(const string& _type)
{
	IMessage *newMessage = 0;
	
	try
	{
		if(!_type.compare("ROUTER_MESSAGE"))
		{
			newMessage = new Message;
		}
	}
	catch (const exception& exp)
	{
		return 0;
	}
	
	return newMessage;
}


