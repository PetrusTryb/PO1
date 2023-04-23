#include "Mlecz.h"

Mlecz::Mlecz(int x, int y): Roslina(USE_EMOJI?u8"🌼":"Ml", 0, x, y)
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
