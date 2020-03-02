#include "Printer.h"

#include <sstream>

using namespace std;

Printer::Printer() = default;

std::vector<Monkeyy> Printer::filter(std::vector<Monkeyy> ms)
{
	auto c = 0;
	printf("Monkeys:\n");
	for (auto m : ms)
	{
		printf("%d. %s, hunger: %s\n", ++c, m.getName().c_str(), hungerBar(m.getHungerLevel(), "").c_str());
	}

	return next != nullptr ? next->filter(ms) : ms;
}


