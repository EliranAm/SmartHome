#ifndef __DEVICE_FACTORY_H__
#define __DEVICE_FACTORY_H__

#include <string>
using namespace std;

class Device;


class DeviceFactory
{
	public:
		static Device* Create(const string& _type); //AIR_COND or FIRE_SYS
		
	private:
		DeviceFactory();
		virtual ~DeviceFactory();
};



#endif /* __DEVICE_FACTORY_H__ */
