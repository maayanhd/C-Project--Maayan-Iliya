#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <iostream>
#include <string.h>
#include "AuxMethods.h"
using namespace std;

#pragma warning(disable: 4996)

const int houseNumInd = 0;
const int entranceInd = 1;

class Address {
	
public: 
	Address(const char* countryName, const char* cityName, const char* streetName,const int* house); // c'tor
	Address(const Address&); // copy c'tor
	Address(Address&&); // move c'tor
	~Address();


public: 
	bool setCountry(const char* countryName);
	bool setCity(const char* cityName);
	void setStreet(const char* streetName);
	bool setHouseInfo(const int* house);
	inline const char* getCountryName() const { return country; };
	inline const char* getCityName() const { return city; };
	inline const char* getStreetName() const { return street; };
	inline const int* getHouseInfo() const { return house;};
	void print()const;

private:
	char* country; // country name
	char* city; // The name of the city
	char* street; // The name of the street
	int house[2]; // The house and entrance numbers

};


#endif