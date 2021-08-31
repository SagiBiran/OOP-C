#pragma once
#include "Car.h"
#include "Private.h"
#include "Commercial.h"
#include "Motorcycle.h"
#include "Date.h"
#include "RentedCarAcc.h"
#include <iostream>
using namespace std;

class VehicleManagement{
public:
	 VehicleManagement(); //defualt C'tor
	//VehicleManagement(int CarParkSize,Vehicle* Vehicls,int NumberOfAccouts,RentedCarAcc* RentedCarAcc);
	VehicleManagement(const VehicleManagement& other);//copy c'tor
	virtual	~VehicleManagement() ; //defualt D'tor
	void Menu(); //function will print all options for user to lunch program.
	void AddPrivateCar();
	void AddCommericalCar();
	void AddMotorCycle();
	void PrintVehicleClassOptions();
	virtual void PrintVehicle() {};
	virtual void PrintTotalPriceForVehicle();
	void Exit();
	//int ValueDecline() {};
	void PrintValueDecline() {};
	int ValueDecline() {};
	int GetVehicleNumber() {return 0;}
	void PrineAllMotorCycle();
	void CheapestPrivate();
	void CreateRentAccout();
	void PriceForSelling();
	void DeleteRentCarAccount();
	virtual void set_RentedCar(Car* other) {};
private:
	int CarParkSize, RentedCarAccounts;
	Vehicle** CarPrk;
	RentedCarAcc** RentCars;
};
