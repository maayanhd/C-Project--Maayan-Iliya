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

User::User(const string& username, const string& password,Address a)
	:address(a) 
{
	setUserName(username);
	setPassword(password);
};

User::User(const User& other): address(other.address) {
	setUserName(other.username);
	setPassword(other.password);

}
User::User(User&& other) : address(other.address) {
	this->username = other.username;
	this->password = other.password;

}

void User::setUserName(const string& username)
{
	this->username = username;
}
void User::setPassword(const string& password)
{
	this->password = password;
}

bool User:: operator==(const User& user)
{
	return this->username.compare(user.username) == 0;
}


User:: ~User()
{
}