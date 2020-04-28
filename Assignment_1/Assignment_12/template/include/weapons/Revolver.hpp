#pragma once

#include "weapon.hpp"

class Revolver : public Weapon
{
public:
	projectile* getProjectile() override;

private:
	float getAccuracy() override;
	const float accuracy = 0.60f;
};