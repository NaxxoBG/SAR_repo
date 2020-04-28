

#include "weapons/Revolver.hpp"
#include "weapons/projectile.hpp"

projectile * Revolver::getProjectile()
{
	return new projectile(90);
}

float Revolver::getAccuracy()
{
	return this->accuracy;
}

