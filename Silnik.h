#pragma once
using namespace std;

class Silnik
{
public:
	/** *Konsktruktory z klasy Silnik*/
	Silnik();
	Silnik(float pojemnosc, string paliwo, int moment_obrotowy, int konie_Mechaniczne);
	Silnik(const Silnik &s);
	Silnik operator=(const Silnik &s);
	Silnik operator+(const Silnik &s);

	void pokazSilnik(); /** *Funkcja wypisuj�ca na ekran informacje o silniku*/
	int iloscKM(); /** *Metoda zwracaj�ca ilo�� koni danego silnika*/
	void zmien(); /** *Metoda pozwalaj�ca na zamian� jednego silnika z drugim*/

private:
	float pojemnosc;
	string paliwo;
	int moment_Obrotowy;
	int konie_Mechaniczne;

	friend class SamochodOsobowy;
};