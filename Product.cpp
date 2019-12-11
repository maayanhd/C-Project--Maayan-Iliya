﻿//#include "Seller.h"
//#include "feedback.h"
#include "Seller.h"


int Product::counter = 0; // counter for the serial numbers of products 
Product::Product(const char* prodName, float price, const char * serial_number, Category ctg):feedbacks(NULL) 
{
	this->name = NULL; 
	setName(prodName);
	setPrice(price);
	setCategory(ctg);
}
Product::Product(const Product& other): serial_number(++counter) 
{
	
	setName(other.name);
	setPrice(other.price);
	setCategory(other.ctg);
}
Product :: Product(Product&& other):serial_number(++counter) 
{
	this->name = other.name;
	setCategory(other.ctg);
	setPrice(other.price);
	other.name = nullptr;
}
Product::~Product() {
	delete[] this->name;
	//delete[] this->serial_number;
}

bool Product::setPrice(float price)
{
	if (price <= 0)
	{
		cout << "Error: The price must be a positive value " << endl;
		return false;
	}
	this->price = price;
	return true;
}
void Product::setCategory(Category ctg) 
{
	this->ctg = ctg;

}
void Product:: setName(const char* name) 
{
	delete[] this->name;
	this->name = strdup(name);
}
void Product :: print() const 
{
	cout << "Product name: " << this->name << endl;
	cout << "Price: " << this->price << " NIS" << endl;
	cout << "Serial number: " << this->serial_number << endl;
	cout << "Category: " << categoryName[this->ctg] << endl;

}