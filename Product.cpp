#include "Product.h"
Product::Product(const char* prodName, float price, const char * serial_number, Category ctg) {
	this->name = NULL; 
	setName(prodName);
	setPrice(price);
	setCategory(ctg);
	setSerialNumber(serial_number);
}
Product::Product(const Product& other) {
	setName(other.name);
	setPrice(other.price);
	setSerialNumber(other.serial_number);
	setCategory(other.ctg);
}
Product :: Product(Product&& other) {
	this->name = other.name;
	this->serial_number = other.serial_number;
	setCategory(other.ctg);
	setPrice(other.price);
	other.name = nullptr;
	other.serial_number = nullptr;
}
Product::~Product() {
	delete[] this->name;
	delete[] this->serial_number;
}

bool Product::setPrice(float price) {
	if (price <= 0)
	{
		cout << "Error: The price must be a positive value " << endl;
		return false;
	}
	this->price = price;
	return true;
}
void Product::setCategory(Category ctg) {
	this->ctg = ctg;

}
void Product:: setName(const char* name) {
	delete[] this->name;
	this->name = strdup(name);
}
bool Product :: setSerialNumber(const char* serialNum) {
	if (checkSerial(serialNum)==false) {
		cout << "The entered number doesn't support the format of serial number" << endl;
		return false;
	}
	delete[] this->serial_number;
	this->serial_number = strdup(serialNum);
	return true;
}
void Product :: print() {
	cout << "Product name: " << this->name << endl;
	cout << "Price: " << this->price << " NIS" << endl;
	cout << "Serial number: " << this->serial_number << endl;
	cout << "Category: " << categoryName[this->ctg] << endl;

}