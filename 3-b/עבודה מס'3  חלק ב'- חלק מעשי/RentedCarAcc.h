#pragma once
#include "Car.h"
#include "Private.h"
#include "Commercial.h"
#include "Motorcycle.h"
#include "Date.h"
#include <typeinfo>
#include "Vehicle.h"

class RentedCarAcc {
public:
	RentedCarAcc(); //defualt D'tor, implement in cpp file
	RentedCarAcc(Date StartDay, Date EndDay, Car& RentCar); //parameter D'tor
	RentedCarAcc(const RentedCarAcc& other);
	virtual ~RentedCarAcc() { delete RentedCar; /*cout << " RentedCarAcc::~RentedCarAcc() //dynamic allocate deleted" << endl;*/ } //d'tor
	void PrintRentedCarAccount();
	int ValueDecline();//need to implement
	int PriceForRent();
	void set_Rent_Start_Day(Date other) { this->Rented_Start_Day.setDay(other.getDay()); this->Rented_Start_Day.setMonth(other.getMonth()); this->Rented_Start_Day.setYear(other.getYear());}
	void set_Rent_End_Day(Date other) {this->Rented_Start_Day.setDay(other.getDay()); this->Rented_Start_Day.setMonth(other.getMonth()); this->Rented_Start_Day.setYear(other.getYear());}
	virtual void set_RentedCar(Car* other) {RentedCar = other; }
	virtual Car* GetRentedCar() { return RentedCar; };
	int GetVehicleNumber() { return 0; }
	void PrintVehicle() {};

protected:
	Car* RentedCar;
	Date Rented_Start_Day;
	Date Rented_End_Day;
};