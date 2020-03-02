#pragma once
#include "FilterStage.h"

class Printer : public FilterStage
{
public:
	Printer();
	std::vector<Monkeyy> filter(std::vector<Monkeyy> ms) override;
private:
	std::string hungerBar(int c, std::string result)
	{
		if (c == 0)
		{
			return result;
		}
		return result.append(hungerBar(--c, "|"));
	}
};

