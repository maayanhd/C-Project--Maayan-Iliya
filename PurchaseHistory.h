#ifndef _PURCHASE_HISTORY_H
#define _PURCHASE_HISTORY_H

#include <iostream>
using namespace std;

class Feedback() {};
class Product() {};

class PurchaseHistory {
	
public:
	PurchaseHistory();
	~PurchaseHistory();
	void add(Product** products, int numOfProducts);
	void setHistorySize(int size);

	
private:
	int pHistorySize;
	Product** prodArr;// Products purchased by the customer //
	Feedback** myFeedbacks; // Pointers to feedbacks of purchased products, myFeedbacks[i] related to prodArr[i]//
};
#enfif