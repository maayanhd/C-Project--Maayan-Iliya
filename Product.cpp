#include "Seller.h"


int Product::counter = 0; // counter for the serial numbers of products 
Product::Product(const string& prodName, float price, Category ctg,Seller& mySeller) : seller(mySeller),feedbacks(NULL) ,serial_number(++counter)
{
	setName(prodName);
	setPrice(price);
	setCategory(ctg);
}
Product::Product(const Product& other): seller(other.seller) , serial_number(++counter) 
{
	setName(other.name);
	setPrice(other.price);
	setCategory(other.ctg);
}
Product :: Product(Product&& other):seller(other.seller),serial_number(++counter) 
{
	this->name = other.name;
	setCategory(other.ctg);
	setPrice(other.price);
}
Product::~Product()
{
	int size = feedbacks.size();
	for (int i = 0; i <size; i++) {
		delete feedbacks[i];
	}
	//feedbacks.erase(feedbacks.begin(), feedbacks.end());
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
void Product:: setName(const string& name) 
{
	this->name = name;
}


void Product::addFeedback(Feedback *feedback) 
{
	feedbacks.push_back(feedback);
}

ostream& operator<<(ostream& os, const Product& product)
{
	os << "Product name: " <<product.name<< endl;
	os << "Price: " << product.price<< " NIS" << endl;
	os << "Serial number: " << product.serial_number<< endl;
	os << "Category: " << categoryName[product.getCategory()] << endl;
	os << "Feedbacks: "<<endl;

	int size = product.feedbacks.size(); // Number of feedbacks of the product
	for (int i = 0; i < size; ++i)
	{
		os << i + 1 << ". " << *(product.feedbacks[i]) << endl;
	}
	return os;
}

bool Product:: operator== (const Product& product)
{
	return this->serial_number == product.serial_number;
}

