#pragma once
#include "Pojazd.h"
#include <vector>
using namespace std;

class Samochod: public Pojazd
{
public:
	/**
	*	Konstruktor klasy samochod: domyslny, z parametrem, kopiuj¹cy
	*/
	Samochod(float p=0, int l=0, char k='A');
	Samochod(float masa, string wlasciciel, int rok_produkcji, float przebieg, int miejsca, char kat);
	Samochod(const Samochod &samochod);
	friend ostream& operator << (ostream& s, Samochod &samochod);
	friend ostream& operator << (ostream& s, Samochod *car);
	void wczytaj(string nazwa, int linia); /** *Metoda wczytuj¹ca samochod z pliku .txt i zapisujaca nowy obiekt w bazie vectorow*/
	void wypisz();/** * Metoda wypisujaca dany samochod*/
	void zapisz(string plik); /** *Metoda sluzaca do zapisu obiektu Samochod to konkretnego pliku podanego przez uzytkownika */
	string typ_pojazdu(); /** * Metoda zwracaj¹ca informacjê o tym, ze obiekt z tej klasy jest samochodem*/
	Samochod utworz(Samochod &t); /** *Metoda pozwalaj¹ca stworzyæ nowy obiekt klasy Samochod*/
	Samochod operator=(const Samochod &t);
	~Samochod();

protected:
	float przebieg;
	int liczba_miejsc;
	char kategoria;

};
