#pragma once
#include <iostream>
#include <string.h>
#include "Vehicle.h"
#include "Commercial.h"
using namespace std;


void Commerical::PrintVehicle()
{
	Car::PrintVehicle();
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
	cout << ValueDecline() << endl << endl;
}