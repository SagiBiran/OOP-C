#pragma once
#include <iostream>
#include <string.h>
#include "Vehicle.h"
#include "Motorcycle.h"
using namespace std;

void  Motorcycle::PrintMotorcycle()
{
	Vehicle::PrintVehicle();
	cout << "HorsePower is: " << HorsePower << endl << endl;

}

int Motorcycle::ValueDecline()
{
	int temp = Year_Of_Manufacturer, temp1 = KiloMeters_Drived, DeclinePrice = Price;
	while (temp <= 2020)
	{
		DeclinePrice -= 200;
		temp++;
	}
	while (temp1 >= 10000)
	{
		DeclinePrice -= 30;
		temp1 -= 10000;
	}
	return DeclinePrice;
};

void Motorcycle::PrintValueDecline()
{
	cout << "Decline Price for Motorcycle is: " << ValueDecline() << endl;
}