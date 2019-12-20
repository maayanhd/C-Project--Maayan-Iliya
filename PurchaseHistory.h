#ifndef _PURCHASE_HISTORY_H
#define _PURCHASE_HISTORY_H

#include "feedback.h"

class PurchaseHistory {
	
public:
	PurchaseHistory();
	~PurchaseHistory();
	void add(Product** products, int numOfProducts);
	void setHistorySize(int size);
	inline int getHistorySize() const	   { return pHistorySize; };
	inline Product** getPurchaseHistory() const { return prodArr; };
	inline Feedback** getFeedbacks() const  { return myFeedbacks; };
	
private:
	int pHistorySize;
	Product** prodArr;// Products purchased by the customer //
	Feedback** myFeedbacks; // Pointers to feedbacks of purchased products, myFeedbacks[i] related to prodArr[i]//
};
#endif