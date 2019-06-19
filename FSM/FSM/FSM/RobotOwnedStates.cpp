#include "RobotOwnedStates.h"
#include "Robot.h"
#include <iostream>

DoHouseWork* DoHouseWork::Instance()
{
	static DoHouseWork instance;
	return &instance;
}

void DoHouseWork::Enter(Robot* pr)
{
	
}


void DoHouseWork::Execute(Robot* pr)
{
	const int index = rand() % 3;
	switch(index)
	{
	case 0:
		std::cout << "\n" << "Robot" << ": Moppin' the floor";
		break;
	case 1:
		std::cout << "\n" << "Robot" << ": Washin' the dishes";
		break;
	case 2:
		std::cout << "\n" << "Robot" << ": Makin' the bed";
		break;
	}

}

void DoHouseWork::Exit(Robot* pr)
{
	
}


VisitBathroom* VisitBathroom::Instance()
{
	static VisitBathroom instance;
	return &instance;
}

void VisitBathroom::Enter(Robot* pr)
{
	std::cout << "\n" << "Robot" << ": Walkin' to the can. Need to powda mah pretty li'lle nose";

}

void VisitBathroom::Execute(Robot* pr)
{
	std::cout << "\n" << "Robot" << ": Ahhhhhh! Sweet relief.";
	pr->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(Robot* pr)
{
	std::cout << "\n" << "Robot" << ": Leavin' the Jon";
}


RobotGlobalState* RobotGlobalState::Instance()
{
	static RobotGlobalState instance;
	return &instance;
}

void RobotGlobalState::Execute(Robot* pr)
{
	if ((rand() % 10) < 1)
		pr->GetFSM()->ChangeState(VisitBathroom::Instance());
}

