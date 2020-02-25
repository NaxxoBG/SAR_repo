#include "Keeper.h"

void Keeper::visit(Fish &f)
{
	f.cleanTeeth();
}

void Keeper::visit(Monkey &m)
{
	m.feedBanana();
}

void Keeper::visit(Tiger &t)
{
	t.scratchBack();
}