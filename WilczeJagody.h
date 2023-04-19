#pragma once
#include "Roslina.h"
class WilczeJagody :
    public Roslina
{
    public:
	WilczeJagody(int x, int y);
	void kolizja(Organizm* inny);
	Organizm* dziecko();
};

