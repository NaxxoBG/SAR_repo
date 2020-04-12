#include <string>
#include <vector>
#include "stdio.h"

#include "Omnivore.h"
#include "Vegan.h"
#include "Vegetarian.h"

using namespace std;

int main(int argc, char** argv)
{
	Customer* g = new Vegan();
	Customer* v = new Vegetarian();
	Customer* o = new Omnivore();

	std::vector<Customer*> customers = { g, v, o };

	for (auto c : customers)
	{
		printf("--------------------------------------------------------\n");
		c->serveDish(RoastedTofu);
		c->serveDish(EggSalad);
		c->serveDish(SteakAndFries);
	}
}
