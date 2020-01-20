#ifndef __SHOPPINGCART_H
#define __SHOPPINGCART_H


class Customer;
class Product; 


class ShoppingCart {

public:
	friend class Customer;
	ShoppingCart(Customer& myCustomer); // makes empty shopping cart
	~ShoppingCart();

public:
	void add(Product* prod);		// add product to the shopping cart
	void toEmpty();					// removes all the products from the shopping cart
	inline const vector<Product*>& getProducts()	const 
		{ return products; };
	inline float getTotalPrice()					const 
		{ return totalPrice; };
	bool existsIn(Product* prod)					const;

public:
	friend ostream& operator<<(ostream& os, const ShoppingCart& sCart);
	
private:
	Customer& customer;
	vector<Product*> products;					  //Cannot change the products, but can change the pointer 
	float totalPrice;
	
};


#endif