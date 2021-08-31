#pragma once
#include <string>
#include <typeinfo>
#include <iostream>
#include <stdexcept>
#include <assert.h> 
#include "LIST.h"

template <class T>
class Queue : public List <T> //this is the syntax for inheritance a template class 
{
public:
	Queue() : List<T>() {}; //defualt c'tor
	~Queue() {}; //defualt d'tor
	Queue<T>& Enqueue(T Element); //method gets elementand add it into end of general array.
	bool isEmpty(); //check wheter queue empty or not
	T Peek(); //method show element that located in the top of the queue
	Queue<T>& Dequeue(); //method that take out top element in queue and remove him from queue.
	template<typename T> //cout overloaded operation 
	friend ostream& operator <<(ostream& out, const Queue<T>& other_obj);
};

/*****************Enqueue Method*****************************************/
template <class T>
Queue<T>& Queue<T>::Enqueue(T Element)
{
	//while entering into Append method there is a condition whether queue was empty or not
	List<T>::Append(Element);
	return *this;
};
/************************************************************************/

/*****************isEmpty Method*****************************************/
template <class T>
bool Queue<T>::isEmpty()
{
	if (this->size == 0)
		return true;
	else
		return false;
};
/************************************************************************/

/*****************Dequeue Method*****************************************/
template <class	T>
Queue<T>& Queue<T>::Dequeue()
{
	//removing head of queue 
	if (!isEmpty())
	{
		List<T>::Remove(0);
		return *this;
	}
	return *this;
}
/************************************************************************/

/*****************Peek Method********************************************/
template <class	T>
T Queue<T>::Peek()
{
		if (!isEmpty()) {
			return List<T>::operator[](0);
		}
		return 0;
}
/************************************************************************/

template <class	T>
/******************overload << operator function*************************/
ostream& operator << (ostream& output, const Queue<T>& object) {
	for (unsigned int i = 0; i < object.size; i++)
		output << object.data[i] << ' ';
	output << endl;
	return output;
};
/************************************************************************/
