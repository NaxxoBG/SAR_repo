#pragma once

#include "Animal.h"
#include <iostream>

class Monkey : Animal
{
public:
	void feedBanana()
	{
		std::cout << "Feeding monkey with a banana." << std::endl;
	}
	void accept(Visitor& v) override;
};

void Monkey::accept(Visitor &v)
{
	v.visit(*this);
}

