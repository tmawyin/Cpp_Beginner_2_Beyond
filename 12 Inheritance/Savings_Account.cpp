/* SAVINGS_ACCOUNT CLASS */

#include "Savings_Account.h"

// Constructors:

//Savings_Account::Savings_Account() : Account{}, int_rate { 3.0 } {}		// no-arg constructor (not needed)

/* Note: we can specify which constructor from the base class to use when inheriting
*	if not specified, derived class will use the base no-args constructor */
Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
	: Account{ name, balance }, int_rate{ int_rate } {
}

// Destructor
Savings_Account::~Savings_Account() {}

// Deposit function
bool Savings_Account::deposit(double amount) {
	// adding int_rate% of deposit amount
	amount *= (1+int_rate/100);
	// invoking the Account deposit function
	return Account::deposit(amount);
}

// Withdrawal function
bool Savings_Account::withdraw(double amount) {
	return Account::withdraw(amount);
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Savings_Account& account) {
	os << "Savings Account: " << account.name << " has a balance of: $" << account.balance << ", (" << account.int_rate << "% interest)" << std::endl;
	return os;
}