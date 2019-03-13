#include <exception>
#include <stdexcept>
#include "ParserFactory.h"
#include "../Parser/IParser.h"
#include "../Parser/XmlParser.h"


IParser* ParserFactory::Create(const string& _type)
{
	IParser *parser = 0;
	
	try
	{
		if (!_type.compare("XML"))
		{
			parser = new XmlParser;
		}
	}
	catch (const exception& exp)
	{
		throw;
	}
	
	return parser;
}

