#include "Lis.h"
#include "Zwierze.h"
#include "Swiat.h"

Lis::Lis(int x, int y) : Zwierze(USE_EMOJI?u8"🦊":"Li", 3, 7, x, y)
{
}

void Lis::akcja()
{
	postarz();
	int move = rand()%4;
	pair<int, int> nowaPozycja;
	while (move <= 8) {
		nowaPozycja = { getX() + ruchy[move%4][0], getY() + ruchy[move%4][1] };
		if (swiat->getOrganizm(nowaPozycja) == nullptr) {
			if (setPozycja(nowaPozycja, false))
				break;
		}
		else if(swiat->getOrganizm(nowaPozycja)->getSila()<=getSila())
			if (setPozycja(nowaPozycja, false))
				break;
		move++;
	}
}

Lis* Lis::dziecko()
{
	return new Lis(*this);
}
