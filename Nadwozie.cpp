#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include "SamochodOsobowy.h"
#include "Nadwozie.h"

using namespace std;

//Konstruktory
//==================================================================================================
Nadwozie::Nadwozie()
{
	kolor = "Czarny";
	dlugosc = 4.00;

#ifdef _DEBUG
	cout << "Uruchomiono kostruktor Nadwozia" << endl;
#endif
}

Nadwozie::Nadwozie(float dlugosc, string kolor)
{
	this->dlugosc = dlugosc;
	this->kolor = kolor;

#ifdef _DEBUG
	cout << "Uruchomiono kostruktor Nadwozia" << endl;
#endif
}

Nadwozie::Nadwozie(const Nadwozie &n)
{
	dlugosc = n.dlugosc;
	kolor = n.kolor;
}

//Operator klasy Nadwozie
//==================================================================================================
Nadwozie Nadwozie::operator=(const Nadwozie &n)
{
	kolor = n.kolor;
	dlugosc = n.dlugosc;
	return *this;
}

//Funkcje klasy Nadwozie
//==================================================================================================
void Nadwozie::zmienNadwozie(float dl, string kol)
{
	dlugosc = dl;
	kolor = kol;
}

void Nadwozie::wypiszNadwozie()
{
	cout << "Dlugosc nadwozia: " << dlugosc << " m" << endl;
	cout << "Kolor: " << kolor << endl;
}