#include "PurchaseHistory.h"

PurchaseHistory::PurchaseHistory() 
{
};


PurchaseHistory::~PurchaseHistory() 
{
}
void PurchaseHistory::setHistorySize(int size) 
{
}

void PurchaseHistory:: print() const {
	int size = prodArr.size();
	for (int i = 0; i < size; ++i)
	{
		cout << i + 1 << ".";
		cout<<*(prodArr[i]);
		cout << endl;
	}
}
void PurchaseHistory::add(vector<Product*>& products)
{
	
	prodArr.insert(prodArr.end(), products.begin(), products.end());
	int size = products.size();
	while (size > 0) {
		myFeedbacks.push_back(nullptr);
		size--;
	}
}
