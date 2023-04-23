#include "Trawa.h"

Trawa::Trawa(int x, int y): Roslina(USE_EMOJI?u8"🌱":"Tr", 0, x, y)
{
}

Organizm* Trawa::dziecko()
{
    return new Trawa(*this);
}
