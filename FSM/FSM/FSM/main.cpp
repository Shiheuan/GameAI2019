#include <Windows.h>
#include "Me.h"
#include "Robot.h"
#include <iostream>
#include <conio.h>
#include "EntityManager.h"
//class Me;

int main()
{
	Me* me = new Me(0);
	Robot* bot = new Robot(1);

	EntityMgr->RegisterEntity(me);
	EntityMgr->RegisterEntity(bot);

	for (int i =0; i < 60;i++)
	{
		me->Update();
		bot->Update();
		Sleep(800);
	}

	std::cout << "\n\nPress any Key to continue" << std::endl;

	delete me;
	delete bot;

	while (!_kbhit()){}

	return 0;
}
