#pragma warning (disable:4996)
#include <iostream>
#include <string.h>
#include "Address.h"
using namespace std;


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

bool Address::IsValid(const char* str) {

	int len = strlen(str);
	if (len > MAX_LENGTH) {
		cout << "This field cannot contain more than 20 characters" << endl;
		return false;
	}
	for (int i = 0; i < len; ++i) {
		if (!((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A')) && str[i] != ' ') {
			cout << "Your input contains illegal characters" << endl;
			return false;
		}
	}
	return true;

}
bool Address::setCountry(const char*countryName)
{
	if (!IsValid(countryName))
		return false;
	delete[] country;
	country = strdup(countryName);
	return true;
}
bool Address:: setCity(const char*cityName)
{

	if (!IsValid(cityName))
		return false;
	delete[] this->city;
	this->city = strdup(cityName);
	return true;
}

bool Address :: setStreet(const char* streetName) {

	if (strlen(streetName) > MAX_LENGTH)
	{
		cout << "This field cannot contain more than 20 characters" << endl;
		return false;
	}
	delete[] street;
	street = strdup(streetName);
	return true;
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