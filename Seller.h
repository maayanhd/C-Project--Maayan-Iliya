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
		inline int getNumOfProducts()								  const 
			{ return availableProducts.getSize(); };
		inline const Array<Product*>& getProducts()								  const 
			{ return availableProducts; };
		inline Feedback ** getFeedbacks() 
			{ return this->feedbacks; };
		int getNextIndexToInsert();		  // next Index to insert a feedback
		bool ProductExists(const string& nameOfProduct) const;
		void addProduct(string& prodName, float price, Category ctg);
		bool optionIsValid (int option) const;
		bool priceIsValid(float price) const;

	public:
		virtual void toOs(ostream& os) const;

	protected: 
		static constexpr int MAX_LENGTH = 21;
		Array<Product*>  availableProducts;		  // Preparation of array of pointers to products available for sale- no supply management
		Feedback ** feedbacks;				  // Array of pointers to feedbacks of customers on the seller's products 
		int numOfFeedbacks;					  // Number of given feedbacks to sellers 
		
};


#endif