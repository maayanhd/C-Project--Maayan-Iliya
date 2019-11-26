#include "eCommerce.h"

Customer** reallocCustomersArr(Customer** customers, unsigned int& updatedNumOfCustomers, unsigned int& currentNumOfCustomers)
{ // Sending the address of the array of pointers to class objects to release it after allocating the new array by the updated size
	Customer** updatedCustomers= new Customer*[updatedNumOfCustomers]; 
	for (int i=0; i<currentNumOfCustomers; i++)
	{
		updatedCustomers[i] = (*customers)[i]; // Shallow copying of pointers 
	}	
	updatedCustomers[updatedNumOfCustomers - 1] = nullptr;
	delete [] * (customers); // Deleting the old array - its elements have been used in the updated array

}
Seller** reallocSellersArr(Seller** sellers, unsigned int& updatedNumOfSellers, unsigned int& currentNumOfSellers)
{// Sending the address of the array of pointers to class objects to release it after allocating the new array by the updated size
	Seller** updatedSellers = new Seller*[updatedNumOfSellers];
	for (int i = 0; i < currentNumOfSellers; i++)
	{
		updatedSellers[i] = (*sellers)[i]; // Shallow copying of pointers 
	}
	updatedSellers[updatedNumOfSellers-1] = nullptr; 
	delete[] * (sellers); // Deleting the old array - its elements have been used in the updated array
}

E_Commerce::E_Commerce(const char * name, Customer** customers, unsigned int currentCustomers, Seller** sellers, unsigned int currentSellers)
: customers(nullptr), currentNumOfCustomers(currentCustomers=0),sellers(nullptr), currentNumOfSellers(currentSellers=0)
{
	name = strdup("Iliya & Ma'ayan eCommerce System");
	customers = nullptr; sellers = nullptr;
}

E_Commerce::~E_Commerce()
{
	// Assuming the custmers' and sellers' arrays aren't empty, and been used at least once during the program 
	// Assuming the pointers of the arrays' elements were released by the class that allocated those pointers 
	delete[] customers;
	delete[] sellers;
}