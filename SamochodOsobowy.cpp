#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Kolo.h"
#include "Silnik.h"
#include "Nadwozie.h"
#include "Samochod.h"
#include "SamochodOsobowy.h"
#include "Pomocnicze.h"

using namespace std;

int SamochodOsobowy::liczba_Aut = 0;

//=================================================================================
//Konstruktory

SamochodOsobowy::SamochodOsobowy() : Samochod(0, "BRAK", 2000, 0, 4, 'B')
{
    marka = "Domyslna";
    model = "Domyslny";
    ilosc_Kol = 4;
    kola = new Kolo[4];
    liczba_Aut++;
    #ifdef _DEBUG
        cout << "Uruchomiono konstruktor domyslny dla Samochodu Osobowego" << endl;
    #endif // _DEBUG
}
SamochodOsobowy::SamochodOsobowy(string marka, string model, int ilosc_Kol) : Samochod(0, "Brak", 2000, 0, 0, 'X')
{
	this->marka = marka;
	this->model = model;
	this->ilosc_Kol = ilosc_Kol;
	kola = new Kolo[ilosc_Kol];
	liczba_Aut++;

#ifdef _DEBUG
	cout << "Uruchomiono konstruktor Samochodu Osobowego" << endl;
#endif
}


SamochodOsobowy::SamochodOsobowy(float przebieg, int miejsca, char kat, string marka, string model, int ilosc_Kol) : Samochod(0, "Brak", 0, przebieg, miejsca, kat)
{
	this->marka = marka;
	this->model = model;
	this->ilosc_Kol = ilosc_Kol;

	kola = new Kolo[ilosc_Kol];
	liczba_Aut++;
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor Samochodu Osobowego" << endl;
#endif
}

SamochodOsobowy::SamochodOsobowy(float masa, string wlasciciel, int rok_produkcji, float przebieg, int miejsca, char kat, string marka, string model, int ilosc_Kol) :Samochod(masa, wlasciciel, rok_produkcji, przebieg, miejsca, kat)
{
	this->marka = marka;
	this->model = model;
	this->ilosc_Kol = ilosc_Kol;

	kola = new Kolo[ilosc_Kol];
	liczba_Aut++;

#ifdef _DEBUG
	cout << "Uruchomiono konstruktor Samochodu Osobowego" << endl;
#endif
}

SamochodOsobowy::SamochodOsobowy(const SamochodOsobowy &s) : Samochod(s)
{
	marka = s.marka;
	model = s.model;
	ilosc_Kol = s.ilosc_Kol;
	silnik = s.silnik;
	nadwozie = s.nadwozie;

	kola = new Kolo[ilosc_Kol];
	for (int i = 0; i < ilosc_Kol; i++)
		kola[i] = s.kola[i];

	liczba_Aut++;
#ifdef _DEBUG
	cout << "Uruchomiono konstruktor Samochodu Osobowego" << endl;
#endif
}

//=================================================================================
//Funkcje z klasy Samochod Osobowy

Silnik SamochodOsobowy::zmienSilnik(const Silnik &s)
{
	silnik = s;
	return s;
}

int SamochodOsobowy::wypiszIloscKM()
{
	return silnik.iloscKM();
}

void SamochodOsobowy::zmien_Nadwozie(float dl, string kol)
{
	nadwozie.zmienNadwozie(dl, kol);
}

void SamochodOsobowy::wypisz()
{
	Samochod::wypisz();
	cout << "Ilosc kol: " << ilosc_Kol << endl;
	cout << "Auto marki " << marka << ", model " << model << "." << endl;
	silnik.pokazSilnik();
	nadwozie.wypiszNadwozie();

}

string SamochodOsobowy::typ_pojazdu()
{
	return "Samochod Osobowy";
}

int SamochodOsobowy::podajLiczbeAut()
{
	return liczba_Aut;
}

SamochodOsobowy SamochodOsobowy::utworz(SamochodOsobowy &s)
{
    Samochod::utworz(s);
    cout << "Podaj marke samochodu: " ;
    cin >> s.marka;
    cout << "Podaj model samochodu: " ;
    cin >> s.model;
    cout << "Podaj ilosc kol: " ;
    cin >> s.ilosc_Kol;
    return s;
}

void SamochodOsobowy::zapisz(string plik)
{
	fstream temp;
	temp.open(plik, ios::app);
	temp << *this;
	temp << endl;
	temp.close();

}

void SamochodOsobowy::wczytaj(string plik, int linia)
{
	Samochod::wczytaj(plik, linia);
	fstream f(plik, ios::in);
	f >> this->marka >> this->model >> this->ilosc_Kol;
	f.close();
}
//=================================================================================
//Operatory klasy SamochodOsobowy

bool SamochodOsobowy::operator==(const SamochodOsobowy &s)
{
	if ((silnik.pojemnosc == s.silnik.pojemnosc) &&
		(silnik.konie_Mechaniczne == s.silnik.konie_Mechaniczne) &&
		(silnik.moment_Obrotowy == s.silnik.moment_Obrotowy) &&
		(silnik.paliwo == s.silnik.paliwo)) {
		return true;
	}
	else return false;
}

bool SamochodOsobowy::operator>(const SamochodOsobowy &s)
{
	if (ilosc_Kol == s.ilosc_Kol) return true;
	else return false;
}

ostream& operator<< (ostream &s, SamochodOsobowy &samochod)
{
	s << static_cast < Samochod &>(samochod);
	s << samochod.marka << ", model " << samochod.model << endl;
	return s;
}

SamochodOsobowy SamochodOsobowy::operator=(const SamochodOsobowy &s)
{
	SamochodOsobowy temp;
	temp = s;
	temp.marka = s.marka;
	temp.model = s.model;
	temp.ilosc_Kol = s.ilosc_Kol;
	temp.silnik = s.silnik;
	temp.nadwozie = s.nadwozie;

	temp.kola = new Kolo[ilosc_Kol];
	for (int i = 0; i < temp.ilosc_Kol; i++)
		temp.kola[i] = s.kola[i];

	return temp;
}

SamochodOsobowy::operator float()
{
	float a;
	a = (float)silnik.konie_Mechaniczne * 0.735499;
	return a;
}
/*
SamochodOsobowy SamochodOsobowy::operator-(int ile)
{
	this->przebieg -= ile;
	return *this;
}
*/

Kolo SamochodOsobowy::operator[](int kolo)
{
	if (kolo > ilosc_Kol) cout << "Pojazd nie posiada tylu kol!" << endl;
	else {
		cout << kolo << " kolo ma rozmiar: " << kola[kolo].rozmiar << " cali" << endl;
		cout << "Typ opony: " << kola[kolo].typ << endl;
		cout << "Producent: " << kola[kolo].marka << endl;

		return kola[kolo];
	}
}

SamochodOsobowy SamochodOsobowy::operator+(const SamochodOsobowy &s)
{
	SamochodOsobowy temp(s);
	temp.silnik.pojemnosc = silnik.pojemnosc + s.silnik.pojemnosc;
	return temp;
}

SamochodOsobowy SamochodOsobowy::operator^=(const SamochodOsobowy &s)
{
	silnik = s.silnik;
	return *this;
}

/*
SamochodOsobowy SamochodOsobowy::operator-(int ile)
{
	przebieg = przebieg - ile;
	return *this;
}
*/
int SamochodOsobowy::operator()()
{
	cout << "Ilosc aut: " << liczba_Aut << endl;
	return liczba_Aut;
}

//=================================================================================
//Destruktor
SamochodOsobowy::~SamochodOsobowy()
{
	delete [] kola;
	--liczba_Aut;
#ifdef _DEBUG
	cout << "Usunieto jeden z Samochodow Osobowych" << endl;
#endif
}
