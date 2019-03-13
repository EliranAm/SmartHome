#ifndef __TEMP_SENSOR_CONTROLLER_H__
#define __TEMP_SENSOR_CONTROLLER_H__

#include <vector>
#include "ISensorController.h"
#include <exception>
#include <stdexcept>

using namespace std;


class ISensorLogic;
class IRouter;
class Thread;


class TempSensorController : public ISensorController
{
	public:
		TempSensorController();		
		virtual ~TempSensorController();

		virtual bool AddSensor(ISensorLogic* _sensorLogic);
		virtual ISensorLogic* RemoveSensor(const string& _location);
		
		virtual bool     SetRouter(IRouter *_router);
		const   IRouter *GetRouter() const {return m_router;}
		
		virtual pthread_t RunController() throw (bad_alloc, runtime_error);
		virtual void StopController();
		
	private:
		TempSensorController(const TempSensorController& _control);
		const TempSensorController& operator=(const TempSensorController& _control);
	
		vector<ISensorLogic*>  m_tempSensors;	
		Thread				  *m_tempThread;	
		IRouter				  *m_router;
};



#endif /* __TEMP_SENSOR_CONTROLLER_H__ */
