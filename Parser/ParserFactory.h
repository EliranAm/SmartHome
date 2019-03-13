#ifndef __PARSER_FACTORY_H__
#define __ROUTER_FACTORY_H__

#include <string>
using namespace std;

class IParser;


class ParserFactory
{
	public:
		static IParser* Create(const string& _type); //XML
		
	private:
		ParserFactory();
		virtual ~ParserFactory();
};



#endif /* __ROUTER_FACTORY_H__ */
