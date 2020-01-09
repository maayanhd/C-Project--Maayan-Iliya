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
}
void PurchaseHistory::setHistorySize(int size) 
{
	pHistorySize = size;
}

void PurchaseHistory:: print() const {
	for (int i = 0; i < pHistorySize; ++i)
	{
		cout << i + 1 << ".";
		cout<<*(prodArr[i]);
		cout << endl;
	}
}
void PurchaseHistory::add(Product** products, int numOfProducts) 
{
	int newSize = numOfProducts + pHistorySize;
	int write = 0, read = 0;
	Product** newArr = new Product*[newSize];
	Feedback** newFeedbacks = new Feedback*[newSize];
	while (write < pHistorySize) 
	{ // Copying old products and the feedbacks
		newArr[write] = prodArr[read];
		newFeedbacks[write] = myFeedbacks[write];
		write++;
		read++;
	}
	read = 0;
	while (write < newSize) 
	{ // Copying new products, and making "blank" feedbacks as nullptr
		newArr[write] = products[read];
		newFeedbacks[write] = nullptr;
		write++;
		read++;
	}
	delete[] prodArr;
	delete[] myFeedbacks;
	setHistorySize(newSize);
	this->prodArr = newArr;
	this->myFeedbacks = newFeedbacks;
}
