#include "Zolw.h"
#include "Swiat.h"

Zolw::Zolw(int x, int y): Zwierze(USE_EMOJI?u8"🐢":"Zo", 2, 1, x, y)
{
}

void Zolw::akcja()
{
    bool robiRuch = (rand() % 100) >= 75;
    if (robiRuch)
        Zwierze::akcja();
    else
        postarz();
}

void Zolw::kolizja(Organizm* inny)
{
    if (inny->getSila() < 5 && typeid(*this) != typeid(*inny)) {
        swiat->dodajLog(this, u8"Odparł atak");
        inny->cofnijRuch();
    }
    else
        Zwierze::kolizja(inny);
}

Zolw* Zolw::dziecko()
{
    return new Zolw(*this);
}
