#pragma once
enum class Type_of_Private { Mini, Family, Sport, Luxary};
#include <iostream>
#include <string.h>
#include "Vehicle.h"
#include "Car.h"
using namespace std;
class Private : public Car
{
public:
	Private() { }
	Private(int Years, string Name_Manufacturer, int Km, int Price, TypeOfEngine type, bool Auto, int numberOFdoors, int numberOFseats, Type_of_Private Type_of_PrivateCar):Car(Years,Name_Manufacturer,Km,Price,type,Auto,numberOFdoors,numberOFseats)
	{ 
		Type_of_Private = Type_of_PrivateCar;
	}
	~Private() { cout << " Private::~Private()" << endl; }		
	int getYear_Of_Manufacturer() { return Year_Of_Manufacturer; };
	int getPrice() { return Price; };
	Type_of_Private getTypeOfPrivate() { return Type_of_Private; };
	int ValueDecline(); //function that calculate decline price for private car.
	void PrintPrivate();
	void PrintValueDecline();
private:
	Type_of_Private Type_of_Private;
};
