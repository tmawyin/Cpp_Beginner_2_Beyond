// Checking Account is a type of Account that charges a $1.50 per withdrawal

#pragma once

#include "Account.h"

class Checking_Account : public Account{
	friend std::ostream& operator<<(std::ostream& os, const Checking_Account& account);

private:
	// Creating constant expressions for default values
	static constexpr const char* def_name = "Unnamed Checking Account";
	static constexpr double def_balance = 0.0;
	static constexpr double def_fee = 1.50;

public:
	/* Note on constructors :
	*	Could use the "Account" constructor as is by calling
	*		using Account::Account;
	*	However, this will prevent us from using the default "Checking Act" name, instead it will use the "Account" default
	*/
	Checking_Account(std::string name = def_name, double balance = def_balance);
	
	bool deposit(double amount);
	bool withdraw(double amount);
};
