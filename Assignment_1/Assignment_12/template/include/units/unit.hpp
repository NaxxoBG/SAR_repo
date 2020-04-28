#pragma once

#include <string>

#include "monitor/subject.hpp"

// TODO add more relevant information to struct
struct UnitEvent
{
    std::string message;
	enum action {hit, attack, idle, miss};

	UnitEvent(action a)
	{
		switch (a) {
		case hit:
			message = "Action - [HIT]: AAAAAAgh...!@$!$, I got hit, need a medic.....\n\n";
			break;
		case attack:
			message = "Action - [ATTACK]: Acquiring target ...standby, BRAVO-SIX, engaging...\n\n";
			break;
		case idle:
			message = "Action - [IDLE]: Affirmative! Standing by... just give the order, sarge\n\n";
			break;
		case miss:
			message = "Action - [MISS]: I've got a negative on the target...\n\n";
			break;
		default:
			message = "Action - [IDLE]: Affirmative! Standing down... stand-by for further action, just give the order, sarge\n\n";
			break;
		}
	}
};

class projectile;

class Unit : public Subject<UnitEvent>
{
public:
    virtual void shootAt(Unit *) = 0;

    virtual void takeHit(projectile *) = 0;
};
