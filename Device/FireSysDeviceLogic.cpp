#include "FireSysDeviceLogic.h"
#include "DeviceFactory.h"
#include "../PubSub/IMessage.h"
#include "FireSysDevice.h"
#include "Device.h"
#include <iostream>



FireSysDeviceLogic::FireSysDeviceLogic(const string& _location) : m_location(_location)
{
	m_device = DeviceFactory::Create("FIRE_SYS");
}

FireSysDeviceLogic::~FireSysDeviceLogic()
{
	delete m_device;
	m_device = 0;
}

bool FireSysDeviceLogic::SetOn()
{
	cout << m_location << " - ";
	return dynamic_cast<FireSysDevice*>(m_device)->SetOn();
}

bool FireSysDeviceLogic::SetOff()
{
	cout << m_location << " - ";
	return dynamic_cast<FireSysDevice*>(m_device)->SetOff();
}

void FireSysDeviceLogic::SetLocation(const string& _location)
{
	m_location = _location;
}

bool FireSysDeviceLogic::Action(const IMessage& _message)
{
	bool res = false;
	string messageBody = _message.GetBody();

	if (!messageBody.compare("FIRE"))
	{
		SetOn();
		res = true;
	}
	else if (!messageBody.compare("NO_FIRE"))
	{
		SetOff();
		res = true;
	}
	
	return res;
}


