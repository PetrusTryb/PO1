#pragma once
#include "Zwierze.h"
class Lis :
    public Zwierze
{
    public:
	Lis(int x, int y);
	void akcja();
	Lis* dziecko();
};

