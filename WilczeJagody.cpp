#include "WilczeJagody.h"
#include "Swiat.h"

WilczeJagody::WilczeJagody(int x, int y) : Roslina(u8"🍒", 99, x, y)
{
}

void WilczeJagody::kolizja(Organizm* inny)
{
	string nazwa = typeid(*inny).name();
	swiat->dodajLog(this, u8"Zatruły "+nazwa.substr(6));
	inny->zabij();
	zabij();
}

Organizm* WilczeJagody::dziecko()
{
	return new WilczeJagody(*this);
}
