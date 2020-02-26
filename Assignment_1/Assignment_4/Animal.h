#pragma once
#include "Subject.h"

class Visitor;

class Animal : public Subject
{
public:
	virtual ~Animal() = default;
	virtual void accept(Visitor &v) = 0;
};