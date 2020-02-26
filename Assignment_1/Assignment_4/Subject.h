#pragma once

#include <list>
#include "Event.h"
#include "Observer.h"

class Subject
{
public:
	void attach(Observer* o)
	{
		this->observers_.push_front(o);
	}

	void detach(Observer* o)
	{
		this->observers_.remove(o);
	}

	void notify(const Events o)
	{
		for (Observer* observer : observers_)
		{
			observer->update(o);
		}
	}

	virtual ~Subject() = default;
protected:
	std::list<Observer*> observers_;
};
