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

public:
	Robot(int id):BaseGameEntity(id),
					m_Location(sweetHome)
	{
		m_pStateMachine = new StateMachine<Robot>(this);
		m_pStateMachine->SetCurrentState(DoHouseWork::Instance());
	}

	~Robot()
	{
		delete m_pStateMachine;
	}

	void Update();
	StateMachine<Robot>* GetFSM()const
	{
		return m_pStateMachine;
	}

	location_type Location()const { return m_Location; }
	void ChangeLocation(const location_type location) { m_Location = location; }
};
