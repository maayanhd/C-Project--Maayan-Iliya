#ifndef __E_COMMERCE_H
#define __E_COMMERCE_H

#include "Customer_Seller.h" 

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
		User** users;
		unsigned int numOfUsers;
		unsigned int maxSize;
		static constexpr int MAX_LENGTH = 21;
		static constexpr int NOT_FOUND = -1;
    public:
		void operator+=(User* newUser);

    public:
	    void changeUsersArrSize();
		unsigned int getNumOfUsers() const { return numOfUsers; }
		void emptyUsers();
		int findUser(const char* username);
		
public:
	bool getString(char* str, int maxSize) ;
	bool isValid(const char* str,strtype type)		const;
	void cleanBuffer();
	char* input(strtype type, int maxSize);
};


#endif

