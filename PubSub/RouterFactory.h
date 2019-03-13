#ifndef __ROUTER_FACTORY_H__
#define __ROUTER_FACTORY_H__

#include <string>
using namespace std;

class IRouter;


class RouterFactory
{
	public:
		static IRouter* Create(const string& _type); //HOME
		
	private:
		RouterFactory();
		virtual ~RouterFactory();
};



#endif /* __ROUTER_FACTORY_H__ */
