#include "Robot.h"
#include "ConsoleUtils.h"

void Robot::Update()
{
	SetTextColor(ROBOT_COLOR);

	m_pStateMachine->Update();
}

bool Robot::HandleMessage(const Telegram& msg)
{
	return m_pStateMachine->HandleMessage(msg);
}

