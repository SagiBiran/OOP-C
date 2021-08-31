#pragma once
enum class TypeOfEngine { Diesel, diesel, gasoline, Gasoline };



#include <iostream>
#include <string.h>
#include "Vehicle.h"


using namespace std;


class Car : public Vehicle {
private:
	TypeOfEngine Type_Of_Engine;
	bool Automatic;
	int Number_Of_Doors;
	int number_Of_Seats;
protected:

public:
	//Parameter C'tor
	Car() :Vehicle() { Type_Of_Engine = TypeOfEngine::Diesel; Automatic = 0; Number_Of_Doors = 0; number_Of_Seats = 0; };
	Car(const Car& other) : Vehicle(other) //copy Constructor must all intialize all members function inside h!! 
	{
		Type_Of_Engine = other.Type_Of_Engine;
		Automatic = other.Automatic;
		Number_Of_Doors = other.Number_Of_Doors;
		number_Of_Seats = other.number_Of_Seats;
	};
	Car(int Years, string Name_Manufacturer, int Km, int Price, int VehicleNumber, TypeOfEngine type, bool Auto, int numberOFdoors, int numberOFseats) :Vehicle(Years, Name_Manufacturer, Km, Price, VehicleNumber)
	{
		Type_Of_Engine = type;
		Automatic = Auto;
		Number_Of_Doors = numberOFdoors;
		number_Of_Seats = numberOFseats;
	}
	virtual ~Car() { /*cout << " Car::~Car()" << endl;*/ }
	void PrintVehicle();
	bool operator==(const Car& other) const;
	void operator=(const Car & other); //overload = operator
};
