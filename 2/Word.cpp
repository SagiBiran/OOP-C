#include "Word.h"

int Word::LettersAmount(char* w)const { //A loop checking how many letters a word has.
	int i = 0;
	while (w[i] != '\0') {
		i++;
	}
	return i;
}

char Word::CreateRandomChar()const {
	char random = (char)((rand() % 25) + 65);
	return random;
}

Word::Word() :word_length(5) { //Default c'tor.
	initArray(word_length);
	strcpy_s(word, word_length, "none");
}

Word::Word(char* w) { //Manual c'tor
	word_length = LettersAmount(w);
	initArray(word_length);
	for (int i = 0; i < word_length; i++)
		word[i] = w[i];
}

Word::Word(char* w, int n) :word_length(n) { //Manual c'tor.
	initArray(word_length);
	for (int i = 0; i < word_length; i++)
		word[i] = w[i];
}

Word::Word(const Word& copy) :word(NULL) { //Copy c'tor.
	*this = copy;
}

Word::~Word() { delete[] word; } //D'tor.

void Word::initArray(int n) {
	word = new char[n];
}

void Word::deleteArray() {
	delete[] word;
}

Word& Word::operator = (const Word& copy) {
	if (this != &copy) {
		word_length = copy.word_length;
		delete[] word;
		word = new char[word_length];
		for (int i = 0; i < word_length; i++)
			word[i] = copy.word[i];
	}
	return *this;
}

Word& Word::operator ! () {
	for (int i = 0; i < word_length; i++) {
		if (word[i] >= '0' && word[i] <= '9') //Completing to 9.
			word[i] = '9' - word[i] + '0';
		else if (word[i] >= 'a' && word[i] <= 'z') { //Uppercase letters.
			word[i] -= ('a' - 'A');
			word[i] = 'Z' - word[i] + 'A';
		}
		else if (word[i] >= 'A' && word[i] <= 'Z') { //Lowercase letters.

			word[i] += ('a' - 'A');
			word[i] = 'z' - word[i] + 'a';
		}
	}
	return *this;
}

Word& Word::operator -= (int n) {
	word_length--;
	char* temp = new char[word_length];
	for (int i = 0; i < n; i++) //Copies to the n element
		temp[i] = word[i];

	for (int i = n; i < word_length; i++) //Copying from one organ after n to the end.
		temp[i] = word[i + 1];

	deleteArray(); //Calls a function that deletes memory.
	initArray(word_length); //Calls a function that assigns memory at the word size, minus one.

	for (int i = 0; i < word_length; i++) //Makes the final copy.
		word[i] = temp[i];

	delete[] temp;
	return *this;
}

Word& Word::operator += (int n) {
	word_length++;
	char* temp = new char[word_length];
	for (int i = 0; i < n; i++) //Copies to the n element
		temp[i] = word[i];

	temp[n] = CreateRandomChar(); //Adds a random character.

	for (int i = n; i < word_length; i++) //Copying from n to the end, including n.
		temp[i + 1] = word[i];

	deleteArray(); //Calls a function that deletes memory.
	initArray(word_length); //Calls a function that assigns memory at the word size, plus one.

	for (int i = 0; i < word_length; i++) //Makes the final copy.
		word[i] = temp[i];

	delete[] temp;
	return *this;
}

Word& Word::operator & () {
	char temp;
	int end_index = word_length - 1;
	for (int i = 0; i <= end_index / 2; ++i) { //A loop that runs up to the center of the array and replaces the edges.
		temp = word[i];
		word[i] = word[end_index - i];
		word[end_index - i] = temp;
	}
	return *this;
}

Word& Word::operator << (int n) {
	for (int j = 0; j < n; j++) {
		char temp;
		temp = word[0]; //Moves the first element to a temporary variable.
		for (int i = 0; i < word_length; i++) { //Move the array to the left.
			word[i] = word[i + 1];
		}
		word[word_length - 1] = temp; //Places the first organ in the last place.
	}
	return (*this);
}

Word& Word::operator >> (int n) {
	for (int j = 0; j < n; j++) {
		int temp;
		temp = word[word_length - 1]; //Moves the last element to a temporary variable.
		for (int i = word_length - 1; i >= 0; i--) { //Move the array to the Right.
			word[i] = word[i - 1];
		}
		word[0] = temp; //Places the last organ in the first place.
	}
	return (*this);
}

char& Word::operator [] (int index) {
	if (index >= 0 && index < word_length) {
		return word[index];
	}
	else {
		cout << "Out of boundary of the array: " << endl;
		exit(1);
	}
}

ostream& operator << (ostream& output, const Word& object) {
	for (int i = 0; i < object.word_length; i++)
		output << object.word[i];
	return output;
}