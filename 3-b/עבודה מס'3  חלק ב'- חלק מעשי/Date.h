#pragma once
#include <iostream>
using namespace std;

class Date {
public:
	Date();
	Date(int Day, int Month, int Year);
	void setDay(int Day);
	void setMonth(int Month);
	void setYear(int Year);
	int getDay();
	int getMonth();
	int getYear();
	void printDate();
	void printMiluli();
	int remainDays();
	bool isLeapyear();
	void NextDayDate();
	virtual ~Date() //dTor that prints last obj info.
	{
		//cout << endl << "~Date()" << endl;
	}
	friend ostream& operator << (ostream&, const Date&);

protected:
	int day, month, year;
};

