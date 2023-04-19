#include "Mlecz.h"

Mlecz::Mlecz(int x, int y): Roslina(u8"🌼", 0, x, y)
{
}

void Mlecz::akcja()
{
	for (int i = 0; i < 3; i++) {
		Roslina::akcja();
	}
}

Organizm* Mlecz::dziecko()
{
	return new Mlecz(*this);
}
