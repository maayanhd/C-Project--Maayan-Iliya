#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() { // We want an empty cart
	products = nullptr; // empty shopping cart
	numOfProducts = 0;
}

ShoppingCart::~ShoppingCart() {
	delete[] products; // Removes only the array, we losing the pointer to the products, but they still exist on the seller side //
}

bool ShoppingCart::setNumOfProducts(int updatedCountOfProducts) {
	if (updatedCountOfProducts < 0)
	{
		cout << "That value should be positive" << endl;
		return false;
	}
	numOfProducts = updatedCountOfProducts;
	return true;
}

void ShoppingCart:: add(Product* prod) {
	const Product** newProdArr = changeArrSize(numOfProducts+1); // add one more slot for new product
	newProdArr[numOfProducts] = prod; // add the new product 
	delete[] products;
	products = newProdArr;
}

const Product** ShoppingCart ::changeArrSize(int newSize) {
	const Product** newProdArr = new const Product*[newSize];
	for (int i = 0; i < numOfProducts; i++)
		newProdArr[i] = products[i];
	return newProdArr;
}

bool ShoppingCart::remove(int indToRemove) {
	if (numOfProducts <= 0 || indToRemove >= numOfProducts)
	{
		cout << "The product you specified is not in your shopping cart" << endl;
		return false;
	}
		products[indToRemove] = products[numOfProducts]; // Taking the last product in the array to replace the deleted product//
		changeArrSize(numOfProducts - 1);
		return true;
}