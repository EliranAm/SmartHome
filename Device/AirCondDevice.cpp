#include "AirCondDevice.h"
#include <iostream>

using namespace std;



bool AirCondDevice::SetOn() 
{
	cout << "AC is on!" << endl;
	return m_power = true;
}

bool AirCondDevice::SetOff() 
{
	cout << "AC is off!" << endl;
	return m_power = false;
}
