#pragma once
#include "Transmission.h"

class TransmissionSpeedster : public Transmission
{
public:
	TransmissionSpeedster() = default;
	void setGear(int g) override;
	void adjustGear() override;
};
