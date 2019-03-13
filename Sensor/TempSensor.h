#ifndef __TEMP_SENSOR_H__
#define __TEMP_SENSOR_H__

#include <exception>
#include <stdexcept>
#include "Sensor.h"

using namespace std;


class TempSensor: public Sensor
{
	public:
		TempSensor();
		virtual ~TempSensor(){}
		
		virtual void SetOff() {m_power = false;}
		virtual void SetOn() {m_power = true;}

		virtual float GetMeasurement() const throw(runtime_error);
		virtual void  SetTemperature(float _temp) {m_temperature = _temp;} //XXX For test Only!
		
	protected:
		bool m_power;
		float m_temperature; 

	private:
		TempSensor(const TempSensor& _sensor);
		const TempSensor& operator=(const TempSensor& _sensor);
		
};




#endif /* __TEMP_SENSOR_H__ */
