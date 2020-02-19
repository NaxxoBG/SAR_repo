#pragma once

#include <sstream>
#include "logger.hpp"

template <typename T>
class TemplateCalculator
{
public:

	TemplateCalculator(Logger* logger)
	{
		this->logger = logger;
	}
	
	// Implement here
	T sum (T a, T b)
	{
			const auto sum = a + b;
			logger->log("Template calculator addition: " + std::to_string(a) + " + " + std::to_string(b) + " = " + std::to_string(sum));
			return sum;
	}

	T multiply(T a, T b)
	{
			const auto product = a * b;
			logger->log("Template calculator multiplication: " + std::to_string(a) + " * " + std::to_string(b) + " = " + std::to_string(product));
			return product;
	}
	
private:
    Logger *logger;
};