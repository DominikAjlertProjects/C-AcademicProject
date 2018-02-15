#include "Pojazd.h"
#include "Pociag.h"
#include "Samochod.h"
#include "SamochodOsobowy.h"
#include "Pomocnicze.h"

Pojazd::Pojazd()
{
	masa = 0;
	wlasciciel = "Brak";
	rok_produkcji = 2000;
}
Pojazd::Pojazd(const Pojazd &pojazd)
{
	masa = pojazd.masa;
	wlasciciel = pojazd.wlasciciel;
	rok_produkcji = pojazd.rok_produkcji;
}

Pojazd::Pojazd(float m, string w, int rok=2000)
{
	masa = m;
	wlasciciel = w;
	rok_produkcji = rok;
}

void Pojazd::wypisz()
{
	cout << "Wlasciciel pojazdu: " << wlasciciel << ", rok produkcji: " << rok_produkcji << ", masa: " << masa << endl;
}

void Pojazd::wczytaj(string plik, vector <Pojazd*> &p)
{
	fstream f;
	f.open(plik, ios::in);
	int temp = 0, x = 0, t=0;
	int pociagi = 0, samochody = 0, samochodyOsobowe = 0;
	string z;
	while (!f.eof()) { getline(f, z); ++x; }
	f.close();
	f.open(plik, ios::in);
	for(int k=0; k<x; k++) 
	{
		getline(f, z);
		for (int i = 0; i<z.length(); i++)
		{
			if (z[i] == ' ' && z[i] != '\0') { ++temp; }
		}

			if (temp > 6)
			{
				SamochodOsobowy *S;
				S = new SamochodOsobowy;
				S->wczytaj(plik, k+1);
				p.push_back(S);
				++samochodyOsobowe;
				temp = 0;
			}
			else
			{
				temp = 0;
				for (int i = 0; temp != 5; i++)
				{
					if (z[i] == ' ') { ++temp; }
					t = i;
				}
				char y = z[t + 1];

				if (y>=48 && y<=57) {
					Pociag *p1;
					p1 = new Pociag;
					p1->wczytaj(plik,k+1);
					p.push_back(p1);
					++pociagi;
					temp = 0;
				}
				else {
					Samochod *S1;
					S1 = new Samochod;
					S1->wczytaj(plik, k+1);
					p.push_back(S1);
					++samochody;
					temp = 0;
				}
			}
		}
	f.close();
	cout << "Wczytano " << pociagi << " pociagi, " << samochody << " samochody oraz " << samochodyOsobowe << " samochody osobowe!" << endl;

}

void Pojazd::zapisz(string plik)
{
	fstream f;
	f.open(plik, ios::app);
	f << "Wlasciciel: " << this->wlasciciel << ", masa: " << this->masa << ", rok produkcji: " << this->masa << endl;
	f.close();
} 



