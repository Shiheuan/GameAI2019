#pragma once
#include <set>
#include "Telegram.h"
#include "BaseGameEntity.h"

// make code easier to read
const double SEND_MSG_IMMEDIATELY = 0.0f;
const int NO_ADDITIONAL_INFO = 0;

// 让撸代码舒服一点
#define Dispatch MessageDispatcher::Instance()

class MessageDispatcher
{
private:
	// 用 set 来作为延迟消息的容器，这样的好处是可以自动地排序和避免产生重复。按照消息的发送时间给他们排序
	std::set<Telegram> PriorityQ;
	// 该方法被 DispatchMessage 或者 DispatchDelayedMessages 方法利用。给方法用最新创建的 telegram 调用接受实体的消息处理成员函数 pReceiver
	void Discharge(BaseGameEntity* pReceiver, const Telegram& msg);
	MessageDispatcher(){}

	//copy ctor and assignment should be private
	MessageDispatcher(const MessageDispatcher&);
	MessageDispatcher& operator=(const MessageDispatcher&);	
public:
	static MessageDispatcher* Instance();
	void DispatchMessages(double delay, int sender, int receiver, int msg, void* ExtraInfo);
	void DispatchDelayedMessages();
};


