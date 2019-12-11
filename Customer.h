#pragma once
#include "Address.h"
#include "PurchaseHistory.h"

class ShoppingCart;
class Customer {

public:
	/* The idea of receiving the cityName etc and not the address object is to avoid unenecessary calls of copy constructor,
	and overall it seems to me more logical */
	/*The constructor */
	Customer(const char* username, const char* password,const char* countryName, const char* cityName, const char* streetName, const int* house);
	Customer(const Customer&) = delete; // copy c'tor 

	~Customer();

public:
	bool setUsername(const char* username);
	bool setPassword(const char* password);
	inline const char* getUsername() const { return username; };
	inline const char* getPassword() const { return password; };
	void print();
	void order();
	void watchPurchaseHistory();
private:

	char* username;
	char* password;
	Address address;
	ShoppingCart sCart;
	PurchaseHistory history;

};

