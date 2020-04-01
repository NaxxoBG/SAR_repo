#pragma once

#include "Car.h"
#include "Horn.h"
#include "Engine.h"
#include  "Brake.h"
#include "Transmission.h"

class Sedan : public Car
{
public:
	Sedan(Engine *en, Brake *brake, Transmission *ts, Horn *horn);
	void applyThrottle() override;
	void applyBrake() override;
	void honk() override;
	void reverse() override;
};
