#pragma once
#include "Zwierze.h"
class Czlowiek :
    public Zwierze
{
private:
	int umiejetnosc;
	pair<int,int> kierunek;
public:
    Czlowiek(int x, int y);
	void akcja();
	bool setKierunek(pair<int,int> kierunek);
	void aktywujUmiejetnosc();
	void setUmiejetnosc(int umiejetnosc);
	string toString();
	Czlowiek* dziecko();
};

