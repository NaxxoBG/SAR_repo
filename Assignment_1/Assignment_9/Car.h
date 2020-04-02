#pragma once
#include <mutex>
#include <thread>

#include "Brake.h"
#include "Engine.h"
#include "Horn.h"
#include "Transmission.h"

class Car
{
public:
	virtual void applyThrottle() = 0;
	virtual void applyBrake() = 0;
	virtual void honk() = 0;
	virtual void reverse() = 0;
	double getSpeed() const
	{
		return this->speed;
	}
	double setSpeed(const double speed)
	{
		return this->speed = speed;
	}
	void dashboard() const
	{
		printf("Speed: %lf; Gear: %d\n", this->getSpeed(), transmission_->getGear());
	}
	void setHorn(Horn *horn)
	{
		this->horn_ = horn;
	}
	
protected:
	double speed = 0;
	bool breaking;
	std::thread* accelerate = nullptr;
	std::thread* decelerate = nullptr;
	Horn *horn_;
	Engine *engine_;
	Brake *brake_;
	Transmission *transmission_;
};
