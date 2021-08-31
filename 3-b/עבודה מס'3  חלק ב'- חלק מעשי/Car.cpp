#include <iostream>
#include <string.h>
#include "Car.h"
#include "Vehicle.h"
using namespace std;

void Car::PrintVehicle()
{
	Vehicle::PrintVehicle();
	cout << "Type_Of_Engine is: ";
	if (Type_Of_Engine == TypeOfEngine::Diesel || Type_Of_Engine == TypeOfEngine::diesel) //which means user input Diesel as input
		cout << "Diesel" << endl;
	else
		cout << "Gasoline" << endl;
	cout << "Gearbox is: ";
	if (Automatic)
		cout << "Automatic" << endl;
	else
		cout << "Manual" << endl;

	cout << "Number_Of_Doors: " << Number_Of_Doors << endl;
	cout << "Number_Of_Seats: " << number_Of_Seats << endl;
}

bool Car::operator==(const Car& other) const //overloading funciton equal qual
{
	if ((Type_Of_Engine == other.Type_Of_Engine) && (Automatic == other.Automatic) && Name_of_Manufacturer == other.Name_of_Manufacturer)
		return true;
	else
		return false;
}

void Car::operator=(const Car& other)
{
	Type_Of_Engine = other.Type_Of_Engine;
	Automatic = other.Automatic;
	Number_Of_Doors = other.Number_Of_Doors;
	number_Of_Seats = other.number_Of_Seats;
}
