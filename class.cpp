#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <locale>
#include <math.h>
#include <list>
#include <Windows.h>

using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu menu;
	Sanatroty sanatroty;

	menu.Output();

	while(true)
	{
		char number = menu.Input();
		switch(number)
		{
			case '1': 
				sanatroty.Add();
				break;
			case '2': 
				sanatroty.Remove();
				break;
			case '3': 
				sanatroty.View();
				break;
			default: 
				cout << "Îøèáêà ââîäà." << endl;
				break;
		}

	}
}

