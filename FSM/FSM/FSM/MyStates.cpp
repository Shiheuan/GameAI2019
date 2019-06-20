#include "MyStates.h"
#include <iostream>
#include "MessageDispatcher.h"
#include "HomeMadeTimer.h"
#include "EntityNames.h"
using std::cout;

GoWorkAndEarnMoney* GoWorkAndEarnMoney::Instance()
{
	static GoWorkAndEarnMoney instance;
	return &instance;
}


void GoWorkAndEarnMoney::Enter(Me* pMe)
{
	// if I Go to Work, I must change the location to the Company
	if (pMe->Location() != company)
	{
		cout << "\n" << "Me" << ": " << "Walking to the Company";
		pMe->ChangeLocation(company);
	}
}

void GoWorkAndEarnMoney::Execute(Me* pMe)
{
	// I work for money, not for dream.
	// I get money according to my skill level.
	pMe->ThePayDay(100 * pMe->Ability());
	pMe->DecreaseMood(2);
	pMe->IncreaseFatigue(1);
	cout << "\n" << "Me" << ": " << "Working and get paid";

	if (pMe->Fatigued())
	{
		pMe->GetFSM()->ChangeState(GoHomeAndSleep::Instance());
	}
	if (pMe->LowMood())
	{
		pMe->GetFSM()->ChangeState(GoBar::Instance());
	}
}

void GoWorkAndEarnMoney::Exit(Me* pMe)
{
	cout << "\n" << "Me" << ": " << "Ah'm leaving the company with today's payment";
}

bool GoWorkAndEarnMoney::OnMessage(Me* pMe, const Telegram& msg)
{
	return false;
}


//---------
GoSchoolAndStudy* GoSchoolAndStudy::Instance()
{
	static GoSchoolAndStudy instance;
	return &instance;
}

void GoSchoolAndStudy::Enter(Me* pMe)
{
	// if I Go to School, I must change the location to the School.
	if (pMe->Location() != school)
	{
		cout << "\n" << "Me" << ": " << "Walking to the School";
		pMe->ChangeLocation(school);
	}
}

void GoSchoolAndStudy::Execute(Me* pMe)
{


	pMe->AddToAbility(1);
	pMe->DecreaseMood(2);
	pMe->IncreaseFatigue(1);
	cout << "\n" << "Me" << ": " << "Studying the courses and improving my skill levels";
	// there should be some logic to change to the state blip.
	pMe->GetFSM()->ChangeState(GoRestroom::Instance());
	if (pMe->Fatigued())
	{
		pMe->GetFSM()->ChangeState(GoHomeAndSleep::Instance());
	}
	if (pMe->LowMood())
	{
		pMe->GetFSM()->ChangeState(GoBar::Instance());
	}
}


void GoSchoolAndStudy::Exit(Me* pMe)
{
	cout << "\n" << "Me" << ": " << "Leaving the School";
}

bool GoSchoolAndStudy::OnMessage(Me* pMe, const Telegram& msg)
{
	return false;
}


//---------

GoHomeAndSleep* GoHomeAndSleep::Instance()
{
	static GoHomeAndSleep instance;
	return &instance;
}


void GoHomeAndSleep::Enter(Me* pMe)
{
	if (pMe->Location() != sweetHome)
	{
		cout << "\n" << "Me" << ": " << "Walking home";
		pMe->ChangeLocation(sweetHome);
		Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
			pMe->ID(), 
			1, // 接收者 Robot 实例的ID
			Msg_HiImHome, 
			NO_ADDITIONAL_INFO);
	}

} 

void GoHomeAndSleep::Execute(Me* pMe)
{
	if (pMe->Rested())
	{
		cout << "\n" << GetNameOfEntity(pMe->ID()) << ": " << "What a God darn fantastic nap! Let me see where to go now...";
		if (pMe->FeelPoor())
		{
			pMe->GetFSM()->ChangeState(GoWorkAndEarnMoney::Instance());
		}
		else
		{
			pMe->GetFSM()->ChangeState(GoSchoolAndStudy::Instance());
		}
	}
	else
	{
		pMe->DecreaseFatigue(1);
		cout << "\n" << "Me" << ": " << "zzZZZ...";
		// there should be some logic to change to the state blip.
		pMe->GetFSM()->ChangeState(GoRestroom::Instance());
	}
}

void GoHomeAndSleep::Exit(Me* pMe)
{
	cout << "\n" << "Me" << ": " << "Leaving the sweet home";
}

bool GoHomeAndSleep::OnMessage(Me* pMe, const Telegram& msg)
{
	switch (msg.Msg)
	{
	case Msg_StewReady:
		std::cout << "\n Message handled by " << "Me" << " at Time: " << HMTimer->GetCurrentHMTime();;

		std::cout << "\n" << "Me" << ": Okay Hun, ahm a comin'!";

		pMe->GetFSM()->ChangeState(EatStew::Instance());
		std::cout << "\n&&&&this time return true;&&&&";
		return true;
	}
	return false;
}

//---------

GoBar* GoBar::Instance()
{
	static GoBar instance;
	return &instance;
}

void GoBar::Enter(Me* pMe)
{
	if (pMe->Location() != beerLady)
	{
		cout << "\n" << "Me" << ": " << "Ah feel so bad! Going to Beer Lady";
		pMe->ChangeLocation(beerLady);
	}
}

void GoBar::Execute(Me* pMe)
{
	
	if (pMe->LowMood())
	{
		pMe->BuyTheBeer();
		cout << "\n" << "Me" << ": " << "Ah-ha-ha Taste good enough";
		// there should be some logic to change to the state blip.
		pMe->GetFSM()->ChangeState(GoRestroom::Instance());
		pMe->GetFSM()->ChangeState(GoHomeAndSleep::Instance());
	}
}

void GoBar::Exit(Me* pMe)
{
	cout << "\n" << "Me" << ": " << "Leaving the Beer Lady, feeling good";
}

bool GoBar::OnMessage(Me* pMe, const Telegram& msg)
{
	return false;
}

//---------
GoRestroom* GoRestroom::Instance()
{
	static GoRestroom instance;
	return &instance;
}


void GoRestroom::Enter(Me* pMe)
{
	cout << "\n" << "Me" << ":" << "Oh! I feel it!";
}


void GoRestroom::Execute(Me* pMe)
{
	cout << "\n" << "Me" << ":" << "I have to pee...";
	pMe->GetFSM()->RevertToPreviousState();
}

void GoRestroom::Exit(Me* pMe)
{
	cout << "\n" << "Me" << ":" << "Now I go back where I belong";
}

bool GoRestroom::OnMessage(Me* pMe, const Telegram& msg)
{
	return false;
}

EatStew* EatStew::Instance()
{
	static EatStew instance;
	return &instance;
}

void EatStew::Enter(Me*)
{
	std::cout << "\n" << "Me" << ": Smells Reaaaal good";
}

void EatStew::Execute(Me* pMe)
{
	std::cout << "\n" << "Me" << ": Tastes real good too";
	pMe->GetFSM()->RevertToPreviousState();
}

void EatStew::Exit(Me*)
{
	std::cout << "\n" << "Me" << ": Thankya li'lle bot. Ah better get back to whatever ah wuz doin'";
}


