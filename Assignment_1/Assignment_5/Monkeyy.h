#pragma once
#include <string>

class Monkeyy
{
public:
	Monkeyy(std::string name, int hungerLevel);
	void feed();
	int getHungerLevel() const;
	std::string getName() const;
private:
	int hungerLevel;
	std::string name;
};

