#include "Customer.h"

Customer::Customer(const char* name, const char* password,const char* countryName, const char* cityName, const char* streetName, const int* house)
	:adress(countryName,cityName,streetName,house), sCart(&this){
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
bool Customer::setPassword(const char* password) {
	delete[] this->password;
	if (strlen(password) >= 20)
	{
		cout << "The password is too long" << endl;
		return false;
	}
	strcpy(this->password, password);
};

void Customer::Order() {

	int totalPrice = 0;
	cout<< "Customer details"
}

void Customer:: print() {
	cout << "Name: " << name << endl;
	cout << "Password: " << password << endl;
	this->adress.print();
}