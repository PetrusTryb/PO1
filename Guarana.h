#pragma once
#include "Roslina.h"
class Guarana :
    public Roslina
{
    public:
	Guarana(int x, int y);
	void kolizja(Organizm* inny);
	Organizm* dziecko();
};

