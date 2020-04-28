#pragma once
#include "units/unit.hpp"

class Weapon;

class Soldier : public Unit
{
public:
    Soldier(Weapon *weapon);

    void shootAt(Unit *) override;

    void takeHit(projectile *) override;

private:
    Weapon *weapon;
};
