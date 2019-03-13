#ifndef __SENSOR_LOGIC_FACTORY_H__
#define __SENSOR_LOGIC_FACTORY_H__

#include <string>
#include <vector>

using namespace std;


class ISensorLogic;


class SensorLogicFactory
{
	public:
		static ISensorLogic* Create(const vector<string>& _args); // TEMP or SMOK
		
	private:
		SensorLogicFactory();
		virtual ~SensorLogicFactory();
};



#endif /* __SENSOR_LOGIC_FACTORY_H__ */
