#pragma once
#include <cstdio>

#include "Customer.h"

class Vegan : public Customer
{
public:
	bool serveDish(Dishes dish) override;
};

inline bool Vegan::serveDish(Dishes dish)
{
	switch (dish)
	{
	case EggSalad:
		printf("AARARAG i am a vegan i shall eat no eggs!\n");
		return false;
	case SteakAndFries:
		printf("AAAAAARARAGARAG this is even worse as a vegan i do not eat meat!!\n");
		return false;
	case RoastedTofu:
		printf("Yummy tofu, this fits my dietary requirements\n");
		return true;
	}
}
