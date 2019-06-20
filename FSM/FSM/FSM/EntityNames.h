#pragma once

#include <string>

enum
{
	ent_Me,
	ent_bot,
};

inline std::string GetNameOfEntity(int n)
{
	switch(n)
	{
	case ent_Me:
		return "Me";
	case ent_bot:
		return "Bot";
	default:
		return "UNKNOWN!!";
	}
}
