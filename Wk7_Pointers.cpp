//
// Swapping values using pointers
//

 #include <iostream>
using namespace std;

int main() {

	int num1 = 1;
	int num2 = 2;

	cout << "Num1: " << num1 << " Num2: " << num2 << endl;

	int* temp1 = &num1;
	int* temp2 = &num2;

	int temp = *temp1;
	*temp1 = *temp2;
	*temp2 = temp;

	cout << "Num1: " << num1 << " Num2: " << num2 << endl;
}
