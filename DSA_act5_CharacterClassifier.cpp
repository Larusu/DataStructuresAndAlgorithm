//
// sorting the input file to odd, even, vowels, consonant, or symbols
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void checkInputFile(char ch, ofstream& odd, ofstream& even, ofstream& vowels, ofstream& consonant, ofstream& symbols);
void checkInt(char c, ofstream& odd, ofstream& even);
void checkString(char c, ofstream& vowels, ofstream& consonant);

int main() {

	fstream inputFile("input.txt", ios::in);
	ofstream oddFile("oddNumbers.txt", ios::out);
	ofstream evenFile("evenNumbers.txt", ios::out);
	ofstream vowelsFile("vowels.txt", ios::out);
	ofstream consonantsFile("consonants.txt", ios::out);
	ofstream symbolsFile("symbols.txt", ios::out);

	if (!inputFile.is_open()) {
		cerr << "Error opening input file." << endl;
		return 1;
	}

	char ch;
	while (inputFile.get(ch)) {
		if (ch != '\n' && ch != '\r') {
			checkInputFile(ch, oddFile, evenFile, vowelsFile, consonantsFile, symbolsFile);
		}
	}
	
	inputFile.close();
	oddFile.close();
	evenFile.close();
	vowelsFile.close();
	consonantsFile.close();
	symbolsFile.close();
}
void checkInputFile(char ch, ofstream& odd, ofstream& even, ofstream& vowels, ofstream& consonant, ofstream& symbols) {

	if (isdigit(ch)) {
		checkInt(ch, odd, even);
	}
	else if (isalpha(ch)) {
		checkString(ch, vowels, consonant);
	}
	symbols << ch << endl;
}

void checkInt(char c, ofstream& odd, ofstream& even) {

	if (!odd.is_open() || !even.is_open()) {
		cerr << "Error opening output files." << endl;
		return;
	}

	if (c % 2 == 0) {
		even << c << endl;
		return;
	}
	odd << c << endl;
}

void checkString(char c, ofstream& vowels, ofstream& consonants) {

	if (!vowels.is_open() || !consonants.is_open()) {
		cerr << "Error opening output files." << endl;
	}
	char vowelsList[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

	int size = sizeof(vowelsList) / sizeof(vowelsList[0]);

	for (int i = 0; i < size; i++) {
		if (c == vowelsList[i]) {
			vowels << c << endl;
			return;
		}
	}
	consonants << c << endl;
}
