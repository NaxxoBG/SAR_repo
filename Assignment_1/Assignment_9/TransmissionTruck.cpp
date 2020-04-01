#include "TransmissionTruck.h"

#include <cstdio>

void TransmissionTruck::setGear(int g)
{
	if (g >= -1 && g <= 5)
	{
		if (g == -1 && speed != 0)
		{
			printf("%s", "Stop before going in reverse\n");
			return;
		}
		this->gear = g;
	}
}

void TransmissionTruck::adjustGear()
{
	if (speed <= 20)
	{
		this->setGear(1);
	}
	else if (speed <= 40 && speed > 20)
	{
		this->setGear(2);
	}
	else if (speed <= 60 && speed > 40)
	{
		this->setGear(3);
	}
	else if (speed <= 80 && speed > 60)
	{
		this->setGear(4);
	}
	else if (speed <= 100 && speed > 80)
	{
		this->setGear(5);
	}
}