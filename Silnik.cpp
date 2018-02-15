#include <cstdlib>
#include <iostream>
#include "Silnik.h"
#include <cstdio>
#include <string>

//=================================================================================
//Konstruktory

Silnik::Silnik()
{
	pojemnosc = 0;
	paliwo = "BRAK";
	moment_Obrotowy = 0;
	konie_Mechaniczne = 0;

#ifdef _DEBUG
	cout << "Uruchomiono konstruktor Silnika" << endl;
#endif
}

Silnik::Silnik(float pojemnosc, string paliwo, int moment_Obrotowy, int konie_Mechaniczne)
{
	this->pojemnosc = pojemnosc;
	this->paliwo = paliwo;
	this->moment_Obrotowy = moment_Obrotowy;
	this->konie_Mechaniczne = konie_Mechaniczne;

#ifdef _DEBUG
	cout << "Uruchomiono konstruktor Silnika" << endl;
#endif
}

Silnik::Silnik(const Silnik &s)
{
	pojemnosc = s.pojemnosc;
	paliwo = s.paliwo;
	moment_Obrotowy = s.moment_Obrotowy;
	konie_Mechaniczne = s.konie_Mechaniczne;
}

//==================================================================================================
//Funkcje z klasy Silnik


void Silnik::pokazSilnik()
{
	cout << "Pojemnosc: " << pojemnosc << " cm3" << endl;
	cout << "Rodzaj paliwa: " << paliwo << endl;
	cout << "Moment obrotowy na poziomie: " << moment_Obrotowy << " nm" << endl;
	cout << "Moc: " << konie_Mechaniczne << " KM" << endl;
}

int Silnik::iloscKM()
{
	return konie_Mechaniczne;
}

void Silnik::zmien()
{
	cout << "Podaj nowa pojemnosc: ";
	cin >> pojemnosc;
	cout << "Rodzaj paliwa: ";
	cin >> paliwo;
	cout << "Podaj moment obrotowy: ";
	cin >> moment_Obrotowy;
	cout << "Podaj liczbe koni mechanicznych: ";
	cin >> konie_Mechaniczne;
}

//==================================================================================================
//Operatory klasy Silnik

Silnik Silnik::operator=(const Silnik &s)
{
	pojemnosc = s.pojemnosc;
	paliwo = s.paliwo;
	moment_Obrotowy = s.moment_Obrotowy;
	konie_Mechaniczne = s.konie_Mechaniczne;
	return *this;
}

Silnik Silnik::operator+(const Silnik &s)
{
	pojemnosc += s.pojemnosc;
	return *this;
}
