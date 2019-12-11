#include "eCommerce.h"

const enum E_Commerce:: strtype;
constexpr int E_Commerce::MAX_LENGTH = 21;

Customer** E_Commerce:: changeCustomersArrSize(unsigned int newSize)
{ // Sending the address of the array of pointers to class objects to release it after allocating the new array by the updated size
	Customer** updatedCustomers= new Customer*[currentNumOfCustomers+newSize]; 
	for (int i=0; i<currentNumOfCustomers; i++)
	{
		updatedCustomers[i] =customers[i]; // Shallow copying of pointers 
	}	
	return updatedCustomers;
}

char* E_Commerce::getData(strtype type) {
	char* res;
	bool valid = false;
	while (!valid) {
		valid = (type, res);
	}
	return res;
}
void E_Commerce::addCustomer() {
	Customer** newCustomerArr;
	char* username,*password, *country,*city, *street;
	int house[2];
	username = getData(MIXED);
	password = getData(MIXED);
	country = getData(LETTERS);
	city = getData(LETTERS);
	street = getData(MIXED);
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
	newCustomerArr = changeCustomersArrSize(++currentNumOfCustomers);
	newCustomerArr[currentNumOfCustomers - 1] = res;
	customers = newCustomerArr;
	delete[] customers;
	delete[] username;
	delete[] password;
	delete[] country;
	delete[] city;
	delete[] street;
} 



Seller** E_Commerce::changeSellersArrSize(unsigned int newSize)
{ // Sending the address of the array of pointers to class objects to release it after allocating the new array by the updated size
	Seller** updatedSellers = new Seller*[currentNumOfSellers + newSize];
	for (int i = 0; i < currentNumOfCustomers; i++)
	{
		updatedSellers[i] = sellers[i]; // Shallow copying of pointers 
	}
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
	bool found = false;
	Customer** newCustomersArr;
	for (int i = 0; i < currentNumOfCustomers && !found; ++i) {

		if (strcmp(customers[i]->getUsername, username) == 0)
		{
			delete customers[i]; // delete seller
			customers[i] = customers[currentNumOfCustomers - 1]; // put the last seller ptr in this place
			newCustomersArr = changeCustomersArrSize(--currentNumOfCustomers); // make new arr with the new size
			delete[] customers;// remove only the arr, the content of the arr still exists
			customers = newCustomersArr;
			found = true;
		}
	}
	if (!found)
		cout << "This username was not found" << endl;


}

void E_Commerce::removeSeller(const char * username) {
	bool found = false;
	Seller** newSellersArr;
	for (int i = 0; i < currentNumOfSellers && !found; ++i) {

		if (strcmp(sellers[i]->getName, username) == 0)
		{
			delete sellers[i]; // delete seller
			sellers[i] = sellers[currentNumOfSellers - 1]; // put the last seller ptr in this place
			newSellersArr = changeSellersArrSize(--currentNumOfSellers); // make new arr with the new size
			delete[] sellers; // remove only the arr, the content of the arr still exists
			sellers = newSellersArr;
			found = true;
		}
	}

	if (!found)
		cout << "This username was not found" << endl;
}

bool input(E_Commerce:: strtype type, char* feedback) // Will be inside eCommerce class 
{
	char ch;
	int phySize = 5, logicSize = 0;
	bool isValid = true; // Flag notices whether the input is valid or not 
	bool isTemp = false; // A flag notices whether the current string is temp or feedback string
	feedback = new char[phySize]; // Allocating with initial size 
	char * tempStr;
	
	cleanBuffer(); // Need to be implemented

	while ((ch = getchar()) != '\n' && isValid)
	{
		if (logicSize == phySize)
		{
			phySize *= 2;
			;
			for (int i = 0; i < logicSize; ++i)
			{
				if (isTemp) {
					feedback= new char[phySize + 1];
					feedback[i] = tempStr[i];
					delete[] tempStr;
				}
				else {
					tempStr= new char[phySize + 1];
					tempStr[i] = feedback[i];
					delete[] feedback;
				}			
		}
		switch (type) {
			case E_Commerce::LETTERS: // only letters
				((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) ? isValid = true : isValid = false;
				break;

			case E_Commerce::MIXED: // no restrictions of input of characters 
				break;
		}
		if (isValid) {
			isTemp ? tempStr[logicSize++] = ch : feedback[logicSize++] = ch; // Inserting the character to the array of characters 
		}
		if (logicSize > E_Commerce::MAX_LENGTH){ // Checking length restriction
			isValid = false;
			isTemp ? delete[] tempStr : delete[] feedback;
		}
	}
		if (isValid)
			isTemp ? tempStr[logicSize] = '\0' : feedback[logicSize] = '\0';
		return isValid;
}
void E_Commerce::emptyCustomers() {

	for (int i = 0; i < currentNumOfCustomers; ++i)
		delete customers[i];
	delete[] customers;
	currentNumOfCustomers = 0;
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