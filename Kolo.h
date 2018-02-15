#pragma once
using namespace std;

class Kolo
{
public:
	Kolo();
	Kolo(int rozmiar, string typ, string marka);
	Kolo(const Kolo &k);

private:
	friend class SamochodOsobowy;
	int rozmiar;
	string typ;
	string marka;
	Kolo operator=(const Kolo &k);
};