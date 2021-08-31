#pragma once
#include <iostream>
#include <string.h>
#include "Vehicle.h"
using namespace std;
class Motorcycle : public Vehicle
{
public:
	Motorcycle() :Vehicle() { HorsePower = 0; } ;
	Motorcycle(int Years, string Name_Manufacturer, int Km, int Price, int Horsepower) : Vehicle(Years, Name_Manufacturer, Km, Price)
	{
		this->HorsePower = Horsepower;
	}
	~Motorcycle() { cout << " Motorcycle::~Motorcycle()" << endl; }
	void PrintMotorcycle();
	int ValueDecline();
	void PrintValueDecline();
	int getYear_Of_Manufacturer() { return Year_Of_Manufacturer; };
	int getPrice() { return Price; };
private:
	int HorsePower;
};
