//#ifndef __FEEDBACK_H
//#define __FEEDBACK_H

#pragma once 

#include "Date.h"
#include "Customer.h"

class Seller;
class Product;
class Customer;
// *** problem recognizing the classes - looks like infinite loop of includes- yet to be covered ***//
class Feedback 
{
	public:
		Feedback(Customer* pCustomer, Seller * pSeller, char ** feedback, Product * pProduct); // Default c'tor
		Feedback(const Feedback & other); // copy c'tor
		Feedback(const Feedback && other); // move c'tor

		~Feedback(); // d'tor
			
		// need to implement set and get functions
			   		 
	private:
		Customer * pCustomer; // A pointer to the customer that wrote the feedback
		Seller * pSeller; // 
		char ** feedback; // preparation of array of strings of feedbacks
		Product * pProduct; // a pointer to the relevant product
		Date dateWritten; 
		// Default values for date 
		static constexpr unsigned int default_0 = 0;
		static constexpr unsigned int default_2 = 2;
};


//#endif