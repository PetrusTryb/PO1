#pragma once
#include "Organizm.h"
class Zwierze :
    public Organizm
{
    public:
	Zwierze(string ikona, int sila, int inicjatywa, int x, int y);
	virtual void akcja();
	virtual void kolizja(Organizm* inny);
};

