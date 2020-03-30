#pragma once

#include "Car.h"
#include  "Horn.h"

class Truck : public Car
{
	void adjustGear() override;
public:
	Truck(Horn *horn);
	void applyThrottle() override;
	void applyBrake() override;
	void honk() override;
	void setGear(int g) override;

private:
	Horn *horn;
};
