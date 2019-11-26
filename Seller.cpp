#include "Seller.h"

Seller::Seller(const char* name, const char* password, const char* countryName, const char* cityName, const char* streetName,
	int houseNumber): address(countryName, cityName, streetName, houseNumber) // Using init line for initializing the address- reducing potential excessive copy c'tor calls
{
	this->name = nullptr;
	this->password = nullptr;
	setName(name);
	setPassword(password);
}
Seller:: ~Seller()
{
	delete[] this->name;
	delete[] this->password;

}
bool Seller::setName(const char * name)
{
	delete[] this->name;
	this->name = strdup(name);
}
void Seller:: setPassword(const char* password)
{
	delete[] this->password;
	this->password = strdup(password);
}
void Seller:: print() const
{
	cout << "Name: " << this->getName << endl;
	cout << "Password: " << this->getPassword << endl;
	this->address.print();
}