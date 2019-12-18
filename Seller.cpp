#include "Seller.h"

Seller::Seller(const char* userName, const char* password, const char* countryName, const char* cityName, const char* streetName,
	int* house) : address(countryName, cityName, streetName, house), availableProducts(NULL) // Using init line for initializing the address- 
{
	this->userName = nullptr;																   // reducing potential excessive copy c'tor calls
	this->password = nullptr;
	setUserName(userName);
	setPassword(password);
}
Seller:: ~Seller()
{
	delete[] this->userName;
	delete[] this->password;

	for (int i = 0; i < numOfProducts; ++i)
		delete this->availableProducts[i];

}
bool Seller::setUserName(const char * userName)
{
	if (strlen(userName) > MAX_LENGTH)
	{
		cout << "Too many characters for username" << endl;
		return false;
	}

	delete[] this->userName;
	this->userName = strdup(userName);
	return false;
}
void Seller::setPassword(const char* password)
{
	delete[] this->password;
	this->password = strdup(password);
}
void Seller::print() const
{
	cout << "UserName: " << this->getUserName() << endl;
	cout << "Password: " << this->getPassword() << endl;
	this->address.print();
}

int Seller::getNextIndexToInsert()
{
	Feedback ** tempFeedbacks = new Feedback *[numOfFeedbacks + 1];

	for (int i = 0; i < numOfFeedbacks; ++i)
	{
		tempFeedbacks[i] = feedbacks[i]; // Copying the remaining 
	}
	feedbacks = tempFeedbacks;
	++numOfFeedbacks;

	return numOfFeedbacks - 1;
}


int Seller::getNextIndexToInsertProduct()
{
	Product ** tempProducts = new Product*[numOfProducts + 1];

	for (int i = 0; i < numOfProducts; ++i)
	{
		tempProducts[i] = availableProducts[i]; // Copying the remaining products
	}
	availableProducts = tempProducts;
	++numOfProducts; // updating the number of products 

	return numOfProducts - 1;
}

bool Seller::ProductExists(char * nameOfProduct) const
{
	bool exists = false;

	for (int i = 0; i < numOfProducts && !exists; ++i)
	{
		if (strcmp(availableProducts[i]->getName(), nameOfProduct) == 0)
		{
			exists = true; // Product is already exists
			cout << "A product with an identical name already exists in the seller's available products list\n";
		}
	}
	return exists;
}

void Seller::addProduct(char* prodName, float price, Category ctg)
{
	Product * newProduct = nullptr;
	const char * finalName = prodName;
	newProduct = new Product(finalName, price, ctg,this);
	int nextIndexToInsert = getNextIndexToInsertProduct();
	availableProducts[nextIndexToInsert] = newProduct; // Inserting the product into the available products storage
	cout << "Product Added successfully to the seller:\n";
	this->print(); // Printing the seller's details
}

bool Seller::optionIsValid(int option) const
{
	return (option >= 1 && option <= 4);
}
bool Seller::priceIsValid(float price) const
{
	return price > 0.0; // a Price of a product must be positive number 
}



