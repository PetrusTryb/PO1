#include "Antylopa.h"
#include "Swiat.h"

Antylopa::Antylopa(int x, int y): Zwierze(u8"🦌", 4, 4, x, y)
{
}

void Antylopa::akcja()
{
	postarz();
	int move = rand() % 8;
	while (!setPozycja({ getX() + moves[move][0], getY() + moves[move][1] }, false)) {
		move++;
		move %= 8;
	}
}

bool Antylopa::czyUcieczka()
{
	bool ucieczka = rand() % 2;
	if (ucieczka) {
		int move = 0;
		while (!setPozycja({ getX() + moves[move][0], getY() + moves[move][1] }, true)) {
			move++;
			if (move == 8) {
				swiat->dodajLog(this,u8"Nie udało się uciec");
				return false;
			}
		}
		swiat->dodajLog(this, u8"Udało się uciec");
		return true;
	}
	return false;
}

Antylopa* Antylopa::dziecko()
{
	return new Antylopa(*this);
}
