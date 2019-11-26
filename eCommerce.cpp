#include "eCommerce.h"
Customer** reallocCustomersArr(Customer** customers, unsigned int& updatedNumOfCustomers, unsigned int& currentNumOfCustomers)
{
	Customer** updatedCustomers= new Customer*[updatedNumOfCustomers]; 
	for (int i=0; i<currentNumOfCustomers; i++)
	{
		updatedCustomers[i] = customers[i]; // Shallow copying of pointers 
	}	
	updatedCustomers[updatedNumOfCustomers - 1] = nullptr;
}
Seller** reallocSellersArr(Seller** sellers, unsigned int& updatedNumOfSellers, unsigned int& currentNumOfSellers)
{
	Seller** updatedSellers = new Seller*[updatedNumOfSellers];
	for (int i = 0; i < currentNumOfSellers; i++)
	{
		updatedSellers[i] = sellers[i]; // Shallow copying of pointers 
	}
	updatedSellers[updatedNumOfSellers-1] = nullptr; 
}

E_Commerce::E_Commerce(const char * name, Customer** customers, unsigned int currentCustomers, Seller** sellers, unsigned int currentSellers)
	:currentCustomers(0) , currentNumOfSellers(0)
{
	name = strdup("Iliya & Ma'ayan eCommerce System");
	customers = nullptr; sellers = nullptr;
}
E_Commerce(const E_Commerce&) = delete; // No logic reason for copying the fields of the eCommerce 
~E_Commerce(); // d'tor 
