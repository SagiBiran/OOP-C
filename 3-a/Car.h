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
	Car():Vehicle(){Type_Of_Engine = TypeOfEngine::Diesel; Automatic = 0; Number_Of_Doors = 0; number_Of_Seats = 0; };
	Car(int Years, string Name_Manufacturer, int Km, int Price, TypeOfEngine type, bool Auto, int numberOFdoors, int numberOFseats):Vehicle(Years, Name_Manufacturer, Km, Price)
	{ 
		Type_Of_Engine = type;
		Automatic = Auto; 
		Number_Of_Doors = numberOFdoors;
		number_Of_Seats = numberOFseats;
	}
	~Car(){ cout << " Car::~Car()" << endl; }
	void PrintCar();
	bool operator==(const Car& other) const;


};
//