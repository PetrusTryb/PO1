#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(string ikona, int sila, int x, int y): Organizm(ikona, sila, 0, x, y)
{
}

void Roslina::akcja()
{
	bool zasieje = rand() % 100 == 0;
	if (zasieje) {
		auto dziecko = dynamic_cast<Roslina*>(this->dziecko());
		int move = rand() % 4;
		while (!dziecko->setPozycja({ getX() + moves[move % 4][0], getY() + moves[move % 4][1] }, true)) {
			move++;
			if (move > 8) {
				swiat->dodajLog(this, "Nie ma miejsca na rozsianie");
				dziecko->zabij();
				return;
			}
		}
		swiat->dodajLog(this, u8"Rozsia�a si�");
	}
}

void Roslina::kolizja(Organizm* inny)
{
	if(this==inny)
		return;
	if (getSila() > inny->getSila())
	{
		swiat->dodajLog(this, u8"Zatru�a napastnika");
		inny->zabij();
	}
	else if (getSila() < inny->getSila())
	{
		swiat->dodajLog(this, u8"Zosta�a zdeptana");
		zabij();
	}
	else
	{
		swiat->dodajLog(this, u8"R�wne si�y");
		zabij();
		inny->zabij();
	}
}
