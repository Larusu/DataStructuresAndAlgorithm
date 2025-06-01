//
// Activity 2 for Data Structures and Algorithm
// A program that accepts a string(array of char). Deteriming the number of occurence in each character of string
// Accepting both upper and lowercase letters
//
#include <iostream>
#include <cstring>
using namespace std;

void counting_occurrence(char arr[]);

int main() {
	char arr[101]; // 100 max size and additional 1 for null
	char confirm;

	do {
		cin.ignore();
		counting_occurrence(arr);

		cout << "\nType 'y' or 'Y' if stop: ";
		cin >> confirm;
	} while (confirm != 'y' && confirm != 'Y');

	return 0;
}

void counting_occurrence(char arr[]) {
	cout << "Enter String Value: ";
	cin.getline(arr, 101);

	int size = strlen(arr); // Getting the length of input using strlen

	for (int i = 0; i < size; i++) {
		if (arr[i] == '\0') { continue; } // Skip if char is already counted

		int count = 1;

		for (int j = i + 1; j < size; j++) {
			if (arr[i] == arr[j]) {
				count++; // Adding 1 to 'count' everytime the char is repeated
				arr[j] = '\0'; // Changing the char in 'arr' into a null or \0 
			}
		}

		cout << '\t' << arr[i] << "\t- \t" << count << endl;
	}
}
