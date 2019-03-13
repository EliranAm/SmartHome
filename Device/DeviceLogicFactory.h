#ifndef __DEVICE_LOGIC_FACTORY_H__
#define __DEVICE_LOGIC_FACTORY_H__


#include <string>
using namespace std;

class IDeviceLogic;


class DeviceLogicFactory
{
	public:
		static IDeviceLogic* Create(const string& _type); //AICO or FIRE
		
	private:
		DeviceLogicFactory();
		virtual ~DeviceLogicFactory();
};


#endif /* __DEVICE_LOGIC_FACTORY_H__ */
