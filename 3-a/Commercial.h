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
	Commerical(int Years, string Name_Manufacturer, int Km, int Price, TypeOfEngine type, bool Auto, int numberOFdoors, int numberOFseats) :Car(Years, Name_Manufacturer, Km, Price, type, Auto, numberOFdoors, numberOFseats) {};
	~Commerical() { cout << " Commerical::~Commerical()" << endl; }
	void PrintCommerical();
	int ValueDecline();
	void PrintValueDecline();
	int getYear_Of_Manufacturer() { return Year_Of_Manufacturer; };
	int getPrice() { return Price; };
private:

};
