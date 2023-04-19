#include "BarszczSosnowskiego.h"
#include "Swiat.h"
#include "Zwierze.h"

BarszczSosnowskiego::BarszczSosnowskiego(int x, int y) : Roslina(u8"🌵", 10, x, y)
{
}

void BarszczSosnowskiego::akcja()
{
	for (int i = 0; i < 4; i++) {
		auto sasiad = swiat->getOrganizm({ getX() + moves[i][0], getY() + moves[i][1]});
		if (sasiad != nullptr) {
			bool isZwierze = dynamic_cast<Zwierze*>(sasiad);
			if (isZwierze) {
				swiat->dodajLog(this, u8"Zatruł sąsiada");
				sasiad->zabij();
			}
		}
	}
}

void BarszczSosnowskiego::kolizja(Organizm* inny)
{
	string nazwa = typeid(*inny).name();
	swiat->dodajLog(this, u8"Zatruł " + nazwa.substr(6));
	inny->zabij();
	zabij();
}

Organizm* BarszczSosnowskiego::dziecko()
{
	return new BarszczSosnowskiego(*this);
}
