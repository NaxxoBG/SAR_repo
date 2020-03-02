#include "FilterByName.h"

#include <algorithm>

FilterByName::FilterByName(std::unordered_set<std::string> &names)
{
	this->names = names;
}

std::vector<Monkeyy> FilterByName::filter(std::vector<Monkeyy> ms)
{
	std::vector<Monkeyy> filtered;

	std::copy_if(ms.begin(), ms.end(), std::back_inserter(filtered), [this](Monkeyy &i) {return find(names.begin(), names.end(), i.getName()) != names.end(); });

	return next != nullptr ? next->filter(filtered) : filtered;
}
