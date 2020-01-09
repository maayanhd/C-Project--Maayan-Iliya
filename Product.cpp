#include "Seller.h"


int Product::counter = 0; // counter for the serial numbers of products 
Product::Product(const char* prodName, float price, Category ctg,Seller& mySeller) : seller(mySeller),feedbacks(NULL) ,serial_number(++counter)
{
	this->name = NULL; 
	setName(prodName);
	setPrice(price);
	setCategory(ctg);
	numOfFeedbacks = 0;
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
	other.name = nullptr;
}
Product::~Product() 
{
	delete[] this->name;
	for (int i = 0; i < numOfFeedbacks; ++i)
		delete  feedbacks[i];
	delete[] feedbacks;
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


void Product::addFeedback(Feedback *feedback) 
{
	// Allocating a new feedbacks array to make room for the new feedback
	Feedback** arr = new Feedback*[numOfFeedbacks + 1];
	for (int i = 0; i < numOfFeedbacks; ++i) // Copying addresses to existing feedbacks
		arr[i] = feedbacks[i];
	arr[numOfFeedbacks] = feedback;
	delete[] feedbacks;						// Deleting the old array of feedbacks
	feedbacks = arr;
	numOfFeedbacks++;					    // Updating number of feedbacks (including the new feedback that is about to be added)
}

ostream& operator<<(ostream& os, const Product& product)
{
	os << "Product name: " <<product.name<< endl;
	os << "Price: " << product.price<< " NIS" << endl;
	os << "Serial number: " << product.serial_number<< endl;
	os << "Category: " << categoryName[product.getCategory()] << endl;
	os << "Feedbacks: "<<endl;

	for (int i = 0; i < product.numOfFeedbacks; ++i)
	{
		os << i + 1 << ". " << product.feedbacks[i] << endl;
	}
	return os;
}
