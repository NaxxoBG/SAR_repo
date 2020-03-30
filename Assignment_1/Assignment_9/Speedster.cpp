#include "Speedster.h"

#include <thread>

#include "Car.h"

Speedster::Speedster()
{
	this->speed = 0;
	this->zero_to_hundred = 6;
}

void Speedster::applyThrottle()
{
	if (decelerate != nullptr)
	{
		this->breaking = false;
		decelerate->join();
	}
	accelerate = new std::thread([this]
	{
		while (!this->breaking && this->getSpeed() != 99.96)
		{
			this->setSpeed(speed += 16.66);
			this->adjustGear();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});
}

void Speedster::applyBrake()
{
	if (accelerate != nullptr)
	{
		this->breaking = true;
		accelerate->join();
	}
	decelerate = new std::thread([this]
	{
		while (this->breaking && this->getSpeed() != 0)
		{
			this->setSpeed(speed -= 16.66);
			this->adjustGear();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});
}

void Speedster::honk()
{
	printf("%s", "Eeeeeeeeeee\n");
}

void Speedster::setGear(int g)
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

void Speedster::adjustGear()
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

