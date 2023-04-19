#pragma once
#include <list>
#include <algorithm>
#include "Organizm.h"
using namespace std;
class Swiat
{
private:
	list<Organizm*> organizmy;
	int szerokosc;
	int wysokosc;
	Organizm* czlowiek;
	bool narysowany;
	int wpisyLogow;
	int tura;
	void wyczyscLogi();
	Swiat(int szerokosc, int wysokosc);
	static Swiat* instance;
public:
	static Swiat* getInstance();
	static Swiat* getInstance(int szerokosc, int wysokosc);
	static Swiat* getInstance(ifstream & plik);
	void wykonajTure();
	void rysujSwiat();
	void dodajLog(Organizm* zrodlo, string log);
	int getSzerokosc();
	int getWysokosc();
	void poczatkowaPopulacja();
	Organizm* getOrganizm(pair<int,int> pozycja);
	void dodajOrganizm(Organizm* organizm);
	Organizm* getCzlowiek();
	void zapiszStan();
};

