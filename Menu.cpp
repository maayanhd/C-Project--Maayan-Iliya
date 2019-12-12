#include "Menu.h"


Menu::Menu() {


}

Menu::~Menu(){}

void Menu::addCustomer() {

	Customer** newCustomerArr;
	Customer* res = system.newCustomer();
	newCustomerArr = system.changeCustomersArrSize(++system.currentNumOfCustomers);
	newCustomerArr[system.currentNumOfCustomers - 1] = res;
	delete[] system.customers;
	system.customers = newCustomerArr;

}

	void Menu::addSeller() {

		Seller** newSellersArr;
		Seller* res = system.newSeller();
		newSellersArr = system.changeSellersArrSize(++system.currentNumOfSellers);
		newSellersArr[system.currentNumOfSellers - 1] = res;
		delete[] system.sellers;
		system.sellers = newSellersArr;

	}

	void Menu::getUserInfo(userType type) {
		char* input = nullptr;
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
				system.customers[i]->print();
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
		switch (input) {

		case 11:
			exit = true;
			break;
		}

}