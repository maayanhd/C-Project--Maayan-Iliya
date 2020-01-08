#ifndef __SHOPPINGCART_H
#define __SHOPPINGCART_H


class Customer;
class Product; 


class ShoppingCart {

public:
	friend class Customer;
	ShoppingCart(Customer* customer); // makes empty shopping cart
	ShoppingCart(const ShoppingCart&);
	ShoppingCart(ShoppingCart&&);
		
	~ShoppingCart();

public:
	inline int getNumOfProducts()					const
		{ return numOfProducts; };
	bool setNumOfProducts(int updatedCountOfProducts);
	void add(Product* prod);		// add product to the shopping cart
	bool remove(int indToRemove);	// remove product from the shopping cart
	void toEmpty();					// removes all the products from the shopping cart
	inline Product** getProducts()					const 
		{ return products; };
	inline float getTotalPrice()					const 
		{ return totalPrice; };
	bool existsIn(Product* prod)					const;

public:
	friend ostream& operator<<(ostream& os, const ShoppingCart& sCart);
	
private:
	Customer* customer;
	Product** changeArrSize(int newSize); // creates the copy of the ptr to products array but with the new size 
	Product** products;					  //Cannot change the products, but can change the pointer 
	int numOfProducts;
	float totalPrice;
	
};


#endif