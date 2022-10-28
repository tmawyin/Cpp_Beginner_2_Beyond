// C++ Structure:
/* Discussing the C++ syntax and elements
*	- comments
*	- namespaces
*	- main function
*	- basic I/O
*/

#include <iostream>

using namespace std;	// Avoids using std:: everytime
using std::endl;		// This is another way of using only what you need from a namespace

int main() {
	// I/O examples
	cout << "Hello World!" << endl;
	cout << "Hi\nOut\nThere!\n"; // Another way to enter a new line "\n"

	int num1;
	int num2;
	cout << "Enter two integers: ";
	cin >> num1 >> num2;
	cout << "Your combined number is: " << num1+num2 << endl;

	double num3;
	cout << "Enter a float number: ";
	cin >> num3;
	cout << "Well, your number now is: " << num3 << endl;

	return 0;
}