#pragma once
#include <cstdio>

#include "Customer.h"

class Omnivore : public Customer
{
public:
	bool serveDish(Dishes dish) override;
};

inline bool Omnivore::serveDish(Dishes dish)
{
	switch (dish)
	{
	case EggSalad:
		printf("Succulent eggs!\n");
		return true;
	case SteakAndFries:
		printf("A feast worth of gods!\n");
		return true;
	case RoastedTofu:
		printf("Soft and spongey\n");
		return true;
	}
}