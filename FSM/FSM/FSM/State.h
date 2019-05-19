#pragma once
#include "Me.h"
class Me;

class State
{
public:
	virtual ~State(){}
	virtual void Enter(Me*) = 0;
	virtual void Execute(Me*) = 0;
	virtual void Exit(Me*) = 0;

};
