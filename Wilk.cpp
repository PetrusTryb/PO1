#include "Wilk.h"

Wilk::Wilk(int x, int y) : Zwierze(u8"🐶", 9, 5, x, y)
{
}

Wilk* Wilk::dziecko()
{
	return new Wilk(*this);
}
