/*Statements and Operators*/

#include <iostream>

using namespace std;

/* COURSE MATERIAL
int main() {
	//mod operator
	cout << 10 % 3 << endl;
	cout << endl;

	//increment and decrement operators
	int counter = 0;
	cout << "Using increment operator ++" << endl;
	cout << counter++ << endl;	//increaments counter AFTER cout is used
	cout << ++counter << endl;	//increments counter BEFORE cout is used

	//casting to other data type
	static_cast<double> (counter);
	
	//equality & relational operators
	int num1{ 100 };
	int num2{ 200 };
	cout << endl;
	cout << boolalpha; //displays true/false instead of 1/0
	cout << "Equality & Relational Operators" << endl;
	cout << (num1 == num2) << endl;
	cout << (num1 != num2) << endl;
	cout << (num1 < num2) << endl;
	cout << (num1 > num2) << endl;

	//logical operators - and: &&, not:!, or:||
	cout << ((num1 < 150) && (num2 > 150)) << endl;

	//compount assignment
	num1 += num2; //add num1 and num2 and assign the result to num1

	return 0;
}
*/

/* SECTION CHALLENGE 
	Given the amount of cents break the change into dollars, quarters, dimes, nickels, pennies.
*/
int main() {
	cout << boolalpha;

	//ask the amount of cents
	int cents{};
	cout << "Enter the amount of cents: ";
	cin >> cents;

	//finding out how many dollars we have
	int dollars = cents / 100;
	cout << "dollars: " << dollars << endl;

	//finding out how many coins are left (can use % operator)
	int cents_left = cents % 100;	//ALTERNATIVE: int cents_left = cents - dollars * 100;
	
	// quarters
	int quarters = cents_left / 25;
	cout << "quarters: " << quarters << endl;
	//dimes
	cents_left -= quarters*25;
	int dimes = cents_left / 10;
	cout << "dimes: " << dimes << endl;
	//nickels
	cents_left -= dimes*10;
	int nickels = cents_left / 5;
	cout << "nickels: " << nickels << endl;
	//pennies
	cents_left -= nickels *5;
	cout << "pennies: " << cents_left << endl;


	return 0;
}