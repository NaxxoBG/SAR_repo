// Assignment_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include "Fish.h"
#include "Tiger.h"
#include "Monkey.h"
#include "Keeper.h"
#include "Tourist.h"
#include "AnimalRightsGroup.h"
using namespace std;

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
	
	AnimalRightsGroup *ag = new AnimalRightsGroup(1, 1, 2);

	nemo->attach(ag);
	shere_khan->attach(ag);
	dunston->attach(ag);
	dori->attach(ag);
	
	zoo.push(nemo);
	zoo.push(shere_khan);
	zoo.push(dunston);
	zoo.push(dori);
	//---------------------- Keeper ---------------------------------
	while (!zoo.empty())
	{
		cout << boolalpha << "Are animals ok?: " << ag->animalsOK() << endl;
		auto a = zoo.front();
		a->accept(jack);
		zoo.pop();
	}
	cout << boolalpha << "Are animals ok?: " << ag->animalsOK() << endl;

	//---------------------- Tourist ---------------------------------
	cout << endl << "Testing tourist: " << endl;
	
	zoo.push(nemo);
	zoo.push(shere_khan);
	zoo.push(dunston);
	zoo.push(dori);
	
	while (!zoo.empty())
	{
		auto a = zoo.front();
		a->accept(jim);
		zoo.pop();
	}
}
