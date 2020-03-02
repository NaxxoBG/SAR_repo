#pragma once
#include <vector>

#include "FilterStage.h"
#include "Monkeyy.h"

class Monkey_Loader
{
public:
	Monkey_Loader();
	Monkey_Loader(FilterStage *fs);
	std::vector<Monkeyy> load();
	FilterStage* set_next(FilterStage*);
private:
	FilterStage* next;
};
