#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "Menu.h"
#include <stdlib.h>

int main()
{
	{
		Menu menu;
		bool exit = false;
		while (!exit)
		{
			menu.show(exit);
		}
	}
	if (_CrtDumpMemoryLeaks())
		cout << "ass holes!\n";
	else
		cout << "awesome man!\n";
}
