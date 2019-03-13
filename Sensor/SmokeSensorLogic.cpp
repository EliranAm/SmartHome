#include "SmokeSensorLogic.h"
#include "SensorFactory.h"
#include "../PubSub/MessageFactory.h"
#include "../PubSub/IRouter.h"
#include "../PubSub/IMessage.h"
#include "Sensor.h"
#include "SmokeSensor.h"
#include <stdlib.h>
#include <algorithm>


#define TURN_ON_MESSAGE  (*m_message[0])
#define TURN_OFF_MESSAGE (*m_message[1])

#define FIRE_PRIORITY	 (_argVec[2].c_str())
#define NO_FIRE_PRIORITY (_argVec[4].c_str())

// "for_each" function
void DestroySmokeMessage(IMessage * _message);


SmokeSensorLogic::SmokeSensorLogic(const string& _location, const vector<string>& _argVec) throw (runtime_error)
{
	m_sensor = SensorFactory::Create("SMOK");
	if (!m_sensor)
	{
		throw runtime_error("Cant create sensor!");
	}
	
	m_location = _location;
	m_router = 0;
	m_rangeCondition = 0;
	if (!SetMessageVec(_argVec))
	{
		delete m_sensor;
		m_sensor = 0;
		throw runtime_error("Cant create message!");
	}	
}

bool SmokeSensorLogic::SetMessageVec(const vector<string>& _argVec)
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

	newMessage1->SetTopic("SMOK" + m_location);
	newMessage1->SetBody("FIRE");
	int priority = atoi(FIRE_PRIORITY);
	newMessage1->SetPriority(priority);
	m_message.push_back(newMessage1);
	
	newMessage2->SetTopic("SMOK" + m_location);
	newMessage2->SetBody("NO_FIRE");
	priority = atoi(NO_FIRE_PRIORITY);
	newMessage2->SetPriority(priority);
	m_message.push_back(newMessage2);
	
	return true;
}

SmokeSensorLogic::~SmokeSensorLogic()
{
	for_each(m_message.begin(), m_message.end(), DestroySmokeMessage);
	delete m_sensor;
	m_sensor = 0;
}

void DestroySmokeMessage(IMessage * _message)
{
	delete _message;
}

void SmokeSensorLogic::SetSensorOn()	
{
	dynamic_cast<SmokeSensor*>(m_sensor)->SetOn();
}

void SmokeSensorLogic::SetSensorOff()
{
	dynamic_cast<SmokeSensor*>(m_sensor)->SetOff();
}

bool SmokeSensorLogic::TestSensor()
{
	bool smokeCheck = false;
	if (!m_router)
	{
		return false;
	}
	
	try
	{
		smokeCheck = dynamic_cast<SmokeSensor*>(m_sensor)->CheckForSmoke();
	}
	catch(const exception& exp)
	{
		return false;
	}
	
	if(smokeCheck && !m_rangeCondition)
	{
		if(!m_router->Publish(this, TURN_ON_MESSAGE))
		{
			return false;
		}
		m_rangeCondition = 1;
	}
	
	if(!smokeCheck && m_rangeCondition)
	{
		if(!m_router->Publish(this, TURN_OFF_MESSAGE))
		{
			return false;
		}
		m_rangeCondition = 0;
	}
	
	return true;
}

void SmokeSensorLogic::SetSmokeState(bool _isSmoke)
{
	dynamic_cast<SmokeSensor*>(m_sensor)->SetSmokeState(_isSmoke);
}






