#pragma once
#include "Pociag.h"
#include "Pojazd.h"

class Pociag : public Pojazd
{
public:
	/** *Konstruktory z klasy Pociag*/
	Pociag(float masa=0, string wlasciciel="BRAK", int rok=2000, int wagony=1, string miasto="Rzym", bool aktiv=0);
	Pociag(int wagony, string miasto, bool aktiv);
	Pociag(const Pociag &p);
	void wypisz(); /** *Metoda wypisuj¹ca na ekran informacje o poci¹gu*/
	friend ostream& operator << (ostream &s, Pociag &pociag); /** *Operator strumieniowy wypisuj¹cy obiekt klasy Poci¹g*/
	void zapisz(string nazwa); /** *Metoda pozwalaj¹ca na zapisanie obiektu w konrketnym pliku .txt*/
	Pociag stworz(Pociag &p); /** *Metoda pozwalaj¹ca na stworzenie nowego poci¹gu*/
	void wczytaj(string plik, int linia); /** *Metoda wczytuj¹ca obiekt klasy Pociag z pliku tekstowego oraz numer linii, od ktorej ma zaczc czytanie pliku*/
	string typ_pojazdu(); /** *Metoda, ktora zwraca informacje o tym, ze obiekt z tej klasy jest Pociagiem*/

private:
	int liczba_wagonow;
	string miasto_macierzyste;
	bool czyAktywny;
};