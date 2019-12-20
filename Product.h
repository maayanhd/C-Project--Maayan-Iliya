#ifndef __PRODUCT_H
#define __PRODUCT_H
#pragma warning (disable:4996)

#include <iostream>
#include <string.h>
using namespace std;
 
class Seller; 
class Feedback;

const char * const categoryName [] = { "Children", "Electricity", "Clothing", "OfficeSupply" };
const enum Category					 { CHILDREN = 0 ,  ELECTRICITY,  CLOTHING,  OFFICESUPPLY };

class Product
{
	public:

		Product(const char* prodName, float price, 
			Category ctg ,Seller* seller);		// c'tor
		Product(const Product&);				// copy c'tor
		Product(Product&&);						// move c'tor
		~Product();								// d'tor

	public:
		inline char* getName()											const 
			{ return name; };
		inline unsigned int getSerialNumber()							const 
			{ return serial_number; };
		inline Seller * getSeller() 
			{ return this->pSeller; };
		inline Category getCategory()									const		
			{ return ctg; };											
		inline float getPrice()											const 
			{ return price; };											
		bool setPrice(float price);										
		void setCategory(Category ctg);									
		void setName(const char* name);									
		void print()													const;
		void printFeedbacks()											const;
		void addFeedback(Feedback* feedback);

	private:
		static int counter;			// Keeps counting added products (in the entire system)
		char* name;
		float price;				// in NIS
		unsigned int serial_number; // Only using a common counter to produce the serial numbers 
		Category ctg;

		Seller * pSeller;			// Pointer to the seller of this product 
		Feedback** feedbacks;		// Array of pointers to feedbacks of this product
		int numOfFeedbacks;
	};


#endif