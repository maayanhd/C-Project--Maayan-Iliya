#include "AuxFunctions.h"
#include <string>
void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}


bool getString(string& str, int maxSize)
{

	getline(std::cin, str);
	if (cin.fail())
	{
		cin.clear();
		cleanBuffer();
		return false;
	}
	else
		return true;
}