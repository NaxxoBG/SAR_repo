#pragma once

#include <ostream>
#include <iostream>

#include "Visitor.h"
#include "Animal.h"

class Fish : public Animal
{
public:
	void cleanTeeth()
	{
		std::cout << "Cleaning fish' teeth." << std::endl;
	}
	void accept(Visitor& v) override;
};
