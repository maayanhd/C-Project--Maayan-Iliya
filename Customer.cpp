
// try 1 
#include "Seller.h"

// constant variable for the maximal length of the feedback string
constexpr int MAX_LENGTH_FEEDBACK = 150;

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

void Customer::addFeedback() 
{
	int option, size = history.getHistorySize();
	char ch;
	bool isValid = false;
	int maxSize = MAX_LENGTH_FEEDBACK; // Maximal size of feedback
	char* feedback= nullptr;
	Product** pHistory = history.getPurchaseHistory();
	Feedback** feedbacks = history.getFeedbacks();
	
	cout << "Choose a product to leave a feedback:\n;";
	for (int i = 0; i < size; ++i) {
		cout << i + 1 << ". ";
		pHistory[i]->print();
		cin >> option;
		if (optionIsValid(option))
		{
			if (feedbacks[option - 1] == nullptr)
			{
				cout << "You haven't left any feedback for this product, would you like to do it now: y/n?" << endl;
				cin >> ch;
				if (ch == 'y' || ch == 'Y') // In case capslock is on 
				{
					Seller * relevantSeller = pHistory[option - 1]->getSeller();
					int indexToInsert = relevantSeller->getNextIndexToInsert();
					feedback = relevantSeller->getFeedbacks()[indexToInsert]->getFeedback();					
					leaveFeedback(maxSize, feedback);
				}
			}
		}
		else // There's already a feedback 
		{
			cout << "You already have left a feedback for this product!" << endl;
		}		
	}
}

bool Customer:: optionIsValid(int option)
{
	return (option >= 1 && option <= history.getHistorySize() );
}

void  Customer::leaveFeedback(int maxSize, char * feedback)
{
	bool isValid = true;

	do
	{
		cout << "Please enter your Feedback:\n";
		isValid = getString(feedback, maxSize); // Ask for input
	} while (!isValid); // As long as the input isn't valid
	
}

void Customer:: order() 
{
	char ch;
	Product** products = sCart.getProducts();
	int numOfProducts = sCart.getNumOfProducts();
	cout << "Customer details: " << endl;
	this->print();
	for (int i = 0; i < numOfProducts; i++) {
		cout << "Product details: " << endl; 
		products[i]->print();
	}
	cout << "Total price: " << sCart.totalPrice << endl;
}

void Customer::pay() {
	sCart.toEmpty();
}
bool Customer::setUsername(const char* username)
{
	if (strlen(username)>MAX_LENGTH)
	{
		cout << "Too many characters for username" << endl;
		return false;
	}
	delete[] this->username;
	this->username = strdup(username);
	return true;
};
bool Customer::setPassword(const char* password)
{
	
	if (strlen(password) > MAX_LENGTH)
	{
		cout << "The password is too long" << endl;
		return false;
	}
	delete[] this->password;
	this->password=strdup(password);
	return true;
};

void Customer:: print() 
{
	cout << "Name: " << username << endl;
	cout << "Password: " << password << endl;
	this->address.print();
}

bool Customer::getString(char* str, int maxSize) 
{

	char* res = new char[maxSize];
	cin.getline(res, maxSize);
	if (cin.fail())
	{
		cin.clear();
		cleanBuffer();
		delete[] res;
		return false;
	}
	else {
		str = res;
		return true;
	}
}

void Customer::cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

