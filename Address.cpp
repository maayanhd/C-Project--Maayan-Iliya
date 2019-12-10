#include "Address.h"

Address::Address(const char* countryName, const char* cityName, const char* streetName,const int* house) {
	setCountry(countryName);
	setCity(cityName);
	setStreet(streetName);
	setHouseInfo(house);
}

Address::Address(const Address& other) {
	setCountry(other.country);
	setCity(other.city);
	setStreet(other.street);
	setHouseInfo(house);
}

Address::Address(Address && other) {
	this->country = other.country;
	this->city = other.city;
	this->street = other.street;
	setHouseInfo(other.house);
	other.country = nullptr;
	other.city = nullptr;
	other.street = nullptr;
}

Address ::~Address() {
	delete[] country;
	delete[] city;
	delete[] street;
}

bool Address::setCountry(const char*countryName)
{
	if (!onlyLetters(countryName)) {
		
		cout << "The name of country must contain letters only" << endl;
		return false;
	}
	delete[] country;
	country = strdup(countryName);
	return true;
}
bool Address:: setCity(const char*cityName)
{
	if (!onlyLetters(cityName)) {
		cout << "The name of the city must contain letters only" << endl;
		return false;
	}
	delete[] this->city;
	this->city = strdup(cityName);
	return true;
}

void Address :: setStreet(const char* streetName) {

	delete[] street;
	street = strdup(streetName);
}
bool Address::setHouseInfo(const int* house) {
	if (house[houseNumInd] <= 0 || house[entranceInd] <= 0) {
		cout << "Oops! It must be a positive value" << endl;
		return false;
	}
	this->house[houseNumInd] = house[houseNumInd];
	this->house[entranceInd] = house[entranceInd];
	return true;
}

void Address :: print() const {
	cout << "Address: " << street << " " << house[houseNumInd] << "/" << house[entranceInd];
	cout <<", " << city << ", " << country << endl;
	
}