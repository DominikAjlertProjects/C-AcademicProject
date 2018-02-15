#include "Pociag.h"
#include "Pojazd.h"
#include "Pomocnicze.h"

Pociag::Pociag(float masa, string wlasciciel, int rok, int wagony, string miasto, bool aktiv) :Pojazd(masa, wlasciciel, rok)
{
	liczba_wagonow = wagony;
	miasto_macierzyste = miasto;
	czyAktywny = aktiv;
}

Pociag::Pociag(int wagony, string miasto, bool aktiv) : Pojazd(0, "BRAK", 2000)
{
	liczba_wagonow = wagony;
	miasto_macierzyste = miasto;
	czyAktywny = aktiv;
}

Pociag::Pociag(const Pociag &p) : Pojazd(p)
{
	liczba_wagonow = p.liczba_wagonow;
	miasto_macierzyste = p.miasto_macierzyste;
	czyAktywny = p.czyAktywny;
}

ostream& operator<<(ostream& s, Pociag &p)
{
	s << "Wlasciciel: " << p.wlasciciel << ", rok produkcji: " << p.rok_produkcji << ", masa: " << p.masa << endl;
	s << "Liczba wagonow: " << p.liczba_wagonow << ", miasto macierzyste: " << p.miasto_macierzyste << ", aktywnosc(0 lub 1): " << p.czyAktywny << endl;
	return s;
}

void Pociag::wypisz()
{
	Pojazd::wypisz();
	cout << "Liczba wagonow: " << liczba_wagonow << endl;
	cout << "Miasto macierzyste: " << miasto_macierzyste << endl;
	if (czyAktywny) cout << "Pociag aktywny" << endl;
	else cout << "Pociag nieaktywny" << endl;
}

void Pociag::zapisz(string nazwa)
{
	fstream temp(nazwa, ios::app);
	temp << *this;
	temp << endl;
	temp.close();
}

void Pociag::wczytaj(string nazwa, int linia)
{
		fstream f;
		f.open(nazwa, ios::in);
		GotoLine(f, linia);
		f >> this->wlasciciel >> this->rok_produkcji >> this->masa >> this->liczba_wagonow >> this->miasto_macierzyste >> this->czyAktywny;
		f.close();

}

string Pociag::typ_pojazdu()
{
	return "Pociag";
}

Pociag Pociag::stworz(Pociag &p)
{
	cout << "Podaj wlasciciela: ";
	cin >> p.wlasciciel;
	cout << "Podaj rok produkcji pociagu: ";
	cin >> p.rok_produkcji;
	cout << "Podaj mase pociagu: ";
	cin >> p.masa;
	cout << "Podaj liczbe wagonow: ";
	cin >> p.liczba_wagonow;
	cout << "Podaj miasto macierzyste pociagu: ";
	cin >> p.miasto_macierzyste;
	cout << "Czy pociag jest aktywny? (0 lub 1): ";
	cin >> p.czyAktywny;
	return p;
}