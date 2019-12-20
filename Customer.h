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
	void setUsername(const char* username);
	void setPassword(const char* password);
	inline const char* getUsername() const { return username; };
	inline const char* getPassword() const { return password; };
	void print() const;
	void order() const;
	void addFeedback();
	bool optionIsValid(int option) const ;
	void leaveFeedback(int maxSize, char * feedback);
	inline ShoppingCart& getCart() { return sCart; };
	inline PurchaseHistory& getpHistory(){ return history; } ;

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