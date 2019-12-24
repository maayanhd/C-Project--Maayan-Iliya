#include "User.h"


ostream& operator<<(ostream& os, const User& user)
{
	os << "UserName: " << user.getUserName() << endl;
	os << "Password: " << user.getPassword() << endl;
	os << "Address: " << user.address.getStreetName();
	os << " " << (user.address.getHouseInfo())[0] << "/";
	os << (user.address.getHouseInfo())[1] << ", ";
	os << user.address.getCityName() << ", " << user.address.getCountryName() << endl;
	// we need to check this
	user.toOs(os);
	return os;
}

User::User(const char* username, const char* password, const char* countryName, const char* cityName, const char* streetName, const int* house)
	:address(countryName, cityName, streetName, house) {
	setUserName(username);
	setPassword(password);
};

User::~User() {
	delete[] this->username;
	delete[] this->password;

}

void User::setUserName(const char* username)
{
	delete[] this->username;
	this->username = strdup(username);
}
void User::setPassword(const char* password)
{
	delete[] this->password;
	this->password = strdup(password);
}

User:: ~User()
{
	// Releasing the strings of username and password 
	delete[] this->username;
	delete[] this->password;
}
