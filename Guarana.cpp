#include "Guarana.h"
#include "Swiat.h"

Guarana::Guarana(int x, int y) : Roslina(u8"🍀", 0, x, y)
{
}

void Guarana::kolizja(Organizm* inny)
{
	string nazwa = typeid(*inny).name();
	swiat->dodajLog(this, u8"Wzmocniła " + nazwa.substr(6));
	inny->wzmocnij(3);
	zabij();
}

Organizm* Guarana::dziecko()
{
	return new Guarana(*this);
}
