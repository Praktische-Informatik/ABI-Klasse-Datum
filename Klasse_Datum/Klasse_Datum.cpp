#include <iostream>
#include "Datum.h"

using namespace std;

int main()
{
	
	CDatum datum("10.12.1999");

	//cout << datum.getJahr() << endl;
	cout << datum.getStringDatum() << endl;

	return 0;
}
