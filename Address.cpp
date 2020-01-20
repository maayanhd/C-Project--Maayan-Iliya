#include "Address.h"


Address::Address(const string& countryName, const string& cityName, const string& streetName,const int* house)
{

	setCountry(countryName);
	setCity(cityName);
	setStreet(streetName);
	setHouseInfo(house);
}


Address ::~Address() 
{
}

void Address::setCountry(const string&countryName)
{
	
	country = countryName;

}
void Address:: setCity(const string& cityName)
{
	city = cityName;
}

void Address :: setStreet(const string& streetName)
{
	street = streetName;
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