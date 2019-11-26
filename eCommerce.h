#ifndef __E_COMMERCE_H
#define __E_COMMERCE_H
#include "Customer.h"
#include "Seller.h"

// Responsible to reallocate the arrays - will be used for adding/removing sellers/customers  - 
// defined as arrays of pointers to class objects to avoid the need for default constructor- which will not 
// be recommended logically

class E_Commerce
{
	public:
		E_Commerce(const char * name, Customer** customers, unsigned int currentCustomers, Seller** sellers, unsigned int currentSellers);
		E_Commerce(const E_Commerce&) = delete; // No logic reason for copying the fields of the eCommerce 
		// Logically the e-commerce system does not suppose to 'distract it self' - but we must deallocate the memory allocated during the program 
		~E_Commerce(); 

	public:
		Customer** reallocCustomersArr(Customer** costumers, unsigned int& updatedNumOfCustomers, unsigned int& currentNumOfCustomers);
		Seller** reallocSellersArr(Seller** sellers, unsigned int& updatedNumOfSellers, unsigned int& currentNumOfSellers);
		const char * getName() const { return this->name; };
		unsigned int getNumOfCustomers() const { return this->currentNumOfCustomers; };
		unsigned int getNumOfSellers() const { return this->currentNumOfSellers; };
		
	private:
		char * name; 
		Customer** customers; // Array of Costumers objects 
		unsigned int currentNumOfCustomers; 
		Seller** sellers; // Array of Costumers objects 	
		unsigned int currentNumOfSellers;

};


#endif

