#include "TempSensorController.h"
#include "../Sensor/ISensorLogic.h"
#include "../Sensor/TempSensorLogic.h"
#include "../Thread/TempContrellerThread.h"
#include <algorithm> 

// "for_each" function
void DestroyTempSensor(ISensorLogic* _sensorLogic);


TempSensorController::TempSensorController() : m_tempThread(0), m_router(0)
{
}

TempSensorController::~TempSensorController() 
{
	for_each(m_tempSensors.begin(), m_tempSensors.end(), DestroyTempSensor);
}

void DestroyTempSensor(ISensorLogic* _sensorLogic)
{
	delete _sensorLogic;
}

bool TempSensorController::AddSensor(ISensorLogic* _sensorLogic)
{
	if (!_sensorLogic)
	{
		return false;
	}
	
	dynamic_cast<TempSensorLogic*>(_sensorLogic)->SetRouter(m_router);
	m_tempSensors.push_back(_sensorLogic);
	return true;
}

ISensorLogic* TempSensorController::RemoveSensor(const string& _location)
{
	ISensorLogic* removedSensor = 0;
	vector<ISensorLogic*>::iterator currItr = m_tempSensors.begin();
	vector<ISensorLogic*>::iterator endItr = m_tempSensors.end();
	
	for (; currItr != endItr ; ++currItr)
	{
		if ((*currItr)->GetLocation() == _location)
		{
			removedSensor = *currItr;
			m_tempSensors.erase(currItr);
		}
	}
	
	return removedSensor;
}

bool TempSensorController::SetRouter(IRouter *_router)
{
	if (!_router)
	{
		return false;
	}
	
	vector<ISensorLogic*>::iterator currItr = m_tempSensors.begin();
	vector<ISensorLogic*>::iterator endItr = m_tempSensors.end();
	
	for (; currItr != endItr ; ++currItr)
	{
		dynamic_cast<TempSensorLogic*>(*currItr)->SetRouter(_router);
	}
	
	m_router = _router;
	return true;
}

pthread_t TempSensorController::RunController() throw (bad_alloc, runtime_error)
{
	try
	{
		m_tempThread = new TempControllerThread(&m_tempSensors);
	}
	catch (const exception& exp)
	{
		throw;
	}
	
	if((m_tempThread->RunThread()) != 0)
	{
        throw runtime_error("Cant run thread!");
    }
	return m_tempThread->GetTid();
}

void TempSensorController::StopController()
{
	dynamic_cast<TempControllerThread*>(m_tempThread)->SetFlag(false);
	delete m_tempThread;
	m_tempThread = 0;
}


