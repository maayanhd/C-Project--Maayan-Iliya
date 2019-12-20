#include "Customer.h"

Feedback::Feedback(Customer* pCustomer, char * feedback, Product * pProduct, 
	unsigned int* day, unsigned int* month, unsigned int* year): dateWritten(day, month, year)
{
	setCustomer(pCustomer);
	setProduct(pProduct);
	setFeedback(feedback);
}
Feedback::Feedback(const Feedback & other):dateWritten(other.dateWritten)
{
	this->pCustomer = other.pCustomer;
	this->pProduct	= other.pProduct;
	// Allocating and copying the string 
	setFeedback(other.feedback);	  
}
Feedback::Feedback(Feedback && other):dateWritten(other.dateWritten)
{
	this->pCustomer = other.pCustomer;
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

void Feedback:: print() const 
{
	cout << pCustomer->getUsername() << ": " << feedback << endl;
	dateWritten.print();
	

}
void Feedback::cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}












