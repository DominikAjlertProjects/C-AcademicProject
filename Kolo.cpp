#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Kolo.h"
#include "Silnik.h"
#include "SamochodOsobowy.h"

using namespace std;

//=================================================================================
//Kontruktory

Kolo::Kolo()
{
	rozmiar = 17;
	typ = "Zimowe";
	marka = "Michelin";

#ifdef _DEBUG
	cout << "Uruchiomiono konstruktor Kola" << endl;
#endif
}

Kolo::Kolo(int rozmiar, string typ, string marka)
{
	this->rozmiar = rozmiar;
	this->typ = typ;
	this->marka = marka;

#ifdef _DEBUG
	cout << "Uruchiomiono konstruktor Kola" << endl;
#endif
}

Kolo::Kolo(const Kolo &k)
{
	rozmiar = k.rozmiar;
	typ = k.typ;
	marka = k.marka;
}

//=================================================================================
//Operator klasy Kolo

Kolo Kolo::operator=(const Kolo &k)
{
	rozmiar = k.rozmiar;
	typ = k.typ;
	marka = k.marka;
	return *this;
}
