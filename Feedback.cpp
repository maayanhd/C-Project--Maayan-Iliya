#include "Customer.h"

Feedback::Feedback(const Customer& customer, string& feedback, Product * pProduct, 
	unsigned int* day, unsigned int* month, unsigned int* year): dateWritten(day, month, year), refCustomer(customer)
{
	setProduct(pProduct);
	setFeedback(feedback);
}
Feedback::Feedback(const Feedback & other): refCustomer(other.getCustomer()),dateWritten(other.dateWritten)
{
	this->pProduct	= other.pProduct;
	// Allocating and copying the string 
	setFeedback(other.feedback);	  
}
Feedback::Feedback(Feedback && other):refCustomer(other.getCustomer()), dateWritten(other.dateWritten)
{
	this->pProduct = other.pProduct;
	this->feedback = other.feedback;
}
Feedback::~Feedback()
{
}

void Feedback:: setFeedback(const string& feedback)   // Type is allocated in eCommerce
{
	this->feedback = feedback; // Copying the string
}
ostream& operator<<(ostream& os, const Feedback& feedback)
{
	 os << feedback.getCustomer().getUserName() << ": " << feedback.getFeedback()<< ", ";
	 os << feedback.getDate();
	 return os;
}









