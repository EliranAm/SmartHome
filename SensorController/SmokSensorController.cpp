#include "SmokSensorController.h"
#include "../Sensor/ISensorLogic.h"
#include "../Sensor/SmokeSensorLogic.h"
#include "../Thread/SmokeControllerThread.h"
#include <algorithm>

// "for_each" functions
void DestroySmokeSensor(ISensorLogic* _sensorLogic);
void TurnOffSensors(ISensorLogic* _sensorLogic);
void TurnOnSensors(ISensorLogic* _sensorLogic);


SmokeSensorController::SmokeSensorController() : m_smokeThread(0), m_router(0)
{
}

SmokeSensorController::~SmokeSensorController() 
{
	for_each(m_smokeSensors.begin(), m_smokeSensors.end(), DestroySmokeSensor);
}

void DestroySmokeSensor(ISensorLogic* _sensorLogic)
{
	delete _sensorLogic;
}

bool SmokeSensorController::AddSensor(ISensorLogic* _sensorLogic)
{
	if (!_sensorLogic)
	{
		return false;
	}
	
	dynamic_cast<SmokeSensorLogic*>(_sensorLogic)->SetRouter(m_router);
	m_smokeSensors.push_back(_sensorLogic);
	return true;
}

ISensorLogic* SmokeSensorController::RemoveSensor(const string& _location)
{
	ISensorLogic* removedSensor = 0;
	vector<ISensorLogic*>::iterator currItr = m_smokeSensors.begin();
	vector<ISensorLogic*>::iterator endItr = m_smokeSensors.end();
	
	for (; currItr != endItr ; ++currItr)
	{
		if ((*currItr)->GetLocation() == _location)
		{
			removedSensor = *currItr;
			m_smokeSensors.erase(currItr);
		}
	}
	
	return removedSensor;
}

bool SmokeSensorController::SetRouter(IRouter *_router)
{
	vector<ISensorLogic*>::iterator currItr = m_smokeSensors.begin();
	vector<ISensorLogic*>::iterator endItr = m_smokeSensors.end();
	for (; currItr != endItr ; ++currItr)
	{
		dynamic_cast<SmokeSensorLogic*>(*currItr)->SetRouter(m_router);
	}
	
	m_router = _router;
	return true;
}

pthread_t SmokeSensorController::RunController() throw (bad_alloc, runtime_error)
{
	try
	{
		m_smokeThread = new SmokeControllerThread(&m_smokeSensors);
	}
	catch (const exception& exp)
	{
		throw;
	}
	
	if((m_smokeThread->RunThread()) != 0)
	{
        throw runtime_error("Cant run thread!");
    }
	return m_smokeThread->GetTid();
}

void SmokeSensorController::StopController()
{
	dynamic_cast<SmokeControllerThread*>(m_smokeThread)->SetFlag(false);
	delete m_smokeThread;
	m_smokeThread = 0;
}


