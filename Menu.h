#ifndef _MENU_H
#define _MENU_H
#include "eCommerce.h"
class Menu
{

public:
	Menu();
	~Menu();

	void addCustomer();
	void addSeller();
	void addProduct();
	void addFeedback();
	void addToShopingCart();
	void order();
	void pay();
	void clientInfo();
	void sellerInfo();
	void findProduct();
	void exit();
	void show();
private:
	E_Commerce system;
};
#endif
