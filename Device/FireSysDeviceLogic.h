#ifndef __FIRE_SYSTEM_DEVICE_LOGIC_H__
#define __FIRE_SYSTEM_DEVICE_LOGIC_H__

#include "IDeviceLogic.h"
#include "../PubSub/ISubscriber.h"

#include <string>

using namespace std;

class IMessage;
class Device;


class FireSysDeviceLogic : public IDeviceLogic, public ISubscriber
{
	public:
		explicit FireSysDeviceLogic(const string& _location);
		virtual ~FireSysDeviceLogic();

		virtual bool SetOn();
		virtual bool SetOff();
		
		virtual const string& GetLocation() const {return m_location;}
		virtual void SetLocation(const string& _location);

		virtual bool Action(const IMessage& _message);

	private:
		FireSysDeviceLogic(const FireSysDeviceLogic&);
		const FireSysDeviceLogic& operator=(const FireSysDeviceLogic&);
		
		string 	 m_location;
		Device  *m_device;
};



#endif /* __FIRE_SYSTEM_DEVICE_LOGIC_H__ */
