#include "FireSysDevice.h"

#include <iostream>
using namespace std;


bool FireSysDevice::SetOn() 
{
	cout << "Sprinklers are on!" << endl;
	return m_power = true;
}

bool FireSysDevice::SetOff() 
{
	cout << "Sprinklers are off!" << endl;
	return m_power = false;
}



