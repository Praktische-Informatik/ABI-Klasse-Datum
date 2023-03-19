#include <iostream>
#include "Datum.h"

using namespace std;

int main()
{
	
	Date datum;
	Date datum1("10.12.1999");
	Date datum2(25,11,2022);
	Date datum3(datum2);
	

	//cout << datum.getJahr() << endl;
	cout << "Daten: " << endl;
	cout << datum.getStringDatum() << endl;
	cout << datum1.getStringDatum() << endl;
	cout << datum2.getStringDatum() << endl;
	cout << datum3.getStringDatum() << endl;

	cout << "Funtionen: " << endl;
	cout << "(true false true true): " << datum1.isBefore(&datum2) << "  " << datum1.isAfter(&datum2) << "    " << datum2.isBetween(&datum, &datum1) << "   " << datum2.isBetween(&datum, &datum1) << endl;

	cout << "Now: " << datum.toString() << endl;
	cout << "+10 Days: " << datum.addDays(10)->toString() << endl;
	cout << "Between: " << datum3.isBetween(datum2.addDays(-1), datum3.addDays(1));
	return 0;
}
