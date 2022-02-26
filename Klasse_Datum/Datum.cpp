#include "Datum.h"
#include <iostream>
using namespace std;

// Konstruktoren und Destruktor

CDatum::CDatum()
{
	tag = 1;
	monat = 1;
	jahr = 2000;
}

CDatum::CDatum(CDatum &datum)
{
	if (datum.jahr < 0 || datum.monat < 1 || datum.monat > 12 || datum.tag < 1 || datum.monat < 8 && datum.monat % 2 == 0 && datum.tag > 30 || datum.monat < 8 && datum.monat % 2 == 1 && datum.tag > 31 || datum.monat > 8 && datum.monat % 2 == 0 && datum.tag > 31 || datum.monat > 8 && datum.monat % 2 == 1 && datum.tag > 30) cout << "Ungültiges Datum" << endl;
	else
	{
		tag = datum.tag;
		monat = datum.monat;
		jahr = datum.jahr;
	}
}

CDatum::CDatum(int tag1, int monat1, int jahr1)
{
	if (jahr1 < 0 || monat1 < 1 || monat1 > 12 || tag1 < 1 || monat1 < 8 && monat1 % 2 == 0 && tag1 > 30 || monat1 < 8 && monat1 % 2 == 1 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 0 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 1 && tag1 > 30) cout << "Ungültiges Datum" << endl;
	else
	{
		tag = tag1;
		monat = monat1;
		jahr = jahr1;
	}
}

CDatum::CDatum(string datum)
{
	int tag1 = 0, monat1 = 0, jahr1 = 0, i = 0;
	string teilstring;
	string::size_type ende;

	while (string::npos != (ende = datum.find("."))) {
		teilstring = datum.substr(0, ende);
		switch (i)
		{
		case 0:
			tag1 = stoi(teilstring);
			cout << tag1 << endl;
			break;
		case 1:
			monat1 = stoi(teilstring);
			cout << monat1 << endl;
			break;
		}
		i++;
		datum.erase(0, ende + 1);
	}
	jahr1 = stoi(datum);

	if (jahr1 < 0 || monat1 < 1 || monat1 > 12 || tag1 < 1 || monat1 < 8 && monat1 % 2 == 0 && tag1 > 30 || monat1 < 8 && monat1 % 2 == 1 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 0 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 1 && tag1 > 30) cout << "Ungültiges Datum" << endl;
	else
	{
		tag = tag1;
		monat = monat1;
		jahr = jahr1;
	}
}

CDatum::~CDatum()
{

}

//Getter

int CDatum::getTag()
{
	return tag;
}

int CDatum::getMonat()
{
	return monat;
}

int CDatum::getJahr()
{
	return jahr;
}

void CDatum::getDatum(int &tag1, int &monat1, int &jahr1)
{
	tag1 = tag;
	monat1 = monat;
	jahr1 = jahr;
}

string CDatum::getStringDatum()
{
	return to_string(tag) + "." + to_string(monat) + "." + to_string(jahr);
}

//Setter

void CDatum::setTag(int tag1)
{
	if (monat < 8 && monat % 2 == 0 && tag1 > 30 || monat < 8 && monat % 2 == 1 && tag1 > 31 || monat > 8 && monat % 2 == 0 && tag1 > 31 || monat > 8 && monat % 2 == 1 && tag1 > 30) cout << "Ungültiges Datum" << endl;
	else tag = tag1;
}

void CDatum::setMonat(int monat1)
{
	if (monat < 1 || monat > 12) cout << "Ungültiges Datum" << endl;
	else monat = monat1;
}

void CDatum::setJahr(int jahr1)
{
	if (jahr1 < 1) cout << "Ungültiges Datum" << endl;
	else jahr = jahr1;
}

void CDatum::setStringDatum(string datum)
{
	int tag1 = 0, monat1 = 0, jahr1 = 0, i = 0;
	string teilstring;
	string::size_type ende;

	while (string::npos != (ende = datum.find("."))) {
		teilstring = datum.substr(0, ende);
		switch (i)
		{
		case 0:
			tag1 = stoi(teilstring);
			break;
		case 1:
			monat1 = stoi(teilstring);
			break;
		case 2:
			jahr1 = stoi(teilstring);
			break;
		}
		i++;
		datum.erase(0, ende + 1);
	}

	if (jahr1 < 0 || monat1 < 1 || monat1 > 12 || tag1 < 1 || monat1 < 8 && monat1 % 2 == 0 && tag1 > 30 || monat1 < 8 && monat1 % 2 == 1 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 0 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 1 && tag1 > 30) cout << "Ungültiges Datum" << endl;
	else
	{
		tag = tag1;
		monat = monat1;
		jahr = jahr1;
	}
}

void CDatum::setDatum(int tag1, int monat1, int jahr1)
{
	if (jahr1 < 0 || monat1 < 1 || monat1 > 12 || tag1 < 1 || monat1 < 8 && monat1 % 2 == 0 && tag1 > 30 || monat1 < 8 && monat1 % 2 == 1 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 0 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 1 && tag1 > 30) cout << "Ungültiges Datum" << endl;
	else
	{
		tag = tag1;
		monat = monat1;
		jahr = jahr1;
	}
}