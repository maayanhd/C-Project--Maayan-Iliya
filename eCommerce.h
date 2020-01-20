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
	public:
		E_Commerce();
		E_Commerce(const E_Commerce&) = delete; // No logic reason for copying the fields of the eCommerce 
		
		// Logically the e-commerce system does not suppose to 'distract it self' -
		// but we must deallocate the memory allocated during the program 

		~E_Commerce();  
		friend class Menu;
	// a Global function for input check                                                          
	private:
		vector<User*> users;
		unsigned int maxSize;
		static constexpr int MAX_LENGTH = 21;
		static constexpr int NOT_FOUND = -1;
    public:
		void operator+=(User* newUser);

    public:
		string input(strtype type, int maxSize);
		void emptyUsers();
		int findUser(const string& username);
		
public:

	bool isValid(const string& str,strtype type)		const;

};


#endif

