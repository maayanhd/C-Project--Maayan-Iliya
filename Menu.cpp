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
	Customer* customer = nullptr;
	Seller* seller = nullptr;
	switch (type) 
	{
	case CUSTOMER:
		customer = customerIdent();
		customer->print();
		break;
	case SELLER:
		seller = sellerIdent();
		seller->print();
		break;
	}
}
void Menu::printHeadLine() const
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

Customer* Menu::customerIdent() {

	char* username = new char[system.MAX_LENGTH];
	Customer* customer = nullptr;
	int i;
	cout << "Please enter a Username: " << endl;
	system.getString(username, system.MAX_LENGTH);
	i = system.findCustomer(username);
	while (i == system.NOT_FOUND)
	{
		cout << "Customer with username you entered wasn't found, please try again" << endl;
		system.getString(username, system.MAX_LENGTH);
		i = system.findCustomer(username);
	}
	delete[] username;
	return system.customers[i];
}

Seller* Menu::sellerIdent() {
	// Asking for a user name
	int i;
	char* username = new char[system.MAX_LENGTH];
	cout << "Please enter a Username: " << endl;
	system.getString(username, system.MAX_LENGTH);
	i = system.findSeller(username);
	while (i == system.NOT_FOUND) // validation of username
	{
		cout << "No seller matching the username you have just entered in the system, please try again.\n" << endl;
		system.getString(username, system.MAX_LENGTH);
		i = system.findSeller(username);
	}
	delete[] username;
	return system.sellers[i];

}
void Menu::show(bool& exit){
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
		addToShoppingCart();
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

	Seller* seller = sellerIdent();
	Category ctg;
	int option;
	float price;

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

	Customer* customer = customerIdent();
	float totalPrice = customer->getCart().getTotalPrice();
	if (totalPrice == 0)
		cout << " The shopping cart is empty" << endl;
	else {
		cout << "The payment process succeeded." << endl;
		cout << "Total price of the shopping cart: " << totalPrice << endl;;
		customer->getCart().toEmpty();
	}
}

void Menu::addFeedback() {
	Customer* customer = customerIdent();
	customer->addFeedback();
}

void Menu::addToShoppingCart() {
	Seller* currSeller = nullptr;
	Customer* customer = customerIdent();
	Product** prodArr = nullptr;
	int option = 1, choice;
	int numOfProducts;

	if (system.currentNumOfSellers > 0)
		cout << "Choose one of the products listed below" << endl;
	for (unsigned int i = 0; i <system.currentNumOfSellers; ++i) {
		currSeller = system.sellers[i];
		prodArr = currSeller->getProducts();
		numOfProducts = currSeller->getNumOfProducts();
		for (int j = 0; j <numOfProducts; ++j) {
			cout << option << ". ";
			prodArr[i]->print();
			option++;
		}
	}
	if (option == 1)
		cout << "There is no products at this moment" << endl;
	else
	{
		cin >> choice;
		system.cleanBuffer();
		if (choice > option)
			cout << "The option you specified doesn't exist" << endl;
		else {
			for (unsigned int i = 0; i < system.currentNumOfSellers && choice - numOfProducts>0; ++i) {
				currSeller = system.sellers[i];
				numOfProducts = currSeller->getNumOfProducts();
				choice -= numOfProducts;
			}
			customer->getCart().add(currSeller->getProducts()[choice - 1]);
		}
	}
}
void Menu::order() {
	Customer* customer = customerIdent();
	customer->order();
}

void Menu::findProduct() {
	char* prodName = new char[system.MAX_LENGTH];
	int count = 0;
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
			if (strcmp(prodArr[j]->getName(), prodName) == 0) {
				prodArr[j]->print();
				count++;
			}
		}
	}
	if (count == 0)
		cout << "This product wasn't found" << endl;
	delete[] prodName;

}