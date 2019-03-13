#include "TempContrellerThread.h"
#include "../Sensor/ISensorLogic.h"
#include "../SensorController/TempSensorController.h"
#include <iterator>

#define SEC_TO_SLEEP (1)

TempControllerThread::TempControllerThread(void* _args) : Thread(_args)
{
    m_sleep.tv_sec = 1;
    m_sleep.tv_nsec = 0;
	m_stopFlag = true;
}

void* TempControllerThread::ThreadAction()
{
	vector<ISensorLogic*> *tempSensors = (vector<ISensorLogic*> *)m_tArg; 
	
	while(m_stopFlag)
	{
		vector<ISensorLogic*>::const_iterator currItr = tempSensors->begin();
		vector<ISensorLogic*>::const_iterator endItr = tempSensors->end();
		for(; currItr != endItr; ++currItr)
		{
			(*currItr)->TestSensor();
		}

		while(nanosleep(&m_sleep,&m_sleep));
	}
	return this;
}
		
		
