#include <iostream>
#include <exception>
#include <stdexcept>
#include "SmartHome.h"
#include "../PubSub/IRouter.h"
#include "../PubSub/Router.h"
#include "../PubSub/RouterFactory.h"
#include "../Parser/XmlParser.h"
#include "../Parser/IParser.h"
#include "../Parser/ParserFactory.h"

using namespace std;
#include <unistd.h>



int main()
{
	IRouter* router = 0;
	IParser* parser = 0;
	
	try
	{
		SmartHome home;
		router = RouterFactory::Create("HOME");
		parser = ParserFactory::Create("XML");
		home.Initialize(router, parser);
		home.RunSmartHome();
		home.StopSmartHome();
	}
	catch(const exception& ex)
	{
		cout << ex.what() << endl;
	}

	delete router;
	delete parser;
	return 0;
}



