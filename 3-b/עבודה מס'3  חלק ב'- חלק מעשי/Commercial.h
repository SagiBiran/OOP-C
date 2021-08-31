#pragma once
#include <iostream>
#include <string.h>
#include "Vehicle.h"
#include "Car.h"
using namespace std;
class Commerical : public Car
{
public:
	Commerical() {};
	Commerical(int Years, string Name_Manufacturer, int Km, int Price, int VehicleNumber,TypeOfEngine type, bool Auto, int numberOFdoors, int numberOFseats) :Car(Years, Name_Manufacturer, Km, Price, VehicleNumber, type, Auto, numberOFdoors, numberOFseats) {};
	Commerical(const Commerical& other) : Car(other){};//copy Constructor must all intialize all members function inside h!! 
	~Commerical() { /*cout << " Commerical::~Commerical()" << endl;*/ }
	void PrintVehicle();
	int ValueDecline();
	void PrintValueDecline();
	int getYear_Of_Manufacturer() { return Year_Of_Manufacturer; };
	int getPrice() { return Price; };
private:

};
