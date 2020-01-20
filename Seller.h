#ifndef __SELLER_H
#define __SELLER_H
#include "Customer.h"

class Seller : virtual public User
{	
	public: 
		Seller(const string& userName, const string& password, Address a);
		Seller(const Seller &other);	// copy c'tor 
 		Seller(Seller&& other);			// move c'tor
		virtual ~Seller();				//virtual d'tor
		
	public: 
		inline const Array<Product*>& getProducts()								  const 
			{ return availableProducts; };
		inline vector<Feedback*>& getFeedbacks() 
			{ return this->feedbacks; };
		bool ProductExists(const string& nameOfProduct) const;
		void addProduct(string& prodName, float price, Category ctg);
		bool optionIsValid (int option) const;
		bool priceIsValid(float price) const;

	public:
		virtual void toOs(ostream& os) const;

	protected: 
		Array<Product*>  availableProducts;		  // Preparation of array of pointers to products available for sale- no supply management
		vector<Feedback*> feedbacks;				  // Array of pointers to feedbacks of customers on the seller's products 
};


#endif