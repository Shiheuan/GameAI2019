#include "Robot.h"

void Robot::Update()
{
	m_pStateMachine->Update();
}

bool Robot::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

