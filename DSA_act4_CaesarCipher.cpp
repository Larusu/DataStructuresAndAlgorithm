//
// Encrypting and Decrypting Caesar Cipher
//
#include <iostream>
#include <fstream>
#include <string>
#include <thread> // for delay
#include <chrono>
#include <cstdio> // for deleting

using namespace std;

#define KEY 3
string getmessage;

void writeToFile(fstream& outputfile, string value);
void convertStringToCharArray(int index, string str, char charArr[]);
string readLineFromFile(fstream& data);
void encryptMessage(fstream& getMsg, fstream& secretMsg, string perform);

int main() {

	string userInput;
	char choice = 'n';
	fstream inputFile;
	fstream encryptedFile;

	cout << "Enter secret message: ";
	getline(cin, userInput);

	// Write message to a file
	inputFile.open("myTopSecretMessage.txt", ios::out);
	writeToFile(inputFile, userInput);
	inputFile.close();

	// Encrypt and write to another file
	inputFile.open("myTopSecretMessage.txt", ios::in);
	encryptedFile.open("youCantReadThis.txt", ios::out);
	encryptMessage(inputFile, encryptedFile, "encrypt");
	inputFile.close();
	encryptedFile.close();

	// Delaying the output
	this_thread::sleep_for(chrono::seconds(1)); cout << ".";
	this_thread::sleep_for(chrono::seconds(1)); cout << ".";
	this_thread::sleep_for(chrono::seconds(1)); cout << ".";
	this_thread::sleep_for(chrono::seconds(1)); cout << "." << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Message encrypted successful!";

	encryptedFile.open("youCantReadThis.txt", ios::in);
	cout << "\n\n" << readLineFromFile(encryptedFile) << endl;
	
	cout << "\nDo you want to see the decrypted message?: ";
	cin >> choice;
	if (toupper(choice) == 'Y') {
		fstream tempFile("temporaryFile.txt", ios::out);

		encryptedFile.clear();              
		encryptedFile.seekg(0, ios::beg);

		encryptMessage(encryptedFile,tempFile, "decrypt");

		cout << getmessage;

		tempFile.close();
		remove("temporaryFile.txt");
	}
	encryptedFile.close();
}

void writeToFile(fstream& file, string content) 
{
	if (file.is_open()) {
		file << content;
	} else {
		cerr << "Failed to open file for writing.";
	}
}

string readLineFromFile(fstream& data) 
{
	string newline;
	getline(data, newline);
	return newline;
}

void convertStringToCharArray(int index, string input, char charArray[])
{
	if (index < 0) return;
	charArray[index] = tolower(input[index]);
	convertStringToCharArray(index - 1, input, charArray);
}

void encryptMessage(fstream& sourceFile, fstream& encryptedFile, string perform) {

	if (!sourceFile.is_open() && !encryptedFile.is_open()) {
		cerr << "Failed to open file for reading.";
		return;
	}

	int shiftAmount = 0;
	if (perform == "encrypt") { shiftAmount = +KEY; }
	else if (perform == "decrypt") { shiftAmount = -KEY; }

	const char alphabet[26] = { 
		'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
		'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' 
	};

	string message = readLineFromFile(sourceFile);
	int size = message.length();
	char* processedMsg = new char[size + 1];

	convertStringToCharArray(size - 1, message, processedMsg);

	for (int i = 0; i < size; i++) {
		if (processedMsg[i] == ' ') {
			processedMsg[i] = '#';
			continue;
		}

		bool notMatched = true;
		for (int j = 0; j < 26; j++) {
			if (alphabet[j] == processedMsg[i]) {
				processedMsg[i] = toupper(alphabet[(j + shiftAmount + 26) % 26]);
				notMatched = false;
				break;
			}
		}

		if (notMatched) {
			processedMsg[i] = ' ';
		}
	}
	processedMsg[size] = '\0';
	
	if (perform == "encrypt") {
		writeToFile(encryptedFile, processedMsg);
	}
	else if (perform == "decrypt") {
		getmessage = processedMsg;
	}

	delete[] processedMsg;
}
