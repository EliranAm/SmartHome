#include "TempSensor.h"


TempSensor::TempSensor()
{
	m_power = true;
	m_temperature = 0;
}

float TempSensor::GetMeasurement() const throw(runtime_error)
{
	if(!m_power)
	{
		throw runtime_error("Power Off");
	}
	return m_temperature;
}

