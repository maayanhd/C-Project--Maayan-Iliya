#include "Menu.h"


Menu::Menu() {


}

Menu::~Menu(){}

void Menu::addCustomer() {

	Customer** newCustomerArr;
	Customer* res = system.newCustomer();
	newCustomerArr = system.changeCustomersArrSize();
	newCustomerArr[system.currentNumOfCustomers - 1] = res;
	delete[] system.customers;
	system.customers = newCustomerArr;

}

	void Menu::addSeller() {

		Seller** newSellersArr;
		Seller* res = system.newSeller();
		newSellersArr = system.changeSellersArrSize();
		newSellersArr[system.currentNumOfSellers - 1] = res;
		delete[] system.sellers;
		system.sellers = newSellersArr;

	}

	void Menu::getUserInfo(userType type) {
		char* input = new char[system.MAX_LENGTH];
		int i;
		cout << "Please enter your username" << endl;
		system.getString(input, system.MAX_LENGTH);
		switch (type) {

		case CUSTOMER:
			i = system.findCustomer(input);
			if (i != system.NOT_FOUND)
				system.customers[i]->print();
			break;
		case SELLER:
			i = system.findSeller(input);
			if (i != system.NOT_FOUND)
				system.sellers[i]->print();
			break;
}
		delete[] input;
	}

	void Menu::show(bool& exit) {
		int input;
		cout << "Welcome to the E_Commerce, choose one of the options below" << endl;
		cout << "1.New customer account" << endl;
		cout << "2.New seller account" << endl;
		cout << "3.Add new product" << endl;
		cout << "4.Leave feedback to seller" << endl;
		cout << "5.Add product to shopping cart" << endl;
		cout << "6.Order products" << endl;
		cout << "7.Order payment" << endl;
		cout << "8.View customer info" << endl;
		cout << "9.View seller info" << endl;
		cout << "10.Find product by name" << endl;
		cout << "11.Exit" << endl;
		cin >> input;
		system.cleanBuffer();
		switch (input) {
		case 1:
			addCustomer();
			break;
		case 2:
			addSeller();
			break;
		case 3:
			addProduct();
			break;
		case 4:
			addFeedback();
			break;
		case 5:
			addToShopingCart(); 
			break;
		case 6:
			order();
			break;
		case 7:
			pay(); 
			break;
		case 8:
			getUserInfo(CUSTOMER); 
			break;
		case 9:
			getUserInfo(SELLER);
			break;
		case 10:
			findProduct();
			break;
		case 11:
			exit = true;
			break;
		}

}

	void Menu::addProduct() {
		char* username = new char[system.MAX_LENGTH];
		Seller* seller;
		int i;
		system.getString(username,system.MAX_LENGTH);
		i = system.findSeller(username);
		while (i == system.NOT_FOUND)
		{
			cout << "Seller with username you entered wasn't found, please try again" << endl;
			system.getString(username, system.MAX_LENGTH);
			i = system.findSeller(username);
		}
		delete[] username;
		seller = system.sellers[i];
		//seller.addProduct(); // need to write the function

	}

	void Menu::pay() {

		char* username = new char[system.MAX_LENGTH];
		Customer* customer;
		int i;
		system.getString(username, system.MAX_LENGTH);
		i = system.findCustomer(username);
		while (i == system.NOT_FOUND)
		{
			cout << "Customer with username you entered wasn't found, please try again" << endl;
			system.getString(username, system.MAX_LENGTH);
			i = system.findCustomer(username);
		}
		delete[] username;
		customer = system.customers[i];
		cout << "The payment proccess succeeded." << endl;
		cout << "Total price of the deal: " << customer->getShoppingCartTotalPrice();
		customer->pay();
	}

	void Menu::addFeedback() {
		char* username = new char[system.MAX_LENGTH];
		Customer* customer;
		int i;
		system.getString(username, system.MAX_LENGTH);
		i = system.findCustomer(username);
		while (i == system.NOT_FOUND)
		{
			cout << "Customer with username you entered wasn't found, please try again" << endl;
			system.getString(username, system.MAX_LENGTH);
			i = system.findCustomer(username);
		}
		delete[] username;
		customer = system.customers[i];
		customer->addFeedback();

	}

	void Menu::addToShopingCart() {



	}

	void Menu::order() {



	}

	void Menu::findProduct() {
		char* prodName = new char[system.MAX_LENGTH];
		system.getString(prodName, system.MAX_LENGTH);
		const Product** prodArr;
		Seller* currSeller;
		int numOfProducts;
		for (int i = 0; i < system.currentNumOfSellers;++i) {
			currSeller = system.sellers[i];
			numOfProducts = currSeller->getNumOfProducts();
			prodArr = currSeller->getProducts();
			for (int j = 0; j < numOfProducts; ++j)
			{
				if (strcmp(prodArr[j]->getName, prodName) == 0)
					prodArr[j]->print();
			}
		}
		delete[] prodName;

	}