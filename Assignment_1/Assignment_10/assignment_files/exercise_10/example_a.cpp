#include "stdio.h"
#include <string>
#include <vector>

using namespace std;

enum Dishes
{
	SteakAndFries,
	EggSalad,
	RoastedTofu,
};

class Customer
{
public:
	Customer(bool isVegan, bool isVegetarian) : isVegan(isVegan),
	                                            isVegetarian(isVegetarian)
	{
	}

	bool serveDish(Dishes dish)
	{
		if (isVegan)
		{
			if (dish == EggSalad)
			{
				printf("AARARAG i am a vegan i shall eat no eggs!\n");
				return false;
			}
			if (dish == SteakAndFries)
			{
				printf("AAAAAARARAGARAG this is even worse as a vegan i do not eat meat!!\n");
				return false;
			}
			if (dish == RoastedTofu)
			{
				printf("Yummy tofu, this fits my dietary requirements\n");
				return true;
			}
		}
		else if (isVegetarian)
		{
			if (dish == EggSalad)
			{
				printf("I love me some eggs!\n");
				return true;
			}
			if (dish == SteakAndFries)
			{
				printf("Do i look like i would eat this?\n");
				return false;
			}
			if (dish == RoastedTofu)
			{
				printf("Yummy tofu, this fits my dietary requirements\n");
				return true;
			}
		}
		else
		{
			if (dish == EggSalad)
			{
				printf("Succulent eggs!\n");
				return true;
			}
			if (dish == SteakAndFries)
			{
				printf("A feast worth of gods!\n");
				return true;
			}
			if (dish == RoastedTofu)
			{
				printf("Soft and spongey\n");
				return true;
			}
		}
	}

	bool isVegan;
	bool isVegetarian;
};

int main(int argc, char** argv)
{
	bool loggingEnabled = true;

	std::vector<Customer> customers = {
		Customer(true, false),
		Customer(false, false),
		Customer(false, true)
	};

	for (auto c : customers)
	{
		if (c.isVegan)
		{
			c.serveDish(RoastedTofu);
		}
		else if (c.isVegetarian)
		{
			c.serveDish(EggSalad);
		}
		else
		{
			c.serveDish(SteakAndFries);
		}
	}
}
