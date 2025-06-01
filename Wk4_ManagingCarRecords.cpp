//
// Formulative test
// A program that manage car records for a small garage using a Structure
//
#include <iostream>
using namespace std;

const int MAXSIZE = 4;

struct Car {
	string model;
	string manufacturer;
	int year;
	long price;
}car[MAXSIZE];

int main() {

	// INITIALIZE
	string models[] =		 {"Civic", "Vios", "Prius", "NV350"};
	string manufacturers[] = { "Honda", "Toyota", "Toyota", "Nissan"};
	int years[] =			 { 2018, 2014, 2020, 2021};
	long prices[] =		 { 900000, 700000, 1800000, 1900000};
	int highest = 0; // storing the index of the highest price
	
	for (int i = 0; i < MAXSIZE; i++) {
		car[i].model = models[i];
		car[i].manufacturer = manufacturers[i];
		car[i].year = years[i];
		car[i].price = prices[i];
	}

	// OUTPUT
	// Print the details of all cars in the inventory
	cout << "Car Inventory:" << endl;

	for (int i = 0; i < MAXSIZE; i++) {
		cout << car[i].model << "\t" << car[i].manufacturer << '\t' << car[i].year << '\t' << car[i].price << endl;
	}

	cout << "\nCars Manufactured after 2015:" << endl;
	for (int i = 0; i < MAXSIZE; i++) {
		// Logic if cars that is manufactured after 2015
		if (car[i].year > 2015) {
			cout << car[i].model << " (" << car[i].year << ')' << endl;
		}
		// checking the highest price then assigning it into 'highest' variable
		if (car[i].price > car[highest].price) {
			highest = i;
		}
	}
	cout << "\nMost expensive car: \n" << car[highest].model << " by " << car[highest].manufacturer << " - P" << car[highest].price << endl;

	//multiplicationTable();
}
