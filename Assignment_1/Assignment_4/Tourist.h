#pragma once

#include <cstdio>

#include "Fish.h"
#include "Monkey.h"
#include "Tiger.h"

class Tourist : public Visitor
{
	int monkey_count_;
	int tiger_count_;
	int fish_count_;
public:
	Tourist() : monkey_count_(0), tiger_count_(0), fish_count_(0) {}
	void print() const
	{
		printf("I have visited:\nMonkeys: %d, Tigers: %d, Fish: %d\n", monkey_count_, tiger_count_, fish_count_);
	}

	void visit(Fish &f) override
	{
		this->fish_count_++;
		this->print();
	}
	void visit(Monkey &m) override
	{
		this->monkey_count_++;
		this->print();
	}
	void visit(Tiger &t) override
	{
		this->tiger_count_++;
		this->print();
	}
};
