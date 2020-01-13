#include "Seller.h"

// constant variable for the maximal length of the feedback string
constexpr int MAX_LENGTH_FEEDBACK = 150;
constexpr int DAY_LENGTH = 2;
constexpr int MONTH_LENGTH = 2;
constexpr int YEAR_LENGTH = 4;

Customer::Customer(const char* username, const char* password, Address a)
:User(username, password, a), sCart(*this){ };

Customer::~Customer() { }

Customer::Customer(const Customer& other): User(other),sCart(*this)
{}
Customer::Customer(Customer&& other) : User(move(other)), sCart(*this)
{}

void Customer::addFeedback()
{
	int option; // Maximal size of feedback
	char ch, *feedback = new char[MAX_LENGTH_FEEDBACK+1];
	unsigned int* day = new unsigned int[DAY_LENGTH];
	unsigned int* month = new unsigned int[MONTH_LENGTH];
	unsigned int* year = new unsigned int[YEAR_LENGTH];

	bool answerIsValid = false;
	Feedback *newFeedback = nullptr;
	if (history.pHistorySize!=0) // The customer has already bought products
	{
		cout << "Choose a product to leave a feedback:\n";
		// Printing the products that has been purchased by the customer
		history.print();
		cin >> option;
		while (!optionIsValid(option)) // Option validation
		{
			cout << "no such of option exists, please try again\n";
			history.print();
			cin >> option;
		}

		if (history.myFeedbacks[option - 1] == nullptr) // Checking if there's already a feedback on the product
		{
			cout << "You haven't left any feedback for this product, would you like to do it now: y/n?" << endl;
			cin >> ch;
			while (!answerIsValid)
			{
				answerIsValid = true; // assuming answer is valid- 
				if (ch == 'y' || ch == 'Y')
				{
				    Seller & relevantSeller = history.prodArr[option - 1]->getSeller(); // Getting the relevant seller 
					int indexToInsert = relevantSeller.getNextIndexToInsert(); // Finding the matching index to insert the feedback
					leaveFeedback(MAX_LENGTH_FEEDBACK, feedback); // The process of leaving the feedback string 						
					getValidDate(day, month, year); // asking for the date

					// Adding the feedback in the next free place in the feedbacks array of the seller
					newFeedback = new Feedback(*this, feedback, history.prodArr[option - 1], day, month, year);
					relevantSeller.getFeedbacks()[indexToInsert] = newFeedback;
					history.prodArr[option - 1]->addFeedback(newFeedback);
					history.myFeedbacks[option - 1] = newFeedback;
					
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
	delete[] day;
	delete[] month;
	delete[] year;
	delete[] feedback;
}

bool Customer::operator>(const Customer& other) const {
	return this->sCart.getTotalPrice() > other.sCart.getTotalPrice();
}
void Customer:: getValidDate(unsigned int *day, unsigned int * month, unsigned int * year)
{
	// Default date fields for access of validation functions 
	unsigned int defaultDay[DAY_LENGTH] = { 0, 0 };
	unsigned int defaultMonth[MONTH_LENGTH] = { 0, 0 };
	unsigned int defaultYear[YEAR_LENGTH] = { 2, 0, 0, 0 };
	int dayNum, monthNum, yearNum, iterationsCounter = 1;
	Date * date = new Date(defaultDay, defaultMonth, defaultYear);

	do
	{	// Notices whether the input is valid or not
		if (iterationsCounter > 1)
			cout << "invalid date, please try again\n";

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
	delete date;
}
bool Customer::dateIsValid(unsigned int *day, unsigned int * month, unsigned int * year, Date* dateAccess)
{
	bool dayIsValid = dateAccess->dayIsValid(day, month, year);
	bool monthIsValid = dateAccess->monthIsValid(month);
	bool yearIsValid = dateAccess->yearIsValid(year);

	return (dayIsValid && monthIsValid && yearIsValid);
}


bool Customer::optionIsValid(int option) const
{
	return (option >= 1 && option <= history.getHistorySize());
}
void  Customer::leaveFeedback(int maxSize, char * feedback)
{
	bool isValid = true; // Allocating the feedback string to maximal size
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
void Customer::order() const
	{
	Product** products = sCart.getProducts();
	int numOfProducts = sCart.getNumOfProducts();
	cout << "Customer details: " << endl;
	cout<<*this;

}
void Customer::toOs(ostream& os) const
{
	os << this->sCart;			 // Using operator << in Shopping cart class
}
