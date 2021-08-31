#include "Word.h"

class Text {
	Word** text;
	int text_length;
	int WordsAmount(const char* sentence)const; //A method that counts the amount of words in the sentence.
	char CreateRandomChar()const; //Create a random char variable.
	char createRandSize()const; //Create a random size.
public:
	Text(); //Default c'tor.
	Text(char* a); //Manual c'tor.
	Text(const Text& copy); //Manual c'tor.
	~Text(); //D'tor.
	void initArray(int n); //A method for dynamic allocation of an array.
	void deleteArray(); //A method to delete an array
	int getSize();
	void setTextLength(int n);
	Word& getText(int index);
	Text& operator = (const Text& copy);
	Text& operator ! ();
	Text& operator -= (int n);
	Text& operator += (int n);
	Text& operator & ();
	Text& operator << (int n);
	Text& operator >> (int n);
	Word& operator [] (int index);
	friend ostream& operator << (ostream&, const Text&);
};
