#include "Text.h"
class EncryptedText {
	Text* textPtr;
	bool status;
	int* key;
	int key_length;
public:
	EncryptedText(); //Default c'tor.
	EncryptedText(char* str, int status); //Manual c'tor.
	~EncryptedText(); //D'tor.
	EncryptedText& operator+=(int* user_key);
	EncryptedText& operator!();
	EncryptedText& operator&();
	friend ostream& operator << (ostream&, const EncryptedText&);
};
