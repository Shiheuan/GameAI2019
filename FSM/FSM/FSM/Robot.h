#pragma once

#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Me.h"
#include "RobotOwnedStates.h"

class Robot : public BaseGameEntity
{
private:
	StateMachine<Robot>* m_pStateMachine;
	location_type m_Location;
	bool m_bCooking;

public:
	Robot(int id):BaseGameEntity(id),
					m_Location(sweetHome)
	{
		m_pStateMachine = new StateMachine<Robot>(this);
		m_pStateMachine->SetCurrentState(DoHouseWork::Instance());
		m_pStateMachine->SetGlobalState(RobotGlobalState::Instance());
	}

	~Robot()
	{
		delete m_pStateMachine;
	}

	void Update();
	bool HandleMessage(const Telegram& msg) override;
	StateMachine<Robot>* GetFSM()const
	{
		return m_pStateMachine;
	}

	location_type Location()const { return m_Location; }
	void ChangeLocation(const location_type location) { m_Location = location; }

	bool Cooking()const { return m_bCooking; }
	void SetCooking(bool val) { m_bCooking = val; }
};
