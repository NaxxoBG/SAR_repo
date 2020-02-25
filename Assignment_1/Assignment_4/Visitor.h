#pragma once

#include "Fish.h"
#include "Tiger.h"
#include "Monkey.h"

class Visitor
{
	virtual void visit(Monkey *m);
	virtual void visit(Tiger *t);
	virtual void visit(Fish *f);
};
