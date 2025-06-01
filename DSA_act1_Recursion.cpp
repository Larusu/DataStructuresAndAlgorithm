//
// Activity 1 for Data Structures and Algorithm
// A program that compute the factorial using RECURSION
//
#include <iostream>
using namespace std;

// Recursion function to calculate factorial
void factorial(int num, int result = 1) {
	if (num == 0 || num == 1) { 
		// Base case: 0 and 1 both have a factorial of 1
		cout << " is 1." << endl;
		return;
	}

	result *= num; // Factorial Formula

	if (num == 2) {
		cout << " is " << result << ".\n";
		return;
	}

	factorial(num - 1, result); // Recursion call with num decremented by 1
}

int main() {
	char confirm;
	int input;

	// Loop if the user wants to try again 
	do {
		cout << "Enter a number: ";
		cin >> input;

		// Input validation loop to prevent negative numbers
		while (input < 0) {
			if (input < 0) {
				cout << "Please input positive integers only!" << endl;
				cin >> input;
			} continue; // Continues only when the input is valid or non-negative
		}

		cout << "Factorial of " << input;
		factorial(input);

		cout << "\nTry again? [y/n]: ";
		cin >> confirm;

		// Input validation for confirmation prompt
		while (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
			if (confirm != 'y' && confirm != 'Y' && confirm != 'n' && confirm != 'N') {
				cout << "Invalid Syntax!" << endl;
				cin >> confirm;
			} continue; // Continue only when the input is 'y', 'Y', 'n', or 'N'
		}
		
	} while (confirm != 'n' && confirm != 'N');

	return 0;
}
