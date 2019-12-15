#include "Customer.h"

ShoppingCart::ShoppingCart(Customer* customer) 
{ // We want an empty cart
	products = nullptr; // empty shopping cart
	setNumOfProducts(0);
	totalPrice = 0;
	this->customer = customer;
}

ShoppingCart::~ShoppingCart() 
{
  delete[] products; // Removes only the array, we losing the pointer to the products, but they still exist on the seller side //
}

bool ShoppingCart::setNumOfProducts(int updatedCountOfProducts) 
{
	if (updatedCountOfProducts < 0)
	{
		cout << "That value should be positive" << endl;
		return false;
	}
	numOfProducts = updatedCountOfProducts;
	return true;
}

void ShoppingCart:: add(Product* prod) 
{
	Product** newProdArr = changeArrSize(getNumOfProducts()+1); // add one more slot for new product
	newProdArr[numOfProducts] = prod; // add the new product 
	totalPrice += prod->getPrice();
	delete[] products;
	products = newProdArr;
	numOfProducts++;
}

Product** ShoppingCart ::changeArrSize(int newSize) 
{
	Product** newProdArr = new Product*[newSize];
	for (int i = 0; i < numOfProducts; i++)
		newProdArr[i] = products[i];
	return newProdArr;
}
void ShoppingCart :: toEmpty() 
{
	delete[] products;
	products = nullptr;
	setNumOfProducts(0);
	totalPrice = 0;
};

bool ShoppingCart::remove(int indToRemove) 
{
	if (numOfProducts <= 0 || indToRemove >= numOfProducts)
	{
		cout << "The product you specified is not in your shopping cart" << endl;
		return false;
	}
	totalPrice -= products[indToRemove]->getPrice();
		products[indToRemove] = products[numOfProducts]; // Taking the last product in the array to replace the deleted product//
		
		changeArrSize(numOfProducts - 1);
		
		return true;
}
