#include "Horn.h"

class UniversalHorn : public Horn
{
public:
	void honk(char* sound, int times_repeated) override;
};

void UniversalHorn::honk(char* sound, int times_repeated)
{
	for (int i = 0; i < times_repeated; i++)
	{
		printf("%s\n", sound);
	}
}
