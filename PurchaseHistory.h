#ifndef _PURCHASE_HISTORY_H
#define _PURCHASE_HISTORY_H

#include "feedback.h"

class PurchaseHistory {
	
public:
	friend class Customer;

	PurchaseHistory();
	~PurchaseHistory();

	void add(Product** products, int numOfProducts);
	void setHistorySize(int size);
	inline int getHistorySize() const	   { return pHistorySize; }
	void print() const;
	
private:
	int pHistorySize;
	Product** prodArr;				// Products purchased by the customer 
	Feedback** myFeedbacks;			// Pointers to feedbacks of purchased products, myFeedbacks[i] related to prodArr[i]
};
#endif