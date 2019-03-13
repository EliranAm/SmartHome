#ifndef __SMART_HOME_H__
#define __SMART_HOME_H__


#include <vector>
#include <map>
#include <string>
#include <exception>
#include <stdexcept>


#define SENSOR_TYPE string

using namespace std;

class IRouter;
class IDeviceLogic;
class ISensorController;
class IParser;
class ISensorLogic;

typedef map<SENSOR_TYPE, ISensorController*> SensorControllerMap_t;



class SmartHome
{
	public:
		SmartHome(){}
		virtual ~SmartHome();

		virtual bool Initialize(IRouter* _router, IParser* _parser);
		virtual void RunSmartHome() throw (runtime_error);
		virtual void StopSmartHome();

	protected:
		virtual bool AddDevice(const vector<string>& initVector);
		virtual bool AddSensor(const vector<string>& initVector);
		virtual void JoinAllThreads() const;
	
	private:
		SmartHome(const SmartHome&);
		const SmartHome& operator=(const SmartHome&);

		vector<ISensorLogic*> m_testSensors;
		vector<IDeviceLogic*> m_devices;
		SensorControllerMap_t m_sensorControllers;
		vector<pthread_t>	  m_controllersThreads;
		pthread_t 			  m_routerTid;
		IRouter*  			  m_router;
		IParser*			  m_parser;
};


#endif // __SMART_HOME_H__
