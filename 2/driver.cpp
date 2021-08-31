/*** Assignment 2
Name: Sagi Bitton Id: 205620859 ***/
#include "EncryptedText.h"

int main() {
	int key[] = { 3,-1,4,1,-1,3,1,0,4,4,-1,0,5,-1,0,-2 };
	EncryptedText etext1((char*)"The London is capital of Great Britian.", 0);
	cout << etext1 << endl;
	etext1 += key;
	cout << !etext1 << endl;
	cout << "---------------------------------------------------------" << endl;
	EncryptedText etext2((char*)"RH oLMWLM gSV yIRGRZM. tIVZG LU iq GZOXZKR.", 1);
	cout << etext2 << endl;
	etext2 += key;
	cout << &etext2 << endl;
}