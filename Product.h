#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <string.h>
#include <iostream>
#include "AuxMethods.h"
#include "feedback.h"

using namespace std;
#pragma warning(disable: 4996)

class Seller; 
class Feedback;

const char * const categoryName [] = { "Children", "Electricity", "Clothing", "OfficeSupply" };
const enum Category { CHILDREN = 0, ELECTRICITY, CLOTHING, OFFICESUPPLY };

//class Feedback;

class Product
{
public:

	
	Product(const char* prodName, float price, const char * serial_number, Category ctg); // c'tor
	Product(const Product&); // copy c'tor
	Product(Product&&); // move c'tor
	~Product();

public:
	inline char* getName() const { return name; };
	//inline const char* getSerialNumber() const { return serial_number; };
	inline int getSerialNumber() const { return serial_number; };

	inline Category getCategory() const { return ctg; };
	inline float getPrice() const { return price; };
	bool setPrice(float price);
	void setCategory(Category ctg);
	void setName(const char* name);
	//bool setSerialNumber(const char* serialNum);
	void print()														const;

private:
	static int counter; // Keeps counting added products (in the entire system)
	//static constexpr int MAX_SIZE_SERIAL_NUM = 6;
	char* name;
	float price; // in NIS
	//const char serial_number[MAX_SIZE_SERIAL_NUM]; // 1 Letter indicates the type of product and 4 digits for the number of product added
	unsigned int serial_number; // Only using a common counter to produce the serial numbers 
	Category ctg;
	Feedback * feedback;
	Seller * pSeller; // Pointing to the seller of the product
};

#endif