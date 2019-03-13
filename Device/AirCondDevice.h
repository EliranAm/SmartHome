#ifndef __AIR_COND_DEVICE_H__
#define __AIR_COND_DEVICE_H__

#include "Device.h"


class AirCondDevice : public Device
{
	public:
		AirCondDevice() : m_power(false){}
		virtual ~AirCondDevice(){}
		
		virtual bool SetOn();
		virtual bool SetOff();
		
	private:
		AirCondDevice(const AirCondDevice& _device);
		const AirCondDevice& operator=(const AirCondDevice& _device);

		bool m_power;
};





#endif /* __AIR_COND_DEVICE_H__ */
