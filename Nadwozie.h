#pragma once

using namespace std;

class Nadwozie
{
public:
	Nadwozie();
	Nadwozie(float dlugosc, string kolor);
	Nadwozie(const Nadwozie &n);
	Nadwozie operator=(const Nadwozie &n);
	void wypiszNadwozie();
	void zmienNadwozie(float dl, string kol);

private:
	float dlugosc;
	string kolor;
	friend class SamochodOsobowy;

};