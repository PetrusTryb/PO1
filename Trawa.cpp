#include "Trawa.h"

Trawa::Trawa(int x, int y): Roslina(u8"🌱", 0, x, y)
{
}

Organizm* Trawa::dziecko()
{
    return new Trawa(*this);
}
