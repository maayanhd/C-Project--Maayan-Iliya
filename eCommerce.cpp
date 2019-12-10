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