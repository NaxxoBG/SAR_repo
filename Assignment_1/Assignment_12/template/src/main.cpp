

#include <ctime>
#include <vector>

#include "../include/monitor/battle_monitor.hpp"
#include "../include/units/soldier.hpp"
#include "../include/units/unit_selection.hpp"
#include "../include/weapons/Revolver.hpp"

class null_monitor : public Observer<UnitEvent>
{
public:
	void do_update(void *event_ptr) override
	{
		UnitEvent event = *((UnitEvent *)event_ptr);
		printf("Hello world!");
	}
};

int main(int argc, char **argv)
{

    /* TODO implement a concrete instance of a weapon. Two patterns are involved:
    *  The weapon itself uses a "template method pattern".
    *  The composition of solider and weapon is a strategy pattern.
    */

	srand((unsigned)time(NULL));
	
    std::vector<Unit *> units = {
        new Soldier(new Revolver()),
        new Soldier(new Revolver()),
        new Soldier(new Revolver()),
        new Soldier(new Revolver())};

    // TODO replace null monitor with a more interesting one
    battle_monitor m;
    for (auto *u : units)
    {
        u->attach(&m);
    }

    /* TODO implement the unit selection mechanism using a "composite pattern".
    * This makes it possible to treat a collection of object as a single entity
    * For example calling s1.shootAt(s2) should cause all units within the selection s1 
    * to shoot at s2.
    */
    UnitSelection s1;
    s1.attach(&m);
    s1.addToSelection(units[1]);
    s1.addToSelection(units[2]);

    UnitSelection s2;
    s1.attach(&m);
    s2.addToSelection(units[2]);
    s2.addToSelection(units[3]);

    s1.shootAt(&s2);
    s2.shootAt(&s1);

	getchar();
    return 0;
}
