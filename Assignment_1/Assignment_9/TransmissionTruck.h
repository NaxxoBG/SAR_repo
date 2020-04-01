#pragma once
#include "Transmission.h"

class TransmissionTruck : public Transmission
{
public:
	TransmissionTruck() = default;
	void setGear(int g) override;
	void adjustGear() override;
};
