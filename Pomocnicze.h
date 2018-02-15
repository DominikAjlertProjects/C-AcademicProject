#include <fstream>
#include <limits>
#include <iostream>

using namespace std;

fstream& GotoLine(fstream& file, unsigned int num); /** *Funkcja pozwalaj¹ca przejœæ do konkretnej linijki w zadanym pliku*/
int liczba_wierszy(string nazwa); /** *Funkcja zwracaj¹ca liczbê wierszy, wystêpuj¹ca w konkretnym pliku*/
void naglowek(string nazwa, int typ); /** *Funkcja "estetyczna" oddzielaj¹ca od siebie typy pojazdów podczas wypisywania ich do jednego pliku*/
