#pragma once

#include "Address.h"
#include "ShoppingCart.h"
#include "PurchaseHistory.h"

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
	inline float getShoppingCartTotalPrice() const { return sCart.totalPrice; };
	void print();
	void pay();
	void order();
	void addFeedback();
	bool optionIsValid(int option);
	void  leaveFeedback(int maxSize, char * feedback);
	void printPurchasedProducts(Product** purchasedProducts) const;
	void getValidDate(unsigned int *day, unsigned int * month, unsigned int * year);
	bool dateIsValid(unsigned int *day, unsigned int * month, unsigned int * year, Date* dateAccess);


	// Helpers for input 
	bool getString(char* str, int maxSize);
	void cleanBuffer();


	private:
		static constexpr int MAX_LENGTH = 21;
		char* username;
		char* password;
		Address address;
		ShoppingCart sCart;
		PurchaseHistory history;
};

