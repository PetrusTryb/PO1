#include "Czlowiek.h"
#include "Swiat.h"

Czlowiek::Czlowiek(int x, int y) : Zwierze(u8"🚹", 5, 4, x, y)
{
	umiejetnosc = -5;
	kierunek = { 0,0 };
}

void Czlowiek::akcja()
{
	postarz();
	int predkosc = 1;
	if (umiejetnosc > 2)
	{
		predkosc = 2;
	}
	else if(umiejetnosc>0)
		predkosc = rand() % 2 + 1;
	if(umiejetnosc>-5)
		umiejetnosc--;
	setPozycja({getX()+kierunek.first*predkosc,getY()+kierunek.second*predkosc}, false);
	kierunek = { 0,0 };
}

bool Czlowiek::setKierunek(pair<int, int> kierunek)
{
	if((getX()+kierunek.first)<0 || (getX()+kierunek.first)>=swiat->getSzerokosc() || (getY()+kierunek.second)<0 || (getY()+kierunek.second)>=swiat->getWysokosc())
		return false;
	this->kierunek = kierunek;
	return true;
}

void Czlowiek::aktywujUmiejetnosc()
{
	if (umiejetnosc == -5)
	{
		swiat->dodajLog(this, u8"Aktywowano Szybkość antylopy");
		umiejetnosc = 5;
	}
}

void Czlowiek::setUmiejetnosc(int umiejetnosc)
{
	this->umiejetnosc = umiejetnosc;
}

string Czlowiek::toString()
{
	string dane = Zwierze::toString();
	dane += to_string(umiejetnosc) + ";";
	return dane;
}

Czlowiek* Czlowiek::dziecko()
{
	return nullptr;
}
