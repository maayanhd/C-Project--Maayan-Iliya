#ifndef __ADDRESS_H
#define __ADDRESS_H
#pragma warning(disable : 4996)
#include "AuxFunctions.h"
#include "Array.h"
#include <vector>
#include <string>

class Address
{
public:
	Address(const string& countryName, const string& cityName,
		const string& streetName, const int* house); // default c'tor
	~Address();									  // d'tor


public:
	void setCountry(const string& countryName);
	void setCity(const string& cityName);
	void setStreet(const string& streetName);
	void setHouseInfo(const int* house);
	inline const string& getCountryName()						const
	{
		return country;
	};
	inline const string& getCityName()						const
	{
		return city;
	};
	inline const string& getStreetName()						const
	{
		return street;
	};
	inline const int* getHouseInfo()						const
	{
		return house;
	};
	void print()											const;

private:
	string country; // country name
	string city;	   // The name of the city
	string street;  // The name of the street
	int house[2];  // The house and entrance numbers

	static constexpr int houseNumInd = 0;
	static constexpr int entranceInd = 1;
};


#endif