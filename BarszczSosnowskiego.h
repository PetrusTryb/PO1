#pragma once
#include "Roslina.h"
class BarszczSosnowskiego :
    public Roslina
{
    public:
	BarszczSosnowskiego(int x, int y);
	void akcja();
	void kolizja(Organizm* inny);
	Organizm* dziecko();
};

