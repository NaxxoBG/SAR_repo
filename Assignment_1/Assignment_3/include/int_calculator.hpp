#pragma once
#include "logger.hpp"

class IntCalculator
{
public:
	virtual ~IntCalculator() = default;
	// Dependency injection through constructor
    IntCalculator(Logger *logger);

    virtual int sum(int a, int b);

    virtual int multiply(int a, int b);

private:
    Logger *logger;
};