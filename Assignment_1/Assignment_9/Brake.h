#pragma once

class Brake
{
public:
	~Brake() = default;
	Brake()
	{
		this->breaking;
	}
	Brake(int zero_to_hundred)
	{
		this->zero_to_hundred = zero_to_hundred;
		this->breaking;
	}
	void applyBrake()
	{
		this->setSpeed(speed -= 100.0 / zero_to_hundred);
	}
	double getSpeed() const
	{
		return this->speed;
	}
	double setSpeed(const double speed)
	{
		return this->speed = speed;
	}
protected:
	double speed = 0;
	int zero_to_hundred = 0;
	bool breaking;
};
