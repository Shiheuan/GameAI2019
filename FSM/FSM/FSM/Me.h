#pragma once
#include "BaseGameEntity.h"
#include "State.h"

template<class entity_name>
class State;

enum location_type
{
	sweetHome,
	school,
	company,
	beerLady,
};

class Me : public BaseGameEntity
{
private:
	State<Me>* m_pCurrentState;
	location_type m_Location;
	// should be early than those variables use them.
	const int Max_Mood = 5;
	const int TirednessThreshold = 5;
	const int LowMoodThreshold = 1;
	const int LowMoneyThreshold = 2000;
	// 
	int m_iMoneyInCard;
	int m_iMoodForDoingStuffs;
	int m_iAbilityLevel;
	int m_iFatigue;
	
public:
	Me(int ID);				
	void Update(); 
	void ChangeState(State<Me> *pNewState);
	// interface
	location_type Location()const { return m_Location; }
	void ChangeLocation(const location_type goal) { m_Location = goal; }
	int Ability()const { return m_iAbilityLevel; }
	void SetAbilityLevel(const int val) { m_iAbilityLevel = val; }
	void AddToAbility(const int val);
	int MoneyInCard()const { return m_iMoneyInCard; }
	void SetMoneyInCard(const int val) { m_iMoneyInCard = val; }
	void ThePayDay(const int val);
	bool Fatigued()const;
	bool Rested()const;
	void DecreaseFatigue(const int val) { m_iFatigue -= val; }
	void IncreaseFatigue(const int val) { m_iFatigue += val; }
	bool LowMood()const;
	void DecreaseMood(const int val) { m_iMoodForDoingStuffs -= val; }
	void IncreaseMood(const int val) { m_iMoodForDoingStuffs += val; }
	bool FeelPoor()const;
	void BuyTheBeer() { m_iMoodForDoingStuffs = Max_Mood; m_iMoneyInCard -= 500; }
};
