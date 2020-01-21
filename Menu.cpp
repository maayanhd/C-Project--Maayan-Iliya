#include "Menu.h"


Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::getUserInfo() {
	
	User* user = userIdent();

	cout << *user << endl;
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
	User * res = nullptr;
	string username, password;
	string country, city, street;
	int house[2];
	bool isValid = false;
	while (!isValid)  // Make sure that we don't have user with the same username
	{
		cout << "Please enter userName:\n";
		username = system.input(MIXED);
		res = system.findUser(username);
		if (res!=NULL)
			cout << "The username:" << username << " already exists in the system, please try again" << endl;		
		else
			isValid = true;
	}
	cout << "Please Enter A Password\n";
	password = system.input(FREESTYLE);
	cout << "Please Enter A Country\n";
	country = system.input(LETTERS);
	cout << "Please Enter A City\n";
	city = system.input(LETTERS);
	cout << "Please Enter A Street\n";
	street = system.input(MIXED);
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
	Address address(country, city, street, house);
	if (isSeller && isCustomer) {
		Customer c(username, password, address);
		Seller s(username, password, address);
		res = new Customer_Seller(c, s);
	}
	else if (isCustomer) {
		res = new Customer(username, password, address);
	}
	else // if seller
	{
		res = new Seller(username, password, address);
	}
	system += *res;
	
}

User* Menu::userIdent() {
	string username;
	User* user = nullptr;
	cout << "Please enter a Username: " << endl;
	std::getline(std::cin, username);
	user= system.findUser(username);
	while (user==NULL)
	{
		cout << "The username you entered wasn't found, please try again or press 0 to return to the menu" << endl;
		std::getline(std::cin, username);
		if (username[0] == '0')
			return nullptr;
		user = system.findUser(username);
		
	}
	return user;
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
	cout << "12.Operator menu" << endl;
	cout << "13. Load from previous save" << endl;
	cout << "14.Exit" << endl << endl;
	cin >> input;
	cleanBuffer();
	} while (cin.fail());


	cin.clear();

	switch (input) {
	case 1:
		newUser(false, true);
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
		operatorMenu();
		break;
	case 13:
		system.load();
		break;
	case 14:
		system.save();
		exit = true;
		break;
	}
}
void Menu::operatorMenu() {


	cout << endl;
	int input;
	int subInput;
	printHeadLine();
	do {
		cin.clear();
		cout << "Operator menu, choose one of the below options: " << endl;
		cout << "1.+=" << endl;
		cout << "2.>" << endl;
		cout << "3.<<" << endl;
		cin >> input;
		cleanBuffer();
	} while (cin.fail());
	cin.clear();
	switch (input){
	case 1:
		do {
			cout << "Choose one of the below options: " << endl;
			cout << "1.Add Customer" << endl;
			cout << "2.Add Seller" << endl;
			cout << "3.Add Customer-Seller" << endl;
			cin >> subInput;
			cleanBuffer();
		} while (cin.fail());
		cin.clear();
		switch (subInput)
		{
		case 1:
			newUser(false, true);
			break;
		case 2:
			newUser(true, false);
			break;
		case 3:
			newUser(true, true);
			break;
		}
		break;
	case 2:
		compareCustomers();
		break;
	case 3:
		getUserInfo();
		break;
	}
}

void Menu::compareCustomers() {
	Customer* c1 = dynamic_cast<Customer*>(userIdent());
	Customer* c2 = dynamic_cast<Customer*>(userIdent());
	if (c1 && c2) {
		if (*c1 > *c2)
			cout << c1->getUserName() << "'s shopping cart total price is bigger." << endl;
		else if (*c2 > *c1)
			cout << c2->getUserName() << "'s shopping cart total price is bigger." << endl;
		else cout << "Both customers have the same total price in their shopping carts." << endl;
	}
	else
		cout << "No matching customers to the usernames you entered" << endl;


}

void Menu:: showAllCustomersSellers() const
{
	Customer_Seller* customerSeller = nullptr;
	
	vector <User*> ::const_iterator itr = system.users.begin();
	vector <User*> ::const_iterator itrEnd = system.users.end();
	
	for ( ; itr!=itrEnd; ++itr)
	{
		customerSeller = dynamic_cast<Customer_Seller*>(*itr);
		if (customerSeller)
			cout << *(customerSeller) << endl;
	}
}

void Menu::addProduct() {

	Seller* seller = dynamic_cast <Seller*>(userIdent());
	Category ctg;
	int option;
	float price;
	string nameOfProduct;
	if (seller != nullptr) {
		cout << " Please enter the name of the product you'd like to add:\n";
		nameOfProduct = system.input(FREESTYLE);
		while (seller->ProductExists(nameOfProduct)) // Validation of product name
		{
			cout << "a Product with an identical name has already been added to the seller, please try again.\n";
			nameOfProduct = system.input(FREESTYLE);
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
			ShoppingCart& cart = customer->getCart();
			cart.toEmpty();
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
	User* user = userIdent();
	Customer* customer = dynamic_cast<Customer*>(user);
	Array<Product*> prodArr;
	Product* prod = nullptr;
	int option = 1, choice;
	int numOfProducts;
	if (customer != nullptr)
	{
		if (!system.users.empty())
			cout << "Choose one of the products listed below" << endl;

		vector<User*>::iterator itr = system.users.begin();
		vector<User*>::iterator itrEnd = system.users.end();

		for (; itr != itrEnd ; ++itr) {
			currSeller = dynamic_cast<Seller*>(*itr);
			if (currSeller && (User*)currSeller!=(User*)customer)
			{
				prodArr = currSeller->getProducts();
				numOfProducts = prodArr.getSize();
				for (int j = 0; j < numOfProducts; ++j) {
					cout << option << ". ";
					cout<<*(prodArr[j]);
					cout << endl;
					option++;
				}
			}
		}
		if (option == 1)
			cout << "There is no products at this moment" << endl;
		else
		{
			cin >> choice;
			cleanBuffer();
			if (choice > option)
				cout << "The option you specified doesn't exist" << endl;
			else {
				vector<User*>::iterator itr = system.users.begin(); // Updating the iterator of users
				for(; itr != itrEnd && choice > 0; ++itr) {
					currSeller = dynamic_cast<Seller*>(*itr);
					if (currSeller && (User*)currSeller!=(User*)customer)
					{
						numOfProducts = currSeller->getProducts().getSize(); // Using iterator to het number of products 
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
	string prodName;
	int count = 0;
	cout << "Enter a product name to find" << endl;
	getline(std::cin, prodName);
	Array<Product*> prodArr;
	Seller* currSeller;
	unsigned int size = system.users.size();
	vector<User*>::iterator itr = system.users.begin();
	vector<User*>::iterator itrEnd = system.users.end();

	for (; itr != itrEnd; ++itr) {
		currSeller = dynamic_cast<Seller*> (*itr);
		if (currSeller) {

			prodArr = currSeller->getProducts();
			for (unsigned int j = 0; j < size; ++j)
			{
				if (prodName.compare( (*itr)->getUserName() ) == 0) {
					cout << *(prodArr[j]);
					count++;
				}
			}
		}
	}
	if (count == 0)
		cout << "This product wasn't found" << endl;

}