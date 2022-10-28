/* Exception Handling
*	Causes of exceptions: no or missing resources, invalid operations
*	Keywords: throw, try, catch
*	Typically, we use classes to generate exceptions. You can build your own class to handle exception
*/

#include <iostream>
#include <vector>
#include <memory>

#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"

using namespace std;

/* COURSE MATERIAL */
//double calculate_mpg(double miles, double gallons) {
//	if (gallons == 0)
//		throw 0;
//	if (miles < 0 || gallons < 0)
//		throw string{ "Negative value error" };
//	return miles / gallons;
//}
//
//int main() {
//
//	// Divide by zero exception
//	double miles{};
//	double gallons{};
//	double mpg{};
//	double mpg_func{};
//	
//	cout << "Enter the miles: ";
//	cin >> miles;
//	cout << "Enter the gallons: ";
//	cin >> gallons;
//
//	// Exception handling basics
//	try {
//		if (gallons == 0)
//			throw 0;
//		mpg = miles / gallons;
//		cout << "MPG = " << mpg << endl;
//	}
//	catch (int& ex) {
//		cerr << "Can't divide by zero" << endl;
//	}
//	cout << "--------------------" << endl;
//
//	// Exception handling from a function
//	try {
//		mpg_func = calculate_mpg(miles, gallons);
//		cout << "MPG = " << mpg_func << endl;
//	}
//	catch (int& exc) {
//		cerr << "Gallons = 0. No division by zero" << endl;
//	}
//	// Handling multiple exceptions
//	catch (string& err) {
//		cerr << err << ": No negative values allowed" << endl;
//	}
//	cout << "--------------------" << endl;
//
//	cout << endl;
//	return 0;
//}

/* SECTION CHALLEGE */
// Create an exception handler for insufficient funds
int main() {

	try {
		cout << "----- Illegal Balance -----" << endl;
		unique_ptr<Account> bat_acc = make_unique<Checking_Account>("Batman", 1000);		// Valid object
		cout << *bat_acc << endl;
		unique_ptr<Account> rob_acc = make_unique<Savings_Account>("Robin", -20, 2.0);			// Invalid object
	}
	catch (const IllegalBalanceException& ex) {
		cerr << ex.what() << endl;
	}
	try {
		cout << "----- Insufficient Funds -----" << endl;
		unique_ptr<Account> aqu_acc = make_unique<Savings_Account>("Aquaman", 100, 1.0);
		aqu_acc->withdraw(2000);
	}
	catch (const InsufficientFundsException& ex) {
		cerr << ex.what() << endl;
	}

	cout << endl;
	return 0;
}