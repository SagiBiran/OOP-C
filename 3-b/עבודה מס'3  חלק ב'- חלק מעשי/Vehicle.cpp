#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(const Vehicle& other) {
	Year_Of_Manufacturer = other.Year_Of_Manufacturer;
	Name_of_Manufacturer = other.Name_of_Manufacturer;
	KiloMeters_Drived = other.KiloMeters_Drived;
	Price = other.Price;
	VehicleNumber = other.VehicleNumber;
}; //copy constructor

void Vehicle::PrintVehicle()
{
	cout << "/************ Vehicle info: ************/" << endl;
	cout << "Manufacturer Model Name: " << Name_of_Manufacturer << endl;
	cout << "Year of production: " << Year_Of_Manufacturer << endl;
	cout << "KiloMeters Drived: " << KiloMeters_Drived << endl;
	cout << "Price: " << Price << endl;
	cout << "Vehicle Number: " << VehicleNumber<< endl;
}




