#pragma once
#include "Roslina.h"
class Mlecz :
    public Roslina
{
	public:
	Mlecz(int x, int y);
	void akcja();
	Organizm* dziecko();
};

