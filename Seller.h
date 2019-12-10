#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
#include "Address.h"

#include "feedback.h"
using namespace std;

class Product;
class Feedback;

class Seller
{	
	public: 
		Seller(const char* name, const char* password, const char* countryName, const char* cityName, const char* streetName,
			int* houseNumber);
		Seller(const Seller &) = delete; // copy c'tor for use of the allocating 
		~Seller(); // d'tor
		
	public: 
		inline const char * getName() const { return name; };
		inline const char * getPassword() const { return password; };
		bool setName(const char * name);
		void setPassword(const char* password);				
		void print()										   const; 

	private: 
		char * name; // Name of Seller 
		char* password; // Password of The seller for logging into the system
		Address address; // The Address of the seller
		Product **  availableProducts; // Preparation of array of pointers to products available for sale- no supply management
		int numOfProducts; // Number of products available 
		Feedback ** feedbacks; // Array of pointers to feedbacks of customers on the seller's products 
		int numOfFeedbacks; // Number of given feedbacks to sellers 

};

#endif