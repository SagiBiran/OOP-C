#include "EncryptedText.h"

EncryptedText::EncryptedText() :textPtr(NULL), key(NULL), status(0), key_length(0) { //Default c'tor.
	textPtr = new Text((char*)"one two three four five");
}
EncryptedText::EncryptedText(char* str, int status) : key(NULL), key_length(0) { //Manual c'tor.
	this->status = status;
	textPtr = new Text(str);
}

EncryptedText::~EncryptedText() { //D'tor.
	delete textPtr;
	delete[] key;
}

EncryptedText& EncryptedText::operator+=(int* user_key) {
	key_length = 0;
	while (user_key[key_length] != -2) { //Count the array size to the final condition, in this case -2.
		key_length++;
	}
	key = new int[key_length]; //Assigns dynamic memory of the array to the size above.
	for (int i = 0; i < key_length; i++)
		key[i] = user_key[i];
	return *this;
}

ostream& operator << (ostream& out, const EncryptedText& obj) {
	if (obj.status == 0 && obj.key == NULL) {
		cout << "The decrypted text: ";
		out << (*obj.textPtr) << endl;
		cout << "The key: Empty" << endl;
	}
	if (obj.status == 0 && obj.key != NULL) {
		cout << "The encrypted text: ";
		out << (*obj.textPtr) << endl;
		cout << "The key:" << endl;
		for (int i = 0; i < obj.key_length; i += 3)
		{
			cout << obj.key[i] << "  " << obj.key[i + 1] << "  " << obj.key[i + 2] << endl;
		}

	}
	if (obj.status == 1 && obj.key != NULL) {
		cout << "The encrypted text: ";
		out << (*obj.textPtr) << endl;
		cout << "The key:" << endl;
		for (int i = 0; i < obj.key_length; i += 3)
		{
			cout << obj.key[i] << "  " << obj.key[i + 1] << "  " << obj.key[i + 2] << endl;
		}
	}
	if (obj.status == 2) {
		cout << "The decrypted text: ";
		out << (*obj.textPtr) << endl;
	}

	cout << endl;
	return out;
}

EncryptedText& EncryptedText::operator!() {
	for (int i = 0; i < key_length; i += 3) {
		int code = key[i], text_or_word = key[i + 1], parameter = key[i + 2];
		if (text_or_word == -1) { //In case the user chooses to encrypt a statement.
			for (int j = 0; j < textPtr->getSize(); j++) {
				switch (code) {
				case 1: (*textPtr) << parameter;
					break;
				case 2: (*textPtr) >> parameter;
					break;
				case 3: (*textPtr) += parameter;
					break;
				case 4: !(textPtr->getText(j));
					continue;
				case 5: &(*textPtr);
					break;
				}
				break;
			}
		}

		else { //In case the user chooses to encrypt a word.
			switch (code) {
			case 1: (textPtr->getText(text_or_word)) << parameter;
				break;
			case 2: (textPtr->getText(text_or_word)) << parameter;
				break;
			case 3: (*textPtr) += parameter;
				break;
			case 4: !(textPtr->getText(text_or_word));
				continue;
			case 5: &(textPtr->getText(text_or_word));
				break;
			}
		}
	}
	return *this;
}

EncryptedText& EncryptedText::operator&() {
	for (int i = key_length - 1; i > 0; i -= 3) {
		int parameter = key[i], text_or_word = key[i - 1], code = key[i - 2];
		if (text_or_word == -1) { //In case the user chooses to encrypt a statement.
			for (int j = 0; j < textPtr->getSize(); j++) {
				switch (code) {
				case 1: (*textPtr) >> parameter;
					break;
				case 2: (*textPtr) << parameter;
					break;
				case 3: (*textPtr) -= parameter;
					break;
				case 4: !(textPtr->getText(j));
					continue;
				case 5: &(*textPtr);
					break;
				}
				break;
			}
		}

		else { //In case the user chooses to encrypt a word.
			switch (code) {
			case 1: (textPtr->getText(text_or_word)) >> parameter;
				continue;
			case 2: (textPtr->getText(text_or_word)) << parameter;
				continue;
			case 3: (*textPtr) -= parameter;
				continue;
			case 4: !(textPtr->getText(text_or_word));
				continue;
			case 5: &(textPtr->getText(text_or_word));
				continue;
			}
		}
	}
	return *this;
}