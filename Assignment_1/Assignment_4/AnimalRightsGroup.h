#pragma once
#include "Observer.h"

class AnimalRightsGroup : public Observer
{
	int nmon, ntig, nfish;
	int monEvents, tigEvents, fiEvents;
public:
	AnimalRightsGroup(int n_monkeys, int n_tigers, int n_fish);
	void update(Events event) override;
	bool animalsOK() const;
};
