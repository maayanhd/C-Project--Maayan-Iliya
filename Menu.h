#ifndef _MENU_H
#define _MENU_H
#include "eCommerce.h"

enum userType { CUSTOMER = 0,SELLER };

class product;

class Menu
{

public:
	Menu();
	~Menu();

	void addCustomer(); // works
	void addSeller(); // works
	void addProduct(); 
	void addFeedback();
	void addToShoppingCart();
	void order();
	void pay();
	void getUserInfo(userType type);// works
	void findProduct(); 
	void show(bool& exit);// works
	void printHeadLine() const ;
	Customer* customerIdent();
	Seller* sellerIdent() ;

private:
	E_Commerce system;
};
#endif
