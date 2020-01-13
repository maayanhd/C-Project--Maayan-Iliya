#include "Customer_Seller.h"


Customer_Seller::Customer_Seller(const Customer& c, const Seller& s) : User(c.getUserName(), c.getPassword(), c.getAddress())
, Customer(c), Seller(s){
}
Customer_Seller::Customer_Seller(const Customer_Seller& other): User(other) , Customer(other), Seller(other){
}
Customer_Seller::Customer_Seller(Customer&& c, Seller&& s): User(move(c)), Customer(move(c)), Seller(move(s)){}

Customer_Seller:: ~Customer_Seller() {
}

void Customer_Seller:: toOs(ostream& os) const 
{
	os << "My Available Products:\n";
	for (int i = 0; i < this->numOfProducts; ++i)
	{
		os << i+1 << ". " << *(availableProducts[i]) << endl; // Using operator << in product class
	}

	os << this->sCart;
}