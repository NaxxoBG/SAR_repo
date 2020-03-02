#include "Feeder.h"

Feeder::Feeder() = default;

std::vector<Monkeyy> Feeder::filter(std::vector<Monkeyy> ms)
{
	for (auto &element : ms)
	{
		element.feed();
	}
	
	return next != nullptr ? next->filter(ms) : ms;
}
