#include "ShoppingCart.h"
#include "Customer.h"

ShoppingCart::ShoppingCart(Customer* customer) { // We want an empty cart
	products = nullptr; // empty shopping cart
	numOfProducts = 0;
	this->customer = customer;
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
	Product** newProdArr = changeArrSize(numOfProducts+1); // add one more slot for new product
	newProdArr[numOfProducts] = prod; // add the new product 
	delete[] products;
	products = newProdArr;
}

Product** ShoppingCart ::changeArrSize(int newSize) {
	Product** newProdArr = new Product*[newSize];
	for (int i = 0; i < numOfProducts; i++)
		newProdArr[i] = products[i];
	return newProdArr;
}
void ShoppingCart :: toEmpty() {
	delete[] products;
	products = nullptr;
};


void ShoppingCart::Order() {
	int totalPrice = 0;
	char ch;
	history.add(products, numOfProducts);
	cout << "Customer details: " << customer->print;
	for (int i = 0; i < numOfProducts, i++) {
		totalPrice += products[i]->getPrice;
		cout << "Product details: " << products[i]->print;
	}
	cout << "Total price: " << totalPrice << endl;
	cout << "Do you want to make a payment: y/n?" << endl;
	cin >> ch;
	if (ch == 'y') {
		history.add(products, numOfProducts);
		toEmpty();
	}
	else
	{
		cout << "Do you want to empty the shopping cart: y/n?" << endl;
		cin << ch;
		if (ch == 'y')
			toEmpty();
	}
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