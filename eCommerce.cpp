#include "eCommerce.h"


bool E_Commerce::isValid(const string& str,strtype type) const {

	int len = str.length();
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
string E_Commerce:: input(strtype type) 
{
	bool valid = false;
	string res;
	int iterationsCounter = 1;
	do {
		if (iterationsCounter > 1)
			cout << "Invalid input, please try again\n";
		getline(std::cin, res);  
	    valid = isValid(res, type);  // content of string validation
		++iterationsCounter;
	} while (!valid);
	
	return res;
}
void E_Commerce:: operator+=(User* newUser) {
	
	users.push_back(newUser);

}
User* E_Commerce::findUser(const string& username) {

	vector<User*>::iterator itr = users.begin();
	vector<User*>::iterator itrEnd = users.end();
		
	for (;itr!=itrEnd; ++itr) {
		if ((username.compare( (*itr)->getUserName() )==0 ))
			return *itr;
	}
	return NULL;
}

E_Commerce::E_Commerce()
{

}

void E_Commerce ::emptyUsers(){
	int size = users.size();
	for (int i = 0; i < size; i++) {
		delete users[i];
	}/*
	users.erase(users.begin(), users.end());*/

}

E_Commerce::~E_Commerce()
{
	emptyUsers();
}

