#pragma once
#include "decorator.h"

class logwrapper : public decorator
{
	Car *car;
public:
	logwrapper(Car* car)
	{
		this->car = car;
	};
	void applyBrake() override;
	void applyThrottle() override;
	void honk() override;
	void reverse() override;
};

inline void logwrapper::applyBrake()
{
	printf("%s", "Car is braking...\n");
	car->applyBrake();
}

inline void logwrapper::applyThrottle()
{
	printf("%s", "Car is accelerating...\n");
	car->applyThrottle();
}

inline void logwrapper::honk()
{
	printf("%s", "Car is honking...\n");
	car->honk();
}

inline void logwrapper::reverse()
{
	printf("%s", "Car is reversing...\n");
	car->reverse();
}

