#pragma once
#include "State.h"
#include "Me.h"
#include "Telegram.h"
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
	virtual bool OnMessage(Me* pMe, const Telegram& msg) override;
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
	bool OnMessage(Me* pMe, const Telegram& msg) override;
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
	bool OnMessage(Me* pMe, const Telegram& msg) override;
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
	bool OnMessage(Me* pMe, const Telegram& msg) override;
};

class GoRestroom:public State<Me>
{
private:
	GoRestroom() = default;
public:
	static GoRestroom* Instance();
	virtual void Enter(Me*) override;
	virtual void Execute(Me*) override;
	virtual void Exit(Me*) override;
	bool OnMessage(Me* pMe, const Telegram& msg) override;
};

class EatStew : public State<Me>
{
private:
	EatStew(){};

	EatStew(const EatStew&);
	EatStew& operator=(const EatStew&);
public:
	static EatStew* Instance();
	void Enter(Me*) override;
	void Execute(Me*) override;
	void Exit(Me*) override;
	bool OnMessage(Me*, const Telegram&) override { return false; };
};
