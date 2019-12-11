#include "Customer.h"
#include "ShoppingCart.h"

Customer::Customer(const char* username, const char* password,const char* countryName, const char* cityName, const char* streetName, const int* house)
	:address(countryName,cityName,streetName,house), sCart(this){
	setUsername(username);
	setPassword(password);
};	

Customer::~Customer() {
	delete[] this->username;
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
bool Customer::setUsername(const char* username) {
	if (strlen(username)>MAX_LENGTH)
	{
		cout << "Too many characters for username" << endl;
		return false;
	}
	delete[] this->username;
	this->username = strdup(username);
	return true;
};
bool Customer::setPassword(const char* password) {
	
	if (strlen(password) > MAX_LENGTH)
	{
		cout << "The password is too long" << endl;
		return false;
	}
	delete[] this->password;
	this->password=strdup(password);
	return true;
};

void Customer:: print() {
	cout << "Name: " << username << endl;
	cout << "Password: " << password << endl;
	this->address.print();
}