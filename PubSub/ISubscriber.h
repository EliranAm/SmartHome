#ifndef __ISUBSCRIBER_H__
#define __ISUBSCRIBER_H__

#include <string>

using namespace std;

class IMessage;


class ISubscriber
{
	public:
		ISubscriber(){}
		virtual ~ISubscriber(){}

		virtual bool Action(const IMessage& _message) = 0;
		

	private:
		
};



#endif /* __ISUBSCRIBER_H__ */
