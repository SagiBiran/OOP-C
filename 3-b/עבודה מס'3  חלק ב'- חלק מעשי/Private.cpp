#pragma once
#include <iostream>
#include <string.h>
#include "Vehicle.h"
#include "Private.h"
using namespace std;


void Private::PrintVehicle()
{
	//calling print funciton from base class to inheritance
	Car::PrintVehicle();
	cout << "Car type is: ";
	switch (Type_of_Private)
	{
	case Type_of_Private::Mini:
		cout << "Mini" << endl;
		break;
	case Type_of_Private::Family:
		cout << "Family" << endl;
		break;
	case Type_of_Private::Sport:
		cout << "Sport" << endl;
		break;
	case Type_of_Private::Luxary:
		cout << "Luxary" << endl;
		break;
	}
	cout << endl;
}
int Private::ValueDecline()
{
	int temp = Year_Of_Manufacturer, temp1 = KiloMeters_Drived, DeclinePrice = Price;
	while (temp <= 2020)
	{
		DeclinePrice -= 500;
		temp++;
	}
	while (temp1 >= 10000)
	{
		DeclinePrice -= 100;
		temp1 -= 10000;
	}
	//for (int i=0;int temp2 ;temp-=10000)
	return DeclinePrice;
};

void Private::PrintValueDecline()
{
	cout <<  ValueDecline() << endl << endl;
}