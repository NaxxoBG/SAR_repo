#include "AnimalRightsGroup.h"

AnimalRightsGroup::AnimalRightsGroup(const int n_monkeys, const int n_tigers, const int n_fish):
																								  nmon(n_monkeys),
                                                                                                  ntig(n_tigers),
                                                                                                  nfish(n_fish),
                                                                                                  monEvents(0),
                                                                                                  tigEvents(0),
                                                                                                  fiEvents(0)
{
}

void AnimalRightsGroup::update(Events event)
{
	switch (event)
	{
	case Events::monkeyFed:
		this->monEvents += 1;
		break;
	case Events::fishTeethCleaned:
		this->fiEvents += 1;
		break;
	case Events::tigerScratched:
		this->tigEvents += 1;
		break;
	}
}

bool AnimalRightsGroup::animalsOK() const
{
	return nmon == monEvents && nfish == fiEvents && ntig == tigEvents;
}
