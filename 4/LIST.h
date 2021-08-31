#pragma once
#include <string>
#include <typeinfo>
#include <iostream>
#include <stdexcept>
#include <assert.h> 

using namespace std;

template <class ObjType>
class List {
protected:
	ObjType* data; //Decalring General type array
	int size; //number of elements in General type array
public:
	List() { size = 0; data = nullptr; }; //defualt c'tor  
	List(int Givensize); //parameter\ c'tor  
	List(const List&); //copy constructor
	virtual ~List() { delete[] data; } //d'tor
	void Clear(); //method that delete general array element (deleting allocated memory)
	int Count(ObjType Element); //method that return how many time given element has been appear in general array.
	List<ObjType>& Append(ObjType Element); //method gets element and add it into end of general array.
	List<ObjType>& Extend(List<ObjType>& Array); //method gets array and add it into end of general array.
	int Index(ObjType Element); //method gets element and return his first index appearence  
	List<ObjType>& Remove(int Index); //method gets index and remove element sits on excat index (decrease size of array by one and update new array).
	int Length() { return size; }; //return number of elements in general array
	List<ObjType>& operator = (const List<ObjType>& other_obj);//assgin this->object with other object of same class
	List<ObjType> operator + (const List<ObjType>& other_obj) const;  //taking two object and do sum
	List<ObjType>& operator += (const List<ObjType>& other_obj); //this->object get array and add his element to him self array
	ObjType& operator [] (int index); //return general array element
	List<ObjType>& operator [] (string str);
	//we must add this line in order to tell compiler opeator << is template
	template<typename ObjType>
	friend ostream& operator <<(ostream& out, const List<ObjType>& other_obj);
	virtual void Print();
	List<ObjType>(ObjType* user_list, int user_size); //special constructor for spcefic operation

};

/*****************parameter c'tor****************************/
template <class ObjType>
List<ObjType>::List(int Givensize) : size(Givensize) {
	data = new ObjType[size];
	cout << "Enter " << size << " values: " << endl;
	for (int i = 0; i < size; i++)
		cin >> data[i];
};
/************************************************************************/

/******************Copy Constructor**************************************/
template <class ObjType>
List<ObjType>::List(const List& obj) : size(obj.size) {
	data = new ObjType[size];
	for (int i = 0; i < size; i++)
		data[i] = obj.data[i];
};
/************************************************************************/

/******************Special Constructor**************************************/

template<class ObjType>
inline List<ObjType>::List(ObjType* other_list, int other_size)
{
	if (other_list == NULL)
		throw invalid_argument("Element is not existent in array..");
	else if (other_size <= 0)
		throw length_error("Index is out of range..");
	size = other_size;
	data = new ObjType[other_size];
	for (int i = 0; i < size; i++)
		data[i] = other_list[i];
}
/************************************************************************/


/******************Clear Method******************************************/
template <class ObjType>
void List<ObjType>::Clear()
{
	delete[] data;
};
/************************************************************************/

/******************Count Method******************************************/
template <class ObjType>
int List<ObjType>::Count(ObjType Element)
{
	int counter = 0, i;
	for (i = 0; i < size; i++)
	{
		if (data[i] == Element) //we need to overload == for other types if needed
			counter++;
	}
	if (counter == 0) //if we reached here then element isn't existent in the array
		throw invalid_argument("Element is not existent in array..");
	return counter;
};
/************************************************************************/

/******************Append Method*****************************************/
template <class ObjType>
List<ObjType>& List<ObjType>::Append(ObjType Element) //typeif(element) == int,//typeif(data) == int*,//typeif(data[0]) == int
{
	if (size != 0)
	{
		int i;
		size++; //increase size for array
		ObjType* tempData;
		tempData = new ObjType[size];
		for (i = 0; i < size - 1; i++)
			tempData[i] = data[i];
		tempData[i] = Element; //input element in the last of array.
		delete[] data;
		data = tempData;  //moving pointer into data variable
	}
	else
	{
		size++;
		data = new ObjType[size];
		data[0] = Element;
	}

	return *this;
};
/************************************************************************/

/******************Extend Method*****************************************/
template <class ObjType>
List<ObjType>& List<ObjType>::Extend(List<ObjType>& Array)
{
	int i, j = 0, tempsize = Array.size;
	ObjType* tempData;
	tempData = new ObjType[size + tempsize];
	//first transfer all element from the obj array member
	for (i = 0; i < size; i++)
		tempData[i] = data[i];
	//laster transfer all element from the array that was sent 
	for (i; i < tempsize + size; i++)
		tempData[i] = Array[j++];
	delete[] data;
	data = tempData;  //moving pointer into data variable
	size += tempsize; //updating original size array. 
	return *this;
};
/************************************************************************/

/******************Index Method******************************************/
template <class ObjType>
int List<ObjType>::Index(ObjType Element)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (data[i] == Element)
			return i;
	}
	//if we reached here then element is not  inside array!
	throw invalid_argument("Element is not existent in array..");
};
/************************************************************************/

/******************Remove Method*****************************************/
template <class ObjType>
List<ObjType>& List<ObjType>::Remove(int index)
{
	//user supplied invalid index
	if (index < 0 && index + size>size - 1 || index >= size || index < 0 && index + size < 0)
		throw length_error("Index is out of range..");
	//we have to think about zero
	else
	{
		int i, j = 0;
		ObjType* tempData;
		tempData = new ObjType[size - 1];
		if (index >= 0) //section for valid positive index
		{
			for (i = 0; i < size; i++)
			{
				if (i == index)
					continue;
				else
					tempData[j++] = data[i]; //first copy all element to local array variable
			}
		}
		else
			//index is valid negative
		{
			int tempIndex = index + size; //user inputed negative index we convert it into valid index
			for (i = 0; i < size; i++)
			{
				if (i == tempIndex)
					continue;
				else
					tempData[j++] = data[i]; //first copy all element to local array variable
			}
		}
		delete[]data;
		data = tempData;
		size--; //update size of new array.
	}
	return *this;
};
/************************************************************************/

/*****************overloading operator = ********************************/
template <class ObjType>
List<ObjType>& List<ObjType>::operator = (const List<ObjType>& other_obj)
{
	if (this != &other_obj)
	{
		if (data)
			delete[] data;
		size = other_obj.size;
		data = new ObjType[size];
		assert(data);
		for (unsigned int i = 0; i < size; i++)
			data[i] = other_obj.data[i];
	}
	else
		cout << "Self assignment!" << endl;
	return *this;
}
/************************************************************************/

/*****************overloading operator + ********************************/
template <class ObjType>
List<ObjType> List<ObjType>::operator + (const List<ObjType>& other_obj) const
{
	List<ObjType> temp(*this);
	temp += other_obj;
	return temp;
}
/************************************************************************/


/*****************overloading operator += *******************************/
template <class ObjType>
List<ObjType>& List<ObjType>::operator += (const List<ObjType>& other_obj)
{
	int Size_of_GiArray = other_obj.size; //findind the size of the array.
	int i, j = 0;
	ObjType* tempData;
	tempData = new ObjType[size + Size_of_GiArray]; //-1
	//first transfer all element from the obj array member
	for (i = 0; i < size; i++)
		tempData[i] = data[i];
	//laster transfer all element from the array that was sent 
	for (i; i < size + other_obj.size; i++)
		tempData[i] = other_obj.data[j++];
	delete[] data;
	data = tempData;  //moving pointer into data variable
	size += other_obj.size; //updating original size array. //-1
	return *this;

};
/************************************************************************/

/*****************overloading operator [] *******************************/
template <class ObjType>
ObjType& List<ObjType>::operator [] (int index)
{
	//user created unvalid List obj
	if (index < 0 && index + size>size - 1 || index >= size || index < 0 && index + size < 0)
		throw length_error("Index is out of range..");
	else
	{
		if (index >= 0) //section for valid positive index
			return data[index];
		//index is valid negative
		else
		{
			int tempIndex = index + size; //user inputed negative index we convert it into valid index
			return data[tempIndex];
		}
	}
}
/************************************************************************/

/*****************overloading operator [] for string only******************************/
template <class ObjType>
List<ObjType>& List<ObjType>::operator [] (string str)
{
	//inorder to find whether there is Parentheses or not and if so , whats the index
	int ParenthesesPostion = str.find(":"), start = 0, end = size, i = 0; //defualt size for start and end.
	if (ParenthesesPostion == -1)//we havn't found parentheses then invalid argument as entered/
	{
		throw invalid_argument("Parentheses is not found! unable to slice array..");
	}
	else
	{
		string temp1 = str.substr(0, ParenthesesPostion);
		string temp2 = str.substr(ParenthesesPostion + 1, str.length());
		if (temp1.length() != 0)
			start = stoi(temp1); //else start remain zero as defualt.
		if (start < 0)
			start += size;
		//two statement to fix temp2 value.
		if (temp2.length() != 0)
			end = stoi(temp2);
		if (end < 0)
			end += size;
	}
	//first update size member then make new array sliced.
	int newsize = end - start;
	ObjType* temp_list = new ObjType[newsize]; //
	for (start; start < end; start++) ///1,2,3,4
		temp_list[i++] = data[start];
	List* tempData = new List(temp_list, newsize); //we must return an list value!
	return *tempData;
}
/************************************************************************/

/******************overload << operator function*************************/
template <class ObjType>
ostream& operator << (ostream& output, const List<ObjType>& object) {
	for (unsigned int i = 0; i < object.size; i++)
		output << object.data[i] << ' ';
	if (object.size==0)
		output << "list[]";
	output << endl;
	return output;
};
/************************************************************************/

/******************Print Method******************************************/
template <class ObjType>
void List<ObjType>::Print() {
	cout << "The values of Array are: ";
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << endl;
};
/************************************************************************/


