#include "Monkeyy.h"

Monkeyy::Monkeyy(std::string name, int hungerLevel)
{
	this->name = name;
	this->hungerLevel = hungerLevel;
}

void Monkeyy::feed()
{
	this->hungerLevel -= 1;
}

int Monkeyy::getHungerLevel() const
{
	return this->hungerLevel;
}

std::string Monkeyy::getName() const
{
	return this->name;
}
