#include <Windows.h>
#include "Me.h"
#include "Robot.h"
#include <iostream>
#include <conio.h>
//class Me;

int main()
{
	Me me(0);
	Robot XBox(1);

	for (int i =0; i < 60;i++)
	{
		me.Update();
		XBox.Update();
		Sleep(800);
	}

	std::cout << "\n\nPress any Key to continue" << std::endl;
	while (!_kbhit()){}

	return 0;
}
