#ifndef __SELLER_H
#define __SELLER_H

#include "Customer.h"

class Seller : virtual public User
{	
	public: 
		Seller(const char* userName, const char* password, Address a);
		Seller(const Seller &);							  // copy c'tor 
		virtual ~Seller();													  // d'tor
		
	public: 
		inline int getNumOfProducts()								  const 
			{ return numOfProducts; };
		inline Product** getProducts()								  const 
			{ return availableProducts; };
		void print()												  const; 
		inline Feedback ** getFeedbacks() 
			{ return this->feedbacks; };
		int getNextIndexToInsert();		  // next Index to insert a feedback
		int getNextIndexToInsertProduct();// finding the next place for 
										  // inserting a product
		bool ProductExists(char * nameOfProduct) const;
		void addProduct(char* prodName, float price, Category ctg);
		bool optionIsValid (int option) const;
		bool priceIsValid(float price) const;

	public:
		virtual void toOs(ostream& os) const;

	protected: 
		static constexpr int MAX_LENGTH = 21;
		Product **  availableProducts;		  // Preparation of array of pointers to products available for sale- no supply management
		int numOfProducts;					  // Number of products available 
		Feedback ** feedbacks;				  // Array of pointers to feedbacks of customers on the seller's products 
		int numOfFeedbacks;					  // Number of given feedbacks to sellers 
		
};


#endif