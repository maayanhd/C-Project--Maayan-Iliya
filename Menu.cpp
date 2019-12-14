#include "Menu.h"


Menu::Menu() {
	cout << " Menu -  c'tor"; // Debugging
}

Menu::~Menu() {
	cout << " Menu -  d'tor"; // Debugging
}

void Menu::addCustomer() {

	Customer** newCustomerArr = nullptr;
	Customer* res = system.newCustomer();
	newCustomerArr = system.changeCustomersArrSize();
	newCustomerArr[system.currentNumOfCustomers - 1] = res;
	delete[] system.customers;
	system.customers = newCustomerArr;

}

void Menu::addSeller() {

	Seller** newSellersArr = nullptr;
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
void Menu::printHeadLine()
{
	auto r1 = R"( __  __                  )";
	auto r2 = R"(|  \/  | ___ _ __  _   _ )";
	auto r3 = R"(| |\/| |/ _ \ '_ \| | | |)";
	auto r4 = R"(| |  | |  __/ | | | |_| |)";
	auto r5 = R"(|_|  |_|\___|_| |_|\__,_|)";
	cout << r1 << endl;
	cout << r2 << endl;
	cout << r3 << endl;
	cout << r4 << endl;
	cout << r5 << endl;
}
void Menu::show(bool& exit) {
	cout << endl;
	int input;
	printHeadLine();
	cout << "Welcome to the E_Commerce system, choose one of the below options: " << endl;
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
	cout << "11.Exit" << endl << endl;
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

	Seller* seller = nullptr;
	int i;
	Category ctg;
	int option;
	float price;

	// Asking for a user name 
	char* username = new char[system.MAX_LENGTH];
	cout << " Please enter a Username:\n";
	system.getString(username, system.MAX_LENGTH);
	i = system.findSeller(username);
	while (i == system.NOT_FOUND) // validation of username
	{
		cout << "No seller matching the username you have just entered in the system, please try again.\n" << endl;
		system.getString(username, system.MAX_LENGTH);
		i = system.findSeller(username);
	}
	delete[] username;
	seller = system.sellers[i];
	// Asking for a product name
	char* nameOfProduct = new char[system.MAX_LENGTH];
	cout << " Please enter the name of the product you'd like to add:\n";
	system.getString(nameOfProduct, system.MAX_LENGTH);
	while (seller->ProductExists(nameOfProduct)) // Validation of product name
	{
		cout << "a Product with an identical name has already been added to the seller, please try again.\n";
		system.getString(nameOfProduct, system.MAX_LENGTH);
	}
	// Asking for a category
	cout << " Please choose a category for the product:\n" << "choose an option by pressing the relevant number:\n";
	cout << " 1 - Children\n 2 - Electricity\n 3 - Clothing\n 4 - Office Supply\n" << endl;
	cin >> option;
	while (!seller->optionIsValid(option)) // Category validation
	{
		cout << "Invalid option, choose again:\n" << " 1 - Children\n 2 - Electricity\n 3 - Clothing\n 4 - Office Supply\n";
		cin >> option;
	}
	ctg = (Category)(option - 1);
	// Asking for a price
	cout << "Please enter a price for the product:\n";
	cin >> price;
	while (!seller->priceIsValid(price))
	{
		cout << "Invalid price, please try again\n";
		cin >> price;
	}
	seller->addProduct(nameOfProduct, price, ctg); // Adding the product to into the "list" of available products of the seller 
}

void Menu::pay() {

	char* username = new char[system.MAX_LENGTH];
	Customer* customer = nullptr;
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
	cout << "The payment process succeeded." << endl;
	cout << "Total price of the shopping cart: " << customer->getShoppingCartTotalPrice() << endl;;
	customer->pay();
}

void Menu::addFeedback() {
	char* username = new char[system.MAX_LENGTH];
	Customer* customer = nullptr;
	int i;
	cout << "Please enter username:\n";
	system.getString(username, system.MAX_LENGTH);
	i = system.findCustomer(username);
	while (i == system.NOT_FOUND) // Username validation
	{
		cout << "No customer matching the username you have just entered in the system, please try again" << endl;
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
	Product** prodArr;
	Seller* currSeller;
	int numOfProducts;
	for (unsigned int i = 0; i < system.currentNumOfSellers; ++i) {
		currSeller = system.sellers[i];
		numOfProducts = currSeller->getNumOfProducts();
		prodArr = currSeller->getProducts();
		for (int j = 0; j < numOfProducts; ++j)
		{
			if (strcmp(prodArr[j]->getName(), prodName) == 0)
				prodArr[j]->print();
		}
	}
	delete[] prodName;

}