#ifndef __FIRE_SYSTEM_DEVICE_H__
#define __FIRE_SYSTEM_DEVICE_H__


#include "Device.h"


class FireSysDevice : public Device
{
	public:
		FireSysDevice() : m_power(false){}
		virtual ~FireSysDevice(){}
		
		virtual bool SetOn();
		virtual bool SetOff();
		
	private:
		FireSysDevice(const FireSysDevice& _device);
		const FireSysDevice& operator=(const FireSysDevice& _device);

		bool m_power;
};



#endif /* __FIRE_SYSTEM_DEVICE_H__ */
