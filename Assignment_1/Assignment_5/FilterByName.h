#pragma once
#include <unordered_set>

#include "FilterStage.h"

class FilterByName : public FilterStage
{
public:
	FilterByName(std::unordered_set<std::string> &names);
	std::vector<Monkeyy> filter(std::vector<Monkeyy> ms) override;
private:
	std::unordered_set<std::string> names;
};
