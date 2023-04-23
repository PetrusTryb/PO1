#pragma once
#include <string>
#include <iostream>
#define USE_EMOJI 1
using namespace std;
class Swiat;
class Organizm
{
	int sila;
	int inicjatywa;
	int wiek;
	string ikona;
	pair<int, int> pozycja;
	pair<int,int> poprzedniaPozycja;
protected:
	Swiat* swiat;
	const int ruchy[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
public:
	Organizm(string ikona, int sila, int inicjatywa, int x, int y);
	Organizm(const Organizm& a);
	virtual void akcja()=0;
	virtual void kolizja(Organizm* inny)=0;
	virtual Organizm* dziecko()=0;
	virtual bool czyUcieczka();
	virtual string toString();
	void rysowanie();
	int getSila();
	int getInicjatywa();
	int getWiek();
	string getIkona();
	void zabij();
	void wzmocnij(int wartosc);
	void postarz(int wartosc=1);
	int getX();
	int getY();
	bool setPozycja(pair<int, int> pozycja, bool musiBycPuste);
	void cofnijRuch();
	static int pierwszenstwo(Organizm* a, Organizm* b);
};

