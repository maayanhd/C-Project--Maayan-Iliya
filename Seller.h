#ifndef __SELLER_H
#define __SELLER_H

#include <iostream>
#include <string.h>
#include "Adress.h"
#include "Product.h"
using namespace std;


class Seller
{	
	public: 
		Seller(const char* name, const char* password, const char* countryName, const char* cityName, const char* streetName,
			int houseNumber);
		Seller(const Seller &); // copy c'tor for use of the allocating 
		~Seller(); // d'tor

	public: 
		inline const char * getName() const { return name; };
		inline const char * getPassword() const { return password; };
		bool setName(const char * name);
		void setPassword(const char* password);				
		void print()												const; 

	private: 
		char * name; // Name of Seller 
		char* password; // Password of The seller for logging into the system
		Adress address; // The Address of the seller
		Product *  availableProducts; // Preparation of array of products available for sale- no supply management

};

#endif