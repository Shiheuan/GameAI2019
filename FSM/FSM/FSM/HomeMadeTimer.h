#pragma once

#pragma comment(lib, "winmm.lib")

#include <Windows.h>

#define HMTimer HomeMadeTimer::Instance()

class HomeMadeTimer
{
private:
	double m_dStartTime;

	HomeMadeTimer()
	{
		m_dStartTime = timeGetTime() * 0.001;
	}

	HomeMadeTimer(const HomeMadeTimer&);
	HomeMadeTimer& operator=(const HomeMadeTimer&);

public:
	static HomeMadeTimer* Instance()
	{
		static HomeMadeTimer instance;
		return &instance;
	}

	double GetCurrentHMTime() { return timeGetTime()*0.001 - m_dStartTime; }
};
