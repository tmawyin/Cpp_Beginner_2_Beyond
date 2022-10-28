/* ACCOUNT CLASS */

#include "Account.h"


//Account::Account() : balance{ 0.0 }, name{ "NULL" }{}		// no-arg constructor (not needed)

// Overloaded constructor
Account::Account(std::string act_name, double act_balance)
	: name{act_name}, balance{act_balance} {}

// Destructor
Account::~Account() {}

// Deposit function
bool Account::deposit(double amount) {
	if (amount >= 0) {
		this->balance += amount;
		std::cout << "Account deposit of $" << amount << std::endl;
		return true;
	}
	else {
		std::cout << "Deposit could not be completed" << std::endl;
		return false;
	}
	
}

// Withdrawal function
bool Account::withdraw(double amount) {
	//std::cout << "Account withdrawal of $" << amount <<  std::endl;
	if (amount > this->balance) {
		std::cout << "Insufficient funds" << std::endl;
		return false;
	}
	else {
		std::cout << "Withdrawal completed" << std::endl;
		this->balance -= amount;
		return true;
	}
}

// Display balance
void Account::display_balance() {
	std::cout << "Your balance is: $" << this->balance << std::endl;
}

// Get balance
double Account::get_balance() {
	return this->balance;
}

// Overloading << operator
std::ostream& operator<<(std::ostream& os, const Account& account) {
	os << "Account: " << account.name << " has a balance of: $" << account.balance << std::endl;
	return os;
}