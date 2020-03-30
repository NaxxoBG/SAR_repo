#include "Truck.h"

#include <thread>

#include "Car.h"

Truck::Truck()
{
	this->speed = 0;
	this->zero_to_hundred = 20;
}

void Truck::applyThrottle()
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
			this->setSpeed(speed += 100.0 / zero_to_hundred);
			this->adjustGear();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});
}

void Truck::applyBrake()
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
			this->setSpeed(speed -= 100.0 / zero_to_hundred);
			this->adjustGear();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});
}

void Truck::honk()
{
	printf("%s", "Dooooooooooooooooot\n");
}

void Truck::setGear(int g)
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

void Truck::adjustGear()
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

