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
	int VehicleNumber;

public:
	Vehicle() { Year_Of_Manufacturer = 0; KiloMeters_Drived = 0; Price = 0; Name_of_Manufacturer = "NULL", VehicleNumber = 0; }
	//Parameter C'tor.
	Vehicle(int Years, string Name_Manufacturer, int Km, int Price, int VehicleNumber) {
		if (Years >= 2000 && Years <= 2020)
		{
			Year_Of_Manufacturer = Years;
			KiloMeters_Drived = Km;
			this->Price = Price;
			Name_of_Manufacturer = Name_Manufacturer;
		}
		else
		{
			cout << "Error: Years input not in range (2000-2020)" << endl << "unable to create object!" << endl << "Program Closed" << endl;;
		}
		if (VehicleNumber >= 10000 && VehicleNumber <= 99999)
			this->VehicleNumber = VehicleNumber;
		else
			cout << "Error: user input is wrong! Vehicle number should contain 5 positive numebrs" << endl << "unable to create object!" << endl << "Program Closed" << endl;;

	}
	Vehicle(const Vehicle& other); //copy constructor
	virtual ~Vehicle() { /*cout << " Vehicle::~Vehicle()" << endl;*/ } //very inportant virtual d'tor!
	virtual void PrintVehicle();
	virtual int GetVehicleNumber() { return VehicleNumber; }
	//virtual int ValueDecline() {} ;
	virtual void PrintValueDecline() {};
	virtual int ValueDecline() { return 0; };
};