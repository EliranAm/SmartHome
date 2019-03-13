#ifndef __SENSOR_FACTORY_H__
#define __SENSOR_FACTORY_H__

#include <string>
using namespace std;

class Sensor;


class SensorFactory
{
	public:
		static Sensor* Create(const string& _type); //TEMP or SMOK
		
	private:
		SensorFactory();
		virtual ~SensorFactory();
};



#endif /* __SENSOR_FACTORY_H__ */
