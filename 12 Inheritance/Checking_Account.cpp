/* CHECKING_ACCOUNT CLASS */

#include "Checking_Account.h"

// Constructor
Checking_Account::Checking_Account(std::string name, double balance) 
	:Account{name, balance}{}

// Destructor - can use the Account class 

// Deposit function - invoking Account class method
bool Checking_Account::deposit(double amount) {
	return Account::deposit(amount);
}

// Withdrawal function - adds a "fee" to each withdraw
bool Checking_Account::withdraw(double amount) {
	return (Account::withdraw(amount + def_fee));
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Checking_Account& account) {
	os << "Checking Account: " << account.name << " has a balance of: $" << account.balance << std::endl;
	return os;
}