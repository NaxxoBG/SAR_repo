#pragma once
#include "FilterStage.h"

class FullFeeder : public FilterStage
{
public:
	FullFeeder();
	std::vector<Monkeyy> filter(std::vector<Monkeyy> ms) override;
};
