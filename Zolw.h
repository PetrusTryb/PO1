#pragma once
#include "Zwierze.h"
class Zolw :
    public Zwierze
{
    public:
	Zolw(int x, int y);
	void akcja();
	void kolizja(Organizm* inny);
	Zolw* dziecko();
};

