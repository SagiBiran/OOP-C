#include <iostream>
#include <time.h>
using namespace std;

class Word {
	char* word;
	int word_length;
	int LettersAmount(char* w)const; //A method that counts the amount of latters in the word.
	char CreateRandomChar()const; //Create a random char variable.
public:
	Word(); //Default c'tor.
	Word(char* w); //Manual c'tor.
	Word(char* w, int n); //Manual c'tor.
	Word(const Word& copy); //Copy c'tor.
	~Word(); //D'tor.
	void initArray(int n); //A method for dynamic allocation of an array.
	void deleteArray(); //A method to delete an array
	Word& operator = (const Word& copy);
	Word& operator ! ();
	Word& operator -= (int n);
	Word& operator += (int n);
	Word& operator & ();
	Word& operator << (int n);
	Word& operator >> (int n);
	char& operator [] (int index);
	friend ostream& operator << (ostream&, const Word&);
};