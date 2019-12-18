#include "PurchaseHistory.h"

PurchaseHistory::PurchaseHistory() 
{
	pHistorySize = 0;
	prodArr = nullptr;
	myFeedbacks = nullptr;
};

PurchaseHistory::~PurchaseHistory() 
{

	delete[] prodArr;
	delete[] myFeedbacks;
};
void PurchaseHistory::setHistorySize(int size) 
{
	pHistorySize = size;

};

void PurchaseHistory::add(Product** products, int numOfProducts) 
{
	int newSize = numOfProducts + pHistorySize;
	int write = 0, read = 0;
	Product** newArr = new Product*[newSize];
	Feedback** newFeedbacks = new Feedback*[newSize];
	while (write < pHistorySize) { // Copying old products 
		newArr[write] = prodArr[read];
		write++;
		read++;
	}
	read = 0;
	while (write < newSize) { // Copying new products
		newArr[write] = products[read];
		write++;
		read++;
	}
	for (int i = 0; i < pHistorySize; i++) // Copying feedbacks, new feedbacks will be nullptr till the customer will leave one//
		newFeedbacks[i] = myFeedbacks[i];
	delete[] prodArr;
	delete[] myFeedbacks;
	setHistorySize(newSize);
	this->prodArr = newArr;
	this->myFeedbacks = newFeedbacks;
}
