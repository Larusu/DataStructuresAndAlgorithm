//
// Activity 3 for Data Structures and Algorithm
// A program to help a local restaurant automate its breakfast billing system
//

#include <iostream>
#include <iomanip> // used for 2 decimal places
using namespace std;

const int SIZE_OF_MENU = 9;
const double TAX = 0.1; // 10 %

void getData();
void showMenu();
void printCheck(int order[], int quantity[], int count);

// Struct for holding menu item name and price
struct Menu { 
	string menuItem;
	double menuPrice;
} menu[SIZE_OF_MENU];


int main() {

	getData();
	showMenu();
	return 0;
}

// Initializing the menu[] with item names and their corresponding prices
void getData() {

	string itemMenu[SIZE_OF_MENU] = { "Plain Egg", "Bacon and Egg", "Muffin", "French Toast", "Pancake", "Cereal", "Coffee", "Tea", "Juice" };
	float prices[SIZE_OF_MENU] = { 20.00, 80.00, 65.00, 70.00, 100.00, 80.00, 50.00, 45.00, 50.00 };

	for (int i = 0; i < SIZE_OF_MENU; i++) {
		menu[i].menuItem = itemMenu[i];
		menu[i].menuPrice = prices[i];
	}
}

// Printing the item names and their prices
void showMenu() {

	int order[99];
	int quantity[99];
	int count = 0;

	char confirmOrder = ' ';

	cout << "\t  Welcome to Johnny's Restaurant" << endl;

	while (confirmOrder != 'n' && confirmOrder != 'N') {
		cout << "\t============= Menu ===============" << endl;
		cout << fixed << setprecision(2);
		for (int i = 0; i < SIZE_OF_MENU; i++) {
			cout << "\t" << i + 1 << ". " << menu[i].menuItem;

			if (menu[i].menuItem.length() < 5)
				cout << "\t\t\t";
			else if (menu[i].menuItem.length() < 13)
				cout << "\t\t";
			else
				cout << "\t";

			cout << " Php " << menu[i].menuPrice << endl;
		}
		cout << endl << "\tChoose your order [1-9]: ";
		cin >> order[count];

		if (order[count] > 9 || order[count] < 1) { // Validation for input that is more than 9 and less than 1
			cout << "\tWrong input. Must be 1 - 9 only!" << "\n\n";
			continue;
		}

		cout << "\tEnter quantity: ";
		cin >> quantity[count];

		order[count] -= 1; // minusing 1, since index starts with 0 not 1
		count++; 

		cout << "\tAdd another order? (y/n): ";
		cin >> confirmOrder;
	}
	printCheck(order, quantity, count);
}

void printCheck(int order[], int quantity[], int count) {

	double amountDue = 0;
	double totalTax;

	// calculating the amount and the tax
	for (int i = 0; i < count; i++) {
		amountDue += menu[order[i]].menuPrice * quantity[i];
	}
	totalTax = amountDue * TAX;
	amountDue += totalTax;

	// Output for the bill
	cout << endl << "\t==================================" << endl;
	cout << "\tYour bill is: " << endl;
	cout << fixed << setprecision(2);
	for (int i = 0; i < count; i++) {
		cout << '\t' << quantity[i] << "  " << menu[order[i]].menuItem;
		if (menu[order[i]].menuItem.length() < 5)
			cout << "\t\t\t";
		else if (menu[order[i]].menuItem.length() < 13)
			cout << "\t\t";
		else
			cout << "\t";

		cout << " Php " << menu[order[i]].menuPrice * quantity[i] << endl;
	}
	cout << "\t   Tax \t\t\t Php " << totalTax << endl;
	cout << "\t   Amount Due \t\t Php " << amountDue << endl;
}
