#pragma once

#include "Car.h"

class Speedster : public Car
{
public:
	Speedster(Engine *en, Brake *brake, Transmission *ts, Horn *horn);
	void applyThrottle() override;
	void applyBrake() override;
	void honk() override;
	void reverse() override;
};
