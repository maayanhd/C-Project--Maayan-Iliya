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
		E_Commerce();
		E_Commerce(const E_Commerce&) = delete; // No logic reason for copying the fields of the eCommerce 
		// Logically the e-commerce system does not suppose to 'distract it self' - but we must deallocate the memory allocated during the program 
		~E_Commerce(); 
		friend class Feedback; // not working 
		                                                                         
	private:
		Customer** customers; // Array of Costumers objects 
		unsigned int currentNumOfCustomers;
		Seller** sellers; // Array of Costumers objects 	
		unsigned int currentNumOfSellers;


		static const enum strtype { LETTERS = 0, MIXED };
		static constexpr int MAX_LENGTH = 21;
	public:
		Customer** changeCustomersArrSize(unsigned int newSize);
		Seller** changeSellersArrSize(unsigned int newSize);
		unsigned int getNumOfCustomers() const { return this->currentNumOfCustomers; };
		unsigned int getNumOfSellers() const { return this->currentNumOfSellers; };
		void setNumOfCustomers(int num);
		void setNumOfSellers(int num);
		void addCustomer();
		void addSeller();
		Customer* createCustomer();
		Seller* createSeller();
		void removeCustomer(const char* username);
		void removeSeller(const char* username);
		void emptyCustomers();
		void emptySellers();
		friend bool input(strtype type,char* str); // a Global function for input check
		char* getData(strtype type);
	
};


#endif

