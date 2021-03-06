#pragma once
#include "decorator.h"
#include<iostream>
#include<windows.h>
#include <mmsystem.h>

class radiowrapper : public decorator
{
	Car *car;
public:
	radiowrapper(Car* car)
	{
		this->car = car;
	};
	void applyBrake() override;
	void applyThrottle() override;
	void honk() override;
	void reverse() override;
	void playRadioSong();
};

inline void radiowrapper::applyBrake()
{
	car->applyBrake();
}

inline void radiowrapper::applyThrottle()
{
	car->applyThrottle();
}

inline void radiowrapper::honk()
{
	car->honk();
}

inline void radiowrapper::reverse()
{
	car->reverse();
}

inline void radiowrapper::playRadioSong()
{
	printf("%s\n", "Playing radio...");
	PlaySound(TEXT("island_music_x"), NULL, SND_FILENAME | SND_ASYNC);
}
