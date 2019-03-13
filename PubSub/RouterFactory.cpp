#include "RouterFactory.h"
#include "../PubSub/Router.h"



IRouter* RouterFactory::Create(const string& _type)
{
	IRouter *router = 0;
	
	try
	{
		if (!_type.compare("HOME"))
		{
			router = new Router;
		}
	}
	catch (const exception& exp)
	{
		return 0;
	}
		
	return router;
}


