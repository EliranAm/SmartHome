#ifndef __SENSOR_CONTROLLER_FACTORY_H__
#define __SENSOR_CONTROLLER_FACTORY_H__

#include <string>

using namespace std;

class ISensorController;


class SensorControllerFactory
{
	public:
		static ISensorController* Create(const string& _type);
		
	private:
		SensorControllerFactory();
		virtual ~SensorControllerFactory();
};



#endif /* __SENSOR_CONTROLLER_FACTORY_H__ */
