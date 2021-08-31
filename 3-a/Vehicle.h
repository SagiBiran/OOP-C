#pragma once
//typedef enum { Diesel, diesel, gasoline, Gasoline } TypeOfEngine; //declaring new type,typeofEngine 
#include <iostream>
#include <string.h>

using namespace std;

class Vehicle
{
protected:
	int Year_Of_Manufacturer;
	string Name_of_Manufacturer;
	int KiloMeters_Drived;
	int Price;

public:
	Vehicle() { Year_Of_Manufacturer = 0; KiloMeters_Drived = 0; Price = 0; Name_of_Manufacturer = "NULL"; }
	//Parameter C'tor.
	Vehicle(int Years, string Name_Manufacturer, int Km, int Price) {
		if (Years >= 2000 && Years <= 2020)
		{
			Year_Of_Manufacturer = Years;
			KiloMeters_Drived = Km;
			this->Price = Price;
			Name_of_Manufacturer = Name_Manufacturer;
		}
		else
		{
			cout << "Error: Years input not in range (2000-2020)"<<endl<<"unable to create object!" << endl << "Program Closed" << endl;;
			exit(1);
		}
	}
	~Vehicle() { cout << " Vehicle::~Vehicle()" << endl; }
	void PrintVehicle();
};