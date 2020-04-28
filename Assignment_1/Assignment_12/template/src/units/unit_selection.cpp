#include "units/unit_selection.hpp"
#include "weapons/weapon.hpp"

void UnitSelection::addToSelection(Unit *unit)
{
    // TODO add unit to selection
	selected.emplace_back(unit);
}

void UnitSelection::shootAt(Unit *unit)
{
	// TODO all selected units should shoot at target unit
	for (auto *u : selected)
	{
		u->shootAt(unit);
	}
}

void UnitSelection::takeHit(projectile *Projectile)
{
    // TODO implement when a group takes a hit
    // decide which units should get hit, a random one? or all of them?

	selected[rand() % this->selected.size()]->takeHit(Projectile);
}
