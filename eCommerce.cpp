#include "eCommerce.h"


Customer** E_Commerce:: changeCustomersArrSize()
{ // Sending the address of the array of pointers to class objects to release it after allocating the new array by the updated size
	Customer** updatedCustomers= new Customer*[currentNumOfCustomers+1]; 
	for (unsigned int i=0; i<currentNumOfCustomers; i++)
	{
		updatedCustomers[i] =customers[i]; // Shallow copying of pointers 
	}	
	setNumOfCustomers(currentNumOfCustomers + 1);
	return updatedCustomers;
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
		if (valid)
			valid = isValid(res, type);
		++iterationsCounter;
	} while (!valid);
	
	return res;
}
Customer* E_Commerce::newCustomer() 
{
	char* username=nullptr, *password, *country, *city, *street;
	int house[2];
	int i = 0, j = 0;
	while (i != NOT_FOUND || j!=NOT_FOUND)  // Make sure that we don't have user with the same username
	{
		cout << "Please enter userName:\n";
		username = input(MIXED, MAX_LENGTH);
		i = findCustomer(username);
		j = findSeller(username);
		if (i != NOT_FOUND || j!=NOT_FOUND)
		{
			cout << "The username:" << username << " already exists in the system, please try again" << endl;
			delete[] username;
		}
	}
	cout << "Please Enter A Password\n";
	password = input(FREESTYLE, MAX_LENGTH);
	cout << "Please Enter A Country\n";
	country = input(LETTERS, MAX_LENGTH);
	cout << "Please Enter A City\n";
	city = input(LETTERS, MAX_LENGTH);
	cout << "Please Enter A Street\n";
		street = input(MIXED, MAX_LENGTH);
	cout << "Enter the house number" << endl;
	cin >> house[0];
	cout << "Enter the entrance number" << endl;
	cin >> house[1];
	while (house[0] <= 0 || house[1] <= 0) {
		cout << "House and entrance numbers should be a positive numbers " << endl;
		cout << "Please try again" << endl;
		cout<< "House number:\n";    cin >> house[0];
		cout << "Entrance number:\n"; cin >> house[1];
	}
	Customer* res = new Customer(username, password, country, city, street, house);
	delete[] username;
	delete[] password;
	delete[] country;
	delete[] city;
	delete[] street;
	return res;
}

Seller* E_Commerce::newSeller() 
{

	char* username=nullptr, *password, *country, *city, *street;
	int house[2];
	int i = 0, j = 0;
	while (i != NOT_FOUND || j != NOT_FOUND) { // Make sure that we don't have user with the same username
		cout << "Please enter a username:\n";
		username = input(MIXED, MAX_LENGTH);
		i = findCustomer(username);
		j = findSeller(username);
		if (i != NOT_FOUND || j != NOT_FOUND)
		{
			cout << "The username:" << username << " already exists in the system, please try again" << endl;
			delete[] username;
		}
	}
	cout << "Please enter a Password:\n";
	password = input(FREESTYLE, MAX_LENGTH);
	cout << "Please enter a Country:\n";
	country = input(LETTERS, MAX_LENGTH);
	cout << "Please enter a City:\n";
	city = input(LETTERS, MAX_LENGTH);
	cout << "Please enter a Street:\n";
	street = input(MIXED, MAX_LENGTH);

	cout << "Enter the house number" << endl;
	cin >> house[0];
	cout << "Enter the entrance number" << endl;
	cin >> house[1];
	while (house[0] <= 0 || house[1] <= 0) {
		cout << "House and entrance numbers should be a positive numbers " << endl;
		cout << "Please try again" << endl;
		cin >> house[0];
		cin >> house[1];
	}
	Seller* res = new Seller(username, password, country, city, street, house);
	delete[] username;
	delete[] password;
	delete[] country;
	delete[] city;
	delete[] street;
	return res;
}

Seller** E_Commerce::changeSellersArrSize()
{ // Sending the address of the array of pointers to class objects to release it after allocating the new array by the updated size
	Seller** updatedSellers = new Seller*[currentNumOfSellers+1];
	for (unsigned int i = 0; i < currentNumOfSellers; i++)
		updatedSellers[i] = sellers[i]; // Shallow copying of pointers 
	setNumOfSellers(currentNumOfSellers + 1);
	return updatedSellers;
}
void E_Commerce :: setNumOfCustomers(int num) 
{
	if(num>=0)
	currentNumOfCustomers = num;
}
void E_Commerce::setNumOfSellers(int num) 
{
	if(num>=0)
	currentNumOfSellers = num;
}
E_Commerce::E_Commerce()
{
	setNumOfCustomers(0);
	setNumOfSellers(0);
	customers = nullptr; sellers = nullptr;
}


bool E_Commerce::getString(char* str, int maxSize) 
{

	cin.getline(str, maxSize);
	if (cin.fail())
	{
		cin.clear();
		cleanBuffer();
		return false;
	}
	else {
		//str = res;
		return true;
	}
}

void E_Commerce::cleanBuffer()
{
	
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}



void E_Commerce::emptyCustomers()
{

	for (unsigned int i = 0; i < currentNumOfCustomers; ++i)
		delete customers[i];
	delete[] customers;
	currentNumOfCustomers = 0;
}
int E_Commerce::findCustomer(const char* username) const 
{

	for (unsigned int i = 0; i < currentNumOfCustomers; ++i) {
		if ( !strcmp(username, customers[i]->getUsername() ))
			return i;
	}
	return NOT_FOUND;
}

int E_Commerce::findSeller(const char* username) const
{

	for (unsigned int i = 0; i < currentNumOfSellers; ++i) {
		if (!strcmp(username, sellers[i]->getUserName()))
			return i;
	}
	return NOT_FOUND;
}
void E_Commerce::emptySellers() 
{

	for (unsigned int i = 0; i < currentNumOfSellers; ++i)
		delete sellers[i];
	delete[] sellers;
	currentNumOfSellers = 0;
}
E_Commerce::~E_Commerce()
{
	emptyCustomers();
	emptySellers();
}