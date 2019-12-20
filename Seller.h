#ifndef __SELLER_H
#define __SELLER_H
 
#include "Customer.h"

class Seller
{	
	public: 
		Seller(const char* userName, const char* password, const char* countryName,
			const char* cityName, const char* streetName, int* houseNumber);
		Seller(const Seller &) = delete;							  // copy c'tor 
		~Seller();													  // d'tor
		
	public: 
		inline const char * getUserName()							  const 
			{ return userName; };
		inline const char * getPassword()							  const 
			{ return password; };
		inline int getNumOfProducts()								  const 
			{ return numOfProducts; };
		inline Product** getProducts()								  const 
			{ return availableProducts; };
		bool setUserName(const char * userName);
		void setPassword(const char* password);				
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

	private: 
		static constexpr int MAX_LENGTH = 21;
		char * userName;				      // UserName of Seller 
		char* password;						  // Password of The seller for logging into the system
		Address address;					  // The Address of the seller
		Product **  availableProducts;		  // Preparation of array of pointers to products available for sale- no supply management
		int numOfProducts;					  // Number of products available 
		Feedback ** feedbacks;				  // Array of pointers to feedbacks of customers on the seller's products 
		int numOfFeedbacks;					  // Number of given feedbacks to sellers 
		
};


#endif