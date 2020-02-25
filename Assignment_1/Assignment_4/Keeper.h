#pragma once

#include "Tiger.h"
#include "Fish.h"
#include "Monkey.h"

class Keeper : public Visitor
{
public:
	void visit(Fish &f) override;
	void visit(Monkey &m) override;
	void visit(Tiger &t) override;
};
