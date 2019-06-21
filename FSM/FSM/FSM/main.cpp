#include <Windows.h>
#include "Me.h"
#include "Robot.h"
#include <iostream>
#include <conio.h>
#include "EntityManager.h"
#include "MessageDispatcher.h"
#include "ConsoleUtils.h"
//class Me;

int main()
{
	Me* me = new Me(0);
	Robot* bot = new Robot(1);

	EntityMgr->RegisterEntity(me);
	EntityMgr->RegisterEntity(bot);

	for (int i =0; i < 20;i++)
	{
		me->Update();
		bot->Update();

		Dispatch->DispatchDelayedMessages();
		Sleep(800);
	}

	SetTextColor(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
	std::cout << "\n\nPress any Key to continue" << std::endl;

	delete me;
	delete bot;

	while (!_kbhit()){}

	return 0;
}
