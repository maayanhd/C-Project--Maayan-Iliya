#pragma warning (disable:4996)
#include <iostream>
#include "Menu.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using namespace std;

int main()
	{
	Menu menu;
	bool exit = false;
		while (!exit) {
		menu.show(exit);
	}
	//system("pause");
	if (_CrtDumpMemoryLeaks())
		cout << "memory leak" << endl;
	else
		cout << "no memory leak" << endl;
}