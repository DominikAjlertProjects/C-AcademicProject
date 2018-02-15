#include <cstdio>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Kolo.h"
#include "Silnik.h"
#include "Nadwozie.h"
#include "SamochodOsobowy.h"
#include "Samochod.h"
#include "Operatory.h"
#include "Pojazd.h"
#include "Pociag.h"
#include "Pomocnicze.h"
#include <vector>

using namespace std;

int main()
{
    int wybor=0, wybor1, wybor2, wybor3, wybor4;
    cout << "============== MENU PROGRAMU =======================" << endl;
	vector <Pojazd*> j;
    vector <Samochod*> v1;
    vector <SamochodOsobowy*> v2;
	vector <Pociag*> v3;
    string nazwa;
	fstream f;
	int wersy = 0, numer=0;

   do{
    switch(wybor)
    {
        case 0: cout << "1. Pojazd" << endl;
				cout << "2. Pociag" << endl;
                cout << "3. Samochod" << endl;
                cout << "4. Samochod Osobowy" << endl;
				cout << "5. Zapisz cala zawartosc programu" << endl;
                cout << "6. Zamknij program" << endl;
                cin >> wybor;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Prosze podac liczbe!" << endl;
					wybor = 0;
					break;
				}
                break;

        case 1:
					cout << "1.Wypisz pojazd" << endl;
                    cout << "2.Usun pojazd" << endl;
                    cout << "3.Wczytaj plik z bazy" << endl;
                    cout << "4.Zapisz stan programu" << endl;
                    cout << "5.Powrot" << endl;
                    cin >> wybor1;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "Prosze podac liczbe!" << endl;
						wybor1 = 0;
						break;
					}

                    switch(wybor1)
                    {

					case 1: cout << "Ktory pojazd ma zostac wypisany? " << endl;
						cin >> numer;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Prosze podac liczbe!" << endl;
							wybor1 = 1;
							break;
						}

						if (j.size() == 0)
						{
							cout << "Brak pojazdow do wyswietlenia!" << endl;
							break;
						}

						if (numer - 1 > j.size())
						{
							cout << "Vector nie posiada tylu pojazdow! Sprobuj ponownie" << endl;
							wybor1 = 1;
							break;
						}

						j[numer - 1]->wypisz();
						break;

                        case 2: cout << "Ktory pojazd usunac? " << endl;
								cin >> numer;
								getchar();

								if (j.size() == 0)
								{
									cout << "Vector pusty!" << endl;
									break;
								}

								while (numer - 1 > j.size())
								{
									cout << "Vector nie posiada tylu pojazdow! Sprobuj ponownie!" << endl;
									cin >> numer;
								}

								j[numer - 1]->wypisz();
                                break;

						case 3: cout << "Podaj nazwe pliku, z ktorego mam wczytac dane: ";
								cin >> nazwa;
								f.open(nazwa, ios::in);
								if (f.is_open() == false)
								{
									cout << "Nie odnaleziono pliku! Sprobuj ponownie!" << endl;
									wybor1 = 2;
									break;
								}

								f.close();
								Pojazd *p1;
								p1 = new Pociag;
								p1->wczytaj(nazwa, j);
								numer = j.size();
								
                                break;

                        case 4: cout << "Podaj nazwe pliku, do ktorego chcesz zapisać zawartosc: ";
							cin >> nazwa;
							getchar();

							naglowek(nazwa, 2);
							for (int i = 0; i < j.size(); i++)
								if(j[i]->typ_pojazdu() == "Pociag") j[i]->zapisz(nazwa);

							naglowek(nazwa, 0);
							for (int i = 0; i < j.size(); i++)
								if (j[i]->typ_pojazdu() == "Samochod") j[i]->zapisz(nazwa);

							naglowek(nazwa, 1);
							for (int i = 0; i < j.size(); i++)
								if (j[i]->typ_pojazdu() == "Samochod Osobowy") j[i]->zapisz(nazwa);
							break;
							cout << "Stan programu zapisano!" << endl;
                        case 5: wybor = 0;
                                break;
                    }
                    break;

		case 2: cout << "1. Stworz pociag" << endl;
				cout << "2. Wypisz pociag" << endl;
				cout << "3. Zapisz stan pociagow do pliku" << endl;
				cout << "4. Wczytaj stan pociagow z pliku" << endl;
				cout << "5. Powrot" << endl;
				cin >> wybor4;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Prosze podac liczbe!" << endl;
					wybor4 = 0;
					break;
				}

				switch (wybor4)
				{
						case 1:
							Pociag *p;
							p = new Pociag;
							p->stworz(*p);
							j.push_back(p);
							v3.push_back(p);
						break;

						case 2:
							cout << "Podaj nr pociagu, ktory chcesz wypisac (z vectora pociagow) ";
							cin >> numer;
							while (numer - 1 > v3.size())
							{
								cout << "Vector nie posiada tylu pozycji! Sprobuj ponownie" << endl;
								cin >> numer;
							}
							v3[numer - 1]->wypisz();
							break;

						case 3:
							cout << "Podaj nazwe pliku, w ktorym maja sie zapisac pociagi: ";
							cin >> nazwa;
							for (int i = 0; i < v3.size(); i++)
								v3[i]->zapisz(nazwa);
							break;

						case 4:
							cout << "Podaj nazwe pliku, ktory ma zostac wczytany: ";
							cin >> nazwa;
							f.open(nazwa, ios::in);
							if (f.is_open() == false)
							{
								cout << "Nie odnaleziono pliku! Sprobuj ponownie!" << endl;
								wybor4 = 2;
								break;
							}
							f.close();
							wersy = liczba_wierszy(nazwa);
							for (int i = 0; i < wersy; i++) {
								Pociag *w;
								w = new Pociag;
								w->wczytaj(nazwa,1);
								v3.push_back(w);
							}



						case 5: wybor = 0;
						break;
				}
				break;


        case 3: cout << "1.Stworz samochod" << endl;
                cout << "2.Usun samochod" << endl;
				cout << "3.Wypisz samochod " << endl;
                cout << "4.Wczytaj plik z bazy" << endl;
                cout << "5.Zapisz baze samochodow" << endl;
                cout << "6.Powrot" << endl;
                cin >> wybor2;
                
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Prosze podac liczbe!" << endl;
					wybor2 = 0;
					break;
				}

                switch(wybor2)
                {
                    case 1:    
						Samochod *temp;  
						temp = new Samochod;
                        temp->utworz(*temp);
						j.push_back(temp);
						v1.push_back(temp);
                            break;

                    case 2: int indeks;
                            cout << "Ktory samochod usunac? " << endl;
                            cin >> indeks;

							if (cin.fail())
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Prosze podac liczbe!" << endl;
								wybor2 = 0;
								break;
							}

							while (indeks > v1.size() - 1)
							{
								cout << "Vector nie posiada tylu pozycji! Sprobuj ponownie!" << endl;
								cin >> indeks;
							}
                            v1.erase(v1.begin() + indeks -1);
                            break;

					case 3: cout << "Ktory samochod ma zostac wypisany? (z vectora samochodow)" << endl;
							cin >> numer;

							if (cin.fail())
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Prosze podac liczbe!" << endl;
								wybor2 = 0;
								break;
							}

							while (numer > v1.size() - 1)
							{
								cout << "Vector nie posiada tylu pozycji! Sprobuj ponownie!" << endl;
								cin >> numer;
							}
							v1[numer - 1]->wypisz();

					case 4: 
							cout << "Podaj nazwe pliku, ktory ma zostac wczytany: " << endl;
							cin >> nazwa;
							f.open(nazwa, ios::in);
							if (f.is_open() == false)
							{
								cout << "Nie odnaleziono pliku! Sprobuj ponownie!" << endl;
								wybor2 = 2;
								break;
							}
							f.close();
							wersy = liczba_wierszy(nazwa);
							for (int i = 0; i < wersy; i++) {
								Samochod *t;
								t = new Samochod;
								t->wczytaj(nazwa,1);
								v1.push_back(t);
							}
                            break;

                    case 5:
                            cout << "Podaj nazwe pliku docelowego: " << endl;
                            cin >> nazwa;
							for (int i = 0; i < v1.size(); i++)
							{
								v1[i]->zapisz(nazwa);
							}
							cout << "Stan bazy zapisano pomyslnie w pliku " << nazwa << "!" << endl;
                            break;

                    case 6: wybor = 0;
                            break;
                }
                break;

        case 4: cout << "1.Stworz samochod osobowy" << endl;
                cout << "2.Usun samochod osobowy" << endl;
                cout << "3.Pokaz samochod" << endl;
				cout << "4.Zmien silnik w samochodzie" << endl;
                cout << "5.Wczytaj plik z bazy" << endl;
                cout << "6.Zapisz stan samochodow do bazy" << endl;
                cout << "7.Powrot" << endl;
                cin >> wybor3;
                
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Prosze podac liczbe!" << endl;
					wybor3 = 0;
					break;
				}

                switch(wybor3)
                {
					case 1:	
							SamochodOsobowy *temp;
                            temp = new SamochodOsobowy;
                            temp->utworz(*temp);
							j.push_back(temp);
							v2.push_back(temp);
                            break;

                    case 2: int indeks;
                            cout << "Ktory ma zostac usuniety? (z vectora samochodow osobowych" << endl;
                            cin >> indeks;

							if (cin.fail())
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Prosze podac liczbe!" << endl;
								wybor3 = 0;
								break;
							}

							while (indeks > v2.size() - 1)
							{
								cout << "Vector nie posiada tylu pozycji! Sprobuj ponownie!" << endl;
								cin >> indeks;
							}
                            v2.erase(v2.begin() + indeks - 1);
                            cout << "Usunieto!" << endl;
                            break;

					case 3: int ktory;
							cout << "Ktory samochod ma zostac pokazany? (z vectora samochodow osobowych)" << endl;
							cin >> ktory;

							if (cin.fail())
							{
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "Prosze podac liczbe!" << endl;
								wybor3 = 0;
								break;
							}

							if (v2.size() == 0)
							{
								cout << "Vector obecnie pusty!" << endl;
								wybor3 = 0;
								break;
							} 

							while (ktory - 1 > v2.size())
							{
								cout << "Vector nie posiada tylu pozycji! Sprobuj ponownie!" << endl;
								cin >> ktory;
							}
							v2[ktory - 1]->wypisz();
                            break;

					case 4: int ind;
						cout << "Podaj numer samochodu, w ktorym chcialbys zmienic silnik: ";
						cin >> ind;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Prosze podac liczbe!" << endl;
							wybor3 = 0;
							break;
						}

						while (ind - 1> v2.size())
						{
							cout << "Vector nie posiada tylu pozycji! Sprobuj ponownie!" << endl;
							cin >> ind;
						}
						Silnik *s1;
						s1 = new Silnik;
						s1->zmien();
						v2[ind - 1]->zmienSilnik(*s1);
						cout << "Silnik zmieniony poprawnie!" << endl;
						break;

					case 5: cout << "Podaj nazwe pliku, z ktorego chcesz wczytac dane: " << endl;
						cin >> nazwa;			
						f.open(nazwa, ios::in);
						if (f.is_open() == false)
						{
							cout << "Nie odnaleziono pliku! Sprobuj ponownie!" << endl;
							wybor1 = 2;
							break;
						}
						f.close();
						for (int i = 0; i < wersy; i++) {
							SamochodOsobowy *t;
							t = new SamochodOsobowy;
							t->wczytaj(nazwa,1);
							v2.push_back(t);
						}
						cout << "Plik wczytany poprawnie!" << endl;
                            break;

                    case 6: cout << "Podaj nazwe pliku docelowego: " ;
                            cin >> nazwa;
							for (int i = 0; i < v2.size(); i++)
							{
								v2[i]->zapisz(nazwa);
							}
							cout << "Stan bazy zapisano pomyslnie w pliku " << nazwa << "!" << endl;
                            break;

                    case 7: wybor = 0;
                            break;

					default: cout << "Nie rozpoznano komendy!" << endl;
                }
                break;

		case 5: 
			cout << "Podaj nazwe pliku, do ktorego chcesz zapisać zawartosc: ";
			cin >> nazwa;
			naglowek(nazwa, 0);

			for (int i = 0; i < v1.size(); i++)
			{
				v1[i]->zapisz(nazwa);
			}

			cout << endl;
			naglowek(nazwa, 1);
			for (int j = 0; j < v2.size(); j++)
			{
				v2[j]->zapisz(nazwa);
			}

			naglowek(nazwa, 2);
				for (int k = 0; k < v3.size(); k++)
				{
					v3[k]->zapisz(nazwa);
			}
			wybor = 0;
			break;

        case 6: cout << "Program zakonczony!" << endl;
                break;

        default: cout << "Nie rozpoznano polecenia!" << endl;
                 wybor = 0;
                 break;
    }
    } while (wybor!=6);

    return 0;
}
