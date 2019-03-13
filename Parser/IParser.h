#ifndef __IPARSER_H__
#define __IPARSER_H__

#include <string>
#include <vector>

using namespace std;

class IParser
{
	public:
		enum Type {E_DEVICE, E_SENSOR, E_FINISH};
		IParser(){}
		virtual ~IParser(){}

		virtual Type GetElement(vector<string>& _vec) = 0;
};

#endif // __IPARSER_H__
