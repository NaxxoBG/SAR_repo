#include "Visitor.h"

class Keeper : Visitor
{
	void visit(Fish* f) override;
	void visit(Monkey* m) override;
	void visit(Tiger* t) override;
};

void Keeper::visit(Fish *f)
{
	f->cleanTeeth();
}

void Keeper::visit(Monkey *m)
{
	m->feedBanana();
}

void Keeper::visit(Tiger *t)
{
	t->scratchBack();
}