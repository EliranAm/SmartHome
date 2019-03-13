#ifndef __AIR_COND_DEVICE_LOGIC_H__
#define __AIR_COND_DEVICE_LOGIC_H__

#include <string>
#include "IDeviceLogic.h"
#include "../PubSub/ISubscriber.h"

using namespace std;

class Device;
class IMessage;


class AirCondDeviceLogic : public IDeviceLogic, public ISubscriber
{
	public:
		explicit AirCondDeviceLogic(const string& _location);
		virtual ~AirCondDeviceLogic();

		virtual bool SetOn();
		virtual bool SetOff();
		
		virtual const string& GetLocation() const {return m_location;}
		virtual void SetLocation(const string& _location);
		
		virtual bool Action(const IMessage& _message);

	private:
		AirCondDeviceLogic(const AirCondDeviceLogic&);
		const AirCondDeviceLogic& operator=(const AirCondDeviceLogic&);
		
		string	 m_location;
		Device  *m_device;
};


#endif /* __AIR_COND_DEVICE_LOGIC_H__ */
