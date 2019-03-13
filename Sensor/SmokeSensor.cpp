#include "SmokeSensor.h"



SmokeSensor::SmokeSensor() : m_power(true), m_isSmoke(false)
{
}

bool SmokeSensor::CheckForSmoke() const throw(runtime_error)	
{
	if(!m_power)
	{
		throw runtime_error("Power Off");
	}
	return m_isSmoke;
}


