#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include "User.h"
#include "ShoppingCart.h"
#include "PurchaseHistory.h"

class Customer : virtual public User
{
public: 

	Customer(const string& username, const string& password, Address address); // default c'tor
	Customer(const Customer& other);									   // copy c'tor 
	Customer(Customer&& other);											   // move c'tor
	virtual ~Customer();											       // virtual d'	tor

public:
	bool operator>(const Customer& other) const ;
public:
	void order() const;
	void addFeedback();
	bool optionIsValid(unsigned int option) const ;
	void leaveFeedback(string& feedback);
	inline ShoppingCart& getCart() { return sCart; };
	inline PurchaseHistory& getpHistory(){ return history; };

	// Helpers for input 
	public:
		void getValidDate(unsigned int *day, unsigned int * month, unsigned int * year);
		bool dateIsValid(unsigned int *day, unsigned int * month, unsigned int * year, Date* dateAccess);

	public:
		virtual void toOs(ostream& os) const;

	protected:
		ShoppingCart sCart;
		PurchaseHistory history;
};

#endif