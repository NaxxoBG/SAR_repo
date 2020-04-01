#pragma once
#include "Horn.h"

class SpecialHorn : public Horn
{
	const char* sound;
	const char* sound2;
	int repetitions;
public:
	SpecialHorn(const char* sound, const char* sound2, int repetitions);
	void honk() override;

};

inline SpecialHorn::SpecialHorn(const char* sound, const char* sound2, int repetitions)
{
	this->sound = sound;
	this->sound2 = sound2;
	this->repetitions = repetitions;
}

inline void SpecialHorn::honk()
{
	for (int i = 0; i < repetitions; i++)
	{
		printf("%s %s\n", sound, sound2);
	}
};
