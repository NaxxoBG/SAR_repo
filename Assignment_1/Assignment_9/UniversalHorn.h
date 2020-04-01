#pragma once
#include <cstdio>

#include "Horn.h"

class UniversalHorn : public Horn
{
	const char* sound;
	int repetitions;
public:
	UniversalHorn(const char* sound, int repetitions);
	void honk() override;

};

UniversalHorn::UniversalHorn(const char* sound, int repetitions)
{
	this->sound = sound;
	this->repetitions = repetitions;
}

void UniversalHorn::honk()
{
	for (int i = 0; i < repetitions; i++)
	{
		printf("%s\n", sound);
	}
}