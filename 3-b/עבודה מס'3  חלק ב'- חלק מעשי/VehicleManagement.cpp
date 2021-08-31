#pragma once
#include "Car.h"
#include "Private.h"
#include "Commercial.h"
#include "Motorcycle.h"
#include "Date.h"
#include "RentedCarAcc.h"
#include "VehicleManagement.h"
#include "Vehicle.h"
#include <typeinfo>

VehicleManagement::VehicleManagement()
{
	int i = 0;
	Private p1(2001, "Private1", 96000, 29000, 10000, TypeOfEngine::Diesel, 1, 4, 5, Type_of_Private::Family); //14400
	Commerical c1(2001, "Commerical1", 96000, 29000, 10001, TypeOfEngine::Diesel, 1, 4, 5);
	Motorcycle m1(2001, "Motorcycle1", 96002, 291000, 10002,156);
	CarParkSize = 3;
	CarPrk = new Vehicle*[CarParkSize]; //dynamic allocate memory
	if (CarPrk != nullptr)
	{
			CarPrk[i] = new Private;
			*((CarPrk)[i++]) =  p1;
			//	Private(int Years, string Name_Manufacturer, int Km, int Price, int VehicleNumber, TypeOfEngine type, bool Auto, int numberOFdoors, int numberOFseats, Type_of_Private Type_of_PrivateCar) :Car(Years, Name_Manufacturer, Km, Price,VehicleNumber, type, Auto, numberOFdoors, numberOFseats)
			CarPrk[i] = new Commerical;
			*((CarPrk)[i++]) = c1;
			CarPrk[i] = new Motorcycle;
			*((CarPrk)[i]) = m1;

	}
	else 
		cout << "Unable to Dynamic allocate Vehicle Array that intedted to be inside CarPark" << endl;
	RentedCarAccounts = 0;
	this->RentCars =	nullptr;
	
}
//
//VehicleManagement::VehicleManagement(int CarParkSize, Vehicle* Vehicls, int NumberOfAccouts, RentedCarAcc* RentedCarAcc)
//{
//	this->CarParkSize = CarParkSize;
//	RentedCarAccounts = NumberOfAccouts;
//	CarPrk = new Vehicle* [CarParkSize];
//	RentCars = nullptr;
//}

VehicleManagement::~VehicleManagement()
{
	int i;
	if (CarPrk != nullptr)
	{
		for (i = 0; i < CarParkSize; i++)
			delete CarPrk[i];
		delete CarPrk;
	}
	if (RentCars != nullptr)
	{
		delete RentCars;
	}
}

VehicleManagement::VehicleManagement(const VehicleManagement& other)
{
	int i = 0;
	this->CarParkSize = other.CarParkSize;
	this->RentedCarAccounts = other.RentedCarAccounts;
	/*CarPrk = new Vehicle * [CarParkSize];
	for (i = 0; i < CarParkSize; i++)
		{
		CarPrk[i] = new (other.CarPrk[i]);  //do later, need to copy Carprk;
		}*/
	CarPrk = new Vehicle*[CarParkSize];
	for (i=0;i<CarParkSize;i++)
	{
		this->CarPrk[i] = new Vehicle;
		this->CarPrk[i] = other.CarPrk[i];
	}

	this->RentCars = new RentedCarAcc*[RentedCarAccounts];
	for (i = 0; i < RentedCarAccounts; i++)
	{
		this->RentCars[i] = new RentedCarAcc;
		this->RentCars[i] = other.RentCars[i];
	}
	//this->RentCars = other.RentCars;

}

void VehicleManagement::Menu()
{
	int UserChoose = 0;
	cout << "Hello! Please Choose one of these options to continue .." << endl << endl;
	cout << "[1]" << "Add Private Car into VehicleManagement" << endl;
	cout << "[2]" << "Add Commercial Car into VehicleManagement" << endl;
	cout << "[3]" << "Add Motorcycle into VehicleManagement" << endl;
	cout << "[4]" << "Rent options available by your Licence class" << endl;
	cout << "[5]" << "Create a new Rent Car Account" << endl;
	cout << "[6]" << "Return a Car from rent by Vehicle number" << endl;
	cout << "[7]" << "Buyout price for Vehicle by his Vehicle number" << endl;
	cout << "[8]" << "Print all Motorcyclies detalis that exist in Vehicle Management" << endl;
	cout << "[9]" << "Print cheapest private car in Vehicle Management" << endl;
	cout << "[10]" << "Exit Program" << endl;
	cout << endl;
	cin >> UserChoose;

	switch (UserChoose)
	{
		case 1:
		{
			AddPrivateCar();
			break;
		}
		case 2:
		{
			AddCommericalCar();
			break;
		}
		case 3:
		{
			AddMotorCycle();
			break;
		}
		case 4:
		{
			PrintVehicleClassOptions();
			break;
		}
		case 5:
		{
			CreateRentAccout();
			break;
		}
		case 6:
		{
			DeleteRentCarAccount();
			break;
		}
		case 7:
		{
			PriceForSelling();
			break;
		}
		case 8:
		{
			PrineAllMotorCycle();
			break;
		}
		case 9:
		{
			CheapestPrivate();
			break;
		}
		case 10:
		{
			Exit();
			break;
		}
	}
}

void VehicleManagement::AddPrivateCar()
	{
	int i, Year_Of_Manufacturer, KiloMeters_Drived, Price, VehicleNumber, Number_Of_Doors, number_Of_Seats;
	string Name_of_Manufacturer;
	bool Automatic;
	int temp_type_of_engine, temp_type_of_private;
	TypeOfEngine typeofengine;
	Type_of_Private Kind_Of_Private;
	Kind_Of_Private = Type_of_Private::Family; //just defualt inorder to disable error

	cout << "Please enter Private Car details to add" << endl;
	cout << "Name of Manufacturer: " << endl;
	cin >> Name_of_Manufacturer;
	cout << "Years of Manufacturer: " << endl;
	cin >> Year_Of_Manufacturer;
	cout << "KiloMeters_Drived: " << endl;
	cin >> KiloMeters_Drived;
	cout << "Company Price: " << endl;
	cin >> Price;
	cout << "Vehicle Number: " << endl;
	cin >> VehicleNumber;
	cout << "Number of doors: " << endl;
	cin >> Number_Of_Doors;
	cout << "Numbers of Seats: " << endl;
	cin >> number_Of_Seats;
	cout << "Automatic(1)/Manual(0)" << endl;
	cin >> Automatic;
	cout << "Type Of Engine(Diesel(0)/Gasoline(1))" << endl;
	cin >> temp_type_of_engine;
	if(temp_type_of_engine)
			typeofengine = TypeOfEngine::Diesel;
	else
			typeofengine = TypeOfEngine::Gasoline;
	cout << "Type Of Private(Mini(0)/Family(1)/Sport(2)/Luxary(3))" << endl;
	//Mini, Family, Sport, Luxary 
	cin >> temp_type_of_private;
	switch (temp_type_of_private)
	{
	case 0:
		Kind_Of_Private= Type_of_Private::Mini;
		break;
	case 1:
		Kind_Of_Private = Type_of_Private::Family;
		break;
	case 2:
		Kind_Of_Private = Type_of_Private::Sport;
		break;
	case 3:
		Kind_Of_Private = Type_of_Private::Luxary;
		break;
	} 
	//searching for similiar vehicles inorder to not add them
	for (i = 0; i < CarParkSize; i++)
	{
		if (VehicleNumber == (CarPrk[i])->GetVehicleNumber())
			cout << "Similiar Private Car Has Found! System is not adding your Car and exit! " << endl;
	}
	//if we reached here then there is no similar vehicle in park
	int new_size = CarParkSize + 1;
	Vehicle** New_Car_Park = new Vehicle * [new_size];
	for (int i = 0; i < CarParkSize; i++)
	New_Car_Park[i] = CarPrk[i];
	//Add the new Private car 
	New_Car_Park[new_size - 1] = new Private(Year_Of_Manufacturer, Name_of_Manufacturer, KiloMeters_Drived, Price, VehicleNumber, typeofengine, Automatic, Number_Of_Doors, number_Of_Seats, Kind_Of_Private);
	CarParkSize = new_size;
	CarPrk = New_Car_Park;
} 

void VehicleManagement::AddCommericalCar()
{
	int i, Year_Of_Manufacturer, KiloMeters_Drived, Price, VehicleNumber, Number_Of_Doors, number_Of_Seats;
	string Name_of_Manufacturer;
	bool Automatic;
	int temp_type_of_engine, temp_type_of_private;
	TypeOfEngine typeofengine;

	cout << "Please enter Commercial Car details to add" << endl;
	cout << "Name of Manufacturer: " << endl;
	cin >> Name_of_Manufacturer;
	cout << "Years of Manufacturer: " << endl;
	cin >> Year_Of_Manufacturer;
	cout << "KiloMeters_Drived: " << endl;
	cin >> KiloMeters_Drived;
	cout << "Company Price: " << endl;
	cin >> Price;
	cout << "Vehicle Number: " << endl;
	cin >> VehicleNumber;
	cout << "Number of doors: " << endl;
	cin >> Number_Of_Doors;
	cout << "Numbers of Seats: " << endl;
	cin >> number_Of_Seats;
	cout << "Automatic(1)/Manual(0)" << endl;
	cin >> Automatic;
	cout << "Type Of Engine(Diesel(0)/Gasoline(1))" << endl;
	cin >> temp_type_of_engine;
	if (temp_type_of_engine)
		typeofengine = TypeOfEngine::Diesel;
	else
		typeofengine = TypeOfEngine::Gasoline;
	//searching for similiar vehicles inorder to not add them
	for (i = 0; i < CarParkSize; i++)
	{
		if (VehicleNumber == (CarPrk[i])->GetVehicleNumber())
			cout << "Similiar Commerical Car Has Found! System is not adding your Commercial and exit! " << endl;
	}
	//if we reached here then there is no similar vehicle in park
	int new_size = CarParkSize + 1;
	Vehicle** New_Car_Park = new Vehicle * [new_size];
	for (int i = 0; i < CarParkSize; i++)
		New_Car_Park[i] = CarPrk[i];
	//Add the new Commercial 
	New_Car_Park[new_size - 1] = new Commerical(Year_Of_Manufacturer, Name_of_Manufacturer, KiloMeters_Drived, Price, VehicleNumber, typeofengine, Automatic, Number_Of_Doors, number_Of_Seats);
	CarParkSize = new_size;
	CarPrk = New_Car_Park;
}


void VehicleManagement::AddMotorCycle()
{
	int i, Year_Of_Manufacturer, KiloMeters_Drived, Price, VehicleNumber,Horsepower;
	string Name_of_Manufacturer;

	cout << "Please enter MotorCycle details to add" << endl;
	cout << "Name of Manufacturer: " << endl;
	cin >> Name_of_Manufacturer;
	cout << "Years of Manufacturer: " << endl;
	cin >> Year_Of_Manufacturer;
	cout << "KiloMeters_Drived: " << endl;
	cin >> KiloMeters_Drived;
	cout << "Company Price: " << endl;
	cin >> Price;
	cout << "Vehicle Number: " << endl;
	cin >> VehicleNumber;
	cout << "Horse-Power: " << endl;
	cin >> Horsepower;

	for (i = 0; i < CarParkSize; i++)
	{
		if (VehicleNumber == (CarPrk[i])->GetVehicleNumber())
			cout << "Similiar Motorcycle Has Found! System is not adding your Motorcycle and exit! " << endl;
	}
	//if we reached here then there is no similar vehicle in park
	int new_size = CarParkSize + 1;
	Vehicle** New_Car_Park = new Vehicle * [new_size];
	for (int i = 0; i < CarParkSize; i++)
		New_Car_Park[i] = CarPrk[i];
	//Add the new MotorCycle 
	New_Car_Park[new_size - 1] = new Motorcycle(Year_Of_Manufacturer, Name_of_Manufacturer, KiloMeters_Drived, Price, VehicleNumber, Horsepower);
	CarParkSize = new_size;
	CarPrk = New_Car_Park;
}

void VehicleManagement::PrintVehicleClassOptions()
{
	char LieceneClass[] = { 'A','a','B','b','C','c' };
	char ClassChoice;
	int i = 0;
	cout << "Please enter your Licence Class (A/B/C) to see available options for rent: " << endl;
	cout << "A: Motorcylce" << endl;
	cout << "B: MotorCycle and Private" << endl;
	cout << "C: All Cars" << endl;
	cin >> ClassChoice;

	//if user choose A class

	if (ClassChoice == LieceneClass[0] || ClassChoice == LieceneClass[1])
	{
		cout << "Available Moyotcylces for rent are: " << endl << endl;;
		for (i = 0; i < CarParkSize; i++)
		{
			if (typeid(*(CarPrk[i])) == typeid(Motorcycle)) //checking for only MotorCycle to show!
				CarPrk[i]->PrintVehicle();
		}
	}
	//if user choose B class
	if (ClassChoice == LieceneClass[2]|| ClassChoice == LieceneClass[3])
	{
		cout << "Available Moyotcylces and Privates for rent are: " << endl << endl;;
		for (i = 0; i < CarParkSize; i++)
		{
			if (typeid(*(CarPrk[i])) == typeid(Motorcycle)|| typeid(*(CarPrk[i])) == typeid(Private)) //checking for MotorCycle && Privates to show!
				CarPrk[i]->PrintVehicle();
		}
	}
	//if user choose C class
	if (ClassChoice == LieceneClass[4] || ClassChoice == LieceneClass[5])
	{
		cout << "Available Cars-Only!! for rent are: " << endl << endl;;
		for (i = 0; i < CarParkSize; i++)
		{
			if (typeid(*(CarPrk[i])) == typeid(Commerical) || typeid(*(CarPrk[i])) == typeid(Private)) //checking for MotorCycle && Privates to show!
				CarPrk[i]->PrintVehicle();
		}
	}


}

void VehicleManagement::PrintTotalPriceForVehicle()
{
	int i, VehicleNumber;
	cout << "Please enter Vehicle Number to print his selling price: " << endl;
	cin >> VehicleNumber;
	for (i = 0; i < CarParkSize; i++)
	{
		if (VehicleNumber == CarPrk[i]->GetVehicleNumber())
		{
			cout << "Total Price for Vehicle is: ";
			CarPrk[i]->PrintValueDecline();
			cout << endl;
			return;
		}	
		else
			continue;
	}
	cout << "Incorrect Vehicle Number as been collected!,quiting program." << endl;
}

void VehicleManagement::PrineAllMotorCycle()
{
	int i = 0;
	for (i = 0; i < CarParkSize; i++)
	{
		if (typeid(*(CarPrk[i])) == typeid(Motorcycle))
			CarPrk[i]->PrintVehicle();
	}

}

void VehicleManagement::CheapestPrivate()
{
	int i,j=0,counter = 0, indexarray[30]; //defualt set to be 30;
	for (i = 0; i < CarParkSize; i++)
	{
		if (typeid(*(CarPrk[i])) == typeid(Private))
		{
			counter++;
			indexarray[j++] = i; //indexarray[1,5,10]
		}
	}
	
	int tempMin = CarPrk[indexarray[0]]->ValueDecline(); //first object is now the tempmax
	for (int i = 1; i < counter; i++)  //
	{
		if (CarPrk[indexarray[i]]->ValueDecline() <= tempMin)
			tempMin = CarPrk[indexarray[i]]->ValueDecline();
	}
	//now print cheapest private deatlies
	for (int i = 0; i < counter; i++)  //
	{
		if (CarPrk[indexarray[i]]->ValueDecline() == tempMin)
		{
			cout << endl << "/************Cheapest Car is: *************/" << endl;
			CarPrk[indexarray[i]]->PrintVehicle();
		}

	}
			
}

void VehicleManagement::Exit()
{
	cout << "Quitting Program,GoodBye..." << endl;
	exit(1);
}

void VehicleManagement::PriceForSelling() //function that print total price for selling to any vehicle in vehicle management
{
	PrintTotalPriceForVehicle();
}

void VehicleManagement::CreateRentAccout()
{
	int userChoose;
	int temp, i, j = 0, indexarray[30]; //defualt set to be 30;
	int d, m, y;
	Date tempDate;
	cout << "Please Choose one from these available Cars to rent: " << endl;
	for (i = 0; i < CarParkSize; i++)
	{
		if (typeid(*(CarPrk[i])) == typeid(Private) || typeid(*(CarPrk[i])) == typeid(Commerical))
		{
			cout << endl << "Rent Option Number: " << "[" << i << "]" << endl << endl;
			CarPrk[i]->PrintVehicle();
			indexarray[j++] = i; 
		}
	}
	cout << endl << endl;
	cout << "Option Number: ";
	cin >> userChoose;
	if (CarPrk[indexarray[userChoose]]->GetVehicleNumber() == 000000)
	{
	cout << "You Choosed rented car! unable to Create Rent Car Account, qutting program.";
	}
	//user choosed available car.
	else
	{
		RentedCarAccounts++;
		RentCars = new RentedCarAcc * [RentedCarAccounts];
		RentCars[RentedCarAccounts-1] = new RentedCarAcc;
		cout << "Please enter date for starting rent: " << endl << "Day: ";
		cin >> d;  cout << "Month: "; cin >> m;  cout << "Year: "; cin >> y;
		tempDate.setDay(d); tempDate.setMonth(m); tempDate.setYear(y);
		RentCars[RentedCarAccounts-1]->set_Rent_Start_Day(tempDate);
		cout << "Please enter date for ending rent: " << endl << "Day: ";
		cin >> d; cout << "Month: "; cin >> m; cout << "Year: "; cin >> y;
		tempDate.setDay(d); tempDate.setMonth(m); tempDate.setYear(y);
		RentCars[RentedCarAccounts-1]->set_Rent_End_Day(tempDate);
		RentCars[RentedCarAccounts-1]->set_RentedCar(dynamic_cast<Car*>(CarPrk[indexarray[userChoose]])); //moving pointer..to exact path//not workign.
		cout << endl << "Car Rent Account has been created!" << endl;
		cout << "Rented Car that choosen is: " << endl << endl;;
		RentCars[RentedCarAccounts-1]->GetRentedCar()->PrintVehicle();
	}
}

void VehicleManagement::DeleteRentCarAccount()
{
	int i, VehicleNumber,j=0;
	cout << "Please enter Vehicle Number to return from rent: " << endl;
	cin >> VehicleNumber;
	for (i = 0; i < CarParkSize; i++)
	{
		if (VehicleNumber == CarPrk[i]->GetVehicleNumber())
		{
			cout << "Deleting Car from Rent Car Accounts! "<< endl;
			delete RentCars[j]; //deleting Car that rented from Rented Car Accounts
			delete RentCars;
			return;
		}
		else
			continue;
	}
	cout << "No Vehicle has been found with inputed Vheicle number ,quiting program." << endl;
}
