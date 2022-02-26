#pragma once
#include <string>
using namespace std;

class CDatum
{
private:
	int tag, monat, jahr;

public:
	// Konstruktoren und Destruktor
	CDatum();// Stadndartkonstruktor
	CDatum(CDatum&);// Kopierkonstruktor
	CDatum(int, int, int);// Parameterkonstruktor
	CDatum(string);// Parameterkonstruktor
	~CDatum();

	//Getter
	int getTag();
	int getMonat();
	int getJahr();
	void getDatum(int&, int&, int&);
	string getStringDatum();

	//Setter
	void setTag(int);
	void setMonat(int);
	void setJahr(int);
	void setStringDatum(string);
	void setDatum(int, int, int);
};

