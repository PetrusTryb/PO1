#include "Owca.h"

Owca::Owca(int x, int y) : Zwierze(USE_EMOJI?u8"🐑":"Ow", 4, 4, x, y)
{
}

Owca* Owca::dziecko()
{
    return new Owca(*this);
}
