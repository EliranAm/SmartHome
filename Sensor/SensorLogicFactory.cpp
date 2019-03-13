#include "SensorLogicFactory.h"
#include "../Sensor/ISensorLogic.h"
#include "../Sensor/SmokeSensorLogic.h"
#include "../Sensor/TempSensorLogic.h"


#define TYPE_LENGTH (4)
#define BEGIN (0)

#define UPPER_LIMIT (_args.at(1))
#define LOWER_LIMIT (_args.at(2))


ISensorLogic* SensorLogicFactory::Create(const vector<string>& _args)
{
	ISensorLogic *sensor = 0;
	
	string typeNLocation = _args.at(0);
	string type = typeNLocation.substr(BEGIN, TYPE_LENGTH);
	string location = typeNLocation.substr(TYPE_LENGTH);

	try
	{
		if (!type.compare("TEMP"))
		{
			sensor = new TempSensorLogic(location, _args);
		}
		else if (!type.compare("SMOK"))
		{
			sensor = new SmokeSensorLogic(location, _args);
		}
	}
	catch (const exception& exp)
	{
		return 0;
	}

	return sensor;
}



