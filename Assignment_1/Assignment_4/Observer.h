#pragma once
#include "Event.h"

class Observer
{
public:
	virtual void update(Events event) = 0;
};
