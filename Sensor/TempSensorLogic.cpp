#include "TempSensorLogic.h"
#include "SensorFactory.h"
#include "../PubSub/MessageFactory.h"
#include "../PubSub/IRouter.h"
#include "../PubSub/IMessage.h"
#include "Sensor.h"
#include "TempSensor.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>


#define ATOI_OFFSET (4)
#define TURN_ON_MESSAGE  (*m_message[0])
#define TURN_OFF_MESSAGE (*m_message[1])

#define UPPER_LIMIT (_argVec[1].c_str())
#define LOWER_LIMIT (_argVec[3].c_str())
#define UPPER_LIM_PRIORITY (_argVec[2].c_str())
#define LOWER_LIM_PRIORITY (_argVec[4].c_str())


// "for_each" function
void DestroyTempMessage(IMessage * _message);


TempSensorLogic::TempSensorLogic(const string& _location, const vector<string>& _argVec)  throw (runtime_error)
{
	m_sensor = SensorFactory::Create("TEMP");
	if (!m_sensor)
	{
		throw runtime_error("Cant create sensor!");
	}
	
	m_router = 0;
	m_location = _location;

	m_lowerLimit = atoi(LOWER_LIMIT + ATOI_OFFSET);
	m_upperLimit = atoi(UPPER_LIMIT + ATOI_OFFSET);

	m_rangeCondition = 0;
	if (!SetMessageVec(_argVec))
	{
		delete m_sensor;
		m_sensor = 0;
		throw runtime_error("Cant create message!");
	}	
}

bool TempSensorLogic::SetMessageVec(const vector<string>& _argVec)
{
	IMessage *newMessage1 = MessageFactory::Create("ROUTER_MESSAGE");
	if (!newMessage1)
	{
		return false;
	}

	IMessage *newMessage2 = MessageFactory::Create("ROUTER_MESSAGE");
	if (!newMessage2)
	{
		delete newMessage1;
		newMessage1 = 0;
		return false;
	}
	
	newMessage1->SetTopic("TEMP" + m_location + UPPER_LIMIT);
	newMessage1->SetBody("OVER_UPPER_LIM");
	int priority = atoi(UPPER_LIM_PRIORITY);
	newMessage1->SetPriority(priority);
	m_message.push_back(newMessage1);
	
	newMessage2->SetTopic("TEMP" + m_location + LOWER_LIMIT);
	newMessage2->SetBody("UNDER_LOWER_LIM");
	priority = atoi(LOWER_LIM_PRIORITY);
	newMessage2->SetPriority(priority);
	m_message.push_back(newMessage2);
	
	return true;
}

TempSensorLogic::~TempSensorLogic()
{
	for_each(m_message.begin(), m_message.end(), DestroyTempMessage);
	delete m_sensor;
	m_sensor = 0;
}

void DestroyTempMessage(IMessage * _message)
{
	delete _message;
}

void TempSensorLogic::SetSensorOn()	
{
	dynamic_cast<TempSensor*>(m_sensor)->SetOn();
}

void TempSensorLogic::SetSensorOff()
{
	dynamic_cast<TempSensor*>(m_sensor)->SetOff();
}

bool TempSensorLogic::TestSensor()
{
	float measurement = 0;
	if (!m_router)
	{
		return false;
	}

	try
	{
		measurement = dynamic_cast<TempSensor*>(m_sensor)->GetMeasurement();
	}
	catch(const exception& exp)
	{
		return false;
	}

	if(measurement > m_upperLimit && !m_rangeCondition)
	{
		if(!m_router->Publish(this, TURN_ON_MESSAGE))
		{
			return false;
		}
		m_rangeCondition = 1;
	}
	
	if(measurement < m_lowerLimit && m_rangeCondition)
	{
		if(!m_router->Publish(this, TURN_OFF_MESSAGE))
		{
			return false;
		}
		m_rangeCondition = 0;
	}
	
	return true;
}

void TempSensorLogic::SetTemperature(float _temp)
{
	dynamic_cast<TempSensor*>(m_sensor)->SetTemperature(_temp);
}










