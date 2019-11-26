#ifndef __SHOPPINGCART_H
#define __SHOPPINGCART_H
#include "Product.h"


class ShoppingCart {

public:
	ShoppingCart(); // makes empty shopping cart
	~ShoppingCart(); 

public:
	inline int getNumOfProducts() const { return numOfProducts; };
	bool setNumOfProducts(int updatedCountOfProducts);
	void add(Product* prod); // add product to the shopping cart
	bool remove(int indToRemove);// remove product from the shopping cart

private:
	const Product** changeArrSize(int newSize); // creates the copy of the ptr to products array but with the new size 
	const Product** products; //Cannot change the products, but can change the pointer //
	int numOfProducts;

};


#endif