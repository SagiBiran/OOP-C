#include <iostream>
#include "Vehicle.h"
using namespace std;

void Vehicle::PrintVehicle()
{
	cout << "/************ Vehicle info: ************/" << endl;
	cout << "Manufacturer Model Name: " << Name_of_Manufacturer << endl;
	cout << "Year of production: " << Year_Of_Manufacturer << endl;
	cout << "KiloMeters Drived: " << KiloMeters_Drived << endl;
	cout << "Price: " << Price << endl;
}



/*int Year_Of_Manufacturer;
	int KiloMeters_Drived;
	int Price;
	string Name_of_Manufacturer;*/