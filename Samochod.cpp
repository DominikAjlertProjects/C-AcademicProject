#include "Samochod.h"
#include "Pomocnicze.h"

Samochod::Samochod(float p, int l, char k) :Pojazd(0, "BRAK", 2000)
{
	przebieg = p;
	liczba_miejsc = l;
	kategoria = k;
}

Samochod::Samochod(float masa, string wlasciciel, int rok_produkcji, float przebieg, int miejsca, char kat) : Pojazd(masa, wlasciciel, rok_produkcji)
{
	this->przebieg = przebieg;
	liczba_miejsc = miejsca;
	kategoria = kat;
}

Samochod::Samochod(const Samochod &samochod) :Pojazd(samochod)
{
	przebieg = samochod.przebieg;
	liczba_miejsc = samochod.liczba_miejsc;
	kategoria = samochod.kategoria;
}

void Samochod::wypisz()
{
	Pojazd::wypisz();
	cout << "Przebieg: " << przebieg << endl;
	cout << "Liczba miejsc: " << liczba_miejsc << endl;
	cout << "Kategoria: " << kategoria << endl;
}

string Samochod::typ_pojazdu()
{
	return "Samochod";
}

ostream& operator << (ostream& s, Samochod &samochod)
{
	s << "Wlasciciel: " << samochod.wlasciciel << ", rok produkcji: " << samochod.rok_produkcji << ", masa: " << samochod.masa << endl;
	s << "Przebieg: " << samochod.przebieg << ", liczba miejsc: " << samochod.liczba_miejsc << ", kategoria: " << samochod.kategoria << endl;
	return s;
}

ostream& operator << (ostream& s, Samochod *car)
{
    s << "Wlasciciel: " << car->wlasciciel << ", rok produkcji: " << car->rok_produkcji << ", masa: " << car->masa << endl;
	s << "Przebieg: " << car->przebieg << ", liczba miejsc: " << car->liczba_miejsc << ", kategoria: " << car->kategoria << endl;
	return s;
}

void Samochod::wczytaj(string nazwa, int linia)
{
	fstream f;
	f.open(nazwa, ios::in);
	GotoLine(f, linia);
	f >> this->wlasciciel >> this->rok_produkcji >> this->masa >> this->przebieg >> this->liczba_miejsc >> this->kategoria;
	f.close();
}

void Samochod::zapisz(string plik)
{
	fstream temp;
	temp.open(plik, ios::app);
	Pojazd::zapisz(plik);
	temp << "Przebieg samochodu: " << this->przebieg << ", liczba miejsc: " << this->liczba_miejsc << ", kategoria: " << this->kategoria << endl;
	temp.close();
}

Samochod Samochod::utworz(Samochod &t)
{
	cout << "Podaj nazwisko wlasciciela: " << endl;
	cin >> t.wlasciciel;
	cout << "Podaj rok produkcji samochodu: " << endl;
	cin >> t.rok_produkcji;
	cout << "Podaj liczbe miejsc: " << endl;
	cin >> t.liczba_miejsc;
	cout << "Podaj mase samochodu: " << endl;
	cin >> t.masa;
	cout << "Podaj przebieg auta: " << endl;
	cin >> t.przebieg;
	cout << "Podaj kategorie pojazdu: " << endl;
	cin >> t.kategoria;
	return t;
}

Samochod Samochod::operator=(const Samochod &s)
{
	Samochod temp;
	temp.kategoria = s.kategoria;
	temp.liczba_miejsc = s.liczba_miejsc;
	temp.masa = s.masa;
	temp.przebieg = s.przebieg;
	temp.rok_produkcji = s.rok_produkcji;
	temp.wlasciciel = s.wlasciciel;
	return temp;
}

Samochod::~Samochod()
{
    #ifdef _DEBUG
    cout << "Wywolano destruktor samochodu!" << endl;
    #endif // _DEBUG
}

