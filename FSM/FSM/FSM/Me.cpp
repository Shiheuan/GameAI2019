#include "Me.h"
#include <cassert>
#include "MyStates.h"

Me::Me(int ID) : BaseGameEntity(ID),
				m_pCurrentState(GoHomeAndSleep::Instance()),
				m_Location(sweetHome),
				m_iMoneyInCard(1000),
				m_iMoodForDoingStuffs(Max_Mood),
				m_iAbilityLevel(10),
				m_iFatigue(0){}
				

void Me::ChangeState(State<Me>* pNewState)
{
	assert(m_pCurrentState && pNewState);
	m_pCurrentState->Exit(this);
	m_pCurrentState = pNewState;
	m_pCurrentState->Enter(this);

}

void Me::AddToAbility(const int val)
{
	m_iAbilityLevel += val;

	if (m_iAbilityLevel < 0) m_iAbilityLevel = 0;
}

void Me::ThePayDay(const int val)
{
	m_iMoneyInCard += val;
	if (m_iMoneyInCard < 0) m_iMoneyInCard = 0;
}

bool Me::Fatigued() const
{
	return m_iFatigue >= TirednessThreshold;
}

bool Me::Rested() const
{
	return m_iFatigue <= 0;
}

bool Me::LowMood() const
{
	return m_iMoodForDoingStuffs < LowMoodThreshold;
}

bool Me::FeelPoor() const
{
	return m_iMoneyInCard <= LowMoneyThreshold;
}

void Me::Update()
{
	if (m_pCurrentState)
	{
		m_pCurrentState->Execute(this);
	}
}
