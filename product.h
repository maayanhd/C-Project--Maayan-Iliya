#ifndef __PRODUCT_H
#define __PRODUCT_H
#include <iostream>
using namespace std;

const char * category[]{ "Children", "Electricity", "Clothing", "OfficeSupply" };

class Product
{
	public:
		enum category { CHILDREN = 0, ELECTRICITY, CLOTHING, OFFICESUPPLY };
		static const int SERIAL_LENGTH = 6;
	private:
		category ctg;
		char* name;
		float price; // in shekel
		char serial_number[SERIAL_LENGTH]; // 5 letters length

	public:
		inline char* getName() const { return name; };
		inline const char* getSerialNumber() const { return serial_number; };
		inline category getCategory() const { return ctg; };
		inline float getPrice() const { return price; };
		bool setPrice(float& price);
		bool setCategory(category& ctg);
		bool setName(char* name);
		bool setSerialNumber(char* serialNum);

	Product(float& price, category& ctg, char* name, char* serialNum)
	{
		setPrice(price);
		setCategory(ctg);
		setName(name);
		setSerialNumber(serialNum);
	}
		
};

#endif