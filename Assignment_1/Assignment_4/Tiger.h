#pragma once

#include "Visitor.h"
#include <ostream>
#include "Animal.h"

#include <iostream>

class Tiger : public Animal
{
public:
	void scratchBack()
	{
		std::cout << "Scratching tiger's back." << std::endl;
		notify(Events::tigerScratched);
	}
	void accept(Visitor& v) override;
};