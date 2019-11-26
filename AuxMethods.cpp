#include "AuxMethods.h"


bool onlyLetters(const char* str) {

	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (!((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A'))) {
			return false;
		}
	}
	return true;

}
bool checkSerial(const char* serial_number) {

	return true; // just for now
}