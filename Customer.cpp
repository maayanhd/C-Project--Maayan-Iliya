#include "Customer.h"

Customer::Customer(const char* name, const char* password,const char* countryName, const char* cityName, const char* streetName, const int* house)
	:adress(countryName,cityName,streetName,house){

	setName(name);
	setPassword(password);
};

Customer::~Customer() {
	delete[] this->name;
	delete[] this->password;
	sCart.~ShoppingCart(); 
}  

bool Customer::setName(const char* name) {
	if (!onlyLetters(name))
	{
		cout << "The name must contain letters only" << endl;
		return false;
	}
	delete[] this->name;
	this->name = strdup(name);
	return true; // must check the name in the future
};
void Customer::setPassword(const char* password) {
	delete[] this->password;
	this->password = strdup(password);
};

void Customer:: print() {
	cout << "Name: " << name << endl;
	cout << "Password: " << password << endl;
	this->adress.print();
}