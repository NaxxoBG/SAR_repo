#pragma once
#include "units/unit.hpp"

class Weapon;

class Soldier : public Unit
{
public:
    Soldier(Weapon *weapon);

    virtual void shootAt(Unit *) override;

    virtual void takeHit(projectile *) override;

private:
    Weapon *weapon;
};
