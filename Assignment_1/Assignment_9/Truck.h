#pragma once

#include "Car.h"
#include  "Horn.h"

class Truck : public Car
{
public:
	Truck(Engine *en, Brake *brake, Transmission *ts, Horn *horn);
	void applyThrottle() override;
	void applyBrake() override;
	void honk() override;
	void reverse() override;
};
