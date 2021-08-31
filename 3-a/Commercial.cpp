#pragma once
#include <iostream>
#include <string.h>
#include "Vehicle.h"
#include "Commercial.h"
using namespace std;

void Commerical::PrintCommerical()
{ //calling print funciton from base class to inheritance
	Car::PrintCar();
	cout << endl;
}
int Commerical::ValueDecline()
{
	int temp = Year_Of_Manufacturer, temp1 = KiloMeters_Drived, DeclinePrice = Price;
	while (temp <= 2020)
	{
		DeclinePrice -= 400;
		temp++;
	}
	while (temp1 >= 10000)
	{
		DeclinePrice -= 50;
		temp1 -= 10000;
	}
	return DeclinePrice;
};

void Commerical::PrintValueDecline()
{
	cout << "Decline Price for Commercial car is: " << ValueDecline() << endl << endl;
}