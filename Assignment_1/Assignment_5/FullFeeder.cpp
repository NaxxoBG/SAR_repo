#include "FullFeeder.h"

FullFeeder::FullFeeder() = default;

std::vector<Monkeyy> FullFeeder::filter(std::vector<Monkeyy> ms)
{
	for (auto &element : ms)
	{
		while (element.getHungerLevel() >= 1)
		{
			element.feed();
		}
	}

	return next != nullptr ? next->filter(ms) : ms;
}
