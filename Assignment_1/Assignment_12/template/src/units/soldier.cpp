#include "units/soldier.hpp"
#include "weapons/weapon.hpp"

Soldier::Soldier(Weapon *weapon) : weapon(weapon)
{
}

void Soldier::shootAt(Unit *unit)
{
	notify(UnitEvent(UnitEvent::attack));
    weapon->shootAt(unit);
}

void Soldier::takeHit(projectile *projectile)
{
    notify(UnitEvent(UnitEvent::hit));
}