#include "Text.h"

int Text::WordsAmount(const char* sentence)const {
	int words = 0, index = 0;
	while (sentence[index] != '\0') { //Checks for any spaces at first. If so, give me the initial index without a space.
		index++;
		if (sentence[index] != ' ')
			break;
	}
	index++;
	while (sentence[index] != '\0') { //Count the amount of words not including the end of sentence spaces.
		if (sentence[index] == ' ' && sentence[index + 1] != ' ' && sentence[index + 1] != '\0')
			words++;
		index++;
	}
	words++;
	return words;
}

char Text::CreateRandomChar()const {
	char random_char = (char)((rand() % 25) + 65);
	return random_char;
}

char Text::createRandSize()const {
	char random_size = (char)((rand() % 20) + 1);
	return random_size;
}

Text::Text() :text_length(5) {
	text = new Word * [text_length];
	text[0] = new Word((char*)"one", 3);
	text[1] = new Word((char*)"two", 3);
	text[2] = new Word((char*)"three", 5);
	text[3] = new Word((char*)"four", 4);
	text[4] = new Word((char*)"five", 4);
}

Text::Text(char* sentence) {
	//a loop that runs on the whole sentence, counts the number of letters of the word until the space,
	int index = 0, word_length = 0;
	text_length = WordsAmount(sentence);
	initArray(text_length);
	for (int i = 0; i < text_length; i++) {
		for (word_length = index; sentence[word_length] != ' ' && sentence[word_length] != '\0'; word_length++);
		while (sentence[word_length] != ' ' && sentence[word_length] != '\0')
			word_length++;
		text[i] = new Word(&(sentence[index]), word_length - index);
		while (sentence[index] != ' ')
			index++;
		index++;
	}
}

Text::Text(const Text& copy) :text(NULL) { //Copy c'tor.
	*this = copy;
}

Text::~Text() { delete[] text; } //D'tor.

void Text::initArray(int n) {
	text = new Word * [text_length];
}

void Text::deleteArray() {
	delete[] text;
}

int Text::getSize() {
	return text_length;
}

Word& Text::getText(int index) {
	return  *text[index];
}

void Text::setTextLength(int n) {
	text_length = n;
}

Text& Text::operator = (const Text& copy) {
	if (this != &copy) {
		text_length = copy.text_length;
		delete text;
		text = new Word * [text_length];
		for (int i = 0; i < text_length; i++)
			text[i] = copy.text[i];
	}
	return *this;
}

Text& Text::operator ! () { //Using the operator ! of word class.
	for (int i = 0; i < text_length; i++)
		!(*text[i]); //this is word object.
	return *this;
}

Text& Text::operator -= (int n) {
	text_length--;

	Word** temp = new Word * [text_length];
	for (int i = 0; i < n; i++) //Copies to the n element
		temp[i] = text[i];

	for (int i = n; i < text_length; i++) //Copying from one organ after n to the end.
		temp[i] = text[i + 1];

	deleteArray(); //Calls a function that deletes memory.
	initArray(text_length); //Calls a function that assigns memory at the word size, minus one.

	for (int i = 0; i < text_length; i++) //Makes the final copy.
		text[i] = temp[i];

	delete[] temp;
	return *this;
}

Text& Text::operator += (int n) {
	text_length++;

	int random_size = createRandSize();
	char* random_text = new char[random_size];

	for (int i = 0; i < random_size; i++) //Assigns dynamic memory to a random string of random size.
		random_text[i] = CreateRandomChar();

	Word** temp = new Word * [text_length];
	for (int i = 0; i < n; i++) //Copies to the n element.
		temp[i] = text[i];

	temp[n] = new Word(random_text, random_size); //Adds a random word.

	for (int i = n; i < text_length; i++) //Copying from n to the end, including n.
		temp[i + 1] = text[i];

	deleteArray(); //Calls a function that deletes memory.
	initArray(text_length); //Calls a function that assigns memory at the word size, plus one.

	for (int i = 0; i < text_length; i++) //Makes the final copy.
		text[i] = temp[i];

	delete[] temp;
	return *this;
}

Text& Text::operator & () {
	Word* temp;
	int end_index = text_length - 1;
	for (int i = 0; i <= end_index / 2; ++i) { //A loop that runs up to the center of the array and replaces the edges.
		temp = text[i];
		text[i] = text[end_index - i];
		text[end_index - i] = temp;
	}
	return *this;
}

Text& Text::operator << (int n) {
	for (int j = 0; j < n; j++) {
		Word* temp;
		temp = text[0]; //Moves the first element to a temporary variable.
		for (int i = 0; i < text_length; i++) { //Move the array to the left.
			text[i] = text[i + 1];
		}
		text[text_length - 1] = temp;  //Places the first organ in the last place.
	}
	return *this;
}

Text& Text::operator >> (int n) {
	for (int j = 0; j < n; j++) {
		Word* temp;
		temp = text[text_length - 1]; //Moves the last element to a temporary variable.
		for (int i = text_length - 1; i >= 0; i--) { //Move the array to the Right.
			text[i] = text[i - 1];
		}
		text[0] = temp; //Places the last organ in the first place.
	}
	return *this;
}

Word& Text::operator [] (int index) {
	if (index >= 0 && index < text_length) {
		return *text[index];
	}
	else {
		cout << "Out of boundary of the array: " << endl;
		exit(1);
	}
}

ostream& operator << (ostream& output, const Text& object) {
	for (int i = 0; i < object.text_length; i++)
		output << *object.text[i] << ' ';
	return output;
}