#include "RobotOwnedStates.h"
#include "Robot.h"
#include <iostream>
#include "MessageDispatcher.h"

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

bool DoHouseWork::OnMessage(Robot*, const Telegram&)
{
	return false;
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

bool VisitBathroom::OnMessage(Robot*, const Telegram&)
{
	return false;
}

CookStew* CookStew::Instance()
{
	static CookStew instance;
	return &instance;
}

void CookStew::Enter(Robot* pr)
{
	if (!pr->Cooking())
	{
		std::cout << "\n" << "Robot" << ": Puttin' the stew in the oven";
		Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
			pr->ID(),
			pr->ID(),
			Msg_StewReady,
			NO_ADDITIONAL_INFO);
		pr->SetCooking(true);
	}
}

void CookStew::Execute(Robot*)
{
	std::cout << "\n" << "Robot" << ": Fussin' over food";
}

void CookStew::Exit(Robot*)
{
	std::cout << "\n" << "Robot" << ": Puttin' the stew on the table";
}

bool CookStew::OnMessage(Robot* pr, const Telegram& msg)
{
	switch(msg.Msg)
	{
	case Msg_StewReady:
		{
			std::cout << "\n Message received by " << "Robot" << "at Time:";
			std::cout << "\n" << "Robot" << ": StewReady! Lets eat";

			Dispatch->DispatchMessage(SEND_MSG_IMMEDIATELY,
				pr->ID(),
				0,
				Msg_StewReady,
				NO_ADDITIONAL_INFO);
			pr->SetCooking(false);
			pr->GetFSM()->ChangeState(DoHouseWork::Instance());
		}
		return true;
	}
	return false;
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

bool RobotGlobalState::OnMessage(Robot* pr, const Telegram& msg)
{
	switch(msg.Msg)
	{
	case Msg_HiImHome:
		{
			std::cout << "\n Message handled by " << "Robot";
			std::cout << "\n" << "Robot" << ": Hi master, Let me make you some of mah fine country stew";

			pr->GetFSM()->ChangeState(CookStew::Instance());
		}
		return true;
	}
	return false;
}

