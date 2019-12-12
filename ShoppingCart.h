//#ifndef __SHOPPINGCART_H
//#define __SHOPPINGCART_H
#pragma once

class Customer;
class Product; // Avoiding including too many times headers


class ShoppingCart {

public:
	ShoppingCart(Customer* customer); // makes empty shopping cart
	~ShoppingCart();

public:
	inline int getNumOfProducts() const { return numOfProducts; };
	bool setNumOfProducts(int updatedCountOfProducts);
	void add(Product* prod); // add product to the shopping cart
	bool remove(int indToRemove);// remove product from the shopping cart
	void toEmpty(); // removes all the products from the shopping cart
	inline Product** getProducts() const { return products; };
	 
	
private:
	Customer* customer;
	Product** changeArrSize(int newSize); // creates the copy of the ptr to products array but with the new size 
	Product** products; //Cannot change the products, but can change the pointer //
	int numOfProducts;
	
};


//#endif