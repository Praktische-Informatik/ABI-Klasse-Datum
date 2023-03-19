#pragma once
#include <string>

#define CDatum Date

using namespace std;

class Date
{
private:
	int tag, monat, jahr;

public:
	// Konstruktoren und Destruktor
	Date();// Stadndartkonstruktor
	Date(Date&);// Kopierkonstruktor
	Date(int, int, int);// Parameterkonstruktor
	Date(string);// Parameterkonstruktor
	~Date();

	//Getter
	int getTag();
	int getMonat();
	int getJahr();
	void getDatum(int&, int&, int&);
	string getStringDatum();
	string toString();

	//Setter
	void setTag(int);
	void setMonat(int);
	void setJahr(int);
	void setStringDatum(string);
	void setDatum(int, int, int);

	Date* addDays(int days);
	bool isBefore(Date* d);
	bool isAfter(Date* d);
	bool isBetween(Date* first, Date* second);

};

