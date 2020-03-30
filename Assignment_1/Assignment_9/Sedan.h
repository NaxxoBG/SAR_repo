#pragma once

#include "Car.h"
#include "Horn.h"

class Sedan : public Car
{
	void adjustGear() override;
public:
	Sedan(Horn* horn);
	void applyThrottle() override;
	void applyBrake() override;
	void honk() override;
	void setGear(int g) override;
private:
	Horn *horn;
};
