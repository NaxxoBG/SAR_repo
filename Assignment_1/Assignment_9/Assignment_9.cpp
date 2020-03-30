// Assignment_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


#include "Sedan.h"
#include "Speedster.h"
#include "Truck.h"

int main()
{
    std::cout << "Throttling...!\n";

    Car* sd = new Sedan();
	Car* sr = new Speedster();
	Car* tr = new Truck();
	
	std::vector<Car*> cars = { sd, sr, tr };

	for (int i = 0; i <= 2; i++)
	{
		int a = 0;

		cars[i]->applyThrottle();

		while (a < 7)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			cars[i]->dashboard();
			a += 1;
		}
		a = 0;
		std::cout << "Braking...!\n";
		cars[i]->applyBrake();
		while (a < 3)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			cars[i]->dashboard();
			a += 1;
		}
		std::cout << "Trying to reverse...\n";
		cars[i]->setGear(-1);
		std::cout << "Dashboard:\n";
		cars[i]->dashboard();
		std::cout << "--------------------\n\n";
	}
}
