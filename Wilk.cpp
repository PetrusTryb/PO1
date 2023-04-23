#include "Wilk.h"

Wilk::Wilk(int x, int y) : Zwierze(USE_EMOJI?u8"🐶":"Wi", 9, 5, x, y)
{
}

Wilk* Wilk::dziecko()
{
	return new Wilk(*this);
}
