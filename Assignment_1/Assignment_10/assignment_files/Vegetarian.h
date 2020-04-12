#pragma once
#include <cstdio>

#include "Customer.h"

class Vegetarian : public Customer
{
public:
	bool serveDish(Dishes dish) override;
};

inline bool Vegetarian::serveDish(Dishes dish)
{
	switch (dish)
	{
	case EggSalad:
		printf("I love me some eggs!\n");
		return true;
	case SteakAndFries:
		printf("Do i look like i would eat this?\n");
		return false;
	case RoastedTofu:
		printf("Yummy tofu, this fits my dietary requirements\n");
		return true;
	}
}