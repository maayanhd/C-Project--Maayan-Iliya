#include "Seller.h"

Seller::Seller(const char* userName, const char* password, const char* countryName, const char* cityName,
	const char* streetName, int* house) : User(userName, password, countryName, cityName,
		streetName, house), availableProducts(NULL) {
}
Seller:: ~Seller()
{
	// Releasing each and every pointer to product 
	for (int i = 0; i < numOfProducts; ++i)
		delete this->availableProducts[i];
	// Releasing the array of pointers to available products
	delete[] availableProducts;
	// Releasing array of pointers to feedbacks - the feedbacks released at the Product d'tor
	delete[] this->feedbacks;

}
void Seller::print() const
{
	cout << "UserName: " << this->getUserName() << endl;
	cout << "Password: " << this->getPassword() << endl;
	this->address.print();
}

int Seller::getNextIndexToInsert()
{
	// Allocating new array of pointers to feedbacks with one more room for the new pointer to feedback
	Feedback ** tempFeedbacks = new Feedback *[numOfFeedbacks + 1];

	for (int i = 0; i < numOfFeedbacks; ++i)
	{
		tempFeedbacks[i] = feedbacks[i]; // Copying the addresses of feedbacks to the new array
	}
	delete[] feedbacks;					 // Releasing the old array of pointers to feedbacks 
	feedbacks = tempFeedbacks;			 // setting the feedbacks array to be the new array 
	++numOfFeedbacks;					 // updating the number of feedbacks (including the new feedback that is about to be added)

	return numOfFeedbacks - 1;			 // Returning the index of the next free place in the array 
}


int Seller::getNextIndexToInsertProduct()
{
	// Allocating new array of pointers to products with one more room for the new pointer to product
	Product ** tempProducts = new Product*[numOfProducts + 1];

	for (int i = 0; i < numOfProducts; ++i)
	{
		tempProducts[i] = availableProducts[i]; // Copying the addresses of products to the new array
	}
	delete[] availableProducts;					// Releasing the old array of pointers to feedbacks
	availableProducts = tempProducts;			// updating the number of products (including the new product that is about to be added)
	++numOfProducts;							// updating the number of products 

	return numOfProducts - 1;					// Returning the index of the next free place in the array
}

bool Seller::ProductExists(char * nameOfProduct) const
{
	bool exists = false;

	for (int i = 0; i < numOfProducts && !exists; ++i)
	{
		if (strcmp(availableProducts[i]->getName(), nameOfProduct) == 0)
		{
			exists = true;								// Product is already exists
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
	availableProducts[nextIndexToInsert] = newProduct;		// Inserting the product into the available products storage
	cout << "Product Added successfully to the seller:\n";
	this->print();										    // Printing the seller's details
}

bool Seller::optionIsValid(int option) const
{
	return (option >= 1 && option <= 4);
}
bool Seller::priceIsValid(float price) const
{
	return price > 0.0;										// a Price of a product must be positive number 
}

void Seller::toOs(ostream& os) const
{
	os << "Available Products\n";
	for (int i = 0; i < this->numOfProducts; ++i)
	{
		os << i << ". " << *(availableProducts[i]) << endl; // Using operator << in product class
	}
}




