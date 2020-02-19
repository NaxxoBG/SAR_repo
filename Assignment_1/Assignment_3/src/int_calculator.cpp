#include "../include/int_calculator.hpp"

IntCalculator::IntCalculator(Logger * logger)
{
	this->logger = logger;
}

int IntCalculator::sum(const int a, const int b)
{
	const auto sum = a + b;
	logger->log("Calculator addition: " + std::to_string(a) + " + " + std::to_string(b) + " = " + std::to_string(sum));
	return sum;
}

int IntCalculator::multiply(const int a, const int b)
{
	const auto product = a * b;
	logger->log("Calculator multiplication: " + std::to_string(a) + " * " + std::to_string(b) + " = " + std::to_string(product));
	return product;
}
