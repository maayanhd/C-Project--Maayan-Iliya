#ifndef __E_COMMERCE_H
#define __E_COMMERCE_H

#include "Customer_Seller.h"
#include <vector>
// Responsible to reallocate the arrays - will be used for adding/removing sellers/customers  - 
// defined as arrays of pointers to class objects to avoid the need for default constructor- which will not 
// be recommended logically
enum strtype { LETTERS = 0, MIXED,FREESTYLE };

class E_Commerce
{
    private:
	vector<User*> users;
	public:
		E_Commerce();
		E_Commerce(const E_Commerce&) = delete; // No logic reason for copying the fields of the eCommerce 
		~E_Commerce();  
		friend class Menu;
    
		void save();
		void load();
		string input(strtype type);
		void emptyUsers();
		User* findUser(const string& username);
		bool isValid(const string& str,strtype type)		const;

public:
	void operator+=(User& newUser);


};


#endif

