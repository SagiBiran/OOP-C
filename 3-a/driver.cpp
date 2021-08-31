/******** Assignment 3, Name: Sagi Bitton
		  Id:205620859					********/

#define Manual 0
#define Automatical 1
#include <iostream>
#include <string.h>
#include "Car.h"
#include "Vehicle.h"
#include "Private.h"
#include "Commercial.h"
#include "Motorcycle.h"
using namespace std;



int main()
{
	Private p1(2017,"Mitsubishi SpaceStar", 97000,29000,TypeOfEngine::diesel,Automatical, 4, 5,Type_of_Private::Mini);
	Private p2(2010,"Kaya Forte", 42000,110000,TypeOfEngine::Diesel,Manual, 4, 5,Type_of_Private::Family);
	Commerical c1(2002,"Citroen Birlingo",200000, 1200000,TypeOfEngine::diesel,Automatical,4,5);
	Commerical c2(2020,"Renualt Kango",92000, 101000,TypeOfEngine::diesel,Automatical,4,5);
	Motorcycle m1(2000, "RZR",32000,80000,132);

	//checking that all Vehicles years manufactor is above 2016, and price is more than 2000, then print Vehicle Detailes
	if((p1.getYear_Of_Manufacturer()>2016&&p1.getPrice()>20000)||(p1.getTypeOfPrivate()==Type_of_Private::Family)) //will print exactly Private car we want.
		p1.PrintPrivate();
	if ((p2.getYear_Of_Manufacturer() > 2016 && p1.getPrice() > 20000) || (p2.getTypeOfPrivate() == Type_of_Private::Family))
		p2.PrintPrivate();
	if (c1.getYear_Of_Manufacturer() > 2016 && p1.getPrice() > 20000)
		c1.PrintCommerical();
	if (c2.getYear_Of_Manufacturer() > 2016 && p1.getPrice() > 20000)
		c2.PrintCommerical();
	if (m1.getYear_Of_Manufacturer() > 2016 && p1.getPrice() > 20000)
		m1.PrintMotorcycle();
	if (m1.getPrice()-m1.ValueDecline() >= 2000) //checking if motorcycle has decline price 2000 or more.
		m1.PrintMotorcycle();
	else
		m1.PrintValueDecline();
	if (p1 == p2) //check whether two private car are equal
	{
		cout << "System Found 2 equal Cars!";
	}
	return 0;
}