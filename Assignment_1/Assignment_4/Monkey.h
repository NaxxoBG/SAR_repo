#pragma once

#include "Animal.h"
#include <iostream>
#include "Visitor.h"

class Monkey : public Animal
{
public:
	void feedBanana()
	{
		std::cout << "Feeding monkey with a banana." << std::endl;
	}
	void accept(Visitor& v) override;
};

