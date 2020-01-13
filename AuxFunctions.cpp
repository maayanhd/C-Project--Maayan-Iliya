#include "AuxFunctions.h"

void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}


bool getString(char* str, int maxSize)
{

	cin.getline(str, maxSize);
	if (cin.fail())
	{
		cin.clear();
		cleanBuffer();
		return false;
	}
	else
		return true;
}