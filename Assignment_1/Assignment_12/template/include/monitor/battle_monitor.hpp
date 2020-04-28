#pragma once
#include "observer.hpp"
#include "units/unit.hpp"

class battle_monitor : public Observer<UnitEvent>
{
	int event_counter = 0;
	void do_update(void* event) override;
};
