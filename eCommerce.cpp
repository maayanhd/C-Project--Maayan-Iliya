#include "eCommerce.h"


Customer** E_Commerce:: changeCustomersArrSize(unsigned int newSize)
{ // Sending the address of the array of pointers to class objects to release it after allocating the new array by the updated size
	Customer** updatedCustomers= new Customer*[currentNumOfCustomers+newSize]; 
	for (int i=0; i<currentNumOfCustomers; i++)
	{
		updatedCustomers[i] =customers[i]; // Shallow copying of pointers 
	}	
	return updatedCustomers;
}

bool E_Commerce::onlyLetters(const char* str)const {

	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (!((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A'))) {
			return false;
		}
	}
	return true;

}

char* E_Commerce:: input(strtype type, int maxSize) {
	bool valid = false;
	char* res;
	int len;
	while (!valid) {
		valid = getString(res, maxSize);
		if (type == LETTERS) {
			valid = onlyLetters(res);
			if (!valid)
				delete[] res;
		}
	}
	
	return res;
}
Customer* E_Commerce::newCustomer() {
	char* username, *password, *country, *city, *street;
	int house[2];
	
	username = input(MIXED, MAX_LENGTH);
	password = input(MIXED, MAX_LENGTH);
	country = input(LETTERS, MAX_LENGTH);
	city = input(LETTERS, MAX_LENGTH);
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
	Customer* res = new Customer(username, password, country, city, street, house);
	return res;
}

Seller* E_Commerce::newSeller() {

	char* username, *password, *country, *city, *street;
	int house[2];

	username = input(MIXED, MAX_LENGTH);
	password = input(MIXED, MAX_LENGTH);
	country = input(LETTERS, MAX_LENGTH);
	city = input(LETTERS, MAX_LENGTH);
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
	return res;
}
void E_Commerce::addCustomer() {
	Customer** newCustomerArr;
	Customer* res = newCustomer();
	newCustomerArr = changeCustomersArrSize(++currentNumOfCustomers);
	newCustomerArr[currentNumOfCustomers - 1] = res;
	delete[] customers;
	customers = newCustomerArr;
} 

void E_Commerce::addSeller() {

	Seller** newSellersArr;
	Seller* res = newSeller();
	newSellersArr = changeSellersArrSize(++currentNumOfSellers);
	newSellersArr[currentNumOfSellers - 1] = res;
	delete[] sellers;
	sellers = newSellersArr;

}

Seller** E_Commerce::changeSellersArrSize(unsigned int newSize)
{ // Sending the address of the array of pointers to class objects to release it after allocating the new array by the updated size
	Seller** updatedSellers = new Seller*[currentNumOfSellers + newSize];
	for (int i = 0; i < currentNumOfCustomers; i++)
		updatedSellers[i] = sellers[i]; // Shallow copying of pointers 
	return updatedSellers;
}
void E_Commerce :: setNumOfCustomers(int num) {
	if(num>=0)
	currentNumOfCustomers = num;
}
void E_Commerce::setNumOfSellers(int num) {
	if(num>=0)
	currentNumOfSellers = num;
}
E_Commerce::E_Commerce()
{
	setNumOfCustomers(0);
	setNumOfSellers(0);
	customers = nullptr; sellers = nullptr;
}

void E_Commerce::removeCustomer(const char * username) {
	Customer** newCustomersArr;
	int i = findCustomer(username);
	if (i != NOT_FOUND)
	{
		delete customers[i];
		customers[i] = customers[currentNumOfCustomers - 1];
		newCustomersArr = changeCustomersArrSize(--currentNumOfCustomers);
		delete[] customers;
		customers = newCustomersArr;
	}

}

bool E_Commerce::getString(char* str, int maxSize) {

	char* res = new char[maxSize];
	cin.getline(res, maxSize);
	if (cin.fail())
	{
		cin.clear();
		cleanBuffer();
		delete[] res;
		return false;
	}
	else {
		str = res;
		return true;
	}
}

void E_Commerce::cleanBuffer() {
	
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

void E_Commerce::removeSeller(const char * username) {
	Seller** newSellersArr;
	int i = findSeller(username);
	if (i != NOT_FOUND)
	{
		delete sellers[i];
		sellers[i] = sellers[currentNumOfCustomers - 1];
		newSellersArr = changeSellersArrSize(--currentNumOfSellers);
		delete[] sellers;
		sellers = newSellersArr;;
	}
}

void E_Commerce::emptyCustomers() {

	for (int i = 0; i < currentNumOfCustomers; ++i)
		delete customers[i];
	delete[] customers;
	currentNumOfCustomers = 0;
}
int E_Commerce::findCustomer(const char* username) const {

	for (int i = 0; i < currentNumOfCustomers; ++i) {
		if (!strcmp(username, customers[i]->getUsername))
			return i;
	}
	cout << "This username wasn't found" << endl;
	return NOT_FOUND;
}

int E_Commerce::findSeller(const char* username) const{

	for (int i = 0; i < currentNumOfSellers; ++i) {
		if (!strcmp(username, sellers[i]->getName))
			return i;
	}
	cout << "This username wasn't found" << endl;
	return NOT_FOUND;
}
void E_Commerce::emptySellers() {

	for (int i = 0; i < currentNumOfSellers; ++i)
		delete sellers[i];
	delete[] sellers;
	currentNumOfSellers = 0;
}
E_Commerce::~E_Commerce()
{
	emptyCustomers();
	emptySellers();
}