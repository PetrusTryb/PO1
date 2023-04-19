#include "Zwierze.h"
#include "Swiat.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
using namespace std;

Zwierze::Zwierze(string ikona, int sila, int inicjatywa, int x, int y) : Organizm(ikona, sila, inicjatywa, x, y)
{

}

void Zwierze::akcja()
{
	postarz();
	int move = rand() % 4;
	while (!setPozycja({ getX()+moves[move][0], getY()+moves[move][1] }, false)) {
		move++;
		move %= 4;
	}
}

void Zwierze::kolizja(Organizm *inny)
{
	if(this==inny)
		return;
	if (typeid(*this) == typeid(*inny)) {
		if(getWiek()<2||inny->getWiek()<2)
			return;
		swiat->dodajLog(this,u8"Rozmna¿anie");
		auto dziecko = dynamic_cast<Zwierze*>(this->dziecko());
		int move = rand() % 4;
		while (!dziecko->setPozycja({ getX()+moves[move%4][0], getY()+moves[move%4][1] },true)) {
			move++;
			if (move > 8) {
				swiat->dodajLog(this, u8"Nie ma miejsca na rozmno¿enie");
				dziecko->zabij();
				return;
			}
		}
	}
	else if (czyUcieczka() || inny->czyUcieczka())
	{
		return;
	}
	else if (getSila() > inny->getSila())
	{
		swiat->dodajLog(this, u8"Wygra³ walkê");
		inny->zabij();
	}
	else if (getSila() < inny->getSila())
	{
		swiat->dodajLog(this, u8"Przegra³ walkê");
		zabij();
	}
	else
	{
		swiat->dodajLog(this, u8"Równe si³y");
		zabij();
		inny->zabij();
	}
}