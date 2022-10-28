/* Characters and Strings
/	C-style string and C++ style strings
*/

#include <iostream>
#include <vector>
#include <cctype>	//C style character functions 
#include <cstring>	//C style string functions
#include <string>

using namespace std;

/* COURSE MATERIAL
int main() {

	//C-STYLE STRINGS
	char first_name[20]{};
	char last_name[20]{};
	char full_name[50]{};
	char temp[50]{};

	cout << "Enter your full name: ";
	cin.getline(temp, 50);
	cout << temp << endl;

	cout << "Please enter your first name: ";
	cin >> first_name;
	cout << "Please enter your last name: ";
	cin >> last_name;

	//strlen() finds length of a string [return *size_t* data type]
	cout << endl << "Your first name has " << strlen(first_name) << " characters" << endl;
	
	strcpy_s(full_name, first_name);
	strcat_s(full_name, " ");
	strcat_s(full_name, last_name);

	cout << "Your complete name is: " << full_name << endl;
	
	//strcmp() compares strings
	cout << endl;
	if (strcmp(temp, full_name) == 0)
		cout << "Yes, same name" << endl;
	else
		cout << "Not the same name" << endl;

	//toupper() moves every character to uppercase
	for (int i{ 0 }; i < strlen(full_name); ++i) {
		if (isalpha(full_name[i])) 
			full_name[i] = toupper(full_name[i]);
	}
	cout << "\nYour name in uppercase is: " << full_name << endl;
	cout << "--------------------------" << endl << endl;

	//C++ STRINGS - behave as vectors of characters
	string s1 = "C++ Rocks!" ;
	string s2 {"Oh Yeah!"};
	cout << s1 + " " + s2 << endl;

	//substr() gets a sub-string from a phrase
	//find() gets the position of where a phrase is located
	//erase() deletes characters of phrases
	//clear() removes all characters
	//length() returns the length of the string
	string phrase{ "This is the best course ever!" };
	cout << phrase << endl;
	cout << phrase.substr(0, 7) << endl;
	cout << phrase.find("best") << endl;
	cout << (phrase.find("xx") == string::npos) << endl;	//npos = no position flag
	
	//a way to get an entire line using c++ strings
	string sample{};
	cin.ignore(10, '\n');	//need this to ignore return characters in buffer
	cout << "Enter a phrase: ";
	getline(std::cin, sample, 'x'); //x is a delimiter and it is optional
	cout << "Is this your sentence: " << sample << endl;

	cout << endl;
	return 0;
}
*/

/* SECTION CHALLENGE 
// Do a cipher to encrypt and decrypt a message

int main() {
	string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
	string key{ "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr" };
	string message{};
	string encrypted{};
	string decrypted{};

	//cin.ignore();
	cout << "Enter your message: ";
	getline(cin, message);
	
	for (auto c : message) {
		if (isalpha(c)) {
			encrypted += key[alphabet.find(c)];
		}
		else {
			encrypted += c;
		}
	}

	cout << endl;
	cout << "Encrypting... " << endl;
	cout << "Your message is: " << encrypted << endl;
	cout << endl;

	for (auto c : encrypted) {
		if (isalpha(c)) {
			decrypted += alphabet[key.find(c)];
		}
		else {
			decrypted += c;
		}
	}

	cout << "Decrypting... " << endl;
	cout << "Your original message is: " << decrypted << endl;
	cout << endl;

	cout << endl;
	return 0;
}
*/

/* ASSIGNMENT */
// Create a letter pyramid

int main() {
	
	string phrase{};
	string fwd{};
	string rev{};

	cout << "Enter your string: ";
	getline(cin, phrase);
	size_t len = phrase.length()-1;
	
	string spaces(len, ' ');
	
	//Loop through the characters and start adding them to a pyramid
	for (int i{ 0 }; i < phrase.size(); i++) {
		cout << (spaces + fwd + phrase.at(i) + rev)  << endl;
		fwd += phrase.at(i);
		rev = phrase.at(i) + rev;
		spaces.erase(0,1);
	}

	return 0;
}

