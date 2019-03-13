#include "AirCondDeviceLogic.h"
#include "DeviceFactory.h"
#include "../PubSub/IMessage.h"
#include "AirCondDevice.h"
#include "Device.h"
#include <iostream>



AirCondDeviceLogic::AirCondDeviceLogic(const string& _location) : m_location(_location)
{
	m_device = DeviceFactory::Create("AIR_COND");
}

AirCondDeviceLogic::~AirCondDeviceLogic()
{
	delete m_device;
	m_device = 0;
}

bool AirCondDeviceLogic::SetOn()
{
	cout << m_location << " - ";
	return dynamic_cast<AirCondDevice*>(m_device)->SetOn();
}

bool AirCondDeviceLogic::SetOff()
{
	cout << m_location << " - ";
	return dynamic_cast<AirCondDevice*>(m_device)->SetOff();
}

void AirCondDeviceLogic::SetLocation(const string& _location)
{
	m_location = _location;
}

bool AirCondDeviceLogic::Action(const IMessage& _message)
{
	bool res = false;
	string messageBody = _message.GetBody();

	if (!messageBody.compare("OVER_UPPER_LIM"))
	{
		SetOn();
		res = true;
	}
	else if (!messageBody.compare("UNDER_LOWER_LIM") || !messageBody.compare("FIRE"))
	{
		SetOff();
		res = true;
	}
	
	return res;
}


