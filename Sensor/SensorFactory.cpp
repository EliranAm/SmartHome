#include "SensorFactory.h"

#include "../Sensor/TempSensor.h"
#include "../Sensor/SmokeSensor.h"
#include "../Sensor/Sensor.h"



Sensor* SensorFactory::Create(const string& _type)
{
	Sensor *newSensor = 0;
	
	try
	{
		if(!_type.compare("TEMP"))
		{
			newSensor = new TempSensor;
		}
		else if(!_type.compare("SMOK"))
		{
			newSensor = new SmokeSensor;
		}
	}
	catch (const exception& exp)
	{
		return 0;
	}
	
	return newSensor;
}
