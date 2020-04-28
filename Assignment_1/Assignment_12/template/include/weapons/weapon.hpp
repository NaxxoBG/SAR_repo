
#pragma once
#include <random>

#include "units/unit.hpp"


class projectile;

class Weapon
{
public:
    void shootAt(Unit *u)
    {
        // TODO take into account accuracy stat
		
		std::random_device rd;
        const std::uniform_int_distribution<int> distribution(1, 100);
		std::mt19937 engine(rd());

        const auto value = distribution(engine);
		if ((value / 100) < this->getAccuracy())
		{
			u->takeHit(getProjectile());	
		} else
		{
			u->notify(UnitEvent(UnitEvent::miss));
		}
    }

private:
    virtual projectile *getProjectile() = 0;

    virtual float getAccuracy() = 0;
};
