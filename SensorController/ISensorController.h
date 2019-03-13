#ifndef __ISENSOR_CONTROLLER_H__
#define __ISENSOR_CONTROLLER_H__

#include <string>
using namespace std;


class IRouter;
class ISensorLogic;


class ISensorController
{
	public:
		ISensorController(){}
		virtual ~ISensorController(){}

		virtual bool AddSensor(ISensorLogic* _sensorLogic) = 0;
		virtual ISensorLogic* RemoveSensor(const string& _location) = 0;

		virtual bool SetRouter(IRouter *_router) = 0;
		virtual pthread_t RunController() = 0;
		virtual void StopController() = 0;

	private:
};


#endif /* __ISENSOR_CONTROLLER_H__ */
