typedef enum { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec } Monthi;
#include <iostream>
#include <time.h>
#include "Date.h"
using namespace std;

Date::Date() //default ctor
{
	time_t rawtime;
	struct tm* timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	day = timeinfo->tm_mday;
	month = timeinfo->tm_mon + 1;
	year = timeinfo->tm_year + 1900;
}

Date::Date(int Day, int Month, int Year) //creative ctor
{
	day = Day;
	month = Month;
	year = Year;
}
void Date::setDay(int Day)
{
	day = Day;
}

void Date::setMonth(int Month)
{
	month = Month;
}

void Date::setYear(int Year)
{
	year = Year;
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::printDate()
{
	cout << day << "/" << month << "/" << year << endl;
}

void Date::printMiluli() //function that prints month in english
{
	//Assignment an array for month
	const char* months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	cout << months[month - 1]; //get excat month in his name!
}
int Date::remainDays() //function that return number of day in month
{
	int num=0;
	typedef enum {
		January = 1, February, March, April, May, June,
		July, August, September, October, November, December
	} Month;

	if ((month == January) || (month == March) || (month == May) || (month == July) || (month == August) || (month == October) || (month == December)) {
		num = 31;
	}
	if ((month == April) || (month == June) || (month == September) || (month == November)) {
		num = 30;
	}
	if (month == February)
	{
		if (isLeapyear())
			num = 29;
		else
			num = 28;
	}
	return num;
}

bool Date::isLeapyear() //function that tell wheter a year is a leap or not // Meoberet
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}
void Date::NextDayDate() {
	if (day < remainDays()) //day is valid and only need to change.
		day++;
	if (day == remainDays() && month < 12) { //we have to initilaize day = 1 and change month.
		day = 1;
		month++;
	}
	if (day == remainDays() && month == 12) {
		day = 1;
		month = 1;
		year++;
	}
}

ostream& operator << (ostream& output, const Date& object) {
	output << object.day << "/" << object.month << "/" << object.year << endl;
	return output;
}