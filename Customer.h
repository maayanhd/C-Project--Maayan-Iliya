#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include "User.h"
#include "Address.h"
#include "ShoppingCart.h"
#include "PurchaseHistory.h"

class Customer : virtual public User
{
public: 

	Customer(const char* username, const char* password,const char* countryName, 
		const char* cityName, const char* streetName, const int* house); // default c'tor
	Customer(const Customer&) = delete;									 // copy c'tor 
	virtual ~Customer();														 // d'tor

public:
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

	public:
		virtual void toOs(ostream& os) const;

	protected:
		static constexpr int MAX_LENGTH = 21;
		ShoppingCart sCart;
		PurchaseHistory history;
};

#endif