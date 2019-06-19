#pragma once

#include "State.h"

class Robot;

class DoHouseWork:public State<Robot>
{
private:
	DoHouseWork(){}

	DoHouseWork(const DoHouseWork&);
	DoHouseWork& operator=(const DoHouseWork&);

public:
	static DoHouseWork* Instance();
	virtual void Enter(Robot* pr) override;
	virtual void Execute(Robot* pr) override;
	virtual void Exit(Robot* pr) override;
	bool OnMessage(Robot*, const Telegram&) override;
};

class VisitBathroom : public State<Robot>
{
private:
	VisitBathroom(){}

	VisitBathroom(const VisitBathroom&);
	VisitBathroom& operator=(const VisitBathroom&);

public:
	static VisitBathroom* Instance();
	virtual void Enter(Robot* pr) override;
	virtual void Execute(Robot* pr) override;
	virtual void Exit(Robot* pr) override;
	bool OnMessage(Robot*, const Telegram&) override;
};

class RobotGlobalState : public State<Robot>
{
private:
	RobotGlobalState(){}
	RobotGlobalState(const RobotGlobalState&);
	RobotGlobalState& operator=(const RobotGlobalState&);
public:
	static RobotGlobalState* Instance();
	virtual void Enter(Robot* pr) override{};
	virtual void Execute(Robot* pr) override;
	virtual void Exit(Robot* pr) override{};
	bool OnMessage(Robot* , const Telegram&) override;
};
