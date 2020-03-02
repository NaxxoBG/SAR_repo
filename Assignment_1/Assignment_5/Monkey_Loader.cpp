#include "Monkey_Loader.h"

Monkey_Loader::Monkey_Loader()
{
}

Monkey_Loader::Monkey_Loader(FilterStage *fs)
{
	this->next = fs;
}

std::vector<Monkeyy> Monkey_Loader::load()
{
	std::vector<Monkeyy> monkeys;
	
	monkeys.push_back(Monkeyy("Coco", 7));
	monkeys.push_back(Monkeyy("Mike", 3));
	monkeys.push_back(Monkeyy("Steve", 9));
	monkeys.push_back(Monkeyy("Trevor", 4));
	monkeys.push_back(Monkeyy("Dave", 5));

	return next->filter(monkeys);
}

FilterStage* Monkey_Loader::set_next(FilterStage *n)
{
	this->next = n;
	return next;
}

