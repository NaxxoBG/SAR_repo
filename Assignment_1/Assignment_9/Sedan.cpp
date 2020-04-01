#include <cstdio>

#include "Car.h"
#include <thread>
#include <chrono>
#include "Sedan.h"

Sedan::Sedan(Engine *en, Brake *brake, Transmission * ts, Horn * horn)
{
	engine_ = en;
	brake_ = brake;
	transmission_ = ts;
	horn_ = horn;
}

void Sedan::applyThrottle()
{
	
	if (decelerate != nullptr)
	{
		this->breaking = false;
		decelerate->join();
		decelerate = nullptr;
	}
	accelerate = new std::thread([this]
	{
		while (!this->breaking && engine_->getSpeed() != 100)
		{
			engine_->applyThrottle();
			this->setSpeed(engine_->getSpeed());
			brake_->setSpeed(this->getSpeed());
			transmission_->setSpeed(this->getSpeed());
			transmission_->adjustGear();
			this->dashboard();
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
		accelerate = nullptr;
	}
	decelerate = new std::thread([this]
	{
		while (this->breaking && this->getSpeed() != 0)
		{
			brake_->applyBrake();
			this->setSpeed(brake_->getSpeed());
			engine_->setSpeed(this->getSpeed());
			transmission_->setSpeed(this->getSpeed());
			transmission_->adjustGear();
			this->dashboard();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	});
}

void Sedan::honk()
{
	horn_->honk();
}

void Sedan::reverse()
{
	this->transmission_->setGear(-1);
	this->dashboard();
}
