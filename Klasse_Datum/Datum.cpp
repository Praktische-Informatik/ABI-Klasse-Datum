#include "Datum.h"
#include <iostream>
#include <time.h>
using namespace std;

// Konstruktoren und Destruktor

Date::Date()
{
	time_t now = time(&now);
	struct tm x;
	localtime_s(&x, &now);
	tag = x.tm_mday;
	monat = x.tm_mon + 1;
	jahr = x.tm_year + 1900;

}

Date::Date(Date& datum) : Date()
{
	if (datum.jahr < 0 || datum.monat < 1 || datum.monat > 12 || datum.tag < 1 || datum.monat < 8 && datum.monat % 2 == 0 && datum.tag > 30 || datum.monat < 8 && datum.monat % 2 == 1 && datum.tag > 31 || datum.monat > 8 && datum.monat % 2 == 0 && datum.tag > 31 || datum.monat > 8 && datum.monat % 2 == 1 && datum.tag > 30) cout << "Ungültiges Datum" << endl;
	else
	{
		tag = datum.tag;
		monat = datum.monat;
		jahr = datum.jahr;
	}
}

Date::Date(int tag1, int monat1, int jahr1) : Date()
{
	if (jahr1 < 0 || monat1 < 1 || monat1 > 12 || tag1 < 1 || monat1 < 8 && monat1 % 2 == 0 && tag1 > 30 || monat1 < 8 && monat1 % 2 == 1 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 0 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 1 && tag1 > 30) cout << "Ungültiges Datum" << endl;
	else
	{
		tag = tag1;
		monat = monat1;
		jahr = jahr1;
	}
}

Date::Date(string datum) : Date()
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
			//cout << tag1 << endl;
			break;
		case 1:
			monat1 = stoi(teilstring);
			//cout << monat1 << endl;
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

Date::~Date()
{

}

//Getter

int Date::getTag()
{
	return tag;
}

int Date::getMonat()
{
	return monat;
}

int Date::getJahr()
{
	return jahr;
}

void Date::getDatum(int& tag1, int& monat1, int& jahr1)
{
	tag1 = tag;
	monat1 = monat;
	jahr1 = jahr;
}

string Date::getStringDatum()
{
	return to_string(tag) + "." + to_string(monat) + "." + to_string(jahr);
}

string Date::toString()
{
	return getStringDatum();
}

//Setter

void Date::setTag(int tag1)
{
	if (monat < 8 && monat % 2 == 0 && tag1 > 30 || monat < 8 && monat % 2 == 1 && tag1 > 31 || monat > 8 && monat % 2 == 0 && tag1 > 31 || monat > 8 && monat % 2 == 1 && tag1 > 30) cout << "Ungültiges Datum" << endl;
	else tag = tag1;
}

void Date::setMonat(int monat1)
{
	if (monat < 1 || monat > 12) cout << "Ungültiges Datum" << endl;
	else monat = monat1;
}

void Date::setJahr(int jahr1)
{
	if (jahr1 < 1) cout << "Ungültiges Datum" << endl;
	else jahr = jahr1;
}

void Date::setStringDatum(string datum)
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

void Date::setDatum(int tag1, int monat1, int jahr1)
{
	if (jahr1 < 0 || monat1 < 1 || monat1 > 12 || tag1 < 1 || monat1 < 8 && monat1 % 2 == 0 && tag1 > 30 || monat1 < 8 && monat1 % 2 == 1 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 0 && tag1 > 31 || monat1 > 8 && monat1 % 2 == 1 && tag1 > 30) cout << "Ungültiges Datum" << endl;
	else
	{
		tag = tag1;
		monat = monat1;
		jahr = jahr1;
	}
}


//Positiver, als auch negativer Bereich möglich
Date* Date::addDays(int days)
{
	struct tm x;
	time_t now = time(&now);
	localtime_s(&x, &now);
	x.tm_year = jahr - 1900;
	x.tm_mon = monat - 1;
	x.tm_mday = tag;
	now = mktime(&x);
	now += days * 24 * 60 * 60;
	localtime_s(&x, &now);


	Date* ret = new Date(x.tm_mday, x.tm_mon + 1, x.tm_year + 1900);
	return ret;
}

bool Date::isBefore(Date* d)
{
	if (d->jahr > jahr)
		return true;
	else if (d->jahr == jahr)
		if (d->monat > monat)
			return true;
		else if (d->monat == monat)
			if (d->tag > tag)
				return true;
	return false;
}

bool Date::isAfter(Date* d)
{
	if (d->jahr < jahr)
		return true;
	else if (d->jahr == jahr)
		if (d->monat < monat)
			return true;
		else if (d->monat == monat)
			if (d->tag < tag)
				return true;
	return false;
}

/// <summary>
/// Funktion gibt an, ob ein Datum zwischen den beiden Daten liegt
/// </summary>
/// <param name="first">: Erstes Datum</param>
/// <param name="second">: Zweites Datum</param>
/// <returns>true: Datum liegt dazwischen
/// <para>false: Datum ist identisch mit einen der Daten oder liegt nicht dazwischen</para></returns>
bool Date::isBetween(Date* first, Date* second)
{

	if ((isBefore(second) && isAfter(first)) || (isBefore(first) && isAfter(second)))
		return true;
	return false;
}


