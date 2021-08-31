#pragma once
#include "RentedCarAcc.h"

RentedCarAcc::RentedCarAcc() //default C'tor
{
	RentedCar = nullptr;
	Rented_Start_Day.setDay(0);
	Rented_Start_Day.setMonth(0);
	Rented_Start_Day.setYear(0);
	Rented_End_Day.setDay(0);
	Rented_End_Day.setMonth(0);
	Rented_End_Day.setYear(0);
}

RentedCarAcc::RentedCarAcc(Date StartDay, Date EndDay, Car& RentCar)
{
	RentedCar = new Car; //we must use this because this is a pointer
	if (RentedCar!=nullptr)
		*(RentedCar)= RentCar;
	Rented_Start_Day = StartDay;
	Rented_End_Day = EndDay;
}

RentedCarAcc::RentedCarAcc(const RentedCarAcc& other)
{
	RentedCar = new Car;
	if (RentedCar != nullptr)
		RentedCar = other.RentedCar;
	Rented_Start_Day = other.Rented_Start_Day;
	Rented_End_Day = other.Rented_End_Day;
}

void RentedCarAcc::PrintRentedCarAccount()
{
	RentedCar->PrintVehicle();//first print cardetail
	cout << "Rent Pick-Up Day is: " << Rented_Start_Day << endl;
	cout << "Rent Drop-Off Day is: " << Rented_End_Day << endl;
	cout << "Price for Rent is: " << PriceForRent() << endl;
}

int RentedCarAcc::PriceForRent()
{
	int PriceForRent;
	if (typeid(*RentedCar) == typeid(Private))
	{
		PriceForRent = 170;
		return PriceForRent;
	}
	if (typeid(*RentedCar) == typeid(Commerical))
	{
		PriceForRent = 200;
		return PriceForRent;
	}
	if (typeid(*RentedCar) == typeid(Motorcycle))
		cout << "Unable to Rent A MotorCycle!" << endl;
}
