#pragma once
#include <thread>

class Car
{
	virtual void adjustGear() = 0;
public:
	virtual ~Car() = default;
	virtual void applyThrottle() = 0;
	virtual void applyBrake() = 0;
	virtual void honk() = 0;
	virtual void setGear(int g) = 0;
	double getSpeed()
	{
		return this->speed;
	}
	double setSpeed(const double speed)
	{
		return this->speed = speed;
	}
	int getGear()
	{
		return this->gear;
	}
	void dashboard()
	{
		printf("Speed: %lf; Gear: %d\n", this->getSpeed(), this->getGear());
	}
	
protected:
	double speed = 0;
	double zero_to_hundred = 0;
	bool breaking;
	int gear = 0; // 0 is neutral
	std::thread* accelerate = nullptr;
	std::thread* decelerate = nullptr;
};
