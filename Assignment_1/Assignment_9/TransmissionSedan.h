#pragma once
#include "Transmission.h"

class TransmissionSedan : public Transmission
{
public:
	TransmissionSedan() = default;
	void setGear(int g) override;
	void adjustGear() override;
};
