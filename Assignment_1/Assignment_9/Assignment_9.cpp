// Assignment_9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "CarFactory.h"

int main()
{
	CarFactory f;
	auto sedan = f.getVehicle("sedan");
	
	std::vector<Car*> cars = { sedan };

    for (auto car : cars)
    {
    	// to test the radio decorator functionality, 
		static_cast<radiowrapper>(car).playRadioSong();
		car->applyThrottle();
    	std::this_thread::sleep_for(std::chrono::seconds(7)); // throttling for 7 secs

		car->applyBrake();
		std::this_thread::sleep_for(std::chrono::seconds(7)); // braking for 3 secs

    	std::cout << "Trying to reverse...\n";
		car->reverse();
    	std::cout << "--------------------\n\n";
	}
}
