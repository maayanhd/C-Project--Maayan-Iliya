
// try 1 
#include "Seller.h"

// constant variable for the maximal length of the feedback string
constexpr int MAX_LENGTH_FEEDBACK = 150;
constexpr int DAY_LENGTH = 2;
constexpr int MONTH_LENGTH = 2;
constexpr int YEAR_LENGTH = 4;

Customer::Customer(const char* username, const char* password, const char* countryName, const char* cityName, const char* streetName, const int* house)
	:address(countryName, cityName, streetName, house), sCart(this) {
	setUsername(username);
	setPassword(password);
};

Customer::~Customer() {
	delete[] this->username;
	delete[] this->password;

}

void Customer::addFeedback()
{
	int option, maxSize = MAX_LENGTH_FEEDBACK; // Maximal size of feedback
	char ch , *feedback = nullptr;;
	bool answerIsValid = false;
	Product** pHistory = history.getPurchaseHistory();
	Feedback** feedbacks = history.getFeedbacks();
	unsigned int * day = nullptr, *month = nullptr, *year = nullptr;
	if (pHistory != NULL) // The customer has already bought products
	{
		cout << "Choose a product to leave a feedback:\n";
		// Printing the products that has been purchased by the customer
		printPurchasedProducts(pHistory);
		cin >> option;
		while (!optionIsValid(option)) // Option validation
		{
			cout << "no such of option exists, please try agian\n";
			printPurchasedProducts(pHistory);
			cin >> option;
		}

		if (feedbacks[option - 1] == nullptr) // Checking if there's already a feedback on the product
		{
			cout << "You haven't left any feedback for this product, would you like to do it now: y/n?" << endl;
			cin >> ch;
			while (!answerIsValid)
			{
				answerIsValid = true; // assuming answer is valid- 
				if (ch == 'y' || ch == 'Y')
				{
					Seller * relevantSeller = pHistory[option - 1]->getSeller(); // Getting the relevant seller 
					int indexToInsert = relevantSeller->getNextIndexToInsert(); // Finding the matching index to insert the feedback
					leaveFeedback(maxSize, feedback); // The process of leaving the feedback string 						
					getValidDate(day, month, year); // asking for the date

					// Adding the feedback in the next free place in the feedbacks array of the seller
					relevantSeller->getFeedbacks()[indexToInsert] = new Feedback(this, feedback, pHistory[option - 1], day, month, year);
				}
				else if (ch == 'n' || ch == 'N') // Invalid input check
					cout << "no feedback has been added\n";
				else // invalid input
				{
					cout << "Invalid input, please enter your answer again.\n" << "You haven't left any feedback for this product, would you like to do it now: y/n?" << endl;
					answerIsValid = false;
					cin >> ch;
				}
			}
		}
		else // There's already a feedback 
		{
			cout << "You already have left a feedback for this product!" << endl;
		}
	}
	else
		cout << "No products has been purchased yet\n";
}
void Customer:: getValidDate(unsigned int *day, unsigned int * month, unsigned int * year)
{
	// Default date fields for access of validation functions 
	unsigned int defaultDay[DAY_LENGTH] = { 0,  };
	unsigned int defaultMonth[MONTH_LENGTH] = { 0, 0 };
	unsigned int defaultYear[YEAR_LENGTH] = { 2, 0, 0, 0 };
	int dayNum, monthNum, yearNum, iterationsCounter = 1;
	
	day = new unsigned int[DAY_LENGTH];
	month = new unsigned int[MONTH_LENGTH];
	year = new unsigned int[YEAR_LENGTH];
	Date * date = new Date(defaultDay, defaultMonth, defaultYear);
	do
	{	// Notices whether the input is valid or not
		iterationsCounter > 1 ? cout << "invalid date, please try again\n" : cout << "Date had been updated\n";

		cout << " Please enter the day:\n";
		cin >> dayNum;
		cout << " Please enter the month:\n";
		cin >> monthNum;
		cout << " Please enter the year:\n";
		cin >> yearNum;
		for (int i = DAY_LENGTH - 1; i >= 0 ; --i)
		{
			day[i] = (unsigned int)dayNum % 10; 
			dayNum /= 10;
		}
		for (int i = MONTH_LENGTH - 1; i >= 0; --i)
		{
			month[i] = (unsigned int) monthNum % 10;
			monthNum /= 10;
		}
		for (int i = YEAR_LENGTH - 1; i >= 0; --i)
		{
			year[i] = (unsigned int) yearNum % 10;
			yearNum /= 10;
		}
		++iterationsCounter;
	} while ( dayNum < 0 || monthNum < 0 || yearNum < 0 || !dateIsValid(day, month, year, date) ) ; // Date validation
}
bool Customer::dateIsValid(unsigned int *day, unsigned int * month, unsigned int * year, Date* dateAccess)
{
	bool dayIsValid = dateAccess->dayIsValid(day, month, year);
	bool monthIsValid = dateAccess->monthIsValid(month);
	bool yearIsValid = dateAccess->yearIsValid(month);

	return (dayIsValid && monthIsValid && yearIsValid);
}
void Customer::printPurchasedProducts(Product** purchasedProducts) const
{	
	int size = history.getHistorySize();
	for (int i = 0; i < size; ++i)
	{	// Printing the products that has been purchased by the customer
		cout << i + 1 << ". ";
		purchasedProducts[i]->print();
		cout << endl;
	}
}
bool Customer::optionIsValid(int option)
{
	return (option >= 1 && option <= history.getHistorySize());
}
void  Customer::leaveFeedback(int maxSize, char * feedback)
{
	bool isValid = true;
	feedback = new char[maxSize]; // Allocating the feedback string to maximal size
	do
	{
		cleanBuffer();
		cout << "Please enter your Feedback:\n";
		isValid = getString(feedback, maxSize); // Ask for input
		if (!isValid)
			cout << "Too many characters, please leave your feedback again.\n";
		else
			cout << "Thank you for your feedback, it is important to us.\n";
	} while (!isValid); // As long as the input isn't valid

}
void Customer::order()
	{
	Product** products = sCart.getProducts();
	int numOfProducts = sCart.getNumOfProducts();
	cout << "Customer details: " << endl;
	this->print();
	for (int i = 0; i < numOfProducts; ++i) {
		cout << "Product details: " << endl;
		products[i]->print();
	}
	cout << "Total price: " << sCart.totalPrice << endl;
}
bool Customer::setUsername(const char* username)
{
	if (strlen(username) > MAX_LENGTH)
	{
		cout << "Too many characters for username" << endl;
		return false;
	}
	delete[] this->username;
	this->username = strdup(username);
	return true;
}
bool Customer::setPassword(const char* password)
{

	if (strlen(password) > MAX_LENGTH)
	{
		cout << "The password is too long" << endl;
		return false;
	}
	delete[] this->password;
	this->password = strdup(password);
	return true;
}
void Customer::print()
{
	cout << "Name: " << username << endl;
	cout << "Password: " << password << endl;
	this->address.print();
}
bool Customer::getString(char* str, int maxSize)
{

	//char* res = new char[maxSize];
	cin.getline(str, maxSize);
	if (cin.fail())
	{
		cin.clear();
		cleanBuffer();
		delete[] str;
		return false;
	}
	else {
		//str = res;
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

