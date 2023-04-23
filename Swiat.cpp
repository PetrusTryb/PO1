#include "Swiat.h"
#include "Organizm.h"
#include "Czlowiek.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include <fstream>
#include <chrono>
#include <time.h>
#include <iomanip>
Organizm* Swiat::getOrganizm(pair<int,int> pozycja)
{
    if(pozycja.first < 0 || pozycja.first >= szerokosc || pozycja.second < 0 || pozycja.second >= wysokosc)
	    return nullptr;
    for (Organizm* o : organizmy)
    {
        if (o->getX() == pozycja.first && o->getY() == pozycja.second)
        {
			return o;
		}
	}
	return nullptr;
}

void Swiat::dodajLog(Organizm* zrodlo, string log)
{
    string nazwa = typeid(*zrodlo).name();
    nazwa = zrodlo->getIkona()+"(" + nazwa.substr(6, nazwa.length())+")";
    wpisyLogow++;
	cout << "\033[" << wysokosc+4+wpisyLogow << ";0H";
    cout << nazwa << log;
}

void Swiat::wyczyscLogi()
{
    cout << "\x1B[2J";
	wpisyLogow = 0;
}

Organizm* Swiat::getCzlowiek()
{
    return czlowiek;
}

void Swiat::zapiszStan()
{
    ofstream plik;
    string nazwa = "save" + to_string(rand()) + ".csv";
	plik.open(nazwa);
    plik << tura << ";" << szerokosc << ";" << wysokosc << endl;
    for (Organizm* o : organizmy)
    {
        if (o->getSila() > -1)
        {
			plik << o->toString() << endl;
		}
	}
	plik.close();
    time_t czas = time(NULL);
    tm czasLokalny;
    localtime_s(&czasLokalny, &czas);
    ofstream lista_plikow;
    string czasTekst = to_string(czasLokalny.tm_year+1900) + "-" + to_string(czasLokalny.tm_mon) + "-" + to_string(czasLokalny.tm_mday) + " " + to_string(czasLokalny.tm_hour) + ":" + to_string(czasLokalny.tm_min);
    lista_plikow.open("saves.csv", ios::app);
    lista_plikow << czasTekst << ";" << nazwa << endl;
    lista_plikow.close();
    dodajLog(czlowiek, "Zapisano stan gry");
}

void Swiat::dodajOrganizm(Organizm* organizm)
{
    organizmy.push_back(organizm);
}

Swiat::Swiat(int szerokosc, int wysokosc)
{
    this->szerokosc = szerokosc;
    this->wysokosc = wysokosc;
    narysowany = false;
    wpisyLogow = 0;
    tura = 0;
    czlowiek = nullptr;
}

Swiat* Swiat::instance = nullptr;

Swiat* Swiat::getInstance() {
    return instance;
}

Swiat* Swiat::getInstance(int szerokosc, int wysokosc) {
    if (instance != nullptr)
        delete instance;
    instance = new Swiat(szerokosc, wysokosc);
    return instance;
}

Swiat* Swiat::getInstance(ifstream& plik)
{
    delete instance;
    int tura, szerokosc, wysokosc;
    string linia;
    getline(plik, linia,';');
    tura = stoi(linia);
    getline(plik, linia,';');
    szerokosc = stoi(linia);
    getline(plik, linia);
    wysokosc = stoi(linia);
    instance = new Swiat(szerokosc, wysokosc);
    instance->tura = tura;
    while (getline(plik, linia, ';'))
    {
        Organizm* obj = nullptr;
        if (linia.size()<2)
            continue;
        string nazwa = linia.substr(linia.find(' ')+1, linia.length());
        getline(plik, linia, ';');
        int x = stoi(linia);
        getline(plik, linia, ';');
        int y = stoi(linia);
        getline(plik, linia, ';');
        int sila = stoi(linia);
        getline(plik, linia, ';');
        int wiek = stoi(linia);
        if (nazwa == "Czlowiek") {
            obj = new Czlowiek(x, y);
            instance->czlowiek = obj;
            getline(plik, linia, ';');
            int umiejetnosc = stoi(linia);
			((Czlowiek*)obj)->setUmiejetnosc(umiejetnosc);
        }
        else if(nazwa=="Wilk")
            obj = new Wilk(x,y);
        else if(nazwa=="Owca")
            obj = new Owca(x,y);
        else if(nazwa=="Lis")
            obj = new Lis(x,y);
        else if(nazwa=="Zolw")
            obj = new Zolw(x,y);
        else if(nazwa=="Antylopa")
            obj = new Antylopa(x,y);
        else if(nazwa=="Trawa")
            obj = new Trawa(x,y);
        else if(nazwa=="Mlecz")
            obj = new Mlecz(x,y);
        else if(nazwa=="Guarana")
            obj = new Guarana(x,y);
		else if(nazwa=="WilczeJagody")
			obj = new WilczeJagody(x,y);
		else if(nazwa=="BarszczSosnowskiego")
			obj = new BarszczSosnowskiego(x,y);
        obj->wzmocnij(sila - obj->getSila());
        obj->postarz(wiek);
	}
    return instance;
}

void Swiat::poczatkowaPopulacja() {
    czlowiek = new Czlowiek(rand() % szerokosc, rand() % wysokosc);
    new Wilk(rand() % szerokosc, rand() % wysokosc);
    new Owca(rand() % szerokosc, rand() % wysokosc);
    new Wilk(rand() % szerokosc, rand() % wysokosc);
    new Owca(rand() % szerokosc, rand() % wysokosc);
    new Lis(rand() % szerokosc, rand() % wysokosc);
    new Lis(rand() % szerokosc, rand() % wysokosc);
    new Zolw(rand() % szerokosc, rand() % wysokosc);
    new Zolw(rand() % szerokosc, rand() % wysokosc);
    new Antylopa(rand() % szerokosc, rand() % wysokosc);
    new Antylopa(rand() % szerokosc, rand() % wysokosc);
    new Trawa(rand() % szerokosc, rand() % wysokosc);
    new Mlecz(rand() % szerokosc, rand() % wysokosc);
    new Guarana(rand() % szerokosc, rand() % wysokosc);
    new WilczeJagody(rand() % szerokosc, rand() % wysokosc);
    new BarszczSosnowskiego(rand() % szerokosc, rand() % wysokosc);
}

void Swiat::wykonajTure()
{
    wyczyscLogi();
    tura++;
    organizmy.sort(Organizm::pierwszenstwo);
    for (Organizm* o : organizmy)
    {
        if (o->getSila() > -1)
            o->akcja();
        else
            break;
	}
}

void Swiat::rysujSwiat()
{
    cout << "\033[0;0H";
    for (int i = 0; i < szerokosc * 2 + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 0; i < wysokosc; i++) {
        cout << "#";
        for (int j = 0; j < szerokosc * 2; j++)
        {
            cout << " ";
        }
        cout << "#\n";
    }
    for (int i = 0; i < szerokosc * 2 + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (Organizm* o : organizmy)
    {
        if(o->getSila()>-1)
		    o->rysowanie();
    }
    cout << "\033["<<wysokosc+3<<";0H";
    cout << "TURA " << tura;
}

int Swiat::getSzerokosc()
{
    return szerokosc;
}

int Swiat::getWysokosc()
{
    return wysokosc;
}
