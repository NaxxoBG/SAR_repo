#include "Speedster.h"

#include <thread>

#include "Car.h"

Speedster::Speedster(Engine *en, Brake *brake, Transmission *ts, Horn *horn)
{
	engine_ = en;
	brake_ = brake;
	transmission_ = ts;
	horn_ = horn;
};

void Speedster::applyThrottle()
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

void Speedster::applyBrake()
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

void Speedster::honk()
{
	horn_->honk();
}

void Speedster::reverse()
{
	this->transmission_->setGear(-1);
}

