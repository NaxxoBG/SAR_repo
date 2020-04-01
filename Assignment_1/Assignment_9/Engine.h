#pragma once
#include <thread>

class Engine
{
public:
	virtual ~Engine() = default;
	Engine() = default;
	Engine(int zero_to_hundred);
	void applyThrottle();
	void setSpeed(double speed)
	{
		this->speed = speed;
	}
	double getSpeed()
	{
		return this->speed;
	}
private:
	double zero_to_hundred = 0;
	bool breaking;
	double speed = 0.0;
};
