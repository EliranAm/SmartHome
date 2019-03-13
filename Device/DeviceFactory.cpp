#include <exception>
#include "DeviceFactory.h"
#include "../Device/Device.h"
#include "../Device/AirCondDevice.h"
#include "../Device/FireSysDevice.h"



Device* DeviceFactory::Create(const string& _type)
{
	Device *device = 0;
	
	try
	{
		if (!_type.compare("AIR_COND"))
		{
			device = new AirCondDevice;
		}
		else if (!_type.compare("FIRE_SYS"))
		{
			device = new FireSysDevice;
		}
	}
	catch (const exception& exp)
	{
		return 0;
	}
		
	return device;
}


