#include "User.h"

#include "Customer_Seller.h"
ostream& operator<<(ostream& os, const User& user)
{
	if (typeid(os) != typeid(ofstream)) {
		os << "UserName: " << user.getUserName() << endl;
		os << "Password: " << user.getPassword() << endl;
		os << "Address: " << user.address.getStreetName();
		os << " " << (user.address.getHouseInfo())[0] << "/";
		os << (user.address.getHouseInfo())[1] << ", ";
		os << user.address.getCityName() << ", " << user.address.getCountryName() << endl;
		user.toOs(os);
	}
	else
	{
		int identType;
		if (typeid(user) == typeid(Customer_Seller))// save Customer-Seller as2
			identType = 2;
		else if (typeid(user) == typeid(Customer))// Save Customer as 1 
			identType = 1; 
		else // Save Seller as 0
			identType = 0;

		os << identType << user.getUserName() << "," << user.getPassword() << ",";
		os << user.address.getCountryName() << "," << user.address.getCountryName() << ",";
		os << user.address.getStreetName() << "," << (user.address.getHouseInfo())[0] << ",";
		os << (user.address.getHouseInfo())[1] << endl;
		
	}
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
User::User(User&& other) : address(move(other.address)) {
    username = move(other.username);
	password = move(other.password);

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