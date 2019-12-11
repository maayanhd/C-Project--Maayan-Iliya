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
	Product** newArr = new Product*[newSize];
	Feedback** newFeedbacks = new Feedback*[newSize];
	for (int i = 0; i < pHistorySize; i++) // Copying old products 
		newArr[i] = prodArr[i];
	for (int i = pHistorySize; i < newSize; i++) // Copying new products
		newArr[i] = prodArr[i];
	for (int i = 0; i < pHistorySize; i++) // Copying feedbacks, new feedbacks will be nullptr till the customer will leave one//
		newFeedbacks[i] = myFeedbacks[i];
	delete[] prodArr;
	delete[] myFeedbacks;
	setHistorySize(newSize);
	this->prodArr = newArr;
	this->myFeedbacks = newFeedbacks;
}
