#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <string.h>
#include <iostream>
#include "AuxMethods.h"
using namespace std;

#pragma warning(disable: 4996)
const char * const categoryName [] = { "Children", "Electricity", "Clothing", "OfficeSupply" };
const enum Category { CHILDREN = 0, ELECTRICITY, CLOTHING, OFFICESUPPLY };

class Product
{
public:

	
	Product(const char* prodName, float price, const char * serial_number, Category ctg); // c'tor
	Product(const Product&); // copy c'tor
	Product(Product&&); // move c'tor
	~Product();

public:
	inline char* getName() const { return name; };
	inline const char* getSerialNumber() const { return serial_number; };
	inline Category getCategory() const { return ctg; };
	inline float getPrice() const { return price; };
	bool setPrice(float price);
	void setCategory(Category ctg);
	void setName(const char* name);
	bool setSerialNumber(const char* serialNum);
	void print();
private:
	
	char* name;
	float price; // in NIS
	const char* serial_number; // 5 letters length
	Category ctg;
};

#endif