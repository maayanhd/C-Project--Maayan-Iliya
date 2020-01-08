#ifndef _MENU_H
#define _MENU_H
#include "eCommerce.h"

class product;

class Menu
{

public:
	
	Menu();
	~Menu();

	void addProduct(); 
	void newUser(bool isCustomer,bool isSeller);
	void addFeedback();
	void addToShoppingCart();
	void order();
	void pay();
	void getUserInfo();
	void showAllCustomersSellers() const;
	void findProduct(); 
	void show(bool& exit);
	void printHeadLine()			const;
	User* userIdent();

private:
	E_Commerce system;
};
#endif
