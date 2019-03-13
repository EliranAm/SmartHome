#include <exception>
#include "DeviceLogicFactory.h"
#include "../Device/AirCondDeviceLogic.h"
#include "../Device/FireSysDeviceLogic.h"

#define TYPE_LENGTH (4)
#define BEGIN (0)


IDeviceLogic* DeviceLogicFactory::Create(const string& _type)
{
	IDeviceLogic *device = 0;
	string type = _type.substr(BEGIN, TYPE_LENGTH);
	string location = _type.substr(TYPE_LENGTH);

	try
	{
		if (!type.compare("AICO"))
		{
			device = new AirCondDeviceLogic(location);
		}
		else if (!type.compare("FIRE"))
		{
			device = new FireSysDeviceLogic(location);
		}
	}
	catch (const exception& exp){}

	return device;
}


