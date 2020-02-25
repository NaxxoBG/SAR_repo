#pragma once

class Visitor;

class Animal
{
public:
	virtual ~Animal() = default;
	virtual void accept(Visitor &v) = 0;
	
};