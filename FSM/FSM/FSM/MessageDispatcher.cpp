#include "MessageDispatcher.h"
#include "EntityManager.h"

MessageDispatcher* MessageDispatcher::Instance()
{
	static MessageDispatcher instance;
	return &instance;
}

void MessageDispatcher::Discharge(BaseGameEntity* pReceiver, const Telegram& msg)
{
	if (!pReceiver->HandleMessage(msg))
	{
		std::cout << "Message not handled";
	}
}


void MessageDispatcher::DispatchMessage(double delay, int sender, int receiver, int msg, void* ExtraInfo)
{
	BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);
	BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);

	if(pReceiver == NULL)
	{
		std::cout << "\n Warning! No Receiver with ID of " << receiver << " found";
		
		return;
	}

	Telegram telegram(delay, sender, receiver, msg, ExtraInfo);
	if (delay <= 0.0)
	{
		Discharge(pReceiver, telegram);
	}
	//else
	//{
	//	double CurrentTime = Clock->GetCurrentTime();
	//	telegram.DispatchTime = CurrentTime + delay;
	//	PriorityQ.insert(telegram);
	//}
}

void MessageDispatcher::DispatchDelayedMessages()
{
	//double CurrentTime = Clock->GetCurrentTime();
	//while((PriorityQ.begin()->DispatchTime < CurrentTime &&
	//	  (PriorityQ.begin()->DispatchTime > 0)))
	//{
	//	Telegram telegram = *PriorityQ.begin();
	//	BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.Receiver);
	//	Discharge(pReceiver, telegram);
	//	PriorityQ.erase(PriorityQ.begin());
	//}
}

