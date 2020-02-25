// Assignment_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include "Fish.h"
#include "Tiger.h"
#include "Monkey.h"
#include "Keeper.h"
#include "Tourist.h"

void Fish::accept(Visitor &v)
{
	v.visit(*this);
}

void Monkey::accept(Visitor &v)
{
	v.visit(*this);
}

void Tiger::accept(Visitor &v)
{
	v.visit(*this);
}

int main()
{
	std::queue<Animal*> zoo;

	Keeper jack;
	Tourist jim;
	
	Fish *nemo = new Fish();
	Tiger *shere_khan = new Tiger();
	Monkey *dunston = new Monkey();
	Fish *dori = new Fish();

	zoo.push(nemo);
	zoo.push(shere_khan);
	zoo.push(dunston);
	zoo.push(dori);

	while (!zoo.empty())
	{
		Animal *a = zoo.front();
		a->accept(jack);
		a->accept(jim);
		jim.print();
		zoo.pop();
	}
}
