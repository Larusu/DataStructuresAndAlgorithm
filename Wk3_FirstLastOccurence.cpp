//
// Test
// A program that determines if the integer input has 8, none, or if there are more checks the first and last occurence
//
#include <iostream>
using namespace std;

int main() {

	int arr[10];
	int size = sizeof(arr) / sizeof(int);
	char count = 0, first = 0, last = 0;

	cout << "Input 10 integers: \n";
	for (int i = 0; i < size; i++) {
		cout << "index[" << i << "]: ";
		cin >> arr[i];

		if (arr[i] == 8) {
			count += 1;
		}
	}

	switch (count) {
	case 0:
		cout << "Number 8 is NOT in the array!";
		break;

	case 1:
		for (int i = 0; i < size; i++) {
			if (arr[i] == 8) {
				cout << "First and last occurence of no. 8 is in index [" << i << "]";
				break;
			}
		}
		break;

	default:
		for (int i = 0; i < size; i++) {
			if (8 != arr[i]) {
				continue;
			}

			if (first == 0) {
				first = i;
			}

			last = i;
		}
		cout << "(" << first << " " << last << ")";
		break;
	}
}
