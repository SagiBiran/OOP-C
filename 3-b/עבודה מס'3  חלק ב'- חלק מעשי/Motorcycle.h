#pragma once
#include <iostream>
#include <string.h>
#include "Vehicle.h"
using namespace std;
class Motorcycle : public Vehicle
{
public:
	Motorcycle() :Vehicle() { HorsePower = 0; };
	Motorcycle(int Years, string Name_Manufacturer, int Km, int Price, int VehicleNumber, int Horsepower) : Vehicle(Years, Name_Manufacturer, Km, Price, VehicleNumber)
	{
		this->HorsePower = Horsepower;
	}
	Motorcycle(const Motorcycle& other) :Vehicle(other) { HorsePower = other.HorsePower; };//CopyConstructor
	~Motorcycle() {/* cout << " Motorcycle::~Motorcycle()" << endl;*/ }
	void PrintVehicle();
	int ValueDecline();
	void PrintValueDecline();
	int getYear_Of_Manufacturer() { return Year_Of_Manufacturer; };
	int getPrice() { return Price; };
private:
	int HorsePower;
};
