#include <cstdio>

#include "monitor/battle_monitor.hpp"
#include "units/unit.hpp"


void battle_monitor::do_update(void *event_ptr)
{
	auto event = *static_cast<UnitEvent*>(event_ptr);
	printf("%d: %s", ++event_counter, event.message.c_str());
}
