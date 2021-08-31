/*** Assignment 1
Name: Sagi Bitton Id: 205620859 ***/
#include <iostream>
#include <string.h>
using namespace std;
#define stdSIZE 80


class Doctor {
	public:
		Doctor();
		Doctor(char full_name[], char id[], int years_of_seniority, int number_of_complexTreats, int qualifyAmount, bool isProf);
		Doctor(const Doctor& old);
		~Doctor();
		void InsertQualify(char** ptr);
		void addCourse(int qualifiesNumber);
		char* getfullName();
		char* getId();
		int getYears_of_seniority();
		int getNumber_of_complexTreats();
		bool getIsproffesor();
		int getQualifyAmount();
		char* getQualifylist();
		void setfullName(const char fullname[]);
		void setId(const char id[]);
		void setYears_of_seniority(const int years_of_sen);
		void setNumber_of_complexTreats(const int complex_treats);
		void setIsproffesor(const bool isprof);
		void setQualifyAmount(int& quality_amount);
		void setQualifylist(int qualifiesNumber);
		bool isExcellent();
		int Salary();
		void printDoctor();
		bool isQualify(char qualifyName[]);
	private:
		char fullName[30];
		char id[10];
		int years_of_seniority;
		int number_of_complexTreats;
		bool isProffesor;
		char** qualifyList;
		int qualifyAmount;
};