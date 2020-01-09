#include "Address.h"


Address::Address(const char* countryName, const char* cityName, const char* streetName,const int* house)
{

	city = street = country = nullptr;
	setCountry(countryName);
	setCity(cityName);
	setStreet(streetName);
	setHouseInfo(house);
}

Address::Address(const Address& other) 
{
	city = street = country = nullptr;
	setCountry(other.country);
	setCity(other.city);
	setStreet(other.street);
	setHouseInfo(other.house);
}

Address::Address(Address && other)
{
	this->country = other.country;
	this->city = other.city;
	this->street = other.street;
	setHouseInfo(other.house);
	other.country = nullptr;
	other.city = nullptr;
	other.street = nullptr;
	
}

Address ::~Address() 
{
	delete[] country;
	delete[] city;
	delete[] street;
}

void Address::setCountry(const char*countryName)
{
	delete[] country;
	country = _strdup(countryName);

}
void Address:: setCity(const char*cityName)
{

	delete[] this->city;
	this->city = _strdup(cityName);

}

void Address :: setStreet(const char* streetName) 
{
	delete[] street;
	street = _strdup(streetName);
}
void Address::setHouseInfo(const int* house) 
{
		this->house[houseNumInd] = house[houseNumInd];
		this->house[entranceInd] = house[entranceInd];
}

void Address :: print() const 
{
	cout << "Address: " << street << " " << house[houseNumInd] << "/" << house[entranceInd];
	cout <<", " << city << ", " << country << endl;
	
}