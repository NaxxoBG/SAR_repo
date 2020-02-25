#pragma once

#include <ostream>
#include <iostream>

#include "Visitor.h"
#include "Animal.h"

class Fish : Animal
{
	void accept(Visitor& v) override;

public:
	void cleanTeeth()
	{
		std::cout << "Cleaning fish' teeth." << std::endl;
	}
};

void Fish::accept(Visitor &v)
{
	v.visit(*this);
}