#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

#include "../Sensor/ISensorLogic.h"
#include "../Sensor/TempSensorLogic.h"
#include "../Sensor/SmokeSensorLogic.h"
#include "Test_t.h"

using namespace std;

#define NAME (name.c_str() + 2)


Test_t::Test_t(vector<ISensorLogic*>& _testSensors)
{
	m_testSensors = _testSensors;
}


void Test_t::RunTest() 
{
	bool cont	= true;			// trigger to stop loop
	while (cont) 
	{
		unsigned int c;
		cout << "Enter your choise:" << endl
			<< "1 - Print list of sensors" 	<< endl
			<< "2 - Choose sensor" 	<< endl
			<< "Any other key - quit"   << endl;
		cin >> c;

		switch (c) 
		{
			case 1:
				Print();
				break;
			case 2:
				SetValue();
				break;
			default:
				cont = false;	 
				break;
		}
	}
}

void Test_t::Print() const
{
	size_t index = 1;
	string name, location;
	vector<ISensorLogic*>::const_iterator itrBegin = m_testSensors.begin();
	vector<ISensorLogic*>::const_iterator itrEnd = m_testSensors.end();

	while (itrBegin != itrEnd)
	{
		name = typeid(*(*itrBegin)).name();
		location = (*itrBegin)->GetLocation();
		cout << index << ". " << NAME << "\t-\t" << location << endl;
		++index;
		++itrBegin;	
	}	
	cout << endl;
}

void Test_t::SetValue()
{
	size_t index;

	cout << "Enter sensor index: ";
	cin >> index;
	if (typeid(*m_testSensors[index-1]) == typeid(SmokeSensorLogic))
	{
		cout << "Is There any smoke in there? ";
		bool isSmoke;
		cin >> isSmoke;
		((SmokeSensorLogic*)m_testSensors[index-1])->SetSmokeState(isSmoke);
	}
	else
	{
		cout << "Enter the temperature: ";
		float newTemp;
		cin >> newTemp;
		((TempSensorLogic*)m_testSensors[index-1])->SetTemperature(newTemp);
	}
}


