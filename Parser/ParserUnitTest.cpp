#include "IParser.h"
#include "XmlParser.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void print(string str);

int main()
{
	vector<string> vec;
	IParser* parser = new XmlParser;
	while (parser->GetElement(vec) != IParser::E_FINISH)
	{
		for_each(vec.begin(), vec.end(), print);
		cout << endl;
	}
}

void print(string str)
{
	cout << str << endl;
}