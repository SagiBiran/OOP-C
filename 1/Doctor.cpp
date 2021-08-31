/*** Assignment 1
Name: Sagi Bitton Id: 205620859 ***/
#include <iostream>
#include "Doctor.h"

Doctor::Doctor() {
	strcpy(fullName, "Unknown\n");
	strcpy(id, "000000000");
	years_of_seniority = 0;								// default cons.
	number_of_complexTreats = 0;
	isProffesor = false;
	qualifyAmount = 0;
	qualifyList= NULL;
}

Doctor::Doctor(char full_name[], char id[], int years_of_seniority, int number_of_complexTreats, int qualifyAmount ,bool isProf) {
	if (strlen(full_name) > 30)
		strcpy(this->fullName, "Unknown");
	else
		strcpy(this->fullName, full_name);
	if (strlen(id) < 9 || strlen(id) > 9 || id[0] == '0')
		strcpy(this->id, "000000000");
	else
		strcpy(this->id, id);
	//checking code propriety
	if (years_of_seniority < 0)
		this->years_of_seniority = 0;
	else
		this->years_of_seniority = years_of_seniority;
	if (number_of_complexTreats < 0)
		this->number_of_complexTreats = 0;
	else
		this->number_of_complexTreats = number_of_complexTreats;
	if(number_of_complexTreats>50 && isExcellent())
	{
		this->isProffesor = true;
	}
	else
		this->isProffesor = isProf;
	if (qualifyAmount < 0)
		this->qualifyAmount = 0;
	else
		this->qualifyAmount = qualifyAmount;

	if (qualifyAmount!=0)
	{
		InsertQualify(this->qualifyList);
	}
	else
		this->qualifyList = NULL; //intialize qulifylist to be MULL //////////FIX
}

Doctor::Doctor(const Doctor& old) //copy cons.
{
	strcpy(fullName, old.fullName);
	strcpy(id,old.id);
	years_of_seniority = old.years_of_seniority;						
	number_of_complexTreats = old.number_of_complexTreats;
	qualifyAmount = old.qualifyAmount;
	isProffesor = old.isProffesor;
	qualifyList = new char*[old.qualifyAmount]; 
	if (old.qualifyList != NULL)
	{
		int i;
		for (i = 0; i <old.qualifyAmount; i++) //inside copy ctor i've build a block instead of function to copy each course list
		{
			qualifyList[i] = new char[stdSIZE];
			if (qualifyList[i]!=NULL && old.qualifyList[i]!=NULL)
				strcpy(qualifyList[i] ,old.qualifyList[i]);
		}
	}
}

Doctor::~Doctor() //dtor
{
	cout << "delete" << endl;
	if (qualifyList != NULL)
	{
		for (int i = 0; i < qualifyAmount; i++)
			delete qualifyList[i];
		delete[] qualifyList;
	}
}


void Doctor::InsertQualify(char** ptr)
{
	char temp[stdSIZE];
	cout << "Please enter number of Courses: ";
	cin >> qualifyAmount;
	qualifyList = new char* [qualifyAmount];
	if (qualifyList != NULL)
	{

		for (int i = 0; i < qualifyAmount; i++)
		{
			cout << "Course name:";
			cin >> temp;
			qualifyList[i] = new char[strlen(temp) + 1];
			if(qualifyList[i]!=NULL)
				strcpy(qualifyList[i], temp);
			else
				exit(1);
		}
	}
	else
		exit(1);
}
bool Doctor::isQualify(char qualifyName[]) //small function that checks whether the doctor qualify specific couse.
{

	int i;
	for (i = 0 ;i < qualifyAmount; i++)
	{
		if (strcmp(qualifyList[i], qualifyName) == 0)
			return true;
	}
	return false;
}

char* Doctor::getfullName() {
	return fullName;
}

char* Doctor::getId() {
	return id;
}

int Doctor::getYears_of_seniority() {
	return years_of_seniority;
}

int Doctor::getNumber_of_complexTreats()
{
	return number_of_complexTreats;
}

bool Doctor::getIsproffesor()
	{
		return isProffesor;
	}

int Doctor::getQualifyAmount()
	{
		return qualifyAmount;
	}

char* Doctor::getQualifylist()
	{
		return *qualifyList;
	}

void Doctor::setfullName(const char fullName[])
{
	strcpy(this->fullName,fullName);
}

void Doctor::setId(const char id[])
{
	strcpy(this->id, id);
}

void Doctor::setYears_of_seniority(const int years_of_sen)
{
	this->years_of_seniority = years_of_sen;
}


void Doctor::setNumber_of_complexTreats(const int number_of_complex)
{
	this->number_of_complexTreats = number_of_complex;
}

void Doctor::setIsproffesor(const bool isprof)
{
	this->isProffesor = isprof;
}
void Doctor::setQualifyAmount(int &qualify_amount)
{
	this->qualifyAmount = qualify_amount;
}
void Doctor::setQualifylist(int qualifiesNumber) //intialize course list
{
	qualifyAmount = qualifiesNumber; //we must update qoualifyAmount
	qualifyList = new char* [qualifiesNumber];
	if (qualifyList != NULL)
	{
		cout << "Add course: " << endl;
		for (int i = 0; i < qualifiesNumber; i++)
		{
			qualifyList[i] = new char[stdSIZE];
			if (qualifyList[i] != NULL)
			{
				cin >> qualifyList[i];
			}
			else
				exit(1);
		}
	}
	else
		exit(1);
}
void Doctor::addCourse(int qualifiesNumber) //intialize course list
{
	qualifyAmount = qualifiesNumber; //we must update qoualifyAmount
	qualifyList = new char* [qualifiesNumber];
	if (qualifyList != NULL)
	{
		cout << "Add course: " << endl;
		for (int i = 0; i < qualifiesNumber; i++)
		{
			qualifyList[i] = new char[stdSIZE];
			if (qualifyList[i] != NULL)
			{
				cin >> qualifyList[i];
			}
			else
				exit(1);
		}
	}
	else
		exit(1);
}


int Doctor::Salary()
{
	int x=years_of_seniority, z=number_of_complexTreats,totalSalary;
	totalSalary = 200 * x + 300 * z + 4500;
	if (isProffesor)
		totalSalary += 1000;
	if (isExcellent())
		totalSalary += 500;
	return totalSalary;
}

bool Doctor::isExcellent()
{
	int temp = years_of_seniority * 3;
	if (temp >= number_of_complexTreats)
		return false;
	else
		return true;
}
void Doctor::printDoctor()
{
	int i;
	cout << "Employee name: " << fullName <<endl<<"ID:" << id << ", " << "Senority:" << years_of_seniority << ", " << "Complex treatments:" << number_of_complexTreats << ", " << "Prof:";
	if (isProffesor)
		cout << "Yes, " << "Courses: ,";
	else
		cout << "No, " << "Courses: ,";
	if (qualifyAmount!=0 && qualifyList!=NULL) //we must check if the qualitylist is empty and pointer is point
	{

		for (i = 0; i < qualifyAmount; i++)
		{
			cout << qualifyList[i] << ","; 
		}
		cout << " Salary:" << Salary() << endl;
	}
	else
		cout << " Salary:" << Salary()<<endl;
}