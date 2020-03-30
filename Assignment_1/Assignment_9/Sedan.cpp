#include <cstdio>

#include "Car.h"
#include <thread>
#include <chrono>
#include "Sedan.h"

#include <mutex>

Sedan::Sedan()
{
	this->speed = 0;
	this->zero_to_hundred = 10;
}

void Sedan::applyThrottle()
{
	if (decelerate != nullptr)
	{
		this->breaking = false;
		decelerate->join();
	}
	accelerate = new std::thread([this]
	{
		while (!this->breaking && this->getSpeed() != 100)
		{
			this->setSpeed(speed += 100.0/zero_to_hundred);
			this->adjustGear();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});
}

void Sedan::applyBrake()
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
			this->setSpeed(speed -= 100.0/zero_to_hundred);
			this->adjustGear();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});
}

void Sedan::setGear(int g)
{
	if (g >=-1 && g <= 3)
	{
		if (g == -1 && speed != 0)
		{
			printf("%s", "Stop before going in reverse\n");
			return;
		}
		this->gear = g;
	}
}

void Sedan::adjustGear()
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

void Sedan::honk()
{
	printf("%s", "Beeeeeeeeeeeeeep\n");
}
