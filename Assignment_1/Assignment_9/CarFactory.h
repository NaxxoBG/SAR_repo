#pragma once
#include "Car.h"
#include "Sedan.h"
#include "SpecialHorn.h"
#include "Speedster.h"
#include "TransmissionSedan.h"
#include "TransmissionSpeedster.h"
#include "TransmissionTruck.h"
#include "Truck.h"
#include "UniversalHorn.h"
#include "logwrapper.h"
#include "radiowrapper.h"

struct CarFactory
{
	Car * getVehicle(const char* type)
	{
		
		Brake* sb;
		Horn* horn;
		Engine* en;
		Transmission* t;

		if (strcmp(type, "sedan") == 0)
		{
			sb = new Brake(10);
			horn = new UniversalHorn("Doot", 2);
			en = new Engine(10);
			t = new TransmissionSedan();
			return new radiowrapper(new logwrapper(new Sedan(en, sb, t, horn))); // example usage of the wrappers
		}
		if (strcmp(type, "speedster") == 0)
		{
			sb = new Brake(6);
			horn = new UniversalHorn("Deet", 2);
			en = new Engine(6);
			t = new TransmissionSpeedster();
			return new Speedster(en, sb, t, horn);
		}
		if (strcmp(type, "Truck") == 0)
		{
			sb = new Brake(20);
			horn = new UniversalHorn("Duuu", 2);
			en = new Engine(20);
			t = new TransmissionTruck();
			return new Truck(en, sb, t, horn);
		}
		return nullptr;
	}

	Car * getVehicle(const char * type, bool special)
	{
		auto car = getVehicle(type);
		if (special)
		{
			car->setHorn(new SpecialHorn("Beep", "Boop", 3));
		}
		return car;
	}
};




