#pragma once
#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Pojazd
{
public:
	/**
	*Konsktruktory dla klasy g³ównej Pojazd
	*/
	Pojazd();
	Pojazd(const Pojazd &pojazd);
	Pojazd(float m, string w, int rok);
	virtual void wypisz(); /** *Metoda wypisujaca informacje o pojezdzie na ekran*/
	virtual void zapisz(string plik); /** *Metoda pozwalaj¹ca zapisaæ parametry pojazdu do pliku .txt. */
	void wczytaj(string plik, vector <Pojazd*> &p); /** *Metoda pozwalajaca wczytaæ z konkretnego pliku .txt pojazdy róznych typow i zapisanie ich od razu w podanym do niej vectorze*/
	virtual string typ_pojazdu() = 0; /** *Metoda abstrakcyjna zwracaj¹ca informacjê o tym, czym dok³adnie jest dany podobiekt, który dziedziczy z klasy Pojazd*/
	

protected:
	float masa;
	string wlasciciel;
	int rok_produkcji;
};
