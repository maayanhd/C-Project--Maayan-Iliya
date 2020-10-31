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
}
