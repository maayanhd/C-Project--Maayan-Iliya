//#include "Seller.h"
//#include "Customer.h"
#include "eCommerce.h"
#include "Product.h"
#include "feedback.h"

Feedback::Feedback(Customer* pCustomer, Seller * pSeller, char * feedback, Product * pProduct, 
	unsigned int* day, unsigned int* month, unsigned int* year): dateWritten(day, month, year)
{
	setCustomer(pCustomer);
	setSeller(pSeller);
	setProduct(pProduct);
	setFeedback(MIXED, feedback);
	
}
Feedback::Feedback(const Feedback & other):dateWritten(other.getDate)
{
	this->pCustomer = other.pCustomer;
	this->pSeller = other.pSeller;
	this->pProduct	= other.pProduct;
	setFeedback(MIXED, other.feedback); // Allocating and copying the string 
}
Feedback::Feedback(Feedback && other):dateWritten(other.getDate)
{
	this->pCustomer = other.pCustomer;
	this->pSeller = other.pSeller;
	this->pProduct = other.pProduct;
	this->feedback = other.feedback;
	other.feedback = nullptr;
}
Feedback::~Feedback()
{
	delete[] feedback; // Releasing the string represents a feedback 
}

bool Feedback:: setFeedback(strtype type, char* feedback) // Type is allocated in eCommerce
{
	bool isValid = false;
	do
	{
		isValid = input(type, feedback); // Ask for input
	}
	while(!isValid) // As long as the input isn't valid

}





