// Ask the user to enter a number and display a phrase

#include <iostream>

int main() {
	int num;

	std::cout << "Enter your favorite number between 1 and 100: ";
	std::cin >> num;
	std::cout << "Amazing, That's my favorite number too" << std::endl;
	std::cout << "No really!, " << num << " is my favorite number!" << std::endl;
	
	return 0;
}
