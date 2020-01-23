#include "Customer.h"

ShoppingCart::ShoppingCart(Customer& myCustomer): customer(myCustomer)
{ // We want an empty cart
	totalPrice = 0;
}

ShoppingCart::~ShoppingCart() 
{
}

void ShoppingCart:: add(Product* prod) 
{
	products.push_back(prod);
	totalPrice += prod->getPrice();
}

bool ShoppingCart::existsIn(Product* prod)  const{

	vector<Product*>::const_iterator itr = products.begin();
	vector<Product*>::const_iterator itrEnd = products.end();
	for (; itr != itrEnd; ++itr)
	{
		if (*prod == *(*itr))
			return true;
	}
	return false;	
}
void ShoppingCart :: toEmpty() 
{
	PurchaseHistory& tempHistory = customer.getpHistory();
	tempHistory.add(products);
	products.clear();
	totalPrice = 0;
};

ostream& operator<<(ostream& os, const ShoppingCart& sCart)
{
	os << "Shopping cart:\n";
	int size = sCart.products.size();
	for (int i = 0; i < size; ++i)
	{
		os << i + 1 << ". " << *(sCart.products[i]) << endl; // Using operator << of Product class
	}
	os << "Total Price: " << sCart.getTotalPrice();
	return os;
}

