/*** Assignment 1
Name: Sagi Bitton Id: 205620859 ***/
#include <iostream>
#include "Doctor.h"
static char** ptr;
int main()
{
	Doctor dc1;
	char name[stdSIZE]="Unknown",id[10]="000000000", name2[stdSIZE], id2[10]; /*Very important! this is the only way to send, we must intialize the char before*/
	int years_of_senority, Complex_treats,Num_of_Course;
	char ch[2];
	cout << "Enter FullName: ";
	cin.getline(name2, sizeof(name));
	dc1.setfullName(name2);
	cout << "Enter ID: ";
	cin.getline(id2, sizeof(id2));  ////**********cin.getline() is safer than cin****************/
	dc1.setId(id2);
	cout << "Years of Senority: ";
	cin >> years_of_senority;
	dc1.setYears_of_seniority(years_of_senority);
	cout << "Complex treatments: ";
	cin >> Complex_treats;
	dc1.setNumber_of_complexTreats(Complex_treats);
	cout << "Prof(Y/N): ";
	cin >> ch;
	if(*ch =='y'||*ch=='Y')
		dc1.setIsproffesor(1);
	else
		dc1.setIsproffesor(0);
	cout << "Num of Courses: ";
	cin >> Num_of_Course;
	dc1.setQualifyAmount(Num_of_Course);
	dc1.addCourse(Num_of_Course);
	dc1.printDoctor();
	Doctor dc2(name, id, 1, 51, 0, 0);
	dc2.printDoctor();
	Doctor dc3 = dc1;
	dc3.printDoctor();
	return 0;

}