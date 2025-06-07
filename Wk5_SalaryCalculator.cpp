// 

#include <iostream>
using namespace std;

const int SIZE = 10;
int employeeCount = 0;

struct Employee {
	string name;
	int rate = 0;
	int hours = 0;
	long gross = 0;
	long net = 0;
}employees[SIZE];

void grossSalary();
void netPay();
void printInformation();
void userInput();

int main() {
	
	userInput();
	printInformation();
}

void grossSalary() {

	for (int i = 0; i < employeeCount; i++) {
		if (employees[i].hours <= 40) {
			employees[i].gross = employees[i].hours * employees[i].rate;
		}
		else if (employees[i].hours > 40) {
			employees[i].gross = (employees[i].rate / 8) * (employees[i].hours - 40) + (employees[i].rate * employees[i].hours);
		}
	}
	netPay();
}

void netPay() {

	for (int i = 0; i < employeeCount; i++) {
		if (employees[i].gross <= 40000) {
			employees[i].net = employees[i].gross;
		}
		else if (employees[i].gross > 40000) {
			employees[i].net = employees[i].gross - (15 + 0.45 * employees[i].gross);
		}
	}
}

void userInput() {
	char choice = ' ';
	int count = 0;
	cout << "Transaction for employee details: " << endl;

	while (choice != 'n' && choice != 'N') {

		if (count >= SIZE) { return; }
		cout << "Employee #" << count + 1 << endl;
		cout << "Enter employee's name: ";
		cin >> employees[count].name;
		cout << "Enter employee's hourly rate: ";
		cin >> employees[count].rate;
		cout << "Enter employee's hours worked: ";
		cin >> employees[count].hours;
		
		count++;

		cout << "\nDo you want to make another transaction? ";
		cin >> choice;
	}

	employeeCount = count;

	grossSalary();
}

void printInformation() {

	cout << "\n\n====== Employee Information ======" << endl;
	for (int i = 0; i < employeeCount; i++) {
		cout << "Employee #" << i + 1 << endl;
		cout << "Name: " << employees[i].name << endl;
		cout << "Hourly Rate: " << employees[i].rate << endl;
		cout << "Hours Worked: " << employees[i].hours << endl;
		cout << "\nGross Salary: " << employees[i].gross << endl;
		cout << "Net Pay: " << employees[i].net << endl;
		cout << "==================================" << endl;
	}
}
