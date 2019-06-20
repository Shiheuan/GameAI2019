#pragma once
#include <set>
#include "Telegram.h"
#include "BaseGameEntity.h"

// make code easier to read
const double SEND_MSG_IMMEDIATELY = 0.0f;
const int NO_ADDITIONAL_INFO = 0;

// ��ߣ�������һ��
#define Dispatch MessageDispatcher::Instance()

class MessageDispatcher
{
private:
	// �� set ����Ϊ�ӳ���Ϣ�������������ĺô��ǿ����Զ�������ͱ�������ظ���������Ϣ�ķ���ʱ�����������
	std::set<Telegram> PriorityQ;
	// �÷����� DispatchMessage ���� DispatchDelayedMessages �������á������������´����� telegram ���ý���ʵ�����Ϣ�����Ա���� pReceiver
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


