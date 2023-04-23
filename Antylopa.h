#pragma once
#include "Zwierze.h"
class Antylopa :
    public Zwierze
{
	private:
	const int ruchy[8][2] = { {0,2},{2,0},{0,-2},{-2,0},{1,1},{1,-1},{-1,1},{-1,-1} };
    public:
	Antylopa(int x, int y);
	void akcja();
	bool czyUcieczka();
	Antylopa* dziecko();
};

