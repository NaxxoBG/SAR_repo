#pragma once
#include "Visitor.h"
#include <ostream>
#include <iostream>
#include "Animal.h"

class Tiger : Animal
{
	void accept(Visitor& v) override;

public:
	void scratchBack()
	{
		std::cout << "Scratching tiger's back." << std::endl;
	}
};

void Tiger::accept(Visitor & v)
{
	v.visit(*this);
}