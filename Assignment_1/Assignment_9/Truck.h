#pragma once

#include "Car.h"

class Truck : public Car
{
	void adjustGear() override;
public:
	Truck();
	void applyThrottle() override;
	void applyBrake() override;
	void honk() override;
	void setGear(int g) override;
};
