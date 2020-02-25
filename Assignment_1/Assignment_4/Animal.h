#pragma once

class Visitor;

class Animal
{
	virtual void accept(Visitor &v) = 0;
};