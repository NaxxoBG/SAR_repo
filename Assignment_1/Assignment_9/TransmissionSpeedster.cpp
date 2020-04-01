#include "TransmissionSpeedster.h"

#include <cstdio>

void TransmissionSpeedster::setGear(int g)
{
	if (g >= -1 && g <= 4)
	{
		if (g == -1 && speed != 0)
		{
			printf("%s", "Stop before going in reverse\n");
			return;
		}
		this->gear = g;
	}
}

void TransmissionSpeedster::adjustGear()
{
	if (speed <= 25.0)
	{
		this->setGear(1);
	}
	else if (speed <= 50.0 && speed > 25.0)
	{
		this->setGear(2);
	}
	else if (speed <= 75.0 && speed > 50.0)
	{
		this->setGear(3);
	}
	else if (speed <= 100.0 && speed > 75.0)
	{
		this->setGear(4);
	}
}