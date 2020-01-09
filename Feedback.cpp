#include "Customer.h"

Feedback::Feedback(const Customer& customer, char * feedback, Product * pProduct, 
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
	other.feedback = nullptr;
}
Feedback::~Feedback()
{
	 // Releasing the string represents a feedback 
	delete[] feedback;
}

void Feedback:: setFeedback(char* feedback)   // Type is allocated in eCommerce
{
	int length = strlen(feedback) + 1;
	this->feedback= new char[length];		  // Allocating the feedback field 
	memcpy(this->feedback, feedback, length); // Copying the string
}

bool Feedback:: getString(char* str, int maxSize) 
{
	char* res = new char[maxSize];
	cin.getline(res, maxSize);
	if (cin.fail())
	{
		cin.clear();
		cleanBuffer();
		return false;
	}
	else 
	{
		str = res;
		return true;
	}
}

ostream& operator<<(ostream& os, const Feedback& feedback)
{
	 os << feedback.getCustomer().getUserName() << ": " << feedback.getFeedback()<< ", ";
	 os << feedback.getDate()<< endl;
	 return os;
}


void Feedback::cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}













