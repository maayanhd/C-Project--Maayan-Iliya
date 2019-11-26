#ifndef __ADRESS_H
#define __ADRESS_H

#include <iostream>
#include <string.h>
#include "AuxMethods.h"
using namespace std;

#pragma warning(disable: 4996)

const int houseNumInd = 0;
const int entranceInd = 1;

class Adress {
	
public: 
	Adress(const char* countryName, const char* cityName, const char* streetName,const int* house); // c'tor
	Adress(const Adress&); // copy c'tor
	Adress(Adress&&); // move c'tor
	~Adress();


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