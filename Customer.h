#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include "Address.h"
#include "ShoppingCart.h"
#include "PurchaseHistory.h"

class Customer {

public:

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
	void addFeedback();
	bool optionIsValid(int option);
	void leaveFeedback(int maxSize, char * feedback);
	void printPurchasedProducts(Product** purchasedProducts) const;
	inline ShoppingCart& getCart() { return sCart; };
	inline PurchaseHistory& getpHistory() { return history; };

	// Helpers for input 
public:
	void getValidDate(unsigned int *day, unsigned int * month, unsigned int * year);
	bool dateIsValid(unsigned int *day, unsigned int * month, unsigned int * year, Date* dateAccess);
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

#endif