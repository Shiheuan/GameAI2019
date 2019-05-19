#include "MyStates.h"
#include <iostream>
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
		pMe->ChangeState(GoHomeAndSleep::Instance());
	}
	if (pMe->LowMood())
	{
		pMe->ChangeState(GoBar::Instance());
	}
}

void GoWorkAndEarnMoney::Exit(Me* pMe)
{
	cout << "\n" << "Me" << ": " << "Ah'm leaving the company with today's payment";
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
	if (pMe->Fatigued())
	{
		pMe->ChangeState(GoHomeAndSleep::Instance());
	}
	if (pMe->LowMood())
	{
		pMe->ChangeState(GoBar::Instance());
	}
}


void GoSchoolAndStudy::Exit(Me* pMe)
{
	cout << "\n" << "Me" << ": " << "Leaving the School";
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
	}

} 

void GoHomeAndSleep::Execute(Me* pMe)
{
	if (pMe->Rested())
	{
		cout << "\n" << "Me" << ": " << "What a God darn fantastic nap! Let me see where to go now...";
		if (pMe->FeelPoor())
		{
			pMe->ChangeState(GoWorkAndEarnMoney::Instance());
		}
		else
		{
			pMe->ChangeState(GoSchoolAndStudy::Instance());
		}
	}
	else
	{
		pMe->DecreaseFatigue(1);
		cout << "\n" << "Me" << ": " << "zzZZZ...";
	}
}

void GoHomeAndSleep::Exit(Me* pMe)
{
	cout << "\n" << "Me" << ": " << "Leaving the sweet home";
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

		pMe->ChangeState(GoHomeAndSleep::Instance());
	}
}

void GoBar::Exit(Me* pMe)
{
	cout << "\n" << "Me" << ": " << "Leaving the Beer Lady, feeling good";
}
