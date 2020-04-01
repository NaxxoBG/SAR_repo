#include "TransmissionSedan.h"

#include <cstdio>

void TransmissionSedan::setGear(int g)
{
	if (g >= -1 && g <= 3)
	{
		if (g == -1 && speed != 0)
		{
			printf("%s", "Stop before going in reverse\n");
			return;
		}
		this->gear = g;
	}
}


void TransmissionSedan::adjustGear()
{
	if (speed <= 40)
	{
		this->setGear(1);
	}
	else if (speed <= 70 && speed > 40)
	{
		this->setGear(2);
	}
	else if (speed <= 100 && speed > 70)
	{
		this->setGear(3);
	}
}