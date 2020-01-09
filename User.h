#ifndef __USER_H 
#define __USER_H 
#include "Address.h"

class User // Abstract class
{
	protected: 
		char* username;					// UserName of Seller 
		char* password;					// Password of The seller for logging into the system
		Address address;				// The Address of the seller
		
	public:
		User(const char* username, const char* password, Address a);
		User(const User &);	
		User(User&&);
		// we do not use copy c'tor in the descendants	 
		virtual ~User();
		
	public: 
		const Address &getAddress() const { return address; }
		void setUserName(const char* username);
		void setPassword(const char* password);
		inline const char* getUserName() const 
			{ return username; };
		inline const char* getPassword() const 
			{ return password; };

	public:
		virtual void toOs(ostream& os) const = 0;
		friend ostream& operator<<(ostream& os, const User& user);
};


#endif