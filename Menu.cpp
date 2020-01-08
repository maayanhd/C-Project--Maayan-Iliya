#include "Menu.h"


Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::getUserInfo() {
	
	User* user = userIdent();

	cout << user << endl;
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
void Menu::newUser(bool isSeller, bool isCustomer) {
	User * res;
	char* username = nullptr, *password = nullptr;
	char *country = nullptr, *city = nullptr, *street = nullptr;
	int house[2];
	int i = 0;
	while (i != system.NOT_FOUND)  // Make sure that we don't have user with the same username
	{
		cout << "Please enter userName:\n";
		username = system.input(MIXED, system.MAX_LENGTH);
		i = system.findUser(username);
		if (i != system.NOT_FOUND)
		{
			cout << "The username:" << username << " already exists in the system, please try again" << endl;
			delete[] username;
		}
	}
	cout << "Please Enter A Password\n";
	password = system.input(FREESTYLE, system.MAX_LENGTH);
	cout << "Please Enter A Country\n";
	country = system.input(LETTERS, system.MAX_LENGTH);
	cout << "Please Enter A City\n";
	city = system.input(LETTERS, system.MAX_LENGTH);
	cout << "Please Enter A Street\n";
	street = system.input(MIXED, system.MAX_LENGTH);
	cout << "Enter the house number" << endl;
	cin >> house[0];
	cout << "Enter the entrance number" << endl;
	cin >> house[1];
	while (house[0] <= 0 || house[1] <= 0) {
		cout << "House and entrance numbers should be a positive numbers " << endl;
		cout << "Please try again" << endl;
		cout << "House number:\n";    cin >> house[0];
		cout << "Entrance number:\n"; cin >> house[1];
	}
	if (isSeller && isCustomer) {
		Address temp(country, city, street, house);
	res = new Customer_Seller(Customer(username, password, temp)
			, Seller(username, password, temp));

	}
	else if (isCustomer) {
		res = new Customer(username, password, Address(country, city, street, house));
	}
	else // if seller
	{
		res = new Seller(username, password, Address(country, city, street, house));
	}
	delete[] username;
	delete[] password;
	delete[] country;
	delete[] city;
	delete[] street;
	system += res;
}

User* Menu::userIdent() {

	char* username = new char[system.MAX_LENGTH];
	User* user = nullptr;
	int i;
	cout << "Please enter a Username: " << endl;
	system.getString(username, system.MAX_LENGTH);
	i = system.findUser(username);
	while (i == system.NOT_FOUND)
	{
		cout << "The username you entered wasn't found, please try again or press 0 to return to the menu" << endl;
		system.getString(username, system.MAX_LENGTH);
		if (username[0] == '0') {
			delete[] username;
			return nullptr;
		}
		i = system.findUser(username);
		
	}
	delete[] username;
	return system.users[i];
}

void Menu::show(bool& exit) {
	//std::system("CLS");
	cout << endl;
	int input;
	printHeadLine();
	do{
		cin.clear();
	cout << "Welcome to the E_Commerce system, choose one of the below options: " << endl;
	cout << "1.New customer account" << endl;
	cout << "2.New seller account" << endl;
	cout << "3.New seller-customer" << endl;
	cout << "4.Add new product" << endl;
	cout << "5.Leave feedback to seller" << endl;
	cout << "6.Add product to shopping cart" << endl;
	cout << "7.Order products" << endl;
	cout << "8.Order payment" << endl;
	cout << "9.View user info" << endl;
	cout << "10. Show All Customers that are Sellers" << endl;
	cout << "11.Find product by name" << endl;
	cout << "12.Exit" << endl << endl;
	cin >> input;
	system.cleanBuffer();
	} while (cin.fail());


	cin.clear();

	switch (input) {
	case 1:
		newUser(true, false);
		break;
	case 2:
		newUser(true, false);
		break;
	case 3:
		newUser(true, true);
		break;
	case 4:
		addProduct();
		break;
	case 5:
		addFeedback();
		break;
	case 6:
		addToShoppingCart();
		break;
	case 7:
		order();
		break;
	case 8:
		pay();
		break;
	case 9:
		getUserInfo();
		break;
	case 10:
		showAllCustomersSellers();
		break;
	case 11:
		findProduct();
		break;
	case 12:
		exit = true;
		break;
	}
}

void Menu:: showAllCustomersSellers() const
{
	Customer_Seller* customerSeller = nullptr;
	for (int i = 0; i < system.numOfUsers; ++i)
	{
		customerSeller = dynamic_cast<Customer_Seller*>(system.users[i]);
		if (customerSeller)
			cout << i+1<<". " << customerSeller << endl;
	}
}

void Menu::addProduct() {

	Seller* seller = dynamic_cast <Seller*>(userIdent());
	Category ctg;
	int option;
	float price;
	char* nameOfProduct;
	if (seller != nullptr) {
		cout << " Please enter the name of the product you'd like to add:\n";
		nameOfProduct = system.input(FREESTYLE, system.MAX_LENGTH);
		while (seller->ProductExists(nameOfProduct)) // Validation of product name
		{
			cout << "a Product with an identical name has already been added to the seller, please try again.\n";
			delete[] nameOfProduct;
			nameOfProduct = system.input(FREESTYLE, system.MAX_LENGTH);
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
		delete[] nameOfProduct;
	}
	else
		cout << "No matching seller to the username you entered!\n";
}

void Menu::pay() {
	// already checked whether the returned is a customer
	Customer* customer = dynamic_cast<Customer*>(userIdent());
		
	if (customer != nullptr) {
		float totalPrice = (customer)->getCart().getTotalPrice();
		if (totalPrice == 0)
			cout << " The shopping cart is empty" << endl;
		else {
			cout << "The payment process succeeded." << endl;
			cout << "Total price of the shopping cart: " << totalPrice << endl;;
			customer->getCart().toEmpty();
		}
	}
	else
		cout << " No customer matching the username you entered!\n";
}

void Menu::addFeedback() {
	Customer* customer = dynamic_cast<Customer*> (userIdent());
	if (customer != nullptr)
		customer->addFeedback();
	else
		cout << "No matching customer to the username you entered!\n";
}

void Menu::addToShoppingCart() {
	Seller* currSeller = nullptr;
	Customer* customer = dynamic_cast<Customer*> (userIdent());
	Product** prodArr = nullptr;
	Product* prod = nullptr;
	int option = 1, choice;
	int numOfProducts;
	if (customer != nullptr)
	{
		if (system.numOfUsers > 0)
			cout << "Choose one of the products listed below" << endl;
		for (unsigned int i = 0; i < system.numOfUsers; ++i) {
			currSeller = dynamic_cast<Seller*>(system.users[i]);
			if (currSeller)
			{
				prodArr = currSeller->getProducts();
				numOfProducts = currSeller->getNumOfProducts();
				for (int j = 0; j < numOfProducts; ++j) {
					cout << option << ". ";
					prodArr[j]->print();
					cout << endl;
					option++;
				}
			}
		}
		if (option == 1)
			cout << "There is no products at this moment" << endl;

		{
			cin >> choice;
			system.cleanBuffer();
			if (choice > option)
				cout << "The option you specified doesn't exist" << endl;
			else {
				unsigned int i;
				for (i = 0; i < system.numOfUsers && choice >0; ++i) {
					currSeller = dynamic_cast<Seller*>(system.users[i]);
					if (currSeller)
					{
						numOfProducts = currSeller->getNumOfProducts();
						choice -= numOfProducts;
					}
				}
				choice += numOfProducts;
				prod = currSeller->getProducts()[choice - 1];
				if (customer->getCart().existsIn(prod))
					cout << "This product already in your shopping cart" << endl;
				else
				{
					customer->getCart().add(prod);
					cout << prod->getName() << " added to your shopping cart" << endl;
				}

			}
		}
	}
	else
		cout << "No matching customer to the username you entered!\n";
}
void Menu::order() {
	Customer* customer = dynamic_cast<Customer*>(userIdent());
	if (customer != nullptr)
		customer->order();
	else
		cout << "No matching customer to the username you entered!\n";
}

void Menu::findProduct() {
	char* prodName = new char[system.MAX_LENGTH];
	int count = 0;
	cout << "Enter a product name to find" << endl;
	system.getString(prodName, system.MAX_LENGTH);
	Product** prodArr;
	Seller* currSeller;
	int numOfProducts;
	for (unsigned int i = 0; i < system.numOfUsers; ++i) {
		currSeller = dynamic_cast<Seller*> (system.users[i]);
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