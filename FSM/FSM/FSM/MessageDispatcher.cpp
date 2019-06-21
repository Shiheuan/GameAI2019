#include "MessageDispatcher.h"
#include "EntityManager.h"
#include "HomeMadeTimer.h"
#include "EntityNames.h"

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


void MessageDispatcher::DispatchMessages(double delay, int sender, int receiver, int msg, void* ExtraInfo)
{
	SetTextColor(MESSAGE_COLOR);

	BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);
	BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);

	if(pReceiver == NULL)
	{
		SetTextColor(MESSAGE_COLOR);
		std::cout << "\n Warning! No Receiver with ID of " << receiver << " found";
		
		return;
	}

	Telegram telegram(delay, sender, receiver, msg, ExtraInfo);
	if (delay <= 0.0)
	{
		SetTextColor(MESSAGE_COLOR);

		std::cout << "\n Instant telegram dispatched at time: " << HMTimer->GetCurrentHMTime() << " by " << GetNameOfEntity(pSender->ID()) << " for " << GetNameOfEntity(pReceiver->ID()) << ". Msg is " << MsgToStr(msg);
		
		Discharge(pReceiver, telegram);
	}
	else
	{
		double CurrentTime = HMTimer->GetCurrentHMTime();
		telegram.DispatchTime = CurrentTime + delay;
		PriorityQ.insert(telegram);

		std::cout << "\n Delayed telegram from " << GetNameOfEntity(pSender->ID()) << " for " << GetNameOfEntity(pReceiver->ID()) << ". Msg is " << MsgToStr(msg);
	}
}

void MessageDispatcher::DispatchDelayedMessages()
{
	SetTextColor(MESSAGE_COLOR);

	double CurrentTime = HMTimer->GetCurrentHMTime();
	while((!PriorityQ.empty()) &&
		  (PriorityQ.begin()->DispatchTime < CurrentTime &&
		  (PriorityQ.begin()->DispatchTime > 0)))
	{
		Telegram telegram = *PriorityQ.begin();
		BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.Receiver);
		Discharge(pReceiver, telegram);
		PriorityQ.erase(PriorityQ.begin());
	}
}

