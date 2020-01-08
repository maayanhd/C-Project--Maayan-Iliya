#ifndef __ADDRESS_H
#define __ADDRESS_H
#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>
using namespace std;

class Address
{
public:
	Address(const char* countryName, const char* cityName,
		const char* streetName, const int* house); // default c'tor
	Address(const Address&);					  // copy c'tor
	Address(Address&&);							  // move c'tor
	~Address();									  // d'tor


public:
	void setCountry(const char* countryName);
	void setCity(const char* cityName);
	void setStreet(const char* streetName);
	void setHouseInfo(const int* house);
	inline const char* getCountryName()						const
	{
		return country;
	};
	inline const char* getCityName()						const
	{
		return city;
	};
	inline const char* getStreetName()						const
	{
		return street;
	};
	inline const int* getHouseInfo()						const
	{
		return house;
	};
	void print()											const;

private:
	char* country; // country name
	char* city;	   // The name of the city
	char* street;  // The name of the street
	int house[2];  // The house and entrance numbers

	static constexpr int houseNumInd = 0;
	static constexpr int entranceInd = 1;
	static constexpr int MAX_LENGTH = 20;
};


#endif