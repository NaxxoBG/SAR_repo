#pragma once

class Transmission
{
public:
	virtual ~Transmission() = default;
	virtual void setGear(int g) = 0;
	virtual void adjustGear() = 0;
	int getGear() const
	{
		return this->gear;
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
	int gear = 0;
};