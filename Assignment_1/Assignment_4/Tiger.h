#pragma once

#include "Visitor.h"
#include <ostream>
#include "Animal.h"

#include <iostream>

class Tiger : Animal
{
	void accept(Visitor& v) override;

public:
	void scratchBack()
	{
		std::cout << "Scratching tiger's back." << std::endl;
	}
};

inline void Tiger::accept(Visitor & v)
{
	v.visit(*this);
}