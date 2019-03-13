#ifndef __SMOKE_SENSOR_CONTROLLER_H__
#define __SMOKE_SENSOR_CONTROLLER_H__

#include <vector>
#include "ISensorController.h"
#include <exception>
#include <stdexcept>



using namespace std;

class ISensorLogic;
class IRouter;
class Thread;


class SmokeSensorController : public ISensorController
{
	public:
		SmokeSensorController();
		virtual ~SmokeSensorController();

		virtual bool AddSensor(ISensorLogic* _sensorLogic);
		virtual ISensorLogic* RemoveSensor(const string& _location);

		virtual bool SetRouter(IRouter *_router);
		const   IRouter *GetRouter() const {return m_router;}

		virtual pthread_t RunController() throw (bad_alloc, runtime_error);
		virtual void 	  StopController();

	private:
		SmokeSensorController(const SmokeSensorController&);
		const SmokeSensorController& operator=(const SmokeSensorController&);
		
		vector<ISensorLogic*>	 m_smokeSensors;
		Thread					*m_smokeThread;
		IRouter					*m_router;
};



#endif /* __SMOKE_SENSOR_CONTROLLER_H__ */
