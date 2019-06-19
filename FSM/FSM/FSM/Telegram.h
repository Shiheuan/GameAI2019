#pragma once
#include <iostream>

enum message_type
{
	Msg_HiImHome,
	Msg_StewReady,
};

inline std::string MsgToStr(int msg)
{
	switch (msg)
	{
	case Msg_HiImHome:
		return "HiImHome";
	case Msg_StewReady:
		return "StewReady";
	default:
		return "Not Recognized!";
	}
}

struct Telegram
{
	int Sender;
	int Receiver;
	int Msg;
	double DispatchTime;
	void* ExtraInfo;

	Telegram():DispatchTime(-1),
				Sender(-1),
				Receiver(-1),
				Msg(-1)
	{}

	Telegram(double time,
			 int sender,
			 int receiver,
			 int msg,
			 void* info = NULL): DispatchTime(time),
								 Sender(sender),
								 Receiver(receiver),
								 Msg(msg),
								 ExtraInfo(info)
	{}
};

// 用来在优先队列中排序

const double SmallestDelay = 0.25;

inline bool operator==(const Telegram& t1, const Telegram& t2)
{
	return (fabs(t1.DispatchTime - t2.DispatchTime) < SmallestDelay) &&
		(t1.Sender == t2.Sender) &&
		(t1.Receiver == t2.Receiver) &&
		(t1.Msg == t2.Msg);
}

inline bool operator<(const Telegram t1, const Telegram t2)
{
	if (t1 == t2)
	{
		return false;
	}
	else
	{
		return (t1.DispatchTime < t2.DispatchTime);
	}
}
//
//// 流操作符重载
//inline std::ostream& operator<<(std::ostream& os, const Telegram& t)
//{
//	os << "Time: " << t.DispatchTime << "  Sender: " << t.Sender << "  Receiver: " << t.Receiver << "  Msg: " << t.Msg;
//	return os;
//}
//
//template <class T>
//inline T DereferenceToType(void* p)
//{
//	return *(T*)(p);
//}
