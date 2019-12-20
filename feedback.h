#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "Date.h"
#include "Product.h"


class Customer;

class Feedback 
{
	private:
		Customer * pCustomer; // A pointer to the customer that wrote the feedback
		char * feedback;	  // a string represents a feedback 
		Product * pProduct;	  // A pointer to the relevant product
		Date dateWritten;

	 public:

		 Feedback(Customer* pCustomer, char * feedback, Product * pProduct,
			 unsigned int* day, unsigned int* month, unsigned int* year); // Default c'tor
		Feedback(const Feedback & other);								  // copy c'tor
		Feedback(Feedback && other);									  // move c'tor
		~Feedback();													  // d'tor
    
     public:

		void setCustomer(Customer* pCustomer) 
			{ this->pCustomer = pCustomer; }; 
		inline Customer* getPCustomer()		  
			{ return this->pCustomer; };
		inline char * getFeedback()           
			{ return this->feedback; };
		void setProduct(Product* pProduct)    
			{ this->pProduct= pProduct; };
		inline Product* getPProduct() 
			{ return this->pProduct; };
		inline Date getDate() 
			{ return this->dateWritten; };
		void setFeedback(char* feedback);
		void print() const;
		
     public:

		// Helpers for input 
		bool getString(char* str, int maxSize);
		void cleanBuffer();
		
};


#endif
