#ifndef __TEMP_SENSOR_LOGIC_H__
#define __TEMP_SENSOR_LOGIC_H__

#include "ISensorLogic.h"
#include "../PubSub/Publisher.h"

#include <vector>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

class IRouter;
class Sensor;
class IMessage;


class TempSensorLogic: public ISensorLogic , public Publisher
{
	public:
		TempSensorLogic(const string& _location, const vector<string>& _argVec) throw (runtime_error);
		virtual ~TempSensorLogic();

		virtual void   SetSensorOn();
		virtual void   SetSensorOff();
		
		virtual void   SetRouter(IRouter *_router) {m_router = _router;}
		const IRouter *GetRouter() const {return m_router;}
		
		virtual const  string& GetLocation() const {return m_location;}
		virtual void   SetLocation(const string& _location) {m_location = _location;}
	
		virtual bool   TestSensor();

		virtual void   SetTemperature(float _temp); //XXX For test Only!

	protected:
		int  GetRangeCondition() const {return m_rangeCondition;}
		void SetRangeCondition(int _newCond) {m_rangeCondition = _newCond;}
		bool SetMessageVec(const vector<string>& _argVec);
		
	private:
		TempSensorLogic(const TempSensorLogic& _sensor);
		const TempSensorLogic& operator=(const TempSensorLogic& _sensor);
		
		vector<IMessage*> 	 m_message;
		string				 m_location;
		Sensor  			*m_sensor;
		int					 m_rangeCondition;
		int 				 m_upperLimit;
		int 				 m_lowerLimit;
		//IRouter			*m_router;
};


#endif /* __TEMP_SENSOR_LOGIC_H__ */
