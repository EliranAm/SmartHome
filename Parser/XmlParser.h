#ifndef __XML_PARSER_H__
#define __XML_PARSER_H__

#include <exception>
#include <stdexcept>
#include <fstream>
#include <string>
#include <vector>
#include "IParser.h"

using namespace std;

class XmlParser : public IParser
{
	public:
		XmlParser() throw(runtime_error);
		virtual ~XmlParser() {}
		virtual Type GetElement(vector<string>& _vec) throw(runtime_error);

	protected:
		virtual void UpdateFloor() throw(runtime_error);
		virtual void UpdateRoom() throw(runtime_error);
		virtual void UpdateType() throw(runtime_error);
		virtual void UpdateName() throw(runtime_error);
		virtual bool UpdateArgument();

		ifstream m_inFile;

	private:
		XmlParser(const XmlParser&);
		const XmlParser& operator=(const XmlParser&);

		string m_buff;
		string m_currentFloor;
		string m_currentRoom;
		string m_currentName; //name of device or sensor
		string m_currentPriority;
		IParser::Type m_currentType;
};

#endif //  __XML_PARSER_H__
