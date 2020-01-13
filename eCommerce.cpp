#include "eCommerce.h"


void E_Commerce:: changeUsersArrSize()
{
	maxSize *= 2;
	User** newArr = new User*[maxSize];
	for (unsigned int i = 0; i < numOfUsers; ++i)
		newArr[i] = users[i];
	delete[] users;
	this->users = newArr;
    
}

bool E_Commerce::isValid(const char* str,strtype type) const {

	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		switch (type)
		{
		case LETTERS:
			if (!((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A')) && str[i] != ' ' && str[i] != '-')
				return false;
			break;
		case MIXED:
			if (!((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A')) && str[i] != ' ' && str[i] != '-' && !(str[i] <= '9' && str[i] >= '0'))
				return false;
			break;
		case FREESTYLE:
			return true;
			break;
		}
	}
	return true;

}
char* E_Commerce:: input(strtype type, int maxSize) 
{
	bool valid = false;
	char* res = new char[maxSize];
	int iterationsCounter = 1;
	do {
		if (iterationsCounter > 1)
			cout << "Invalid input, please try again\n";
		valid = getString(res, maxSize);  
		if (valid)						 // in case the string is valid - in manners of length
			valid = isValid(res, type);  // content of string validation
		++iterationsCounter;
	} while (!valid);
	
	return res;
}
void E_Commerce:: operator+=(User* newUser) {
	if (numOfUsers == maxSize)
		changeUsersArrSize();
	users[numOfUsers++] = newUser;

}
int E_Commerce::findUser(const char* username) {

	for (unsigned int i = 0; i < numOfUsers; ++i) {
		if (strcmp(username, users[i]->getUserName()) == 0)
			return i;
	}
	return NOT_FOUND;
}

E_Commerce::E_Commerce()
{
	numOfUsers = 0;
	maxSize = 1;
	users = new User*[maxSize];
}

void E_Commerce ::emptyUsers(){

	for (unsigned int i = 0; i < numOfUsers; ++i) {
		delete users[i];
	}
	delete[] users;
	numOfUsers = 0;
	maxSize = 1;
}

E_Commerce::~E_Commerce()
{
	emptyUsers();
}

