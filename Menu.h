#ifndef _MENU_H
#define _MENU_H
#include "eCommerce.h"

enum userType { CUSTOMER = 0,SELLER };
class Menu
{

public:
	Menu();
	~Menu();

	void addCustomer(); // works
	void addSeller(); // works
	void addProduct(); 
	void addFeedback();
	void addToShopingCart();
	void order();
	void pay();
	void getUserInfo(userType type);// works
	void findProduct(); 
	void show(bool& exit);// works
private:
	E_Commerce system;
};
#endif
