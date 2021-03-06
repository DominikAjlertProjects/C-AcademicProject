#include <fstream>
#include <limits>
#include <iostream>

using namespace std;

fstream& GotoLine(fstream& file, unsigned int num); /** *Funkcja pozwalająca przejść do konkretnej linijki w zadanym pliku*/
int liczba_wierszy(string nazwa); /** *Funkcja zwracająca liczbę wierszy, występująca w konkretnym pliku*/
void naglowek(string nazwa, int typ); /** *Funkcja "estetyczna" oddzielająca od siebie typy pojazdów podczas wypisywania ich do jednego pliku*/
