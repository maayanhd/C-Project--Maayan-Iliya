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

