#include "User.h"


ostream& operator<<(ostream& os, const User& user)
{
	
	os << "UserName: " << user.getUserName() << endl;
	os << "Password: " << user.getPassword() << endl;
	os << "Address: " << user.address.getStreetName();
	os << " " << (user.address.getHouseInfo())[0] << "/";
	os << (user.address.getHouseInfo())[1] << ", ";
	os << user.address.getCityName() << ", " << user.address.getCountryName() << endl;
	user.toOs(os);
	return os;
}

User::User(const char* username, const char* password, Address a)
	:address(a) {
	this->username = this->password = nullptr;
	setUserName(username);
	setPassword(password);
};

User::User(const User& other): address(other.address) {
	username = password = nullptr;
	setUserName(other.username);
	setPassword(other.password);

}
User::User(User&& other) : address(other.address) {
	this->username = other.username;
	this->password = other.password;
	other.username = nullptr;
	other.password = nullptr;

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
