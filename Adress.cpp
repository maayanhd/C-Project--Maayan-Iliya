#include "Adress.h"

Adress::Adress(const char* countryName, const char* cityName, const char* streetName,const int* house) {
	setCountry(countryName);
	setCity(cityName);
	setStreet(streetName);
	setHouseInfo(house);
}

Adress::Adress(const Adress& other) {
	setCountry(other.country);
	setCity(other.city);
	setStreet(other.street);
	setHouseInfo(house);
}

Adress::Adress(Adress && other) {
	this->country = other.country;
	this->city = other.city;
	this->street = other.street;
	setHouseInfo(other.house);
	other.country = nullptr;
	other.city = nullptr;
	other.street = nullptr;
}

Adress ::~Adress() {
	delete[] country;
	delete[] city;
	delete[] street;
}

bool Adress::setCountry(const char*countryName)
{
	if (!onlyLetters(countryName)) {
		
		cout << "The name of country must contain letters only" << endl;
		return false;
	}
	delete[] country;
	country = strdup(countryName);
	return true;
}
bool Adress:: setCity(const char*cityName)
{
	if (!onlyLetters(cityName)) {
		cout << "The name of the city must contain letters only" << endl;
		return false;
	}
	delete[] this->city;
	this->city = strdup(cityName);
	return true;
}

void Adress :: setStreet(const char* streetName) {

	delete[] street;
	street = strdup(streetName);
}
bool Adress::setHouseInfo(const int* house) {
	if (house[houseNumInd] <= 0 || house[entranceInd] <= 0) {
		cout << "Oops! It must be a positive value" << endl;
		return false;
	}
	this->house[houseNumInd] = house[houseNumInd];
	this->house[entranceInd] = house[entranceInd];
	return true;
}

void Adress :: print() const {
	cout << "Adress: " << street << " " << house[houseNumInd] << "/" << house[entranceInd];
	cout <<", " << city << ", " << country << endl;
	
}