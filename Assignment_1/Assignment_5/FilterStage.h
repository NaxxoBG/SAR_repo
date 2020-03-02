#pragma once
#include <vector>

#include "Monkeyy.h"

class FilterStage
{
protected:
	FilterStage* next;
	FilterStage()
	{
		this->next = nullptr;
	};
public:
	virtual std::vector<Monkeyy> filter(std::vector<Monkeyy> ms) = 0;
	virtual FilterStage* set_next(FilterStage* filter)
	{
		this->next = filter;
		return next;
	};
};
