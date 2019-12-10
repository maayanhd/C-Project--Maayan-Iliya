#include "Seller.h"
#include "Product.h"
#include "feedback.h"


Seller::Seller(const char* name, const char* password, const char* countryName, const char* cityName, const char* streetName,
	int* house): address(countryName, cityName, streetName, house), availableProducts(NULL) // Using init line for initializing the address- 
{	this->name = nullptr;																   // reducing potential excessive copy c'tor calls
	this->password = nullptr;
	setName(name);
	setPassword(password);
}
Seller:: ~Seller()
{
	delete[] this->name;
	delete[] this->password;

	for (int i = 0; i < numOfProducts; ++i)
		delete this->availableProducts[i];

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