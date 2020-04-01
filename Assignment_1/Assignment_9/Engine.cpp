#include "Engine.h"

#include <chrono>
#include <thread>

Engine::Engine(const int zero_to_hundred)
{
	this->zero_to_hundred = zero_to_hundred;
}

void Engine::applyThrottle()
{
	this->setSpeed(speed += 100.0 / zero_to_hundred);
}
