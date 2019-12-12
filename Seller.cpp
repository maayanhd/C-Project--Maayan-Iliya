#include "Seller.h"

Seller::Seller(const char* userName, const char* password, const char* countryName, const char* cityName, const char* streetName,
	int* house): address(countryName, cityName, streetName, house), availableProducts(NULL) // Using init line for initializing the address- 
{	this->userName = nullptr;																   // reducing potential excessive copy c'tor calls
	this->password = nullptr;
	setUserName(userName);
	setPassword(password);
}
Seller:: ~Seller()
{
	delete[] this->userName;
	delete[] this->password;

	for (int i = 0; i < numOfProducts; ++i)
		delete this->availableProducts[i];

}
bool Seller::setUserName(const char * userName)
{
	if (strlen(userName) > MAX_LENGTH)
	{
		cout << "Too many characters for username" << endl;
		return false;
	}

	delete[] this->userName;
	this->userName = strdup(userName);
	return false;
}
void Seller:: setPassword(const char* password)
{
	delete[] this->password;
	this->password = strdup(password);
}
void Seller:: print() const
{
	cout << "UserName: " << this->getUserName() << endl;
	cout << "Password: " << this->getPassword() << endl;
	this->address.print();
}

int Seller:: getNextIndexToInsert()
{
	Feedback ** tempFeedbacks = new Feedback *[numOfFeedbacks + 1];

	for (int i = 0; i < numOfFeedbacks; ++i)
	{
		tempFeedbacks[i] = feedbacks[i]; // Copying the remaining 
	}
	feedbacks = tempFeedbacks; 
	++numOfFeedbacks;

	return numOfFeedbacks - 1;
}
