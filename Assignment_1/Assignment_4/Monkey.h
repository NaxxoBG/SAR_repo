#pragma once

#include "Animal.h"
#include <iostream>
#include "Visitor.h"

class Monkey : Animal
{
	void accept(Visitor& v) override;
public:
	void feedBanana()
	{
		std::cout << "Feeding monkey with a banana." << std::endl;
	}
};

inline void Monkey::accept(Visitor &v)
{
	v.visit(*this);
}

