#ifndef __SMOKE_SENSOR_H__
#define __SMOKE_SENSOR_H__

#include <exception>
#include <stdexcept>
#include "Sensor.h"

using namespace std;

class SmokeSensor : public Sensor
{
	public:
		SmokeSensor();
		virtual ~SmokeSensor(){}
		
		virtual void SetOff() {m_power = false;}
		virtual void SetOn() {m_power = true;}
		
		virtual bool CheckForSmoke() const throw(runtime_error);
		
		virtual void SetSmokeState(bool _isSmoke) {m_isSmoke = _isSmoke;} //XXX For test Only!

	protected:
		bool m_power;
		bool m_isSmoke; 

	private:
		SmokeSensor(const SmokeSensor& _sensor);
		const SmokeSensor& operator=(const SmokeSensor& _sensor);

};


#endif /* __SMOKE_SENSOR_H__ */

