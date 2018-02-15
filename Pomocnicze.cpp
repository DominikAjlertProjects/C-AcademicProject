#include "Pomocnicze.h"
#include <fstream>
#include <cstdlib>
#include <string>

fstream& GotoLine(fstream& file, unsigned int num) {
	file.seekg(ios::beg);
	for (int i = 0; i < num - 1; ++i) {
		file.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return file;
}

int liczba_wierszy(string nazwa)
{
	int wiersze = 0;
	string temp;
	fstream f(nazwa, ios::in);
	while (getline(f, temp)) ++wiersze;
	return wiersze;
}

void naglowek(string nazwa, int typ)
{
	fstream temp(nazwa, ios::app);
	if (typ == 0)
	{
		temp << "========================================================" << endl;
		temp << "\t\tKolekcja samochodow" << endl;
		temp << "========================================================" << endl;
	}

	else if (typ == 1)
	{
		temp << "========================================================" << endl;
		temp << "\t\tKolekcja samochodow osobowych" << endl;
		temp << "========================================================" << endl;
	}

	else if (typ == 2)
	{
		temp << "========================================================" << endl;
		temp << "\t\tKolekcja pociagow" << endl;
		temp << "========================================================" << endl;
	}
	temp.close();
}