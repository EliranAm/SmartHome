#ifndef __IDEVICE_LOGIC_H__
#define __IDEVICE_LOGIC_H__

#include <string>

using namespace std;


class IDeviceLogic
{
	public:
		IDeviceLogic(){}
		virtual ~IDeviceLogic(){}
		
		virtual const string& GetLocation() const = 0;
		virtual void  SetLocation(const string& _location) = 0;

	private:
		
};


#endif /* __IDEVICE_LOGIC_H__ */
