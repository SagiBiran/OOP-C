/******** Assignment 4, Name: Sagi Bitton
	  Id:205620859					********/
#pragma once
#include <string>
#include <typeinfo>
# include <iostream>
#include "LIST.h"
#include "Queue.h"
#include <stdexcept>
#include <assert.h> 

using namespace std;


int main()
{
	try {
	List <int> list1;
	cout << list1 << endl;
	list1.Append(1).Append(2).Append(3);
	cout << list1;
	cout << ",[list1]" << list1.Length() << endl;

	List <int> list2(list1);
	cout << list1.Extend(list2).Remove(0);
	cout << ",#3-" << list1.Count(3) << endl;
	list2 = list1;
	list2[0] = 100;
	list2[-1] = 200;
	cout << list2 << ",index(2)-" << list2.Index(2) << endl;
	cout << list2["2:"] + list2[":3"] + list2["1:-1"] << endl;
	list1 += list2["2:"];
	cout << list1 << endl;

	List<string>list3, list4, list5;
	cout << list3.Append("London").Append("is").Append("the").Append("capital").Append("Of") << endl;
	list4.Append("Great").Append("Britian");
	list5.Append("Paris").Append("France");
	list3 += list4;
	cout << list3 << endl << list3[":4"] << endl << list3["-2:"] << " - " << list3[0] << endl;
	cout << list5[":1"] + list3["1:-2"] + list5["1:"] << endl;

	Queue<int>q1;
	cout << q1.Enqueue(1).Enqueue(2).Enqueue(3).Enqueue(4).Enqueue(5) << endl;
	cout << q1.Peek() << " " << q1.Peek()<< " " << q1.Peek() + 1 << endl;
	q1.Dequeue();
	q1.Dequeue();
	q1.Enqueue(100);
	cout << q1 << endl;
	}
	catch (const length_error& e)
	{
		cout << "Error: " << e.what() << endl;
	}
	catch (const invalid_argument& e)
	{
		cout << "Error: " << e.what() << endl;
	}
	//catch in order to catch invalid allocation
	catch (bad_alloc& ba)
	{
		cout << "Error: " << ba.what() << " has been found , program terminated." << endl;
	}
	catch (...) { //Global exception handling
		cout << "Caught unknown exception." << endl;
	}
	return 0;
}

