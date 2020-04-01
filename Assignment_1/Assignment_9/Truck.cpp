#include "Truck.h"

#include <thread>

#include "Car.h"

Truck::Truck(Engine *en, Brake *brake, Transmission *ts, Horn *horn)
{
	engine_ = en;
	brake_ = brake;
	transmission_ = ts;
	horn_ = horn;
};


void Truck::applyThrottle()
{
	if (decelerate != nullptr)
	{
		this->breaking = false;
		decelerate->join();
	}
	accelerate = new std::thread([this]
	{
		engine_->applyThrottle();
		transmission_->adjustGear();
		std::this_thread::sleep_for(std::chrono::seconds(1));
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
		brake_->applyBrake();
		transmission_->adjustGear();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	});
}

void Truck::honk()
{
	horn_->honk();
}

void Truck::reverse()
{
	this->transmission_->setGear(-1);
}

