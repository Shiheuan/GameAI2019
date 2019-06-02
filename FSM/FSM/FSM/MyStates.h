#pragma once
#include "State.h"
#include <sys/stat.h>

class GoWorkAndEarnMoney:public State<Me>
{
private:
	GoWorkAndEarnMoney() = default;
public:
	static GoWorkAndEarnMoney* Instance();
	virtual void Enter(Me* pMe);
	virtual void Execute(Me* pMe);
	virtual void Exit(Me* pMe);
};

class GoSchoolAndStudy:public State<Me>
{
private:
	GoSchoolAndStudy() = default;
public:
	static GoSchoolAndStudy* Instance();
	virtual void Enter(Me* pMe);
	virtual void Execute(Me* pMe);
	virtual void Exit(Me* pMe);
};

class GoHomeAndSleep:public State<Me>
{
private:
	GoHomeAndSleep() = default;
public:
	static GoHomeAndSleep* Instance();
	virtual void Enter(Me* pMe);
	virtual void Execute(Me* pMe);
	virtual void Exit(Me* pMe);
};
 
class GoBar:public State<Me>
{
private:
	GoBar() = default;
public:
	static GoBar* Instance();
	virtual void Enter(Me* pMe);
	virtual void Execute(Me* pMe);
	virtual void Exit(Me* pMe);
};