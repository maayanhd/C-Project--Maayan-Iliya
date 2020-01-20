#ifndef __PRODUCT_H
#define __PRODUCT_H
#pragma warning (disable:4996)

#include <iostream>
#include "Array.h"
#include <vector>
#include <string>
using namespace std;

 
class Seller; 
class Feedback;

const char * const categoryName [] = { "Children", "Electricity", "Clothing", "OfficeSupply" };
const enum Category					 { CHILDREN = 0 ,  ELECTRICITY,  CLOTHING,  OFFICESUPPLY };

class Product
{
	public:

		Product(const string& prodName, float price,
			Category ctg ,Seller& mySeller);		// c'tor
		Product(const Product&);				// copy c'tor
		Product(Product&&);						// move c'tor
		~Product();								// d'tor

	public:
		inline const string& getName()											const
			{ return name; };
		inline unsigned int getSerialNumber()							const 
			{ return serial_number; };
		inline Seller & getSeller() 
			{ return seller; };
		inline Category getCategory()									const		
			{ return ctg; };											
		inline float getPrice()											const 
			{ return price; };											
		bool setPrice(float price);										
		void setCategory(Category ctg);									
		void setName(const string& name);
		void addFeedback(Feedback* feedback);

	public:
		friend ostream& operator<<(ostream& os, const Product& product);
		bool operator== (const Product& product);

	private:
		static int counter;			// Keeps counting added products (in the entire system)
		string name;
		float price;				// in NIS
		unsigned int serial_number; // Only using a common counter to produce the serial numbers 
		Category ctg;

		Seller & seller;			// ref to the seller of this product 
		vector <Feedback*> feedbacks;		// Array of pointers to feedbacks of this product
	};


#endif