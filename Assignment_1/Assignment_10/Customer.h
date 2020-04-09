#pragma once

enum Dishes
{
	SteakAndFries,
	EggSalad,
	RoastedTofu,
};

class Customer
{
public:
	virtual bool serveDish(Dishes dish) = 0;
};
