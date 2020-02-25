#pragma once

#include "Fish.h"
#include "Tiger.h"
#include "Monkey.h"

class Keeper : public Visitor
{
public:
	void visit(Fish &f) override
	{
		f.cleanTeeth();
	}

	void visit(Monkey &m) override
	{
		m.feedBanana();
	}

	void visit(Tiger &t) override
	{
		t.scratchBack();
	}
};
