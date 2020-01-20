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
string E_Commerce:: input(strtype type, int maxSize) 
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
int E_Commerce::findUser(const string& username) {

	for (unsigned int i = 0; i < numOfUsers; ++i) {
		if ((username.compare(users[i]->getUserName())==0))
			return i;
	}
	return NOT_FOUND;
}

E_Commerce::E_Commerce()
{

}

void E_Commerce ::emptyUsers(){
	vector<User*> ::iterator itr = users.begin();
	vector<User*> ::iterator itrEnd = users.end();
	for (; itr != itrEnd; ++itr)
		users.erase(itr);

}

E_Commerce::~E_Commerce()
{
	emptyUsers();
}

