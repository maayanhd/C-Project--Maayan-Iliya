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
void E_Commerce::save() {

	ofstream outFile("Users.txt", ios::trunc);
	for (auto user : users) {
		outFile << *user;
	}
	outFile.close();

}

void E_Commerce::load() {
	ifstream inFile("Users.txt", ios::_Nocreate);
	char delim;
	int identType;
	string username, password, country, city, street;
	int houseInfo[2];
	while (!inFile.eof()) {
		inFile >> identType;
		getline(inFile, username, ',');
		getline(inFile, password, ',');
		getline(inFile, country, ',');
		getline(inFile, city, ',');
		getline(inFile, street, ',');
		inFile >> houseInfo[0];
		inFile >> delim;
		inFile >> houseInfo[1];
		Address address(country, city, street, houseInfo);
		if (identType == 0) {
			users.push_back(new Seller(username, password, address));
		}
		else if (identType == 1) {
			users.push_back(new Customer(username, password, address));
		}
		else
		{
			Customer c(username, password, address);
			Seller s(username, password, address);
			users.push_back(new Customer_Seller(c,s));
		}
	
	}
	inFile.close();
}
void E_Commerce:: operator+=( User& newUser) {
	
	users.push_back(&newUser);

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
	for (auto user:users)
		delete user;
}

E_Commerce::~E_Commerce()
{
	emptyUsers();
}

