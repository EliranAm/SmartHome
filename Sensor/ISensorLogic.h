#ifndef __ISENSOR_LOGIC_H__
#define __ISENSOR_LOGIC_H__

#include <string>
using namespace std;

class ISensorLogic
{
	public:
		ISensorLogic(){}
		virtual ~ISensorLogic(){}
		
		virtual const string& GetLocation() const = 0;
		virtual void  SetLocation(const string&) = 0;
		
		virtual bool  TestSensor() = 0;

	private:
		
};



#endif /* __ISENSOR_LOGIC_H__ */
