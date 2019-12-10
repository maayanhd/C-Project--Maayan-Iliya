#include "feedback.h"
#include "Seller.h"
#include "Customer.h"
#include "Product.h"

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

bool Feedback:: setFeedback(charstr type, char* feedback) // Type is allocated in eCommerce
{
	bool isValid = false;
	do
	{
		isValid = input(type, feedback); // Ask for input
	}
	while(!isValid) // As long as the input isn't valid
}


bool input(charstr type, char* feedback) // Will be inside eCommerce class 
{
	char ch;
	int phySize = 5, logicSize=0;
	bool isValid = true;
	feedback = new char[phySize];
	char * tempChar;
	
	while ((ch = getchar()) != '\n' && isValid)
	{
		if (logicSize == phySize)
		{
			phySize *= 2;
			tempChar = new char[phySize + 1];
			for (int i = 0; i < logicSize; ++i)
				tempChar[i]=feedBack[i]
		}
		switch (type) 
		{
			case LETTERS: // only letters
				( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ) ? isValid = true : isValid = false ;
				break;

			case MIXED: // no restrictions of input of characters 
				break;
		}
	}
}



