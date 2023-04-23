#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <chrono>
#include "Swiat.h"
#include "Czlowiek.h"
using namespace std;

enum klawisze { gora = 72, dol = 80, lewo = 75, prawo = 77, umiejetnosc = ' ', enter = 13, zapisz = 's', wczytaj='l' };

int main()
{
    srand(time(NULL));
    SetConsoleTitle(L"Piotr Trybisz [193557]");
    SetConsoleOutputCP(CP_UTF8);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 15;
    cfi.dwFontSize.Y = 20;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Courier New");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    ios::sync_with_stdio(false);
    int wysokosc, szerokosc;
    cout << u8"Wysokość świata: ";
    cin >> wysokosc;
    cout <<u8"Szerokość świata: ";
    cin >>szerokosc;
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    Swiat* swiat = Swiat::getInstance(szerokosc, wysokosc);
    swiat->poczatkowaPopulacja();
    swiat->rysujSwiat();
    char klawisz;
    ifstream lista_plikow;
    ifstream plik;
    string linia;
    while (1) {
        Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(swiat->getCzlowiek());
        klawisz = _getch();
        if (czlowiek != nullptr)
            switch (klawisz) {
            case gora:
                if (!czlowiek->setKierunek({ 0,-1 }))
                    continue;
                break;
            case dol:
                if (!czlowiek->setKierunek({ 0, 1 }))
                    continue;
                break;
            case lewo:
                if (!czlowiek->setKierunek({ -1, 0 }))
                    continue;
                break;
            case prawo:
                if (!czlowiek->setKierunek({ 1, 0 }))
                    continue;
                break;
            case umiejetnosc:
                czlowiek->aktywujUmiejetnosc();
                continue;
            case enter:
                break;
            case zapisz:
                swiat->zapiszStan();
				continue;
            case wczytaj:
                cout << "\x1B[2J\033[0;0H";
                lista_plikow.open("saves.csv");
                while (getline(lista_plikow, linia, ';'))
                {
                    cout << linia << " - ";
                    getline(lista_plikow, linia);
                    cout << linia<<endl;
				}
                cout << u8"Podaj nr pliku do wczytania (0 = anuluj): ";
                int numer;
                cin >> numer;
                plik = ifstream("save" + to_string(numer) + ".csv");
                if (plik.is_open())
                    swiat = Swiat::getInstance(plik);
                swiat->rysujSwiat();
                plik.close();
                lista_plikow.close();
                continue;
            default:
                continue;
            }
        if(klawisz!=enter)
            continue;
        swiat->wykonajTure();
        swiat->rysujSwiat();
    }
    return 0;
}