#pragma once
#include <string>
#include "Kolo.h"
#include "Silnik.h"
#include "Nadwozie.h"
#include "Pojazd.h"
#include "Samochod.h"

using namespace std;

class SamochodOsobowy : public Samochod
{
public:
	/** *Konstruktory z klasy Samochod Osobowy*/
    SamochodOsobowy();
	SamochodOsobowy(string marka, string model, int ilosc_Kol); //Tylko samochod osobowy
	SamochodOsobowy(float przebieg, int miejsca, char kat, string marka, string model, int ilosc_Kol); //Samochod + Samochod osobowy
	SamochodOsobowy(float masa, string wlasciciel, int rok_produkcji, float przebieg, int miejsca, char kat, string marka, string model, int ilosc_Kol); //Wszystkie 3 naraz
	SamochodOsobowy(const SamochodOsobowy &s);
	void wypisz(); /** *Funkcja wypisuj¹ca na ekran informacje o samochodzie osobowym*/
	int podajLiczbeAut(); /** *Funkcja zwracaj¹ca informacje o obecnej liczbie samochodów osobowych w bazie*/
	SamochodOsobowy utworz(SamochodOsobowy &s); /** *Metoda pozwalaj¹ca na stworzenie kolejnego obiektu z klasy Samochodu Osobowego*/
	~SamochodOsobowy();
	/** *Operatory z klasy Samochod Osobowy*/
	bool operator==(const SamochodOsobowy &s);
	bool operator>(const SamochodOsobowy &s);
	SamochodOsobowy operator+(const SamochodOsobowy &s);
	SamochodOsobowy operator=(const SamochodOsobowy &s);
	friend ostream& operator << (ostream &s, SamochodOsobowy &samochod);
	SamochodOsobowy operator^=(const SamochodOsobowy &s);
	operator float();
//	SamochodOsobowy operator-(int ile);
	Kolo operator[] (int kolo);
	int operator() ();
	Silnik zmienSilnik(const Silnik &s);
	void zmien_Nadwozie(float dl, string kol);
	int wypiszIloscKM();
	void zapisz(string plik);
	void wczytaj(string plik, int linia);
	string typ_pojazdu();

private:
	static int liczba_Aut;

	string marka;
	string model;
	int ilosc_Kol;

	Silnik silnik;
	Nadwozie nadwozie;
	Kolo *kola;

};
