#include "SmokeControllerThread.h"
#include "../SensorController/SmokSensorController.h"
#include "../Sensor/ISensorLogic.h"
#include <iterator>

#define NANO_IN_MILI (1000000)
#define NANO_TO_SLEEP ((NANO_IN_MILI) * 5)


SmokeControllerThread::SmokeControllerThread(void* _args) : Thread(_args)
{
    m_sleep.tv_sec = 0;
    m_sleep.tv_nsec = NANO_TO_SLEEP;
	m_stopFlag = true;
}

void* SmokeControllerThread::ThreadAction()
{
	vector<ISensorLogic*> *smokeSensors = (vector<ISensorLogic*> *)m_tArg;

	while(m_stopFlag)
	{
		vector<ISensorLogic*>::const_iterator currItr = smokeSensors->begin();
		vector<ISensorLogic*>::const_iterator endItr = smokeSensors->end();
		for(; currItr != endItr; ++currItr)
		{
			(*currItr)->TestSensor();
		}

		while(nanosleep(&m_sleep,&m_sleep));
	}
	return this;
}
		
		
