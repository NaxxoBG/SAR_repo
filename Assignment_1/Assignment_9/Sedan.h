#pragma once

#include "Car.h"

class Sedan : public Car
{
	void adjustGear() override;
public:
	Sedan();
	void applyThrottle() override;
	void applyBrake() override;
	void honk() override;
	void setGear(int g) override;
};
