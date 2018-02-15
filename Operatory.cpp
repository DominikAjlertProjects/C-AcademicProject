/*#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include "SamochodOsobowy.h"
#include "Silnik.h"
#include "Kolo.h"
#include "Nadwozie.h"
#include "Operatory.h"
#include "Samochod.h"
#ifdef _DEBUG

using namespace std;

void operatory(SamochodOsobowy &a, SamochodOsobowy &b)
{
	cout << endl;
	cout << "========================================" << endl;
	cout << "\tTest operatorow" << endl;
	cout << "========================================" << endl;
	cout << "1. Operator ==:" << endl;
	if (a == b) cout << "Silniki takie same" << endl;
	else cout << "Rozne silniki" << endl;
	cout << "========================================" << endl;
	cout << "2. Operator >:" << endl;
	if (a > b) cout << "Auto pierwsze wieksze od drugiego" << endl; //pod wzgledem ilosci kol
	else cout << "Auto drugie wieksze lub rowne pierwszemu" << endl;
	cout << "========================================" << endl;
	cout << "3. Operator <<: (Wypisanie marki i modelu SamochodOsobowyu)" << endl;
	cout << a;
	cout << "========================================" << endl;
	cout << "4. Operator =: (dla obiketu S2 i nowozadeklarowanego obiektu)" << endl;
		SamochodOsobowy S3 = b;
		S3.wypisz(); //wypisanie obiektu na ekran
		cout << endl;
		cout << "========================================" << endl;
		cout << "5. Operator konwersji (float): " << endl;
		float test = a; //zmienna pomocnicza, ktorej przypisujemy ilosc KM silnika dzieki operatorowi "float"
		cout << "Moc zapisania nominalnie: " << a.wypiszIloscKM() << " KM" << endl;
		cout << "Ta sama moc zapisana przy uzyciu konwersji: " << test << " kW" << endl;
		cout << "========================================" << endl;
		cout << "6. Operator indeksowania []: " << endl;
		b[3];
		cout << "========================================" << endl;
		cout << "7. Operator +: (dodawanie pojemnosci silnikow S1 i S2 dla nowego obiektu)" << endl;
		SamochodOsobowy temp;
		temp + b;
		temp + a;
		temp.wypisz_Auto();*/
/*
		SamochodOsobowy S1("BMW", "E40", 4);
		Silnik e7(123, "Diesel", 120, 200);
		SamochodOsobowy t("Fiat", "Multipla", 6);
		Silnik multipla(100, "LPG", 84, 176);
		t.zmienSilnik(multipla);
		S1.zmienSilnik(e7);
		t = S1 + b;
		cout << endl;
		cout << "Wyisanie S1" << endl;
		S1.wypisz();
			cout << endl;
			cout << "Wypisanie b" << endl;
			b.wypisz();
			cout << endl;
			cout << "Wypisanie nowego obiektu t z wartosciami okreslonymi w funkcji" << endl;
			t.wypisz();
			cout << endl;
			cout << "Wypisanie ponowne obiektu b, w celu sprawdzenia czy jego silnik nie ulegl zmianie" << endl;
		b.wypisz();
		cout << endl;
		cout << "Wypisanie ponowne obiektu S1, w celu sprawdzenia czy jego silnik nie ulegl zmianie" << endl;
		S1.wypisz();
		cout << endl;
		cout << "========================================" << endl;
		cout << "8. Operator ^=: (wymiana silnika z obiektu S1)" << endl;
		a^=b;
		a.wypisz();
		cout << "========================================" << endl;
		cout << "9. Operator -: (Zmniejszanie przebiegu o liczbe)" << endl;
		SamochodOsobowy a2 = a - 120;
		a2.wypisz();
		cout << "========================================" << endl;
		cout << "10. Operator (): (Podglad ilosci SamochodOsobowyow obecnie istniejacych)" << endl;
		a();
		cout << "========================================" << endl;
		cout << "\t KONIEC TESTU" << endl;


}

#endif
*/
