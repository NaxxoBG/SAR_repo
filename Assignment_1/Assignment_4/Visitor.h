#pragma once

class Monkey;
class Tiger;
class Fish;

class Visitor
{
public:
	virtual void visit(Monkey &m) = 0;
	virtual void visit(Tiger &t) = 0;
	virtual void visit(Fish &f) = 0;
};
