#include "XmlParser.h"

#define FILE_NAME "Config.xml"
#define HOME "<HOME>"
#define FLOOR "<FLOOR>"
#define NUMBER "<NUMBER>"
#define ROOM "<ROOM>"
#define DEVICE "<DEVICE>"
#define SENSOR "<SENSOR>"
#define NAME "<NAME>"
#define ARGUMENT "<ARGUMENT>"
#define PRIORITY "<PRIORITY>"
#define FINISH "</HOME>"
#define END_ROOM "</ROOM>"
#define END_FLOOR "</FLOOR>"



XmlParser::XmlParser() throw(runtime_error)
{
	m_inFile.open("Config.xml");
	m_inFile >> m_buff;
	if (m_buff.compare(HOME)!=0) //the first token has to be "HOME"
	{
		throw runtime_error("XML file invalid");
	}
}

IParser::Type XmlParser::GetElement(vector<string>& _vec) throw(runtime_error)
{	
	_vec.clear();
	m_inFile >> m_buff;
	while (m_buff.compare(END_FLOOR) == 0 || m_buff.compare(END_ROOM) == 0)
	{
		m_inFile >> m_buff;
	}	
	if (m_buff.compare(FINISH) == 0)
	{
		return E_FINISH;
	}
	try
	{
		UpdateFloor();
		UpdateRoom();
		UpdateType();
		UpdateName();
		_vec.push_back(m_currentName);
	}
	catch (const exception& ex)
	{
		throw;
	}
	while (UpdateArgument())
	{
		_vec.push_back(m_currentName);
		_vec.push_back(m_currentPriority);
	}
	return m_currentType;
}

void XmlParser::UpdateFloor()  throw(runtime_error)
{
	if (m_buff.compare(FLOOR) == 0)
	{
		m_inFile >> m_buff;
		if (m_buff.compare(NUMBER) == 0)
		{
			m_inFile >> m_currentFloor;
			m_inFile >> m_buff;
			m_inFile >> m_buff;
		}
		else
		{
			throw runtime_error("XML file invalid: Number of floor!");
		}
	}
}

void XmlParser::UpdateRoom() throw(runtime_error)
{
	if (m_buff.compare(ROOM) == 0)
	{
		m_inFile >> m_buff;
		if (m_buff.compare(NUMBER) == 0)
		{
			m_inFile >> m_currentRoom;
			m_inFile >> m_buff;
			m_inFile >> m_buff;
		}
		else
		{
			throw runtime_error("XML file invalid: Number of room!");
		}
	}
}

void XmlParser::UpdateType() throw(runtime_error)
{
	if (m_buff.compare(DEVICE) == 0)
	{
		m_currentType = E_DEVICE;
	}
	else if (m_buff.compare(SENSOR) == 0)
	{
		m_currentType = E_SENSOR;
	}
	else
	{
		throw runtime_error("XML file invalid: Unknown type!");
	}
	m_inFile >> m_buff;
}

void XmlParser::UpdateName()  throw(runtime_error)
{
	if (m_buff.compare(NAME) == 0)
	{
		m_inFile >> m_currentName;
		m_inFile >> m_buff;
		m_inFile >> m_buff;
		if (m_buff.compare(NUMBER) == 0)
		{
			m_inFile >> m_buff;
			m_currentName += m_currentFloor + m_currentRoom + m_buff;
			m_inFile >> m_buff;
			m_inFile >> m_buff;
		}
		else
		{
			throw runtime_error("XML file invalid: No Device/Sensor Number!");
		}
	}
	else
	{
		throw runtime_error("XML file invalid: No Device/Sensor Name!");
	}
}

bool XmlParser::UpdateArgument()
{
	bool res = false;
	if (m_buff.compare(ARGUMENT) == 0)
	{
		m_inFile >> m_currentName;
		m_inFile >> m_buff;
		m_inFile >> m_buff;
		if (m_currentType == E_SENSOR && m_buff.compare(PRIORITY) == 0)
		{
			m_inFile >> m_currentPriority;
			m_inFile >> m_buff;
			m_inFile >> m_buff;
			res = true;
		}
		else if (m_currentType == E_DEVICE)
		{
			res = true;
		}
	}
	return res;
}


