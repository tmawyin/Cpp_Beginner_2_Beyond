//Defining methods for the Account class

#include "Account.h"

//==== Constructors ====
/* Constructor using initialization list - more efficient way of assigning values
	this is also a delegating constructor - since it can be used as a template for other constructors
*/	
Account::Account(double bal, int t)
	: balance{ bal }, type{ t }{
	++num_accounts;
}

/* Removing delagating constructors when using default parameters in the main constructor */
//Account::Account()
//	:Account{ 0, 1 } {}	// Calls the delagating constructor with provided values
//Account::Account(double bal)
//	:Account{ bal,1 } {}


//Copy constructor - everytime a copy of the Account class is needed, this constructor will be used
Account::Account(const Account& source) 
	:balance(source.balance), type(source.type) {}

//==== Destructor: ====
Account::~Account(){
	--num_accounts;
}

//==== Methods: ====
void Account::set_balance(double bal) {
	balance = bal;
}

double Account::get_balance() const {
	return balance;
}

bool Account::deposit(double value) {
	balance += value;
	return true;
}

bool Account::withdraw(double value) {
	if (balance - value >= 0) {
		balance -= value;
		return true;
	}
	return false;
}

// Defining static values - these belong to the Class and not to each Object
int Account::num_accounts = 0;

int Account::get_num_accounts() {
	return num_accounts;
}