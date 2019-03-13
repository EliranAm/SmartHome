#include <exception>
#include "SensorControllerFactory.h"
#include "../SensorController/ISensorController.h"
#include "../SensorController/TempSensorController.h"
#include "../SensorController/SmokSensorController.h"



ISensorController* SensorControllerFactory::Create(const string& _type)
{
	ISensorController *controller = 0;
	
	try
	{
		if (!_type.compare("TEMP"))
		{
			controller = new TempSensorController;
		}
		else if (!_type.compare("SMOK"))
		{
			controller = new SmokeSensorController;
		}
	}
	catch (const exception& exp)
	{
		return 0;
	}
	
	return controller;
}




