#pragma once

#include "Visitor.h"

class Animal
{
	virtual void accept(Visitor &v) = 0;
};