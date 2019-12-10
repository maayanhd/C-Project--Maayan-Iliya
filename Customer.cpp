#include "Customer.h"

Customer::Customer(const char* name, const char* password,const char* countryName, const char* cityName, const char* streetName, const int* house)
	:address(countryName,cityName,streetName,house), sCart(this){
	setName(name);
	setPassword(password);
};	

Customer::~Customer() {
	delete[] this->name;
	delete[] this->password;
	sCart.~ShoppingCart(); 
}  

void Customer::watchPurchaseHistory() {
	int size = history.getHistorySize();
	char ch;
	Product** pHistory = history.getPurchaseHistory();
	Feedback** feedbacks = history.getFeedbacks();
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". ";
		pHistory[i]->print();
		if (feedbacks[i] == nullptr)
		{
			cout << "You haven't left any feedback for this product, do you want do to this now: y/n?" << endl;
			cin >> ch;
			if (ch == 'y') {
				//feedbacks[i] = pHistory[i].addFeedback(); // Need to realize this method when Maayan will make the feedback class
			}
		}
	}

}
void Customer:: order() {
	int totalPrice = 0;
	char ch;
	Product** products = sCart.getProducts();
	int numOfProducts = sCart.getNumOfProducts();
	cout << "Customer details: " << this->print;
	for (int i = 0; i < numOfProducts; i++) {
		totalPrice += products[i]->getPrice;
		cout << "Product details: " << products[i]->print;
	}
	cout << "Total price: " << totalPrice << endl;
	cout << "Do you want to make a payment: y/n?" << endl;
	cin >> ch;
	if (ch == 'y') {
		history.add(products, numOfProducts);
		sCart.toEmpty();
	}
	else
	{
		cout << "Do you want to empty the shopping cart: y/n?" << endl;
		cin >> ch;
		if (ch == 'y')
			sCart.toEmpty();
	}
}
bool Customer::setName(const char* name) {
	if (!onlyLetters(name))
	{
		cout << "The name must contain letters only" << endl;
		return false;
	}
	delete[] this->name;
	this->name = strdup(name);
	return true; // must check the name in the future
};
bool Customer::setPassword(const char* password) {
	delete[] this->password;
	if (strlen(password) >= 20)
	{
		cout << "The password is too long" << endl;
		return false;
	}
	strcpy(this->password, password);
};

void Customer:: print() {
	cout << "Name: " << name << endl;
	cout << "Password: " << password << endl;
	this->address.print();
}