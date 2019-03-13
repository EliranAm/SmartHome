#ifndef __SMOKE_SENSOR_LOGIC_H__
#define __SMOKE_SENSOR_LOGIC_H__

#include "ISensorLogic.h"
#include "../PubSub/Publisher.h"
#include <vector>
#include <exception>
#include <stdexcept>
#include <string>


class IRouter;
class Sensor;
class IMessage;


class SmokeSensorLogic : public ISensorLogic, public Publisher
{
	public:
		SmokeSensorLogic(const string& _location, const vector<string>& _argVec) throw (runtime_error);
		virtual ~SmokeSensorLogic();
		
		virtual void   SetSensorOn();
		virtual void   SetSensorOff();
		
		virtual void   SetRouter(IRouter *_router) {m_router = _router;}
		const IRouter *GetRouter() const {return m_router;}
		
		virtual const  string& GetLocation() const {return m_location;}
		virtual void   SetLocation(const string& _location) {m_location = _location;}

		virtual bool   TestSensor();

		virtual void   SetSmokeState(bool _isSmoke); //XXX For test Only!

	protected:
		int  GetRangeCondition() const {return m_rangeCondition;}
		void SetRangeCondition(int _newCond) {m_rangeCondition = _newCond;}
		bool SetMessageVec(const vector<string>& _argVec);
		
	private:
		SmokeSensorLogic(const SmokeSensorLogic& _sensor);
		const SmokeSensorLogic& operator=(const SmokeSensorLogic& _sensor);

		vector<IMessage*> 	 m_message;
		string				 m_location;
		Sensor  			*m_sensor;
		int					 m_rangeCondition;
		//IRouter  			*m_router; - in base class
};


#endif /* __SMOKE_SENSOR_LOGIC_H__ */
