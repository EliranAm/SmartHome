#include "SmartHome.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <pthread.h>

#include "../Parser/IParser.h"
#include "../Parser/XmlParser.h"
#include "../Device/IDeviceLogic.h"
#include "../Device/AirCondDevice.h"
#include "../Device/DeviceLogicFactory.h"
#include "../Sensor/SensorLogicFactory.h"
#include "../PubSub/ISubscriber.h"
#include "../SensorController/SensorControllerFactory.h"
#include "../SensorController/ISensorController.h"
#include "../PubSub/IRouter.h"

#include "Test_t.h"



#define KEY_LENGTH (4)

// "for_each" functions
void StopController(pair<SENSOR_TYPE, ISensorController*> _controller);
void DestroyDevice(IDeviceLogic* _device);
void DestroyController(pair<SENSOR_TYPE, ISensorController*> _controller);


SmartHome::~SmartHome() 
{
	for_each(m_devices.begin(), m_devices.end(), DestroyDevice);
	for_each(m_sensorControllers.begin(), m_sensorControllers.end(), DestroyController);
}

void DestroyController(pair<SENSOR_TYPE, ISensorController*> _controller)
{
	delete _controller.second;
}

void DestroyDevice(IDeviceLogic* _device)
{
	delete _device;
}

bool SmartHome::Initialize(IRouter* _router, IParser* _parser)
{
	if (!_router || !_parser)
	{
		return false;
	}
	
	m_router = _router;
	m_parser = _parser;

	vector<string> initVector;
	IParser::Type type;
	do
	{
		try 
		{
			type = m_parser->GetElement(initVector);
		}
		catch(const exception& ex)
		{
			cout << ex.what() << endl;
			return false;
		}
		if (type == IParser::E_DEVICE)
		{
			if (!AddDevice(initVector))
			{
				return false;
			}
		}
		else if (type == IParser::E_SENSOR)
		{
			if (!AddSensor(initVector))
			{
				return false;
			}
		}
	} while (type != IParser::E_FINISH);
	return true;
}

bool SmartHome::AddDevice(const vector<string>& initVector)
{
	IDeviceLogic* newDevice = DeviceLogicFactory::Create(initVector[0]);
	if(!newDevice)
	{
		return false;
	}
	
	m_devices.insert(m_devices.end(), newDevice);

	vector<string>::const_iterator itrBegin = initVector.begin() + 1;
	vector<string>::const_iterator itrEnd = initVector.end();
	while (itrBegin != itrEnd)
	{
		if (!m_router->Subscribe(dynamic_cast<ISubscriber*>(newDevice), *itrBegin))
		{
			return false;
		}
		++itrBegin;
	}

	return true;
}

bool SmartHome::AddSensor(const vector<string>& initVector)
{
	string key = initVector[0].substr(0, KEY_LENGTH);
	SensorControllerMap_t::iterator itr;
	itr = m_sensorControllers.find(key);
	
	if (itr == m_sensorControllers.end())
	{
		ISensorController* newController = SensorControllerFactory::Create(key);
		if (!newController)
		{	
			return false;
		}
		
		if (!newController->SetRouter(m_router))
		{	
			delete newController;
			return false;
		}
		m_sensorControllers.insert(m_sensorControllers.end(), pair<SENSOR_TYPE, ISensorController*>(key, newController));
	}
	
	ISensorLogic* newSensor = SensorLogicFactory::Create(initVector);
	if (!newSensor)
	{	
		return false;
	}
	
	m_testSensors.insert(m_testSensors.end(), newSensor);
	if (!m_sensorControllers[key]->AddSensor(newSensor))
	{	
		return false;
	}
	return true;
}

void SmartHome::RunSmartHome() throw (runtime_error)
{
	pthread_t tid = 0;
	SensorControllerMap_t::iterator currItr = m_sensorControllers.begin();
	SensorControllerMap_t::iterator endItr = m_sensorControllers.end();
	
	while (currItr != endItr)
	{
		tid = (currItr->second)->RunController();
		if (!tid)
		{
			throw runtime_error("Cant run controllers!");
		}
		
		m_controllersThreads.push_back(tid);
		++currItr;
	}

	m_routerTid = m_router->RunRouter();
	if (!m_routerTid)
	{
		throw runtime_error("Cant run router!");
	}
	m_controllersThreads.push_back(tid);
	
	Test_t test(m_testSensors);
	test.RunTest();
}

void SmartHome::StopSmartHome()
{
	for_each(m_sensorControllers.begin(), m_sensorControllers.end(), StopController);
	m_router->StopRouter();
	JoinAllThreads();
}

void SmartHome::JoinAllThreads() const
{
	vector<pthread_t>::const_iterator currItr = m_controllersThreads.begin();
	vector<pthread_t>::const_iterator endItr = m_controllersThreads.end();

	while (currItr != endItr)
	{
		pthread_join(*currItr, NULL);
		++currItr;
	}
	
	pthread_join(m_routerTid, NULL);
}

void StopController(pair<SENSOR_TYPE, ISensorController*> _controller)
{
	_controller.second->StopController();
}


