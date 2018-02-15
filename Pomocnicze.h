#include <fstream>
#include <limits>
#include <iostream>

using namespace std;

fstream& GotoLine(fstream& file, unsigned int num); /** *Funkcja pozwalaj�ca przej�� do konkretnej linijki w zadanym pliku*/
int liczba_wierszy(string nazwa); /** *Funkcja zwracaj�ca liczb� wierszy, wyst�puj�ca w konkretnym pliku*/
void naglowek(string nazwa, int typ); /** *Funkcja "estetyczna" oddzielaj�ca od siebie typy pojazd�w podczas wypisywania ich do jednego pliku*/
