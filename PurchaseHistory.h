#ifndef _PURCHASE_HISTORY_H
#define _PURCHASE_HISTORY_H

#include "feedback.h"

class PurchaseHistory {
	
public:
	friend class Customer;

	PurchaseHistory();
	~PurchaseHistory();

	void add(vector<Product*>& products);
	void setHistorySize(int size);
	void print() const;
	
private:
	vector<Product*> prodArr;				// Products purchased by the customer 
	vector<Feedback*> myFeedbacks;			// Pointers to feedbacks of purchased products, myFeedbacks[i] related to prodArr[i]
};
#endif