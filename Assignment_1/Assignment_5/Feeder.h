#pragma once
#include "FilterStage.h"

class Feeder : public FilterStage
{
public:
	Feeder();
	std::vector<Monkeyy> filter(std::vector<Monkeyy> ms) override;
};
