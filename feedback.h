//#ifndef __FEEDBACK_H
//#define __FEEDBACK_H

#pragma once // ifndef isn't working well 

#include "Date.h"
#include "Customer.h"

class Seller;
class Product;
class Customer;
class E_Commerce;

class Feedback 
{
	private:
		Customer * pCustomer; // A pointer to the customer that wrote the feedback
		Seller * pSeller; // A pointer to seller 
		char * feedback; // a string represents a feedback 
		Product * pProduct; // A pointer to the relevant product
		Date dateWritten;
		static const enum strtype { LETTERS = 0, MIXED };

	public:
		Feedback(Customer* pCustomer, Seller * pSeller, char * feedback, Product * pProduct, 
			unsigned int* day, unsigned int* month, unsigned int* year); // Default c'tor
		Feedback(const Feedback & other); // copy c'tor
		Feedback(Feedback && other); // move c'tor

		void setCustomer(Customer* pCustomer) { this->pCustomer = pCustomer; }; 
		inline Customer* getPCustomer() { return this->pCustomer; };
		void setSeller(Seller * pSeller) { this->pSeller = pSeller; };
		inline Seller* getPSeller() { return this->pSeller; };
		bool setFeedback(strtype type, char* feedback); 
		inline char * getFeedback() { return this->feedback; };
		void setProduct(Product* pProduct) { this->pProduct= pProduct; };
		inline Product* getPProduct() { return this->pProduct; };
		inline Date getDate() { return this->dateWritten; };
		~Feedback(); // d'tor
};
//#endif