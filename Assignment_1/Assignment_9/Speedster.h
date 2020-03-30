#pragma once

#include "Car.h"

class Speedster : public Car
{
	void adjustGear() override;
public:
	Speedster();
	void applyThrottle() override;
	void applyBrake() override;
	void honk() override;
	void setGear(int g) override;
};
