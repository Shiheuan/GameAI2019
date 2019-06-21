#pragma once

#include <Windows.h>

#define MESSAGE_COLOR BACKGROUND_RED|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE
#define MY_COLOR FOREGROUND_RED|FOREGROUND_INTENSITY
#define ROBOT_COLOR FOREGROUND_GREEN|FOREGROUND_INTENSITY 

// 修改控制台字体颜色
inline void SetTextColor(WORD colors)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, colors);
}
