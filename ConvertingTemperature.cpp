//
// Formative Test
// A program that uses functions to convert temperatures
//
#include <iostream>
using namespace std;

float celsiusToFahrenheit(float c);
float fahrenheitToCelsius(float f);
float celsiusToKelvin(float c);
float kelvinToCelsius(float k);
void showMenu();

int main() {
	float num;
	int option;

	do {
		cout << endl;
		showMenu();
		cin >> option;
		switch (option) {
		case 1:
			cout << "Enter Temperature in Celsius: ";
			cin >> num;
			cout << "Temperature in Fahrenheit: " << celsiusToFahrenheit(num) << endl;
			break;
		case 2:
			cout << "Enter Temperature in Fahrenheit: ";
			cin >> num;
			cout << "Temperature in Celsius: " << fahrenheitToCelsius(num) << endl;
			break;
		case 3:
			cout << "Enter Temperature in Celsius: ";
			cin >> num;
			cout << "Temperature in Kelvin: " << celsiusToKelvin(num) << endl;
			break;
		case 4:
			cout << "Enter Temperature in Kelvin: ";
			cin >> num;
			cout << "Temperature in Celsius: " << kelvinToCelsius(num) << endl;
			break;
		case 5:
			cout << "Exiting... \n";
			break;
		default:
			cout << "Wrong input." << endl;
			break;
		}
	} while (option != 5);
	return 0;
}

float celsiusToFahrenheit(float c) {return (c * 9 / 5) + 32;}
float fahrenheitToCelsius(float f) {return (f - 32) * 5 / 9;}
float celsiusToKelvin(float c) {return c + 273.15;}
float kelvinToCelsius(float k) {return k - 273.15;}

void showMenu() {
	cout << "=== Temperature Converter ===" << endl;
	cout << "1. Celsius to Fahrenheit" << endl;
	cout << "2. Fahrenheit to Celsius " << endl;
	cout << "3. Celsius to Kelvin " << endl;
	cout << "4. Kelvin to Celsius " << endl;
	cout << "5. Exit " << endl;
	cout << "Choose an option: ";
}

