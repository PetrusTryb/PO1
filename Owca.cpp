#include "Owca.h"

Owca::Owca(int x, int y) : Zwierze(u8"🐑", 4, 4, x, y)
{
}

Owca* Owca::dziecko()
{
    return new Owca(*this);
}
